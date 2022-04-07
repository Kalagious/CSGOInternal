#include "screenmanager.h"
#pragma warning(disable: 4838)


void ScreenManager::FilledRect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, D3DCOLOR color)
{
	D3DRECT rect = { x, y, x + w, y + h };
	ScreenManager::d3dDevice->Clear(1, &rect, D3DCLEAR_TARGET, color, 0, 0);
}

void ScreenManager::Line(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t h, D3DCOLOR color)
{

}

void ScreenManager::Text(uint32_t x, uint32_t y, uint32_t w, uint32_t h, std::string text, D3DCOLOR color)
{
	std::wstring wtext(text.begin(), text.end());
	LPD3DXFONT m_font = NULL;
	RECT rect = { x, y, x + w, y + h };
	D3DXCreateFont(ScreenManager::d3dDevice, 17, 0, FW_BOLD, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Arial"), &m_font);
	m_font->DrawText(NULL, wtext.c_str(), -1, &rect, DT_CENTER, color);
}

#pragma warning(default: 4838)
