#include "endscenehook.h"
#include "screenmanager.h"
#include "cheats.h"

extern Cheats* cheatsGlobal;
EndSceneHook::tTargetPtr EndSceneHook::oFunction;

void APIENTRY EndSceneHook::hookFunction(LPDIRECT3DDEVICE9 device)
{
	if (!ScreenManager::d3dDevice)
		ScreenManager::d3dDevice = device;
	cheatsGlobal->screenManager->FilledRect(cheatsGlobal->screenManager->gameDimensions.cx, cheatsGlobal->screenManager->gameDimensions.cy, 50, 50, D3DCOLOR_ARGB(0, 0, 255, 255));
	oFunction(device);
}



EndSceneHook::EndSceneHook(uintptr_t endSceneAddr)
{
	hookName = "End Scene Hook";
	hookLen = 7;
	moduleBase = NULL;
	targetAddr = endSceneAddr;
	enabled = false;
	EndSceneHook::oFunction = (tTargetPtr)(targetAddr);
}


bool EndSceneHook::initialize()
{
	printf("Hooking %s function at %#8x\n", hookName.c_str(), (uintptr_t)EndSceneHook::oFunction);
	EndSceneHook::oFunction = (tTargetPtr)trampoline32((uintptr_t)EndSceneHook::oFunction, (uintptr_t)EndSceneHook::hookFunction, hookLen);
	enabled = true;
	return true;
}