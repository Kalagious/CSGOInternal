#pragma once
#include "General.h"
// Created with ReClass.NET 1.2 by KN4CK3R

class ClientState
{
public:
	char pad_0000[19856]; //0x0000
	float pitch; //0x4D90
	float yaw; //0x4D94
	char pad_4D98[680]; //0x4D98
}; //Size: 0x5040
static_assert(sizeof(ClientState) == 0x5040);