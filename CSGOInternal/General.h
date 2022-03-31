#pragma once
#include "windows.h"
#include <stdint.h>
#include <vector>


void mainCode(HMODULE hModule);
extern const float PI;

class Vector3
{
public:
	Vector3(float xIn, float yIn, float zIn) { x = xIn; y = yIn; z = zIn; }
	float x, y, z;
};