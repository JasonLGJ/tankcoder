#include "WorldManager.h"

WorldManager::WorldManager() {}

bool WorldManager::run() {
	return !pprog.isFinished() && !eprog.isFinished();
}

void WorldManager::update() {
	pprog.execute();
	eprog.execute();
}

bool WorldManager::initProgs(std::string playerfile, std::string enemyfile) {
	pprog.load(playerfile);
	eprog.load(enemyfile);

	pprog.setTank(&ptank);
	eprog.setTank(&etank);

	std::cout << ">>> Player <<<" << std::endl;
	pprog.print();

	std::cout << ">>> Enemy <<<" << std::endl;
	eprog.print();
}

bool WorldManager::initGrid(std::string gridpath) {
	grid.loadMap(gridpath);

	int w = grid.getWidth();
	int h = grid.getHeight();

	ptank.setPosition(0,1);
	etank.setPosition(w-1, h-2);

	ptank.setGrid(&grid);
	etank.setGrid(&grid);
}

bool WorldManager::tankIn(char tid, int x, int y) {
	if (tid == 'P')
	{
		return x == ptank.getX() && y == ptank.getY();
	}
	else
	{
		return x == etank.getX() && y == etank.getY();
	}
}

void WorldManager::draw() {
	int w = grid.getWidth();
	int h = grid.getHeight();

	for (int j = 0; j < h; j++)
	{
		for (int i = 0; i < w; i++)
		{
			std::cout << "[";

			if (tankIn('P', i, j))
				std::cout << "P" << ptank.getDirection();
			else if (tankIn('E', i, j))
				std::cout << "E" << etank.getDirection();
			else
				std::cout << "  ";

			std::cout << "]";
		}

		std::cout << std::endl;
	}

}
