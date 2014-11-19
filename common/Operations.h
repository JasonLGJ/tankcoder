#pragma once

enum opCodes {
	OPCODE_UNUSED,
	OPCODE_BEGIN,
	OPCODE_END,
	OPCODE_WAIT,
	OPCODE_TURN_LEFT,
	OPCODE_TURN_RIGHT,
	OPCODE_GO_FORWARD,
	OPCODE_SHOOT,
	OPCODE_JUMP,
	OPCODE_JUMP_RAND
};

const std::string opNames[] = {
	"Unused",
	"Begin",
	"End",
	"Wait",
	"Left",
	"Right",
	"Go",
	"Shoot"
};