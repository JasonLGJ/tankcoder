#pragma once

#include <vector>
#include "MenuItem.h"
#include "MenuRow.h"
#include "../utils/scene/SceneManager.h"

const int MAX_DISPLAY_ITEMS = 10;

class MenuList : public MenuItem {
	public:
		MenuList();
		void init(std::shared_ptr<SceneManager> s);
		void checkInput(std::string operation, float x, float y);
		std::vector<MenuRow> getRows();
	private:
		bool inside(float px, float py);
		std::vector<MenuRow> rows;
		std::shared_ptr<SceneManager> scene;
};