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
	pos = { 0,0, 48,48 };

	powerUp = NOTHING;
}


Player::~Player()
{
}

void Player::movePlayer()
{
}
