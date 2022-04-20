#pragma once
#include "Module.h"
#include "General.h"
#include "ClientPlayer.h"

class Tracers : public Module
{
public:
	Tracers(std::vector<ClientPlayer*>* entList);
	Vector2 screenDimensions;

	bool tick();
	void drawSettings();
	void drawTracer(ClientPlayer* ent, float thickness, D3DCOLOR color, bool isTeam);

	bool showEnemyTracer;
	bool showEnemyTracerOnScreen;
	bool showEnemyTracerOffScreen;
	float enemyThickness;
	float enemyColor[4];

	bool showTeamTracer;
	bool showTeamTracerOnScreen;
	bool showTeamTracerOffScreen;
	float teamThickness;
	float teamColor[4];

	ClientPlayer* clientPlayer;
	std::vector<ClientPlayer*>* entList;
};