#pragma once
#include "player.h"
using namespace sf;

const int HEIGHT_MAP = 12;
const int WIDTH_MAP = 21;

class Map{
    private:
        Player *player;
        Image map_image;
        Texture map_texture;
        Sprite map_sprite;

        String tile_map[HEIGHT_MAP] = {
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
        Player* get_player();

        void draw(RenderWindow &window);
        void update();
};

