#include "key_press.h"
#include "constants.cpp"

void Key_press::set_player(Player* player){
    this->player = player;
}

void Key_press::action(){
    Clock clock;
    float time = clock.getElapsedTime().asMicroseconds();
    clock.restart();

    if(Keyboard::isKeyPressed(Keyboard::Right)){
        player->set_speed(Vector2f(PLAYER_SPEED * time, NULL));
    }

    else if(Keyboard::isKeyPressed(Keyboard::Left)){
        player->set_speed(Vector2f(-PLAYER_SPEED * time, NULL));
    }

    else if (Keyboard::isKeyPressed(Keyboard::Up)){
        player->set_speed(Vector2f(NULL, -PLAYER_SPEED  * time ));
    }

    else if(Keyboard::isKeyPressed(Keyboard::Down)){
        player->set_speed(Vector2f(NULL, PLAYER_SPEED * time));
    }

    else{
        player->set_speed(Vector2f(NULL, NULL));
    }
}

void Key_press::animation(){
    if(Keyboard::isKeyPressed(Keyboard::Right)){
       player->next_frame( 4, 6, false);
    }

    if(Keyboard::isKeyPressed(Keyboard::Left)){
        player->next_frame(4, 6, true);
    }
}