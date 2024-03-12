#include "../include/GameServer.h"
#include <iostream>
#include <string>

GameServer::GameServer()
	:m_socket{},
	m_socketSet{},
	m_client{},
	m_ipAdd{}
{
}

void GameServer::InitServer()
{
	SDLNet_Init();
	SDLNet_ResolveHost(&m_ipAdd, NULL, 31234);
	m_serverTCP = SDLNet_TCP_Open(&m_ipAdd);
}

void GameServer::ListenConnection()
{
	m_clientTCP = SDLNet_TCP_Accept(m_serverTCP);

	if (m_clientTCP)
	{
		const char* testString = "Conectado\n";
		//std::string testString = "test";
		SDLNet_TCP_Send(m_clientTCP, testString, strlen(testString) + 1);
		SDLNet_TCP_Close(m_clientTCP);
		std::cout << "Conexao recebida" << std::endl;

	}
	//m_socket = SDLNet_UDP_Open(31234);
	//m_client = SDLNet_UDP_Bind();
}



void GameServer::CloseServer()
{
	SDLNet_TCP_Close(m_serverTCP);
	//SDLNet_UDP_DelSocket(m_socketSet, m_socket);
	SDLNet_Quit();
}
