#include "floor.h"

Floor::Floor(String player_img, int frame_width, int frame_height, Vector2f position, int start_row , int start_column)
:  Entity (player_img, frame_width,  frame_height, start_row, start_column){
    set_position(position);
    set_name("Floor");
}