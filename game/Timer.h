#pragma once

#include <string>
#include <stack>
#include <memory>
#include <vector>
#include "../utils/scene/SceneManager.h"

class Timer {
	public:
		Timer();
		void create(std::shared_ptr<SceneManager> scene);
		void update();
		void restart();
		void remove();
	private:
		int segs;
		int mins;
		std::shared_ptr<FlatNode> min_1;
		std::shared_ptr<FlatNode> min_2;
		std::shared_ptr<FlatNode> seg_1;
		std::shared_ptr<FlatNode> seg_2;
};
