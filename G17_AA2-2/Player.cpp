#include "Player.h"



Player::Player(int a)
{
	vida = a;

	velocidad = 1;
	invencible = false;
	bombSet = false;
	Puntuation = 0;

	Vector2 PlayerSize = Renderer::Instance()->GetTextureSize(PLAYER_SPRITE);

	PlayerSize.x = PlayerSize.x / 3;
	PlayerSize.y = PlayerSize.y / 4;

	sprites = { PlayerSize.x, PlayerSize.y * 2, PlayerSize.x, PlayerSize.y };
	pos = { 0,0, ITEM_SIZE, ITEM_SIZE };

	powerUp = PowerUp::NOTHING;
}


Player::~Player()
{
}

void Player::movePlayer(positions a)
{

	switch (a)
	{
	case positions::ARRIBA:

		if (powerUp == PowerUp::PATINES)
		{
			pos.y -= velocidad * 1.8;
		}
		else
		{
			pos.y -= velocidad;
		}

		break;

	case positions::ABAJO:

		if (powerUp == PowerUp::PATINES)
		{
			pos.y += velocidad * 1.8;
		}
		else
		{
			pos.y += velocidad;
		}

		break;

	case positions::IZQUIERDA:

		if (powerUp == PowerUp::PATINES)
		{
			pos.x -= velocidad * 1.8;
		}
		else
		{
			pos.x -= velocidad;
		}

		break;

	case positions::DERECHA:

		if (powerUp == PowerUp::PATINES)
		{
			pos.x += velocidad * 1.8;
		}
		else
		{
			pos.x += velocidad;
		}

		break;

	default:
		break;
	}

}
