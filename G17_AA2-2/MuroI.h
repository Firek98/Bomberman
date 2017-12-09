#pragma once
#include "GameObject.h"
class MuroI :
	public GameObject
{
public:
	MuroI(SDL_Rect recta);
	~MuroI();

	void Draw() override;
};

