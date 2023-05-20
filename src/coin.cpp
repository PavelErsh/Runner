#include "coin.h"

Coin::Coin(String player_img, int frame_width, int frame_height, Vector2f position, int start_row = 0, int start_column = 0) : Entity(player_img, frame_width,  frame_height, start_row, start_column){

    set_position(position);
}


