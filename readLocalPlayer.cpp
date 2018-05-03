#include "readLocalPlayer.h"



readLocalPlayer::readLocalPlayer()
{
}


readLocalPlayer::readLocalPlayer(MyMemoryManager &manager, Player &localPlayer):ReadCommand(manager)
{
	this->localPlayer = &localPlayer;
}

readLocalPlayer::~readLocalPlayer()
{
}

int readLocalPlayer::execute()
{
	DWORD localPlayerAddress;
	int player_team;
	//Reads
	this->manager->Read<DWORD>(manager->getClientBase() +signatures::dwLocalPlayer, localPlayerAddress);
	this->manager->Read<int>(localPlayerAddress + netvars::m_iTeamNum,player_team);
	//Sets player attributes
	this->localPlayer->setDwEntityAddress(localPlayerAddress);
	this->localPlayer->setPlayer_team(player_team);
	return 0;
}
