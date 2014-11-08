#pragma once

#include <stack>
#include <memory>
#include "MenuEvents.h"
#include "../utils/scene/FlatNode.h"

enum menuItemType {
	MENU_TYPE_ITEM,
	MENU_TYPE_BUTTON,
	MENU_TYPE_IMAGE
};

class MenuItem {
	public:
		MenuItem();
		void addNode(std::shared_ptr<FlatNode> n);
		void addStack(std::stack<MenuEvent>* e);
		virtual void mouse_moved(float x, float y, bool pressed);
		std::shared_ptr<FlatNode> node;
		std::stack<MenuEvent>* events;
};
