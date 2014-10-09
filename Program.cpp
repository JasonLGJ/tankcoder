#include "Program.h"

Program::Program() {
	finish = false;
	ipSearch = 0;
}

void Program::load(std::string filename) {

}

void Program::execute() {
	if (!tank.isAlive())
	{
		finish = true;
		return;
	}

	if (onShootingRange())
	{
		//STUB
	}
	else if (onVisionRange())
	{
		//STUB
	}
	else
	{
		doTask(searching[ipSearch]);
	}
}

void doTask(Statement stat) {
	switch(stat.getOpCode())
	{
		case OPCODE_TURN_LEFT:
			tank.turnLeft();
			break;

		case OPCODE_TURN_RIGHT:
			tank.turnRight();
			break;

		case OPCODE_TURN_GO_FORWARD:
			tank.goForward();
			break;

		case OPCODE_TURN_SHOOT:
			tank.shoot();
			break;

		case OPCODE_UKNOWN:
		default:
			break;
	}
}

bool Program::isFinished() {
	return finish;
}

bool Program::onVisionRange() {
	//STUB
	return false;
}

bool Program::onShootingRange() {
	//STUB
	return false;
}