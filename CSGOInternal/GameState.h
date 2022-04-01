#pragma once
#include "General.h"

class GameState
{
public:
	GameState(BYTE* ClientDllIn);
	bool RoundStateChanged();
	BYTE* ClientDll;
	bool b_IsInGameLast;
	bool* b_IsInGame;
};