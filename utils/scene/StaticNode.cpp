#include "StaticNode.h"

StaticNode::StaticNode() {
	type = SCENE_NODE_STATIC;
}

StaticNode::~StaticNode() {}

void StaticNode::addMesh(std::shared_ptr<Mesh> m) {
	mesh = m;
}

std::shared_ptr<Mesh> StaticNode::getMesh() {
	return mesh;
}
