#include "entlist.h"
#include "Cheats.h"


extern Cheats* cheatsGlobal;


EntList::EntList(uintptr_t startAddress)
{
	startNode = (EntListNode*)(startAddress + 4);
}


bool EntList::load()
{
	if (startNode == nullptr)
		return false;
	EntListNode* nodeItr = startNode;
	cheatsGlobal->clientEntList.clear();
	printf(" [*] Loading Entity List:\n");
	while (nodeItr)
	{
		if (nodeItr->entity && *(uintptr_t*)(nodeItr->entity) == cheatsGlobal->C_CSPlayerPtr)
		{
			cheatsGlobal->clientEntList.push_back(nodeItr->entity);
			printf("	Entity %d: (%#8X)\n", cheatsGlobal->clientEntList.size(), (uintptr_t)nodeItr->entity);
		}
		nodeItr = nodeItr->nextNode;
	}
	return true;
}

bool IsValidEnt(ClientPlayer* player)
{
	if (!player)
		return false;
	if (player->b_Dormant)
		return false;
	if (player->i_Health < 0)
		return false;
	return true;
}