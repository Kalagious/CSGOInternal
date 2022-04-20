#pragma once
#include "general.h"

class TraceResult
{
	Vector3 pos1;			// 0x0000
	Vector3 pos2;			// 0x000C
	uint32_t padding[5];	// 0x0018
	uint32_t bigInt;		// 0x002C
	uint32_t padding1[2];	// 0x0030
	float dist;				// 0x0038
};