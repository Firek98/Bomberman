#include "Level.h"



Level::Level()
{
	Renderer::Instance()->LoadTexture(PLAY_BG, PATH_IMG + "bgGame.jpg");
	Renderer::Instance()->LoadTexture(PLAYER_SPRITE, PATH_IMG + "player1.png");
	Renderer::Instance()->LoadTexture(PLAYER_SPRITE, PATH_IMG + "player2.png");
	Renderer::Instance()->LoadTexture(ITEMS, PATH_IMG + "items.png");
	Renderer::Instance()->LoadTexture(EXPLOSION, PATH_IMG + "explosion.png");
	Renderer::Instance()->LoadTexture(LEVEL2, PATH_IMG + "map1.xml");
	
}


Level::~Level()
{
}

void Level::handleEvent()
{
}

void Level::Draw()
{
}

void Level::Update()
{

}
