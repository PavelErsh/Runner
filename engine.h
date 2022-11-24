#pragma once

#include <SFML/Graphics.hpp>
#include "map.h"

using namespace sf;

class Engine {
	public:
		RenderWindow window;

		Engine();

		Map map;
		void init(int width, int height, String title);
		void loop();
		void draw();
};
