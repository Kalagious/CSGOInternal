#include "hookmanager.h"



HookManager::HookManager(uintptr_t CSGOExeIn, uintptr_t ServerDllIn, uintptr_t ClientDllIn, uintptr_t EngineDllIn, ServerPlayer* serverPlayerIn)
{
	CSGOExe = CSGOExeIn;
	ServerDll = ServerDllIn;
	ClientDll = ClientDllIn;
	EngineDll = EngineDllIn;
	serverPlayer = serverPlayerIn;
	setLocalVelHook = new SetLocalVelHook(ServerDll);
	setPositionHook = new SetPositionHook(ServerDll);
	setYawOffsetHook = new SetYawOffsetHook(ServerDll);
	setClientViewAnglesHook = new SetClientViewAnglesHook(EngineDll);
	drawWeaponGUIHook = new DrawWeaponGUIHook(ClientDll);
	testingHook = new TestingHook(ClientDll);
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

	if (drawWeaponGUIHook->enabled)
		drawWeaponGUIHook->remove();
}