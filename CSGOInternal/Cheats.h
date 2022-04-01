#pragma once
#include "windows.h"
#include "HookManager.h"
#include "AllModules.h"
#include "GameState.h"
#include "EntList.h"


class Cheats {
public:
	Cheats(uintptr_t CSGOExeIn, uintptr_t ServerDllIn, uintptr_t ClientDllIn, uintptr_t EngineDllIn);
	void tick();
	void keybinds();
	void cheatStatus();
	void cleanup();
	void initializeHooks();
	void recalculateAddresses();

	bool serverCheatsEnabled;
	bool uninject;
	bool firstTick;
	bool addressesAreValid;
	HookManager* hookManager;
	uintptr_t clientEntityListAddress;
	std::vector<ServerPlayer*> serverEntList;
	std::vector<ClientPlayer*> clientEntList;
	ServerPlayer* serverPlayer;
	ClientPlayer* clientPlayer;
	ServerWeapon* heldWeapon;
	ClientState* clientState;
	GameState* gameState;
	EntList* entList;
	uintptr_t CSGOExe, ServerDll, ClientDll, EngineDll;
	InfiniteHealth* infiniteHealth;
	NoRecoil* noRecoil;
	InfiniteAmmo* infiniteAmmo;
	Speed* speed;
	Aimbot* aimbot;
	Fly* fly;
};