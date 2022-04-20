#include "InfiniteHealth.h"


InfiniteHealth::InfiniteHealth()
{
	name = "Infinite Health";
	serverModule = true;
	enable = true;
}

bool InfiniteHealth::tick()
{
	if (enable)
	{
		if (!serverPlayer)
			return false;
		serverPlayer->health = 1337;
	}
	return true;
}
