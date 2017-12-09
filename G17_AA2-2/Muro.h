#pragma once
#include "GameObject.h"
class Muro :
	public GameObject
{
public:
	Muro(SDL_Rect recta);
	~Muro();

	void Draw()override;
};

