#include "Game/WorldManager.h"

int main() {
	WorldManager world;

	if (!world.initGrid("test"))
		return -1;
		
	if (!world.initProgs("test.tc", "test.tc"))
		return -1;

	int x;

	while (world.run())
	{
		world.update();
		world.draw();

		std::cin >> x;
	}
}
