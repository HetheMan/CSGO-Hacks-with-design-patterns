#pragma once
#include "Command.h"
class Caller
{
public:
	Caller();
	~Caller();
	Command * getCommand() const { return theCommand; }
	void setCommand(Command & val) { this->theCommand = &val; }
	void execute();
	Caller(Command &theCommand);
private:
	Command * theCommand;
};

