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
	linePts[0] = D3DXVECTOR2(x1, y1);
	linePts[1] = D3DXVECTOR2(x2, y2);
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
		ImGui::Checkbox("Server Cheats Enabled", &cheatsGlobal->serverCheatsEnabled);
		if (cheatsGlobal->serverCheatsEnabled)
		{
			ImGui::Text("Server Cheats:");
			ImGui::Indent();
			ImGui::Checkbox("Speed", &cheatsGlobal->speed->enable);
			ImGui::Checkbox("Fly", &cheatsGlobal->fly->enable);
			ImGui::Checkbox("Infinite Ammo", &cheatsGlobal->infiniteAmmo->enable);
			ImGui::Checkbox("Infinite Health", &cheatsGlobal->infiniteHealth->enable);
			ImGui::Checkbox("No Recoil", &cheatsGlobal->noRecoil->enable);
			ImGui::Unindent();
		}
		ImGui::Text("Client Cheats:");
		ImGui::Indent();
		ImGui::Checkbox("Aimbot", &cheatsGlobal->aimbot->enable);
		ImGui::Checkbox("BHop", &cheatsGlobal->bhop->enable);
		ImGui::Checkbox("ESP", &cheatsGlobal->esp->enable);
		ImGui::Checkbox("Radar", &cheatsGlobal->radar->enable);
		ImGui::Unindent();
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

#pragma warning(default: 4838)
