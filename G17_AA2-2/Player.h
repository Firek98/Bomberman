#pragma once
#include "Renderer.h"
#include "GameObject.h"
class Player : public GameObject
{

public:
	Player(int a, SDL_Rect recta);
	~Player();

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

protected:

	SDL_Rect pos;

private:
	PowerUp powerUp;
	SDL_Rect sprites;
};