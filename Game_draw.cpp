#include "Game.h"

void Game::draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	scene.drawAll();

	SDL_GL_SwapWindow(window);
}