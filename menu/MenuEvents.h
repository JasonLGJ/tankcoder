#pragma once

enum menu_event {
	MENU_EVENT_ITEM_HOVER,
	MENU_EVENT_ITEM_PRESSED,
	MENU_EVENT_ITEM_RELEASED
};

struct MenuEvent {
	menu_event event;
	int id;
};
