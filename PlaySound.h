#pragma once
#include "HookIncludes.h"

void __stdcall hkPlaySound(const char* szFileName)
{
	//Call original PlaySound
    hooks::original_play_sound(Interfaces::Surface(), szFileName);
	if (g_Options.Misc.AutoAccept)
	{
		if (Interfaces::Engine()->IsInGame()) return;

		if (strstr(szFileName, "UI/competitive_accept_beep.wav"))
			//"UI/competitive_accept_beep.wav"	
		{

			static auto CServerConfirmedReservationCheckCallback__IsReady
				= (void(__cdecl*)(void))CSX::Memory::NewPatternScan(
					GetModuleHandleW(L"client_panorama.dll"),
				    "55 8B EC 83 E4 F8 8B 4D 08 BA ? ? ? ? E8 ? ? ? ? 85 C0 75 12"
					

				);
			CServerConfirmedReservationCheckCallback__IsReady();
		}
	}

}
