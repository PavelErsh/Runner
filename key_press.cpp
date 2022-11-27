#include "key_press.h"

Key_press::Key_press(){

}

void Key_press::set_player(Player* player){
    this->player = player;
}

void Key_press::action(){
    Clock clock;
    float time = clock.getElapsedTime().asMicroseconds();
    clock.restart();

    if(Keyboard::isKeyPressed(Keyboard::Right)){
        player->set_speed(Vector2f(0.1 * time, 0));
    }

    else if(Keyboard::isKeyPressed(Keyboard::Left)){
        player->set_speed(Vector2f(-0.1, 0));
    }

    else if (Keyboard::isKeyPressed(Keyboard::Up)){
        player->set_speed(Vector2f(0, -0.1 * time ));
    }

    else if(Keyboard::isKeyPressed(Keyboard::Down)){
        player->set_speed(Vector2f(0, 0.1 * time));
    }

    else{
        player->set_speed(Vector2f(0, 0));
    }
}