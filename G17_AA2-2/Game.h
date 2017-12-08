#pragma once
#include "Menu.h"
class Game
{
public:
	Game();
	~Game();
	void Running();

	bool isRunning;
	Scene *game;
};

