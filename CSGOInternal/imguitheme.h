#pragma once

#include "ImGUI/imgui.h"
#include "ImGUI/imgui_impl_dx9.h"
#include "ImGUI/imgui_impl_win32.h"
#include "screenmanager.h"
#include <string>
#include <sstream>
#include <fstream>
#include <regex>

class ScreenManager;
extern ScreenManager* screenManagerGlobal;

class ImGuiTheme
{
public:
    ImGuiTheme();
    float Text[4];
    float TextDisabled[4];
    float WindowBg[4];
    float ChildBg[4];
    float PopupBg[4];
    float Border[4];
    float BorderShadow[4];
    float FrameBg[4];
    float FrameBgHovered[4];
    float FrameBgActive[4];
    float TitleBg[4];
    float TitleBgActive[4];
    float TitleBgCollapsed[4];
    float MenuBarBg[4];
    float ScrollbarBg[4];
    float ScrollbarGrab[4];
    float ScrollbarGrabHovered[4];
    float ScrollbarGrabActive[4];
    float CheckMark[4];
    float SliderGrab[4];
    float SliderGrabActive[4];
    float Button[4];
    float ButtonHovered[4];
    float ButtonActive[4];
    float Header[4];
    float HeaderHovered[4];
    float HeaderActive[4];
    float Separator[4];
    float SeparatorHovered[4];
    float SeparatorActive[4];
    float ResizeGrip[4];
    float ResizeGripHovered[4];
    float ResizeGripActive[4];
    float Tab[4];
    float TabHovered[4];
    float TabActive[4];
    float TabUnfocused[4];
    float TabUnfocusedActive[4];
    float PlotLines[4];
    float PlotLinesHovered[4];
    float PlotHistogram[4];
    float PlotHistogramHovered[4];
    float TableHeaderBg[4];
    float TableBorderStrong[4];   // Prefer using Alpha=1.0 here
    float TableBorderLight[4];   // Prefer using Alpha=1.0 here
    float TableRowBg[4];
    float TableRowBgAlt[4];
    float TextSelectedBg[4];
    float DragDropTarget[4];
    float NavHighlight[4];
    float NavWindowingHighlight[4];
    float NavWindowingDimBg[4];
    float ModalWindowDimBg[4];

    void UpdateTheme();
    void SaveTheme();
    void LoadTheme();
    void GUICustomizer();
    void InputThemeParameter(std::string name, float p1, float p2, float p3, float p4);

    std::string themeFile;
};