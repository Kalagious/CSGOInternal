#pragma once
#include "Hooks.h"


class TestingHook : public Hook
{
public:

	bool initialize();
	TestingHook(uintptr_t moduleBaseIn);
	typedef void(__fastcall* tTargetPtr)(void* thisPtr, void* unused, int a2, int a3, int a4, void* a5);
	static tTargetPtr oFunction;

	static void __cdecl hookFunction(void* thisPtr, void* unused, int a2, int a3, int a4, void* a5);
};

