#pragma once

#include <SFML/Graphics.hpp>
#include "constants.cpp"

using namespace sf;

class Map{
    private:
        Image map_image;
        Texture map_texture;
        Sprite map_sprite;

        sf::String tile_map[HEIGHT_MAP] = {

            "sssssssssssssssssssss",

            "sgggggggggggggggggggs",

            "sgggggggggggggggggggs",

            "sgggggggggggggggggggs",

            "sgggggggggggggggggggs",

            "sgggggggggggggggggggs",

            "sgggggggggggggggggggs",

            "sgggggggggggggggggggs",

            "sgggggggggggggggggggs",

            "sgggggggggggggggggggs",

            "sgggggggggggggggggggs",

            "sssssssssssssssssssss"

            };

    public:
        Map();
        void draw(RenderWindow window);

};

