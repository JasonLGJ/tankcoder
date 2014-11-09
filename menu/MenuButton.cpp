#include "MenuButton.h"

MenuButton::MenuButton() {}

void MenuButton::mouse_moved(float px, float py, bool pressed) {
	if (inside(px, py))
	{
		if (pressed)
		{
			events->push(event);
			node->getTexture()->changeTexture(2);
		}
		else //hover
		{
			node->getTexture()->changeTexture(1);
		}
	}
	else //nothing
	{
		node->getTexture()->changeTexture(0);
	}
}

bool MenuButton::inside(float px, float py) {
	if (px < node->getX() || px > node->getX() + node->getWidth())
		return false;

	if (py < node->getY() || py > node->getY() + node->getHeight())
		return false;

	return true;
}
