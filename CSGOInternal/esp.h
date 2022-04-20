#pragma once
#include "Module.h"
#include "General.h"
#include "ClientPlayer.h"

class ESP : public Module
{
public:
	ESP(std::vector<ClientPlayer*>* entList);
	Vector2 screenDimensions;

	bool tick();
	void drawSettings();
	void drawBoneIDs(ClientPlayer* ent, D3DCOLOR color);
	void drawBone(ClientPlayer* ent, std::vector<int> BoneIDs, D3DCOLOR color);
	void drawBonePoints(ClientPlayer* ent, D3DCOLOR color);
	void drawTSkeleton(ClientPlayer* ent, D3DCOLOR color);
	void drawBox(ClientPlayer* ent, D3DCOLOR color);
	bool initialize();
	bool initialized;
	int32_t nameFontSize; 

	float boxWidthScale;
	float boxHeightScale;

	bool showEnemyBox;
	bool showEnemyBones;
	bool showEnemyName;
	bool showEnemyHealth;
	bool showEnemyArmor;
	bool showEnemyWeapon;
	float enemyColor[4];
	bool showTeamBox;
	bool showTeamBones;
	bool showTeamName;
	bool showTeamHealth;
	bool showTeamArmor;
	bool showTeamWeapon;
	float teamColor[4];

	ClientPlayer* clientPlayer;
	std::vector<ClientPlayer*>* entList;
};