#include "map.h"
#include "constants.cpp"

#include <iostream>
using namespace std;

using namespace sf;

Map::Map(){
   
    player = new Player("images/cyborg.png", 200, 200, 0, 0);//w, h

 }

void Map::update(){
    player->update();
    for (auto it = entities.begin(); it != entities.end();it++)
    {
        FloatRect playerCollider = player->get_sprite().getGlobalBounds(); 
        FloatRect otherCollider = (*it)->get_sprite().getGlobalBounds(); 
        if (playerCollider.intersects(otherCollider) && (*it)->get_name() == "c") {
            entities.erase(it++);
            cout << "work" << endl;
        }
        
    }
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
                Coin* coin = new Coin("images/coin.png", 32, 32,  Vector2f (column * 60, row * 60), 0, 0);
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
      /*for (auto v : entities){
        window.draw( v->get_sprite() );
      }*/
}

void Map::draw(RenderWindow &window){
   
    draw_map(window);
    window.draw(player->get_sprite());
}


//?????