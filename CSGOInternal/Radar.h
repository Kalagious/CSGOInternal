#pragma once
#include "module.h"
#include "general.h"
#include "clientplayer.h"

class Radar : public Module
{
public:
	ClientPlayer* clientPlayer;
	Radar(std::vector<ClientPlayer*>* entList);
	bool tick();
	std::vector<ClientPlayer*>* entList;
};