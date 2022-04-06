#pragma once
#include "Module.h"
#include "ServerPlayer.h"

class InfiniteHealth : public Module
{
public:
	InfiniteHealth();
	ServerPlayer* serverPlayer;
	bool tick();
};