#include <iostream>
#include <string>
#include <vector>
#include "Tile.h"

class Grid {
	public:
		Grid();
		void loadMap(std::string name);
		void draw();
	private:
		std::vector<Tile> tiles;
		int width;
		int height;
};
