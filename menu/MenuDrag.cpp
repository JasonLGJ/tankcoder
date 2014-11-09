#include "MenuDrag.h"

MenuDrag::MenuDrag() {}

void MenuDrag::mouse_moved(float px, float py, bool pressed) {
	float pdx = 0.0;
	float pdy = 0.0;
	float newx = 0.0;
	float newy = 0.0;
	float x = 0.0;
	float y = 0.0;
	bool dragging = false;
	
	if (dragging) //dragging
	{
		if (pressed) //moviendo
		{
			float nx = node->getX() + pdx - px;
			float ny = node->getY() + pdy - py;

			node->setX(nx);
			node->setY(ny);
			//actualiza posicion
		}
		else
		{
			dragging = false;//released
			events->push(event);//genera evento
			
			node->setX(x);
			node->setY(y);
			//regresa a su posicion original
		}
	}
	else //aun no lo esta drageando
	{
		if (inside(px,py) && pressed) //adentro
		{
			dragging = true;//comenzar a dragear
			x = node->getX();
			y = node->getY();
			//guardar posicion original
			pdx = px;
			pdy = py;
			//guardar posicion del mouse
		}
		else
		{
			//poner terxtura de estado normal
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
