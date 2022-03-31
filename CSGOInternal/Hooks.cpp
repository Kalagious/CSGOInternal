#include "Hooks.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include <tlHelp32.h>
#include <stdint.h>
#include <tchar.h>


bool Hook::detour32(uintptr_t src, uintptr_t dst, uint32_t len)
{
	if (len < 5) return false;

	DWORD oldProtect;
	VirtualProtect((BYTE*)src, len, PAGE_EXECUTE_READWRITE, &oldProtect);

	uintptr_t relativeAddress = dst - src - 5;

	// Save the original stolen bytes to be later replaced
	memcpy(stolenBytes, (BYTE*)src, len);

	memset((BYTE*)src, 0x90, len);


	*(uintptr_t*)src = 0xE9;
	*(uintptr_t*)(src + 1) = relativeAddress;


	VirtualProtect((BYTE*)src, len, oldProtect, &oldProtect);
	return true;
}







uintptr_t Hook::trampoline32(uintptr_t src, uintptr_t dst, uint32_t len)
{
	if (len < 5) return NULL;
	uintptr_t gatewayAddr = (uintptr_t)VirtualAlloc(NULL, len, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

	if (!gatewayAddr)
	{
		printf("Error allocating gateway\n");
		return false;
	}

	DWORD oldProtect;
	VirtualProtect((BYTE*)src, len, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy((BYTE*)gatewayAddr, (BYTE*)src, len);
	VirtualProtect((BYTE*)src, len, oldProtect, &oldProtect);

	uintptr_t relativeAddrFrGatewayToSrc = (uintptr_t)(src - 5) - gatewayAddr;

	*(uintptr_t*)(gatewayAddr + len) = 0xE9;
	*(uintptr_t*)(gatewayAddr + len + 1) = relativeAddrFrGatewayToSrc;

	detour32(src, dst, len);

	trampAddr = gatewayAddr;

	return gatewayAddr;
}



bool Hook::remove()
{
	printf(" [*] Unhooking %s at %#8X\n", hookName.c_str(), targetAddr);
	DWORD oldProtect;
	VirtualProtect((BYTE*)targetAddr, hookLen, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy((BYTE*)targetAddr, stolenBytes, hookLen);
	VirtualProtect((BYTE*)targetAddr, hookLen, oldProtect, &oldProtect);
	enabled = false;
	return true;
}

