#pragma once
#include "Grid.h"
enum TankDirection {
	TANK_DIRECTION_UP,
	TANK_DIRECTION_LEFT_UP,
	TANK_DIRECTION_LEFT_DOWN,
	TANK_DIRECTION_DOWN,
	TANK_DIRECTION_RIGHT_DOWN,
	TANK_DIRECTION_RIGHT_UP
};

class Tank {
	public:
		Tank();
		Tank(int dir, int x, int y);
		//
		void turnLeft();
		void turnRight();
		void goForward();
		void shoot();
		bool onShootingRange();
		bool onVisionRange();
		//
		void setPosition(int x, int y);
		void setGrid(Grid* g);
		//
		int getX();
		int getY();
		int getDirection();
		bool isAlive();

	private:
		Grid* grid;
		int direction;
		int x;
		int y;
		bool alive;
};
