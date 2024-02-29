#include "../include/Game.h"
#include <iostream>

SDL_Rect destRect;

Game::Game()
	:m_window{ nullptr },
	m_renderer{ nullptr },
	m_isRunning{ false },
	m_playerTexture{ nullptr },
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

	m_playerTexture = TextureManager::LoadTexture("./images/P1.png", m_renderer);

}

void Game::update()
{
	++m_frame;
	destRect.w = 50;
	destRect.h = 50;
	destRect.x = m_frame;
	std::cout << m_frame << std::endl;
}

void Game::render()
{
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_playerTexture, NULL, &destRect);
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
	SDL_Event event;
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
