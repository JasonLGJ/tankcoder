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

	ptank.setPosition(0,1);
	etank.setPosition(w-1, h-2);

	ptank.setGrid(&grid);
	etank.setGrid(&grid);
}

void WorldManager::draw() {
	int w = grid.getWidth();
	int h = grid.getHeight();
	int offset = 0;


	for (int j = 0; j < h + 2; j++)
	{
		offset = (j % 2 == 0) ? 1 : 0;
		for (int i = 0; i < w - 1 - offset; i++)
		{
			if (j % 2 == 0)
			{
				std::cout << "   <" << i << j << ">";
			}
			else
			{
				std::cout << "<" << i << j << ">   ";
			}
		}

		std::cout << std::endl;
	}
}

/*
//3x3
		<00>
	<01>    <10>
{02}    <11>    {20}
	<12>    <21>
		<22>
*/
