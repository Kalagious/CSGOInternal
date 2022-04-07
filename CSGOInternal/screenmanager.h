#pragma once
#include "general.h"
#include "endscenehook.h"


struct windowDimensions {
	int32_t x, y;
	int32_t w, h;
	int32_t cx, cy;
};


class ScreenManager
{
public:
	ScreenManager();
	bool Initialize();
	bool GetGameWindow();
	bool GetD3D9Device(void** table, size_t tableSize);
	std::string GetWindowName();
	void RecalculateWindowDimensions();
	static BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM param);

	void* d3d9DeviceVTable[119];
	static LPDIRECT3DDEVICE9 d3dDevice;
	EndSceneHook* endSceneHook;
	static HWND gameWindow;
	windowDimensions gameDimensions;

	// Draw Functions
	void FilledRect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, D3DCOLOR color);
	void Line(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t h, D3DCOLOR color);
	void Text(uint32_t x, uint32_t y, uint32_t w, uint32_t h, std::string text, D3DCOLOR color);
};


