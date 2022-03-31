#include "SetPositionHook.h"
#include <vector>
#include <string>
#include <sstream>
#include "Cheats.h"

extern Cheats* cheatsGlobal;

SetPositionHook::tTargetPtr SetPositionHook::oFunction;


void __fastcall SetPositionHook::hookFunction(ServerPlayer* player, void* unused, float* position)
{	
	if (!isnan(cheatsGlobal->fly->xPos) && !isnan(cheatsGlobal->fly->xPos) && !isnan(cheatsGlobal->fly->zPos) &&
		player == cheatsGlobal->serverPlayer && cheatsGlobal->fly->enable && cheatsGlobal->serverPlayer->health > 0)
	{
		position[0] = position[0] + cheatsGlobal->fly->xPos;
		position[1] = position[1] + cheatsGlobal->fly->yPos;
		position[2] = position[2] + cheatsGlobal->fly->zPos;
	}
	SetPositionHook::oFunction(player, unused, position);
}



SetPositionHook::SetPositionHook(uintptr_t moduleBaseIn)
{	
	hookName = "Move";
	hookLen = 6;
	moduleBase = moduleBaseIn;
	targetAddr = (moduleBase + setPositionHookOffset);
	enabled = false;
	SetPositionHook::oFunction = (tTargetPtr)(targetAddr);
}


bool SetPositionHook::initialize()
{
	printf("%s function at %#8x\n", hookName.c_str(), SetPositionHook::oFunction);
	SetPositionHook::oFunction = (tTargetPtr)trampoline32((uintptr_t)SetPositionHook::oFunction, (uintptr_t)SetPositionHook::hookFunction, hookLen);
	enabled = true;
	return true;
}