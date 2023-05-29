#include "map.h"
#include "constants.cpp"

using namespace sf;

Map::Map(){
   
    player = new Player("images/cyborg.png", 200, 200, 0, 0);//w, h

 }

void Map::update(){
    player->update();
}

Player* Map::get_player(){
    return player;
}

void Map::draw_map(RenderWindow &window){
    for(int row = 0; row < HEIGHT_MAP; row++){
        for(int column = 0; column < WIDTH_MAP; column++){
            
            if(tile_map[row][column] == 'm'){
                 Floor* floor = new Floor("images/floor.png", 60, 60,  Vector2f (column * 60, row * 60));
                entities.push_back(floor);
                Coin* coin = new Coin("images/coin.png", 32, 32,  Vector2f (column * 60, row * 60));
                entities.push_back(coin);
               
            }

            if(tile_map[row][column] == 'g'){
                Floor* floor = new Floor("images/floor.png", 60, 60,  Vector2f (column * 60, row * 60));
                entities.push_back(floor);
            }

            if(tile_map[row][column] == 'k'){
                Wall* wall = new Wall("images/brick.png", 60, 60,  Vector2f (column * 60, row * 60));
                entities.push_back(wall);
            }
        }
    }

    for (auto it = entities.begin(); it != entities.end();it++) {
            window.draw((*it)->get_sprite());
        }
}

void Map::draw(RenderWindow &window){
   
    draw_map(window);
    window.draw(player->get_sprite());
 }