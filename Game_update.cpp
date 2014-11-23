#include "Game.h"


void Game::update() {

	if (state == GAME_STATE_MENU)
	{
		menu->update();

		loader->getSound("assets/sounds/menu.mp3", SOUND_TYPE_MUSIC)->play();

		if (menu->shouldStartGame())
		{
			state = GAME_STATE_PLAY;
			world->initGrid("assets/game/levels.json", menu->getParam());
			menu->passEditor(world->getEditor());
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
		if (menu->musica)
		loader->getSound("assets/sounds/game.mp3", SOUND_TYPE_MUSIC)->play();

		switch (menu->getMenuOption())
		{
			case MENU_ACTION_EDITOR:
			case MENU_ACTION_PLAYING:
			default:
				break;

			case MENU_ACTION_BEGIN:
				world->initProgs("assets/progs/test.tc");
				world->set_pause(false);
				menu->setMenuOption(MENU_ACTION_PLAYING);
				break;

			case MENU_ACTION_PAUSED:
				world->set_pause(true);
				break;

			case MENU_ACTION_RESUME:
				world->set_pause(false);
				break;

			case MENU_ACTION_RESTART:
				world->restart();
				menu->passEditor(world->getEditor());
				menu->setMenuOption(MENU_ACTION_EDITOR);
				break;
		}

		if (!menu->shouldStartGame())
		{
			world->reset();
			menu->setMenuOption(MENU_ACTION_EDITOR);
			state = GAME_STATE_MENU;
		}
	}
}
