#pragma once
#include "Module.h"

class BHop : public Module
{
public:
	BHop();
	bool tick();
	typedef void(__fastcall* t_JumpFunction)();
	static t_JumpFunction f_jump;
};