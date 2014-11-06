#pragma once

#include "MenuItem.h"

class MenuButton : public MenuItem {
	public:
		MenuButton();
		bool inside(float px, float py);
		std::string text;
};
