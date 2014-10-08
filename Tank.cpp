#include "Tank.h"

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
			y++;
			x++;
			break;

		case TANK_DIRECTION_RIGHT_UP:
			x++;
			break;

		default:
			break;
	}
}

void Tank::shoot() {
	shooting = true;
}
