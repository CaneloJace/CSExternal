#include "include.h"
#include "MemMan.h"
#include "ColorManager.h"

void redraw()
{
	system("CLS");
	std::cout << green << "F1: Bunnyhop - " << (Settings.BHop.enabled ? "enabled\n" : "disabled\n");
	std::cout << green << "F2: Glow - " << (Settings.Visuals.Glow.enabled ? "enabled\n" : "disabled\n");
	std::cout << green << "F3: Triggerbot - " << (Settings.Aim.Trigger.enabled ? "enabled\n" : "disabled\n");
	std::cout << green << "F4: Auto Pistol - " << (Settings.Aim.AutoPistol.enabled ? "enabled\n" : "disabled\n");
	std::cout << green << "F8: Aimbot - " << (Settings.Aim.Aimbot.enabled ? "enabled\n" : "disabled\n");
	std::cout << green << "F9: NoFlash - " << (Settings.Misc.NoFlash.enabled ? "enabled\n" : "disabled\n");
}

int main()
{

	Offsets.val.process = Offsets.val.manager.getProcess("csgo.exe");
	Offsets.val.gameModule = Offsets.val.manager.getModule(Offsets.val.process, "client_panorama.dll");

	std::cout << std::hex << Offsets.val.gameModule << std::endl;

	LocalPlayer.setLocalPlayer();

	//Offsets.val.engineAddress = Offsets.val.manager.getModule(Offsets.val.process, "engine.dll");
	//Offsets.val.clientState = Offsets.val.manager.readMem<DWORD>(Offsets.val.engineAddress + Offsets.clientState);

	while (LocalPlayer.getLocalTeam() == 0)
	{
		LocalPlayer.setLocalPlayer();
	}

	redraw();

	while (true)
	{
		DWORD glowObject = Offsets.val.manager.readMem<DWORD>(Offsets.val.gameModule + Offsets.glowObject);

		// Bunny Hop
		if (GetAsyncKeyState(VK_F1) & 1)
		{
			Settings.BHop.enabled = !Settings.BHop.enabled;
			redraw();
		}
		// Glow 
		if (GetAsyncKeyState(VK_F2) & 1)
		{	
			Settings.Visuals.Glow.enabled = !Settings.Visuals.Glow.enabled;
			redraw();

		}
		// TriggerBot
		if (GetAsyncKeyState(VK_F3) & 1)
		{

			Settings.Aim.Trigger.enabled = !Settings.Aim.Trigger.enabled;
			redraw();
		}

		if (GetAsyncKeyState(VK_F4) & 1)
		{
			Settings.Aim.AutoPistol.enabled = !Settings.Aim.AutoPistol.enabled;
			redraw();
		}

		if (GetAsyncKeyState(VK_F8) & 1)
		{
			Settings.Aim.Aimbot.enabled = !Settings.Aim.Aimbot.enabled;
			redraw();
		}

		if (GetAsyncKeyState(VK_F9) & 1)
		{
			Settings.Misc.NoFlash.enabled = !Settings.Misc.NoFlash.enabled;
			redraw();
		}

		if (Settings.BHop.enabled && LocalPlayer.getLocalFlags() & (1 << 0))
			if (GetAsyncKeyState(VK_SPACE))
					BHop.run();

		// Auto Pistol

		if (Settings.Aim.AutoPistol.enabled && GetAsyncKeyState(VK_LBUTTON))
			Trigger.shoot();

		if (Settings.Aim.Aimbot.enabled && GetAsyncKeyState(VK_LBUTTON))
		{
			Aimbot.run();
		}

		if (Settings.Visuals.Glow.enabled)
		{
			for (short int i = 0; i < 64; i++)
			{
				Glow.run(glowObject, i);
			}
		}

		if (Settings.Aim.Trigger.enabled && GetAsyncKeyState(VK_MENU))
			Trigger.run();

		if (Settings.Misc.NoFlash.enabled)
			NoFlash.run();

		Sleep(1);
	}

	return 0;
}

