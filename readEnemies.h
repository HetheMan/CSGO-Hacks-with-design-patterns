#pragma once
#include "ReadCommand.h"
#include <vector>
#include "Player.h"
#include "offsets.h"
using namespace std;
class readEnemies :
	public ReadCommand

{
public:
	readEnemies();
	~readEnemies();
	readEnemies(MyMemoryManager &manager, Player &localPlayer);
	readEnemies(MyMemoryManager &manager, Player &localPlayer, vector<Player> &enemies);

	virtual int execute() override;

	std::vector<Player> *getEnemigos() const { return enemies; }
	void setEnemigos(std::vector<Player> &val) { enemies = &val; }
	//	vector<Player> enemigos;
private:
	std::vector<Player> *enemies;
	Player *localPlayer;
};