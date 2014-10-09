#include "Game/WorldManager.h"

int main() {
	WorldManager world;

	world.initGrid("test");
	world.initProgs("test.tc", "test.tc");

	world.draw();
}
