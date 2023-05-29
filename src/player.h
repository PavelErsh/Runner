#pragma once

#include <SFML/Graphics.hpp>
#include "entity.h"

using namespace sf;

class Player : public Entity{
	private:
		

		void stop_map_moving();

	public:

		Player(String player_img, int frame_width = 200, int frame_height = 200, int start_row = 0, int start_column = 0);
};
