# CSGO case study with Command Design Pattern

## What is this?

It's a wallhack made in c++ using the Command design pattern to call for READ, WRITE functions and finally the Wallhack or Bunnyhop hack.

## What else should I know?

This hack uses non-auto-updated offsets, if you want it to work you should update them with new ones.

## CLASSES

### MyMemoryManager
Searches for process and gets first memory address of modules.
### Player
Represents enemy, team and self player stats.
### Offsets
Static class, change each time there is an update.
### Caller
Class that recieves a command and executes it.
### Command
Interface of Commands.
### ReadCommand
Interface - Type of Command that will only read on memory.
### WriteCommand
Interface - Type of Command that will only write on memory.
### readEnemies
Command that read enemies from memory.
### readLocalPlayer
Command that read local player info from memory.
### SeeEnemies
Command that writes in memory to glow enemies <- Wallhack
