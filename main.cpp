#include "game/World.h"

int main() {
	World world;

	world.initGrid("test");
	world.initProgs("test.tc", "test.tc");

	world.draw();
}
