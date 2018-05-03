#include "Command.h"
#include "Caller.h"
#include "readLocalPlayer.h"
#include "readEnemies.h"
#include "SeeEnemies.h"
int main(){
	MyMemoryManager manager("csgo.exe");
	manager.GrabModule("client.dll");
	manager.setClientDLL(manager.GetModule("client.dll"));
	Caller reader = Caller();
	Caller writer = Caller();
	//Set commands and entities we're gonna use
	vector<Player> enemies;
	Player localPlayer = Player();

	//Create Commands
	readLocalPlayer readLocalPlayerCommand = readLocalPlayer(manager, localPlayer);
	readEnemies readEnemiesCommand = readEnemies(manager, localPlayer,enemies);
	//We read localPlayerAddress and give it to Player
	reader.setCommand(readLocalPlayerCommand);
	reader.execute();
	//Now we read enemies
	reader.setCommand(readEnemiesCommand);
	reader.execute();
	//Now that we have everything we need we use wallhack.
	SeeEnemies wallhack = SeeEnemies(manager, enemies);
	writer.setCommand(wallhack);
	writer.execute();




	return 0;
}