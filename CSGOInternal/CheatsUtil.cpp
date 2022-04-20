#include "cheats.h"
#include "windows.h"
#include "Offsets.h"

#define gModule(x) (uintptr_t)GetModuleHandle(x)

extern ScreenManager* screenManagerGlobal;

Cheats::Cheats()
{
	uninject = true;
	serverCheatsEnabled = true;

	C_CSPlayerPtr = NULL;
	heldWeapon = NULL;
	clientPlayer = NULL;
	serverPlayer = NULL;

	// Find dll load locations
	clientDll = gModule(L"client.dll");
	serverDll = gModule(L"server.dll");
	engineDll = gModule(L"engine.dll");
	inputSystemDll = gModule(L"inputsystem.dll");

	// Set up different function managers
	hookManager = new HookManager(serverDll, clientDll, engineDll);
	screenManager = new ScreenManager(clientDll);
	interfaceManger = new InterfaceManager();
	screenManagerGlobal = screenManager;

	clientState = (ClientState*)*(uintptr_t*)(engineDll + ClientStateOffset); // No recalculation
	printf(" [*] Client Player State at %#8X\n", (uintptr_t)clientState);

	clientEntityListAddress = (uintptr_t)(clientDll + ClientEntityListOffset); // No recalculation
	printf(" [*] Client Entity List found at %#8X\n", clientEntityListAddress);
	

	gameState = new GameState(clientDll);

	// Modules
	infiniteHealth = new InfiniteHealth();
	infiniteAmmo = new InfiniteAmmo();
	noRecoil = new NoRecoil();
	speed = new Speed();
	radar = new Radar(&clientEntList);
	aimbot = new Aimbot(&clientEntList);
	esp = new ESP(&clientEntList);
	fly = new Fly();
	bhop = new BHop();
	tracers = new Tracers(&clientEntList);

	uninject = false;
	addressesAreValid = false;
}

void Cheats::tick()
{
	keybinds();

	if (gameState->RoundStateChanged())
		addressesAreValid = false;

	if (addressesAreValid && gameState->b_IsInGameLast)
	{	
		bhop->tick();
		if (serverCheatsEnabled)
		{
			infiniteHealth->tick();
			speed->tick();
			radar->tick();
			fly->tick();
			if (!infiniteAmmo->tick())
				addressesAreValid = false;
		}
	}

	if (!addressesAreValid && gameState->b_IsInGameLast)
		recalculateAddresses();
}


void Cheats::cheatStatus()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 16 });
	if (serverCheatsEnabled)
	{
		printf("Server Cheats:\n");
		infiniteHealth->status();
		infiniteAmmo->status();
		noRecoil->status();
		speed->status();
		fly->status();
	}
	else
	{ 
		printf("<Server Disabled>\n");
	}
	printf("\nClient Cheats:\n");
	radar->status();
	aimbot->status();
}

void Cheats::cleanup()
{
	hookManager->removeAll();
	screenManager->Cleanup();
}

void Cheats::recalculateAddresses()
{
	printf(" [!] Recalculating Addreses\n");

	hookManager->InitalizeHooks();
	
	if (!screenManager->initialized)
	{
		if (!screenManager->Initialize())
		{
			printf(" [!] Error Hooking D3D!\n");
			uninject = true;
		}
	}

	if (!interfaceManger->initialized)
	{
		if (!interfaceManger->intializeInterfaces())
		{
			printf(" [!] Error Initializing Interfaces!\n");
			uninject = true;
		}
	}

	serverPlayer = (ServerPlayer*)*(uintptr_t*)(serverDll + ServerPlayerOffset);
	clientPlayer = (ClientPlayer*)*(uintptr_t*)(clientDll + ClientPlayerOffset);
	C_CSPlayerPtr = *(uintptr_t*)clientPlayer;


	infiniteAmmo->heldWeaponPtr = (uintptr_t)((uintptr_t)serverPlayer->weaponListPtr + HeldWeaponListOffset);
	
	if (clientPlayer)
	{
		esp->clientPlayer = clientPlayer;
		tracers->clientPlayer = clientPlayer;
		aimbot->clientPlayer = clientPlayer;
		radar->clientPlayer = clientPlayer;
	}
	else
	{
		addressesAreValid = false;
		return;
	}

	if (clientState)
	{
		fly->clientState = clientState;
		aimbot->clientState = clientState;
		speed->clientState = clientState;
	}
	else
	{
		addressesAreValid = false;
		return;
	}

	if (serverPlayer)
	{
		infiniteHealth->serverPlayer = serverPlayer;
		speed->serverPlayer = serverPlayer;
		fly->serverPlayer = serverPlayer;
		if (serverPlayer->weaponListPtr)
		{
			infiniteAmmo->heldWeaponPtr = (uintptr_t)((uintptr_t)serverPlayer->weaponListPtr + HeldWeaponListOffset);
		}
	}
	else
	{
		addressesAreValid = false;
		return;
	}

	if (screenManager->gameDimensions.w && screenManager->gameDimensions.h)
	{
		esp->screenDimensions.x = screenManager->gameDimensions.w;
		esp->screenDimensions.y = screenManager->gameDimensions.h;

		tracers->screenDimensions.x = screenManager->gameDimensions.w;
		tracers->screenDimensions.y = screenManager->gameDimensions.h;

	}
	loadClientEntityList();
	addressesAreValid = true;
}

bool Cheats::loadClientEntityList()
{
	printf(" [*] Loading Entity List:\n");

	clientEntList.clear();
	ClientPlayer* currentEnt = NULL;
	for (uint32_t i = 0; i < interfaceManger->clientEntityList->GetMaxEntities(); i++)
	{
		currentEnt = interfaceManger->clientEntityList->GetClientEntity(i);
		if (IsValidEnt(currentEnt))
		{
			printf("	Entity %d: (%#8X)\n", i, (uintptr_t)currentEnt);
			clientEntList.push_back(currentEnt);
		}
	}
	printf(" [*] Entity List Loaded!\n\n");

	return true;
}

bool Cheats::IsValidAndAliveEnt(ClientPlayer* player)
{
	if (!player)
		return false;
	if (*(uintptr_t*)(player) != C_CSPlayerPtr)
		return false;
	if (player == clientPlayer)
		return false;
	if (player->b_Dormant)
		return false;
	if (player->i_Health < 1)
		return false;
	return true;
}

bool Cheats::IsValidEnt(ClientPlayer* player)
{
	if (!player)
		return false;
	if (*(uintptr_t*)(player) != C_CSPlayerPtr)
		return false;
	return true;
}