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
		int frame_widht;
		int frame_height;

		Player(String player_img, int frame_width, int frame_height, int start_row, int start_column);

		void set_position(Vector2f position);
		void set_texture_rect(IntRect rect);
		void set_speed(Vector2f speed);

		void update();
		void next_frame( int frame_row, int max_frame , bool is_fleep);
		void  check_frame(int max_frame, bool is_filp);

		float get_time();

		Vector2f get_position();
		Vector2f get_speed();
		Sprite get_sprite();
};
