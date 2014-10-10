#include "Statement.h"

Statement::Statement() {
	opcode = -1;
}

void Statement::setOpCode(int code) {
	opcode = code;
}

int Statement::getOpCode() {
	return opcode;
}

std::string Statement::getOpName() {
	return opNames[opcode];
}
