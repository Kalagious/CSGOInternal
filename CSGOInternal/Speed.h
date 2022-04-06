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
	float speedMult, xVel, yVel;
};