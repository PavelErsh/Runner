#pragma once

#include <SFML/Graphics.hpp>
#include "entity.h"

using namespace sf;

class Wall : public Entity{
    public:
        Wall(String player_img, int frame_width, int frame_height, Vector2f position, int start_row = 0, int start_column = 0);
};