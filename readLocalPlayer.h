#pragma once
#include "ReadCommand.h"
#include "Player.h"
class readLocalPlayer:
	public ReadCommand
{
public:
	readLocalPlayer();
	readLocalPlayer(MyMemoryManager &manager, Player &localPlayer);
	~readLocalPlayer();
	virtual int execute() override;
private:
	Player * localPlayer;
};

