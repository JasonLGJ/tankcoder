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
		Tank(int dir, int x, int y);
		//
		void turnLeft();
		void turnRight();
		void goForward();
		void shoot();
		//
		int getX();
		int getY();
		int getDirection();
		bool isAlive();
		bool isShooting();
	private:
		int direction;
		int x;
		int y;
		bool alive;
		bool shooting;
};
