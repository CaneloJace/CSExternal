#include "NoFlash.h"

CNoFlash NoFlash;

void CNoFlash::run()
{
	Offsets.val.manager.writeMem(LocalPlayer.getLocalPlayer() + Offsets.flashDuration, 0);
}