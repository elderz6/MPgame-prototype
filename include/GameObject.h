#pragma once
#include "Game.h"

class GameObject
{
public:
	GameObject(const char* textureSheet, SDL_Renderer* renderer);
	~GameObject();

	void SetPosition(int x, int y);

	virtual void Update();
	virtual void Render();

	void GetPosition();

private:
	int m_xPos;
	int m_yPos;

	float m_speed;
	float m_xMove;
	float m_yMove;

	void HandleInput();
	void ConsumeInput();

	SDL_Texture* m_texture;
	SDL_Rect m_srcRect;
	SDL_Rect m_destRec;
	SDL_Renderer* m_renderer;

};