#include "Level.h"



Level::Level()
{
	Renderer::Instance()->LoadTexture(PLAY_BG, PATH_IMG + "bgGame.jpg");
	Renderer::Instance()->LoadTexture(PLAYER_SPRITE, PATH_IMG + "player1.png");
	Renderer::Instance()->LoadTexture(PLAYER_SPRITE, PATH_IMG + "player2.png");
	Renderer::Instance()->LoadTexture(ITEMS, PATH_IMG + "items.png");
	Renderer::Instance()->LoadTexture(EXPLOSION, PATH_IMG + "explosion.png");

	int w, h;

	w = SCREEN_WIDTH / 15;
	h = (SCREEN_HEIGHT - 80) / 13;

	rapidxml::xml_document<> document;
	std::ifstream archivo(PATH_IMG + "m.xml");
	std::stringstream buffer;
	buffer << archivo.rdbuf();
	archivo.close();
	std::string cont(buffer.str());
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

	for (int i = 0; i < 13; i++)
	{

		w = SCREEN_WIDTH / 15;

		for (int j = 0; j < 11; j++)
		{
			if (i == auxX && j == auxY)
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
						int auxX;
						auxX = atoi(strung.c_str());
						atr = atr->next_attribute();
						strung = atr->value();
						int auxY;
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
						int auxX;
						auxX = atoi(strung.c_str());
						atr = atr->next_attribute();
						strung = atr->value();
						int auxY;
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

	jugador1 = new Player(3);
	jugador2 = new Player(3);
	j1 = false;
	j2 = false;
}


Level::~Level()
{
}

void Level::handleEvent()
{
	while (SDL_PollEvent(&evento))
	{
		switch (evento.type) {
		
		case SDLK_w:
			break;
		case SDLK_s:
			break;
		case SDLK_a:
			break;
		case SDLK_d:
			break;
		case SDLK_SPACE:
			break;
		case SDLK_UP:
			break;
		case SDLK_DOWN:
			break;
		case SDLK_LEFT:
			break;
		case SDLK_RIGHT:
			break;
		case SDLK_LCTRL:
			break;

		}

	}
}

void Level::Draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(PLAY_BG, {0,0,SCREEN_WIDTH, SCREEN_HEIGHT});
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			map[i][j]->Draw();
		}
	}

	Renderer::Instance()->Render();
}

void Level::Update()
{

}
