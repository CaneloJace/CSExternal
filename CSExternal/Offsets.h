#pragma once

#include "MemMan.h"

class COffsets
{
public:
	DWORD localPlayer = 0xCF3A4C;
	DWORD fJump = 0x51A91AC;
	DWORD flags = 0x104;
	DWORD forceAttack = 0x31371BC;
	DWORD entityList = 0x4D05AF4;
	DWORD crosshair = 0xB3AC;
	DWORD team = 0xF4;
	DWORD health = 0x100;
	DWORD glowObject = 0x5245F08;
	DWORD glowIndex = 0xA40C;
	DWORD flashDuration = 0xA3F4;
	DWORD bDormant = 0xED;
	DWORD clip = 0x3244;
	DWORD spotted = 0x93D;
	DWORD vecOrigin = 0x138;
	DWORD customName = 0x303C;
	DWORD boneMatrix = 0x26A8;
	DWORD vecViewOffset = 0x108;
	DWORD isScoped = 0x3910;
	DWORD isDefusing = 0x3918;
	DWORD isReloading = 0x3285;
	DWORD hasHelmet = 0xB334;
	DWORD hasDefuser = 0xB350;
	DWORD gunGameImmunity = 0x392C;
	DWORD activeWeapon = 0x2EF8;
	DWORD viewMatrix = 0x4CF7524;
	DWORD punchAngles = 0x302C;
	DWORD clientViewAngles = 0x4D88;
	DWORD clientState = 0x58ECFC;

	struct values
	{
		DWORD localPlayer;
		DWORD process;
		DWORD gameModule;
		DWORD clientState;
		DWORD engineAddress;
		BYTE flag;
		MemMan manager;
	}val;

};

extern COffsets Offsets;
