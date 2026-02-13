#include "DungeonGlacier.h"

// X = Wall, E = Enemy, > = Next Room, <  = Last Room, P = Player
 
//DungeonGlacier::DungeonGlacier() { }

DungeonGlacier::DungeonGlacier()
{
	this->dungeon_name = "Glacier Wasteland";
	this->dungeon_room = 1;
	this->pos_x = 3;
	this->pos_y = 10;
	this->dungeon_map =
	{
	{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, //       XXXXXXXX
	{ 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', '>' }, //    XXXX      >
	{ 'O', 'O', 'O', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' }, //   XX       XXX
	{ 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'O', 'O' }, //   X      XXX
	{ 'O', 'O', 'O', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'O', 'O', 'O', 'O' }, //   XX    XX
	{ 'O', 'O', 'O', 'O', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'O', 'O' }, //    XX    XXX
	{ 'O', 'O', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'O' }, //     X      XX
	{ 'O', 'O', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O' }, //  XXXX       X
	{ 'O', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'O' }, // XX  XX      X
	{ 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X' }, // X    XXXXX  XX
	{ 'O', 'X', ' ', 'P', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X' }, // X P      X   X
	{ 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' }, // X            X
	{ 'O', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X' }, // XX    XXXX   X
	{ 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'X', 'X', ' ', ' ', 'X' }, //  XXXXXX  XX  X
	{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'X' }  //           XXXX
	};
}