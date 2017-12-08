#pragma once
#include "Scene.h"

class Menu :
	public Scene
{
public:
	Menu();
	~Menu();

	void handleEvent() override;
	void Draw() override;
	void Update() override;

	std::unordered_map<char, SDL_Rect>menu;
	SDL_Event evento;
};