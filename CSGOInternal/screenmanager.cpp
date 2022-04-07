#include "screenmanager.h"
#pragma warning(disable: 4244 26495)

HWND ScreenManager::gameWindow;
LPDIRECT3DDEVICE9 ScreenManager::d3dDevice;

ScreenManager::ScreenManager()
{
    endSceneHook = NULL;
    ScreenManager::gameWindow = NULL;
    gameDimensions = { 0, 0, 0, 0, 0, 0 };
}


BOOL CALLBACK ScreenManager::EnumWindowsProc(HWND hwnd, LPARAM lparam)
{
    int nameLen = GetWindowTextLength(hwnd);
    LPWSTR windowName = (LPWSTR)VirtualAlloc((LPVOID)NULL, (DWORD)(nameLen + 1), MEM_COMMIT, PAGE_READWRITE);
    if (windowName)
    {
        GetWindowText(hwnd, windowName, nameLen + 1);
        std::wstring wsName(windowName);

        uintptr_t windowProcessID = NULL;
        uintptr_t thread = GetWindowThreadProcessId(hwnd, (LPDWORD)&windowProcessID);
        if (windowProcessID == GetProcessId(GetCurrentProcess()) && wsName.find(L"Direct3D") != -1)
        {
            ScreenManager::gameWindow = hwnd;
            return false;
        }
    }

    return true;
}


bool ScreenManager::GetGameWindow()
{
    EnumWindows(ScreenManager::EnumWindowsProc, NULL);
    if (ScreenManager::gameWindow)
    {
        RecalculateWindowDimensions();
        return true;
    }
    return false;
}


bool ScreenManager::GetD3D9Device(void** table, size_t tableSize)
{
    if (!table)
        return false;

    IDirect3D9* d3d = Direct3DCreate9(D3D_SDK_VERSION);
    if (!d3d)
        return false;

    IDirect3DDevice9* d3dDeviceDummy = NULL;

    D3DPRESENT_PARAMETERS d3dParams = {};
    d3dParams.Windowed = false;
    d3dParams.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dParams.hDeviceWindow = ScreenManager::gameWindow;

    HRESULT dummyCreated = d3d->CreateDevice(NULL, D3DDEVTYPE_HAL, d3dParams.hDeviceWindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dParams, &d3dDeviceDummy);
    if (dummyCreated != S_OK)
    {
        d3dParams.Windowed = true;
        HRESULT dummyCreated = d3d->CreateDevice(NULL, D3DDEVTYPE_HAL, d3dParams.hDeviceWindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dParams, &d3dDeviceDummy);
        if (dummyCreated != S_OK)
        {
            return false;
            d3d->Release();
        }

    }
    memcpy(table, *(void***)(d3dDeviceDummy), tableSize);
    d3dDeviceDummy->Release();
    d3d->Release();
    return true;
}


bool ScreenManager::Initialize()
{
    if (GetGameWindow())
    {
        printf("%s\n", GetWindowName().c_str());
        if (GetD3D9Device(d3d9DeviceVTable, sizeof(d3d9DeviceVTable)))
        {
            printf("D3D Vtable Loaded\n");
            if (!d3d9DeviceVTable[42])
                return false;

            endSceneHook = new EndSceneHook((uintptr_t)d3d9DeviceVTable[42]);
            endSceneHook->initialize();
            return true;
        }
    }
    return false;
}

void ScreenManager::RecalculateWindowDimensions()
{
    RECT temp;
    GetWindowRect(ScreenManager::gameWindow, &temp);
    gameDimensions = { temp.left, temp.top, temp.right - temp.left - 6, temp.bottom - temp.top - 40, (temp.left + (temp.right - temp.left - 6) / 2), (temp.top + (temp.bottom - temp.top - 40) / 2) };
}

std::string ScreenManager::GetWindowName()
{
    int nameLen = GetWindowTextLength(ScreenManager::gameWindow);
    LPWSTR windowName = (LPWSTR)VirtualAlloc((LPVOID)NULL, (DWORD)(nameLen + 1), MEM_COMMIT, PAGE_READWRITE);
    if (windowName)
    {
        GetWindowText(ScreenManager::gameWindow, windowName, nameLen + 1);

        std::wstring wsName(windowName);
        std::string strName(wsName.begin(), wsName.end());
        return strName;
    }
    return "";
}

#pragma warning(default: 4244 26495)

