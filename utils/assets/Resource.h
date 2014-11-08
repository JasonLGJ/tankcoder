#pragma once

#include <memory>
#include <string>
#include <vector>
#include <map>

#include "../../libs/json/gason.h"

enum resourceType {
	RES_TYPE_NUMBER,
	RES_TYPE_BOOLEAN,
	RES_TYPE_STRING,
	RES_TYPE_NULL,
	RES_TYPE_OBJECT,
	RES_TYPE_ARRAY
};

class Resource {
	public:
		Resource();
		void setName(std::string name);
		std::string getName();
		//
		std::shared_ptr<Resource> get(std::string name);
		double getNumber(std::string name, double def = 0.0);
		bool getBool(std::string name, bool def = false);
		std::string getString(std::string name, std::string def = "");
		void getArray(std::string name, std::vector<double>& vec);
		//
		void addResource(std::shared_ptr<Resource> res);
		void addBool(std::string name, bool boolean);
		void addNumber(std::string name, double number);
		void addString(std::string name, std::string str);
		void addArrayNum(std::string name, double number);
	private:
		std::string name;
		std::vector<std::shared_ptr<Resource>> res_list;
		std::map<std::string, bool> bool_list;
		std::map<std::string, double> number_list;
		std::map<std::string, std::string> str_list;
		std::map<std::string, std::vector<double>> array_list;
};