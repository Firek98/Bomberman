#pragma once
#include "Renderer.h"
class Player 
{

public:
	Player(int a);
	~Player();

	int vida;
	float velocidad;
	bool invencible;
	bool bombSet;
	int Puntuation;
	
	void movePlayer(positions a);

protected:

	SDL_Rect pos;

private:
	PowerUp powerUp;
	SDL_Rect sprites;
};