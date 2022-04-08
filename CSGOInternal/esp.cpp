#include "esp.h"
#include "entlist.h"

ESP::ESP(std::vector<ClientPlayer*>* entList)
{
	this->entList;
	name = "ESP";
	serverModule = false;
	enable = false;
}

bool ESP::tick()
{
	if (enable)
	{
		for (uint32_t i = 0; i < entList->size(); i++)
		{
			if (IsValidEnt(entList->at(i)))
			{

			}
		}
	}
	return true;
}
