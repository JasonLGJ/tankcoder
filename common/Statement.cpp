#include "Statement.h"

Statement::Statement() {
	opcode = OPCODE_UNUSED;
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

std::string Statement::toObj() {
	return std::to_string(opcode) + " " + std::to_string(address);
}