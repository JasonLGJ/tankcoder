#include "Tile.h"

Tile::Tile(int i) {
	id = i;
}

bool Tile::isPassable() {
	return id == 0;
}

void Tile::setNode(std::shared_ptr<StaticNode> n) {
	node = n;
}