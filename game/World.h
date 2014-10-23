#pragma once
#include <string>

#include "Program.h"
#include "Tank.h"
#include "Grid.h"

class World {
	public:
		World();
		//
		bool initProgs(std::string playerfile, std::string enemyfile);
		bool initGrid(std::string gridpath);
		void draw();
		bool run();
		void update();
	private:
		bool tankIn(char tid, int x, int y);
		Grid grid;
		Program pprog;
		Program eprog;
		Tank ptank;
		Tank etank;
};
