#include "WorldManager.h"

WorldManager::WorldManager() {}


void WorldManager::initProgs(std::string playerfile, std::string enemyfile) {
	pprog.load(playerfile);
	eprog.load(enemyfile);

	pprog.setTank(&ptank);
	eprog.setTank(&etank);
}

void WorldManager::initGrid(std::string gridpath) {
	grid.loadMap(gridpath);

	int w = grid.getWidth();
	int h = grid.getHeight();

	ptank.setPosition(1,1);
	etank.setPosition(w-1, h-1);

	ptank.setGrid(&grid);
	etank.setGrid(&grid);
}

void WorldManager::draw() {
	pprog.print();
	eprog.print();
}
