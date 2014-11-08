#pragma once

#include "MenuItem.h"

class MenuButton : public MenuItem {
	public:
		MenuButton();
		void mouse_moved(float px, float py, bool pressed);
		MenuEvent event;
	private:
		bool inside(float px, float py);
};
