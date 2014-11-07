#include "Menu.h"

Menu::Menu() {
	pressed = false;
	scene = nullptr;
	loader = nullptr;
}

void Menu::init(std::shared_ptr<Loader> l, std::shared_ptr<SceneManager> s) {
	loader = l;
	scene = s;
}

void Menu::load(std::string filename, std::string menuname) {
	std::shared_ptr<Resource> res = loader->getResource(filename);

	if (res == nullptr)
	{
		//panic
		return;
	}

	if (!menuname.empty())
		create_menu(res->get(menuname));
	else
	{
		std::string startname = res->getString("start_menu");
		create_menu(res->get(startname));
	}

}

void Menu::create_menu(std::shared_ptr<Resource> menu) {
	int qty = menu->getNumber("itemqty");

	for (int i = 0; i < qty; i++)
	{
		std::string item_name = "item" + std::to_string(i);
		create_item(menu->get(item_name));
	}
}

void Menu::create_item(std::shared_ptr<Resource> item) {
	int type = item->getNumber("type");

	switch(type)
	{
		case MENU_TYPE_BUTTON:
			{
				std::shared_ptr<MenuButton> button = std::make_shared<MenuButton>();

				float x = item->getNumber("x");
				float y = item->getNumber("y");
				float w = item->getNumber("w");
				float h = item->getNumber("h");
				std::string name = item->getString("textname");

				button->node = scene->createFlatNode(name, x, y, w, h);
				button->text = item->getString("text");

				items.push_back(button);
			}
			break;

		case MENU_TYPE_ITEM:
		default:
			break;
	}
}

void Menu::mouse_moved(float x, float y) {
	for (int i = 0; i < items.size(); i++)
	{
		items[i]->mouse_moved(x,y,pressed);
	}
}

void Menu::mouse_pressed() {
	pressed = true;
}

void Menu::mouse_released() {
	pressed = false;
}

void Menu::update() {
	if (!events.empty())
	{
		//proccess event
		events.pop();
	}
}
