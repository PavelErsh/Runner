#include "key_press.h"
#include "constants.cpp"

void  Key_press::check_frame(int max_frame)
{
	if( player->current_frame > max_frame)
	{
		player->current_frame -= max_frame;
	}
}

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
        player->set_speed(Vector2f(0, 0));
    }
}

void Key_press::animation(){
    Clock clock;
    float time = clock.getElapsedTime().asMicroseconds();
    clock.restart();

    if(Keyboard::isKeyPressed(Keyboard::Right)){
        player->current_frame = player->current_frame + 0.2 * time; 
        check_frame(6);
        player->set_text_rect(IntRect(int(player->current_frame) * 200, 4*200, 200, 200));
     }

    if(Keyboard::isKeyPressed(Keyboard::Left)){
        player->current_frame = player->current_frame + 0.2 * time; 
        check_frame(6);
        player->set_text_rect(IntRect(int(player->current_frame) * 200, 4*200, -200, 200));
     }

}