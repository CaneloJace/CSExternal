#pragma once

#include "Offsets.h"
#include "Entity.h"
#include "LocalPlayer.h"

class CGlow
{
public:
	void run(DWORD glowObject, int i);
};

extern CGlow Glow;