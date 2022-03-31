#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include <tlHelp32.h>
#include <stdint.h>
#include <tchar.h>
#include "AllClasses.h"
#include "SetLocalVelHook.h"
#include "SetPositionHook.h"
#include "SetClientViewAnglesHook.h"
#include "SetYawOffsetHook.h"
#include "DrawWeaponGUIHook.h"
#include "TestingHook.h"

class HookManager
{
public:
	SetLocalVelHook* setLocalVelHook;
	SetPositionHook* setPositionHook;
	SetYawOffsetHook* setYawOffsetHook;
	SetClientViewAnglesHook* setClientViewAnglesHook;
	DrawWeaponGUIHook* drawWeaponGUIHook;
	TestingHook* testingHook;
	HookManager(uintptr_t CSGOExeIn, uintptr_t ServerDllIn, uintptr_t ClientDllIn, uintptr_t EngineDllIn, ServerPlayer* serverPlayerIn);
	void removeAll();
	uintptr_t CSGOExe, ServerDll, ClientDll, EngineDll;
	ServerPlayer* serverPlayer;

};