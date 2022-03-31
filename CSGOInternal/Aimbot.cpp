#include "Aimbot.h"

// Server-side aimbot relies on server entity list
// !!!HOOK!!!! Uses a hook on the client view angle function

Aimbot::Aimbot(ClientPlayer* clientPlayerIn, ClientState* clientStateIn, std::vector<ClientPlayer*>* clientEntListIn)
{
	clientPlayer = clientPlayerIn;
	clientState = clientStateIn;
	clientEntList = clientEntListIn;
	name = "Aimbot";
	serverModule = true;
	enable = false;
}

void Aimbot::tick()
{
	if (enable)
	{
		// REPLACE ALL PLAYER REFERENCES, LOCAL PLAYER IS NOT INCLUDED IN CLIENT ENT LIST
		Vector3 pos1 = clientPlayer->v_Position1;

		Vector3 lowestDist(0, -1, 0);

		for (int i = 1; i < clientEntList->size(); i++)
		{
			Vector3 pos2 = clientEntList->at(i)->v_Position1;
			if (clientEntList->at(i)->i_Health > 0)
			{
				if (lowestDist.y == -1)
				{
					lowestDist.x = sqrt(pow((pos1.x - pos2.x), 2) + pow((pos1.y - pos2.y), 2));
					lowestDist.y = i;
				}
				if (sqrt(pow((pos1.x - pos2.x), 2) + pow((pos1.y - pos2.y), 2)) < lowestDist.x)
				{
					lowestDist.x = sqrt(pow((pos1.x - pos2.x), 2) + pow((pos1.y - pos2.y), 2));
					lowestDist.y = i;
				}
			}
		}

		if (lowestDist.y != -1)
		{
			Vector3 pos2 = clientEntList->at(lowestDist.y)->v_Position1;

			float newYaw = atan((pos2.y - pos1.y) / (pos2.x - pos1.x));
			float newPitch = atan((pos2.z - pos1.z) / lowestDist.x);

			newYaw *= 180 / PI;
			newPitch *= -180 / PI;

			if (pos2.x > pos1.x)
				newYaw = 180 + newYaw;

			newYaw += 180;
			if (!isnan(newYaw))
				newYawOut = newYaw;
			if (!isnan(newPitch))
				newPitchOut = newPitch;
		}
	}
}
