#include "Muro.h"



Muro::Muro(SDL_Rect recta)
{
	tipo = GOtypes::MURO;

	pos = recta;
	Vector2 vect = Renderer::Instance()->GetTextureSize(ITEMS);

	vect.x /= 3;
	vect.y /= 2;

	sprites = { vect.x, 0, ITEM_SIZE, ITEM_SIZE };
}


Muro::~Muro()
{
}

void Muro::Draw()
{
	Renderer::Instance()->PushSprite(ITEMS, sprites, pos);
}
