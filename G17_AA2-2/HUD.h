#pragma once
#include "GameObject.h"
class HUD :
	public GameObject
{
public:
	HUD();
	~HUD();

	void Draw()override;
};

