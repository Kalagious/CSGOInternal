#include "windows.h"
#include "Cheats.h"
#include "General.h"
#include <tlhelp32.h>
#include <iostream>
#include "AllClasses.h"
#include "HookManager.h"

/* 
TODO:
	Reverse Client Linked Ent List and parse properly
	Reverse Server Linked Ent List and parse properly
	Hook Something fast for cheats->tick()
	Find Bullet Spread
	Find Line function for triggerbot and better aimbot
	Hook Graphics Function for ESP
*/ 



const float PI = 3.14159265358979F;
Cheats* cheatsGlobal;

void mainCode(HMODULE hModule)
{
	AllocConsole();
	FILE* console;
	freopen_s(&console, "CONOUT$", "w", stdout);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	printf("Starting!\n");

	uintptr_t csgoExe = (uintptr_t)GetModuleHandle(L"csgo.exe");
	uintptr_t clientDll = (uintptr_t)GetModuleHandle(L"client.dll");
	uintptr_t serverDll = (uintptr_t)GetModuleHandle(L"server.dll");
	uintptr_t engineDll = (uintptr_t)GetModuleHandle(L"engine.dll");

	Cheats cheats(csgoExe, serverDll, clientDll, engineDll);
	cheatsGlobal = &cheats;

	//cheats.setTickHook();

	while (!cheats.uninject)
	{
		cheats.tick();
		if (GetAsyncKeyState(VK_F1) & 0x01)
			cheats.uninject = true;
	}

	cheats.cleanup();

	fclose(console);
	FreeConsole();
	FreeLibraryAndExitThread(hModule, 0);
}


