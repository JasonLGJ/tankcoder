#include "World.h"

World::World() {}


void World::initProgs(std::string playerfile, std::string enemyfile) {
	pprog.load(playerfile);
	eprog.load(enemyfile);

	pprog.setTank(&ptank);
	eprog.setTank(&etank);
}

void World::initGrid(std::string gridpath) {
	grid.loadMap(gridpath);

	int w = grid.getWidth();
	int h = grid.getHeight();

	ptank.setPosition(1,1);
	etank.setPosition(w-1, h-1);

	ptank.setGrid(&grid);
	etank.setGrid(&grid);
}

void World::draw() {
	pprog.print();
	eprog.print();
}
