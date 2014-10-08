class Tile {
	public:
		Tile(bool p, bool v);
		bool isPassable();
		bool isVisible();
	private:
		bool passable;
		bool visible;
};
