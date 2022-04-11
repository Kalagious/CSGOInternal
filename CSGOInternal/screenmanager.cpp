#include "screenmanager.h"
#pragma warning(disable: 4244 26495)


extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
HWND ScreenManager::gameWindowHandle;
LPDIRECT3DDEVICE9 ScreenManager::d3dDevice;
ScreenManager::OrigWndProcT ScreenManager::origWndProc;
ScreenManager* screenManagerGlobal;


ScreenManager::ScreenManager()
{
    endSceneHook = NULL;
    ScreenManager::gameWindowHandle = NULL;
    ScreenManager::origWndProc = NULL;
    gameDimensions = { 0, 0, 0, 0, 0, 0 };
    imGUIIsInitialized = false;
    GUIIsVisable = true;
    theme = new ImGuiTheme();
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
            ScreenManager::gameWindowHandle = hwnd;
            return false;
        }
    }

    return true;
}


bool ScreenManager::GetGameWindow()
{
    EnumWindows(ScreenManager::EnumWindowsProc, NULL);
    if (ScreenManager::gameWindowHandle)
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
    d3dParams.hDeviceWindow = ScreenManager::gameWindowHandle;

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
        if (GetD3D9Device(d3d9DeviceVTable, sizeof(d3d9DeviceVTable)))
        {
            printf(" [*] D3D Vtable Loaded\n");
            if (!d3d9DeviceVTable[42])
                return false;
            endSceneHook = new EndSceneHook((uintptr_t)d3d9DeviceVTable[42]);
            endSceneHook->initialize();
            return true;
        }
    }
    return false;
}

void ScreenManager::Cleanup()
{
    theme->SaveTheme();
    endSceneHook->remove();
    SetWindowLongPtr(ScreenManager::gameWindowHandle, GWLP_WNDPROC, (LONG_PTR)ScreenManager::origWndProc);
}

void ScreenManager::RecalculateWindowDimensions()
{
    RECT temp;
    GetWindowRect(ScreenManager::gameWindowHandle, &temp);
    gameDimensions = { temp.left, temp.top, temp.right - temp.left - 6, temp.bottom - temp.top - 40, (float)(temp.left + (temp.right - temp.left - 6) / 2), (float)(temp.top + (temp.bottom - temp.top - 40) / 2) };
}

std::string ScreenManager::GetWindowName()
{
    int nameLen = GetWindowTextLength(ScreenManager::gameWindowHandle);
    LPWSTR windowName = (LPWSTR)VirtualAlloc((LPVOID)NULL, (DWORD)(nameLen + 1), MEM_COMMIT, PAGE_READWRITE);
    if (windowName)
    {
        GetWindowText(ScreenManager::gameWindowHandle, windowName, nameLen + 1);

        std::wstring wsName(windowName);
        std::string strName(wsName.begin(), wsName.end());
        return strName;
    }
    return "";
}

bool ScreenManager::InitializeImGUI()
{
    ScreenManager::origWndProc = (OrigWndProcT)GetWindowLongPtr(ScreenManager::gameWindowHandle, GWLP_WNDPROC);
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.FontDefault = io.Fonts->AddFontFromFileTTF("C:\\Users\\Jordan\\source\\repos\\CSGOInternal\\CSGOInternal\\ImGUI\\Fonts\\Exo2-Medium.ttf", 24.0f);
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    theme->UpdateTheme();
    ImGui_ImplWin32_Init(ScreenManager::gameWindowHandle);
    ImGui_ImplDX9_Init(ScreenManager::d3dDevice);
    imGUIIsInitialized = true;
    printf(" [*] ImGUI Initialized\n");
    return true;
}


void ScreenManager::ToggleGUI()
{
    if (GUIIsVisable)
        SetWindowLongPtr(ScreenManager::gameWindowHandle, GWLP_WNDPROC, (LONG_PTR)origWndProc);
    else
        SetWindowLongPtr(ScreenManager::gameWindowHandle, GWLP_WNDPROC, (LONG_PTR)WndProc);

    GUIIsVisable = !GUIIsVisable;
}

void ScreenManager::InputHandler()
{
    for (int i = 0; i < 5; i++) ImGui::GetIO().MouseDown[i] = false;

    int button = -1;
    if (GetAsyncKeyState(VK_LBUTTON)) button = 0;

    if (button != -1) ImGui::GetIO().MouseDown[button] = true;
}


LRESULT CALLBACK ScreenManager::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    ImGui_ImplWin32_WndProcHandler(hwnd, msg, wParam, lParam);
    ScreenManager::origWndProc(hwnd, msg, wParam, lParam);
    return 0;
}
#pragma warning(default: 4244 26495)

