#include "Menu.h"
#pragma coment(lib,"winmm.lib")


Menu::Menu() {
	pressed = false;
	scene = nullptr;
	loader = nullptr;
	editor = nullptr;

	start_game = false;
	quit_requested = false;

	menu_action = MENU_ACTION_EDITOR;

	event_param = "";
}

void Menu::init(std::shared_ptr<Loader> l, std::shared_ptr<SceneManager> s) {
	loader = l;
	scene = s;
	
}

void Menu::clean() {
	for (int i = 0; i < items.size(); i++)
		scene->deleteNode(items[i]->node);

	items.clear();
}

void Menu::load(std::string filename, std::string menuname) {
	std::shared_ptr<Resource> res = loader->getResource(filename);

	if (res == nullptr)
	{
		printf("menu_creation failed\n");
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

		case MENU_TYPE_ITEM:
			{
				std::shared_ptr<MenuItem> image = std::make_shared<MenuItem>();

				float x = item->getNumber("x");
				float y = item->getNumber("y");
				float w = item->getNumber("w");
				float h = item->getNumber("h");
				std::string name = item->getString("textname");
				int tn = item->getNumber("textnum");

				image->node = scene->createFlatNode(name, x, y, w, h);

				if (tn > 1)
					image->node->getTexture()->setMultiTexture(tn);

				items.push_back(image);
			}
			break;

		case MENU_TYPE_BUTTON:
			{
				std::shared_ptr<MenuButton> button = std::make_shared<MenuButton>();

				float x = item->getNumber("x");
				float y = item->getNumber("y");
				float w = item->getNumber("w");
				float h = item->getNumber("h");
				std::string name = item->getString("textname");
				int tn = item->getNumber("textnum");

				button->node = scene->createFlatNode(name, x, y, w, h);

				if (tn > 1)
					button->node->getTexture()->setMultiTexture(tn);

				button->event = create_event(item->getString("action"));
				button->addStack(&events);

				items.push_back(button);
			}
			break;

		case MENU_TYPE_DRAG:
			{
				std::shared_ptr<MenuDrag> drag = std::make_shared<MenuDrag>();

				float x = item->getNumber("x");
				float y = item->getNumber("y");
				float w = item->getNumber("w");
				float h = item->getNumber("h");
				std::string name = item->getString("textname");
				int tn = item->getNumber("textnum");

				drag->node = scene->createFlatNode(name, x, y, w, h);

				if (tn > 1)
					drag->node->getTexture()->setMultiTexture(tn);

				drag->event = create_event(item->getString("action"));
				drag->addStack(&events);

				items.push_back(drag);
			}
			break;

		case MENU_TYPE_LIST:
			{
				std::shared_ptr<MenuList> list = std::make_shared<MenuList>();

				float x = item->getNumber("x");
				float y = item->getNumber("y");
				float w = item->getNumber("w");
				float h = item->getNumber("h");
				std::string name = item->getString("textname");
				int tn = item->getNumber("textnum");

				list->node = scene->createFlatNode(name, x, y, w, h);

				if (tn > 1)
					list->node->getTexture()->setMultiTexture(tn);

				editor = list;
				editor->init(scene);

				items.push_back(list);
			}
			break;

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
		process_event(events.top());
		events.pop();
	}
}

void Menu::process_event(MenuEvent event) {
	switch (event.action)
	{
		case MENU_EVENT_SWAP_MENU:
			//printf("Swaping menu...\n");
			clean();
			load("assets/menus/menus.json", event.param);
			break;

		case MENU_EVENT_START_GAME:
			//printf("Starting game...\n");
			start_game = true;
			clean();
			scene->drop();
			load("assets/editor/editor.json");
			event_param = event.param;
			break;

		case MENU_EVENT_QUIT_GAME:
			//printf("Quitting...\n");
			quit_requested = true;
			clean();
			break;

		case MENU_EVENT_DROP:
			//printf("dropped: %s\n", event.param.c_str());
			if (editor != nullptr)
			{
				std::string action;
				float x, y;

				split_drop(event.param, action, x, y);

				editor->checkInput(action, x, y);
			}
			break;

		case MENU_EVENT_SCROLL_EDITOR:
			//printf("scroll %s\n", event.param.c_str());
			if (editor != nullptr)
			{
				int dir = (event.param.compare("up") == 0) ? -1 : 1;
				editor->scroll(dir);
			}
			break;

		case MENU_EVENT_MODIFY_LEVEL:
			printf("level %s\n", event.param.c_str());
			if (editor != nullptr)
			{
				if (event.param.compare("quit") == 0)
				{
					start_game = false;
					clean();
					scene->drop();
					load("assets/menus/menus.json");
				}
				else if (event.param.compare("begin") == 0)
				{
					editor->save();
					menu_action = MENU_ACTION_BEGIN;
					clean();
					load("assets/editor/editor.json", "ingame");
				}
				else if (event.param.compare("pause") == 0)
				{
					menu_action = MENU_ACTION_PAUSED;
				}
				else if (event.param.compare("resume") == 0)
				{
					menu_action = MENU_ACTION_RESUME;
				}
				else if (event.param.compare("restart") == 0)
				{
					menu_action = MENU_ACTION_RESTART;
					clean();
					load("assets/editor/editor.json");
				}
			}
			break;

		case MENU_EVENT_DO_NOTHING:
		default:
			//printf("params: %s\n", event.param.c_str());
			break;
	}
}

bool Menu::shouldStartGame() {
	return start_game;
}

bool Menu::shouldQuit() {
	return quit_requested;
}

int Menu::getMenuOption() {
	return menu_action;
}

std::string Menu::getParam() {
	return event_param;
}

void Menu::setMenuOption(int opt) {
	menu_action = opt;
}

void Menu::passEditor(Editor* edit) {
	if (editor != nullptr)
	{
		editor->setEdit(edit);
	}
}