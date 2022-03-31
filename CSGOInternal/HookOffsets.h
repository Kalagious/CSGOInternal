#pragma once
#include <stdint.h>

const uint32_t setPositionHookOffset = 0x1F8120; // server.dll
const uint32_t setLocalVelHookOffset = 0x1F8870; // server.dll
const uint32_t setYawOffsetHookOffset = 0x484b90; // server.dll
const uint32_t setClientViewAnglesHookOffset = 0xb24e0; // engine.dll
const uint32_t drawWeaponGUIHookOffset = 0x52ac10; // client.dll
const uint32_t testingHookOffset = 0x5074a0; // client.dll