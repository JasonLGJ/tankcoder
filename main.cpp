#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "Game.h"
#include <iostream>

int main(int argc, char* argv[]) {
	/*
	Loader load;

	std::shared_ptr<Resource> res = load.getResource("leveltest.json");

	int w = res->getNumber("w");
	int h = res->getNumber("h");

	printf("%d,%d\n", w, h);

	for (int j = 0; j < h; j++)
	{
		std::vector<double> row;
		std::string name = "r" + std::to_string(j);

		printf("%s\n", name.c_str());

		res->getArray(name, row);

		for (int i = 0; i < row.size(); i++)
		{
			int y = row[i];
			printf("%d ", y);
		}

		printf("\n");
	}

	int x;
	std::cin >> x;
	return x;
	*/
	
	Game g;
	return g.execute();
}
