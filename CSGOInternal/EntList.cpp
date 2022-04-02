#include "EntList.h"
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
	while (nodeItr)
	{
		if (nodeItr->entity && *(uintptr_t*)(nodeItr->entity) == cheatsGlobal->C_CSPlayerPtr)
		{
			cheatsGlobal->clientEntList.push_back(nodeItr->entity);
			printf("%#8X - %#8X\n", nodeItr-> entity, *(nodeItr->entity));
		}
		nodeItr = nodeItr->nextNode;
	}
	return true;
}

