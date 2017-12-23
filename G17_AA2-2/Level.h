#pragma once
#include "Scene.h"
#include "Player.h"
#include "Muro.h"
#include "MuroI.h"
#include "Bomb.h"
#include "PUP.h"

class Level :
	public Scene
{
public:
	Level();
	~Level();
	void handleEvent() override;
	void Draw() override;
	void Update() override;

	SDL_Event evento;

	GameObject *jugador1;
	GameObject *jugador2;

	bool j1;
	bool j2;

	GameObject *map[11][13];

	bool salir;
};