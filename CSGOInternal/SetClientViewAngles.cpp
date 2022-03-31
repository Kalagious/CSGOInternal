#include "SetClientViewAnglesHook.h"
#include <vector>
#include <string>
#include <sstream>
#include"Cheats.h"


// Used for the aimbot

extern Cheats* cheatsGlobal;

SetClientViewAnglesHook::tTargetPtr SetClientViewAnglesHook::oFunction;



void __stdcall SetClientViewAnglesHook::hookFunction(float* viewAnglesIn)
{
	if (cheatsGlobal->aimbot->enable)
	{
		viewAnglesIn[1] = cheatsGlobal->aimbot->newYawOut;
		viewAnglesIn[0] = cheatsGlobal->aimbot->newPitchOut;
	}
	SetClientViewAnglesHook::oFunction(viewAnglesIn);
}



SetClientViewAnglesHook::SetClientViewAnglesHook(uintptr_t moduleBaseIn)
{
	hookName = "View Angles";
	hookLen = 6;
	moduleBase = moduleBaseIn;
	targetAddr = (moduleBase + setClientViewAnglesHookOffset);
	enabled = false;
	SetClientViewAnglesHook::oFunction = (tTargetPtr)(targetAddr);
}


bool SetClientViewAnglesHook::initialize()
{
	SetClientViewAnglesHook::oFunction = (tTargetPtr)trampoline32((uintptr_t)SetClientViewAnglesHook::oFunction, (uintptr_t)SetClientViewAnglesHook::hookFunction, hookLen);
	enabled = true;
	return true;
}

