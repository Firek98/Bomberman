#include "Game.h"



Game::Game()
{
	game = new Menu();
}


Game::~Game()
{
}

void Game::Running()
{
	while (true)
	{
		game->handleEvent();
		game->Update();
		game->Draw();
	}
}
