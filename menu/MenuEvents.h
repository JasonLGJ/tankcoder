#pragma once
#include <string>

enum event_type {
	MENU_EVENT_DO_NOTHING,
	MENU_EVENT_SWAP_MENU,
	MENU_EVENT_START_GAME,
	MENU_EVENT_QUIT_GAME,
	MENU_EVENT_DROP,
	MENU_EVENT_SCROLL_EDITOR,
	MENU_EVENT_MODIFY_LEVEL,
	MENU_EVENT_SWITCH_MUSIC
};

struct MenuEvent {
	event_type action;
	std::string param;
};

static void split_drop(std::string& text, std::string& action, float& x, float& y) {
	int pos1 = -1, pos2 = -1;

	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] == ',')
		{
			if (pos1 == -1)
				pos1 = i+1;
			else
			{
				pos2 = i+1;
				break;
			}
		}
	}

	if (pos1 == -1 || pos2 == -1)
	{
		action = "";
		x = y = 0.0f;
	}
	else
	{
		action = text.substr(0,pos1-1);
		
		std::string strx = text.substr(pos1, pos2 - pos1 - 1);
		std::string stry = text.substr(pos2);

		x = std::atof(strx.c_str());
		y = std::atof(stry.c_str());
	}
}

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
	else if (act.compare("dropped") == 0)
	{
		eve.action = MENU_EVENT_DROP;
	}
	else if (act.compare("scroll") == 0)
	{
		eve.action = MENU_EVENT_SCROLL_EDITOR;
	}
	else if (act.compare("level") == 0)
	{
		eve.action = MENU_EVENT_MODIFY_LEVEL;
	}
	else if (act.compare("switch_music") == 0)
	{
		eve.action = MENU_EVENT_SWITCH_MUSIC;
	}
	else
	{
		eve.action = MENU_EVENT_DO_NOTHING;
	}

	eve.param = par;

	return eve;
}
