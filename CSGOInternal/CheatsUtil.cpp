#include "Cheats.h"
#include "windows.h"
#include "Offsets.h"

Cheats::Cheats(uintptr_t CSGOExeIn, uintptr_t ServerDllIn, uintptr_t ClientDllIn, uintptr_t EngineDllIn)
{
	uninject = true;

	serverCheatsEnabled = true;

	CSGOExe = CSGOExeIn;
	ServerDll = ServerDllIn;
	ClientDll = ClientDllIn;
	EngineDll = EngineDllIn;

	serverPlayer = (ServerPlayer*)*(uintptr_t*)(ServerDll + ServerPlayerOffset);
	printf("\nServer Player Object found at %#8X\n", serverPlayer);

	clientPlayer = (ClientPlayer*)*(uintptr_t*)(ClientDll + ClientPlayerOffset); 
	printf("\Client Player Object found at %#8X\n", clientPlayer);

	clientState = (ClientState*)*(uintptr_t*)(EngineDll + ClientStateOffset); // No recalculation
	printf("\nClient Player State at %#8X\n", clientState);

	clientEntityListAddress = (uintptr_t)(ClientDll + ClientEntityListOffset); // No recalculation
	printf("\Client Entity List found at %#8X\n", clientEntityListAddress);

	gameState = new GameState(ClientDll);
	entList = new EntList(clientEntityListAddress);
	
	infiniteHealth = new InfiniteHealth(serverPlayer);
	infiniteAmmo = new InfiniteAmmo((uintptr_t)((uintptr_t)serverPlayer->weaponListPtr + HeldWeaponListOffset));
	noRecoil = new NoRecoil();
	speed = new Speed(serverPlayer, clientState);
	aimbot = new Aimbot(clientPlayer, clientState, &clientEntList);
	fly = new Fly(serverPlayer, clientState);

	uninject = false;
	firstTick = true;
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
		if (serverCheatsEnabled)
		{
			infiniteHealth->tick();
			speed->tick();
			aimbot->tick();
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
		printf(" %15s: %s                     \n", infiniteHealth->name.c_str(), (infiniteHealth->enable) ? "Enabled" : "Disabled");
		printf(" %15s: %s                     \n", infiniteAmmo->name.c_str(), (infiniteAmmo->enable) ? "Enabled" : "Disabled");
		printf(" %15s: %s                     \n", noRecoil->name.c_str(), (noRecoil->enable) ? "Enabled" : "Disabled");
		printf(" %15s: %s                     \n", speed->name.c_str(), (speed->enable) ? "Enabled" : "Disabled");
		printf(" %15s: %s                     \n", aimbot->name.c_str(), (aimbot->enable) ? "Enabled" : "Disabled");
		printf(" %15s: %s                     \n", fly->name.c_str(), (fly->enable) ? "Enabled" : "Disabled");
	}
	else
	{ 
		printf("<Server Disabled>\n");
	}
}

void Cheats::cleanup()
{
	hookManager->removeAll();
}


void Cheats::initializeHooks()
{
	hookManager = new HookManager(CSGOExe, ServerDll, ClientDll, EngineDll, serverPlayer);
	hookManager->setClientViewAnglesHook->initialize();
	hookManager->setLocalVelHook->initialize();
	hookManager->setPositionHook->initialize();
	hookManager->setYawOffsetHook->initialize();
	//hookManager->testingHook->initialize();
	//hookManager->drawWeaponGUIHook->initialize();

}


void Cheats::recalculateAddresses()
{
	serverPlayer = (ServerPlayer*)*(uintptr_t*)(ServerDll + ServerPlayerOffset);
	clientPlayer = (ClientPlayer*)*(uintptr_t*)(ClientDll + ClientPlayerOffset);
	C_CSPlayerPtr = *(uintptr_t*)clientPlayer;


	infiniteAmmo->heldWeaponPtr = (uintptr_t)((uintptr_t)serverPlayer->weaponListPtr + HeldWeaponListOffset);
	
	infiniteHealth->player = serverPlayer;
	speed->serverPlayer = serverPlayer;
	aimbot->clientPlayer = clientPlayer;
	fly->serverPlayer = serverPlayer;

	entList->load();
	addressesAreValid = true;
}