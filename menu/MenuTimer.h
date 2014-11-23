#pragma once

#include <string>
#include <stack>
#include <memory>
#include <vector>
#include "../utils/scene/SceneManager.h"
#include"MenuItem.h"

class MenuTimer {
public:
	std::shared_ptr<FlatNode> min_1;
	std::shared_ptr<FlatNode>min_2;
	std::shared_ptr<FlatNode>seg_1;
	std::shared_ptr<FlatNode>seg_2;
	
	void update();
	int segs;
	int mins;
	void create(std::shared_ptr<SceneManager> s);


	
private:
	
};
