#include "StaticNode.h"

StaticNode::StaticNode() {
	type = SCENE_NODE_STATIC;
	visible = true;
	rotation = 0.0f;
	scale = 1.0f;
}

StaticNode::~StaticNode() {}

void StaticNode::addMesh(Mesh m) {
	mesh = m;
}

Mesh* StaticNode::getMesh() {
	return &mesh;
}

float StaticNode::getRotation() {
	return rotation;
}

void StaticNode::setRotation(float rot) {
	rotation = rot;
}

float StaticNode::getScale() {
	return scale;
}

void StaticNode::setScale(float sc) {
	scale = sc;
}