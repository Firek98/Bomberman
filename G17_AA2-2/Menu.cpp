#include "Menu.h"



Menu::Menu()
{
	Renderer::Instance()->LoadTexture(MENU_BG, PATH_IMG+"bgGame.jpg");
	Renderer::Instance()->LoadFont({MENU_80, PATH_FONT+"game_over.ttf", 80});
	Text button1{ BUTTON1, "Play LvL 1", {0,0,0, 255}, 123, 81 };
	Text button2{ BUTTON2, "Play LvL 2", {0,0,0, 255 }, 123, 81};
	Text buttonRank{ BUTTONRANK, "Ranking", {0,0,0, 255 }, 123, 81};
	Text buttonMusic{ BUTTONMUSIC, "Music", {0,0,0, 255}, 123, 81 };
	Text buttonExit{ BUTTONEXIT, "Exit", {0,0,0, 255}, 123, 81 };
	Renderer::Instance()->LoadTextureText(MENU_80, button1);
	Renderer::Instance()->LoadTextureText(MENU_80, button2);
	Renderer::Instance()->LoadTextureText(MENU_80, buttonRank);
	Renderer::Instance()->LoadTextureText(MENU_80, buttonMusic);
	Renderer::Instance()->LoadTextureText(MENU_80, buttonExit);

	menu['0'] = { 0, 0, SCREEN_WIDTH , SCREEN_HEIGHT };
	
	Vector2 vector = Renderer::Instance()->GetTextureSize(BUTTON1);
	Vector2 pos = { SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) - 100};
	pos.y -= vector.y / 2;
	pos.x -= vector.x / 2;
	menu['1'] = { pos.x, pos.y, vector.x, vector.y };
	pos.y += 46;
	vector = Renderer::Instance()->GetTextureSize(BUTTON2);
	menu['2'] = { pos.x, pos.y, vector.x, vector.y };
	pos.y += vector.y;
	vector = Renderer::Instance()->GetTextureSize(BUTTONRANK);
	menu['R'] = { pos.x, pos.y, vector.x, vector.y };
	pos.y += vector.y;
	vector = Renderer::Instance()->GetTextureSize(BUTTONMUSIC);
	menu['M'] = { pos.x, pos.y, vector.x, vector.y };
	pos.y += vector.y;
	vector = Renderer::Instance()->GetTextureSize(BUTTONEXIT);
	menu['E'] = { pos.x, pos.y, vector.x, vector.y };
	
}


Menu::~Menu()
{
}

void Menu::handleEvent()
{
	while (SDL_PollEvent(&evento)) {
		switch (evento.type)
		{
		case SDL_MOUSEBUTTONDOWN:

			señal = true;
			break;

		case SDL_MOUSEBUTTONUP:

			señal = false;
			break;
		}
	}
}

void Menu::Draw()
{
	Renderer::Instance()->Clear();

	Renderer::Instance()->PushImage(MENU_BG, menu['0']);
	Renderer::Instance()->PushImage(BUTTON1, menu['1']);
	Renderer::Instance()->PushImage(BUTTON2, menu['2']);
	Renderer::Instance()->PushImage(BUTTONRANK, menu['R']);
	Renderer::Instance()->PushImage(BUTTONMUSIC, menu['M']);
	Renderer::Instance()->PushImage(BUTTONEXIT, menu['E']);

	Renderer::Instance()->Render();
}

void Menu::Update()
{

}
