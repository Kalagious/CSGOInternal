#include "Fly.h"

// Server-side fly
// !!!HOOK!!! Uses the set vel hook for player objects


Fly::Fly()
{
	name = "Fly";
	serverModule = true;
	flyMult = 10;
	vertMult = 8;
	enable = false;
}


bool Fly::tick()
{
	if (enable)
	{
		if (!clientState)
			return false;
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

		if (GetAsyncKeyState(VK_SPACE))
		{
			zPos = vertMult;
		}
		else if (GetAsyncKeyState(VK_CONTROL))
		{
			zPos = -1 * vertMult;
		}
		else
		{
			zPos = 0;
		}

		if (move)
		{
			yaw = yaw * PI / 180;
			xPos = cos(yaw) * flyMult;
			yPos = sin(yaw) * flyMult;
		}
		else
		{
			xPos = 0;
			yPos = 0;
		}
	}
	return true;
}

void Fly::drawSettings()
{
	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	if (ImGui::Button("Back"))
		screenManagerGlobal->GUIState = screenManagerGlobal->MAIN;
	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	ImGui::Indent();
	ImGui::SliderFloat("Fly Speed Multiplier", &flyMult, 0, 50);
	ImGui::SliderFloat("Vertical Speed Multiplier", &vertMult, 0, 50);

	ImGui::Unindent();
}