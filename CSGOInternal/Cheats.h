#pragma once
#include "windows.h"
#include "HookManager.h"
#include "AllModules.h"


class Cheats {
public:
	Cheats(uintptr_t CSGOExeIn, uintptr_t ServerDllIn, uintptr_t ClientDllIn, uintptr_t EngineDllIn);
	void tick();
	void keybinds();
	void cheatStatus();
	void cleanup();
	void setTickHook();
	void loadServerEntList(uintptr_t serverEntListAddressIn);
	void loadClientEntList(uintptr_t clientEntListAddressIn);


	bool serverCheatsEnabled;
	bool uninject;
	HookManager* hookManager;
	uintptr_t serverEntityListAddress;
	uintptr_t clientEntityListAddress;
	std::vector<ServerPlayer*> serverEntList;
	std::vector<ClientPlayer*> clientEntList;
	ServerPlayer* serverPlayer;
	ClientPlayer* clientPlayer;
	ServerWeapon* heldWeapon;
	ClientState* clientState;
	uintptr_t CSGOExe, ServerDll, ClientDll, EngineDll;
	InfiniteHealth* infiniteHealth;
	NoRecoil* noRecoil;
	InfiniteAmmo* infiniteAmmo;
	Speed* speed;
	Aimbot* aimbot;
	Fly* fly;
};