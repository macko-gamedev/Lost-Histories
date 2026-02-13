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
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, //       XXXXXXXX
	{ ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', '>' }, //    XXXX      >
	{ ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' }, //   XX       XXX
	{ ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'E', ' ', 'X', 'X', 'X', ' ', ' ' }, //   X      XXX
	{ ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ' }, //   XX    XX
	{ ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ' }, //    XX    XXX
	{ ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ' }, //     X      XX
	{ ' ', ' ', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ' }, //  XXXX       X
	{ ' ', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', ' ' }, // XX  XX      X
	{ ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'E', ' ', 'X', 'X' }, // X    XXXXX  XX
	{ ' ', 'X', ' ', 'P', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X' }, // X P      X   X
	{ ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' }, // X            X
	{ ' ', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X' }, // XX    XXXX   X
	{ ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X', ' ', ' ', 'X' }, //  XXXXXX  XX  X
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X' }  //           XXXX
	};
}