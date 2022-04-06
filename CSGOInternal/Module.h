#pragma once
#include <iostream>

class Module
{
public:
	bool enable;
	bool serverModule;
	std::string name;
	virtual bool tick() = 0;
	virtual void status() { printf(" %15s: %s                     \n", name.c_str(), (enable) ? "Enabled" : "Disabled"); }
};