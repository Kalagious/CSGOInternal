#pragma once
#include "Hooks.h"


class SetLocalVelHook : public Hook
{
public:

	bool initialize();
	SetLocalVelHook(uintptr_t moduleBaseIn);
	typedef void (__fastcall* tTargetPtr)(ServerPlayer* player, void* unused, float* velocity);
	static tTargetPtr oFunction;

	static void __fastcall hookFunction(ServerPlayer* player, void* unused, float* velocity);
};

