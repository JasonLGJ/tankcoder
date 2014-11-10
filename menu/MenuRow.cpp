#include "MenuRow.h"

MenuRow::MenuRow(std::string op) {
	operation = op;
}

bool MenuRow::inside(float y) {
	if (y < node->getY())
		return false;

	if (y > node->getY() + node->getHeight())
		return false;

	return true;
}

float MenuRow::getY() {
	return node->getY();
}