#include "map.h"

using namespace sf;

const int ITEM_WIDTH = 134;
const int ITEM_HEIGHT = 133;

 Map::Map(){
    map_image.loadFromFile("images/map1.png");
    map_texture.loadFromImage(map_image);
    map_sprite.setTexture(map_texture);
    player = new Player("images/cyborg.png", 200, 200, 0, 0);
 }
void Map::update(){
    player->update();
}
Player* Map::get_player(){
    return player;
}
 void Map::draw(RenderWindow &window){
   
    for(int row = 0; row < HEIGHT_MAP; row++){
        for(int column = 0; column < WIDTH_MAP; column++){
            
            if(tile_map[row][column] == 's'){
                map_sprite.setTextureRect(IntRect(0, 0, ITEM_WIDTH, ITEM_HEIGHT));
            }

            if(tile_map[row][column] == 'g'){
                map_sprite.setTextureRect(IntRect(ITEM_WIDTH * 1, ITEM_HEIGHT* 0, ITEM_WIDTH, ITEM_HEIGHT));
            }

            map_sprite.setPosition(column * ITEM_WIDTH, row * ITEM_HEIGHT);
            window.draw(map_sprite);
        }
    }
    window.draw(player->get_sprite());
 }