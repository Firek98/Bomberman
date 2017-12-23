#include "Player.h"



Player::Player(int a, SDL_Rect recta)
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
	pos = recta;

	powerUp = PowerUp::NOTHING;

	arriba = false;
	izq = false;
	derecha = false;
	abajo = false;
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

void Player::Draw()
{
	Renderer::Instance()->PushSprite(PLAYER_SPRITE, sprites, pos);
}

void Player::HandleEvent(positions pos)
{
	switch (pos)
	{
	case positions::ARRIBA:
		arriba = true;
		izq = false;
		derecha = false;
		abajo = false;
		break;
	case positions::ABAJO:
		arriba = false;
		izq = false;
		derecha = false;
		abajo = true;
		break;
	case positions::IZQUIERDA:
		arriba = false;
		izq = true;
		derecha = false;
		abajo = false;
		break;
	case positions::DERECHA:
		arriba = false;
		izq = false;
		derecha = true;
		abajo = false;
		break;
	default:
		break;
	}
}

void Player::Update()
{

	if (arriba)
	{
		if (powerUp == PowerUp::PATINES)
		{
			pos.y -= velocidad * 1.8;
		}
		else
		{
			pos.y -= velocidad;
		}
		arriba = false;
	}

	else if (abajo)
	{
		if (powerUp == PowerUp::PATINES)
		{
			pos.y += velocidad * 1.8;
		}
		else
		{
			pos.y += velocidad;
		}
		abajo = false;
	}
	else if (izq)
	{
		if (powerUp == PowerUp::PATINES)
		{
			pos.x -= velocidad * 1.8;
		}
		else
		{
			pos.x -= velocidad;
		}
		izq = false;
	}
	else if (derecha)
	{
		if (powerUp == PowerUp::PATINES)
		{
			pos.x += velocidad * 1.8;
		}
		else
		{
			pos.x += velocidad;
		}
		derecha = false;
	}

}
