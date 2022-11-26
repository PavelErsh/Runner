#include "key_press.h"

Key_press::Key_press(){

}

void Key_press::set_player(Player* player){
    this->player = player;
}

void Key_press::action(){
    if(Keyboard::isKeyPressed(Keyboard::Right)){
        player->set_speed(Vector2f(0.1, 0));
    }

    else{
        player->set_speed(Vector2f(0, 0));
    }
}