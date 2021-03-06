#include "gamestate.h"
#include "Offsets.h"


GameState::GameState(uintptr_t ClientDllIn)
{	
	ClientDll = ClientDllIn;
	b_IsInGame = (bool*)(ClientDll + b_IsInGameOffset);
	b_IsInGameLast = *b_IsInGame;
}


bool GameState::RoundStateChanged()
{
	if (b_IsInGameLast != *b_IsInGame)
	{
		b_IsInGameLast = *b_IsInGame;
		return true;
	}
	return false;
}