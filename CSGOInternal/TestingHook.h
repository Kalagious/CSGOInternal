#pragma once
#include "Hooks.h"


class TestingHook : public Hook
{
public:

	bool initialize();
	TestingHook(uintptr_t moduleBaseIn);
	typedef void(__cdecl* tTargetPtr)(uint32_t param1, uint32_t param2, uint32_t param3, char param4, char param5);
	static tTargetPtr oFunction;

	static void __cdecl hookFunction(uint32_t param1, uint32_t param2, uint32_t param3, char param4, char param5);
};

