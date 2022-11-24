#include "map.h"
using namespace sf;

 Map::Map(){
    map_image.loadFromFile("images/textures.jpg");
    map_texture.loadFromImage(map_image);
    map_sprite.setTexture(map_texture);
 }

 void Map::draw(RenderWindow &window){
    for(int row = 0; row < HEIGHT_MAP; row++){
        for(int column = 0; column < WIDTH_MAP; column++){
            
            if(tile_map[row][column] == 's'){
                map_sprite.setTextureRect(IntRect(0, 0, 60, 60));
            }

            if(tile_map[row][column] == 'g'){
                map_sprite.setTextureRect(IntRect(60 * 0, 60 * 1, 60, 60));
            }

            map_sprite.setPosition(row * 60, column * 60);
            window.draw(map_sprite);
        }
    }
    window.draw(player.get_sprite());
 }