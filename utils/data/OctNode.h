#pragma once
#include "../scene/SceneNode.h"
#include "Region.h"
#include <memory>

const int MAX_CHILDREN = 8;
const int MAX_DATA = 8;

class OctNode {
	public:
		OctNode();
		OctNode(Region r);
		void insert(std::shared_ptr<SceneNode> n);
		void setRegion(Region r);
		bool inside(int x, int y, int z);
		void getNodes(std::vector<std::shared_ptr<SceneNode>>& storage);
	private:
		void add(std::shared_ptr<SceneNode> n);
		//
		bool leaf;
		int dataNum;
		Region region;
		std::shared_ptr<SceneNode> data[MAX_DATA];
		std::shared_ptr<OctNode> children[MAX_CHILDREN];
};