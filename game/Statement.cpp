#include "Statement.h"

Statement::Statement() {
<<<<<<< HEAD:game/Statement.cpp
	opcode = OPCODE_UNUSED;
=======
	opcode = -1;
>>>>>>> 20a751524fced1cd1d1ffea2fd479c02c640e36e:Game/Statement.cpp
}

void Statement::setOpCode(int code) {
	opcode = code;
}

int Statement::getOpCode() {
	return opcode;
}

void Statement::setAddress(int addr) {
	address = addr;
}

int Statement::getAddress() {
	return address;
}

std::string Statement::getOpName() {
	return opNames[opcode];
}
