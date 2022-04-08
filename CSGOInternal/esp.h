#pragma once
#include "Module.h"
#include "General.h"
#include "ClientPlayer.h"

class ESP : public Module
{
public:
	ESP(std::vector<ClientPlayer*>* entList);
	bool tick();
	std::vector<ClientPlayer*>* entList;
};