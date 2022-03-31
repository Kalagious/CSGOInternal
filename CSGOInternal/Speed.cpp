#include "Speed.h"

// Server-side speed
// !!!HOOK!!! Uses the set vel hook for player objects
Speed::Speed(ServerPlayer* serverPlayerIn, ClientState* clientStateIn)
{
	serverPlayer = serverPlayerIn;
	clientState = clientStateIn;

	name = "Speed";
	serverModule = true;
	speedMult = 800;
	enable = false;
}

void Speed::tick()
{
	if (enable)
	{
		bool move = false;
		float yaw = clientState->yaw;
		if (GetAsyncKeyState(0x57))
		{
			if (GetAsyncKeyState(0x41))
			{
				yaw += 45;
			}
			 else if (GetAsyncKeyState(0x44))
			{
				yaw -= 45;
			}
			move = true;
		}
		else if (GetAsyncKeyState(0x53))
		{
			yaw += 180;
			if (GetAsyncKeyState(0x41))
			{
				yaw -= 45;
			}
			else if (GetAsyncKeyState(0x44))
			{
				yaw += 45;
			}
			move = true;
		}
		else if (GetAsyncKeyState(0x41))
		{
			yaw += 90;
			move = true;
		}
		else if (GetAsyncKeyState(0x44))
		{
			yaw -= 90;
			move = true;
		}

		if (move)
		{
			yaw = yaw * PI / 180;
			xVel = cos(yaw) * speedMult;
			yVel = sin(yaw) * speedMult;
			serverPlayer->velocity2.x = 0;
			serverPlayer->velocity2.y = 0;
		}
		else
		{
			xVel = 0;
			yVel = 0;
		}
	}
}