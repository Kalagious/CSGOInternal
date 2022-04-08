#pragma once
#include "general.h"
#include "ImGUI/imgui.h"
#include "ImGUI/imgui_impl_dx9.h"
#include "ImGUI/imgui_impl_win32.h"
#include "endscenehook.h"

struct windowDimensions {
	int32_t x, y;
	int32_t w, h;
	float cx, cy;
};

class ScreenManager
{
public:
	ScreenManager();
	bool Initialize();
	bool InitializeImGUI();
	void Cleanup();
	void InputHandler();
	void ToggleGUI();
	bool GetGameWindow();
	bool GetD3D9Device(void** table, size_t tableSize);
	std::string GetWindowName();
	void RecalculateWindowDimensions();
	static BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM param);
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	ID3DXLine* d3dLine;
	void* d3d9DeviceVTable[119];
	bool imGUIIsInitialized;
	bool GUIIsVisable;
	static LPDIRECT3DDEVICE9 d3dDevice;
	EndSceneHook* endSceneHook;
	static HWND gameWindowHandle;
	typedef LRESULT(CALLBACK* OrigWndProcT)(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static OrigWndProcT origWndProc;
	windowDimensions gameDimensions;

	// Draw Functions
	void FilledRect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, D3DCOLOR color);
	void Line(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, float w, D3DCOLOR color);
	void Text(uint32_t x, uint32_t y, uint32_t w, uint32_t h, std::string text, D3DCOLOR color);
	void DrawImGUI();
};


