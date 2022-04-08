#pragma once
#include "Module.h"
#include "AllClasses.h"

class Speed : public Module
{
public:
	Speed();
	ServerPlayer* serverPlayer;
	ClientState* clientState;
	bool tick();
	int speedMult;
	float xVel, yVel;
	void drawSettings();
};