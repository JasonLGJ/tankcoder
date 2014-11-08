#include "Resource.h"

Resource::Resource() {
	name = "";
}

void Resource::setName(std::string name) {
	this->name = name;
}

std::string Resource::getName() {
	return name;
}

std::shared_ptr<Resource> Resource::get(std::string name) {
	for (int i = 0; i < res_list.size(); i++)
	{
		if (res_list[i]->getName().compare(name) == 0)
		{
			return res_list[i];
		}
	}

	return nullptr;
}

double Resource::getNumber(std::string name, double def) {
	if (number_list.count(name))
		return number_list[name];
	else
		return def;
}

bool Resource::getBool(std::string name, bool def) {
	if (bool_list.count(name))
		return bool_list[name];
	else
		return def;
}

std::string Resource::getString(std::string name, std::string def) {
	if (str_list.count(name))
		return str_list[name];
	else
		return def;
}

void Resource::getArray(std::string name, std::vector<double>& vec) {
	if (str_list.count(name))
		vec = array_list[name];
}

void Resource::addResource(std::shared_ptr<Resource> res) {
	res_list.push_back(res);
}

void Resource::addBool(std::string name, bool boolean) {
	bool_list[name] = boolean;
}

void Resource::addNumber(std::string name, double number) {
	number_list[name] = number;
}

void Resource::addString(std::string name, std::string str) {
	str_list[name] = str;
}

void Resource::addArrayNum(std::string name, double num) {
	array_list[name].push_back(num);
}