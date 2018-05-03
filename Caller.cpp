#include "Caller.h"



Caller::Caller()
{
}


Caller::Caller(Command &theCommand)
{
	this->theCommand = &theCommand;
}

Caller::~Caller()
{
}

void Caller::execute()
{
	theCommand->execute();
}
