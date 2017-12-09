#include "GameObject.h"



GameObject::GameObject()
{
}

GameObject::GameObject(SDL_Rect recta)
{
	pos = recta;
	sprites = { 0,0,0,0 };
}


GameObject::~GameObject()
{
}

void GameObject::Draw()
{

}
