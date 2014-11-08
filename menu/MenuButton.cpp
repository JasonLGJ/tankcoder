#include "MenuButton.h"

MenuButton::MenuButton() {}

void MenuButton::mouse_moved(float px, float py, bool pressed) {
	if (inside(px, py))
	{
		if (pressed)
		{
			events->push(event);
		}
		else //hover
		{

		}
	}
	else //nothing
	{

	}
}

bool MenuButton::inside(float px, float py) {
	if (px < node->getX() || px > node->getX() + node->getWidth())
		return false;

	if (py < node->getY() || py > node->getY() + node->getHeight())
		return false;

	return true;
}
