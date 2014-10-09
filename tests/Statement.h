#pragma once
#include <string>

enum opCodes {
	OPCODE_UKNOWN,
	OPCODE_TURN_LEFT,
	OPCODE_TURN_RIGHT,
	OPCODE_TURN_GO_FORWARD,
	OPCODE_TURN_SHOOT
};

const std::string opNames[5] = {
	"Uknown",
	"Left",
	"Right",
	"Go",
	"Shoot"
};

class Statement {
	public:
		Statement();
		//
		void setOpCode(int code);
		int getOpCode();
		std::string getOpName();
	private:
		int opcode;
};