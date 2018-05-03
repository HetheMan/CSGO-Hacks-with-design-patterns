#include "ReadCommand.h"



ReadCommand::ReadCommand()
{
}


ReadCommand::ReadCommand(MyMemoryManager &manager)
{
	this->manager = &manager;
}

ReadCommand::~ReadCommand()
{
}
