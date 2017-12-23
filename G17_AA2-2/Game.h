#pragma once
#include "Menu.h"
#include "Level.h"
class Game
{
public:
	Game();
	~Game();
	void Running();

	bool isRunning;
	Scene *game;

	scene actual;
};

