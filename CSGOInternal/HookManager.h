#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include <tlHelp32.h>
#include <stdint.h>
#include <tchar.h>
#include "allclasses.h"
#include "setlocalvelhook.h"
#include "setpositionhook.h"
#include "setclientviewangleshook.h"
#include "setyawoffsethook.h"
#include "testinghook.h"
#include "endscenehook.h"

class HookManager
{
public:
	SetLocalVelHook* setLocalVelHook;
	SetPositionHook* setPositionHook;
	SetYawOffsetHook* setYawOffsetHook;
	SetClientViewAnglesHook* setClientViewAnglesHook;
	TestingHook* testingHook;
	HookManager(uintptr_t ServerDllIn, uintptr_t ClientDllIn, uintptr_t EngineDllIn);
	void removeAll();
	void InitalizeHooks();
	uintptr_t ServerDll, ClientDll, EngineDll;
	ServerPlayer* serverPlayer;

};