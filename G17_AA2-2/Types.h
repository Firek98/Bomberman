#pragma once
#include <string>
#include <SDL.h>
#include "../dep/inc/XML/rapidxml.hpp"
#include "../dep/inc/XML/rapidxml_iterators.hpp"
#include "../dep/inc/XML/rapidxml_print.hpp"
#include "../dep/inc/XML/rapidxml_utils.hpp"
#include <sstream>
#include <iostream>

	using Rect = struct  Rect{ int  x; int y; int w; int h; };

	using Color = struct Color { Uint8 r; Uint8 g; Uint8 b; Uint8 a; };
	
	struct Vector2 { int x; int y; };

	using Font = struct {
		std::string id;
		std::string path;
		int size;
	};

	using Text = struct {
		std::string id;
		std::string text;
		Color color;
		int w;
		int h;
	};

	enum class Key {UP, DOWN, LEFT, RIGHT, NONE};

	enum class PowerUp
	{
		PATINES, CASCO, NOTHING
	};

	enum class positions {

		ARRIBA, ABAJO, IZQUIERDA, DERECHA
	};

	enum StateScene
	{
		RUNNING, GOTO1, GOTO2, GOTOR, EXIT
	};

	enum scene
	{
		MENU, LVL1, LVL2, RANKING
	};