#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"

class Key_press{
    private:
        Player* player;
    public:
        Key_press();

        void set_player(Player* player);
        void action();
};
