#include "screenmanager.h"
#include "cheats.h"
#pragma warning(disable: 4838)

extern Cheats* cheatsGlobal;


void ScreenManager::FilledRect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, D3DCOLOR color)
{
	D3DRECT rect = { x, y, x + w, y + h };
	ScreenManager::d3dDevice->Clear(1, &rect, D3DCLEAR_TARGET, color, 0, 0);
}

void ScreenManager::Line(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, float w, D3DCOLOR color)
{
	if (!d3dLine)
		D3DXCreateLine(ScreenManager::d3dDevice, &d3dLine);
	D3DXVECTOR2 linePts[2];
	linePts[0] = D3DXVECTOR2((float)x1, (float)y1);
	linePts[1] = D3DXVECTOR2((float)x2, (float)y2);
	d3dLine->SetWidth(w);
	d3dLine->Draw(linePts, 2, color);
}

void ScreenManager::Text(uint32_t x, uint32_t y, uint32_t w, uint32_t h, std::string text, D3DCOLOR color)
{
	std::wstring wtext(text.begin(), text.end());
	LPD3DXFONT m_font = NULL;
	RECT rect = { x, y, x + w, y + h };
	D3DXCreateFont(ScreenManager::d3dDevice, 17, 0, FW_BOLD, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Arial"), &m_font);
	m_font->DrawText(NULL, wtext.c_str(), -1, &rect, DT_CENTER, color);
}

void ScreenManager::DrawImGUI()
{
    if (GUIIsVisable)
    {
        InputHandler();
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        ImGui::Begin("Skill Manager V1.1");
		
		switch (GUIState)
		{
		case MAIN:
			MainMenu();
			break;
		case SETTINGSSPEED:
			cheatsGlobal->speed->drawSettings();
			break;
		case SETTINGSFLY:
			cheatsGlobal->fly->drawSettings();
			break;
		case SETTINGSAMMO:
			cheatsGlobal->infiniteAmmo->drawSettings();
			break;
		case SETTINGSHEALTH:
			cheatsGlobal->infiniteHealth->drawSettings();
			break;
		case SETTINGSRECOIL:
			cheatsGlobal->noRecoil->drawSettings();
			break;
		case SETTINGSAIMBOT:
			cheatsGlobal->aimbot->drawSettings();
			break;
		case SETTINGSBHOP:
			cheatsGlobal->bhop->drawSettings();
			break;
		case SETTINGSESP:
			cheatsGlobal->esp->drawSettings();
			break;
		case SETTINGSRADAR:
			cheatsGlobal->radar->drawSettings();
			break;
		case SETTINGSGUI:
			theme->GUICustomizer();
		}

		ImGui::Dummy(ImVec2(0.0f, 20.0f));
		if (ImGui::Button("Uninject"))
			cheatsGlobal->uninject = true;
		ImGui::End();
        ImGui::EndFrame();


        ScreenManager::d3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
        ScreenManager::d3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
        ScreenManager::d3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);

        ImGui::Render();
        ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
    }
}

#define MENUENTRYENABLE(x, y); ImGui::Checkbox(x->name.c_str(), &x->enable); ImGui::SameLine(200); if (ImGui::Button(std::string(x->name+" Settings").c_str())) GUIState = y;
#define MENUENTRYNOENABLE(x, y); ImGui::Dummy(ImVec2(100.0f, 1.0f)); ImGui::Text(x->name.c_str()); ImGui::SameLine(200); if (ImGui::Button(std::string(x->name+" Settings").c_str())) GUIState = y;

void ScreenManager::MainMenu() 
{
	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	ImGui::Checkbox("Server Cheats Enabled", &cheatsGlobal->serverCheatsEnabled);
	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	if (cheatsGlobal->serverCheatsEnabled)
	{
		ImGui::Text("Server Cheats:");
		ImGui::Indent();
		MENUENTRYENABLE(cheatsGlobal->speed, SETTINGSSPEED);
		MENUENTRYNOENABLE(cheatsGlobal->fly, SETTINGSFLY);
		MENUENTRYENABLE(cheatsGlobal->infiniteAmmo, SETTINGSAMMO);
		MENUENTRYENABLE(cheatsGlobal->infiniteHealth, SETTINGSHEALTH);
		MENUENTRYENABLE(cheatsGlobal->noRecoil, SETTINGSRECOIL);
		ImGui::Unindent();
		ImGui::Dummy(ImVec2(0.0f, 20.0f));
	}
	ImGui::Text("Client Cheats:");
	ImGui::Indent();
	MENUENTRYNOENABLE(cheatsGlobal->aimbot, SETTINGSAIMBOT);
	MENUENTRYENABLE(cheatsGlobal->bhop, SETTINGSBHOP);
	MENUENTRYENABLE(cheatsGlobal->esp, SETTINGSESP);
	MENUENTRYENABLE(cheatsGlobal->radar, SETTINGSRADAR);
	ImGui::Unindent();
	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	if (ImGui::Button("Customize GUI"))
		GUIState = SETTINGSGUI;
}
#pragma warning(default: 4838)
