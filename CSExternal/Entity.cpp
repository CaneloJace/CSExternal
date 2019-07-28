#include "Entity.h"

DWORD Entity::getEntBase(int index)
{
	return Offsets.val.manager.readMem<DWORD>(Offsets.val.gameModule + Offsets.entityList + (index * 0x10));
}

int	Entity::getEntHp(DWORD playerBase)
{
	return Offsets.val.manager.readMem<int>(playerBase + Offsets.health);
}

bool Entity::isAlive(DWORD playerBase)
{
	if (getEntHp(playerBase) > 0 && getEntHp(playerBase) <= 100)
		return true;
	return false;
}

int	Entity::getEntTeam(DWORD playerBase)
{
	return Offsets.val.manager.readMem<int>(playerBase + Offsets.team);
}

int Entity::getGlowIndex(DWORD playerBase)
{
	return Offsets.val.manager.readMem<int>(playerBase + Offsets.glowIndex);
}

DWORD Entity::getGlowObj()
{
	return Offsets.val.manager.readMem<DWORD>(Offsets.val.gameModule + Offsets.glowObject);
}

bool Entity::isValid(DWORD playerBase)
{
	auto dormant = Offsets.val.manager.readMem<bool>(playerBase + Offsets.bDormant);
	if ((Entity::isAlive(playerBase) && Entity::getEntTeam(playerBase) != 0) && !dormant)
		return true;
	return false;
}

//TODO: MINIMISE WPM CALLS HERE BY USING A GLOW STRUCT 

bool Entity::getSpotted(DWORD playerBase)
{
	return Offsets.val.manager.readMem<bool>(playerBase + Offsets.spotted);
}

D3DXVECTOR3	Entity::getEntPos(DWORD playerBase)
{
	return Offsets.val.manager.readMem<D3DXVECTOR3>(playerBase + Offsets.vecOrigin);
}


char* Entity::getEntName(DWORD playerBase)
{
	return Offsets.val.manager.readMem<char*>(playerBase + Offsets.customName);
}

DWORD Entity::getEntBoneMatrix(DWORD playerBase)
{
	return Offsets.val.manager.readMem<DWORD>(playerBase + Offsets.boneMatrix);
}
D3DXVECTOR3 Entity::getEntEyePos(DWORD playerBase)
{
	return ((Entity::getEntPos(playerBase)) + (Offsets.val.manager.readMem<D3DXVECTOR3>(playerBase + Offsets.vecViewOffset)));
}



bool Entity::getEntScoped(DWORD playerBase)
{
	return Offsets.val.manager.readMem<bool>(playerBase + Offsets.isScoped);
}

bool Entity::getEntDefusing(DWORD playerBase)
{
	return Offsets.val.manager.readMem<bool>(playerBase + Offsets.isDefusing);
}

bool Entity::getEntReloading(DWORD playerBase)
{
	return Offsets.val.manager.readMem<bool>(playerBase + Offsets.isReloading);
}

bool Entity::getEntHelmet(DWORD playerBase)
{
	return Offsets.val.manager.readMem<bool>(playerBase + Offsets.hasHelmet);
}

bool Entity::getEntDefuser(DWORD playerBase)
{
	return Offsets.val.manager.readMem<bool>(playerBase + Offsets.hasDefuser);
}

bool Entity::getEntImmunity(DWORD playerBase)
{
	return Offsets.val.manager.readMem<bool>(playerBase + Offsets.gunGameImmunity);
}

DWORD Entity::getActiveWeapon(DWORD playerBase)
{
	DWORD WeaponIndex = Offsets.val.manager.readMem<DWORD>(playerBase + Offsets.activeWeapon) & 0xFFF;
	return Offsets.val.manager.readMem<DWORD>((Offsets.val.gameModule + Offsets.entityList + WeaponIndex * 0x10) - 0x10);
}

//Uses ClassID
bool Entity::isWeaponNonAim(int classID)
{
	if (classID == CKnife || classID == CKnifeGG || classID == CFlashbang || classID == CHEGrenade || classID == CSmokeGrenade
		|| classID == CMolotovGrenade || classID == CDecoyGrenade || classID == CIncendiaryGrenade || classID == CC4)
		return true;
	return false;
}

//Uses iItemDefinitionIndex
bool Entity::isWeaponNonAim2(int iWeaponID)
{
	if (iWeaponID == weapon_knife || iWeaponID == weapon_knifegg || iWeaponID == weapon_flashbang || iWeaponID == weapon_hegrenade || iWeaponID == weapon_smokegrenade
		|| iWeaponID == weapon_molotov || iWeaponID == weapon_decoy || iWeaponID == weapon_c4 || iWeaponID == weapon_incgrenade)
		return true;
	return false;
}

//Uses ClassID
bool Entity::isWeaponPistol(int classID)
{
	if (classID == CDEagle || classID == CWeaponElite || classID == CWeaponFiveSeven || classID == CWeaponGlock
		|| classID == CWeaponP228 || classID == CWeaponUSP || classID == CWeaponTec9 || classID == CWeaponTaser || classID == CWeaponHKP2000 || classID == CWeaponP250)
		return true;

	return false;
}

//Uses ClassID
bool Entity::isWeaponSniper(int classID)
{
	if (classID == CWeaponAWP || classID == CWeaponSSG08 || classID == CWeaponG3SG1 || classID == CWeaponSCAR20)
		return true;

	return false;
}

int	Entity::getEntClassID(DWORD entity)
{
	int one = Offsets.val.manager.readMem<int>(entity + 0x8);
	int two = Offsets.val.manager.readMem<int>(one + 2 * 0x4);
	int three = Offsets.val.manager.readMem<int>(two + 0x1);
	return Offsets.val.manager.readMem<int>(three + 0x14);
}

D3DXVECTOR3	Entity::getEntBonePos(DWORD playerBase, int boneID)
{
	Matrix3x4_t boneMatrix = Offsets.val.manager.readMem<Matrix3x4_t>(Entity::getEntBoneMatrix(playerBase) + boneID * 0x30);

	return{
		boneMatrix.Matrix[0][3],
		boneMatrix.Matrix[1][3],
		boneMatrix.Matrix[2][3]
	};
}

int Entity::getEntAmmo(DWORD playerBase)
{
	auto weapon = Entity::getActiveWeapon(playerBase);
	return Offsets.val.manager.readMem<int>(weapon + Offsets.clip);
}