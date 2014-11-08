#include "MenuItem.h"

MenuItem::MenuItem() {}

void MenuItem::addNode(std::shared_ptr<FlatNode> n) {
	node = n;
}

void MenuItem::addStack(std::stack<MenuEvent>* e) {
	events = e;
}

void MenuItem::mouse_moved(float x, float y, bool pressed) {}