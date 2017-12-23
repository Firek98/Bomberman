#include "Game.h"



Game::Game()
{
	game = new Menu();
	isRunning = true;
	actual = MENU;

}


Game::~Game()
{
}

void Game::Running()
{
	while (isRunning)
	{
		if (game->estado == RUNNING)
		{
			game->handleEvent();
			game->Update();
			game->Draw();
		}

		else if (game->estado == GOTO1)
		{
			delete(game);
			actual = LVL1;
			game = new Level(1);
		}

		else if (game->estado == GOTO2)
		{
			delete(game);
			actual = LVL2;
			game = new Level(1);
		}

	/*	else if (game->estado == GOTOR)
		{
			delete(game);
			actual = RANKING;
			game = new Level();
		} */

		else if (game->estado == EXIT)
		{
			if (actual == MENU)
			{
				isRunning = false;
			}
			
			else
			{
				delete (game);
				actual = MENU;
				game = new Menu();
			}
		}
	
	}
}
