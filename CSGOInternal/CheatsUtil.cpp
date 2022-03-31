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

	clientState = (ClientState*)*(uintptr_t*)(EngineDll + ClientStateOffset);
	printf("\nClient Player State at %#8X\n", clientState);


	serverEntityListAddress = (uintptr_t)(ServerDll + ServerEntityListOffset);
	printf("\nServer Entity List found at %#8X\n", serverEntityListAddress);
	loadServerEntList(serverEntityListAddress);

	clientEntityListAddress = (uintptr_t)(ClientDll + ClientEntityListOffset);
	printf("\Client Entity List found at %#8X\n", clientEntityListAddress);
	loadClientEntList(clientEntityListAddress);




	hookManager = new HookManager(CSGOExe, ServerDll, ClientDll, EngineDll, serverPlayer);
	hookManager->setClientViewAnglesHook->initialize();
	hookManager->setLocalVelHook->initialize();
	hookManager->setPositionHook->initialize();
	hookManager->setYawOffsetHook->initialize();
	//hookManager->testingHook->initialize();
	
	infiniteHealth = new InfiniteHealth(serverPlayer);
	infiniteAmmo = new InfiniteAmmo((uintptr_t)((uintptr_t)serverPlayer->weaponListPtr + HeldWeaponListOffset));
	noRecoil = new NoRecoil();
	speed = new Speed(serverPlayer, clientState);
	aimbot = new Aimbot(clientPlayer, clientState, &clientEntList);
	fly = new Fly(serverPlayer, clientState);

	uninject = false;
}

void Cheats::tick()
{

	keybinds();
	//cheatStatus();

	if (serverCheatsEnabled)
	{
		infiniteHealth->tick();
		speed->tick();
		aimbot->tick();
		fly->tick();
		infiniteAmmo->tick();
	}	
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


void Cheats::loadServerEntList(uintptr_t serverEntListAddressIn)
{
	uint32_t itr = 0x1C;
	while (true)
	{
		if (*(uint32_t*)(serverEntListAddressIn + itr) == 0x0)
			break;
		serverEntList.push_back((ServerPlayer*)*(uint32_t*)(serverEntListAddressIn + itr));
		itr += 0x18;
	}
}

void Cheats::loadClientEntList(uintptr_t clientEntListAddressIn)
{
	uint32_t itr = 0x00;
	while (true)
	{
		if (*(uint32_t*)(clientEntListAddressIn + itr) == 0x0)
			break;
		clientEntList.push_back((ClientPlayer*)*(uint32_t*)(clientEntListAddressIn + itr));
		itr += 0x10;
	}
}


void Cheats::cleanup()
{
	hookManager->removeAll();
}


void Cheats::setTickHook()
{
	hookManager->drawWeaponGUIHook->initialize();
}