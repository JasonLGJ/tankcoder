#include "Game.h"

void Game::update() {

	if (state == GAME_STATE_MENU)
	{
		menu->update();

		if (menu->shouldPlay())
		{
			state = GAME_STATE_PLAY;
			world->initGrid("leveltest.json");
			menu->load("editor.json");
		}
		else if (menu->shouldQuit())
		{
			running = false;
		}

	}
	else if (state == GAME_STATE_PLAY)
	{
		world->update();
		menu->update();

		if (!menu->shouldPlay())
			state = GAME_STATE_MENU;
	}
}