#pragma once
#include "SceneNode.h"
#include "../assets/Mesh.h"

class StaticNode : public SceneNode {
	public:
		StaticNode();
		~StaticNode();
		void addMesh(std::shared_ptr<Mesh> m);
		std::shared_ptr<Mesh> getMesh();
	private:
		std::shared_ptr<Mesh> mesh;
};
