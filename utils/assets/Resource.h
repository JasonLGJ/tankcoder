#pragma once

#include <string>

class Resource {
	public:
		Resource();
		void setName(std::string name);
		std::string getName();
	private:
		int potato;
		std::string name;
};