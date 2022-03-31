#include <iostream>
#include "windows.h"
#include "HookOffsets.h"

bool detour32(uintptr_t src, uintptr_t dst, const int len)
{
	if (len < 5) return false;

	DWORD oldProtect;
	VirtualProtect((BYTE*)src, len, PAGE_EXECUTE_READWRITE, &oldProtect);

	uintptr_t relativeAddress = dst - src - 5;

	// Save the original stolen bytes to be later replaced
	memset((BYTE*)src, 0x90, len);


	*(uintptr_t*)src = 0xE9;
	*(uintptr_t*)(src + 1) = relativeAddress;

	VirtualProtect((BYTE*)src, len, oldProtect, &oldProtect);
	return true;
}


uintptr_t trampoline32(uintptr_t src, uintptr_t dst, const int len)
{
	printf("Hooking %#8X\n", src);
	if (len < 5) return NULL;
	uintptr_t gatewayAddr = (uintptr_t)VirtualAlloc(NULL, len, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

	if (!gatewayAddr)
	{
		printf("Error allocating gateway\n");
		return false;
	}


	printf("Gateway allocated at %#8X\n", gatewayAddr);

	DWORD oldProtect;
	VirtualProtect((BYTE*)src, len, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy((BYTE*)gatewayAddr, (BYTE*)src, len);
	VirtualProtect((BYTE*)src, len, oldProtect, &oldProtect);

	uintptr_t relativeAddrFrGatewayToSrc = (uintptr_t)(src - 5) - gatewayAddr;

	*(uintptr_t*)(gatewayAddr + len) = 0xE9;
	*(uintptr_t*)(gatewayAddr + len + 1) = relativeAddrFrGatewayToSrc;

	printf("%#8X - %#8X - 5 = %#8X\n", src, gatewayAddr, relativeAddrFrGatewayToSrc);
	detour32(src, dst, len);

	return gatewayAddr;
}



typedef void (__fastcall* tTargetPtr)(void* player, float* velocity);
tTargetPtr oMoveFunction;


void __fastcall hookFunction(void* player, float* velocity)
{
	printf("Hook Hit\n");
	oMoveFunction(player, velocity);
}
void hook(uintptr_t serverdll)
{
	oMoveFunction = (tTargetPtr)trampoline32((uintptr_t)serverdll + moveOffset, (uintptr_t)hookFunction, 6);
}
