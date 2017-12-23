#include "MuroI.h"



MuroI::MuroI(SDL_Rect recta)
{
	tipo = GOtypes::MUROI;
	pos = recta;
	Vector2 vect = Renderer::Instance()->GetTextureSize(ITEMS);

	vect.x /= 3;
	vect.y /= 2;

	sprites = { 0, 0, ITEM_SIZE, ITEM_SIZE };
}


MuroI::~MuroI()
{
}

void MuroI::Draw()
{
	Renderer::Instance()->PushSprite(ITEMS, sprites, pos);
}
