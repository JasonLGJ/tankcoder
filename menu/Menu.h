#pragma once

#include <string>
#include <stack>
#include <memory>
#include <vector>

#include "../utils/assets/Loader.h"
#include "../utils/scene/SceneManager.h"
#include "MenuButton.h"
#include "MenuDrag.h"
#include "MenuList.h"

enum menu_actions {
	MENU_ACTION_EDITOR,
	MENU_ACTION_BEGIN,
	MENU_ACTION_PLAYING,
	MENU_ACTION_PAUSED,
	MENU_ACTION_RESUME,
	MENU_ACTION_RESTART
};

class Menu {
	public:
		Menu();
		void init(std::shared_ptr<Loader> l, std::shared_ptr<SceneManager> s);
		void load(std::string filename, std::string menuname = "");
		void mouse_moved(float x, float y);
		void mouse_pressed();
		void mouse_released();
		void create_menu(std::shared_ptr<Resource> menu);
		void create_item(std::shared_ptr<Resource> item);
		void process_event(MenuEvent event);
		void update();
		void clean();
		bool shouldStartGame();
		bool shouldQuit();
		std::string getParam();
		int getMenuOption();
		void setMenuOption(int opt);
		void passEditor(Editor* edit);
	private:
		bool start_game;
		bool pressed;
		bool quit_requested;
		int menu_action;
		std::string event_param;
		std::stack<MenuEvent> events;
		std::shared_ptr<Loader> loader;
		std::shared_ptr<SceneManager> scene;
		std::vector<std::shared_ptr<MenuItem>> items;
		std::shared_ptr<MenuList> editor;
};
