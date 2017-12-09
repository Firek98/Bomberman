#include "PUP.h"



PUP::PUP(SDL_Rect recta, PowerUp powerup)
{
	pos = recta;
	Vector2 vect = Renderer::Instance()->GetTextureSize(ITEMS);

	vect.x /= 3;
	vect.y /= 2;

	if (powerup == PowerUp::CASCO)
	{
		sprites = { vect.x * 2, vect.y, ITEM_SIZE, ITEM_SIZE };
	}
	else if (powerup == PowerUp::PATINES)
	{
		sprites = { vect.x, vect.y, ITEM_SIZE, ITEM_SIZE };
	}
}


PUP::~PUP()
{
}

void PUP::Draw()
{
	Renderer::Instance()->PushSprite(ITEMS, sprites, pos);
}
