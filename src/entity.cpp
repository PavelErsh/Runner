#include "player.h"
#include "map.h"
#include "constants.cpp"
#include <algorithm> 


using namespace sf;

Entity ::Entity (String player_img, int frame_width, int frame_height, int start_row = 0, int start_column = 0){	

	this->frame_widht = frame_width;
	this->frame_height = frame_height;

	Image image;
	image.loadFromFile(player_img);

	texture.loadFromImage(image);

	sprite.setTexture(texture);	
	
	set_texture_rect(IntRect(start_row, start_column, frame_width, frame_height));

	set_position( Vector2f(0, 0) );
}

void  Entity ::check_frame(int max_frame, bool is_filp){
	
	if(current_frame > max_frame and is_filp == false){
		current_frame -= max_frame;
	}
	
	if(current_frame > max_frame and is_filp == true){
		current_frame = 1;
	}
}

void Entity ::next_frame(int frame_row, int max_frame, bool is_fleep){

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

Vector2f Entity ::get_position(){
	return sprite.getPosition();
}

float Entity ::get_time(){
	float time = clock.getElapsedTime().asMicroseconds();
	time /= 1000;
	clock.restart();

	return time;
}

void Entity::set_position(Vector2f position){
	sprite.setPosition(position.x, position.y);
}

Sprite Entity ::get_sprite(){
	return sprite;
}

void Entity ::set_texture_rect(IntRect rect){
	sprite.setTextureRect(rect);
}

void Entity ::set_speed(Vector2f speed){
	this->speed = speed * get_time();
}

void Entity::set_name(String name){
	this->name = name;
}

Vector2f Entity ::get_speed(){
	return speed;
}

void Entity ::update(){
	sprite.move(speed.x, speed.y);
	position = sprite.getPosition();
}

int Entity::get_widht(){
	return frame_widht;
}

int Entity::get_height(){
	return frame_height;
}

String Entity::get_name(){
	return name;
}


