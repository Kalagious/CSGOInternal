#include "cheats.h"
#include "windows.h"
#include "Offsets.h"

#define gModule(x) (uintptr_t)GetModuleHandle(x)


Cheats::Cheats()
{
	uninject = true;
	serverCheatsEnabled = true;

	C_CSPlayerPtr = NULL;
	heldWeapon = NULL;
	hookManager = NULL;

	csgoExe = gModule(L"csgo.exe");
	clientDll = gModule(L"client.dll");
	serverDll = gModule(L"server.dll");
	engineDll = gModule(L"engine.dll");
	inputSystemDll = gModule(L"inputsystem.dll");

	clientState = (ClientState*)*(uintptr_t*)(engineDll + ClientStateOffset); // No recalculation
	printf("Client Player State at %#8X\n", (uintptr_t)clientState);

	clientEntityListAddress = (uintptr_t)(clientDll + ClientEntityListOffset); // No recalculation
	printf("Client Entity List found at %#8X\n", clientEntityListAddress);
	
	screenManager = new ScreenManager();
	gameState = new GameState(clientDll);
	entList = new EntList(clientEntityListAddress);
	//viewMatrix = (float*)(clientDll + ViewMatrixOffset);

	infiniteHealth = new InfiniteHealth();
	infiniteAmmo = new InfiniteAmmo();
	noRecoil = new NoRecoil();
	speed = new Speed();
	radar = new Radar(&clientEntList);
	aimbot = new Aimbot(&clientEntList);
	esp = new ESP(&clientEntList);
	fly = new Fly();
	bhop = new BHop();


	uninject = false;
	firstTick = true;
	addressesAreValid = false;
}

void Cheats::tick()
{
	if (firstTick)
	{
		initializeHooks();
		firstTick = false;
	}

	keybinds();
	//cheatStatus();

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


void Cheats::initializeHooks()
{
	hookManager = new HookManager(csgoExe, serverDll, clientDll, engineDll, serverPlayer);
	hookManager->setClientViewAnglesHook->initialize();
	hookManager->setLocalVelHook->initialize();
	hookManager->setPositionHook->initialize();
	hookManager->setYawOffsetHook->initialize();
	if (!screenManager->Initialize())
	{
		printf("[*] Error Hooking D3D!\n");
		uninject = true;
	}
	//hookManager->testingHook->initialize();
	//hookManager->drawWeaponGUIHook->initialize();

}


void Cheats::recalculateAddresses()
{
	serverPlayer = (ServerPlayer*)*(uintptr_t*)(serverDll + ServerPlayerOffset);
	clientPlayer = (ClientPlayer*)*(uintptr_t*)(clientDll + ClientPlayerOffset);
	C_CSPlayerPtr = *(uintptr_t*)clientPlayer;


	infiniteAmmo->heldWeaponPtr = (uintptr_t)((uintptr_t)serverPlayer->weaponListPtr + HeldWeaponListOffset);
	
	if (clientPlayer)
	{
		aimbot->clientPlayer = clientPlayer;
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

	entList->load();
	addressesAreValid = true;
}