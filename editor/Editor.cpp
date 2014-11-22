#include "Editor.h"

Editor::Editor() {}

void Editor::save(std::string filename) {
	std::ofstream file(filename.c_str());

	for (int i = 0; i < stats.size(); i++)
	{
		file << stats[i].toObj() << std::endl;
	}

	file.close();
}

std::vector<Statement> Editor::get_content() {
	return stats;
}

void Editor::generate_statement(std::string operation) {
	Statement st;
	st.setOpCode(map_instruction(operation));
	st.setAddress(-1);

	stats.push_back(st);
}

void Editor::fill() {
	for (int i = stats.size() - 1; i >= 0; i++)
	{
		if (stats[i].getOpCode() == OPCODE_JUMP_RAND)
			stats[i].setAddress(stats.size() - 1);
	}
}

int Editor::map_instruction(std::string name) {
	printf("%s\n", name.c_str());
	
	if (name.compare("turn_left") == 0)
	{
		return OPCODE_TURN_LEFT;
	}
	else if (name.compare("turn_right") == 0)
	{
		return OPCODE_TURN_RIGHT;
	}
	else if (name.compare("forward") == 0)
	{
		return OPCODE_GO_FORWARD;
	}
	else if (name.compare("back") == 0)
	{
		return OPCODE_GO_BACKWARD;
	}
	else if (name.compare("wait") == 0)
	{
		return OPCODE_WAIT;
	}
	else if (name.compare("fire") == 0)
	{
		return OPCODE_SHOOT;
	}


	return OPCODE_UNUSED;
}

void Editor::clean() {
	stats.clear();
}