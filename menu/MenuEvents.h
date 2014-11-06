#pragma once

enum event_type {
	MENU_EVENT_ITEM_HOVER,
	MENU_EVENT_ITEM_PRESSED,
	MENU_EVENT_ITEM_RELEASED
};

struct MenuEvent {
	event_type event;
	int id;
};
