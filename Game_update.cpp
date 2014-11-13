#include "Game.h"

void Game::update() {

	if (state == GAME_STATE_MENU)
	{
		menu->update();

		if (menu->shouldStartGame())
		{
			state = GAME_STATE_PLAY;
			world->initGrid("assets/game/levels.json", menu->getParam());
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
		
		switch (menu->getMenuOption())
		{
			case MENU_ACTION_EDITOR:
			case MENU_ACTION_PLAYING:
			default:
				break;

			case MENU_ACTION_BEGIN:
				world->initProgs("", menu->getParam());
				world->set_pause(false);
				break;

			case MENU_ACTION_PAUSED:
				world->set_pause(true);
				break;

			case MENU_ACTION_RESUME:
				world->set_pause(false);
				break;

			case MENU_ACTION_RESTART:
				world->restart();
				break;
		}

		if (!menu->shouldStartGame())
		{
			world->reset();
			state = GAME_STATE_MENU;
		}
	}
}