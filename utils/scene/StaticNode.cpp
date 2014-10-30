#include "StaticNode.h"

StaticNode::StaticNode() {
	type = SCENE_NODE_STATIC;
}

StaticNode::~StaticNode() {}

void StaticNode::addMesh(Mesh m) {
	mesh = m;
}

Mesh StaticNode::getMesh() {
	return mesh;
}
