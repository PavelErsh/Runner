#include "player.h"
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
	
	if(current_frame > max_frame and is_filp == false)
	{
		current_frame -= max_frame;
	}
	
	if(current_frame > max_frame and is_filp == true)
	{
		current_frame = 1;
	}
}

void Player::next_frame(int frame_row, int max_frame, bool is_fleep){
	Clock clock;
    float time = clock.getElapsedTime().asMicroseconds();
    clock.restart();

	current_frame += FRAME_SPEED * time; 

	if (is_fleep == false){
		check_frame(max_frame, false);
    	set_texture_rect(IntRect(int(current_frame) * frame_widht, frame_row * frame_height, frame_widht, frame_height));
	}

	if (is_fleep == true){
		check_frame(max_frame, true);
		set_texture_rect(IntRect(int(current_frame) * frame_widht, frame_row * frame_height, -frame_widht, frame_height));
	}
}

Vector2f Player::get_position(){
	return sprite.getPosition();
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
	this->speed = speed;
}

Vector2f Player::get_speed(){
	return speed;
}

void Player::update(){
	sprite.move(speed.x, speed.y);
	position = sprite.getPosition();
}


