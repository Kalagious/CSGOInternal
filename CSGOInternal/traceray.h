#pragma once
#include "offsets.h"
#include "clientplayer.h"

class TraceRay
{
public:
	TraceRay();
	typedef void(__fastcall* tTraceRayPtr)(void* thisPtr, void* unused, int a2, int a3, int a4, void* a5);
	tTraceRayPtr f_TraceRay;

	ClientPlayer* TraceLookVectorForEnt(ClientPlayer player, float dist);
};