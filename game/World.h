#pragma once
#include <string>

#include "Program.h"
#include "Tank.h"
#include "Grid.h"

class World {
	public:
		World();
		//
		void initProgs(std::string playerfile, std::string enemyfile);
		void initGrid(std::string gridpath);
		void draw();
	private:
		Grid grid;
		Program pprog;
		Program eprog;
		Tank ptank;
		Tank etank;
};