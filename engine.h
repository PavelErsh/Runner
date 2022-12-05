#pragma once

#include <SFML/Graphics.hpp>
#include "map.h"
#include "key_press.h"
#include "camera.h"

using namespace sf;

class Engine {
	public:
		RenderWindow window;
		Key_press key_press;
		Camera* camera;
		Engine();

		Map map;
		void init(int width, int height, String title);
		void loop();
		void draw();
		void update();
};
