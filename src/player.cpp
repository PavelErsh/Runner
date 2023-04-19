#include "player.h"
#include "map.h"
#include "constants.cpp"

using namespace sf;

Player::Player(String player_img, int frame_width, int frame_height, int start_row, int start_column){	

	this->frame_widht = frame_width;
	this->frame_height = frame_height;

	Image image;
	image.loadFromFile(player_img);

	texture.loadFromImage(image);

	sprite.setTexture(texture);	
	
	set_texture_rect(IntRect(start_row, start_column, frame_width, frame_height));

	set_position( Vector2f(0, 0) );
}

void  Player::check_frame(int max_frame, bool is_filp){
	
	if(current_frame > max_frame and is_filp == false){
		current_frame -= max_frame;
	}
	
	if(current_frame > max_frame and is_filp == true){
		current_frame = 1;
	}
}

void Player::next_frame(int frame_row, int max_frame, bool is_fleep){

    current_frame += FRAME_SPEED * get_time(); 

	if (is_fleep == false){
		check_frame(max_frame, false);
        set_texture_rect(IntRect( int(current_frame) * frame_widht, frame_height * frame_row, frame_widht, frame_height));
	}

	if (is_fleep == true){
		check_frame(max_frame + 1, true);
		set_texture_rect(IntRect( int(current_frame) * frame_widht, frame_height * frame_row, -frame_widht, frame_height));
	}
}

Vector2f Player::get_position(){
	return sprite.getPosition();
}

float Player::get_time(){
	float time = clock.getElapsedTime().asMicroseconds();
	time /= 1000;
	clock.restart();

	return time;
}

void Player::set_position(Vector2f position){
	sprite.setPosition(position.x, position.y);
}

Sprite Player::get_sprite(){
	return sprite;
}

void Player::set_texture_rect(IntRect rect){
	sprite.setTextureRect(rect);
}

void Player::set_speed(Vector2f speed){
	this->speed = speed * get_time();
}

Vector2f Player::get_speed(){
	return speed;
}

void Player::update(){
	sprite.move(speed.x, speed.y);
	position = sprite.getPosition();
	stop_map_moving();
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

	set_position(Vector2f(position.x, position.y));
}

int Player::get_widht(){
	return frame_widht;
}

int Player::get_height(){
	return frame_height;
}


