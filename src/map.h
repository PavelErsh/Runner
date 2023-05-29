#pragma once

#include "player.h"
#include "coin.h"
#include "wall.h"
#include "floor.h"

#include <list>

using namespace sf;

const int HEIGHT_MAP = 12;
const int WIDTH_MAP = 21;

class Map{
    private:
        Player *player;
        std::list<Entity*> entities;

        String tile_map[HEIGHT_MAP] = {
            "kkkkkkkkkkkkkkkkkkkkk",
            "kggggggggmggggkgmkgmk",
            "kgggggggggggggkggkggk",
            "kgggggkkkkkgggkggkggk",
            "kkkkkkkgmgkgggkggkggk",
            "kgggggggggkgggkggkggk",
            "kgggggggggkgggkggkggk",
            "kggkkkkkkkkgggkggkggk",
            "kggggggggggggggggkggk",
            "kggggggmgggggggmggggk",
            "kgggggggggggggggggggk",
            "kmgkkkkkkkkkkkkkkkkkk"
        };

        void draw_map(RenderWindow &window);

    public:
        Map();
        Player* get_player();

        void draw(RenderWindow &window);
        void update();
};

