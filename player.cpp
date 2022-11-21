#include "player.h"

using namespace sf;

Player::Player(String player_img, int width = 10, int height = 10, int start_row = 0, int start_column = 0){	
	Image image;
	image.loadFromFile(player_img);

	texture.loadFromImage(image);

	sprite.setTexture(texture);	

	set_text_rect(IntRect(start_row, start_column, width, height));

	set_position( Vector2f(0, 0) );
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

void Player::set_text_rect(IntRect rect){
	sprite.setTextureRect(rect);
}


