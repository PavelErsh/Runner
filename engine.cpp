#include "engine.h"

using namespace sf;

Engine::Engine(){
}

void Engine::init(int width = 500, int height = 500, String title = "Game"){
	window.create(VideoMode(width, height), title);
}

void Engine::loop(){
	while(window.isOpen()){
		Event event;

		while(window.pollEvent(event)){
			if (event.type == Event::Closed){
				window.close();
			}
		}
	}
}
