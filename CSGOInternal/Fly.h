#pragma once
#include "Module.h"
#include "AllClasses.h"

class Fly : public Module
{
public:
	Fly(ServerPlayer* serverPlayerIn, ClientState* clientStateIn);
	ServerPlayer* serverPlayer;
	ClientState* clientState;
	void tick();
	float flyMult, vertMult, xPos, yPos, zPos;
};