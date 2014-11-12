#pragma once
#include "SceneNode.h"
#include "../assets/Mesh.h"

class StaticNode : public SceneNode {
	public:
		StaticNode();
		~StaticNode();
		void addMesh(Mesh m);
		Mesh* getMesh();
		float getRotation();
		void setRotation(float rot);
		float getScale();
		void setScale(float sc);
	private:
		Mesh mesh;
		float rotation;
		float scale;
};
