#pragma once

#include <SFML/Graphics.hpp>
#include "entity.h"

using namespace sf;

class Coin : public Entity{
    

    public:
        Coin(String player_img, int frame_width, int frame_height, Vector2f position, int start_row, int start_column);

};