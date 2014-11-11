#include "MenuList.h"

MenuList::MenuList() {
	offsetx = 0;
}

void MenuList::init(std::shared_ptr<SceneManager> s) {
	scene = s;
}

void MenuList::checkInput(std::string operation, float x, float y) {
	if (inside(x, y))
	{
		MenuRow row(operation);

		float nx = node->getX() + 0.6 * offsetx;
		float ny = node->getY() + node->getWidth() - rows.size() * 0.6;

		row.node = scene->createFlatNode(operation, nx, ny, 0.5, 0.5);

		if (rows.size() == 0 || y < rows[rows.size()-1].getY())
		{
			rows.push_back(row);
		}
		else
		{
			int pos = -1;

			for (int i = 0; i < rows.size(); i++)
			{
				if (rows[i].inside(y))
				{
					pos = i;
					break;
				}
			}

			if (pos >= 0)
			{
				rows.insert(rows.begin()+pos, row);
			}
		}
	}
}


std::vector<MenuRow> MenuList::getRows() {
	return rows;
}

bool MenuList::inside(float px, float py) {
	if (px < node->getX() || px > node->getX() + node->getWidth())
		return false;

	if (py < node->getY() || py > node->getY() + node->getHeight())
		return false;

	return true;
}

bool MenuList::is_conditional(std::string operation) {
	return false;
}