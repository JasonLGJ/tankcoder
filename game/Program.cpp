#include "Program.h"

Program::Program() {
	finish = false;
	ipSearch = ipVision = ipShooting = 0;
}

void Program::load(std::string filename) {
	std::ifstream file(filename.c_str(), std::ios::in);
	std::string line;

	int selection = 0;

	if (file.is_open())
	{
		while (!file.eof())
		{
			int opc, adr;

			file >> opc;
			file >> adr;

			if (opc == OPCODE_BEGIN)
				continue;

			if (opc == OPCODE_END)
			{
				selection++;
				continue;
			}

			Statement stat;
			stat.setOpCode(opc);
			stat.setAddress(adr);

			switch (selection)
			{
				case 0:
					searching.push_back(stat);
					break;

				case 1:
					vision.push_back(stat);
					break;

				case 2:
					shooting.push_back(stat);
					break;

				default:
					break;
			}
		}
	}
	else
	{
		std::cout << "File not found" << std::endl;
	}
}

void Program::execute() {
	if (!tank->isAlive())
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
		ipSearch++;

		if (ipSearch >= searching.size())
			ipSearch = 0;
	}
}

void Program::print() {
	std::cout << "[Searching]" << std::endl;
	for (int i = 0; i < searching.size(); i++)
	{
		std::cout << searching[i].getOpName() << std::endl;
	}

	std::cout << "[Vision]" << std::endl;
	for (int i = 0; i < vision.size(); i++)
	{
		std::cout << vision[i].getOpName() << std::endl;
	}

	std::cout << "[Shooting]" << std::endl;
	for (int i = 0; i < shooting.size(); i++)
	{
		std::cout << shooting[i].getOpName() << std::endl;
	}
}

void Program::doTask(Statement stat) {
	switch(stat.getOpCode())
	{
		case OPCODE_TURN_LEFT:
			tank->turnLeft();
			break;

		case OPCODE_TURN_RIGHT:
			tank->turnRight();
			break;

		case OPCODE_TURN_GO_FORWARD:
			tank->goForward();
			break;

		case OPCODE_TURN_SHOOT:
			tank->shoot();
			break;

		case OPCODE_WAIT:
		case OPCODE_UNUSED:
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

void Program::setTank(Tank* t) {
	tank = t;
}