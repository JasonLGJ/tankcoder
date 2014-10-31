#include "Resource.h"

Resource::Resource() {
	potato = 0;
}

void Resource::setName(std::string name) {
	this->name = name;
}

std::string Resource::getName() {
	return name;
}