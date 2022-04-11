#include "TestingHook.h"
#include <vector>
#include <string>
#include <sstream>
#include "Cheats.h"

extern Cheats* cheatsGlobal;

TestingHook::tTargetPtr TestingHook::oFunction;


void __cdecl TestingHook::hookFunction(uint32_t param1, uint32_t param2, uint32_t param3, char param4, char param5)
{
	printf("1[ %d ] 2[ %d ] 3[ %d ] 4[ %c ] 5[ %c ]\n", param1, param2, param3, param4, param5);
	TestingHook::oFunction(param1, param2, param3, param4, param5);
}



TestingHook::TestingHook(uintptr_t moduleBaseIn)
{
	hookName = "Testing Hook";
	hookLen = 6;
	moduleBase = moduleBaseIn;
	targetAddr = (moduleBase + testingHookOffset);
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