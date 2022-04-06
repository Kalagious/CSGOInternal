#pragma once
#include "Module.h"
#include "ServerWeapon.h"

class InfiniteAmmo : public Module
{
public:
	InfiniteAmmo();
	uintptr_t heldWeaponPtr;
	bool tick();
};