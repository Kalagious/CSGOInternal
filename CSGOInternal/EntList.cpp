#include "EntList.h"
#include "Cheats.h"


extern Cheats* cheatsGlobal;


EntList::EntList(BYTE* startAddress)
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
		if (nodeItr->entity)
			cheatsGlobal->clientEntList.push_back(nodeItr->entity);
		nodeItr = nodeItr->nextNode;
	}
	return true;
}

