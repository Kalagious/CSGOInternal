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


class Matrix3x3 {
public:
	float data[3][3];
	//Matrix3x3 mult(Matrix3x3 m2);
	//Matrix3x4 mult(Matrix4x4 m2);

};
//Matrix3x3 out = new Matrix3x3();

//for (int row = 0; row < 3; row++)
//{
//	for (int col = 0; col < 3; col++)
//	{
//		out.data[col][row] = this->data[row][0] * m2.data[0][col] + this->data[row][1] * m2.data[1][col] + this->data[row][2] * m2.data[2][col];
//	}
//}

class Matrix3x4 {
public:
	float data[3][4];
};

class Matrix4x4 {
public:
	float data[4][4];
	//Matrix4x4 mult(Matrix4x4 m2);
	//Matrix3x4 mult(Matrix3x3 m2);

};

