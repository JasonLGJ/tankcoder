#include "Statement.h"

Statement::Statement() {
	opcode = OPCODE_UKNOWN;
}

void Statement::setOpCode(int code) {
	opcode = code;
}

int Statement::getOpCode() {
	return opcode;
}
