#include "Game.h"

void Game::event(SDL_Event* e) {
	while(SDL_PollEvent(e) != 0)
	{ 
		switch (e->type)
		{
			case SDL_QUIT:
				running = false;
				break;

			case SDL_MOUSEMOTION:
				{
					int x, y;
					SDL_GetMouseState(&x,&y);
					menu->mouse_moved(x / GL_SCALE, (DEFAULT_HEIGHT - y) / GL_SCALE);
				}
				break;

			case SDL_MOUSEBUTTONDOWN:
				{
					int x, y;
					SDL_GetMouseState(&x, &y);
					menu->mouse_pressed();
					menu->mouse_moved(x / GL_SCALE, (DEFAULT_HEIGHT - y) / GL_SCALE);
				}
				break;

			case SDL_MOUSEBUTTONUP:
				{
					int x, y;
					SDL_GetMouseState(&x, &y);
					menu->mouse_released();
					menu->mouse_moved(x / GL_SCALE, (DEFAULT_HEIGHT - y) / GL_SCALE);
				}
				break;
		}
		
		
		if( e->type == SDL_QUIT ) 
		{ 
			running = false; 
		}
		
	}
}