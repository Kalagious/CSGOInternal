#pragma once
#include "General.h"
	
const uint32_t PlayerCountOffset = 0x4DBDEE0; // client.dll !Only seems to work in real games, not wamrup!
const uint32_t ServerEntityListOffset = 0xA8E270; // server.dll
const uint32_t ClientEntityListOffset = 0x4DD2448; // client.dll
const uint32_t EngineTraceClientOffset = 0x59789C; // engine.dll

const uint32_t MegaFunctionWithAllPlayerClassFuncsOffset = 0x1ef9a0; // server.dll
const uint32_t ServerClassDefinitionsOffset = 0x9CA074; // server.dll

const uint32_t PlayerMemberFunctionDescOffset1 = 0xA8D334; // server.dll
const uint32_t PlayerMemberFunctionDescOffset2 = 0xA8D344; // server.dll

const uint32_t ClientStateOffset = 0x58CFC4; // engine.dll
const uint32_t ServerPlayerOffset = 0xA8E28C; // server.dll
const uint32_t ClientPlayerOffset = 0xDB65DC; // client.dll
const uint32_t RenderMatrixesOffset = 0x04DC3AF0; // client.dll
const uint32_t PlayerCameraOffset = 0x04DC3AF0; //client.dll

const uint32_t HeldWeaponListOffset = 0x54; 
const uint32_t b_IsInGameOffset = 0x5224D24; // client.dll
const uint32_t InputBitfieldsOffset = 0x79A635FC; // inputsystem.dll

// Functions
const uint32_t TraceRayFunctionOffset = 0x201580; // engine.dll

