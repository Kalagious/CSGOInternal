#pragma once
#include "Hooks.h"
// Used for the aimbot

class SetClientViewAnglesHook : public Hook
{
public:

	bool initialize();
	SetClientViewAnglesHook(uintptr_t moduleBaseIn);
	typedef void(__stdcall* tTargetPtr)(float* viewAnglesIn);
	static tTargetPtr oFunction;
	static void __stdcall hookFunction(float* viewAnglesIn);
};

