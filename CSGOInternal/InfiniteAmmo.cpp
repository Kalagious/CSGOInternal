#include "InfiniteAmmo.h"

InfiniteAmmo::InfiniteAmmo(uintptr_t heldWeaponPtrIn)
{
	heldWeaponPtr = heldWeaponPtrIn;
	name = "Infinite Ammo";
	serverModule = true;
	enable = false;
}

InfiniteAmmo::InfiniteAmmo()
{
	name = "Infinite Ammo";
	serverModule = true;
	enable = false;
}



bool InfiniteAmmo::tick()
{
	if (enable)
	{
		ServerWeapon* currentWeapon = (ServerWeapon*)*(uintptr_t*)heldWeaponPtr;
		if (currentWeapon != nullptr)
		{
			currentWeapon->currentMag = 69;
			currentWeapon->reserveAmmo = 420;
			return true;
		}
		return false;
	}

}
