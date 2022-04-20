#pragma once
#include "general.h"
// Created with ReClass.NET 1.2 by KN4CK3R

class Camera
{
public:
	Vector3 v3_Position; //0x0000
	Vector2 v2_RotationD; //0x000C
	char pad_0014[8]; //0x0014
	float f_AspectRatio; //0x001C
	float f_Near; //0x0020
	float f_Far; //0x0024
	char pad_0028[8]; //0x0028
	Matrix3x4 N0000005C; //0x0030
	char pad_0060[60]; //0x0060
	Matrix4x4 N0000006C; //0x009C
	char pad_00DC[164]; //0x00DC
	Matrix4x4 N00000097; //0x0180
	Matrix4x4 N00000098; //0x01C0
	char pad_0200[4]; //0x0200
	Matrix4x4 m4x4_ProjectionMatrix; //0x0204
	char pad_0244[64]; //0x0244
	Matrix4x4 m4x4_ViewMatrix; //0x0284
	char pad_02C4[80]; //0x02C4
	Matrix4x4 m4x4_VPMatrix; //0x0314
	Matrix4x4 m4x4_ProjectionMatrix2; //0x0354
	Matrix4x4 m4x4_ViewMatrix2; //0x0394
	char pad_03D4[412]; //0x03D4
	Matrix4x4 N00000129; //0x0570
	char pad_05B0[3296]; //0x05B0
}; //Size: 0x1290
static_assert(sizeof(Camera) == 0x1290);