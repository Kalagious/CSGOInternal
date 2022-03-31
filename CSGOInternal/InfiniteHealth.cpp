#include "InfiniteHealth.h"

InfiniteHealth::InfiniteHealth(ServerPlayer* playerIn)
{
	player = playerIn;
	name = "Infinite Health";
	serverModule = true;
	enable = false;
}

void InfiniteHealth::tick()
{
	if (enable)
		player->health = 1337;
}
