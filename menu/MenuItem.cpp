#include "MenuItem.h"

MenuItem::MenuItem() {}

void MenuItem::addNode(std::shared_ptr<FlatNode> n) {
	node = n;
}
