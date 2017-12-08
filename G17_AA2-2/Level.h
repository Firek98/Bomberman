#pragma once
#include "Scene.h"
#include "Player.h"
class Level :
	public Scene
{
public:
	Level();
	~Level();
	void handleEvent() override;
	void Draw() override;
	void Update() override;
};