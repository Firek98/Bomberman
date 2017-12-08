#pragma once
#include "Renderer.h"
class GameObject
{
public:
	GameObject();
	~GameObject();

	SDL_Rect sprites;
	SDL_Rect pos;
};

