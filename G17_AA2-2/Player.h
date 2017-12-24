#pragma once
#include "Renderer.h"
#include "GameObject.h"
#include "Types.h"

class Player : public GameObject
{

public:
	Player(int a, SDL_Rect recta, GameObject *map[11][13]);
	~Player();

	GameObject *myMap[11][13];

	int vida;
	float velocidad;
	bool invencible;
	bool bombSet;
	int Puntuation;
	
	void movePlayer(positions a);

	void Draw() override;
	void HandleEvent(positions pos);
	void Update();

	bool arriba;
	bool izq;
	bool derecha;
	bool abajo;

	bool bombapuesta;
	//GameObject *map[11][13];

	GameObject *bomba;

protected:

	SDL_Rect pos;

private:
	PowerUp powerUp;
	SDL_Rect sprites;
};