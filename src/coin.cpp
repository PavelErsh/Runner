#include "coin.h"

Coin::Coin(Vector2f position){
    init();
    set_position(position);
}

void Coin::init(){
    Image image;
    image.loadFromFile("images/coin.png");
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}

void Coin::set_position(Vector2f position){
    this->position = position;
    sprite.setPosition(position.x, position.y);
}

void Coin::set_texture_rect(IntRect rect){
    sprite.setTextureRect(rect);
}

void Coin::set_width(int widht){
    frame_width = widht;
}

void Coin::set_height(int height){
    frame_height = height;
}

int Coin::get_width(){
    return frame_width;
}

int Coin::get_height(){
    return frame_height;
}

Sprite Coin::get_sprite(){
    return sprite;
}