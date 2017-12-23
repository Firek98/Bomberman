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
	if (evento.motion.x >= menu['1'].x  && evento.motion.x <= (menu['1'].x + menu['1'].w) && evento.motion.y >= menu['1'].y && evento.motion.y <= (menu['1'].y + menu['1'].h))
	{
		if (señal)
		{
			estado = GOTO1;
			señal = false;
		}
	}

	else if (evento.motion.x >= menu['2'].x  && evento.motion.x <= (menu['2'].x + menu['2'].w) && evento.motion.y >= menu['2'].y && evento.motion.y <= (menu['2'].y + menu['2'].h))
	{

		if (señal)
		{
			estado = GOTO2;
			señal = false;
		}
	}

	else if (evento.motion.x >= menu['R'].x  && evento.motion.x <= (menu['R'].x + menu['R'].w) && evento.motion.y >= menu['R'].y && evento.motion.y <= (menu['R'].y + menu['R'].h))
	{
		if (señal)
		{
			estado = GOTOR;
			señal = false;
		}
	}

	else if (evento.motion.x >= menu['M'].x  && evento.motion.x <= (menu['M'].x + menu['M'].w) && evento.motion.y >= menu['M'].y && evento.motion.y <= (menu['M'].y + menu['M'].h))
	{
		if (señal)
		{
			std::cout << "No ere tu, soy yo";
			señal = false;
		}
	}

	else if (evento.motion.x >= menu['E'].x  && evento.motion.x <= (menu['E'].x + menu['E'].w) && evento.motion.y >= menu['E'].y && evento.motion.y <= (menu['E'].y + menu['E'].h))
	{
		if (señal)
		{
			estado = EXIT;
			señal = false;
		}
	}
}
