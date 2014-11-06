#pragma once
#include "SceneNode.h"
#include "../assets/Texture.h"

class FlatNode : public SceneNode {
	public:
		FlatNode();
		~FlatNode();
		void setTexture(std::shared_ptr<Texture> t);
		std::shared_ptr<Texture> getTexture();
		void setSize(float w, float h);
		float getWidth();
		float getHeight();
	private:
		std::shared_ptr<Texture> texture;
		float width;
		float height;
};
