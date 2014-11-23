#include "Tank.h"

Tank::Tank() {
	direction = TANK_DIRECTION_LEFT;
	x = y = 0;
	id = 0;
	alive = false;
}

void Tank::init(int i, int dir) {
	id = i;
	direction = dir;

	validateRotation();
}

void Tank::setNode(std::shared_ptr<StaticNode> n) {
	node = n;
}

void Tank::setAlive(bool a) {
	alive = a;
}

bool* Tank::obtainAlive() {
	return &alive;
}

void Tank::turnLeft() {
	direction++;

	if (direction > TANK_DIRECTION_LEFT_UP)
		direction = TANK_DIRECTION_LEFT;

	validateRotation();
}

void Tank::turnRight() {
	direction--;

	if (direction < TANK_DIRECTION_LEFT)
		direction = TANK_DIRECTION_LEFT_UP;

	validateRotation();
}

void Tank::goForward() {
	int or_x = x;
	int or_y = y;

	switch(direction)
	{
		case TANK_DIRECTION_LEFT:
			x--;
			break;

		case TANK_DIRECTION_LEFT_DOWN:
			if (y % 2 == 0)
			{
				y++;
			}
			else
			{
				x--;
				y++;
			}
			break;

		case TANK_DIRECTION_RIGHT_DOWN:
			if (y % 2 == 0)
			{
				x++;
				y++;
			}
			else
			{
				y++;
			}
			break;

		case TANK_DIRECTION_RIGHT:
			x++;
			break;

		case TANK_DIRECTION_RIGHT_UP:
			if (y % 2 == 0)
			{
				x++;
				y--;
			}
			else
			{
				y--;
			}
			break;

		case TANK_DIRECTION_LEFT_UP:
			if (y % 2 == 0)
			{
				y--;
			}
			else
			{
				x--;
				y--;
			}
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

	if (grid->is_obstacle(x, y))
	{
		x = or_x;
		y = or_y;
	}

	if (id == 0)
	{
		int ex, ey;
		grid->findEnemy(ex, ey);

		if (x == ex && y == ey)
		{
			x = or_x;
			y = or_y;
		}

		grid->update_player(x, y);
	}
	else
	{
		int px, py;
		grid->findPlayer(px, py);

		if (x == px && y == py)
		{
			x = or_x;
			y = or_y;
		}

		grid->update_enemy(x, y);
	}

	validatePosition();
}

void Tank::goBackward() {
	int or_x = x;
	int or_y = y;

	switch (direction)
	{
		case TANK_DIRECTION_LEFT:
			x++;
			break;

		case TANK_DIRECTION_LEFT_DOWN:
			if (y % 2 == 0)
			{
				x++;
				y--;
			}
			else
			{
				y--;
			}
			break;

		case TANK_DIRECTION_RIGHT_DOWN:
			if (y % 2 == 0)
			{
				y--;
			}
			else
			{
				x--;
				y--;
			}
			break;

		case TANK_DIRECTION_RIGHT:
			x--;
			break;

		case TANK_DIRECTION_RIGHT_UP:
			if (y % 2 == 0)
			{
				y++;
			}
			else
			{
				x--;
				y++;
			}
			break;

		case TANK_DIRECTION_LEFT_UP:
			if (y % 2 == 0)
			{
				x++;
				y++;
			}
			else
			{
				y++;
			}
			break;

		default:
			break;
	}

	if (x >= grid->getWidth())
		x = grid->getWidth() - 1;
	else if (x < 0)
		x = 0;

	if (y >= grid->getHeight())
		y = grid->getHeight() - 1;
	else if (y < 0)
		y = 0;

	if (grid->is_obstacle(x, y))
	{
		x = or_x;
		y = or_y;
	}

	if (id == 0)
	{
		int ex, ey;
		grid->findEnemy(ex, ey);

		if (x == ex && y == ey)
		{
			x = or_x;
			y = or_y;
		}

		grid->update_player(x, y);
	}
	else
	{
		int px, py;
		grid->findPlayer(px, py);

		if (x == px && y == py)
		{
			x = or_x;
			y = or_y;
		}

		grid->update_enemy(x, y);
	}

	validatePosition();
}

void  Tank::shoot() {
	int ex, ey;
	grid->findEnemy(ex, ey);

	if (onShootingRange(x, y, ex, ey))
	{
		printf("ded\n");

		if (id == 0)
			grid->kill_enemy_tank();
		else
			grid->kill_player_tank();
	}
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

	validatePosition();
}

void Tank::setGrid(Grid* g) {
	grid = g;
}

bool Tank::onVisionRange() {
	return false;
}

bool Tank::onShootingRange(int px, int py, int ex, int ey) {
	int xs[3];
	int ys[3];

	switch (direction)
	{
		case TANK_DIRECTION_LEFT:
			xs[0] = x - 1;
			xs[1] = x - 2;
			xs[2] = x - 3;
			ys[0] = y;
			ys[1] = y;
			ys[2] = y;
			break;

		case TANK_DIRECTION_LEFT_DOWN:
			if (y % 2 == 0)
			{
				xs[0] = x;
				xs[1] = x - 1;
				xs[2] = x - 1;
				ys[0] = y + 1;
				ys[1] = y + 2;
				ys[2] = y + 3;
			}
			else
			{
				xs[0] = x - 1;
				xs[1] = x - 1;
				xs[2] = x - 2;
				ys[0] = y + 1;
				ys[1] = y + 2;
				ys[2] = y + 3;
			}
			break;

		case TANK_DIRECTION_RIGHT_DOWN:
			if (y % 2 == 0)
			{
				xs[0] = x + 1;
				xs[1] = x + 1;
				xs[2] = x + 2;
				ys[0] = y + 1;
				ys[1] = y + 2;
				ys[2] = y + 3;
			}
			else
			{
				xs[0] = x;
				xs[1] = x + 1;
				xs[2] = x + 1;
				ys[0] = y + 1;
				ys[1] = y + 2;
				ys[2] = y + 3;
			}
			break;

		case TANK_DIRECTION_RIGHT:
			xs[0] = x + 1;
			xs[1] = x + 2;
			xs[2] = x + 3;
			ys[0] = y;
			ys[1] = y;
			ys[2] = y;
			break;

		case TANK_DIRECTION_RIGHT_UP:
			if (y % 2 == 0)
			{
				xs[0] = x + 1;
				xs[1] = x + 1;
				xs[2] = x + 2;
				ys[0] = y - 1;
				ys[1] = y - 2;
				ys[2] = y - 3;
			}
			else
			{
				xs[0] = x ;
				xs[1] = x + 1;
				xs[2] = x + 1;
				ys[0] = y - 1;
				ys[1] = y - 2;
				ys[2] = y - 3;
			}
			break;

		case TANK_DIRECTION_LEFT_UP:
			if (y % 2 == 0)
			{
				xs[0] = x;
				xs[1] = x - 1;
				xs[2] = x - 1;
				ys[0] = y - 1;
				ys[1] = y - 2;
				ys[2] = y - 3;
			}
			else
			{
				xs[0] = x - 1;
				xs[1] = x - 1;
				xs[2] = x - 2;
				ys[0] = y - 1;
				ys[1] = y - 2;
				ys[2] = y - 3;
			}
			break;

		default:
			break;
	}

	for (int i = 0; i < 3; i++)
	{
		if (xs[i] == ex && ys[i] == ey)
		{
			return true;
		}
	}

	return false;
}

void Tank::validateRotation() {

	switch (direction)
	{
		case TANK_DIRECTION_LEFT:
			node->setRotation(0.0f);
			break;

		case TANK_DIRECTION_LEFT_DOWN:
			node->setRotation(60.0f);
			break;

		case TANK_DIRECTION_RIGHT_DOWN:
			node->setRotation(120.0f);
			break;

		case TANK_DIRECTION_RIGHT:
			node->setRotation(180.0f);
			break;

		case TANK_DIRECTION_RIGHT_UP:
			node->setRotation(-120.0f);
			break;

		case TANK_DIRECTION_LEFT_UP:
			node->setRotation(-60.0f);
			break;

		default:
			break;
	}
}

void Tank::validatePosition() {
	float nx = ((y % 2 == 0) ? 0.4 : 0) + ((y / 2) * 0.15) + x - 5;
	float ny = y * 0.85 - 3;

	node->setX(nx);
	node->setZ(ny);
}
