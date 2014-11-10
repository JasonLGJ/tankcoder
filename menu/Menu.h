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
		bool shouldPlay();
		bool shouldQuit();
	private:
		bool start_playing;
		bool pressed;
		bool quit_requested;
		std::stack<MenuEvent> events;
		std::shared_ptr<Loader> loader;
		std::shared_ptr<SceneManager> scene;
		std::vector<std::shared_ptr<MenuItem>> items;
		std::shared_ptr<MenuList> editor;
};
