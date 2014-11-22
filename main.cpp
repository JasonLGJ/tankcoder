#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "Game.h"

int main(int argc, char* argv[]) {
	//PlaySound("C:/Users/pepe/Documents/Visual Studio 2013/Projects/tankcoder/tankcoder/assets/games1.wav", NULL, SND_ASYNC);
	Game g;
	return g.execute();

}
