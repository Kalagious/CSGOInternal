#pragma once
#include "Module.h"

class NoRecoil : public Module
{
public:
	NoRecoil();
	bool tick() { return false; }
};