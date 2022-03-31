#pragma once
#include "Hooks.h"


class TestingHook : public Hook
{
public:

	bool initialize();
	TestingHook(uintptr_t moduleBaseIn);
	typedef void(__cdecl* tTargetPtr)(int param1, int param2, int param3, char param4, char param5);
	static tTargetPtr oFunction;

	static void __cdecl hookFunction(int param1, int param2, int param3, char param4, char param5);
};

