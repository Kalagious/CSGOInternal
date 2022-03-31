#include "SetYawOffsetHook.h"
#include <vector>
#include <string>
#include <sstream>
#include "Cheats.h"

extern Cheats* cheatsGlobal;

SetYawOffsetHook::tTargetPtr SetYawOffsetHook::oFunction;


void __fastcall SetYawOffsetHook::hookFunction(ServerPlayer* player)
{
	if (player != cheatsGlobal->serverPlayer || !cheatsGlobal->noRecoil->enable)
		SetYawOffsetHook::oFunction(player);
}



SetYawOffsetHook::SetYawOffsetHook(uintptr_t moduleBaseIn)
{
	hookName = "Set Yaw Offset";
	hookLen = 6;
	moduleBase = moduleBaseIn;
	targetAddr = (moduleBase + setYawOffsetHookOffset);
	enabled = false;
	SetYawOffsetHook::oFunction = (tTargetPtr)(targetAddr);
}


bool SetYawOffsetHook::initialize()
{
	printf("Hooking %s function at %#8x\n", hookName.c_str(), SetYawOffsetHook::oFunction);
	SetYawOffsetHook::oFunction = (tTargetPtr)trampoline32((uintptr_t)SetYawOffsetHook::oFunction, (uintptr_t)SetYawOffsetHook::hookFunction, hookLen);
	enabled = true;
	return true;
}