#pragma once

#include <memory>

enum sceneNodeType {
	SCENE_NODE,
	SCENE_NODE_FLAT,
	SCENE_NODE_STATIC,
	SCENE_NODE_ANIMATED
};

class SceneNode {
	public:
		SceneNode();
		virtual ~SceneNode();
		void setPosition(float x, float y, float z);
		void setX(float x);
		void setY(float y);
		void setZ(float z);
		float getX();
		float getY();
		float getZ();
		bool isVisible();
		bool isCollidable();
		void setVisible(bool v);
		void setCollidable(bool c);
		sceneNodeType getType();
		unsigned long getId();
		void setId(unsigned long i);
	protected:
		sceneNodeType type;
		bool visible;
		bool collidable;
		float x;
		float y;
		float z;
		unsigned long id;
};
