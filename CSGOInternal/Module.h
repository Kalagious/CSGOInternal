#pragma once
#include <iostream>
#include "screenmanager.h"

#pragma warning(disable: 26495)

extern ScreenManager* screenManagerGlobal;

class Module
{
public:
	bool enable;
	bool serverModule;
	std::string name;
	virtual bool tick() = 0;
	virtual void drawSettings() { ImGui::Dummy(ImVec2(0.0f, 20.0f)); if (ImGui::Button("Back")) { screenManagerGlobal->GUIState = screenManagerGlobal->MAIN; }
	ImGui::Dummy(ImVec2(0.0f, 20.0f)); ImGui::Indent(); ImGui::Text(std::string("No Settings Page for " + name).c_str()); };
	virtual void status() { printf(" %15s: %s                     \n", name.c_str(), (enable) ? "Enabled" : "Disabled"); }
};
#pragma warning(default: 26495)