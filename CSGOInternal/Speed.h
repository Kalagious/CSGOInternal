#pragma once
#include "Module.h"
#include "AllClasses.h"

class Speed : public Module
{
public:
	Speed(ServerPlayer* serverPlayerIn, ClientState* clientStateIn);
	ServerPlayer* serverPlayer;
	ClientState* clientState;
	void tick();
	float speedMult, xVel, yVel;
};