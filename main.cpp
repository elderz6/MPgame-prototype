#include "include/Game.h"
#include "include/SteamManager.h"
#include "include/GameServer.h"

int main(int argc, char* args[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	//SteamManager manager = SteamManager{};
	GameServer server = GameServer{};

	Uint32 frameStart;
	int frameTime;

	Game* game = new Game();
	game->init("Prototype", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

	//manager.InitSteam();
	server.InitServer();

	while (game->isRunning())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
		server.ListenConnection();
	}
	//manager.ShutdownSteam();
	server.CloseServer();
	game->clean();

	return 0;
}