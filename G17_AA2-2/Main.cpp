#include "Game.h"
#include "Level.h"
int main(int, char*[]) {


	//Game game;

	//game.Running();

	Level lvl1;
	
	while (true)
	{
		lvl1.handleEvent();
		lvl1.Update();
		lvl1.Draw();
	}
	return 0;
}