#include <iostream>
#include "../include/SteamManager.h"

void SteamManager::InitSteam()
{
	SteamErrMsg errMsg;
	if (SteamAPI_InitEx(&errMsg) != k_ESteamAPIInitResult_OK)
		std::cout << errMsg << std::endl;
}

void SteamManager::ShutdownSteam()
{
	SteamAPI_Shutdown();
	std::cout << "Closing steam" << std::endl;
}
