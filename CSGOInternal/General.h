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
	Vector2() {};
	Vector2(float x, float y) { this->x = x; this->y = y; }
	float x, y;
};
class Vector3
{
public:
	Vector3() {};
	Vector3(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }
	float x, y, z;
};
class Vector4
{
public:
	Vector4() {};
	Vector4(float x, float y, float z, float w) { this->x = x; this->y = y; this->z = z; this->w = w; }
	float x, y, z, w;
};


class Matrix3x3 {
public:
	float data[9];
	Matrix3x3() {};
};

class Matrix3x4 {
public:
	float data[12];
	Matrix3x4() {};

	void setData(const float* values)
	{
		for (int i = 0; i < 12; i++)
		{
			this->data[i] = values[i];
		}
	}

	void print()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
				printf("%2.2f, ", this->data[i*4+j]);
			printf("\n");
		}
	}
};

class Matrix4x4 {
public:
	float data[16];
	Matrix4x4() {};

	void setData (const float* values)
	{
		for (int i = 0; i < 16; i++)
		{
			this->data[i] = values[i];
		}
	}

	Matrix4x4* mult(const Matrix4x4* m2)
	{
		Matrix4x4* out = new Matrix4x4();
		for (int i = 0; i < 16; i++)
		{
			out->data[i] = this->data[(i % 4) + (4 * 0)] * m2->data[(i / 4) * 4 + 0] +
				this->data[(i % 4) + (4 * 1)] * m2->data[(i / 4) * 4 + 1] +
				this->data[(i % 4) + (4 * 2)] * m2->data[(i / 4) * 4 + 2] +
				this->data[(i % 4) + (4 * 3)] * m2->data[(i / 4) * 4 + 3];	
		}
		return out;
	}

	void print()
	{
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				printf("%10.2f ", this->data[4*row+col]);
			}
			printf("\n");
		}
	}
};

