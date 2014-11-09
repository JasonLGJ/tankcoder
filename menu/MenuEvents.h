#pragma once
#include <string>

enum event_type {
	MENU_EVENT_DO_NOTHING,
	MENU_EVENT_SWAP_MENU,
	MENU_EVENT_START_GAME,
	MENU_EVENT_QUIT_GAME
};

struct MenuEvent {
	event_type action;
	std::string param;
};

static void split_text(std::string& text, std::string& action, std::string& param) {
	int pos = 0;

	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] == ' ')
		{
			pos = i;
			break;
		}
	}

	action = text.substr(0, pos);
	param = text.substr(pos+1);
}

static MenuEvent create_event(std::string text) {
	MenuEvent eve;
	
	//split text
	std::string act, par;

	split_text(text, act, par);

	if (act.compare("start_game") == 0)
	{
		eve.action = MENU_EVENT_START_GAME;
	}
	else if (act.compare("swap_menu") == 0) 
	{
		eve.action = MENU_EVENT_SWAP_MENU;
	}
	else if (act.compare("quit") == 0)
	{
		eve.action = MENU_EVENT_QUIT_GAME;
	}
	else
	{
		eve.action = MENU_EVENT_DO_NOTHING;
	}

	eve.param = par;

	return eve;
}
