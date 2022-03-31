#include "DrawWeaponGUIHook.h"
#include <vector>
#include <string>
#include <sstream>
#include "Cheats.h"

extern Cheats* cheatsGlobal;

DrawWeaponGUIHook::tTargetPtr DrawWeaponGUIHook::oFunction;


void __cdecl DrawWeaponGUIHook::hookFunction(void)
{
	printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
	DrawWeaponGUIHook::oFunction();
}



DrawWeaponGUIHook::DrawWeaponGUIHook(uintptr_t moduleBaseIn)
{
	hookName = "Draw Weapon GUI";
	hookLen = 6;
	moduleBase = moduleBaseIn;
	targetAddr = (moduleBase + drawWeaponGUIHookOffset);
	enabled = false;
	DrawWeaponGUIHook::oFunction = (tTargetPtr)(targetAddr);
}


bool DrawWeaponGUIHook::initialize()
{
	printf("Hooking %s function at %#8x\n", hookName.c_str(), DrawWeaponGUIHook::oFunction);
	DrawWeaponGUIHook::oFunction = (tTargetPtr)trampoline32((uintptr_t)DrawWeaponGUIHook::oFunction, (uintptr_t)DrawWeaponGUIHook::hookFunction, hookLen);
	enabled = true;
	return true;
}