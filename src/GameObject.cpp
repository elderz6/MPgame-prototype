#include "../include/GameObject.h"
#include "../include/TextureManager.h"
#include <iostream>

GameObject::GameObject(const char* textureSheet, SDL_Renderer* renderer)
	:m_renderer{renderer},
	m_texture{nullptr},
	m_srcRect{},
	m_destRec{},
	m_xPos{0}, 
	m_yPos{0},
	m_speed{10},
	m_yMove{0},
	m_xMove{0}
{
	m_texture = TextureManager::LoadTexture(textureSheet, renderer);
	m_srcRect.h = 32;
	m_srcRect.w = 32;
	m_srcRect.x = 0;
	m_srcRect.y = 0;

	m_destRec.x = m_xPos;
	m_destRec.y = m_yPos;
	m_destRec.w = m_srcRect.w * 2;
	m_destRec.h = m_srcRect.h * 2;
}

void GameObject::SetPosition(int x, int y)
{
	m_xPos = x;
	m_yPos = y;
}

void GameObject::Update()
{
	HandleInput();
	ConsumeInput();
}

void GameObject::Render()
{
	SDL_RenderCopy(m_renderer, m_texture, &m_srcRect, &m_destRec);
}

void GameObject::GetPosition()
{

}

void GameObject::HandleInput()
{
	SDL_Keycode key = Game::event.key.keysym.sym;

	if (Game::event.type == SDL_KEYDOWN && Game::event.key.repeat == 0)
	{
		if (key == SDLK_a) m_xMove += -1.f;
		else if (key == SDLK_d) m_xMove += 1.f;
		if (key == SDLK_w) m_yMove += -1.f;
		else if (key == SDLK_s) m_yMove += 1.f;
	}
	else if (Game::event.type == SDL_KEYUP && Game::event.key.repeat == 0)
	{
		if (key == SDLK_a) m_xMove -= -1.f;
		else if (key == SDLK_d) m_xMove -= 1.f;
		if (key == SDLK_w) m_yMove -= -1.f;
		else if (key == SDLK_s) m_yMove -= 1.f;
	}
}

void GameObject::ConsumeInput()
{
	m_destRec.x += m_xMove * m_speed;
	m_destRec.y += m_yMove * m_speed;
}
