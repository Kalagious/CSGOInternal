#include "interfacemanager.h"


InterfaceManager::InterfaceManager()
{
	engineTraceClient = NULL;
	initialized = false;
}

bool InterfaceManager::intializeInterfaces()
{
	engineTraceClient = (EngineTraceClient*)getInterface(EngineTraceClientModule, EngineTraceClientI);
	clientEntityList = (ClientEntityList*)getInterface(ClientEntityListModule, ClientEntityListI);
	initialized = true;
	return true;
}


uintptr_t InterfaceManager::getInterface(std::string moduleName, std::string interfaceName)
{
	std::wstring wModuleName = std::wstring(moduleName.begin(), moduleName.end());
	tGetInterface oGetInterface = (tGetInterface)GetProcAddress(GetModuleHandle(wModuleName.c_str()), "CreateInterface");

	int tmp = 0;
	return (uintptr_t)oGetInterface(interfaceName.c_str(), &tmp);
}