#include "engine.h"
#include <thread>

using namespace sf;

Engine::Engine(){
}

void Engine::init(int width = 500, int height = 500, String title = "Game"){
	window.create(VideoMode(width, height), title);
	key_press.set_player(map.get_player());
	camera = new Camera(map.get_player());
}

void Engine::loop(){
	while(window.isOpen()){
		Event event;

		while(window.pollEvent(event)){
			if (event.type == Event::Closed){
				window.close();
			}
		}
		draw();
		update();
	}
}

void Engine::draw(){
	window.clear(Color());
	window.setView(camera->getView());
	map.draw(window);
	window.display();
}

void Engine::update(){

	key_press.action();
	key_press.animation();

	map.update();
	camera->update();
}
