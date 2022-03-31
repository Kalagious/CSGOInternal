#include "Cheats.h"
#include "WinDef.h"

void Cheats::keybinds()
{
	if (GetAsyncKeyState(VK_NUMPAD1) & 0x01)
		infiniteHealth->enable = !infiniteHealth->enable;

	if (GetAsyncKeyState(VK_NUMPAD2) & 0x01)
		infiniteAmmo->enable = !infiniteAmmo->enable;

	if (GetAsyncKeyState(VK_NUMPAD4) & 0x01)
		noRecoil->enable = !noRecoil->enable;

	if (GetAsyncKeyState(VK_NUMPAD3) & 0x01)
		speed->enable = !speed->enable;

	if (GetAsyncKeyState(VK_XBUTTON2))
		aimbot->enable = true;
	else
		aimbot->enable = false;

	if (GetAsyncKeyState(VK_XBUTTON1))
		fly->enable = true;
	else
		fly->enable = false;
}