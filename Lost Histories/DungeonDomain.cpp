#include "DungeonDomain.h"

// X = Wall, ! = Enemy, > = Next Room, <  = Last Room, + = Player

DungeonDomain::DungeonDomain(string N_Name)
{
	this->STR_Dungeon_Name = "Domain";
	this->INT_Dungeon_Room = 1;
	this->INT_Pos_X = 3;
	this->INT_Pos_Y = 7;
	this->STR_Player_Name = N_Name;
	this->VEC_Dungeon_Map =
	{
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, //       XXXXXXXX
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', '>' }, //    XXXX      >
			{ 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' }, //   XX       XXX
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X' }, //   X      XXX
			{ 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X' }, //   XX    XX
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X' }, //    XX    XXX
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' }, //     X      XX
			{ 'X', 'X', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' }, //  XXXX       X
			{ 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' }, // XX  XX      X
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X' }, // X    XXXXX  XX
			{ 'X', 'X', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X' }, // X P      X   X
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' }, // X            X
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X' }, // XX    XXXX   X
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X' }, //  XXXXXX  XX  X
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }  //           XXXX
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, // XXXX  XXXXX 
			{ 'X', '<', '+', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X' }, // <  XXXX   XX
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' }, // XX  X      XXX 
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', 'X' }, //  X     XX    X
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X' }, //  X      X    X
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' }, //  XX        XXX
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X' }, //   X       XX
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X' }, //   XXX XX   XX
			{ 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X' }, //   XX   XXX  XX
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X', 'X' }, //  XX     X  XX 
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' }, //  X  X      X   
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X', 'X' }, //  X      X  XX
			{ 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X' }, //  X   XX     XX
			{ 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '>' }, //  XXX         >
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }  //    XXXXXXXXXXX
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, // XXXX  XXXXXXXX 
			{ 'X', 'X', '?', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X' }, // X? XXXX   X  X
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', 'X', ' ', 'X', 'X' }, // XX  X   X X XX 
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X' }, //  X  X XXX X X 
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'X' }, //  X  X   X   X 
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X' }, //  XX   XXXXX X 
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X', 'X' }, //  XXXX     X X
			{ 'X', 'X', 'X', ' ', 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X' }, //  X XX XXXXX XX
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', '|', '>' }, //  X        X |>
			{ 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', 'X' }, //  X X XX X XXXX
			{ 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', 'X' }, //  X X XX X X X  
			{ 'X', 'X', 'X', ' ', 'X', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', 'X', 'X' }, //  X X    X X X
			{ 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', 'X' }, //  XXX XX X X XX
			{ 'X', 'X', '<', '+', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X' }, //  <      X    X
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }  //  XXXXXXXXXXXXX
		},
{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '>' },
			{ '<', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', 'X', ' ', 'X', 'X', 'X', ' ', ' ', 'X', ' ', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', 'X', ' ', ' ', 'X', 'X', 'X', ' ', 'X', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', ' ', 'X', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', 'X', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X' },
			{ '<', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '>', 'X', ' ', '*', 'X' },
			{ 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', 'X', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', 'X', 'X', ' ', ' ', 'X' },
			{ 'X', ' ', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', '?', ' ', ' ', ' ', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', ' ', '>' },
			{ 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', ' ', 'X', 'X', 'X', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', 'X', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', 'X' },
			{ '<', '+', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X' },
			{ '<', '+', ' ', ' ', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', '>' },
			{ 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', '>' },
			{ 'X', 'X', ' ', ' ', 'X', '*', 'X', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ '<', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '?', '|', ' ', ' ', '>' },
			{ '<', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '>' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ '<', '+', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X' },
			{ 'X', ' ', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X' },
			{ '<', '+', ' ', ' ', 'X', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X', 'X', 'X', 'X', ' ', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', 'X', 'X', ' ', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', 'X', 'X', ' ', 'X', 'X', ' ', 'X', 'X', ' ', ' ', '>' },
			{ 'X', 'X', 'X', ' ', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', '>' },
			{ 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X' },
			{ '<', '+', ' ', ' ', 'X', 'X', ' ', 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '>', 'X' },
			{ 'X', '<', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X' },
			{ 'X', '<', '+', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', '|', '>', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', '?', 'X', ' ', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', '<', '+', '?', ' ', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X', ' ', ' ', ' ', ' ', ' ', '?', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X', ' ', 'X', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
		}
	};

	this->VEC_Explored_Rooms = { true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false };
	this->MAP_New_Room_Text =
	{
		{ 1, { "..." } },
		{ 2, { "...", "Why must you come here?", "You do realise there are no achievements for this game" } },
		{ 3, { "...", "You feel a strong presence on this floor" } },
		{ 4, { "...", "Ah Atlantis, welcome back!", "That poor creature you beat down at the end", "You're a monster " + STR_Player_Name } },
		{ 5, { "...", "You feel a strong presence on this floor" } },
		{ 6, { "...", "Hey, you really think this is the last dungeon?", "Who knows...", "I mean I do...", "Maybe you can change the game a bit", "Literally..." } },
		{ 7, { "...", "Are you not bored?", "You could say I am, I DID add this dungeon for no reason really" } },
		{ 8, { "...", "You know, I did add physical skills today!", "Today is 22/05/2026!", "Wait... how is that possible?", "The year is currently 2067 no?" } },
		{ 9, { "...", "You feel a strong presence on this floor" } },
		{ 10, { "...", "I really enjoy RPGs, turn based combat is the best!", "Who am I even talking to?", STR_Player_Name + " > Don't ask me" } },
		{ 11, { "...", "Hey, have you figured out any secrets yet?", "You do realise this dungeon isn't the last secret", "Or perhaps I am lying to simply waste your time..." } },
		{ 12, { "...", "Your patience is incredible", "I must really applaud you for that", "How can you keep playing?", "It's a silly little text game what could POSSIBLY be so interesting?"} },
		{ 13, { "...", "Oooooooo, you're nearing the end!", "Or are you?", "I mean you wouldn't know", "Do me a favour and ALT + F4"} },
		{ 14, { "...", "You feel a strong presence on this floor" } },
		{ 15, { "...", "You feel a strong presence on this floor", "This is it...", "Are you happy?", "Are you satisfied?", "You're reaching the end", "Go on, fight him...", "Don't keep me waiting" } }
	};
	this->MAP_Encounter_Dialogue =
	{
		{ 3, {"..." } },
		{ 5, {"..." } },
		{ 9, {"..." } },
		{ 14, {"..." } },
		{ 15, {
				"...",
				"Macko > You really are relentless",
				"Macko > Honestly, you really sat there and beaten the other 14 floors?",
				"Macko > Now you're here...",
				"Macko > Face to face with me",
				"Macko > Ok then. Fine.",
				"Macko > I won't hold back",
				"Macko > I will really make this unfair for you",
				"Macko > Are you ready?"
			  }
		}
	};
	this->MAP_Encounter_Enemy =
	{
		{ 3, Enemy("Domain Keeper 1", 110, 2861, 3809, { Skill("Inferno"), Skill("Freezadiaran"), Skill("Blizzard"), Skill("Blightaon"), Skill("Blightaonia") }, true, 213) },
		{ 5, Enemy("Domain Keeper 2", 120, 3144, 4153, { Skill("Splashadiaran"), Skill("Tsunami"), Skill("Gustadiaran"), Skill("Hurricane"), Skill("Hexoania"), Skill("Healan") }, true, 225) },
		{ 9, Enemy("Domain Keeper 3", 130, 3327, 2537, { Skill("Zapadiaran"), Skill("Thunder Bolt"), Skill("Blightaonia"), Skill("Fist of Justice"), Skill("Decaying Chucks"), Skill("Healan") }, true, 253) },
		{ 14, Enemy("Domain Keeper 4", 140, 3896, 6467, { Skill("God's Power Punch"), Skill("Impulse Strike"), Skill("Flamadiaran"), Skill("Inferno"), Skill("Zapadiaran"), Skill("Gustadiaran") }, true, 268) },
		{ 15, Enemy("Macko", 150, 5000, 12336, { Skill("End of the World") }, true, 333) }
	};
}
void DungeonDomain::displayDungeon()
{
	system("CLS");
	cout << "\n   " << dye::black_on_white(" ") << dye::black_on_white(this->getDungeonName()) << dye::black_on_white(" ") << dye::black_on_white(this->getDungeonRoom()) << dye::black_on_white("F \n\n");
	for (int i = 0; i < 15; i++)
	{
		cout << "   ";
		for (int j = 0; j < 15; j++)
		{
			if (this->getDungeonMap()[(this->getDungeonRoom() - 1)][i][j] == 'S')
			{
				cout << dye::aqua("S") << " ";
			}
			else if (this->getDungeonMap()[(this->getDungeonRoom() - 1)][i][j] == 'X')
			{
				int INT_Random = (rand() % 12) + 1;
				if (INT_Random == 1)
				{
					cout << dye::black_on_red(" ");
				}
				else if (INT_Random == 2)
				{
					cout << dye::black_on_light_red(" ");
				}
				else if (INT_Random == 3)
				{
					cout << dye::black_on_blue(" ");
				}
				else if (INT_Random == 4)
				{
					cout << dye::black_on_light_blue(" ");
				}
				else if (INT_Random == 5)
				{
					cout << dye::black_on_light_yellow(" ");
				}
				else if (INT_Random == 6)
				{
					cout << dye::black_on_yellow(" ");
				}
				else if (INT_Random == 7)
				{
					cout << dye::black_on_purple(" ");
				}
				else if (INT_Random == 8)
				{
					cout << dye::black_on_light_purple(" ");
				}
				else if (INT_Random == 9)
				{
					cout << dye::black_on_white(" ");
				}
				else if (INT_Random == 10)
				{
					cout << dye::black_on_grey(" ");
				}
				else if (INT_Random == 11)
				{
					cout << dye::black_on_green(" ");
				}
				else if (INT_Random == 12)
				{
					cout << dye::black_on_light_green(" ");
				}
				if ((j + 1) == 15 && this->getDungeonMap()[(this->getDungeonRoom() - 1)][i][j] == 'X')
				{
					int INT_Random = (rand() % 12) + 1;
					if (INT_Random == 1)
					{
						cout << dye::black_on_red(" ");
					}
					else if (INT_Random == 2)
					{
						cout << dye::black_on_light_red(" ");
					}
					else if (INT_Random == 3)
					{
						cout << dye::black_on_blue(" ");
					}
					else if (INT_Random == 4)
					{
						cout << dye::black_on_light_blue(" ");
					}
					else if (INT_Random == 5)
					{
						cout << dye::black_on_light_yellow(" ");
					}
					else if (INT_Random == 6)
					{
						cout << dye::black_on_yellow(" ");
					}
					else if (INT_Random == 7)
					{
						cout << dye::black_on_purple(" ");
					}
					else if (INT_Random == 8)
					{
						cout << dye::black_on_light_purple(" ");
					}
					else if (INT_Random == 9)
					{
						cout << dye::black_on_white(" ");
					}
					else if (INT_Random == 10)
					{
						cout << dye::black_on_grey(" ");
					}
					else if (INT_Random == 11)
					{
						cout << dye::black_on_green(" ");
					}
					else if (INT_Random == 12)
					{
						cout << dye::black_on_light_green(" ");
					}
				}
				else if ((j + 1) < 15)
				{
					if (this->getDungeonMap()[(this->getDungeonRoom() - 1)][i][(j + 1)] == 'X')
					{
						int INT_Random = (rand() % 12) + 1;
						if (INT_Random == 1)
						{
							cout << dye::black_on_red(" ");
						}
						else if (INT_Random == 2)
						{
							cout << dye::black_on_light_red(" ");
						}
						else if (INT_Random == 3)
						{
							cout << dye::black_on_blue(" ");
						}
						else if (INT_Random == 4)
						{
							cout << dye::black_on_light_blue(" ");
						}
						else if (INT_Random == 5)
						{
							cout << dye::black_on_light_yellow(" ");
						}
						else if (INT_Random == 6)
						{
							cout << dye::black_on_yellow(" ");
						}
						else if (INT_Random == 7)
						{
							cout << dye::black_on_purple(" ");
						}
						else if (INT_Random == 8)
						{
							cout << dye::black_on_light_purple(" ");
						}
						else if (INT_Random == 9)
						{
							cout << dye::black_on_white(" ");
						}
						else if (INT_Random == 10)
						{
							cout << dye::black_on_grey(" ");
						}
						else if (INT_Random == 11)
						{
							cout << dye::black_on_green(" ");
						}
						else if (INT_Random == 12)
						{
							cout << dye::black_on_light_green(" ");
						}
					}
					else
					{
						cout << " ";
					}
				}
			}
			else if (this->getDungeonMap()[(this->getDungeonRoom() - 1)][i][j] == '!' || this->getDungeonMap()[(this->getDungeonRoom() - 1)][i][j] == '?')
			{
				cout << dye::red(this->getDungeonMap()[(this->getDungeonRoom() - 1)][i][j]) << " ";
			}
			else if (this->getDungeonMap()[(this->getDungeonRoom() - 1)][i][j] == '*')
			{
				cout << dye::yellow("*") << " ";
			}
			else
			{
				cout << this->getDungeonMap()[(this->getDungeonRoom() - 1)][i][j] << " ";
			}
			if (this->getDungeonMap()[(this->getDungeonRoom() - 1)][i][j] == '+')
			{
				this->setPosX(j);
				this->setPosY(i);
			}
			if (i == 1 && j == 14)
			{
				cout << "   " << dye::black_on_bright_white(" 1 ") << " Open Inventory";
			}
			if (i == 3 && j == 14)
			{
				cout << "   " << dye::black_on_bright_white(" 2 ") << " View Stats";
			}
			if (i == 5 && j == 14)
			{
				cout << "   " << dye::black_on_bright_white(" 3 ") << " Quick Travel";
			}
			if (i == 7 && j == 14)
			{
				cout << "   " << dye::black_on_bright_white(" 4 ") << " Save Game";
			}
			if (i == 9 && j == 14)
			{
				cout << "   " << dye::black_on_bright_white(" 5 ") << " Exit Game";
			}
		}
		cout << "\n";
	}
	cout << "\n\n\n";
}

Enemy DungeonDomain::newEnemy()
{
	if (this->getDungeonRoom() >= 1)
	{
		// Enemy level for this floor: 65-75		Lava Spirit: 65-71   Japanese Soldier: 70-75   Gold Entity VII: 70
		int INT_Enemy_Spawn_Chance = (rand() % 10) + 1;
		if (INT_Enemy_Spawn_Chance == 10)
		{
			return Enemy("Gold Entity VII", 70, 650, 0, { }, true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("Japanese Soldier", ((rand() % 6) + 70), 302, 189, { Skill("Splashadia"), Skill("Splashadiaran"), Skill("Gustadia"), Skill("Blightaon") }, false, 89);
		}
		else
		{
			return Enemy("Lava Spirit", ((rand() % 7) + 65), 264, 57, { Skill("Flamadia"), Skill("Flamadiaran"), Skill("Freezadia"), Skill("Frei"), Skill("Healan") }, false, 45);
		}
	}
}

Item* DungeonDomain::getItemFromChest()
{
	vector<Item*> VEC_Chest_Loot = { };
	// Default Loot for Dungeon 6
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new Item("Magma Rock", "Hot piece of magma rock", 1));

	// Additional Loot added per Room
	if (this->INT_Dungeon_Room >= 2)
	{
	}

	Item* ITEM_New_Item = VEC_Chest_Loot[rand() % (VEC_Chest_Loot.size())];
	return ITEM_New_Item;
}