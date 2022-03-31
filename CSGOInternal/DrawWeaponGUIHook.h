#pragma once
#include "Hooks.h"


class DrawWeaponGUIHook : public Hook
{
public:

	bool initialize();
	DrawWeaponGUIHook(uintptr_t moduleBaseIn);
	typedef void(__cdecl* tTargetPtr)(void);
	static tTargetPtr oFunction;

	static void __cdecl hookFunction(void);
};

