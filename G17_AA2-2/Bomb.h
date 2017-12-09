#pragma once
#include "GameObject.h"
class Bomb :
	public GameObject
{
public:
	Bomb(SDL_Rect recta);
	~Bomb();

	void Draw() override;
};

