#include "player.h"
#include "map.h"
#include "constants.cpp"
#include <algorithm> 

using namespace sf;

Player::Player(String player_img, int frame_width, int frame_height, int start_row, int start_column) 
: Entity (player_img, frame_width,  frame_height, start_row, start_column){	

	set_position( Vector2f(0, 0) );

	set_name("Player");
}



void Player::stop_map_moving(){

	if (position.x > RIGHT_BORDER + frame_widht ){
		position.x = RIGHT_BORDER + frame_widht;
	}

	if (position.x < 0 + frame_widht / 2 ){
		position.x = 0 + frame_widht / 2;
	}

	if (position.y < 0 ){
		position.y = 0;
	}

	if (position.y > DOWN_BORDER ){
		position.y = DOWN_BORDER ;
	}

}




