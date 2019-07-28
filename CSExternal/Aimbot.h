#pragma once

#include "Offsets.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "Entity.h"
#include "LocalPlayer.h"
#include <intrin.h>
#include <math.h>
#include "W2S.h"

class CAimbot
{
public:
	void run();
	DWORD findPlayer();
};

extern CAimbot Aimbot;