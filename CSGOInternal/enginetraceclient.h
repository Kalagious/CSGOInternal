#pragma once
#include "general.h"
// Created with ReClass.NET 1.2 by KN4CK3R

class IConVar
{
public:
	char pad_0004[8]; //0x0004
	char* s_Name; //0x000C
	char* s_Desc; //0x0010
	char pad_0014[68]; //0x0014

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
}; //Size: 0x0058
static_assert(sizeof(IConVar) == 0x58);

class EngineTraceClient
{
public:
	char pad_0004[44]; //0x0004
	char* s_InterfaceName; //0x0030
	char pad_0034[8]; //0x0034
	class IConVar occlusion_test_async; //0x003C
	class IConVar occlusion_test_async_move_tolerance; //0x0094
	class IConVar occlusion_test_async_jitter; //0x00EC
	class IConVar occlusion_test_margins; //0x0144

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void TraceRay();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
}; //Size: 0x019C
static_assert(sizeof(EngineTraceClient) == 0x19C);