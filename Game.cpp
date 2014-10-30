#include "Game.h"

#include <iostream>

Game::Game() {}

int Game::execute() {
	if (!init())
	{
		int x;
		std::cin >> x;
		return -1;
	}

	//TODO
	running = true;

	int ticks = SDL_GetTicks();
	int loops;
	int fps = 0;

	std::string title = "Windjammers";

	while(running)
	{
		loops = 0;
		while (SDL_GetTicks() > ticks && loops < MAX_SKIP)
		{
			event(&ev);
			update();

			ticks += SKIP_TICKS;
			loops++;
		}

		//window
		draw();
	}

	cleanUp();

	return 0;
}

void Game::cleanUp() {
	SDL_DestroyWindow(window);

	IMG_Quit();
	SDL_Quit();
}