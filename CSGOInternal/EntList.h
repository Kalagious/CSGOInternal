#pragma once
#include "AllClasses.h"


class EntListNode 
{
public:
	ClientPlayer* entity;
	uint32_t pd;
	EntListNode* lastNode;
	EntListNode* nextNode;
};


class EntList
{
public:
	EntList(uintptr_t startAddress);
	bool load();
	EntListNode* startNode;
};