#pragma once
#include <string>

#include "../utils/scene/SceneManager.h"

#include "Program.h"
#include "Tank.h"
#include "Grid.h"

class World {
	public:
		World();
		//
		void init(std::shared_ptr<Loader> l, std::shared_ptr<SceneManager> s);
		bool initProgs(std::string playerfile, std::string enemyfile);
		bool initGrid(std::string gridpath, std::string lvlname);
		bool run();
		void update();
	private:
		bool tankIn(char tid, int x, int y);
		std::shared_ptr<Loader> loader;
		std::shared_ptr<SceneManager> scene;
		Grid grid;
		Program pprog;
		Program eprog;
		Tank ptank;
		Tank etank;
};
