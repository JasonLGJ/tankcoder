#pragma once

#include <fstream>
#include <vector>
#include "../common/Statement.h"

class Editor {
	public:
		Editor();
		void save(std::string filename);
	private:
		std::vector<Statement> stats;
};