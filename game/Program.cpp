#include "Program.h"
#include "Tank.h"

Program::Program()
{
    finish = false;
    ipSearch = ipVision = ipShooting = 0;
}

bool Program::load(std::string filename)
{
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

        return true;
    }
    else
    {
        std::cout << "File not found" << std::endl;
        return false;
    }
}

void Program::execute()
{
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

void Program::print()
{
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

void Program::doTask(Statement stat)
{
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

bool Program::isFinished()
{
    return finish;
}

bool Program::onVisionRange()
{
    int Ry1,Ry2,Ry3,Ry4,Ry5,Ry6,Ry7,Ry8,Ry9;
    int Rx1,Rx2,Rx3,Rx4,Rx5,Rx6,Rx7,Rx8,Rx9;

    int x=tank->getX();
    int y=tank->getY();
    switch(tank->getDirection())
    {
    case TANK_DIRECTION_UP:
        //vision cerca
        Rx1=x-1;
        Ry1=y-1;
        Rx2=x;
        Ry2=y-1;
        Rx3=x+1;
        Ry3=y-1;
        //vision media
        Rx4=Rx1;
        Ry4=y-2;
        Rx5=x;
        Ry5=y-2;
        Rx6=Rx3;
        Ry6=y-2;
        //vision larga
        Rx7=Rx4;
        Ry7=y-3;
        Rx8=x;
        Ry8=y-3;
        Rx9=Rx6;
        Ry9=y-3;
        if(x==Rx1&&y==Ry1||x==Rx2&&y==Ry2||x==Rx3&&y==Ry3 ||x==Rx4&&y==Ry4||x==Rx5&&y==Ry5||x==Rx6&&y==Ry6||x==Rx7&&y==Ry7||x==Rx8&&y==Ry8||x==Rx9&&y==Ry9)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;

    case TANK_DIRECTION_LEFT_UP:
        //vision cerca
        Rx1=x-1;
        Ry1=y+1;
        Rx2=x-1;
        Ry2=y-1;
        Rx3=x;
        Ry3=y-1;
        //vision media
        Rx4=x-2;
        Ry4=y;
        Rx5=x-2;
        Ry5=y-2;
        Rx6=x-1;
        Ry6=y-2;
        //vision lejos
        Rx7=x-3;
        Ry7=y-1;
        Rx8=x-3;
        Ry8=y-3;
        Rx9=x-2;
        Ry9=y-3;
        if(x==Rx1&&y==Ry1||x==Rx2&&y==Ry2||x==Rx3&&y==Ry3 ||x==Rx4&&y==Ry4||x==Rx5&&y==Ry5||x==Rx6&&y==Ry6||x==Rx7&&y==Ry7||x==Rx8&&y==Ry8||x==Rx9&&y==Ry9)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;

    case TANK_DIRECTION_LEFT_DOWN:
        //vision cerca
        Rx1=x;
        Ry1=y+1;
        Rx2=x-1;
        Ry2=y+1;
        Rx3=x-1;
        Ry3=y-1;
        //vision media
        Rx4=x-1;
        Ry4=y+2;
        Rx5=x-2;
        Ry5=y+2;
        Rx6=x-2;
        Ry6=y;
        //vision lejos
        Rx7=x-2;
        Ry7=y+3;
        Rx8=x-3;
        Ry8=y+3;
        Rx9=x-3;
        Ry9=y+1;
        if(x==Rx1&&y==Ry1||x==Rx2&&y==Ry2||x==Rx3&&y==Ry3 ||x==Rx4&&y==Ry4||x==Rx5&&y==Ry5||x==Rx6&&y==Ry6||x==Rx7&&y==Ry7||x==Rx8&&y==Ry8||x==Rx9&&y==Ry9)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;

    case TANK_DIRECTION_DOWN:
        //vision cerca
        Rx1=x-1;
        Ry1=y+1;
        Rx2=x;
        Ry2=y+1;
        Rx3=x+1;
        Ry3=y+1;
        //vision lejos
        Rx4=Rx1;
        Ry4=y+2;
        Rx5=x;
        Ry5=y+2;
        Rx6=Rx3;
        Ry6=y+2;
        //vision lejos
        Rx7=Rx4;
        Ry7=y+3;
        Rx8=x;
        Ry8=y+3;
        Rx9=Rx6;
        Ry9=y+3;
        if(x==Rx1&&y==Ry1||x==Rx2&&y==Ry2||x==Rx3&&y==Ry3 ||x==Rx4&&y==Ry4||x==Rx5&&y==Ry5||x==Rx6&&y==Ry6||x==Rx7&&y==Ry7||x==Rx8&&y==Ry8||x==Rx9&&y==Ry9)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;

    case TANK_DIRECTION_RIGHT_DOWN:
        //vision cerca
        Rx3=x;
        Ry1=y+1;
        Rx2=x+1;
        Ry2=y+1;
        Rx1=x+1;
        Ry3=y-1;
        //vision media
        Rx6=x+1;
        Ry4=y+2;
        Rx5=x+2;
        Ry5=y+2;
        Rx4=x+2;
        Ry6=y;
        //vision lejos
        Rx9=x+2;
        Ry7=y+3;
        Rx8=x+3;
        Ry8=y+3;
        Rx7=x+3;
        Ry9=y+1;

        if(x==Rx1&&y==Ry1||x==Rx2&&y==Ry2||x==Rx3&&y==Ry3 ||x==Rx4&&y==Ry4||x==Rx5&&y==Ry5||x==Rx6&&y==Ry6||x==Rx7&&y==Ry7||x==Rx8&&y==Ry8||x==Rx9&&y==Ry9)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case TANK_DIRECTION_RIGHT_UP:
        //vision cerca
        Rx3=x+1;
        Ry1=y-1;
        Rx2=x+1;
        Ry2=y-1;
        Rx1=x;
        Ry3=y+1;
        //vision media
        Rx6=x+2;
        Ry4=y-2;
        Rx5=x+2;
        Ry5=y-2;
        Rx4=x+1;
        Ry6=y;
        //vision lejos
        Rx9=x+3;
        Ry7=y-3;
        Rx8=x+3;
        Ry8=y-3;
        Rx7=x+2;
        Ry9=y-1;


        if(x==Rx1&&y==Ry1||x==Rx2&&y==Ry2||x==Rx3&&y==Ry3 ||x==Rx4&&y==Ry4||x==Rx5&&y==Ry5||x==Rx6&&y==Ry6||x==Rx7&&y==Ry7||x==Rx8&&y==Ry8||x==Rx9&&y==Ry9)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;

    default:
        break;
    }


}

bool Program::onShootingRange()
{
    return tank->onShootingRange();
}

void Program::setTank(Tank* t)
{
    tank = t;
}
