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
		if (offsetx == 0 && is_end_cond(operation))
			return;

		MenuRow row(operation);

		float nx = node->getX() + 0.55 * offsetx + 0.1;
		float ny = node->getY() + node->getHeight() - (rows.size() + 1) * 0.55 - 0.1;

		row.node = scene->createFlatNode("assets/editor/" + operation, nx, ny, 0.5, 0.5);
		row.node->setZ(5.0);

		if (is_conditional(operation))
			offsetx++;
		else if (operation.compare("endif") == 0)
		{
			nx = node->getX() + 0.55 * (offsetx - 1) + 0.1;
			row.node->setX(nx);
			offsetx--;
		}
		else if (operation.compare("else") == 0)
		{
			float nnx = node->getX() + 0.55 * (offsetx - 1) + 0.1;
			row.node->setX(nnx);
		}

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
		
		if (is_end_cond(rows[i].getOperation()))
		{
			nx = node->getX() + 0.55 * (offx - 1) + 0.1;
		}


		rows[i].node->setX(nx);
		rows[i].node->setY(ny);

		if (is_conditional(rows[i].getOperation()))
			offx++;
		else if (rows[i].getOperation().compare("endif") == 0)
			offx--;
	}
}

void MenuList::checkVisible() {
	for (int i = 0; i < rows.size(); i++)
	{
		if (i >= offsety && i < offsety + MAX_DISPLAY_ITEMS)
		{
			float ny = node->getY() + node->getHeight() - (i - offsety + 1) * 0.55 - 0.1;;

			rows[i].node->setY(ny);
			rows[i].node->setVisible(true);
		}
		else
		{
			float ny = -5.0f;

			rows[i].node->setY(ny);
			rows[i].node->setVisible(false);
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
	if (operation.compare("random") == 0)
		return true;
	
	if (operation.compare("if") == 0)
		return true;

	return false;
}

bool MenuList::is_end_cond(std::string operation) {
	if (operation.compare("endif") == 0)
		return true;

	if (operation.compare("else") == 0)
		return true;

	return false;
}


void MenuList::scroll(int direction) {
	if (rows.size() == 0)
		return;

	offsety += direction;

	if (offsety < 0)
		offsety = 0;
	else if (offsety >= rows.size())
		offsety = rows.size() - 1;

	checkVisible();
}

void MenuList::save() {
	for (int i = 0; i < rows.size(); i++)
	{
		editor->generate_statement(rows[i].getOperation());
		scene->deleteNode(rows[i].node);
	}

	rows.clear();
}

void MenuList::setEdit(Editor* edit) {
	editor = edit;
}