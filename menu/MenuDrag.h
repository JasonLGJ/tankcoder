#pragma once
#include "MenuItem.h"

class MenuDrag : public MenuItem {
	public:
		MenuDrag();
		void mouse_moved(float px, float py, bool pressed);
		MenuEvent event;
	private:
		bool inside(float px, float py);
		bool dragging;
		bool in_drag;
		float original_x;
		float original_y;
		float mouse_x;
		float mouse_y;
};
