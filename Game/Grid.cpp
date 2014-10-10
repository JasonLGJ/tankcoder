#include "Grid.h"

Grid::Grid() {
	width = height = 0;
}

void Grid::loadMap(std::string name) {
	//STUB
	width = height = 3;
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
