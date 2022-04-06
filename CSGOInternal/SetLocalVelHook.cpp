#include "SetLocalVelHook.h"
#include <vector>
#include <string>
#include <sstream>
#include "Cheats.h"

extern Cheats* cheatsGlobal;

SetLocalVelHook::tTargetPtr SetLocalVelHook::oFunction;


void __fastcall SetLocalVelHook::hookFunction(ServerPlayer* player, void* unused, float* velocity)
{
	if (!isnan(cheatsGlobal->speed->xVel) && !isnan(cheatsGlobal->speed->xVel) && velocity[0] != 0 && velocity[1] != 0 &&
		player == cheatsGlobal->serverPlayer && cheatsGlobal->speed->enable && !cheatsGlobal->fly->enable && cheatsGlobal->serverPlayer->health > 0)
	{
		velocity[0] = cheatsGlobal->speed->xVel;
		velocity[1] = cheatsGlobal->speed->yVel;
		cheatsGlobal->serverPlayer->velocity2.x = 0;
		cheatsGlobal->serverPlayer->velocity2.y = 0;
	}
	else if (cheatsGlobal->fly->enable && player == cheatsGlobal->serverPlayer)
	{
		velocity[0] = 0;
		velocity[1] = 0;
		velocity[2] = 0;
	}
	SetLocalVelHook::oFunction(player, unused, velocity);
}


	
SetLocalVelHook::SetLocalVelHook(uintptr_t moduleBaseIn)
{
	hookName = "Set Local Vel";
	hookLen = 6;
	moduleBase = moduleBaseIn;
	targetAddr = (moduleBase + setLocalVelHookOffset);
	enabled = false;
	SetLocalVelHook::oFunction = (tTargetPtr)(targetAddr);
}


bool SetLocalVelHook::initialize()
{
	printf("Hooking %s function at %#8x\n", hookName.c_str(), (uintptr_t)SetLocalVelHook::oFunction);
	SetLocalVelHook::oFunction = (tTargetPtr)trampoline32((uintptr_t)SetLocalVelHook::oFunction, (uintptr_t)SetLocalVelHook::hookFunction, hookLen);
	enabled = true;
	return true;
}