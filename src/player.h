#pragma once

#include <SFML/Graphics.hpp>
#include "entity.h"

using namespace sf;

class Player : public Entity{
	private:
		

		void stop_map_moving();

	public:

		Player(String player_img, int frame_width, int frame_height, int start_row, int start_column);
};
