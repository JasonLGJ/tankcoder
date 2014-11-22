#pragma once

#include <fstream>
#include <vector>
#include "../common/Statement.h"

class Editor {
	public:
		Editor();
		void save(std::string filename);
		int map_instruction(std::string name);
		void generate_statement(std::string operation);
		std::vector<Statement> get_content();
		void fill();
		void clean();
	private:
		std::vector<Statement> stats;
};