#pragma once
#define THEDALMANAGERADDRESS 0x00A8AD30
#define THEGAMEFLOWMANAGER_ADDRESS 0xA99BBC
bool(__thiscall *DALVehicle_GetRPM)(void *DALVehicle, float *getVal, const int playerNum) = (bool(__thiscall*)(void*, float*, const int))0x004B65F0;
bool(__thiscall *DALVehicle_GetMaxRPM)(void *DALVehicle, float *getVal, const int playerNum) = (bool(__thiscall*)(void*, float*, const int))0x004B66E0;
bool(__thiscall *DALVehicle_GetTurbo)(void *DALVehicle, float *getVal, const int playerNum) = (bool(__thiscall*)(void*, float*, const int))0x004B6730;
bool(__thiscall *DALVehicle_GetSpeedMps)(void *DALVehicle, float *getVal, const int playerNum) = (bool(__thiscall*)(void*, float*, const int))0x004B65A0;
bool(__thiscall *DALVehicle_GetGear)(void *DALVehicle, int *getVal, const int playerNum) = (bool(__thiscall*)(void*, int*, const int))0x004B68C0;
bool(__thiscall *DALVehicle_GetNos)(void *DALVehicle, float *getVal, const int playerNum) = (bool(__thiscall*)(void*, float*, const int))0x004B67F0;
bool(__thiscall *DALVehicle_GetSpeedBreaker)(void *DALVehicle, float *getVal, const int playerNum) = (bool(__thiscall*)(void*, float*, const int))0x004B6870;
bool(__thiscall *DALVehicle_GetCarIDHash)(void *DALVehicle, int *getVal, const int playerNum) = (bool(__thiscall*)(void*, int*, const int))0x004B6FB0;
bool(__thiscall *DALVehicle_GetRedLine)(void *DALVehicle, float *getVal, const int playerNum) = (bool(__thiscall*)(void*, float*, const int))0x004B6690;
bool(__thiscall *DALVehicle_GetWheelAngle)(void *DALVehicle, float *getVal, const int playerNum) = (bool(__thiscall*)(void*, float*, const int))0x004C3610;
bool(__thiscall *DALVehicle_GetIsPlayerControlling)(void *DALVehicle, int *getVal, const int playerNum) = (bool(__thiscall*)(void*, int*, const int))0x004C3540;
bool(__thiscall *DALVehicle_GetIsRevolutionWheelVisible)(void *DALVehicle, int *getVal, const int playerNum) = (bool(__thiscall*)(void*, int*, const int))0x004B7050;
bool(__thiscall *DALVehicle_GetStockCarIDHash)(void *DALVehicle, int *getVal, const int playerNum) = (bool(__thiscall*)(void*, int*, const int))0x004B7000;
bool(__thiscall *DALVehicle_GetSpeedPercentToDriftCap)(void *DALVehicle, float *getVal, const int playerNum) = (bool(__thiscall*)(void*, float*, const int))0x004B6F40;
bool(__thiscall *DALVehicle_GetPipHeight)(void *DALVehicle, float *getVal, const int playerNum) = (bool(__thiscall*)(void*, float*, const int))0x004B6EF0;
bool(__thiscall *DALVehicle_GetPipWidth)(void *DALVehicle, float *getVal, const int playerNum) = (bool(__thiscall*)(void*, float*, const int))0x004B6EA0;
bool(__thiscall *DALVehicle_GetPipPosY)(void *DALVehicle, float *getVal, const int playerNum) = (bool(__thiscall*)(void*, float*, const int))0x004B6E40;
bool(__thiscall *DALVehicle_GetPipPosX)(void *DALVehicle, float *getVal, const int playerNum) = (bool(__thiscall*)(void*, float*, const int))0x004B6DE0;
bool(__thiscall *DALVehicle_GetIsHudVisible)(void *DALVehicle, int *getVal, const int playerNum) = (bool(__thiscall*)(void*, int*, const int))0x004B6DA0;
bool(__thiscall *DALVehicle_GetIsDrivingCamera)(void *DALVehicle, int *getVal, const int playerNum) = (bool(__thiscall*)(void*, int*, const int))0x004B6D50;
bool(__thiscall *DALVehicle_GetIsFacingWrongWay)(void *DALVehicle, int *getVal, const int playerNum) = (bool(__thiscall*)(void*, int*, const int))0x004B6D00;
bool(__thiscall *DALVehicle_GetInPerfectLaunchRange)(void *DALVehicle, int *getVal, const int playerNum) = (bool(__thiscall*)(void*, int*, const int))0x004B6BF0;
bool(__thiscall *DALVehicle_GetPipTextureInfo)(void *DALVehicle, int *getVal, const int playerNum) = (bool(__thiscall*)(void*, int*, const int))0x004B6B90;
bool(__thiscall *DALVehicle_GetVehicleDestroyed)(void *DALVehicle, int *getVal, const int playerNum) = (bool(__thiscall*)(void*, int*, const int))0x004B6B40;
bool(__thiscall *DALVehicle_GetEngineBlown)(void *DALVehicle, int *getVal, const int playerNum) = (bool(__thiscall*)(void*, int*, const int))0x004B6AF0;
bool(__thiscall *DALVehicle_GetStaging)(void *DALVehicle, int *getVal, const int playerNum) = (bool(__thiscall*)(void*, int*, const int))0x004B6AA0;
bool(__thiscall *DALVehicle_GetShifting)(void *DALVehicle, int *getVal, const int playerNum) = (bool(__thiscall*)(void*, int*, const int))0x004B6A50;
bool(__thiscall *DALVehicle_GetLastShiftStatus)(void *DALVehicle, int *getVal, const int playerNum) = (bool(__thiscall*)(void*, int*, const int))0x004B69B0;
bool(__thiscall *DALVehicle_GetShiftPotential)(void *DALVehicle, int *getVal, const int playerNum) = (bool(__thiscall*)(void*, int*, const int))0x004B6910;
bool(__thiscall *DALVehicle_GetHeat)(void *DALVehicle, float *getVal, const int playerNum) = (bool(__thiscall*)(void*, float*, const int))0x004B6790;
bool(__thiscall *DALVehicle_GetSpeedLocalized)(void *DALVehicle, float *getVal, const int playerNum) = (bool(__thiscall*)(void*, float*, const int))0x004B6500;
bool(__thiscall *DALVehicle_GetIVehicle)(const int playerNum) = (bool(__thiscall*)(const int))0x004B62B0;
bool(__thiscall *DALVehicle_GetInt)(void *DALVehicle, const int valueType, int *getVal, const int arg1, const int arg2, const int arg3) = (bool(__thiscall*)(void*, const int, int*, const int, const int, const int))0x004CC1C0;
bool(__thiscall *DALVehicle_GetFloat)(void *DALVehicle, const int valueType, float *getVal, const int arg1, const int arg2, const int arg3) = (bool(__thiscall*)(void*, const int, float*, const int, const int, const int))0x004CC000;
