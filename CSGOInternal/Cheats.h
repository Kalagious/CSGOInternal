#pragma once
#include "windows.h"
#include "hookmanager.h"
#include "screenmanager.h"
#include "interfacemanager.h"
#include "allmodules.h"
#include "gamestate.h"


class Cheats {
public:
	Cheats();
	void tick();
	void keybinds();
	void cheatStatus();
	void cleanup();
	void recalculateAddresses();

	bool serverCheatsEnabled;
	bool uninject;
	bool firstTick;
	bool addressesAreValid;
	bool loadClientEntityList();
	bool IsValidEnt(ClientPlayer* player);
	bool IsValidAndAliveEnt(ClientPlayer* player);
	HookManager* hookManager;
	ScreenManager* screenManager;
	InterfaceManager* interfaceManger;

	uintptr_t clientEntityListAddress;
	std::vector<ServerPlayer*> serverEntList;
	std::vector<ClientPlayer*> clientEntList;
	uintptr_t C_CSPlayerPtr;
	ServerPlayer* serverPlayer;
	ClientPlayer* clientPlayer;
	ServerWeapon* heldWeapon;
	ClientState* clientState;
	GameState* gameState;
	uintptr_t serverDll, clientDll, engineDll, inputSystemDll;

	std::vector<Module*> modules;
	InfiniteHealth* infiniteHealth;
	NoRecoil* noRecoil;
	InfiniteAmmo* infiniteAmmo;
	Speed* speed;
	Aimbot* aimbot;
	Fly* fly;
	Radar* radar;
	BHop* bhop;
	ESP* esp;
	Tracers* tracers;
};