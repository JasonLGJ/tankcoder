#pragma once
#include "../utils/scene/StaticNode.h"

enum tile_type {
	TILE_TYPE_PLAIN,
	TILE_TYPE_OBSTACLE,
	TILE_TYPE_PLAYER,
	TILE_TYPE_ENEMY,
	TILE_TYPE_RANDOM
};

class Tile {
	public:
		Tile(int i);
		bool isPassable();
		//
		void setNode(std::shared_ptr<StaticNode> n);
	private:
		int id;
		std::shared_ptr<StaticNode> node;
};
