#include "Aimbot.h"

// !!!HOOK!!!! Uses a hook on the client view angle function

Aimbot::Aimbot(std::vector<ClientPlayer*>* entList)
{
	this->entList = entList;
	name = "Aimbot";
	serverModule = false;
	enable = false;
}


bool Aimbot::tick()
{
	if (enable)
	{
		if (!clientPlayer || !entList)
			return false;
		Vector3 pos1 = clientPlayer->v_Position1;

		Vector3 lowestDist(0, -1, 0);
		
		for (uint32_t i = 0; i < entList->size(); i++)
		{
			
			if (entList->at(i)->i_Health > 0 && entList->at(i) != clientPlayer && !entList->at(i)->b_Dormant)
			{
				if (lowestDist.y == -1)
				{
					lowestDist.x = sqrt(pow((pos1.x - entList->at(i)->v_Position1.x), 2) + pow((pos1.y - entList->at(i)->v_Position1.y), 2));
					lowestDist.y = i;
				}
				if (sqrt(pow((pos1.x - entList->at(i)->v_Position1.x), 2) + pow((pos1.y - entList->at(i)->v_Position1.y), 2)) < lowestDist.x)
				{
					lowestDist.x = sqrt(pow((pos1.x - entList->at(i)->v_Position1.x), 2) + pow((pos1.y - entList->at(i)->v_Position1.y), 2));
					lowestDist.y = i;
				}
			}
		}

		if (lowestDist.y != -1)
		{
			Vector3 pos2 = entList->at(lowestDist.y)->v_Position1;

			pos2.z += entList->at(lowestDist.y)->f_PlayerHeight - clientPlayer->f_PlayerHeight;

			float newYaw = atan((pos2.y - pos1.y) / (pos2.x - pos1.x));
			float newPitch = atan((pos2.z - pos1.z) / lowestDist.x);

			
			newYaw *= 180.0 / PI;
			newPitch *= -180.0 / PI;

			if (pos2.x > pos1.x)
				newYaw = 180.0 + newYaw;

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
