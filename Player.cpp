#include "Player.h"



Player::Player()
{

}


Player::Player(int player_health, int player_team, int i_Glow,DWORD address)
{
	this->player_health = player_health,
		this->player_team = player_team;
	this->i_Glow = i_Glow;
	this->dwEntityAddress = address;
}

Player::Player(DWORD address)
{
	this->dwEntityAddress = address;
}

Player::~Player()
{
}
