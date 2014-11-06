#include "World.h"

World::World() {}

void World::init(std::shared_ptr<Loader> l, std::shared_ptr<SceneManager> s) {
	loader = l;
	scene = s;
}

bool World::run() {
	return !pprog.isFinished() && !eprog.isFinished();
}

void World::update() {
	pprog.execute();
	eprog.execute();
}

bool World::initProgs(std::string playerfile, std::string enemyfile) {
	if (!pprog.load(playerfile))
		return false;

	if (!eprog.load(enemyfile))
		return false;

	pprog.setTank(&ptank);
	eprog.setTank(&etank);

	std::cout << ">>> Player <<<" << std::endl;
	pprog.print();

	std::cout << ">>> Enemy <<<" << std::endl;
	eprog.print();

	return true;
}

bool World::initGrid(std::string gridpath) {
	if (!grid.loadMap(gridpath))
		return false;

	int w = grid.getWidth();
	int h = grid.getHeight();

	ptank.setPosition(0,1);
	etank.setPosition(w-1, h-2);

	ptank.setGrid(&grid);
	etank.setGrid(&grid);

	return true;
}

bool World::tankIn(char tid, int x, int y) {
	if (tid == 'P')
	{
		return x == ptank.getX() && y == ptank.getY();
	}
	else
	{
		return x == etank.getX() && y == etank.getY();
	}
}

void World::draw() {
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
