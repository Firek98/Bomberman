#pragma once
#include "Renderer.h"

class GameObject
{
public:
	GameObject();
	GameObject(SDL_Rect recta);
	~GameObject();

	SDL_Rect sprites;
	SDL_Rect pos;


	virtual void Draw();

};

