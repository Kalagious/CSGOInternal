#pragma once
#include <vector>
#include <windows.h>
#include <tlHelp32.h>
#include <stdint.h>
#include <tchar.h>
#include <iostream>
#include "AllClasses.h"
#include "HookOffsets.h"


class Hook
{
public:
	std::string hookName;
	uint32_t hookLen;
	uintptr_t moduleBase;
	uintptr_t targetAddr;
	uintptr_t trampAddr;
	uint32_t stolenBytes[10];
	bool enabled;

	bool detour32(uintptr_t src, uintptr_t dst, uint32_t len);
	uintptr_t trampoline32(uintptr_t src, uintptr_t dst, uint32_t len);
	bool remove();
};

