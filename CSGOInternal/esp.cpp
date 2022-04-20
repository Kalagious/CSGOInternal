#include "esp.h"
#include "cheats.h"

class Cheats;
extern Cheats* cheatsGlobal;


ESP::ESP(std::vector<ClientPlayer*>* entList)
{
	this->entList = entList;
	name = "ESP";
	serverModule = false;
	enable = true;
	initialized = false;
	boxWidthScale = 0.4;
	boxHeightScale = 0.25;

	showTeamBox = false;
	showTeamBones = false;
	showTeamName = true;
	showTeamHealth = false;
	showTeamArmor = false;
	showTeamWeapon = false;
	teamColor[0] = 0;
	teamColor[1] = 1;
	teamColor[2] = 0;
	teamColor[3] = 255;

	showEnemyBox = true;
	showEnemyBones = false;
	showEnemyName = true;
	showEnemyHealth = false;
	showEnemyArmor = false;
	showEnemyWeapon = false;
	enemyColor[0] = 1;
	enemyColor[1] = 0;
	enemyColor[2] = 0;
	enemyColor[3] = 255;
	nameFontSize = 16;
	screenDimensions.x = screenManagerGlobal->gameDimensions.w;
	screenDimensions.y = screenManagerGlobal->gameDimensions.h;
}


bool ESP::initialize()
{
	D3DXCreateFont(ScreenManager::d3dDevice, nameFontSize, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE, _T("Exo 2"), &screenManagerGlobal->espNameFont);
	initialized = true;
	return true;
}


bool ESP::tick()
{
	if (!entList)
		return false;

	if (!screenDimensions.x || !screenDimensions.y)
		return false;

	if (enable)
	{
		for (uint32_t i = 0; i < entList->size(); i++)
		{
			if (cheatsGlobal->IsValidAndAliveEnt(entList->at(i)))
			{

				D3DCOLOR boxColor;
				if (!clientPlayer)
					return false;
				if (entList->at(i)->i_Team != clientPlayer->i_Team)
				{
					boxColor = D3DCOLOR_RGBA(int(enemyColor[0] * 255), int(enemyColor[1] * 255), int(enemyColor[2] * 255), int(enemyColor[3]));
				}
				else
				{
					boxColor = D3DCOLOR_RGBA(int(teamColor[0] * 255), int(teamColor[1] * 255), int(teamColor[2] * 255), int(teamColor[3]));
				}


				if ((showEnemyBones && entList->at(i)->i_Team != clientPlayer->i_Team) || (showTeamBones && entList->at(i)->i_Team == clientPlayer->i_Team))
				{
					if (cheatsGlobal->IsValidAndAliveEnt(entList->at(i)))
						drawBonePoints(entList->at(i), boxColor);
				}

				if ((showEnemyBox && entList->at(i)->i_Team != clientPlayer->i_Team) || (showTeamBox && entList->at(i)->i_Team == clientPlayer->i_Team))
				{
					if (cheatsGlobal->IsValidAndAliveEnt(entList->at(i)))
						drawBox(entList->at(i), boxColor);
				}
			}
		}
	}
	return true;
}


void ESP::drawTSkeleton(ClientPlayer* ent, D3DCOLOR color)
{
	std::vector<int> spine = { 8, 9, 7, 6, 5, 4, 3, 0 };
	std::vector<int> lArm = { 7, 11, 37, 12, 35, 13, 33};
	std::vector<int> rArm = { 7, 39, 65, 40, 63, 41, 61};
	std::vector<int> lLeg = { 0, 66, 71, 72, 67, 68, 70};
	std::vector<int> rLeg = { 0, 73, 78, 79, 74, 75, 76};
	std::vector<int> test;

	drawBone(ent, spine, color);
	drawBone(ent, lArm, color);
	drawBone(ent, rArm, color);
	drawBone(ent, lLeg, color);
	drawBone(ent, rLeg, color);
}


void ESP::drawBone(ClientPlayer* ent, std::vector<int> BoneIDs, D3DCOLOR color)
{
	if (!ent)
		return;

	Matrix3x4 bone = Matrix3x4();
	bone.setData((float*)(ent->p_BoneArray + BoneIDs.at(0) * 12));
	Vector3 pos1 = screenManagerGlobal->WorldToScreen(bone.data[3], bone.data[7], bone.data[11], screenDimensions);
	Vector3 pos2 = Vector3();

	for (int i = 1; i < BoneIDs.size(); i++)
	{
		bone.setData((float*)(ent->p_BoneArray + BoneIDs.at(i) * 12));
		pos2 = screenManagerGlobal->WorldToScreen(bone.data[3], bone.data[7], bone.data[11], screenDimensions);
		if (pos1.z != -1 && pos2.z != -1 && pos1.x > 0 && pos2.x > 0 && pos1.y >0 && pos2.y > 0)
			if (sqrt(pow((ent->v_Position1.x-bone.data[3]), 2) + pow((ent->v_Position1.y - bone.data[7]), 2)) < 80)
				screenManagerGlobal->Line(pos1.x, pos1.y, pos2.x, pos2.y, 5, color);
		pos1 = pos2;
	}
}



void ESP::drawBoneIDs(ClientPlayer* ent, D3DCOLOR color)
{
	Matrix3x4 currBone = Matrix3x4();
	Vector3 pos1 = Vector3();

	for (int j = 0; j < 85; j++)
	{
		if (!((float*)(ent->p_BoneArray + j * 12))[3])
			continue;

		currBone.setData((float*)(ent->p_BoneArray + j * 12));
		pos1 = screenManagerGlobal->WorldToScreen(currBone.data[3], currBone.data[7], currBone.data[11], screenDimensions);
		
		if (pos1.x)
		{
			if (pos1.z != -1)
				screenManagerGlobal->Text(pos1.x, pos1.y, 50, 50, std::to_string(j), color);

		}
	}
}

void ESP::drawBonePoints(ClientPlayer* ent, D3DCOLOR color)
{
	Matrix3x4 currBone = Matrix3x4();
	Vector3 pos1 = Vector3();

	for (int j = 0; j < 85; j++)
	{
		if (!ent->p_BoneArray)
			break;
		if (!((float*)(ent->p_BoneArray + j * 12))[3])
			continue;

		currBone.setData((float*)(ent->p_BoneArray + j * 12));
		if (sqrt(pow((currBone.data[3] - ent->v_Position1.x), 2) + pow((currBone.data[7] - ent->v_Position1.y), 2)) > 100)
			continue;
		pos1 = screenManagerGlobal->WorldToScreen(currBone.data[3], currBone.data[7], currBone.data[11], screenDimensions);

		if (pos1.x)
		{
			if (pos1.z != -1)
			{
				float scale = 600 / pos1.z;
				if (scale > 1)
					scale = 1;

				screenManagerGlobal->FilledRect(pos1.x - 4*scale, pos1.y - 4*scale, 8*scale, 8*scale, color);
			}

		}
	}
}


void ESP::drawBox(ClientPlayer* ent, D3DCOLOR color)
{
	Matrix3x4 bone = Matrix3x4();
	bone.setData((float*)(ent->p_BoneArray + 1 * 12));
	Vector3 pos1 = screenManagerGlobal->WorldToScreen(bone.data[3], bone.data[7], bone.data[11], screenDimensions);
	bone.setData((float*)(ent->p_BoneArray + 8 * 12));
	Vector3 pos2 = screenManagerGlobal->WorldToScreen(bone.data[3], bone.data[7], bone.data[11], screenDimensions);
	if (pos1.z != -1 && pos2.z != -1 && pos1.x > 0 && pos2.x > 0 && pos1.y > 0 && pos2.y > 0)
	{
		int scale = abs(pos1.y - pos2.y);
		screenManagerGlobal->Line(pos1.x - boxWidthScale * scale, pos1.y + boxHeightScale * scale, pos1.x - boxWidthScale * scale, pos2.y - boxHeightScale * scale, 3, color);
		screenManagerGlobal->Line(pos1.x + boxWidthScale * scale, pos1.y + boxHeightScale * scale, pos1.x + boxWidthScale * scale, pos2.y - boxHeightScale * scale, 3, color);
		screenManagerGlobal->Line(pos1.x + boxWidthScale * scale, pos1.y + boxHeightScale * scale, pos1.x - boxWidthScale * scale, pos1.y + boxHeightScale * scale, 3, color);
		screenManagerGlobal->Line(pos1.x + boxWidthScale * scale, pos2.y - boxHeightScale * scale, pos1.x - boxWidthScale * scale, pos2.y - boxHeightScale * scale, 3, color);

	}
}

void ESP::drawSettings()
{
	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	if (ImGui::Button("Back"))
		screenManagerGlobal->GUIState = screenManagerGlobal->MAIN;
	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	ImGui::Text("General Settings:");
	ImGui::Indent();
	ImGui::SliderFloat("Box Width Scale", &boxWidthScale, 0, 2);
	ImGui::SliderFloat("Box Height Scale", &boxHeightScale, 0, 2);
	ImGui::Unindent();

	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	ImGui::Text("Enemy Settings:");
	ImGui::Indent();
	ImGui::Checkbox("Box##e", &showEnemyBox);
	ImGui::SameLine(200);
	ImGui::Checkbox("Bones##e", &showEnemyBones);
	ImGui::SameLine(400);
	ImGui::Checkbox("Name##e", &showEnemyName);

	ImGui::Checkbox("Health##e", &showEnemyHealth);
	ImGui::SameLine(200);
	ImGui::Checkbox("Armor##e", &showEnemyArmor);
	ImGui::SameLine(400);
	ImGui::Checkbox("Weapon##e", &showEnemyWeapon);
	ImGui::ColorEdit4("Color##e", enemyColor, ImGuiColorEditFlags_NoInputs);
	ImGui::Unindent();

	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	ImGui::Text("Team Settings:");
	ImGui::Indent();
	ImGui::Checkbox("Box##t", &showTeamBox);
	ImGui::SameLine(200);
	ImGui::Checkbox("Bones##t", &showTeamBones);
	ImGui::SameLine(400);
	ImGui::Checkbox("Name##t", &showTeamName);

	ImGui::Checkbox("Health##t", &showTeamHealth);
	ImGui::SameLine(200);
	ImGui::Checkbox("Armor##t", &showTeamArmor);
	ImGui::SameLine(400);
	ImGui::Checkbox("Weapon##t", &showTeamWeapon);
	ImGui::ColorEdit4("Color##t", teamColor, ImGuiColorEditFlags_NoInputs);
	ImGui::Unindent();
}