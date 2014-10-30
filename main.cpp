#include "Game.h"

#include <iostream>
#include "libs/json/json.h"

int main() {
	Json::Value root;
	Json::Reader reader;

	if (!reader.parse("test.json", root ))
	{
		// report to the user the failure and their locations in the document.
		std::cout  << "Failed to parse configuration\n" << reader.getFormattedErrorMessages();
		return -1;
	}

	std::cout << root << std::endl;

	/*
	Game g;
	return g.execute();
	*/
}
