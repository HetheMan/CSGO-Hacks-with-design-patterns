#pragma once
#include "Command.h"
class ReadCommand :
	public Command
{
public:
	ReadCommand();
	~ReadCommand();
	ReadCommand(MyMemoryManager &manager);
	virtual int execute() = 0;
};

