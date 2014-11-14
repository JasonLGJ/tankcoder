#include "OctTree.h"

OctTree::OctTree() {
	size = 0;
	node_ids = 1;
	root = std::make_shared<OctNode>();
}

void OctTree::insert(std::shared_ptr<SceneNode> n) {
	n->setId(node_ids);
	root->insert(n);
	size++;
	node_ids++;
}

int OctTree::getSize() {
	return size;
}

void OctTree::getNodes(std::vector<std::shared_ptr<SceneNode>>& storage) {
	root->getNodes(storage);
}

void OctTree::remove(std::shared_ptr<SceneNode> n) {
	root->remove(n);
	size--;
}

void OctTree::prune() {
	size = 0;
	root = std::make_shared<OctNode>();
}