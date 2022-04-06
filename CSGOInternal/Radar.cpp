#include "Radar.h"

Radar::Radar(std::vector<ClientPlayer*>* entList)
{
	this->entList;
	name = "Radar";
	serverModule = false;
	enable = false;
}

bool Radar::tick()
{
	if (enable)
	{
		for (int i = 0; i < entList->size(); i++)
		{
			if (!entList->at(i)->b_Dormant)
				entList->at(i)->b_IsSpotted = true;
		}
	}
	return true;
}
