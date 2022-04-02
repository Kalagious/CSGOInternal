#pragma once
#include "General.h"
// Created with ReClass.NET 1.2 by KN4CK3R

class ICollideable
{
public:
	char pad_0000[92]; //0x0000
}; //Size: 0x005C
static_assert(sizeof(ICollideable) == 0x5C);

class CParticleProperty
{
public:
	char pad_0000[72]; //0x0000
}; //Size: 0x0048
static_assert(sizeof(CParticleProperty) == 0x48);

class IInterpolatedVar
{
public:
	char pad_0000[44]; //0x0000
}; //Size: 0x002C
static_assert(sizeof(IInterpolatedVar) == 0x2C);

class ClientPlayer
{
public:
	char pad_0000[32]; //0x0000
	float f_DistTraveled; //0x0020
	char pad_0024[24]; //0x0024
	float f_SecondsSinceCreation; //0x003C
	char pad_0040[84]; //0x0040
	Vector3 v_Velocity1; //0x0094
	Vector3 v_Position1; //0x00A0
	Vector3 v_Position2; //0x00AC
	char pad_00B8[69]; //0x00B8
	bool b_Dormant; //0x00FD
	char pad_00FE[2]; //0x00FE
	int32_t i_Health; //0x0100
	char pad_0104[12]; //0x0104
	float f_PlayerHeight; //0x0110
	Vector3 v_Velocity2; //0x0114
	char pad_0120[12]; //0x0120
	float f_Pitch; //0x012C
	float f_Yaw; //0x0130
	char pad_0134[492]; //0x0134
	class ICollideable ic_m_CollisionObject; //0x0320
	class CParticleProperty cpp_m_ParticleProperty; //0x037C
	class IInterpolatedVar m_iv_vecOrigin; //0x03C4
	char pad_03F0[20]; //0x03F0
	class IInterpolatedVar m_iv_angRotation; //0x0404
	char pad_0430[11332]; //0x0430
	class IInterpolatedVar m_iv_viewPunchAngle; //0x3074
	class IInterpolatedVar m_iv_aimPunchAngle; //0x30A0
	class IInterpolatedVar m_iv_aimPunchAngleVel; //0x30CC
	char pad_30F8[744]; //0x30F8
	class IInterpolatedVar m_iv_vecViewOffset; //0x33E0
	char pad_340C[1480]; //0x340C
}; //Size: 0x39D4
static_assert(sizeof(ClientPlayer) == 0x39D4);
