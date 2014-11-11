#pragma once

#include <iostream>
#include "MenuItem.h"

class MenuRow : public MenuItem {
	public:
		MenuRow(std::string op);
		bool inside(float y);
		float getY();
		std::string getOperation();
	private:
		std::string operation;
};