#include "Trigger.h"

CTrigger Trigger;

void CTrigger::shoot()
{
	std::cout << "I GOT HERE!!!" << std::endl;
	Offsets.val.manager.writeMem<int>(Offsets.val.gameModule + Offsets.forceAttack, 5);
	Sleep(5);
	Offsets.val.manager.writeMem<int>(Offsets.val.gameModule + Offsets.forceAttack, 4);
}

bool CTrigger::checkTBot()
{
	int crosshair = LocalPlayer.getLocalCrossID();
	if (crosshair != 0 && crosshair < 64)
	{
		DWORD entity = Offsets.val.manager.readMem<DWORD>(Offsets.val.gameModule + Offsets.entityList + (crosshair - 1) * 0x10);
		int eTeam = Offsets.val.manager.readMem<int>(entity + Offsets.team);
		int eHealth = Offsets.val.manager.readMem<int>(entity + Offsets.health);
		if (eTeam != LocalPlayer.getLocalTeam() && eHealth > 0)
			return true;
	}
	return false;

}

void CTrigger::run()
{
	if (checkTBot())
		shoot();
}