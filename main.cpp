#include "engine.h"
#include "constants.cpp"

using namespace sf;

int main(){
	Engine window;

	window.init(WINDOW_WIDHT, WINDOW_HEIGHT, TITLE);

	window.loop();
}
