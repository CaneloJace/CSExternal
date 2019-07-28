#define _USE_MATH_DEFINES

#include "Aimbot.h"

CAimbot Aimbot;

D3DXVECTOR3 CalcAngle(register const D3DXVECTOR3& src, register const D3DXVECTOR3& dst)
{
	//square root func faster than normal func youd use
	const auto sqrtss = [](float in) {
		__m128 reg = _mm_load_ss(&in);
		return _mm_mul_ss(reg, _mm_rsqrt_ss(reg)).m128_f32[0];
	};


	D3DXVECTOR3 angles;

	//getting delta between source and destination vectors
	D3DXVECTOR3 delta = src - dst;

	//finding the hypoteneuse using pythagoras theorem a squared + b squared = c squared
	//this gives us the vector to our enemy
	float hyp = sqrtss(delta.x * delta.x + delta.y * delta.y);

	//now we need to find the angle needed to aim at the vector (aim angles)
	angles.x = asinf(delta.z / hyp)		* (180.0f / M_PI);
	angles.y = atanf(delta.y / delta.x)	* (180.0f / M_PI) + !((*(DWORD*)&delta.x) >> 31 & 1) * 180.0f;

	//!((*(DWORD*)&delta.x) >> 31 & 1) * 180.0f; is basically the if statement bellow - it removes code branching for better performance
	//if (delta.x >= 0.0)
	//	angles.y += 180.0;

	angles.z = 0.0f;

	return angles;
}

void CAimbot::run()
{
	DWORD plrToAim = CAimbot::findPlayer();

	if (plrToAim != NULL)
	{
		if (Entity::getSpotted(plrToAim) == 1)
		{
			D3DXVECTOR3 aimAngles = CalcAngle(LocalPlayer.getLocalPos(), Entity::getEntPos(plrToAim));

			aimAngles -= LocalPlayer.getLocalPunchAngles() * 2.0;

			//LocalPlayer.setLocalViewAngles(aimAngles);
		}
	}
}

DWORD CAimbot::findPlayer()
{
	D3DXVECTOR3 w2sHead;

	DWORD plrToAim = NULL;
	double lowestDist = 9999;

	for (int i = 1; i < 32; i++)
	{
		auto base = Entity::getEntBase(i);

		if (Entity::getEntTeam(base) != LocalPlayer.getLocalTeam() && Entity::isValid(base) && !Entity::getEntImmunity(base))
		{
			WorldToScreen(Entity::getEntBonePos(base, 8), w2sHead, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));

			double dist = sqrt(pow((GetSystemMetrics(SM_CXSCREEN) / 2) - w2sHead.x, 2) + pow((GetSystemMetrics(SM_CYSCREEN) / 2) - w2sHead.y, 2));

			if (dist < lowestDist)
			{
				lowestDist = dist;
				plrToAim = base;
			}
		}
	}

	return plrToAim;
}