#include "Bomb.h"


Bomb::Bomb(SDL_Rect recta)
{
	pos = recta;

	Vector2 vect = Renderer::Instance()->GetTextureSize(ITEMS);

	vect.x /= 3;
	vect.y /= 2;

	sprites = { 0, vect.y, ITEM_SIZE, ITEM_SIZE };
}


Bomb::~Bomb()
{

}

void Bomb::Draw()
{
	Renderer::Instance()->PushSprite(ITEMS, sprites, pos);
}
