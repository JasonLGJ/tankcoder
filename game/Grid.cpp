#include "Grid.h"

Grid::Grid() {
	width = height = 0;
}

bool Grid::loadMap(std::shared_ptr<Resource> data, std::shared_ptr<SceneManager> scene) {
	width = data->getNumber("w");
	height = data->getNumber("h");

	for (int j = 0; j < height; j++)
	{
		std::vector<double> row;
		std::string rname = "r" + std::to_string(j);

		data->getArray(rname, row);

		for (int i = 0; i < width; i++)
		{
			create_tile(row[i], i, j, scene);
		}
	}

	return true;
}

void Grid::create_tile(int type, int x, int y, std::shared_ptr<SceneManager> scene) {
	float nx = (y % 2 == 0) ? x + 0.4 : x;
	float ny = y * 0.85;
	
	switch (type)
	{
		case TILE_TYPE_PLAIN:
			{
				Tile t(type);
				t.setNode(scene->createStaticNode("plain", nx, 0, ny));
				tiles.push_back(t);
			}
			break;
		
		case TILE_TYPE_OBSTACLE:
			{
				Tile t(type);
				t.setNode(scene->createStaticNode("obstacle", nx, 0, ny));
				tiles.push_back(t);
			}
			break;

		case TILE_TYPE_PLAYER:
			{
				player_x = x;
				player_y = y;

				Tile t(TILE_TYPE_PLAIN);
				t.setNode(scene->createStaticNode("plain", nx, 0, ny));
				tiles.push_back(t);
			}
			break;

		case TILE_TYPE_ENEMY:
			{
				enemy_x = x;
				enemy_y = y;

				Tile t(TILE_TYPE_PLAIN);
				t.setNode(scene->createStaticNode("plain", nx, 0, ny));
				tiles.push_back(t);
			}
			break;

		case TILE_TYPE_RANDOM:
		default:
			break;
	}
}

int Grid::getWidth() {
	return width;
}

int Grid::getHeight() {
	return height;
}

void Grid::findPlayer(int& x, int& y) {
	x = player_x;
	y = player_y;
}

void Grid::findEnemy(int& x, int& y) {
	x = enemy_x;
	y = enemy_y;
}