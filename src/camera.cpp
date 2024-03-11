#include "constants.cpp"
#include "camera.h"
//
using namespace sf;

Camera::Camera(Player* player){
    this->player = player;
    view.reset(FloatRect(0, 0, 900, 600));
}

void Camera::setCenter(){
    short player_x = player->get_position().x;
    short player_y = player->get_position().y;

    if(player_x < LEFT_BORDER){
        player_x = LEFT_BORDER;
    }

    if(player_x > RIGHT_BORDER){
        player_x = RIGHT_BORDER;
    }

    if(player_y < UP_BORDER){
        player_y = UP_BORDER;
    }

    if(player_y > DOWN_BORDER){
        player_y = DOWN_BORDER;
    }

    view.setCenter(player_x, player_y);
}

void Camera::update(){
    setCenter();
}

View Camera::getView(){
    return view;
}
