#pragma once

class CSettings
{
public:
	struct
	{
		struct
		{
			bool enabled = false;
		}Glow;
	}Visuals;
	struct
	{
		struct
		{
			bool enabled = false;
		}Aimbot;

		struct
		{
			bool enabled = false;
		}Trigger;

		struct
		{
			bool enabled = false;
		}AutoPistol;
	}Aim;
	struct
	{
		bool enabled = false;
	}BHop;

	struct
	{
		struct
		{
			bool enabled = false;
		}NoFlash;
	}Misc;

};

extern CSettings Settings;
