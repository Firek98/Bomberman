#pragma once
#include "Renderer.h"
class Scene
{
public:
	Scene();
	~Scene();

	virtual void handleEvent();
	virtual void Draw();
	virtual void Update();
};

