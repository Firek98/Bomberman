#pragma once
#include "Renderer.h"
#include "Types.h"

class GameObject
{
public:
	GameObject();
	GameObject(SDL_Rect recta);
	~GameObject();

	SDL_Rect sprites;
	SDL_Rect pos;

	GOtypes tipo;

	virtual void Draw();
};

