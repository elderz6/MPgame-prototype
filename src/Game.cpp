#include "../include/Game.h"
#include "../include/GameObject.h"
#include <iostream>

SDL_Rect destRect;
SDL_Event Game::event;

Game::Game()
	:m_window{ nullptr },
	m_renderer{ nullptr },
	m_isRunning{ false },
	m_frame{0}
{
}

Game::~Game()
{
}

void Game::init(const char* title, int x, int y, int w, int h, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL initialized" << std::endl;
		m_window = SDL_CreateWindow(title, x, y, w, h, SDL_WINDOW_SHOWN);
		m_renderer = SDL_CreateRenderer(m_window, -1, 0);
		if (!m_renderer)
		{
			m_isRunning = false;
		}
		m_isRunning = true;
	}
	else
	{
		m_isRunning = false;
	}
	m_player = new GameObject("./images/P1.png", m_renderer, 0.f, 0.f, true);
	m_enemy = new GameObject("./images/P2.png", m_renderer, 100.f, 100.f, false);
}

void Game::update()
{
	m_player->Update();
	m_enemy->Update();
}

void Game::render()
{
	SDL_RenderClear(m_renderer);
	m_player->Render();
	m_enemy->Render();
	SDL_RenderPresent(m_renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		m_isRunning = false;
		break;
	default:
		break;
	}
}
