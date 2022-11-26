#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
	private:
		Sprite sprite;
		Texture texture;
		Vector2f speed;
		Vector2f position;

	public:
		float current_frame = 0;
		Player(String player_img, int width, int height, int start_row, int start_column);

		void set_position(Vector2f position);
		void set_text_rect(IntRect rect);
		void set_speed(Vector2f speed);
		void update();

		Vector2f get_position();
		Vector2f get_speed();
		Sprite get_sprite();
};
