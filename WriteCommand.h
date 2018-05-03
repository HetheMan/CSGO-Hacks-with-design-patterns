#pragma once
#include "Command.h"
class WriteCommand :
	public Command
{
public:
	WriteCommand();
	~WriteCommand();

	virtual int execute() =0;

};

