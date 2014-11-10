#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "Game.h"
#include <iostream>

int main(int argc, char* argv[]) {
	Game g;
	return g.execute();
}
