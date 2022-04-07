#pragma once
#include "hooks.h"


class EndSceneHook : public Hook
{
public:

	bool initialize();
	EndSceneHook(uintptr_t endSceneAddr);
	typedef HRESULT(APIENTRY* tTargetPtr)(LPDIRECT3DDEVICE9 device);
	static tTargetPtr oFunction;
	static void APIENTRY hookFunction(LPDIRECT3DDEVICE9 device);
};

