/*
	Add copyright and lisence here.
*/

#include <iostream>
#include <SDL.h>

int main(int argc, char* args[]) {
	std::cout << "Hello World!\n";

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("Could not init SDL %s\n", SDL_GetError());
		return 1;
	} else {
		std::cout << "SDL here, good to go...\n";
	};

	return 0;
}
