#include "LocalPlayer.h"

CLocalPlayer LocalPlayer;

void CLocalPlayer::setLocalPlayer()
{
	CLocalPlayer::LocalPlayerBase = Offsets.val.manager.readMem<DWORD>(Offsets.val.gameModule + Offsets.localPlayer);
}

DWORD CLocalPlayer::getLocalPlayer()
{
	return CLocalPlayer::LocalPlayerBase;
}

BYTE CLocalPlayer::getLocalFlags()
{
	return Offsets.val.manager.readMem<BYTE>(CLocalPlayer::getLocalPlayer() + Offsets.flags);
}

int CLocalPlayer::getLocalTeam()
{
	return Offsets.val.manager.readMem<int>(CLocalPlayer::getLocalPlayer() + Offsets.team);
}

void CLocalPlayer::forceLocalJump()
{
	Offsets.val.manager.writeMem<DWORD>(Offsets.val.gameModule + Offsets.fJump, 6);
}

int CLocalPlayer::getLocalCrossID()
{
	return Offsets.val.manager.readMem<int>(CLocalPlayer::getLocalPlayer() + Offsets.crosshair);
}

D3DXMATRIX CLocalPlayer::getLocalViewMatrix()
{
	return Offsets.val.manager.readMem<D3DXMATRIX>(CLocalPlayer::getLocalPlayer() + Offsets.viewMatrix);
}

D3DXVECTOR3 CLocalPlayer::getLocalPos()
{
	return Offsets.val.manager.readMem<D3DXVECTOR3>(CLocalPlayer::getLocalPlayer() + Offsets.vecOrigin);
}

D3DXVECTOR3 CLocalPlayer::getLocalPunchAngles()
{
	return Offsets.val.manager.readMem<D3DXVECTOR3>(CLocalPlayer::getLocalPlayer() + Offsets.punchAngles);
}

void CLocalPlayer::setLocalViewAngles(D3DXVECTOR3 angles)
{
	Offsets.val.manager.writeMem<D3DXVECTOR3>(Offsets.val.clientState + Offsets.clientViewAngles, angles);
}
