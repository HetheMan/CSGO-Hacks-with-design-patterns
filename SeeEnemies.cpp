#include "SeeEnemies.h"



SeeEnemies::SeeEnemies()
{
}


SeeEnemies::SeeEnemies(MyMemoryManager &manager, vector<Player> &enemigos)
{
	this->manager = &manager;
	this->enemigos = &enemigos;
}

SeeEnemies::~SeeEnemies()
{
}

int SeeEnemies::execute()
{
	DWORD pointerToGlow;

	this->manager->Read<DWORD>(manager->getClientBase() + signatures::dwGlowObjectManager, pointerToGlow);
	float Enemy = SanitizeColor(140);
	int shotsfired;
	while (true) {
		for (auto m : *this->enemigos) {
			cout << "Soy team: " << m.getPlayer_team() << endl;
			cout << "Soy vuda: " << m.getPlayer_health() << endl;
			cout << "Soy address, entidad" << m.getDwEntityAddress() << endl;
			cout << "Soy iglow, entidad" << m.getGlow() << endl;
			DWORD offset = m.getGlow() * 0x38;
			glow_player(pointerToGlow + offset, 0, Enemy, 0, *manager);
		}
	}
	return 0;
}

float SeeEnemies::SanitizeColor(int value)
{
		if (value > 255) value = 255;
		if (value < 0) value = 0;
		return (float)value / 255;
}

void SeeEnemies::glow_player(DWORD mObj, float r, float g, float b, MyMemoryManager &m)
{
		m.Write<float>(mObj + 0x4, r);
		m.Write<float>(mObj + 0x8, g);
		m.Write<float>(mObj + 0xC, b);
		m.Write<float>(mObj + 0x10, 1.0f);
		m.Write<BOOL>(mObj + 0x24, true);
		m.Write<BOOL>(mObj + 0x25, false);
		m.Write<BOOL>(mObj + 0x26, false);
}
