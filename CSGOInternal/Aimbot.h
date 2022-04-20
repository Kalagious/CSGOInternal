#pragma once
#include "Module.h"
#include "AllClasses.h"

class Aimbot : public Module
{
public:
	Aimbot(std::vector<ClientPlayer*>* entList);
	ClientState* clientState;
	ClientPlayer* clientPlayer;
	std::vector<ClientPlayer*>* entList;
	bool tick();
	void drawSettings();

	int32_t targetBoneID;
	float aimbotStrength, newYawOut, newPitchOut;
};

