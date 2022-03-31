#include "InfiniteAmmo.h"

InfiniteAmmo::InfiniteAmmo(uintptr_t heldWeaponPtrIn)
{
	heldWeaponPtr = heldWeaponPtrIn;
	name = "Infinite Ammo";
	serverModule = true;
	enable = false;
}

void InfiniteAmmo::tick()
{
	if (enable)
	{
		ServerWeapon* currentWeapon = (ServerWeapon*)*(uintptr_t*)heldWeaponPtr;
		currentWeapon->currentMag = 69;
		currentWeapon->reserveAmmo = 420;
	}

}
