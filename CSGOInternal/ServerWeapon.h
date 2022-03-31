#pragma once
#include "General.h"
// Created with ReClass.NET 1.2 by KN4CK3R

class ServerWeapon
{
public:
	char pad_0004[92]; //0x0004
	char* name; //0x0060
	char pad_0064[1045]; //0x0064
	int8_t N00000173; //0x0479
	char pad_047A[1258]; //0x047A
	uint32_t currentMag; //0x0964
	char pad_0968[4]; //0x0968
	uint32_t reserveAmmo; //0x096C
	char pad_0970[280]; //0x0970
	float spread; //0x0A88
	char pad_0A8C[460]; //0x0A8C

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
}; //Size: 0x0C58
static_assert(sizeof(ServerWeapon) == 0xC58);