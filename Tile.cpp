#include "Tile.h"

Tile::Tile(bool p, bool v) {
	passable = p;
	visible = v;
}

bool Tile::isPassable() {
	return passable;
}

bool Tile::isVisible() {
	return visible;
}
