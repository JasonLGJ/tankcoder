#pragma once
#include "Grid.h"
#include "../utils/scene/StaticNode.h"

enum TankDirection {
	TANK_DIRECTION_LEFT,
	TANK_DIRECTION_LEFT_DOWN,
	TANK_DIRECTION_RIGHT_DOWN,
	TANK_DIRECTION_RIGHT,
	TANK_DIRECTION_RIGHT_UP,
	TANK_DIRECTION_LEFT_UP
};

class Tank {
	public:
		Tank();
		Tank(int dir, int x, int y);
		//
		void turnLeft();
		void turnRight();
		void goForward();
		void goBackward();
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
		void setAlive(bool a);
		void shoot(int px, int py,int ex,int ey,bool live);
		bool onShootingRange(int px, int py, int ex, int ey);
		void setNode(std::shared_ptr<StaticNode> n);
		//
		void validateRotation();
		void validatePosition();
	private:
		Grid* grid;
		int direction;
		int x;
		int y;
		bool alive;
		std::shared_ptr<StaticNode> node;
};
