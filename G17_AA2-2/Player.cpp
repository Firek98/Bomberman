#include "Player.h"



Player::Player(int a, SDL_Rect recta, GameObject *map[11][13])
{
	vida = a;

	velocidad = 1;
	invencible = false;
	bombSet = false;
	Puntuation = 0;

	Vector2 PlayerSize = Renderer::Instance()->GetTextureSize(PLAYER_SPRITE);

	PlayerSize.x = PlayerSize.x / 3;
	PlayerSize.y = PlayerSize.y / 4;

	sprites = { PlayerSize.x, PlayerSize.y * 2, PlayerSize.x, PlayerSize.y};
	pos = recta;

	powerUp = PowerUp::NOTHING;

	arriba = false;
	izq = false;
	derecha = false;
	abajo = false;

	for (int x = 0; x < 11; x++)
	{
		for (int y = 0; y < 13; y++)
		{
			myMap[x][y] = map[x][y];
		}
	}
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
	std::cout << pos.x << ", " << pos.y << std::endl;
	if (arriba &&
		pos.y - velocidad >= HUD_HEIGHT + ITEM_SIZE &&
		myMap[(int)((pos.y - velocidad - HUD_HEIGHT) / 48) - 1][(int)((pos.x + 1) / 48) - 1]->tipo != GOtypes::MUROI &&
		myMap[(int)((pos.y - velocidad - HUD_HEIGHT) / 48) - 1][(int)((pos.x - 1 + 48) / 48) - 1]->tipo != GOtypes::MURO)

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

	else if (abajo &&
		myMap[(int)((pos.y + 48 + velocidad - 80) / 48) - 1][(int)((pos.x + 1) / 48) - 1]->tipo == GOtypes::NADA &&    // II
		myMap[(int)((pos.y + 48 + velocidad - 80) / 48) - 1][(int)((pos.x + 48 - 1) / 48) - 1]->tipo == GOtypes::NADA) // ID
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
	else if (izq &&
		pos.x - velocidad >= ITEM_SIZE &&
		myMap[(int)((pos.y + 1 - 80) / 48) - 1][(int)((pos.x - velocidad) / 48) - 1]->tipo == GOtypes::NADA &&
		myMap[(int)((pos.y - 1 + 48 - 80) / 48) - 1][(int)((pos.x - velocidad) / 48) - 1]->tipo == GOtypes::NADA)

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
	else if (derecha &&
		pos.x + velocidad + ITEM_SIZE <= SCREEN_WIDTH - ITEM_SIZE &&
		myMap[(int)((pos.y + 1 - 80) / 48) - 1][(int)((pos.x + 48 + velocidad) / 48) - 1]->tipo == GOtypes::NADA &&
		myMap[(int)((pos.y - 1 + 48 - 80) / 48) - 1][(int)((pos.x + 48 + velocidad) / 48) - 1]->tipo == GOtypes::NADA)
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
