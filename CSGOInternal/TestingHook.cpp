#include "TestingHook.h"
#include <vector>
#include <string>
#include <sstream>
#include "Cheats.h"

extern Cheats* cheatsGlobal;

TestingHook::tTargetPtr TestingHook::oFunction;


void __cdecl TestingHook::hookFunction(void* thisPtr, void* unused, int a2, int a3, int a4, void* a5)
{
	printf("1[ %#8X ] 2[ %d ] 3[ %d ] 4[ %c ] 5[ %c ]\n", thisPtr, a2, a3, a4, a5);
	TestingHook::oFunction(thisPtr, unused, a2, a3, a4, a5);
}



TestingHook::TestingHook(uintptr_t moduleBaseIn)
{
	hookName = "Testing Hook TraceRay";
	hookLen = 6;
	moduleBase = moduleBaseIn;
	targetAddr = (moduleBase + TraceRayFunctionOffset);
	enabled = false;
	TestingHook::oFunction = (tTargetPtr)(targetAddr);
}


bool TestingHook::initialize()
{
	PrintHookPrompt();	
	TestingHook::oFunction = (tTargetPtr)trampoline32((uintptr_t)TestingHook::oFunction, (uintptr_t)TestingHook::hookFunction, hookLen);
	enabled = true;
	return true;
}