#include "Menu.h"



Menu::Menu()
{
	rend = Renderer::Instance();
	rend->LoadTexture(MENU_BG, PATH_IMG+"bgGame.jpg");
	rend->LoadFont({ MENU_80, PATH_FONT + "game_over.ttf" });
	Text button1{ BUTTON1, "Play LvL 1", {0,0,0, 255}, 123, 81 };
	Text button2{ BUTTON2, "Play LvL 2", {0,0,0, 255 }, 123, 81};
	Text buttonRank{ BUTTONRANK, "Ranking", {0,0,0, 255 }, 123, 81};
	Text buttonMusic{ BUTTONMUSIC, "Music", {0,0,0, 255}, 123, 81 };
	Text buttonExit{ BUTTONEXIT, "Exit", {0,0,0, 255}, 123, 81 };
	rend->LoadTextureText(MENU_80, button1);
	rend->LoadTextureText(MENU_80, button2);
	rend->LoadTextureText(MENU_80, buttonRank);
	rend->LoadTextureText(MENU_80, buttonMusic);
	rend->LoadTextureText(MENU_80, buttonExit);

	//Text PlayT1{ MENU_TEXT_BUTTON_PLAY,"Map 1",{ 0,255,0,255 },123,81 };
	//rend->LoadTextureText(MENU_80,PlayT1);

	menu['0'] = { 0, 0, SCREEN_WIDTH , SCREEN_HEIGHT };
	Vector2 vector = rend->GetTextureSize(MENU_TEXT_BUTTON_PLAY);
	Vector2 pos = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 100};
	menu['1'] = { pos.x, pos.y, 80 , 46};
	pos.y += 46;
	vector = rend->GetTextureSize(BUTTON2);
	menu['2'] = { pos.x, pos.y, vector.x, vector.y };
	pos.y += vector.y;
	vector = rend->GetTextureSize(BUTTONRANK);
	menu['R'] = { pos.x, pos.y, vector.x, vector.y };
	pos.y += vector.y;
	vector = rend->GetTextureSize(BUTTONMUSIC);
	menu['M'] = { pos.x, pos.y, vector.x, vector.y };
	pos.y += vector.y;
	vector = rend->GetTextureSize(BUTTONEXIT);
	menu['E'] = { pos.x, pos.y, vector.x, vector.y };
}


Menu::~Menu()
{
}

void Menu::handleEvent()
{
}

void Menu::Draw()
{
	rend->Clear();

	rend->PushImage(MENU_BG, menu['0']);
	rend->PushImage(BUTTON1, menu['1']);
	rend->PushImage(BUTTON2, menu['2']);
	rend->PushImage(BUTTONRANK, menu['R']);
	rend->PushImage(BUTTONMUSIC, menu['M']);
	rend->PushImage(BUTTONEXIT, menu['E']);
	rend->Render();
}

void Menu::Update()
{
}
