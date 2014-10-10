#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Tile.h"

class Grid {
	public:
		Grid();
		bool loadMap(std::string name);
		void draw();
		//
		int getWidth();
		int getHeight();
	private:
		std::vector<Tile> tiles;
		int width;
		int height;
};
