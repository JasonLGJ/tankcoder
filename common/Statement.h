#pragma once
#include <string>
#include "Operations.h"

class Statement {
	public:
		Statement();
		//
		void setOpCode(int code);
		int getOpCode();
		void setAddress(int addr);
		int getAddress();
		std::string getOpName();
	private:
		int opcode;
		int address;
};