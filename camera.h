#pragma once

#include<SFML/Graphics.hpp>
#include "player.h"

class Camera{
    private:
        View view;
        Player* player;

        void setCenter();

    public:
        Camera(Player* player);
        void update();
        View getView();
};