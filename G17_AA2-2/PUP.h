#pragma once
#include "GameObject.h"
class PUP :
	public GameObject
{
public:
	PUP(SDL_Rect recta, PowerUp powerup);
	~PUP();

	void Draw() override;
};

