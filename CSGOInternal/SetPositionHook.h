#pragma once
#include "Hooks.h"


class SetPositionHook : public Hook
{
public:

	bool initialize();
	SetPositionHook(uintptr_t moduleBaseIn);

	typedef void (__fastcall* tTargetPtr)(ServerPlayer* player, void* unused, float* position);
	static tTargetPtr oFunction;

	static void __fastcall hookFunction(ServerPlayer* player, void* unused, float* position);

};

