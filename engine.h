#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Engine {
	public:
		RenderWindow window;
		Engine();
		void init(int width, int height, String title);
		void loop();
};
