#include "Tank.h"

Tank::Tank() {
	direction = TANK_DIRECTION_UP;
	x = y = 0;
	alive = true;
}


Tank::Tank(int dir, int x, int y) {
	direction = dir;
}

void Tank::turnLeft() {
	direction++;

	if (direction > TANK_DIRECTION_RIGHT_UP)
		direction = TANK_DIRECTION_UP;
}

void Tank::turnRight() {
	direction--;

	if (direction < TANK_DIRECTION_UP)
		direction = TANK_DIRECTION_RIGHT_UP;
}

void Tank::goForward() {
	switch(direction)
	{
		case TANK_DIRECTION_UP:
			y--;
			break;

		case TANK_DIRECTION_LEFT_UP:
			x--;
			break;

		case TANK_DIRECTION_LEFT_DOWN:
			x--;
			y++;
			break;

		case TANK_DIRECTION_DOWN:
			y++;
			break;

		case TANK_DIRECTION_RIGHT_DOWN:
			x++;
			break;

		case TANK_DIRECTION_RIGHT_UP:
			y--;
			x++;
			break;

		default:
			break;
	}

	if (x >= grid->getWidth())
		x = grid->getWidth() -1;
	else if (x < 0)
		x = 0;
		
	if (y >= grid->getHeight())
		y = grid->getHeight() -1;
	else if (y < 0)
		y = 0;
}

void  Tank::shoot() {
}

int Tank::getX() {
	return x;
}

int Tank::getY() {
	return y;
}

int Tank::getDirection() {
	return direction;
}

bool Tank::isAlive() {
	return alive;
}


void Tank::setPosition(int x, int y) {
	this->x = x;
	this->y = y;
}

void Tank::setGrid(Grid* g) {
	grid = g;
}
