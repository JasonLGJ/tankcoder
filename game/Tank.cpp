#include "Tank.h"

Tank::Tank() {
	direction = TANK_DIRECTION_LEFT;
	x = y = 0;
	alive = false;
}

void Tank::setNode(std::shared_ptr<StaticNode> n) {
	node = n;
}

void Tank::setAlive(bool a) {
	alive = a;
}

Tank::Tank(int dir, int x, int y) {
	direction = dir;
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

	validatePosition();
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

	validatePosition();
}

void Tank::setGrid(Grid* g) {
	grid = g;
}

bool Tank::onVisionRange() {
	return false;
}

bool Tank::onShootingRange() {
	int xs[3];
	int ys[3];

	return false;

	/*
	int Ry1,Ry2,Ry3;
	int Rx1,Rx2,Rx3;

	int x=Tank.getX();
	int y=Tank.getY();
	switch(Tank.getDirection())
	{
	case TANK_DIRECTION_UP:
		//vision cerca

		Rx1=x;
		Ry1=y-1;

		//vision media

		Rx2=x;
		Ry2=y-2;

		//vision larga

		Rx3=x;
		Ry3=y-3;
		if(x==Rx1&&y==Ry1||x==Rx2&&y==Ry2||x==Rx3&&y==Ry3)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;

	case TANK_DIRECTION_LEFT_UP:
		//vision cerca

		Rx1=x-1;
		Ry1=y-1;

		//vision media

		Rx2=x-2;
		Ry2=y-2;

		//vision lejos

		Rx3=x-3;
		Ry3=y-3;
		if(x==Rx1&&y==Ry1||x==Rx2&&y==Ry2||x==Rx3&&y==Ry3)
		{
			return true;
		}
		else
		{
			return false;
		}

		break;

	case TANK_DIRECTION_LEFT_DOWN:
		//vision cerca

		Rx1=x-1;
		Ry1=y+1;

		//vision media

		Rx2=x-2;
		Ry2=y+2;

		//vision lejos

		Rx3=x-3;
		Ry3=y+3;
		if(x==Rx1&&y==Ry1||x==Rx2&&y==Ry2||x==Rx3&&y==Ry3)
		{
			return true;
		}
		else
		{
			return false;
		}

		break;

	case TANK_DIRECTION_DOWN:
		//vision cerca

		Rx1=x;
		Ry1=y+1;

		//vision lejos

		Rx2=x;
		Ry2=y+2;

		//vision lejos

		Rx3=x;
		Ry3=y+3;
		if(x==Rx1&&y==Ry1||x==Rx2&&y==Ry2||x==Rx3&&y==Ry3)
		{
			return true;
		}
		else
		{
			return false;
		}

		break;

	case TANK_DIRECTION_RIGHT_DOWN:
		//vision cerca

		Rx1=x+1;
		Ry1=y+1;

		//vision media

		Rx2=x+2;
		Ry2=y+2;

		//vision lejos

		Rx3=x+3;
		Ry3=y+3;
		if(x==Rx1&&y==Ry1||x==Rx2&&y==Ry2||x==Rx3&&y==Ry3)
		{
			return true;
		}
		else
		{
			return false;
		}

		break;
	case TANK_DIRECTION_RIGHT_UP:
		//vision cerca

		Rx1=x+1;
		Ry1=y-1;

		//vision media

		Rx2=x+2;
		Ry2=y-2;

		//vision lejos

		Rx3=x+3;
		Ry3=y-3;
		if(x==Rx1&&y==Ry1||x==Rx2&&y==Ry2||x==Rx3&&y==Ry3)
		{
			return true;
		}
		else
		{
			return false;
		}

		break;

	default:
		break;
	}
	*/
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