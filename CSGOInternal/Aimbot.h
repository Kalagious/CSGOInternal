#pragma once
#include "Module.h"
#include "AllClasses.h"

class Aimbot : public Module
{
public:
	Aimbot(ClientPlayer* clientPlayerIn, ClientState* clientStateIn, std::vector<ClientPlayer*>* clientEntListIn);
	Aimbot();
	ClientState* clientState;
	ClientPlayer* clientPlayer;
	std::vector<ClientPlayer*>* clientEntList;
	void tick();
	float aimbotStrength, newYawOut, newPitchOut;
};

