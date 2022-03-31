#pragma once
#include "General.h"
// Created with ReClass.NET 1.2 by KN4CK3R

class ServerPlayer
{
public:
	char pad_0004[40]; //0x0004
	Vector3 position; //0x002C
	char pad_0038[40]; //0x0038
	char* classType; //0x0060
	char pad_0064[8]; //0x0064
	float timeAlive; //0x006C
	char pad_0070[80]; //0x0070
	float noIdea; //0x00C0
	char pad_00C4[8]; //0x00C4
	uint32_t ticks; //0x00CC
	uint32_t noIdea2; //0x00D0
	char pad_00D4[168]; //0x00D4
	Vector3 velocity; //0x017C
	char pad_0188[84]; //0x0188
	Vector3 postion2; //0x01DC
	char pad_01E8[12]; //0x01E8
	Vector3 velocity2; //0x01F4
	char pad_0200[48]; //0x0200
	uint32_t health; //0x0230
	char pad_0234[168]; //0x0234
	Vector3 position3; //0x02DC
	char pad_02E8[4]; //0x02E8
	float yaw; //0x02EC
	char pad_02F0[312]; //0x02F0
	float fineYawChange; //0x0428
	float finePitchChange; //0x042C
	char pad_0430[1556]; //0x0430
	uint32_t inputs; //0x0A44
	char pad_0A48[4]; //0x0A48
	float recoilX; //0x0A4C
	float recoilSomething1; //0x0A50
	char pad_0A54[4]; //0x0A54
	float recoilY; //0x0A58
	float recoilSomethin2; //0x0A5C
	char pad_0A60[4]; //0x0A60
	float recoilZ; //0x0A64
	float recoilSomething3; //0x0A68
	char pad_0A6C[1332]; //0x0A6C
	int32_t armor; //0x0FA0
	char pad_0FA4[2024]; //0x0FA4
	uint32_t team; //0x178C
	char pad_1790[5400]; //0x1790
	class N000022C0* weaponListPtr; //0x2CA8
	char pad_2CAC[1328]; //0x2CAC

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
}; //Size: 0x31DC
static_assert(sizeof(ServerPlayer) == 0x31DC);

class N000022C0
{
public:
	char pad_0000[68]; //0x0000
}; //Size: 0x0044
static_assert(sizeof(N000022C0) == 0x44);