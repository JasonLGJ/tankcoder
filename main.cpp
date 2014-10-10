#include "Game/WorldManager.h"

int main() {
	WorldManager world;

	world.initGrid("test");
	world.initProgs("test.tc", "test.tc");

	int x;

	while (world.run())
	{
		world.update();
		world.draw();

		std::cin >> x;
	}
}
