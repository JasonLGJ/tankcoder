#pragma once
#include "SceneNode.h"
#include "../assets/Mesh.h"

class StaticNode : public SceneNode {
	public:
		StaticNode();
		~StaticNode();
		void addMesh(Mesh m);
		Mesh getMesh();
	private:
		Mesh mesh;
};
