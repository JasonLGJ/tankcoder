#pragma once
#include "SceneNode.h"
#include "../assets/AnimatedMesh.h"

class AnimatedNode : public SceneNode {
	public:
		AnimatedNode();
		~AnimatedNode();
		void addMesh(AnimatedMesh m);
		AnimatedMesh getMesh();
	private:
		AnimatedMesh mesh;
};
