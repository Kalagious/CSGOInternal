#pragma once
#include "general.h"
#include "interfaces.h"
#include "allclasses.h"



class InterfaceManager
{
public:
	InterfaceManager();
	bool intializeInterfaces();

	typedef void* (__cdecl* tGetInterface)(const char* interfaceName, int* returnCode);
	uintptr_t getInterface(std::string moduleName, std::string interfaceName);
	
	EngineTraceClient* engineTraceClient;
	ClientEntityList* clientEntityList;
	bool initialized;
};