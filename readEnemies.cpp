#include "readEnemies.h"



readEnemies::readEnemies()
{
}


readEnemies::readEnemies(MyMemoryManager &manager, Player &localPlayer): ReadCommand(manager)
{
	this->localPlayer = &localPlayer;
}

readEnemies::readEnemies(MyMemoryManager &manager, Player &localPlayer, vector<Player> &enemies) :ReadCommand(manager)
{
	this->localPlayer = &localPlayer;
	this->enemies = &enemies;
}

readEnemies::~readEnemies()
{
}

int readEnemies::execute()
{
	//We declare the information of the player.
	int e_team = 0;
	int e_health = 0;
	int e_glow = 0;
	DWORD dwEntity; //Guardamos temporalmente para crear el objeto.
	for (int i = 0; i < 64; i++)
	{
		e_team = -1;
		e_health = -1;
		//Loop From Base Entity Address by 0x10 On Each Iteration si da error, se ha leido mal
		if (!this->manager->Read<DWORD>((this->manager->getClientBase() + signatures::dwEntityList) + (i * 0x10), dwEntity))
		{
			cout << "No he podido leer entidad" << endl;
		} //64 bytes.
		if (dwEntity == 0) { continue; }
		//Prevent Crash From Reading Null Pointer - also stop counting when weve read the last entity

		if (!this->manager->Read<int>(dwEntity + netvars::m_iTeamNum, e_team)) {
			cout << "No he podido leer equipo de la entidad" << endl;
		}
		//Health
		if (!this->manager->Read<int>(dwEntity + netvars::m_iHealth, e_health)) {
			cout << "No he podido leer equipo de la entidad" << endl;
		}
		//iGlow
		if (!this->manager->Read<int>(dwEntity + netvars::m_iGlowIndex, e_glow)) {
			cout << "No he podido leer glow de la entidad" << endl;
		}

		//If An Enemy Has Been Found, create EntyObject and push Into Array.

		if (e_team != this->localPlayer->getPlayer_team() && e_team > 1)
		{
			this->enemies->push_back(Player(e_health, e_team, e_glow, dwEntity)); // You can add a check here to see if the module is already there ;)														 //i_Count++;
		}
	}
	return 0;
}
