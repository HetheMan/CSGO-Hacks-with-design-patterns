#pragma once
#include <windows.h>
#include <iostream>
#include "MyMemoryManager.h"
#include "offsets.h"
#include "Player.h"
class Command
{
public:
	Command();
	~Command();
	virtual int execute() = 0;
protected:
	MyMemoryManager * manager;
};

