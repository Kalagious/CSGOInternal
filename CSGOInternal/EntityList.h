#pragma once
#include "ServerPlayer.h"

class ServerEntityList
{
public:
	char pad_0000[28]; //0x0000
	class ServerPlayer* Player0; //0x001C
	char pad_0020[20]; //0x0020
	class ServerPlayer* Player1; //0x0034
	char pad_0038[20]; //0x0038
	class ServerPlayer* Player2; //0x004C
	char pad_0050[20]; //0x0050
	class ServerPlayer* Player3; //0x0064
	char pad_0068[20]; //0x0068
	class ServerPlayer* Player4; //0x007C
	char pad_0080[20]; //0x0080
	class ServerPlayer* Player5; //0x0094
	char pad_0098[20]; //0x0098
	class ServerPlayer* Player6; //0x00AC
	char pad_00B0[20]; //0x00B0
	class ServerPlayer* Player7; //0x00C4
	char pad_00C8[20]; //0x00C8
	class ServerPlayer* Player8; //0x00DC
	char pad_00E0[20]; //0x00E0
	class ServerPlayer* Player9; //0x00F4
	char pad_00F8[3908]; //0x00F8
}; //Size: 0x103C
static_assert(sizeof(ServerEntityList) == 0x103C);

