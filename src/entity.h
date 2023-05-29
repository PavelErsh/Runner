#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Entity {
    protected:
		Sprite sprite;
		Texture texture;
		Vector2f speed;
		Vector2f position;

		float current_frame = NULL;
		int frame_widht;
		int frame_height;

		String name;

    public:
        Entity (String player_img, int frame_width, int frame_height, int start_row, int start_column);
		Clock clock;

		void set_position(Vector2f position);
		void set_texture_rect(IntRect rect);
		void set_speed(Vector2f speed);
		void set_name(String name);

		void update();
		void next_frame( int frame_row, int max_frame , bool is_fleep);
		void check_frame(int max_frame, bool is_filp);

		float get_time();

		Vector2f get_position();
		Vector2f get_speed();
		Sprite get_sprite();

		int get_widht();
		int get_height();

		String get_name();
};