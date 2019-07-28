#pragma once

#include "Offsets.h"
#include "Entity.h"
#include "LocalPlayer.h"
#include <iostream>

class CTrigger
{
public:
	void shoot();
	void run();
	bool checkTBot();
};

extern CTrigger Trigger;