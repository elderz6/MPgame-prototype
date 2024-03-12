#pragma once
#include "SDL2/SDL_net.h"

class GameServer
{
public:
	GameServer();

	void InitServer();
	void ListenConnection();
	void CloseServer();

private:
	IPaddress m_ipAdd;
	SDLNet_SocketSet m_socketSet;

	UDPsocket m_socket;
	UDPsocket m_client;

	TCPsocket m_serverTCP;
	TCPsocket m_clientTCP;
};