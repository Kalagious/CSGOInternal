#include "hookmanager.h"


HookManager::HookManager(uintptr_t ServerDllIn, uintptr_t ClientDllIn, uintptr_t EngineDllIn)
{
	ServerDll = ServerDllIn;
	ClientDll = ClientDllIn;
	EngineDll = EngineDllIn;
	serverPlayer = NULL;
	setLocalVelHook = new SetLocalVelHook(ServerDll);
	setPositionHook = new SetPositionHook(ServerDll);
	setYawOffsetHook = new SetYawOffsetHook(ServerDll);
	setClientViewAnglesHook = new SetClientViewAnglesHook(EngineDll);
	testingHook = new TestingHook(ClientDll);
}


void HookManager::InitalizeHooks()
{
	printf(" [*] Initializing Game Hooks:\n");
	if (!setClientViewAnglesHook->enabled)
		setClientViewAnglesHook->initialize();
	if (!setLocalVelHook->enabled)
		setLocalVelHook->initialize();
	if (!setPositionHook->enabled)
		setPositionHook->initialize();
	if (!setYawOffsetHook->enabled)
		setYawOffsetHook->initialize();
	printf(" [*] Hooks Initialized!\n\n");
}


void HookManager::removeAll()
{
	if (setLocalVelHook->enabled)
		setLocalVelHook->remove();

	if (setPositionHook->enabled)
		setPositionHook->remove();

	if (setClientViewAnglesHook->enabled)
		setClientViewAnglesHook->remove();

	if (setYawOffsetHook->enabled)
		setYawOffsetHook->remove();
}