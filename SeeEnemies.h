#pragma once
#include "WriteCommand.h"
class SeeEnemies :
	public WriteCommand
{
public:
	SeeEnemies();
	~SeeEnemies();
	SeeEnemies(MyMemoryManager &manager, vector<Player> &enemigos);
	virtual int execute() override;
	static float SanitizeColor(int value);
	static void glow_player(DWORD mObj, float r, float g, float b, MyMemoryManager &m);
private:
	vector<Player> *enemigos;
};

