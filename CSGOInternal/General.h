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

class Vector3
{
public:
	Vector3(float xIn, float yIn, float zIn) { x = xIn; y = yIn; z = zIn; }
	float x, y, z;
};