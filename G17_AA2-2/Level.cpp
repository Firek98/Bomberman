#include "Level.h"



Level::Level()
{
	Renderer::Instance()->LoadTexture(PLAY_BG, PATH_IMG + "bgGame.jpg");
	Renderer::Instance()->LoadTexture(PLAYER_SPRITE, PATH_IMG + "player1.png");
	Renderer::Instance()->LoadTexture(PLAYER_SPRITE, PATH_IMG + "player2.png");
	Renderer::Instance()->LoadTexture(ITEMS, PATH_IMG + "items.png");
	Renderer::Instance()->LoadTexture(EXPLOSION, PATH_IMG + "explosion.png");

	int w, h;

	w = ITEM_SIZE;
	h = SCREEN_HEIGHT - ITEM_SIZE * 12;

	rapidxml::xml_document<> document;
	std::ifstream archivo(PATH_IMG + "mapamaquinola2.xml");
	std::stringstream buffer;
	buffer << archivo.rdbuf();
	archivo.close();
	std::string cont(buffer.str());
	document.parse<0>(&cont[0]);
	rapidxml::xml_node<> *raiz = document.first_node();
	rapidxml::xml_node<> *nodo1 = raiz->first_node();
	rapidxml::xml_attribute<> *atr = nodo1->first_attribute();
	std::string strung = atr->value();
	int auxX;
	auxX = atoi(strung.c_str());
	atr = atr->next_attribute();
	strung = atr->value();
	int auxY;
	auxY = atoi(strung.c_str());

	for (int i = 0; i < 11; i++)
	{

		w = ITEM_SIZE;

		for (int j = 0; j < 13; j++)
		{
			if (i == auxY && j == auxX)
			{
				rapidxml::xml_node<> *nodo2 = nodo1->first_node();
				strung = nodo2->value();
				if (strung == "Muro")
				{
					map[i][j] = new Muro({w, h, ITEM_SIZE, ITEM_SIZE});
					nodo1 = nodo1->next_sibling();
					atr = nodo1->first_attribute();
					if (atr != nullptr)
					{
						strung = atr->value();
						auxX = atoi(strung.c_str());
						atr = atr->next_attribute();
						strung = atr->value();
						auxY = atoi(strung.c_str());
					}
				}
				else if (strung == "MuroI") 
				{
					map[i][j] = new MuroI({ w, h, ITEM_SIZE, ITEM_SIZE });
					nodo1 = nodo1->next_sibling();
					atr = nodo1->first_attribute();
					if (atr != nullptr)
					{
						strung = atr->value();
						auxX = atoi(strung.c_str());
						atr = atr->next_attribute();
						strung = atr->value();
						auxY = atoi(strung.c_str());
					}
				}
			}
			else
			{
				map[i][j] = new GameObject({ w, h, ITEM_SIZE, ITEM_SIZE });
			}
			
			w += ITEM_SIZE;
		}
			h += ITEM_SIZE;
	}

	map[11][2];

	jugador1 = new Player(3, {100, 50, 48,48});
	jugador2 = new Player(3, {50, 100, 48,48});
	j1 = false;
	j2 = false;

	salir = false;
}


Level::~Level()
{
}

void Level::handleEvent()
{
	while (SDL_PollEvent(&evento))
	{
		switch (evento.type) {
		
		case SDL_KEYDOWN:

			if (evento.key.keysym.sym == SDLK_ESCAPE)
			{
				salir = true;
			}
			else if (evento.key.keysym.sym == SDLK_w)
			{
				jugador1->HandleEvent(positions::ARRIBA);
			}
			else if (evento.key.keysym.sym == SDLK_a)
			{
				jugador1->HandleEvent(positions::IZQUIERDA);
			}
			else if (evento.key.keysym.sym == SDLK_d)
			{
				jugador1->HandleEvent(positions::DERECHA);
			}
			else if (evento.key.keysym.sym == SDLK_s)
			{
				jugador1->HandleEvent(positions::ABAJO);
			}
			break;
		default:
			jugador1->HandleEvent(positions::NADA);
			break;
		}

	}
}

void Level::Draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(PLAY_BG, {0,0,SCREEN_WIDTH, SCREEN_HEIGHT});
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			map[i][j]->Draw();
		}
	}
	jugador1->Draw();
	jugador2->Draw();
	Renderer::Instance()->Render();
}

void Level::Update()
{

	jugador1->Update();

	if (salir)
	{
		estado = EXIT;
	}

}