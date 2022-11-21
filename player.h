#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
	private:
		Sprite sprite;
		Texture texture;

	public:
		Player(String player_img, int width, int height, int start_row, int start_column);

		void set_position(Vector2f position);
		void set_text_rect(IntRect rect);

		Vector2f get_position();
		Sprite get_sprite();
};
