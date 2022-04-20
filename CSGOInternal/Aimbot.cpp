#include "aimbot.h"
#include "cheats.h"

// !!!HOOK!!!! Uses a hook on the client view angle function
class Cheats;
extern Cheats* cheatsGlobal;

Aimbot::Aimbot(std::vector<ClientPlayer*>* entList)
{
	this->entList = entList;
	name = "Aimbot";
	serverModule = false;
	enable = false;
	targetBoneID = 8;
}


bool Aimbot::tick()
{
	if (enable)
	{
		if (!clientPlayer || !entList)
			return false;


		Matrix3x4 currBone = Matrix3x4();
		currBone.setData((float*)(clientPlayer->p_BoneArray + targetBoneID * 12));
		Vector3 pos1 = Vector3(currBone.data[3], currBone.data[7], currBone.data[11]);
		Vector3 lowestDist(0, -1, 0);
		Vector3 pos2 = Vector3();

		
		for (uint32_t i = 0; i < entList->size(); i++)
		{	
			if (entList->at(i) != clientPlayer && cheatsGlobal->IsValidAndAliveEnt(entList->at(i)) && entList->at(i)->i_Team != clientPlayer->i_Team)
			{
				currBone.setData((float*)(entList->at(i)->p_BoneArray + targetBoneID * 0x30));
				pos2 = Vector3(currBone.data[3], currBone.data[7], currBone.data[11]);

				if (sqrt(pow((pos2.x - pos1.x), 2) + pow((pos2.y - pos1.y), 2)) < lowestDist.x || lowestDist.y == -1)
				{
					lowestDist.x = (float)sqrt(pow((pos2.x - pos1.x), 2) + pow((pos2.y - pos1.y), 2));
					lowestDist.y = (float)i;
				}
			}
		}

		if (lowestDist.y != -1)
		{
			currBone.setData((float*)(entList->at((uint32_t)lowestDist.y)->p_BoneArray + targetBoneID * 12));
			pos2 = Vector3(currBone.data[3], currBone.data[7], currBone.data[11]);

			float newYaw = atan((pos2.y - pos1.y) / (pos2.x - pos1.x));
			float newPitch = atan((pos2.z - pos1.z) / lowestDist.x);

			
			newYaw *= (float)(180.0 / PI);
			newPitch *= (float)(-180.0 / PI);

			if (pos2.x > pos1.x)
				newYaw = (float)(180.0 + newYaw);

			newYaw += 180.0;
			if (!isnan(newYaw))
				newYawOut = newYaw;
			else
				newYawOut = 720;

			if (!isnan(newPitch))
				newPitchOut = newPitch;
			else
				newPitchOut = 720;

		}
		else
		{
			newYawOut = 720;
			newPitchOut = 720;
		}
	}
	return true;
}

void Aimbot::drawSettings()
{
	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	if (ImGui::Button("Back"))
		screenManagerGlobal->GUIState = screenManagerGlobal->MAIN;
	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	ImGui::InputInt("TargetBoneID", &targetBoneID);
}