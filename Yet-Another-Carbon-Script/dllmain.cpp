// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "injector/injector.hpp"
#include <iostream>

// Stuff for HUD
#include "DALVehicle_Carbon.h"
float GetRpmValue = 0;
float MaxRPM = 10000.0;
float RedLine = 8000.0;
float GetTurboValue = 0;
float SpeedMpsValue = 0;
float NosValue = 0;
float SpeedBreakerValue = 0;
int GearValue = 0;
int CarIDHash = 0;
int OldCarIDHash = 0;
const char* GearChar;


DEVMODE devmode;
HWND hWnd;
HCURSOR hCursor;

int ScreenX = GetSystemMetrics(SM_CXSCREEN);	//Get screen width from desktop resolution
int ScreenY = GetSystemMetrics(SM_CYSCREEN);	//Get screen height from desktop resolution

void *DALVehiclePointer;
unsigned int *gTheDALManager;

static bool ReturnFalse()
{
	return 0;
}

static bool ReturnTrue()
{
	return 1;
}

/* DWORD WINAPI MainThread()
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	// HUD stuff by xan1242 (temporary thing until I hook ImGui)
	if (*(int*)0xA99BBC == 3)
	{
		gTheDALManager = *(unsigned int**)0x00A8AD30;
		DALVehiclePointer = (void*)gTheDALManager[4];
	}

	if (*(int*)0xA99BBC == 5)
	{
		OldCarIDHash = CarIDHash;									// Monitor if car has changed to update the MaxRPM and the redline.
		DALVehicle_GetCarIDHash(DALVehiclePointer, &CarIDHash, 0);

		if (OldCarIDHash != CarIDHash)
		{
			DALVehicle_GetMaxRPM(DALVehiclePointer, &MaxRPM, 0);
			DALVehicle_GetRedLine(DALVehiclePointer, &RedLine, 0);
			std::cout << "Max RPM: " << MaxRPM << std::endl;
		}

		DALVehicle_GetSpeedBreaker(DALVehiclePointer, &SpeedBreakerValue, 0);
		DALVehicle_GetNos(DALVehiclePointer, &NosValue, 0);
		DALVehicle_GetSpeedMps(DALVehiclePointer, &SpeedMpsValue, 0);
		DALVehicle_GetTurbo(DALVehiclePointer, &GetTurboValue, 0);
		DALVehicle_GetRPM(DALVehiclePointer, &GetRpmValue, 0);
		DALVehicle_GetGear(DALVehiclePointer, &GearValue, 0);

		if (GearValue == 1)
		{
			GearChar = "N";
			std::cout << "Gear: " << GearChar << std::endl;
		}

		if (GearValue >= 0)
		{
			GearChar = "R";
			std::cout << "Gear: " << GearChar << std::endl;
		}
		else
		{
			std::cout << "Gear: " << GearValue - 1 << std::endl;
		}

		std::cout << "Redline: " << RedLine << std::endl;
		std::cout << "NOS: " << NosValue << std::endl;
		std::cout << "Speed: " << SpeedMpsValue * 3.6 << " km/h" << std::endl;
		std::cout << "Speedbreaker: " << SpeedBreakerValue << std::endl;
		std::cout << "RPM: " << GetRpmValue << std::endl;
		std::cout << "Turbo: " << GetTurboValue << std::endl;
		std::cout << "Car ID hash: " << DALVehicle_GetCarIDHash(DALVehiclePointer, &CarIDHash, 0) << std::endl;

		return 1;
	}
}*/

void main()
{
	// Make HUD Update Rate depend on screen's refresh rate (thanks sparx for the idea)
	ZeroMemory(&devmode, sizeof(DEVMODE));
	EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devmode);
	float HUDUpdateRate = devmode.dmDisplayFrequency / 30.0f;
	injector::WriteMemory<float>(0xA7127C, HUDUpdateRate, true);

	// Debugging
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	std::cout << "HUD Update Rate: " << HUDUpdateRate << std::endl;

	// SkipFE
	injector::WriteMemory(0xA9E620, 1, true);

	// Disable SMS
	injector::MakeJMP(0x66B771, 0x66B779, true);

	// Disable Silverton barriers
	injector::WriteMemory<unsigned char>(0x61817C, 0xEB, true);

	// Setting cursor to the centre of the screen (like in newer NFS)
	SetCursorPos(ScreenX / 2, ScreenY / 2);

	// Fix save and load
	injector::MakeNOP(0x59606d, 2, true);
	injector::MakeNOP(0x5960a9, 2, true);

	// Disable pausing
	injector::MakeJMP(0x4A62E0, ReturnFalse, false);
	injector::MakeJMP(0x4A6300, ReturnFalse, false);
	injector::MakeJMP(0x4C5860, ReturnTrue, true);
	injector::MakeJMP(0x4CE410, ReturnTrue, true);

	// Initialize HUD
	//CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&MainThread, NULL, 0, NULL);

	// Disable speedbreaker
	injector::MakeJMP(0x761BF0, ReturnFalse, false);

	// Unlock all things
	injector::WriteMemory(0xA9E6C0, 1, true);

	// Console title
	SetConsoleTitle( TEXT("Need for Speed Weeaboo"));

	// Store settings
	injector::MakeNOP(0x71D117, 10, true);

	// Fix key remapping
	injector::WriteMemory<int>(0x692539, 29, true);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		main();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

