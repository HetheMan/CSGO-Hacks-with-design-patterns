#pragma once
#include <windows.h>
class Player
{
public:
	Player();
	Player(int player_health, int player_team, int i_Glow, DWORD address);
	~Player();
	Player(DWORD address);

	int getPlayer_health()  { return this->player_health; }
	void setPlayer_health(int val) { this->player_health = val; }
	int getPlayer_team()  { return player_team; }
	void setPlayer_team(int val) { this->player_team = val; }
	int getGlow()  { return this->i_Glow; }
	void setGlow(int val) { this->i_Glow = val; }
	DWORD getDwEntityAddress() { return this->dwEntityAddress; }
	void setDwEntityAddress(DWORD val) { this->dwEntityAddress = val; }
	Player(int player_health, int player_team, int i_Glow);
	
	//	int player_health;
private:
	int player_health;
	int player_team;
	int i_Glow;
	DWORD dwEntityAddress;

};

