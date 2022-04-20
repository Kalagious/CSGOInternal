#include "endscenehook.h"
#include "screenmanager.h"
#include "cheats.h"

extern Cheats* cheatsGlobal;
extern ScreenManager* screenManagerGlobal;

EndSceneHook::tTargetPtr EndSceneHook::oFunction;

void APIENTRY EndSceneHook::hookFunction(LPDIRECT3DDEVICE9 device)
{
	cheatsGlobal->aimbot->tick();

	if (!ScreenManager::d3dDevice)
		ScreenManager::d3dDevice = device;

	if (!cheatsGlobal->esp->initialized && ScreenManager::d3dDevice)
		cheatsGlobal->esp->initialize();

	if (!screenManagerGlobal->imGUIIsInitialized && ScreenManager::d3dDevice)
		screenManagerGlobal->InitializeImGUI();

	if (!cheatsGlobal->esp->tick())
		cheatsGlobal->addressesAreValid = false;

	if (!cheatsGlobal->tracers->tick())
		cheatsGlobal->addressesAreValid = false;

	if (screenManagerGlobal->imGUIIsInitialized)
		screenManagerGlobal->DrawImGUI();

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
	printf(" [*] Hooking %s function at %#8x\n", hookName.c_str(), (uintptr_t)EndSceneHook::oFunction);
	EndSceneHook::oFunction = (tTargetPtr)trampoline32((uintptr_t)EndSceneHook::oFunction, (uintptr_t)EndSceneHook::hookFunction, hookLen);
	enabled = true;
	return true;
}