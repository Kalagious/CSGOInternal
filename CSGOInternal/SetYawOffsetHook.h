#pragma once
#include "Hooks.h"


class SetYawOffsetHook : public Hook
{
public:

	bool initialize();
	SetYawOffsetHook(uintptr_t moduleBaseIn);
	typedef void(__fastcall* tTargetPtr)(ServerPlayer* player);
	static tTargetPtr oFunction;

	static void __fastcall hookFunction(ServerPlayer* player);
};

