#include "MenuDrag.h"

MenuDrag::MenuDrag() {
	dragging = false;
	mouse_x = mouse_y = 0.0f;
	original_x = original_y = 0.0f;
}

void MenuDrag::mouse_moved(float px, float py, bool pressed) {
	if (dragging)
	{
		if (pressed)
		{
			float nx = original_x - (mouse_x - px);
			float ny = original_y - (mouse_y - py);

			node->setX(nx);
			node->setY(ny);
		}
		else
		{
			dragging = false;
			events->push(event);
			
			node->setX(original_x);
			node->setY(original_y);
		}

		node->getTexture()->changeTexture(2);
	}
	else
	{
		if (inside(px,py) && pressed)
		{
			dragging = true;
			original_x = node->getX();
			original_y = node->getY();
			
			mouse_x = px;
			mouse_y = py;

			node->getTexture()->changeTexture(1);
		}
		else
		{
			node->getTexture()->changeTexture(0);
		}
	}
}

bool MenuDrag::inside(float px, float py) {
	if (px < node->getX() || px > node->getX() + node->getWidth())
		return false;

	if (py < node->getY() || py > node->getY() + node->getHeight())
		return false;

	return true;
}
