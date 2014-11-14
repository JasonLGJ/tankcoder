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
		bool initProgs(std::string playerfile);
		bool initGrid(std::string gridpath, std::string lvlname);
		bool run();
		void update();
		void set_pause(bool p);
		void restart();
		void reset();
	private:
		bool tankIn(char tid, int x, int y);
		bool paused;
		std::shared_ptr<Loader> loader;
		std::shared_ptr<SceneManager> scene;
		Grid grid;
		Program pprog;
		Program eprog;
		Tank ptank;
		Tank etank;
		int st_px;
		int st_py;
		int st_ex;
		int st_ey;
		std::string enemyfile;
};
