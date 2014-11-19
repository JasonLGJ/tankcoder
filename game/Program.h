#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

#include "../common/Statement.h"
#include "Tank.h"


class Program {
	public:
		Program();
		//
		void execute();
		bool isFinished();
		bool load(std::string filename);
		bool load(std::vector<Statement>& sts);
		void doTask(Statement stat);
		void print();
		//
		bool onVisionRange();
		bool onShootingRange();
		//
		void setTank(Tank* t);
		void clear();
	private:
		Tank* tank;
		bool finish;
		std::vector<Statement> searching;
		std::vector<Statement> vision;
		std::vector<Statement> shooting;
		int ipSearch;
		int ipVision;
		int ipShooting;
};
