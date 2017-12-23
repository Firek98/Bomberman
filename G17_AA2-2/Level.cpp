#include "Level.h"



Level::Level(int levelNum)
{
	Renderer::Instance()->LoadTexture(PLAY_BG, PATH_IMG + "bgGame.jpg");
	Renderer::Instance()->LoadTexture(PLAYER_SPRITE, PATH_IMG + "player1.png");
	Renderer::Instance()->LoadTexture(PLAYER_SPRITE2, PATH_IMG + "player2.png");
	Renderer::Instance()->LoadTexture(ITEMS, PATH_IMG + "items.png");
	Renderer::Instance()->LoadTexture(EXPLOSION, PATH_IMG + "explosion.png");

	//jugador1 = new Player(3, { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 , ITEM_SIZE, ITEM_SIZE });

	int w, h;

	w = ITEM_SIZE;
	h = SCREEN_HEIGHT - ITEM_SIZE * 12;

	rapidxml::xml_document<> document;
	/*if (lvl == 1)
	{
	std::ifstream archivo(PATH_IMG + "m.xml");
	}
	else
	{
	std::ifstream archivo(PATH_IMG + "mapamaquinola2.xml");
	}*/
	std::ifstream archivo;
	archivo.open(PATH_FILES + "config.xml");

	std::stringstream buffer;
	buffer << archivo.rdbuf();

	archivo.close();

	std::string cont(buffer.str());
	document.parse<0>(&cont[0]);

	rapidxml::xml_node<> *raiz = document.first_node();
	rapidxml::xml_node<> *nodo1 = raiz->first_node(); ///// Gets level
	rapidxml::xml_node<> *nodo2 = nodo1->first_node(); //// Gets destructible/fixed
	rapidxml::xml_node<> *nodo3 = nodo2->first_node(); //// Gets wall

	rapidxml::xml_attribute<> *atr = nodo1->first_attribute();
	//rapidxml::xml_attribute<> *myAtr = nodo1->first_attribute();
	rapidxml::xml_attribute<> *myAtr;

	std::string strung = atr->value();

	int auxX;
	auxX = atoi(strung.c_str());

	atr = atr->next_attribute();
	strung = atr->value();

	int auxY;
	auxY = atoi(strung.c_str());

	int i, j;

	///--------------------------------------------------------------------------------------------------------------------
	for (int x = 0; x < 11; x++)
	{
		for (int y = 0; y < 13; y++)
		{
			map[x][y] = new GameObject();
		}
	}

	for (nodo1; nodo1; nodo1 = nodo1->next_sibling())
	{
		myAtr = nodo1->first_attribute();
		int a = atoi(myAtr->value());
		std::cout << a << std::endl;
		if (atoi(myAtr->value()) == levelNum)
		{
			//Destructible

			for (nodo3; nodo3; nodo3 = nodo3->next_sibling())
			{
				myAtr = nodo3->first_attribute();
				i = atoi(myAtr->value());
				myAtr = myAtr->next_attribute();
				j = atoi(myAtr->value());
				map[i][j] = new Muro({ (j + 1) * ITEM_SIZE, (i + 1) * ITEM_SIZE + 80, ITEM_SIZE, ITEM_SIZE }); ///Añade 1 a "j" e "i" para compensar el marco exterior
			}
			nodo2 = nodo2->next_sibling();
			nodo3 = nodo2->first_node();
			//Fixed
			for (nodo3; nodo3; nodo3 = nodo3->next_sibling())
			{
				myAtr = nodo3->first_attribute();
				i = atoi(myAtr->value());
				myAtr = myAtr->next_attribute();
				j = atoi(myAtr->value());
				map[i][j] = new MuroI({ (j + 1) * ITEM_SIZE, (i + 1) * ITEM_SIZE + 80, ITEM_SIZE, ITEM_SIZE }); ///Añade 1 a "j" e "i" para compensar el marco exterior
			}
		}
		/*else if (nodo1->next_sibling())
		{

		nodo1 = nodo1->next_sibling();
		myAtr = nodo1->first_attribute();
		}*/
		else
		{

		}
	}

	jugador2 = new Player(3, { 1 * ITEM_SIZE + 1, ITEM_SIZE + HUD_HEIGHT + 1, 48,48 }, map);
	jugador1 = new Player(3, { 13 * ITEM_SIZE - 1, ITEM_SIZE + HUD_HEIGHT + 1, 48,48 }, map);
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