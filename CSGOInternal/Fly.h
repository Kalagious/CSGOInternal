#pragma once
#include "Module.h"
#include "AllClasses.h"

class Fly : public Module
{
public:
	Fly();
	ServerPlayer* serverPlayer;
	ClientState* clientState;
	bool tick();
	float flyMult, vertMult, xPos, yPos, zPos;
};