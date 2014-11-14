#include "SceneNode.h"

SceneNode::SceneNode() {
	visible = collidable = false;
	x = y = z = 0.0f;
	type = SCENE_NODE;
	id = 0;
}

SceneNode::~SceneNode() {}

void SceneNode::setPosition(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void SceneNode::setX(float x) {
	this->x = x;
}

void SceneNode::setY(float y) {
	this->y = y;
}

void SceneNode::setZ(float z) {
	this->z = z;
}

float SceneNode::getX() {
	return x;
}

float SceneNode::getY() {
	return y;
}

float SceneNode::getZ() {
	return z;
}

bool SceneNode::isVisible() {
	return visible;
}

bool SceneNode::isCollidable() {
	return collidable;
}

void SceneNode::setVisible(bool v) {
	visible = v;
}

void SceneNode::setCollidable(bool c) {
	collidable = c;
}

sceneNodeType SceneNode::getType() {
	return type;
}

unsigned long SceneNode::getId() {
	return id;
}

void SceneNode::setId(unsigned long i) {
	id = i;
}