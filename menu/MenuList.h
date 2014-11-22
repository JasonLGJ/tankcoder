#pragma once

#include <vector>
#include "MenuItem.h"
#include "MenuRow.h"
#include "../utils/scene/SceneManager.h"
#include "../editor/Editor.h"

const int MAX_DISPLAY_ITEMS = 9;

class MenuList : public MenuItem {
	public:
		MenuList();
		void init(std::shared_ptr<SceneManager> s);
		void checkInput(std::string operation, float x, float y);
		std::vector<MenuRow> getRows();
		void checkVisible();
		void reposition();
		void scroll(int direction);
		void save();
		void setEdit(Editor* edit);
	private:
		Editor* editor;
		int offsetx;
		int offsety;
		bool is_conditional(std::string operation);
		bool is_end_cond(std::string operation);
		bool inside(float px, float py);
		std::vector<MenuRow> rows;
		std::shared_ptr<SceneManager> scene;
};