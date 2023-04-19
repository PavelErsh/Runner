#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Coin{
    private:
        Sprite sprite;
        Texture texture;
        Vector2f position;

        int frame_width;
        int frame_height;

        void init();

    public:
        Coin(Vector2f position);

        void set_position(Vector2f position);
        void set_texture_rect(IntRect rect);
        void set_width(int width);
        void set_height(int height);

        Sprite get_sprite();

        int get_width();
        int get_height();

};