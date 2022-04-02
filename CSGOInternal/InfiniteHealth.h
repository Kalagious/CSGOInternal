#pragma once
#include "Module.h"
#include "ServerPlayer.h"

class InfiniteHealth : public Module
{
public:
	InfiniteHealth(ServerPlayer* playerIn);
	InfiniteHealth();
	ServerPlayer* player;
	void tick();
};