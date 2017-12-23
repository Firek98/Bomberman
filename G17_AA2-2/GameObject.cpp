#include "GameObject.h"



GameObject::GameObject()
{
	tipo = GOtypes::NADA;
}

GameObject::GameObject(SDL_Rect recta)
{
	tipo = GOtypes::NADA;
	pos = recta;
	sprites = { 0,0,0,0 };
}


GameObject::~GameObject()
{
}

void GameObject::Draw()
{

}
