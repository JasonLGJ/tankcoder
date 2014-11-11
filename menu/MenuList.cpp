#include "MenuList.h"

MenuList::MenuList() {
	offsetx = 0;
	offsety = 0;
}

void MenuList::init(std::shared_ptr<SceneManager> s) {
	scene = s;
}

void MenuList::checkInput(std::string operation, float x, float y) {
	if (inside(x, y))
	{
		MenuRow row(operation);

		float nx = node->getX() + 0.55 * offsetx + 0.1;
		float ny = node->getY() + node->getHeight() - (rows.size() + 1) * 0.55 - 0.1;

		row.node = scene->createFlatNode("assets/editor/" + operation, nx, ny, 0.5, 0.5);
		row.node->setZ(5.0);

		if (is_conditional(operation))
			offsetx++;

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
				
				reposition();
			}
		}

		checkVisible();
	}
}

void MenuList::reposition() {
	int offx = 0;

	for (int i = 0; i < rows.size(); i++)
	{
		float nx = node->getX() + 0.55 * offx + 0.1;
		float ny = node->getY() + node->getHeight() - (i + 1) * 0.55 - 0.1;

		rows[i].node->setX(nx);
		rows[i].node->setY(ny);

		if (is_conditional(rows[i].getOperation()))
			offx++;
	}
}

void MenuList::checkVisible() {
	for (int i = 0; i < rows.size(); i++)
	{
		if (i >= offsety && i < offsety + MAX_DISPLAY_ITEMS)
			rows[i].node->setVisible(true);
		else
			rows[i].node->setVisible(false);
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
	if (operation.compare("random") == 0)
		return true;
	
	return false;
}