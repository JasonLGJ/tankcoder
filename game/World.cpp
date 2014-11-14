#include "World.h"

World::World() {
	paused = true;
	st_px = st_py =	st_ex =	st_ey = -10;
	enemyfile = "assets/progs/test.tc";
	timer = 0;
}

void World::init(std::shared_ptr<Loader> l, std::shared_ptr<SceneManager> s) {
	loader = l;
	scene = s;
}

bool World::run() {
	return !pprog.isFinished() && !eprog.isFinished();
}

void World::update() {
	if (run())
	{
		if (!paused)
		{
			if (timer == 60)
			{
				pprog.execute();
				eprog.execute();
				timer = 0;
			}
			else
			{
				timer++;
			}
		}
	}
	else
	{
		//meep?
		//show end game
	}
}

bool World::initProgs(std::string playerfile) {
	if (!pprog.load(playerfile))
		return false;

	if (!eprog.load(enemyfile))
		return false;

	pprog.setTank(&ptank);
	eprog.setTank(&etank);

	ptank.setAlive(true);
	etank.setAlive(true);

	/*
	std::cout << ">>> Player <<<" << std::endl;
	pprog.print();

	std::cout << ">>> Enemy <<<" << std::endl;
	eprog.print();
	*/

	return true;
}

bool World::initGrid(std::string gridpath, std::string lvlname) {
	std::shared_ptr<Resource> res = loader->getResource(gridpath);
	
	if (res == nullptr)
		return false;

	if (lvlname.compare("freeplay") != 0)
		grid.loadMap(res->get(lvlname), scene);
	else
		grid.loadMap(res->get("level_test"), scene);

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

	st_px = ptx;
	st_py = pty;
	st_ex = etx;
	st_ey = ety;

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

void World::set_pause(bool p) {
	paused = p;
}

void World::restart() {
	pprog.clear();
	eprog.clear();

	ptank.setPosition(st_px, st_py);
	etank.setPosition(st_ex, st_ey);
}

void World::reset() {
	pprog.clear();
	eprog.clear();

	ptank.setPosition(-10,-10);
	etank.setPosition(-10,-10);


	ptank.setAlive(false);
	etank.setAlive(false);
}
