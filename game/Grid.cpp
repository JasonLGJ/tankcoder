#include "Grid.h"

Grid::Grid() {
	width = height = 0;
}

bool Grid::loadMap(std::string name) {
	//STUB
	width = height = 5;

	return true;
}

void Grid::draw() {
	//STUB
}


int Grid::getWidth() {
	return width;
}

int Grid::getHeight() {
	return height;
}
