#pragma once
#include "general.h"
// Created with ReClass.NET 1.2 by KN4CK3R

class ClientRenderMatrixes
{
public:
	char pad_0000[384]; //0x0000
	Matrix3x3 m_RotationMatrix1; //0x0180
	char pad_01A4[220]; //0x01A4
	Matrix4x4 m_PotentialProjectionMatrix1; //0x0280
	char pad_02C0[3620]; //0x02C0
}; //Size: 0x10E4
static_assert(sizeof(ClientRenderMatrixes) == 0x10E4);