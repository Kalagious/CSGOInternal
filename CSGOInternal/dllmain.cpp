// dllmain.cpp : Defines the entry point for the DLL application.
#include "windows.h"
#include "iostream"
#include "General.h"




DWORD APIENTRY CheatThread(HMODULE hModule)
{
    mainCode(hModule);

    return 0;
}


BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
        CloseHandle(CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)CheatThread, hModule, NULL, NULL));

    return TRUE;
}

