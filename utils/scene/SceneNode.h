#pragma once

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
		void setPosition(int x, int y, int z);
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
	protected:
		sceneNodeType type;
		bool visible;
		bool collidable;
		int x;
		int y;
		int z;
};
