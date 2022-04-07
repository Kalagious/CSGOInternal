#include "screenmanager.h"

void ScreenManager::FilledRect(int x, int y, int w, int h, D3DCOLOR color)
{
	D3DRECT rect = { x, y, x + w, y + h };
	ScreenManager::d3dDevice->Clear(1, &rect, D3DCLEAR_TARGET, color, 0, 0);
}