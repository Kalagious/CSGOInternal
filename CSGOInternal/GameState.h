#pragma once
#include "General.h"

class GameState
{
public:
	GameState(uintptr_t ClientDllIn);
	bool RoundStateChanged();
	uintptr_t ClientDll;
	bool b_IsInGameLast;
	bool* b_IsInGame;
};