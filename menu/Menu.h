#pragma once

#include <string>
#include <stack>
#include <memory>
#include <vector>

#include "../utils/assets/Loader.h"
#include "../utils/scene/SceneManager.h"
#include "MenuButton.h"

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
	private:
		bool pressed;
		std::stack<MenuEvent> events;
		std::shared_ptr<Loader> loader;
		std::shared_ptr<SceneManager> scene;
		std::vector<std::shared_ptr<MenuItem>> items;
};
