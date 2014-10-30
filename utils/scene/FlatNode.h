#pragma once
#include "SceneNode.h"
#include "../assets/Texture.h"

class FlatNode : public SceneNode {
	public:
		FlatNode();
		~FlatNode();
		void setTexture(Texture t);
		Texture getTexture();
		void setSize(float w, float h);
		float getWidth();
		float getHeight();
	private:
		Texture texture;
		float width;
		float height;
};
