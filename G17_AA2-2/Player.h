#pragma once
#include "Renderer.h"
class Player 
{

	enum PowerUp
	{
		PATINES, CASCO, NOTHING
	};

public:
	Player(int a);
	~Player();

	int vida;
	float velocidad;
	bool invencible;
	bool bombSet;
	int Puntuation;

	
	void movePlayer();

protected:

	SDL_Rect pos;

private:
	PowerUp powerUp;
	SDL_Rect sprites;
};