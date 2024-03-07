#pragma once
#include "SDL2/SDL.h"
#include "TextureManager.h"

class GameObject;
class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int x, int y, int w, int h, bool fullscreen);
	virtual void update();
	virtual void render();
	void clean();
	void handleEvents();

	bool isRunning() { return m_isRunning; }
	static SDL_Event event;

private:
	bool m_isRunning;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	GameObject* m_player;
	GameObject* m_enemy;
	int m_frame;
};