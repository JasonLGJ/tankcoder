#include "Grid.h"

Grid::Grid() {
	width = height = 5;
}

void Grid::loadMap(std::string name) {

}

void Grid::draw() {
	std::cout << " ";

	for (int i = 0; i < width - 1; i++)
	{
		std::cout << "__    ";
	}

	std::cout << std::endl;


	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width - 1; i++)
		{
			if (i == width - 2)
				std::cout << "/  \\";
			else
				std::cout << "/  \\__";
		}

		std::cout << std::endl;

		for (int i = 0; i < width - 1; i++)
		{
			std::cout << "\\__/  ";
		}

		std::cout << std::endl;
	}

	std::cout << " ";

	for (int i = 0; i < width - 2; i++)
	{
		std::cout << "  \\__/";
	}

	std::cout << std::endl << std::endl;
}
