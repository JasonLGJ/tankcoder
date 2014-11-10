#include "Editor.h"

Editor::Editor() {}

void Editor::save(std::string filename) {
	std::ofstream file(filename.c_str());

	for (int i = 0; i < stats.size(); i++)
	{
		file << stats[i].toObj() << std::endl;
	}

	file.close();
}