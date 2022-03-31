#pragma once
#include "General.h"

const uint32_t PlayerCountOffset = 0x4DBDEE0; // client.dll !Only seems to work in real games, not wamrup!
const uint32_t ServerEntityListOffset = 0xA8E270; // server.dll
const uint32_t ClientEntityListOffset = 0x4DD244C; // client.dll

const uint32_t MegaFunctionWithAllPlayerClassFuncsOffset = 0x1ef9a0; // server.dll
const uint32_t ServerClassDefinitionsOffset = 0x9CA074; // server.dll

const uint32_t PlayerMemberFunctionDescOffset1 = 0xA8D334; // server.dll
const uint32_t PlayerMemberFunctionDescOffset2 = 0xA8D344; // server.dll

const uint32_t ClientStateOffset = 0x58CFC4; // engine.dll
const uint32_t ServerPlayerOffset = 0xA8E28C; // server.dll
const uint32_t ClientPlayerOffset = 0xDB65DC; // client.dll

const uint32_t HeldWeaponListOffset = 0x54; 
