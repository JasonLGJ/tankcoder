class Tank {
	public:
		Tank();
		void turnLeft();
		void turnRight();
		void goForward();
		void shoot();
	private:
		int direction;
		int x;
		int y;
		bool alive;
};