#pragma once
#include <vector>
#include <windows.h>
#include <tlHelp32.h>
#include <stdint.h>
#include <tchar.h>
#include <iostream>
#pragma warning(disable: 26495)
#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma warning(default: 26495)


void mainCode(HMODULE hModule);
extern const float PI;

class Vector2
{
public:
	Vector2(float x, float y) { this->x = x; this->y = y; }
	float x, y;
};
class Vector3
{
public:
	Vector3(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }
	float x, y, z;
};
class Vector4
{
public:
	Vector4(float x, float y, float z, float w) { this->x = x; this->y = y; this->z = z; this->w = w; }
	float x, y, z, w;
};