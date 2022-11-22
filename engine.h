#pragma once

#include <SFML/Graphics.hpp>
#include "player.h"

using namespace sf;

class Engine {
	public:
		RenderWindow window;
		Player player = Player("images/player.png", 80, 120, 0, 0);

		Engine();

		void init(int width, int height, String title);
		void loop();
		void draw();
};
