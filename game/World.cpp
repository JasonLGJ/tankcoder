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
	/*
	pprog.execute();
	eprog.execute();
	*/
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
	std::shared_ptr<Resource> res = loader->getResource(gridpath);
	
	if (res == nullptr)
		return false;

	grid.loadMap(res, scene);

	//Mesh
	std::shared_ptr<StaticNode> pnode = scene->createStaticNode("assets/game/tank", 0.0, 0.1, 0.0);
	pnode->setScale(0.11);

	std::shared_ptr<StaticNode> enode = scene->createStaticNode("assets/game/tank", 0.0, 0.1, 0.0);
	enode->setScale(0.11);

	ptank.setNode(pnode);
	etank.setNode(enode);

	//positions
	int ptx = 0, pty = 0, etx = 0, ety = 0;

	grid.findPlayer(ptx, pty);
	grid.findEnemy(etx, ety);
	
	ptank.setPosition(ptx, pty);
	etank.setPosition(etx, ety);

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