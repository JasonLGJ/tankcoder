#pragma once
#include <memory>
#include "OctNode.h"

class OctTree {
	public:
		OctTree();
		void insert(std::shared_ptr<SceneNode> n);
		void prune();
		void remove(std::shared_ptr<SceneNode> n);
		int getSize();
		void getNodes(std::vector<std::shared_ptr<SceneNode>>& storage);
	private:
		std::shared_ptr<OctNode> root;
		unsigned long size;
		unsigned long node_ids;
};