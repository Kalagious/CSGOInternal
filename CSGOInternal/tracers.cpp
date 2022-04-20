#include "tracers.h"
#include "cheats.h"

class Cheats;
extern Cheats* cheatsGlobal;

Tracers::Tracers(std::vector<ClientPlayer*>* entList)
{
	this->entList = entList;
	name = "Tracers";
	serverModule = false;
	enable = true;

	enemyThickness = 3;
	showEnemyTracer = true;
	showEnemyTracerOnScreen = true;
	showEnemyTracerOffScreen = true;
	enemyColor[0] = 1;
	enemyColor[1] = 0;
	enemyColor[2] = 0;
	enemyColor[3] = 255;

	teamThickness = 3;
	showTeamTracer = false;
	showTeamTracerOnScreen = false;
	showTeamTracerOffScreen = false;
	teamColor[0] = 0;
	teamColor[1] = 1;
	teamColor[2] = 0;
	teamColor[3] = 255;

	screenDimensions.x = 1920;
	screenDimensions.y = 1200;
}


bool Tracers::tick()
{
	if (!entList)
		return false;

	if (enable)
	{
		for (uint32_t i = 0; i < entList->size(); i++)
		{
			if (cheatsGlobal->IsValidAndAliveEnt(entList->at(i)))
			{
				if (!clientPlayer)
					return false;

				float thickness;
				D3DCOLOR tracerColor;


				if (entList->at(i)->i_Team != clientPlayer->i_Team)
				{
					tracerColor = D3DCOLOR_RGBA(int(enemyColor[0] * 255), int(enemyColor[1] * 255), int(enemyColor[2] * 255), int(enemyColor[3]));
					thickness = enemyThickness;
				}
				else
				{
					tracerColor = D3DCOLOR_RGBA(int(teamColor[0]*255), int(teamColor[1] * 255), int(teamColor[2] * 255), int(teamColor[3]));
					thickness = teamThickness;
				}

				if ((showEnemyTracer && entList->at(i)->i_Team != clientPlayer->i_Team) || (showTeamTracer && entList->at(i)->i_Team == clientPlayer->i_Team))
				{
					drawTracer(entList->at(i), thickness, tracerColor, (entList->at(i)->i_Team == clientPlayer->i_Team));
				}
			}
		}
	}
	return true;
}



void Tracers::drawTracer(ClientPlayer* ent, float thickness, D3DCOLOR color, bool isTeam)
{
	Matrix3x4 bone = Matrix3x4();
	bone.setData((float*)(ent->p_BoneArray + 8 * 12));
	Vector3 pos1 = screenManagerGlobal->WorldToScreen(bone.data[3], bone.data[7], bone.data[11], screenDimensions);
	if (pos1.x != -1 && pos1.x != -1)
	{
		if (pos1.z != -1 && isTeam && showTeamTracerOnScreen)
			screenManagerGlobal->Line(screenDimensions.x/2, screenDimensions.y, pos1.x, pos1.y, thickness, color);
		else if (pos1.z != -1 && !isTeam && showEnemyTracerOnScreen)
			screenManagerGlobal->Line(screenDimensions.x / 2, screenDimensions.y, pos1.x, pos1.y, thickness, color);
	}
}

void Tracers::drawSettings()
{
	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	if (ImGui::Button("Back"))
		screenManagerGlobal->GUIState = screenManagerGlobal->MAIN;
	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	ImGui::Text("Enemy Settings:");
	ImGui::Indent();
	ImGui::Checkbox("Enable##e", &showEnemyTracer);
	ImGui::Checkbox("Show On Screen##e", &showEnemyTracerOnScreen);
	ImGui::Checkbox("Show Off Screen##e", &showEnemyTracerOffScreen);
	ImGui::DragFloat("Thickness##e", &enemyThickness);
	ImGui::ColorEdit4("Color##e", enemyColor, ImGuiColorEditFlags_NoInputs);
	ImGui::Unindent();

	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	ImGui::Text("Team Settings:");
	ImGui::Indent();
	ImGui::Checkbox("Enable##t", &showTeamTracer);
	ImGui::Checkbox("Show On Screen##t", &showTeamTracerOnScreen);
	ImGui::Checkbox("Show Off Screen##t", &showTeamTracerOffScreen);
	ImGui::DragFloat("Thickness##t", &teamThickness);
	ImGui::ColorEdit4("Color##t", teamColor, ImGuiColorEditFlags_NoInputs);
	ImGui::Unindent();
}