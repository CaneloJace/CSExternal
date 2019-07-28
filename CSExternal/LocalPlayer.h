#pragma once

#include "Offsets.h"
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>

class CLocalPlayer
{
public:
	void setLocalPlayer();
	DWORD getLocalPlayer();
	BYTE getLocalFlags();
	int getLocalTeam();
	void forceLocalJump();
	int getLocalCrossID();
	D3DXMATRIX getLocalViewMatrix();
	D3DXVECTOR3 getLocalPos();
	D3DXVECTOR3 getLocalPunchAngles();
	void setLocalViewAngles(D3DXVECTOR3 angles);
	DWORD LocalPlayerBase;
};

extern CLocalPlayer LocalPlayer;