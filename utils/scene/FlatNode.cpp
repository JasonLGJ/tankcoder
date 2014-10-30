#include "FlatNode.h"

FlatNode::FlatNode() {
	type = SCENE_NODE_FLAT;
	width = height = 1;
}

FlatNode::~FlatNode() {}

void FlatNode::setTexture(Texture t) {
	texture = t;
}

Texture FlatNode::getTexture() {
	return texture;
}

void FlatNode::setSize(float w, float h) {
	width = w;
	height = h;
}

float FlatNode::getWidth() {
	return width;
}

float FlatNode::getHeight() {
	return height;
}