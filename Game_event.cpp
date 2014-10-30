#include "Game.h"

void Game::event(SDL_Event* e) {
	while(SDL_PollEvent(e) != 0)
	{ 
		if( e->type == SDL_QUIT ) 
		{ 
			running = false; 
		} 
	}
}