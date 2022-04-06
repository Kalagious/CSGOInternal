#pragma once
#include "Module.h"
#include "General.h"
#include "ClientPlayer.h"

class Radar : public Module
{
public:
	Radar(std::vector<ClientPlayer*>* entList);
	bool tick();
	std::vector<ClientPlayer*>* entList;
};