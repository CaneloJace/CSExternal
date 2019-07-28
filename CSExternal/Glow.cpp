#include "Glow.h"

CGlow Glow;

void CGlow::run(DWORD glowObject, int i)
{
	DWORD entity = Offsets.val.manager.readMem<DWORD>(Offsets.val.gameModule + Offsets.entityList + i * 0x10);
	if (entity != NULL)
	{
		int glowIndx = Offsets.val.manager.readMem<int>(entity + Offsets.glowIndex);
		int entityTeam = Offsets.val.manager.readMem<int>(entity + Offsets.team);

		if (LocalPlayer.getLocalTeam() == entityTeam)
		{
			Offsets.val.manager.writeMem<float>(glowObject + ((glowIndx * 0x38) + 0x4), 0);
			Offsets.val.manager.writeMem<float>(glowObject + ((glowIndx * 0x38) + 0x8), 0);
			Offsets.val.manager.writeMem<float>(glowObject + ((glowIndx * 0x38) + 0xC), 2);
			Offsets.val.manager.writeMem<float>(glowObject + ((glowIndx * 0x38) + 0x10), 1);
		}
		else
		{
			Offsets.val.manager.writeMem<float>(glowObject + ((glowIndx * 0x38) + 0x4), 2);
			Offsets.val.manager.writeMem<float>(glowObject + ((glowIndx * 0x38) + 0x8), 0);
			Offsets.val.manager.writeMem<float>(glowObject + ((glowIndx * 0x38) + 0xC), 0);
			Offsets.val.manager.writeMem<float>(glowObject + ((glowIndx * 0x38) + 0x10), 1);
		}
		Offsets.val.manager.writeMem<bool>(glowObject + ((glowIndx * 0x38) + 0x24), true);
		Offsets.val.manager.writeMem<bool>(glowObject + ((glowIndx * 0x38) + 0x25), false);
	}
}