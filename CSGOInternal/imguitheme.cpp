#include "imguitheme.h"


void ImGuiTheme::SaveTheme()
{
	printf(" [*] Saving Theme\n");
	std::ofstream themeFileStream(themeFile);
	std::string entry;
	entry = std::string("Text (" + std::to_string(Text[0]) + ", " + std::to_string(Text[1]) + ", " + std::to_string(Text[2]) + ", " + std::to_string(Text[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("TextDisabled (" + std::to_string(TextDisabled[0]) + ", " + std::to_string(TextDisabled[1]) + ", " + std::to_string(TextDisabled[2]) + ", " + std::to_string(TextDisabled[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("WindowBg (" + std::to_string(WindowBg[0]) + ", " + std::to_string(WindowBg[1]) + ", " + std::to_string(WindowBg[2]) + ", " + std::to_string(WindowBg[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("ChildBg (" + std::to_string(ChildBg[0]) + ", " + std::to_string(ChildBg[1]) + ", " + std::to_string(ChildBg[2]) + ", " + std::to_string(ChildBg[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("PopupBg (" + std::to_string(PopupBg[0]) + ", " + std::to_string(PopupBg[1]) + ", " + std::to_string(PopupBg[2]) + ", " + std::to_string(PopupBg[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("Border (" + std::to_string(Border[0]) + ", " + std::to_string(Border[1]) + ", " + std::to_string(Border[2]) + ", " + std::to_string(Border[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("BorderShadow (" + std::to_string(BorderShadow[0]) + ", " + std::to_string(BorderShadow[1]) + ", " + std::to_string(BorderShadow[2]) + ", " + std::to_string(BorderShadow[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("FrameBg (" + std::to_string(FrameBg[0]) + ", " + std::to_string(FrameBg[1]) + ", " + std::to_string(FrameBg[2]) + ", " + std::to_string(FrameBg[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("FrameBgHovered (" + std::to_string(FrameBgHovered[0]) + ", " + std::to_string(FrameBgHovered[1]) + ", " + std::to_string(FrameBgHovered[2]) + ", " + std::to_string(FrameBgHovered[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("FrameBgActive (" + std::to_string(FrameBgActive[0]) + ", " + std::to_string(FrameBgActive[1]) + ", " + std::to_string(FrameBgActive[2]) + ", " + std::to_string(FrameBgActive[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("TitleBg (" + std::to_string(TitleBg[0]) + ", " + std::to_string(TitleBg[1]) + ", " + std::to_string(TitleBg[2]) + ", " + std::to_string(TitleBg[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("TitleBgActive (" + std::to_string(TitleBgActive[0]) + ", " + std::to_string(TitleBgActive[1]) + ", " + std::to_string(TitleBgActive[2]) + ", " + std::to_string(TitleBgActive[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("TitleBgCollapsed (" + std::to_string(TitleBgCollapsed[0]) + ", " + std::to_string(TitleBgCollapsed[1]) + ", " + std::to_string(TitleBgCollapsed[2]) + ", " + std::to_string(TitleBgCollapsed[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("MenuBarBg (" + std::to_string(MenuBarBg[0]) + ", " + std::to_string(MenuBarBg[1]) + ", " + std::to_string(MenuBarBg[2]) + ", " + std::to_string(MenuBarBg[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("ScrollbarBg (" + std::to_string(ScrollbarBg[0]) + ", " + std::to_string(ScrollbarBg[1]) + ", " + std::to_string(ScrollbarBg[2]) + ", " + std::to_string(ScrollbarBg[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("ScrollbarGrab (" + std::to_string(ScrollbarGrab[0]) + ", " + std::to_string(ScrollbarGrab[1]) + ", " + std::to_string(ScrollbarGrab[2]) + ", " + std::to_string(ScrollbarGrab[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("ScrollbarGrabHovered (" + std::to_string(ScrollbarGrabHovered[0]) + ", " + std::to_string(ScrollbarGrabHovered[1]) + ", " + std::to_string(ScrollbarGrabHovered[2]) + ", " + std::to_string(ScrollbarGrabHovered[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("ScrollbarGrabActive (" + std::to_string(ScrollbarGrabActive[0]) + ", " + std::to_string(ScrollbarGrabActive[1]) + ", " + std::to_string(ScrollbarGrabActive[2]) + ", " + std::to_string(ScrollbarGrabActive[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("CheckMark (" + std::to_string(CheckMark[0]) + ", " + std::to_string(CheckMark[1]) + ", " + std::to_string(CheckMark[2]) + ", " + std::to_string(CheckMark[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("SliderGrab (" + std::to_string(SliderGrab[0]) + ", " + std::to_string(SliderGrab[1]) + ", " + std::to_string(SliderGrab[2]) + ", " + std::to_string(SliderGrab[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("SliderGrabActive (" + std::to_string(SliderGrabActive[0]) + ", " + std::to_string(SliderGrabActive[1]) + ", " + std::to_string(SliderGrabActive[2]) + ", " + std::to_string(SliderGrabActive[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("Button (" + std::to_string(Button[0]) + ", " + std::to_string(Button[1]) + ", " + std::to_string(Button[2]) + ", " + std::to_string(Button[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("ButtonHovered (" + std::to_string(ButtonHovered[0]) + ", " + std::to_string(ButtonHovered[1]) + ", " + std::to_string(ButtonHovered[2]) + ", " + std::to_string(ButtonHovered[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("ButtonActive (" + std::to_string(ButtonActive[0]) + ", " + std::to_string(ButtonActive[1]) + ", " + std::to_string(ButtonActive[2]) + ", " + std::to_string(ButtonActive[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("Header (" + std::to_string(Header[0]) + ", " + std::to_string(Header[1]) + ", " + std::to_string(Header[2]) + ", " + std::to_string(Header[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("HeaderHovered (" + std::to_string(HeaderHovered[0]) + ", " + std::to_string(HeaderHovered[1]) + ", " + std::to_string(HeaderHovered[2]) + ", " + std::to_string(HeaderHovered[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("HeaderActive (" + std::to_string(HeaderActive[0]) + ", " + std::to_string(HeaderActive[1]) + ", " + std::to_string(HeaderActive[2]) + ", " + std::to_string(HeaderActive[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("Separator (" + std::to_string(Separator[0]) + ", " + std::to_string(Separator[1]) + ", " + std::to_string(Separator[2]) + ", " + std::to_string(Separator[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("SeparatorHovered (" + std::to_string(SeparatorHovered[0]) + ", " + std::to_string(SeparatorHovered[1]) + ", " + std::to_string(SeparatorHovered[2]) + ", " + std::to_string(SeparatorHovered[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("SeparatorActive (" + std::to_string(SeparatorActive[0]) + ", " + std::to_string(SeparatorActive[1]) + ", " + std::to_string(SeparatorActive[2]) + ", " + std::to_string(SeparatorActive[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("ResizeGrip (" + std::to_string(ResizeGrip[0]) + ", " + std::to_string(ResizeGrip[1]) + ", " + std::to_string(ResizeGrip[2]) + ", " + std::to_string(ResizeGrip[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("ResizeGripHovered (" + std::to_string(ResizeGripHovered[0]) + ", " + std::to_string(ResizeGripHovered[1]) + ", " + std::to_string(ResizeGripHovered[2]) + ", " + std::to_string(ResizeGripHovered[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("ResizeGripActive (" + std::to_string(ResizeGripActive[0]) + ", " + std::to_string(ResizeGripActive[1]) + ", " + std::to_string(ResizeGripActive[2]) + ", " + std::to_string(ResizeGripActive[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("Tab (" + std::to_string(Tab[0]) + ", " + std::to_string(Tab[1]) + ", " + std::to_string(Tab[2]) + ", " + std::to_string(Tab[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("TabHovered (" + std::to_string(TabHovered[0]) + ", " + std::to_string(TabHovered[1]) + ", " + std::to_string(TabHovered[2]) + ", " + std::to_string(TabHovered[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("TabActive (" + std::to_string(TabActive[0]) + ", " + std::to_string(TabActive[1]) + ", " + std::to_string(TabActive[2]) + ", " + std::to_string(TabActive[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("TabUnfocused (" + std::to_string(TabUnfocused[0]) + ", " + std::to_string(TabUnfocused[1]) + ", " + std::to_string(TabUnfocused[2]) + ", " + std::to_string(TabUnfocused[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("TabUnfocusedActive (" + std::to_string(TabUnfocusedActive[0]) + ", " + std::to_string(TabUnfocusedActive[1]) + ", " + std::to_string(TabUnfocusedActive[2]) + ", " + std::to_string(TabUnfocusedActive[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("PlotLines (" + std::to_string(PlotLines[0]) + ", " + std::to_string(PlotLines[1]) + ", " + std::to_string(PlotLines[2]) + ", " + std::to_string(PlotLines[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("PlotLinesHovered (" + std::to_string(PlotLinesHovered[0]) + ", " + std::to_string(PlotLinesHovered[1]) + ", " + std::to_string(PlotLinesHovered[2]) + ", " + std::to_string(PlotLinesHovered[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("PlotHistogram (" + std::to_string(PlotHistogram[0]) + ", " + std::to_string(PlotHistogram[1]) + ", " + std::to_string(PlotHistogram[2]) + ", " + std::to_string(PlotHistogram[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("PlotHistogramHovered (" + std::to_string(PlotHistogramHovered[0]) + ", " + std::to_string(PlotHistogramHovered[1]) + ", " + std::to_string(PlotHistogramHovered[2]) + ", " + std::to_string(PlotHistogramHovered[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("TableHeaderBg (" + std::to_string(TableHeaderBg[0]) + ", " + std::to_string(TableHeaderBg[1]) + ", " + std::to_string(TableHeaderBg[2]) + ", " + std::to_string(TableHeaderBg[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("TableBorderStrong (" + std::to_string(TableBorderStrong[0]) + ", " + std::to_string(TableBorderStrong[1]) + ", " + std::to_string(TableBorderStrong[2]) + ", " + std::to_string(TableBorderStrong[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("TableBorderLight (" + std::to_string(TableBorderLight[0]) + ", " + std::to_string(TableBorderLight[1]) + ", " + std::to_string(TableBorderLight[2]) + ", " + std::to_string(TableBorderLight[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("TableRowBg (" + std::to_string(TableRowBg[0]) + ", " + std::to_string(TableRowBg[1]) + ", " + std::to_string(TableRowBg[2]) + ", " + std::to_string(TableRowBg[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("TableRowBgAlt (" + std::to_string(TableRowBgAlt[0]) + ", " + std::to_string(TableRowBgAlt[1]) + ", " + std::to_string(TableRowBgAlt[2]) + ", " + std::to_string(TableRowBgAlt[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("TextSelectedBg (" + std::to_string(TextSelectedBg[0]) + ", " + std::to_string(TextSelectedBg[1]) + ", " + std::to_string(TextSelectedBg[2]) + ", " + std::to_string(TextSelectedBg[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("DragDropTarget (" + std::to_string(DragDropTarget[0]) + ", " + std::to_string(DragDropTarget[1]) + ", " + std::to_string(DragDropTarget[2]) + ", " + std::to_string(DragDropTarget[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("NavHighlight (" + std::to_string(NavHighlight[0]) + ", " + std::to_string(NavHighlight[1]) + ", " + std::to_string(NavHighlight[2]) + ", " + std::to_string(NavHighlight[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("NavWindowingHighlight (" + std::to_string(NavWindowingHighlight[0]) + ", " + std::to_string(NavWindowingHighlight[1]) + ", " + std::to_string(NavWindowingHighlight[2]) + ", " + std::to_string(NavWindowingHighlight[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("NavWindowingDimBg (" + std::to_string(NavWindowingDimBg[0]) + ", " + std::to_string(NavWindowingDimBg[1]) + ", " + std::to_string(NavWindowingDimBg[2]) + ", " + std::to_string(NavWindowingDimBg[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	entry = std::string("ModalWindowDimBg (" + std::to_string(ModalWindowDimBg[0]) + ", " + std::to_string(ModalWindowDimBg[1]) + ", " + std::to_string(ModalWindowDimBg[2]) + ", " + std::to_string(ModalWindowDimBg[3]) + ");\n");
	themeFileStream.write(entry.c_str(), entry.length());
	themeFileStream.close();
}

void ImGuiTheme::LoadTheme()
{
	std::ifstream themeFileStream(themeFile);
	if (themeFileStream)
	{
		std::stringstream themeFileDataStream;

		std::string themeFileData;
		
		themeFileDataStream << themeFileStream.rdbuf();
		themeFileStream.close();
		themeFileData = themeFileDataStream.str();

		if (std::count(themeFileData.begin(), themeFileData.end(), '\n') != 53)
		{
			SaveTheme();
			return;
		}
		printf(" [*] Loading Theme\n");
		std::string line;
		std::regex pattern("(.*?) .(.*?), (.*?), (.*?), (.*?).;");
		std::smatch match;
		while (std::getline(themeFileDataStream, line))
		{
			std::regex_search(line, match, pattern);
			InputThemeParameter(match[1], stof(match[2]), stof(match[3]), stof(match[4]), stof(match[5]));
		}

	}
}

#define ColorPicker(x, y); ImGui::ColorEdit4(x, y, ImGuiColorEditFlags_NoInputs);
void ImGuiTheme::GUICustomizer()
{
	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	if (ImGui::Button("Back"))
		screenManagerGlobal->GUIState = screenManagerGlobal->MAIN;
	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	ColorPicker("Text", Text);
	ImGui::SameLine(300);
	ColorPicker("TextDisabled", TextDisabled);
	ImGui::SameLine(600);
	ColorPicker("WindowBg", WindowBg);
	ColorPicker("ChildBg", ChildBg);
	ImGui::SameLine(300);
	ColorPicker("PopupBg", PopupBg);
	ImGui::SameLine(600);
	ColorPicker("Border", Border);
	ColorPicker("BorderShadow", BorderShadow);
	ImGui::SameLine(300);
	ColorPicker("FrameBg", FrameBg);
	ImGui::SameLine(600);
	ColorPicker("FrameBgHovered", FrameBgHovered);
	ColorPicker("FrameBgActive", FrameBgActive);
	ImGui::SameLine(300);
	ColorPicker("TitleBg", TitleBg);
	ImGui::SameLine(600);
	ColorPicker("TitleBgActive", TitleBgActive);
	ColorPicker("TitleBgCollapsed", TitleBgCollapsed);
	ImGui::SameLine(300);
	ColorPicker("MenuBarBg", MenuBarBg);
	ImGui::SameLine(600);
	ColorPicker("ScrollbarBg", ScrollbarBg);
	ColorPicker("ScrollbarGrab", ScrollbarGrab);
	ImGui::SameLine(300);
	ColorPicker("ScrollbarGrabHovered", ScrollbarGrabHovered);
	ImGui::SameLine(600);
	ColorPicker("ScrollbarGrabActive", ScrollbarGrabActive);
	ColorPicker("CheckMark", CheckMark);
	ImGui::SameLine(300);
	ColorPicker("SliderGrab", SliderGrab);
	ImGui::SameLine(600);
	ColorPicker("SliderGrabActive", SliderGrabActive);
	ColorPicker("Button", Button);
	ImGui::SameLine(300);
	ColorPicker("ButtonHovered", ButtonHovered);
	ImGui::SameLine(600);
	ColorPicker("ButtonActive", ButtonActive);
	ColorPicker("Header", Header);
	ImGui::SameLine(300);
	ColorPicker("HeaderHovered", HeaderHovered);
	ImGui::SameLine(600);
	ColorPicker("HeaderActive", HeaderActive);
	ColorPicker("Separator", Separator);
	ImGui::SameLine(300);
	ColorPicker("SeparatorHovered", SeparatorHovered);
	ImGui::SameLine(600);
	ColorPicker("SeparatorActive", SeparatorActive);
	ColorPicker("ResizeGrip", ResizeGrip);
	ImGui::SameLine(300);
	ColorPicker("ResizeGripHovered", ResizeGripHovered);
	ImGui::SameLine(600);
	ColorPicker("ResizeGripActive", ResizeGripActive);
	ColorPicker("Tab", Tab);
	ImGui::SameLine(300);
	ColorPicker("TabHovered", TabHovered);
	ImGui::SameLine(600);
	ColorPicker("TabActive", TabActive);
	ColorPicker("TabUnfocused", TabUnfocused);
	ImGui::SameLine(300);
	ColorPicker("TabUnfocusedActive", TabUnfocusedActive);
	ImGui::SameLine(600);
	ColorPicker("PlotLines", PlotLines);
	ColorPicker("PlotLinesHovered", PlotLinesHovered);
	ImGui::SameLine(300);
	ColorPicker("PlotHistogram", PlotHistogram);
	ImGui::SameLine(600);
	ColorPicker("PlotHistogramHovered", PlotHistogramHovered);
	ColorPicker("TableBorderLight", TableBorderLight);
	ImGui::SameLine(300);
	ColorPicker("TableRowBg", TableRowBg);
	ImGui::SameLine(600);
	ColorPicker("TableRowBgAlt", TableRowBgAlt);
	ColorPicker("TextSelectedBg", TextSelectedBg);
	ImGui::SameLine(300);
	ColorPicker("DragDropTarget", DragDropTarget);
	ImGui::SameLine(600);
	ColorPicker("NavHighlight", NavHighlight);
	ColorPicker("NavWindowingHighlight", NavWindowingHighlight);
	ImGui::SameLine(300);
	ColorPicker("NavWindowingDimBg", NavWindowingDimBg);
	ImGui::SameLine(600);
	ColorPicker("ModalWindowDimBg", ModalWindowDimBg);
	ColorPicker("TableHeaderBg", TableHeaderBg);
	ImGui::SameLine(300);
	ColorPicker("TableBorderStrong", TableBorderStrong);
	if (ImGui::Button("Save"))
		SaveTheme();
	ImGui::SameLine(200);
	if (ImGui::Button("Load"))
		LoadTheme();
	UpdateTheme();
}

ImGuiTheme::ImGuiTheme()
{
	themeFile = "C:\\Users\\Jordan\\source\\repos\\CSGOInternal\\CSGOInternal\\mainDarkBlue.thm";
	Text[0] = 1.00f;
	Text[1] = 1.00f;
	Text[2] = 1.00f;
	Text[3] = 1.00f;

	TextDisabled[0] = 0.50f;
	TextDisabled[1] = 0.50f;
	TextDisabled[2] = 0.50f;
	TextDisabled[3] = 1.00f;

	WindowBg[0] = 0.06f;
	WindowBg[1] = 0.06f;
	WindowBg[2] = 0.06f;
	WindowBg[3] = 0.94f;

	ChildBg[0] = 0.00f;
	ChildBg[1] = 0.00f;
	ChildBg[2] = 0.00f;
	ChildBg[3] = 0.00f;

	PopupBg[0] = 0.08f;
	PopupBg[1] = 0.08f;
	PopupBg[2] = 0.08f;
	PopupBg[3] = 0.94f;

	Border[0] = 0.43f;
	Border[1] = 0.43f;
	Border[2] = 0.50f;
	Border[3] = 0.50f;

	BorderShadow[0] = 0.00f;
	BorderShadow[1] = 0.00f;
	BorderShadow[2] = 0.00f;
	BorderShadow[3] = 0.00f;

	FrameBg[0] = 0.16f;
	FrameBg[1] = 0.29f;
	FrameBg[2] = 0.48f;
	FrameBg[3] = 0.54f;

	FrameBgHovered[0] = 0.26f;
	FrameBgHovered[1] = 0.59f;
	FrameBgHovered[2] = 0.98f;
	FrameBgHovered[3] = 0.40f;

	FrameBgActive[0] = 0.26f;
	FrameBgActive[1] = 0.59f;
	FrameBgActive[2] = 0.98f;
	FrameBgActive[3] = 0.67f;

	TitleBg[0] = 0.04f;
	TitleBg[1] = 0.04f;
	TitleBg[2] = 0.04f;
	TitleBg[3] = 1.00f;

	TitleBgActive[0] = 0.16f;
	TitleBgActive[1] = 0.29f;
	TitleBgActive[2] = 0.48f;
	TitleBgActive[3] = 1.00f;

	TitleBgCollapsed[0] = 0.00f;
	TitleBgCollapsed[1] = 0.00f;
	TitleBgCollapsed[2] = 0.00f;
	TitleBgCollapsed[3] = 0.51f;

	MenuBarBg[0] = 0.14f;
	MenuBarBg[1] = 0.14f;
	MenuBarBg[2] = 0.14f;
	MenuBarBg[3] = 1.00f;

	ScrollbarBg[0] = 0.02f;
	ScrollbarBg[1] = 0.02f;
	ScrollbarBg[2] = 0.02f;
	ScrollbarBg[3] = 0.53f;

	ScrollbarGrab[0] = 0.31f;
	ScrollbarGrab[1] = 0.31f;
	ScrollbarGrab[2] = 0.31f;
	ScrollbarGrab[3] = 1.00f;

	ScrollbarGrabHovered[0] = 0.41f;
	ScrollbarGrabHovered[1] = 0.41f;
	ScrollbarGrabHovered[2] = 0.41f;
	ScrollbarGrabHovered[3] = 1.00f;

	ScrollbarGrabActive[0] = 0.51f;
	ScrollbarGrabActive[1] = 0.51f;
	ScrollbarGrabActive[2] = 0.51f;
	ScrollbarGrabActive[3] = 1.00f;

	CheckMark[0] = 0.26f;
	CheckMark[1] = 0.59f;
	CheckMark[2] = 0.98f;
	CheckMark[3] = 1.00f;

	SliderGrab[0] = 0.24f;
	SliderGrab[1] = 0.52f;
	SliderGrab[2] = 0.88f;
	SliderGrab[3] = 1.00f;

	SliderGrabActive[0] = 0.26f;
	SliderGrabActive[1] = 0.59f;
	SliderGrabActive[2] = 0.98f;
	SliderGrabActive[3] = 1.00f;

	Button[0] = 0.26f;
	Button[1] = 0.59f;
	Button[2] = 0.98f;
	Button[3] = 0.40f;

	ButtonHovered[0] = 0.26f;
	ButtonHovered[1] = 0.59f;
	ButtonHovered[2] = 0.98f;
	ButtonHovered[3] = 1.00f;

	ButtonActive[0] = 0.06f;
	ButtonActive[1] = 0.53f;
	ButtonActive[2] = 0.98f;
	ButtonActive[3] = 1.00f;

	Header[0] = 0.26f;
	Header[1] = 0.59f;
	Header[2] = 0.98f;
	Header[3] = 0.31f;

	HeaderHovered[0] = 0.26f;
	HeaderHovered[1] = 0.59f;
	HeaderHovered[2] = 0.98f;
	HeaderHovered[3] = 0.80f;

	HeaderActive[0] = 0.26f;
	HeaderActive[1] = 0.59f;
	HeaderActive[2] = 0.98f;
	HeaderActive[3] = 1.00f;

	Separator[0] = Border[0];
	Separator[1] = Border[1];
	Separator[2] = Border[2];
	Separator[3] = Border[3];

	SeparatorHovered[0] = 0.10f;
	SeparatorHovered[1] = 0.40f;
	SeparatorHovered[2] = 0.75f;
	SeparatorHovered[3] = 0.78f;

	SeparatorActive[0] = 0.10f;
	SeparatorActive[1] = 0.40f;
	SeparatorActive[2] = 0.75f;
	SeparatorActive[3] = 1.00f;

	ResizeGrip[0] = 0.26f;
	ResizeGrip[1] = 0.59f;
	ResizeGrip[2] = 0.98f;
	ResizeGrip[3] = 0.20f;

	ResizeGripHovered[0] = 0.26f;
	ResizeGripHovered[1] = 0.59f;
	ResizeGripHovered[2] = 0.98f;
	ResizeGripHovered[3] = 0.67f;

	ResizeGripActive[0] = 0.26f;
	ResizeGripActive[1] = 0.59f;
	ResizeGripActive[2] = 0.98f;
	ResizeGripActive[3] = 0.95f;

	Tab[0] = Header[0];
	Tab[1] = Header[1];
	Tab[2] = Header[2];
	Tab[3] = Header[3];

	TabHovered[0] = HeaderHovered[0];
	TabHovered[1] = HeaderHovered[1];
	TabHovered[2] = HeaderHovered[2];
	TabHovered[3] = HeaderHovered[3];

	TabActive[0] = HeaderActive[0];
	TabActive[1] = HeaderActive[1];
	TabActive[2] = HeaderActive[2];
	TabActive[3] = HeaderActive[3];

	TabUnfocused[0] = Tab[0];
	TabUnfocused[1] = Tab[1];
	TabUnfocused[2] = Tab[2];
	TabUnfocused[3] = Tab[3];

	TabUnfocusedActive[0] = TabActive[0];
	TabUnfocusedActive[1] = TabActive[1];
	TabUnfocusedActive[2] = TabActive[2];
	TabUnfocusedActive[3] = TabActive[3];

	PlotLines[0] = 0.61f;
	PlotLines[1] = 0.61f;
	PlotLines[2] = 0.61f;
	PlotLines[3] = 1.00f;

	PlotLinesHovered[0] = 1.00f;
	PlotLinesHovered[1] = 0.43f;
	PlotLinesHovered[2] = 0.35f;
	PlotLinesHovered[3] = 1.00f;

	PlotHistogram[0] = 0.90f;
	PlotHistogram[1] = 0.70f;
	PlotHistogram[2] = 0.00f;
	PlotHistogram[3] = 1.00f;

	PlotHistogramHovered[0] = 1.00f;
	PlotHistogramHovered[1] = 0.60f;
	PlotHistogramHovered[2] = 0.00f;
	PlotHistogramHovered[3] = 1.00f;

	TableHeaderBg[0] = 0.19f;
	TableHeaderBg[1] = 0.19f;
	TableHeaderBg[2] = 0.20f;
	TableHeaderBg[3] = 1.00f;

	TableBorderStrong[0] = 0.31f;
	TableBorderStrong[1] = 0.31f;
	TableBorderStrong[2] = 0.35f;
	TableBorderStrong[3] = 1.00f;
	// Prefer using Alpha=1.0 here
	TableBorderLight[0] = 0.23f;
	TableBorderLight[1] = 0.23f;
	TableBorderLight[2] = 0.25f;
	TableBorderLight[3] = 1.00f;
	// Prefer using Alpha=1.0 here
	TableRowBg[0] = 0.00f;
	TableRowBg[1] = 0.00f;
	TableRowBg[2] = 0.00f;
	TableRowBg[3] = 0.00f;

	TableRowBgAlt[0] = 1.00f;
	TableRowBgAlt[1] = 1.00f;
	TableRowBgAlt[2] = 1.00f;
	TableRowBgAlt[3] = 0.06f;

	TextSelectedBg[0] = 0.26f;
	TextSelectedBg[1] = 0.59f;
	TextSelectedBg[2] = 0.98f;
	TextSelectedBg[3] = 0.35f;

	DragDropTarget[0] = 1.00f;
	DragDropTarget[1] = 1.00f;
	DragDropTarget[2] = 0.00f;
	DragDropTarget[3] = 0.90f;

	NavHighlight[0] = 0.26f;
	NavHighlight[1] = 0.59f;
	NavHighlight[2] = 0.98f;
	NavHighlight[3] = 1.00f;

	NavWindowingHighlight[0] = 1.00f;
	NavWindowingHighlight[1] = 1.00f;
	NavWindowingHighlight[2] = 1.00f;
	NavWindowingHighlight[3] = 0.70f;

	NavWindowingDimBg[0] = 0.80f;
	NavWindowingDimBg[1] = 0.80f;
	NavWindowingDimBg[2] = 0.80f;
	NavWindowingDimBg[3] = 0.20f;

	ModalWindowDimBg[0] = 0.80f;
	ModalWindowDimBg[1] = 0.80f;
	ModalWindowDimBg[2] = 0.80f;
	ModalWindowDimBg[3] = 0.3f;

	LoadTheme();
}



void ImGuiTheme::UpdateTheme()
{
	ImGuiStyle* style = &ImGui::GetStyle();
	ImVec4* colors = style->Colors;
	colors[ImGuiCol_Text].x = Text[0];
	colors[ImGuiCol_Text].y = Text[1];
	colors[ImGuiCol_Text].z = Text[2];
	colors[ImGuiCol_Text].w = Text[3];

	colors[ImGuiCol_TextDisabled].x = TextDisabled[0];
	colors[ImGuiCol_TextDisabled].y = TextDisabled[1];
	colors[ImGuiCol_TextDisabled].z = TextDisabled[2];
	colors[ImGuiCol_TextDisabled].w = TextDisabled[3];

	colors[ImGuiCol_WindowBg].x = WindowBg[0];
	colors[ImGuiCol_WindowBg].y = WindowBg[1];
	colors[ImGuiCol_WindowBg].z = WindowBg[2];
	colors[ImGuiCol_WindowBg].w = WindowBg[3];

	colors[ImGuiCol_ChildBg].x = ChildBg[0];
	colors[ImGuiCol_ChildBg].y = ChildBg[1];
	colors[ImGuiCol_ChildBg].z = ChildBg[2];
	colors[ImGuiCol_ChildBg].w = ChildBg[3];

	colors[ImGuiCol_PopupBg].x = PopupBg[0];
	colors[ImGuiCol_PopupBg].y = PopupBg[1];
	colors[ImGuiCol_PopupBg].z = PopupBg[2];
	colors[ImGuiCol_PopupBg].w = PopupBg[3];

	colors[ImGuiCol_Border].x = Border[0];
	colors[ImGuiCol_Border].y = Border[1];
	colors[ImGuiCol_Border].z = Border[2];
	colors[ImGuiCol_Border].w = Border[3];

	colors[ImGuiCol_BorderShadow].x = BorderShadow[0];
	colors[ImGuiCol_BorderShadow].y = BorderShadow[1];
	colors[ImGuiCol_BorderShadow].z = BorderShadow[2];
	colors[ImGuiCol_BorderShadow].w = BorderShadow[3];

	colors[ImGuiCol_FrameBg].x = FrameBg[0];
	colors[ImGuiCol_FrameBg].y = FrameBg[1];
	colors[ImGuiCol_FrameBg].z = FrameBg[2];
	colors[ImGuiCol_FrameBg].w = FrameBg[3];

	colors[ImGuiCol_FrameBgHovered].x = FrameBgHovered[0];
	colors[ImGuiCol_FrameBgHovered].y = FrameBgHovered[1];
	colors[ImGuiCol_FrameBgHovered].z = FrameBgHovered[2];
	colors[ImGuiCol_FrameBgHovered].w = FrameBgHovered[3];

	colors[ImGuiCol_FrameBgActive].x = FrameBgActive[0];
	colors[ImGuiCol_FrameBgActive].y = FrameBgActive[1];
	colors[ImGuiCol_FrameBgActive].z = FrameBgActive[2];
	colors[ImGuiCol_FrameBgActive].w = FrameBgActive[3];

	colors[ImGuiCol_TitleBg].x = TitleBg[0];
	colors[ImGuiCol_TitleBg].y = TitleBg[1];
	colors[ImGuiCol_TitleBg].z = TitleBg[2];
	colors[ImGuiCol_TitleBg].w = TitleBg[3];

	colors[ImGuiCol_TitleBgActive].x = TitleBgActive[0];
	colors[ImGuiCol_TitleBgActive].y = TitleBgActive[1];
	colors[ImGuiCol_TitleBgActive].z = TitleBgActive[2];
	colors[ImGuiCol_TitleBgActive].w = TitleBgActive[3];

	colors[ImGuiCol_TitleBgCollapsed].x = TitleBgCollapsed[0];
	colors[ImGuiCol_TitleBgCollapsed].y = TitleBgCollapsed[1];
	colors[ImGuiCol_TitleBgCollapsed].z = TitleBgCollapsed[2];
	colors[ImGuiCol_TitleBgCollapsed].w = TitleBgCollapsed[3];

	colors[ImGuiCol_MenuBarBg].x = MenuBarBg[0];
	colors[ImGuiCol_MenuBarBg].y = MenuBarBg[1];
	colors[ImGuiCol_MenuBarBg].z = MenuBarBg[2];
	colors[ImGuiCol_MenuBarBg].w = MenuBarBg[3];

	colors[ImGuiCol_ScrollbarBg].x = ScrollbarBg[0];
	colors[ImGuiCol_ScrollbarBg].y = ScrollbarBg[1];
	colors[ImGuiCol_ScrollbarBg].z = ScrollbarBg[2];
	colors[ImGuiCol_ScrollbarBg].w = ScrollbarBg[3];

	colors[ImGuiCol_ScrollbarGrab].x = ScrollbarGrab[0];
	colors[ImGuiCol_ScrollbarGrab].y = ScrollbarGrab[1];
	colors[ImGuiCol_ScrollbarGrab].z = ScrollbarGrab[2];
	colors[ImGuiCol_ScrollbarGrab].w = ScrollbarGrab[3];

	colors[ImGuiCol_ScrollbarGrabHovered].x = ScrollbarGrabHovered[0];
	colors[ImGuiCol_ScrollbarGrabHovered].y = ScrollbarGrabHovered[1];
	colors[ImGuiCol_ScrollbarGrabHovered].z = ScrollbarGrabHovered[2];
	colors[ImGuiCol_ScrollbarGrabHovered].w = ScrollbarGrabHovered[3];

	colors[ImGuiCol_ScrollbarGrabActive].x = ScrollbarGrabActive[0];
	colors[ImGuiCol_ScrollbarGrabActive].y = ScrollbarGrabActive[1];
	colors[ImGuiCol_ScrollbarGrabActive].z = ScrollbarGrabActive[2];
	colors[ImGuiCol_ScrollbarGrabActive].w = ScrollbarGrabActive[3];

	colors[ImGuiCol_CheckMark].x = CheckMark[0];
	colors[ImGuiCol_CheckMark].y = CheckMark[1];
	colors[ImGuiCol_CheckMark].z = CheckMark[2];
	colors[ImGuiCol_CheckMark].w = CheckMark[3];

	colors[ImGuiCol_SliderGrab].x = SliderGrab[0];
	colors[ImGuiCol_SliderGrab].y = SliderGrab[1];
	colors[ImGuiCol_SliderGrab].z = SliderGrab[2];
	colors[ImGuiCol_SliderGrab].w = SliderGrab[3];

	colors[ImGuiCol_SliderGrabActive].x = SliderGrabActive[0];
	colors[ImGuiCol_SliderGrabActive].y = SliderGrabActive[1];
	colors[ImGuiCol_SliderGrabActive].z = SliderGrabActive[2];
	colors[ImGuiCol_SliderGrabActive].w = SliderGrabActive[3];

	colors[ImGuiCol_Button].x = Button[0];
	colors[ImGuiCol_Button].y = Button[1];
	colors[ImGuiCol_Button].z = Button[2];
	colors[ImGuiCol_Button].w = Button[3];

	colors[ImGuiCol_ButtonHovered].x = ButtonHovered[0];
	colors[ImGuiCol_ButtonHovered].y = ButtonHovered[1];
	colors[ImGuiCol_ButtonHovered].z = ButtonHovered[2];
	colors[ImGuiCol_ButtonHovered].w = ButtonHovered[3];

	colors[ImGuiCol_ButtonActive].x = ButtonActive[0];
	colors[ImGuiCol_ButtonActive].y = ButtonActive[1];
	colors[ImGuiCol_ButtonActive].z = ButtonActive[2];
	colors[ImGuiCol_ButtonActive].w = ButtonActive[3];

	colors[ImGuiCol_Header].x = Header[0];
	colors[ImGuiCol_Header].y = Header[1];
	colors[ImGuiCol_Header].z = Header[2];
	colors[ImGuiCol_Header].w = Header[3];

	colors[ImGuiCol_HeaderHovered].x = HeaderHovered[0];
	colors[ImGuiCol_HeaderHovered].y = HeaderHovered[1];
	colors[ImGuiCol_HeaderHovered].z = HeaderHovered[2];
	colors[ImGuiCol_HeaderHovered].w = HeaderHovered[3];

	colors[ImGuiCol_HeaderActive].x = HeaderActive[0];
	colors[ImGuiCol_HeaderActive].y = HeaderActive[1];
	colors[ImGuiCol_HeaderActive].z = HeaderActive[2];
	colors[ImGuiCol_HeaderActive].w = HeaderActive[3];

	colors[ImGuiCol_Separator].x = Border[0];
	colors[ImGuiCol_Separator].y = Border[1];
	colors[ImGuiCol_Separator].z = Border[2];
	colors[ImGuiCol_Separator].w = Border[3];

	colors[ImGuiCol_SeparatorHovered].x = SeparatorHovered[0];
	colors[ImGuiCol_SeparatorHovered].y = SeparatorHovered[1];
	colors[ImGuiCol_SeparatorHovered].z = SeparatorHovered[2];
	colors[ImGuiCol_SeparatorHovered].w = SeparatorHovered[3];

	colors[ImGuiCol_SeparatorActive].x = SeparatorActive[0];
	colors[ImGuiCol_SeparatorActive].y = SeparatorActive[1];
	colors[ImGuiCol_SeparatorActive].z = SeparatorActive[2];
	colors[ImGuiCol_SeparatorActive].w = SeparatorActive[3];

	colors[ImGuiCol_ResizeGrip].x = ResizeGrip[0];
	colors[ImGuiCol_ResizeGrip].y = ResizeGrip[1];
	colors[ImGuiCol_ResizeGrip].z = ResizeGrip[2];
	colors[ImGuiCol_ResizeGrip].w = ResizeGrip[3];

	colors[ImGuiCol_ResizeGripHovered].x = ResizeGripHovered[0];
	colors[ImGuiCol_ResizeGripHovered].y = ResizeGripHovered[1];
	colors[ImGuiCol_ResizeGripHovered].z = ResizeGripHovered[2];
	colors[ImGuiCol_ResizeGripHovered].w = ResizeGripHovered[3];

	colors[ImGuiCol_ResizeGripActive].x = ResizeGripActive[0];
	colors[ImGuiCol_ResizeGripActive].y = ResizeGripActive[1];
	colors[ImGuiCol_ResizeGripActive].z = ResizeGripActive[2];
	colors[ImGuiCol_ResizeGripActive].w = ResizeGripActive[3];

	colors[ImGuiCol_Tab].x = Tab[0];
	colors[ImGuiCol_Tab].y = Tab[1];
	colors[ImGuiCol_Tab].z = Tab[2];
	colors[ImGuiCol_Tab].w = Tab[3];

	colors[ImGuiCol_TabHovered].x = HeaderHovered[0];
	colors[ImGuiCol_TabHovered].y = HeaderHovered[1];
	colors[ImGuiCol_TabHovered].z = HeaderHovered[2];
	colors[ImGuiCol_TabHovered].w = HeaderHovered[3];

	colors[ImGuiCol_TabActive].x = TabActive[0];
	colors[ImGuiCol_TabActive].y = TabActive[1];
	colors[ImGuiCol_TabActive].z = TabActive[2];
	colors[ImGuiCol_TabActive].w = TabActive[3];

	colors[ImGuiCol_TabUnfocused].x = TabUnfocused[0];
	colors[ImGuiCol_TabUnfocused].y = TabUnfocused[1];
	colors[ImGuiCol_TabUnfocused].z = TabUnfocused[2];
	colors[ImGuiCol_TabUnfocused].w = TabUnfocused[3];

	colors[ImGuiCol_TabUnfocusedActive].x = TabUnfocusedActive[0];
	colors[ImGuiCol_TabUnfocusedActive].y = TabUnfocusedActive[1];
	colors[ImGuiCol_TabUnfocusedActive].z = TabUnfocusedActive[2];
	colors[ImGuiCol_TabUnfocusedActive].w = TabUnfocusedActive[3];

	colors[ImGuiCol_PlotLines].x = PlotLines[0];
	colors[ImGuiCol_PlotLines].y = PlotLines[1];
	colors[ImGuiCol_PlotLines].z = PlotLines[2];
	colors[ImGuiCol_PlotLines].w = PlotLines[3];

	colors[ImGuiCol_PlotLinesHovered].x = PlotLinesHovered[0];
	colors[ImGuiCol_PlotLinesHovered].y = PlotLinesHovered[1];
	colors[ImGuiCol_PlotLinesHovered].z = PlotLinesHovered[2];
	colors[ImGuiCol_PlotLinesHovered].w = PlotLinesHovered[3];

	colors[ImGuiCol_PlotHistogram].x = PlotHistogram[0];
	colors[ImGuiCol_PlotHistogram].y = PlotHistogram[1];
	colors[ImGuiCol_PlotHistogram].z = PlotHistogram[2];
	colors[ImGuiCol_PlotHistogram].w = PlotHistogram[3];

	colors[ImGuiCol_PlotHistogramHovered].x = PlotHistogramHovered[0];
	colors[ImGuiCol_PlotHistogramHovered].y = PlotHistogramHovered[1];
	colors[ImGuiCol_PlotHistogramHovered].z = PlotHistogramHovered[2];
	colors[ImGuiCol_PlotHistogramHovered].w = PlotHistogramHovered[3];

	colors[ImGuiCol_TableHeaderBg].x = TableHeaderBg[0];
	colors[ImGuiCol_TableHeaderBg].y = TableHeaderBg[1];
	colors[ImGuiCol_TableHeaderBg].z = TableHeaderBg[2];
	colors[ImGuiCol_TableHeaderBg].w = TableHeaderBg[3];

	colors[ImGuiCol_TableBorderStrong].x = TableBorderStrong[0];
	colors[ImGuiCol_TableBorderStrong].y = TableBorderStrong[1];
	colors[ImGuiCol_TableBorderStrong].z = TableBorderStrong[2];
	colors[ImGuiCol_TableBorderStrong].w = TableBorderStrong[3];
	// Prefer using Alpha=1.0 here
	colors[ImGuiCol_TableBorderLight].x = TableBorderLight[0];
	colors[ImGuiCol_TableBorderLight].y = TableBorderLight[1];
	colors[ImGuiCol_TableBorderLight].z = TableBorderLight[2];
	colors[ImGuiCol_TableBorderLight].w = TableBorderLight[3];
	// Prefer using Alpha=1.0 here
	colors[ImGuiCol_TableRowBg].x = TableRowBg[0];
	colors[ImGuiCol_TableRowBg].y = TableRowBg[1];
	colors[ImGuiCol_TableRowBg].z = TableRowBg[2];
	colors[ImGuiCol_TableRowBg].w = TableRowBg[3];

	colors[ImGuiCol_TableRowBgAlt].x = TableRowBgAlt[0];
	colors[ImGuiCol_TableRowBgAlt].y = TableRowBgAlt[1];
	colors[ImGuiCol_TableRowBgAlt].z = TableRowBgAlt[2];
	colors[ImGuiCol_TableRowBgAlt].w = TableRowBgAlt[3];

	colors[ImGuiCol_TextSelectedBg].x = TextSelectedBg[0];
	colors[ImGuiCol_TextSelectedBg].y = TextSelectedBg[1];
	colors[ImGuiCol_TextSelectedBg].z = TextSelectedBg[2];
	colors[ImGuiCol_TextSelectedBg].w = TextSelectedBg[3];

	colors[ImGuiCol_DragDropTarget].x = DragDropTarget[0];
	colors[ImGuiCol_DragDropTarget].y = DragDropTarget[1];
	colors[ImGuiCol_DragDropTarget].z = DragDropTarget[2];
	colors[ImGuiCol_DragDropTarget].w = DragDropTarget[3];

	colors[ImGuiCol_NavHighlight].x = NavHighlight[0];
	colors[ImGuiCol_NavHighlight].y = NavHighlight[1];
	colors[ImGuiCol_NavHighlight].z = NavHighlight[2];
	colors[ImGuiCol_NavHighlight].w = NavHighlight[3];

	colors[ImGuiCol_NavWindowingHighlight].x = NavWindowingHighlight[0];
	colors[ImGuiCol_NavWindowingHighlight].y = NavWindowingHighlight[1];
	colors[ImGuiCol_NavWindowingHighlight].z = NavWindowingHighlight[2];
	colors[ImGuiCol_NavWindowingHighlight].w = NavWindowingHighlight[3];

	colors[ImGuiCol_NavWindowingDimBg].x = NavWindowingDimBg[0];
	colors[ImGuiCol_NavWindowingDimBg].y = NavWindowingDimBg[1];
	colors[ImGuiCol_NavWindowingDimBg].z = NavWindowingDimBg[2];
	colors[ImGuiCol_NavWindowingDimBg].w = NavWindowingDimBg[3];

	colors[ImGuiCol_ModalWindowDimBg].x = ModalWindowDimBg[0];
	colors[ImGuiCol_ModalWindowDimBg].y = ModalWindowDimBg[1];
	colors[ImGuiCol_ModalWindowDimBg].z = ModalWindowDimBg[2];
	colors[ImGuiCol_ModalWindowDimBg].w = ModalWindowDimBg[3];

	
}


void ImGuiTheme::InputThemeParameter(std::string name, float p1, float p2, float p3, float p4)
{
	//printf("%s %f %f %f %f\n", name.c_str(), p1, p2, p3, p4);
	if (name == "Text")
	{
		Text[0] = p1;
		Text[1] = p2;
		Text[2] = p3;
		Text[3] = p4;
	}

	if (name == "TextDisabled")
	{
		TextDisabled[0] = p1;
		TextDisabled[1] = p2;
		TextDisabled[2] = p3;
		TextDisabled[3] = p4;
	}

	if (name == "WindowBg")
	{
		WindowBg[0] = p1;
		WindowBg[1] = p2;
		WindowBg[2] = p3;
		WindowBg[3] = p4;
	}

	if (name == "ChildBg")
	{
		ChildBg[0] = p1;
		ChildBg[1] = p2;
		ChildBg[2] = p3;
		ChildBg[3] = p4;
	}

	if (name == "PopupBg")
	{
		PopupBg[0] = p1;
		PopupBg[1] = p2;
		PopupBg[2] = p3;
		PopupBg[3] = p4;
	}

	if (name == "Border")
	{
		Border[0] = p1;
		Border[1] = p2;
		Border[2] = p3;
		Border[3] = p4;
	}

	if (name == "BorderShadow")
	{
		BorderShadow[0] = p1;
		BorderShadow[1] = p2;
		BorderShadow[2] = p3;
		BorderShadow[3] = p4;
	}

	if (name == "FrameBg")
	{
		FrameBg[0] = p1;
		FrameBg[1] = p2;
		FrameBg[2] = p3;
		FrameBg[3] = p4;
	}

	if (name == "FrameBgHovered")
	{
		FrameBgHovered[0] = p1;
		FrameBgHovered[1] = p2;
		FrameBgHovered[2] = p3;
		FrameBgHovered[3] = p4;
	}

	if (name == "FrameBgActive")
	{
		FrameBgActive[0] = p1;
		FrameBgActive[1] = p2;
		FrameBgActive[2] = p3;
		FrameBgActive[3] = p4;
	}

	if (name == "TitleBg")
	{
		TitleBg[0] = p1;
		TitleBg[1] = p2;
		TitleBg[2] = p3;
		TitleBg[3] = p4;
	}

	if (name == "TitleBgActive")
	{
		TitleBgActive[0] = p1;
		TitleBgActive[1] = p2;
		TitleBgActive[2] = p3;
		TitleBgActive[3] = p4;
	}

	if (name == "TitleBgCollapsed")
	{
		TitleBgCollapsed[0] = p1;
		TitleBgCollapsed[1] = p2;
		TitleBgCollapsed[2] = p3;
		TitleBgCollapsed[3] = p4;
	}

	if (name == "MenuBarBg")
	{
		MenuBarBg[0] = p1;
		MenuBarBg[1] = p2;
		MenuBarBg[2] = p3;
		MenuBarBg[3] = p4;
	}

	if (name == "ScrollbarBg")
	{
		ScrollbarBg[0] = p1;
		ScrollbarBg[1] = p2;
		ScrollbarBg[2] = p3;
		ScrollbarBg[3] = p4;
	}

	if (name == "ScrollbarGrab")
	{
		ScrollbarGrab[0] = p1;
		ScrollbarGrab[1] = p2;
		ScrollbarGrab[2] = p3;
		ScrollbarGrab[3] = p4;
	}

	if (name == "ScrollbarGrabHovered")
	{
		ScrollbarGrabHovered[0] = p1;
		ScrollbarGrabHovered[1] = p2;
		ScrollbarGrabHovered[2] = p3;
		ScrollbarGrabHovered[3] = p4;
	}

	if (name == "ScrollbarGrabActive")
	{
		ScrollbarGrabActive[0] = p1;
		ScrollbarGrabActive[1] = p2;
		ScrollbarGrabActive[2] = p3;
		ScrollbarGrabActive[3] = p4;
	}

	if (name == "CheckMark")
	{
		CheckMark[0] = p1;
		CheckMark[1] = p2;
		CheckMark[2] = p3;
		CheckMark[3] = p4;
	}

	if (name == "SliderGrab")
	{
		SliderGrab[0] = p1;
		SliderGrab[1] = p2;
		SliderGrab[2] = p3;
		SliderGrab[3] = p4;
	}

	if (name == "SliderGrabActive")
	{
		SliderGrabActive[0] = p1;
		SliderGrabActive[1] = p2;
		SliderGrabActive[2] = p3;
		SliderGrabActive[3] = p4;
	}

	if (name == "Button")
	{
		Button[0] = p1;
		Button[1] = p2;
		Button[2] = p3;
		Button[3] = p4;
	}

	if (name == "ButtonHovered")
	{
		ButtonHovered[0] = p1;
		ButtonHovered[1] = p2;
		ButtonHovered[2] = p3;
		ButtonHovered[3] = p4;
	}

	if (name == "ButtonActive")
	{
		ButtonActive[0] = p1;
		ButtonActive[1] = p2;
		ButtonActive[2] = p3;
		ButtonActive[3] = p4;
	}

	if (name == "Header")
	{
		Header[0] = p1;
		Header[1] = p2;
		Header[2] = p3;
		Header[3] = p4;
	}

	if (name == "HeaderHovered")
	{
		HeaderHovered[0] = p1;
		HeaderHovered[1] = p2;
		HeaderHovered[2] = p3;
		HeaderHovered[3] = p4;
	}

	if (name == "HeaderActive")
	{
		HeaderActive[0] = p1;
		HeaderActive[1] = p2;
		HeaderActive[2] = p3;
		HeaderActive[3] = p4;
	}

	if (name == "Separator")
	{
		Separator[0] = p1;
		Separator[1] = p2;
		Separator[2] = p3;
		Separator[3] = p4;
	}

	if (name == "SeparatorHovered")
	{
		SeparatorHovered[0] = p1;
		SeparatorHovered[1] = p2;
		SeparatorHovered[2] = p3;
		SeparatorHovered[3] = p4;
	}

	if (name == "SeparatorActive")
	{
		SeparatorActive[0] = p1;
		SeparatorActive[1] = p2;
		SeparatorActive[2] = p3;
		SeparatorActive[3] = p4;
	}

	if (name == "ResizeGrip")
	{
		ResizeGrip[0] = p1;
		ResizeGrip[1] = p2;
		ResizeGrip[2] = p3;
		ResizeGrip[3] = p4;
	}

	if (name == "ResizeGripHovered")
	{
		ResizeGripHovered[0] = p1;
		ResizeGripHovered[1] = p2;
		ResizeGripHovered[2] = p3;
		ResizeGripHovered[3] = p4;
	}

	if (name == "ResizeGripActive")
	{
		ResizeGripActive[0] = p1;
		ResizeGripActive[1] = p2;
		ResizeGripActive[2] = p3;
		ResizeGripActive[3] = p4;
	}

	if (name == "Tab")
	{
		Tab[0] = p1;
		Tab[1] = p2;
		Tab[2] = p3;
		Tab[3] = p4;
	}

	if (name == "TabHovered")
	{
		TabHovered[0] = p1;
		TabHovered[1] = p2;
		TabHovered[2] = p3;
		TabHovered[3] = p4;
	}

	if (name == "TabActive")
	{
		TabActive[0] = p1;
		TabActive[1] = p2;
		TabActive[2] = p3;
		TabActive[3] = p4;
	}

	if (name == "TabUnfocused")
	{
		TabUnfocused[0] = p1;
		TabUnfocused[1] = p2;
		TabUnfocused[2] = p3;
		TabUnfocused[3] = p4;
	}

	if (name == "TabUnfocusedActive")
	{
		TabUnfocusedActive[0] = p1;
		TabUnfocusedActive[1] = p2;
		TabUnfocusedActive[2] = p3;
		TabUnfocusedActive[3] = p4;
	}

	if (name == "PlotLines")
	{
		PlotLines[0] = p1;
		PlotLines[1] = p2;
		PlotLines[2] = p3;
		PlotLines[3] = p4;
	}

	if (name == "PlotLinesHovered")
	{
		PlotLinesHovered[0] = p1;
		PlotLinesHovered[1] = p2;
		PlotLinesHovered[2] = p3;
		PlotLinesHovered[3] = p4;
	}

	if (name == "PlotHistogram")
	{
		PlotHistogram[0] = p1;
		PlotHistogram[1] = p2;
		PlotHistogram[2] = p3;
		PlotHistogram[3] = p4;
	}

	if (name == "PlotHistogramHovered")
	{
		PlotHistogramHovered[0] = p1;
		PlotHistogramHovered[1] = p2;
		PlotHistogramHovered[2] = p3;
		PlotHistogramHovered[3] = p4;
	}

	if (name == "TableHeaderBg")
	{
		TableHeaderBg[0] = p1;
		TableHeaderBg[1] = p2;
		TableHeaderBg[2] = p3;
		TableHeaderBg[3] = p4;
	}

	if (name == "TableBorderStrong")
	{
		TableBorderStrong[0] = p1;
		TableBorderStrong[1] = p2;
		TableBorderStrong[2] = p3;
		TableBorderStrong[3] = p4;
	}

	if (name == "TableBorderLight")
	{
		TableBorderLight[0] = p1;
		TableBorderLight[1] = p2;
		TableBorderLight[2] = p3;
		TableBorderLight[3] = p4;
	}

	if (name == "TableRowBg")
	{
		TableRowBg[0] = p1;
		TableRowBg[1] = p2;
		TableRowBg[2] = p3;
		TableRowBg[3] = p4;
	}

	if (name == "TableRowBgAlt")
	{
		TableRowBgAlt[0] = p1;
		TableRowBgAlt[1] = p2;
		TableRowBgAlt[2] = p3;
		TableRowBgAlt[3] = p4;
	}

	if (name == "TextSelectedBg")
	{
		TextSelectedBg[0] = p1;
		TextSelectedBg[1] = p2;
		TextSelectedBg[2] = p3;
		TextSelectedBg[3] = p4;
	}

	if (name == "DragDropTarget")
	{
		DragDropTarget[0] = p1;
		DragDropTarget[1] = p2;
		DragDropTarget[2] = p3;
		DragDropTarget[3] = p4;
	}

	if (name == "NavHighlight")
	{
		NavHighlight[0] = p1;
		NavHighlight[1] = p2;
		NavHighlight[2] = p3;
		NavHighlight[3] = p4;
	}

	if (name == "NavWindowingHighlight")
	{
		NavWindowingHighlight[0] = p1;
		NavWindowingHighlight[1] = p2;
		NavWindowingHighlight[2] = p3;
		NavWindowingHighlight[3] = p4;
	}

	if (name == "NavWindowingDimBg")
	{
		NavWindowingDimBg[0] = p1;
		NavWindowingDimBg[1] = p2;
		NavWindowingDimBg[2] = p3;
		NavWindowingDimBg[3] = p4;
	}

	if (name == "ModalWindowDimBg")
	{
		ModalWindowDimBg[0] = p1;
		ModalWindowDimBg[1] = p2;
		ModalWindowDimBg[2] = p3;
		ModalWindowDimBg[3] = p4;
	}

}