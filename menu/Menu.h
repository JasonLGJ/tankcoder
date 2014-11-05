#pragma once

#include <string>
#include <stack>
#include <memory>
#include <vector>
#include "MenuButton.h"

class Menu {
	public:
		Menu();
		void load(std::string filename);
		void moved(float x, float y);
		void pressed();
		void released();
		void update();
	private:
		std::stack<MenuEvent> events;
		std::shared_ptr<Loader> loader;
		std::vector<std::shared_ptr<MenuItem>> item;
};
