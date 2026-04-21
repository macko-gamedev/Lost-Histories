#include "DungeonGlacier.h"

// X = Wall, ! = Enemy, > = Next Room, <  = Last Room, + = Player
 
//DungeonGlacier::DungeonGlacier() { }

DungeonGlacier::DungeonGlacier()
{
	this->STR_Dungeon_Name = "Glacier Wasteland";
	this->INT_Dungeon_Room = 1;
	this->INT_Pos_X = 3;
	this->INT_Pos_Y = 10;
	this->VEC_Dungeon_Map =
	{
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
			{ 'O', 'X', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X' }, // X P      X   X
			{ 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' }, // X            X
			{ 'O', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X' }, // XX    XXXX   X
			{ 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'X', 'X', ' ', ' ', 'X' }, //  XXXXXX  XX  X
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'X' }  //           XXXX
		},
		{
			{ 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O' }, // XXXX  XXXXX 
			{ 'O', '<', '+', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'O', 'O' }, // <  XXXX   XX
			{ 'O', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' }, // XX  X      XXX 
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', 'X' }, //  X     XX    X
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X' }, //  X      X    X
			{ 'O', 'O', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' }, //  XX        XXX
			{ 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'O', 'O' }, //   X       XX
			{ 'O', 'O', 'O', 'X', 'X', 'X', ' ', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'O' }, //   XXX XX   XX
			{ 'O', 'O', 'O', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X' }, //   XX   XXX  XX
			{ 'O', 'O', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X', 'O' }, //  XX     X  XX 
			{ 'O', 'O', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O' }, //  X  X      X   
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X', 'O' }, //  X      X  XX
			{ 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X' }, //  X   XX     XX
			{ 'O', 'O', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '>' }, //  XXX         >
			{ 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }  //    XXXXXXXXXXX
		},
		{                                                                                  
			{ 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, // XXXX  XXXXXXXX 
			{ 'O', 'X', '?', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X' }, // X? XXXX   X  X
			{ 'O', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', 'X', ' ', 'X', 'X' }, // XX  X   X X XX 
			{ 'O', 'O', 'X', ' ', ' ', 'X', ' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'O' }, //  X  X XXX X X 
			{ 'O', 'O', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'O' }, //  X  X   X   X 
			{ 'O', 'O', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'O' }, //  XX   XXXXX X 
			{ 'O', 'O', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X', 'O' }, //  XXXX     X X
			{ 'O', 'O', 'X', ' ', 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X' }, //  X XX XXXXX XX
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', '|', '>' }, //  X        X |>
			{ 'O', 'O', 'X', ' ', 'X', ' ', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', 'X' }, //  X X XX X XXXX
			{ 'O', 'O', 'X', ' ', 'X', ' ', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', 'O' }, //  X X XX X X X  
			{ 'O', 'O', 'X', ' ', 'X', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', 'X', 'O' }, //  X X    X X X
			{ 'O', 'O', 'X', 'X', 'X', ' ', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', 'X' }, //  XXX XX X X XX
			{ 'O', 'O', '<', '+', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X' }, //  <      X    X
			{ 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }  //  XXXXXXXXXXXXX
		},
		{                                                                                  // --------------
			{ 'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' }, //     XXXXXX 
			{ 'X', 'X', 'X', ' ', 'X', 'X', 'O', 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'O' }, //    XX    XX
			{ 'X', 'S', '!', ' ', ' ', 'X', 'O', 'X', 'X', ' ', ' ', 'X', 'X', 'O', 'O' }, //   XX  XX  XX  
			{ 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'O' }, //  XX   XX   XX
			{ 'O', 'O', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' }, // XX          XX
			{ 'O', 'O', 'O', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X' }, // X            X
			{ 'O', 'O', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', '>' }, // X  XX    XX  >
			{ 'O', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' }, // X            X
			{ 'O', '<', '+', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X' }, // <+   XXXX    X 
			{ 'O', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X' }, // X            X
			{ 'O', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'O' }, // X   XXXXXX   X
			{ 'O', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'O' }, // XX          XX
			{ 'O', 'O', 'X', 'X', ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'O' }, //  XX   XX   XX 
			{ 'O', 'O', 'O', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'O', 'O' }, //   XXX    XXX
			{ 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'O' }  //     XXXXXX
		},
		{                                                                                  // --------------
			{ 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O' }, //   XXXXXXXXXXX 
			{ 'O', 'O', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' }, //  XX         XX
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' }, //  X           X
			{ 'O', 'O', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X' }, //  XXX X   X XXX
			{ 'O', 'O', 'O', 'O', 'X', ' ', 'X', '?', ' ', ' ', 'X', ' ', 'X', 'O', 'O' }, //    X X ? X X
			{ 'O', 'X', 'X', 'X', 'X', '!', 'X', 'X', 'X', 'X', 'X', '!', 'X', 'X', 'X' }, // XXXX!XXXXX!XXX
			{ 'O', '<', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '>' }, // <           |>
			{ 'O', 'X', 'X', 'X', 'X', '!', 'X', ' ', ' ', ' ', 'X', '!', 'X', 'X', 'X' }, // XXXX!X   X!XXX
			{ 'O', 'O', 'O', 'O', 'X', ' ', 'X', ' ', ' ', ' ', 'X', ' ', 'X', 'O', 'O' }, //    X X   X X
			{ 'O', 'O', 'O', 'X', 'X', ' ', 'X', 'X', ' ', 'X', 'X', ' ', 'X', 'X', 'O' }, //   XX XX XX XX
			{ 'O', 'O', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X' }, //  XX   XXX   XX
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', 'X' }, //  X     X     X
			{ 'O', 'O', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X' }, //  XX   XXX   XX
			{ 'O', 'O', 'O', 'X', 'X', '*', 'X', 'X', 'O', 'X', 'X', '*', 'X', 'X', 'O' }, //   XX*XX XX*XX
			{ 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'X', 'X', 'X', 'O', 'O' }  //    XXX   XXX
		},
		{
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' }, //
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' }, //
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' }, //
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' }, //
			{ 'O', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O' }, //
			{ 'O', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'O', 'O', 'O' }, //
			{ 'O', '<', '+', ' ', ' ', '!', ' ', ' ', '!', ' ', ' ', 'X', 'O', 'O', 'O' }, // <    !  !  ! ?
			{ 'O', 'X', 'X', ' ', ' ', 'X', ' ', 'X', 'X', ' ', ' ', 'X', 'X', 'O', 'O' }, //
			{ 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'O' }, //
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'X' }, //
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X', ' ', ' ', '?', 'O' }, //
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X', ' ', 'X', 'X' }, //
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'O' }, //
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' }, //
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' }
		}
	};
	this->VEC_Explored_Rooms = { true, false, false, false, false, false };
	this->MAP_New_Room_Text =
	{
		{ 1, { "..." } },
		{ 2, { "...", "You feel a sharp chill down your spine", "Maybe you should take extra care whilst exploring", "[You can press SPACE and type /help for a list of commands!]"}},
		{ 3, { "...", "You feel a strong presence in this section", "The next area looks to be locked behind a door", "Perhaps try searching for the key" } },
		{ 4, { "...", "An overwhelming panic is starting to set in", "Yourself > What is this place!?" } },
		{ 5, { "...", "You feel a strong presence in this section", "The next area looks to be locked behind a door", "Perhaps try searching for the key", "Yourself > Another locked door?", "Yourself > The last strong 'thing' was hard enough..."} },
		{ 6, { "...", "The land is void of enemies but two guards and a formidable opponent", "Make sure you're ready for whats up ahead" } }
	};
}

void DungeonGlacier::fillWithEnemies()
{
	// 15% chance for each tile to have an enemy
	for (int r = 0; r < 5; r++)
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (this->getDungeonMap()[r][i][j] == ' ')
				{
					int INT_Spawn_Chance = (rand() % 100) + 1;
					if (INT_Spawn_Chance > 84)
					{
						this->setPosition(r, i, j, '!');
					}
				}
			}
		}
	}
}

void DungeonGlacier::fillWithChests()
{
	// 5% chance for each tile to have a chest
	for (int r = 0; r < 6; r++)
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (this->getDungeonMap()[r][i][j] == ' ')
				{
					int INT_Spawn_Chance = (rand() % 100) + 1;
					if (INT_Spawn_Chance > 94)
					{
						this->setPosition(r, i, j, '*');
					}
				}
			}
		}
	}
}

void DungeonGlacier::elementSetter(Enemy& ENEMY_Enemy)
{
	// Normal Enemies
	if (ENEMY_Enemy.getName() == "Ice Monster")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Wk"}, {"Water", "-"}, {"Ice", "Rst"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (ENEMY_Enemy.getName() == "Ice Fiend")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Rst"}, {"Water", "-"}, {"Ice", "Rst"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (ENEMY_Enemy.getName() == "Bergmite")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Wk"}, {"Water", "-"}, {"Ice", "-"}, {"Electric", "-"}, {"Wind", "Rst"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (ENEMY_Enemy.getName() == "Wasteland Spirit")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Wk"}, {"Water", "Wk"}, {"Ice", "Rst"}, {"Electric", "Rst"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "Wk"} });
	}
	else if (ENEMY_Enemy.getName() == "Patrol Soldier")
	{
		ENEMY_Enemy.setElements({ {"Fire", "-"}, {"Water", "-"}, {"Ice", "Rst"}, {"Electric", "Wk"}, {"Wind", "Rst"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	// Mini Bosses
	else if (ENEMY_Enemy.getName() == "Snow Golem")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Wk"}, {"Water", "-"}, {"Ice", "Nul"}, {"Electric", "-"}, {"Wind", "Rst"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (ENEMY_Enemy.getName() == "Duty Soldier")
	{
		ENEMY_Enemy.setElements({ {"Fire", "-"}, {"Water", "-"}, {"Ice", "Rst"}, {"Electric", "Wk"}, {"Wind", "Rst"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	// Rare Enemies
	else if (ENEMY_Enemy.getName() == "Gold Entity I")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Wk"}, {"Water", "Wk"}, {"Ice", "Wk"}, {"Electric", "Wk"}, {"Wind", "Wk"}, {"Curse", "Wk"}, {"Bless", "Wk"} });
	}
	// Dungeon Boss
	else if (ENEMY_Enemy.getName() == "Russian Sergeant")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Rst"}, {"Water", "-"}, {"Ice", "Rst"}, {"Electric", "Wk"}, {"Wind", "Rst"}, {"Curse", "Wk"}, {"Bless", "Wk"} });
	}
}

Enemy DungeonGlacier::newEnemy()
{
	if (this->getDungeonRoom() == 1)
	{
		// Enemy level for this floor: 1-3		Ice Monster: 1-3
		return Enemy("Ice Monster", ((rand() % 3) + 1), 30, 24, { Skill("Freeze") }, getItemFromLootTable("Ice Monster"), false, 14);
	}
	else if (this->getDungeonRoom() == 2)
	{
		// Enemy Level for this floor: 2-5		Ice Monster: 2-5
		return Enemy("Ice Monster", ((rand() % 4) + 2), 30, 24, { Skill("Freeze") }, getItemFromLootTable("Ice Monster"), false, 14);
	}
	else if (this->getDungeonRoom() == 3)
	{
		// Enemy Level for this floor: 3-7		Ice Monster: 3-6	Ice Fiend: 4-7
		if (((rand() % 5) + 1) > 3)
		{
			return Enemy("Ice Fiend", ((rand() % 4) + 4), 45, 18, { Skill("Freeze"), Skill("Freezan") }, getItemFromLootTable("Ice Fiend"), false, 21);
		}
		else
		{
			return Enemy("Ice Monster", ((rand() % 4) + 3), 30, 24, { Skill("Freeze") }, getItemFromLootTable("Ice Monster"), false, 14);
		}
	}
	else if (this->getDungeonRoom() == 4)
	{
		// Enemy Level for this floor: 4-9		Ice Monster: 4-8	Ice Fiend: 5-8	 Bergmite: 5-9   Gold Entity I: 5
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity I", 5, 200, 0, { }, getItemFromLootTable("Gold Entity I"), true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 11)
		{
			return Enemy("Bergmite", ((rand() % 5) + 5), 62, 27, { Skill("Freezan"), Skill("Gust") }, getItemFromLootTable("Bergmite"), false, 26);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("Ice Fiend", ((rand() % 4) + 5), 45, 18, { Skill("Freeze"), Skill("Freezan") }, getItemFromLootTable("Ice Fiend"), false, 21);
		}
		else
		{
			return Enemy("Ice Monster", ((rand() % 5) + 4), 30, 24, { Skill("Freeze") }, getItemFromLootTable("Ice Monster"), false, 14);
		}
	}
	else if (this->getDungeonRoom() == 5)
	{
		// Enemy Level for this floor: 8-15		Ice Monster: 8-12	Ice Fiend: 9-13	 Bergmite: 10-15   Wasteland Spirit: 12-15
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 17)
		{
			return Enemy("Wasteland Spirit", ((rand() % 4) + 12), 79, 41, { Skill("Flame"), Skill("Freeze"), Skill("Zap"), Skill("Gust") }, getItemFromLootTable("Wasteland Spirit"), false, 34);
		}
		if (INT_Enemy_Spawn_Chance > 11)
		{
			return Enemy("Bergmite", ((rand() % 6) + 10), 62, 27, { Skill("Freezan"), Skill("Gust") }, getItemFromLootTable("Bergmite"), false, 26);
		}
		else if (INT_Enemy_Spawn_Chance > 6)
		{
			return Enemy("Ice Fiend", ((rand() % 5) + 9), 45, 18, { Skill("Freeze"), Skill("Freezan") }, getItemFromLootTable("Ice Fiend"), false, 21);
		}
		else
		{
			return Enemy("Ice Monster", ((rand() % 5) + 8), 30, 24, { Skill("Freeze") }, getItemFromLootTable("Ice Monster"), false, 14);
		}
	}

	else if (this->getDungeonRoom() == 6)
	{
		// Enemy Level for this floor: 15		Patrol Soldier: 15
		return Enemy("Patrol Soldier", 15, 146, 27, { Skill("Flamao"), Skill("Meflamao"), Skill("Gustan"), Skill("Blighta") }, new Item("Gun Fragment", "A piece of fragment from a Soldiers gun", 3), true, 48);
	}
}

Item* DungeonGlacier::getItemFromLootTable(string STR_Enemy_Name)
{
	vector<Item*> VEC_Enemy_Drops = { };
	if (STR_Enemy_Name == "Ice Monster")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Ice Core", "A strange looking block of Ice", 1, Skill("Freeze")));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 40));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Sharp Icicle", "Caution, fragile!", 1, (((rand() % 7) - 3) + 13), true));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2));
	}
	else if (STR_Enemy_Name == "Ice Fiend")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 40));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Sharp Icicle", "Caution, fragile!", 1, (((rand() % 7) - 3) + 13), true));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Ice Shard", "A sharp ended icicle which could shatter", 2, Skill("Mefreeze")));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 35));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Crystalised Flake", "A snowflake fully crystalised, emitting a frosty aura", 3, Skill("Freezan")));
	}
	else if (STR_Enemy_Name == "Bergmite")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Dented Airhorn", "Old, red-ended airhorn which somehow still works", 1, Skill("Gust")));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 40));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Energy Pills", "Unopened tub of energy pills", 1, "STA", 15));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Worn Field Kit", "Can still be used for emergencies", 2, "HP", 100));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 35));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Cold Hairdryer", "Lethalised hairdryer from the 2040s, the air is even more colder.", 3, Skill("Gustan")));
	}
	else if (STR_Enemy_Name == "Wasteland Spirit")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Shattered Molotov", "Ash remains inside the bottle", 1, Skill("Flame")));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 40));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Energy Pills", "Unopened tub of energy pills", 1, "STA", 15));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Worn Field Kit", "Can still be used for emergencies", 2, "HP", 100));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 35));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Power Cord", "Unfrozen exposed power cable. Wonder if it still sparks?", 3, Skill("Zapao")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Medkit", "For a quick patch up", 3, "HP", 200));
	}
	else if (STR_Enemy_Name == "Gold Entity I")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Shattered Molotov", "Ash remains inside the bottle", 1, Skill("Flame")));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Bubble Blower", "POP!", 1, Skill("Splash")));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Ice Core", "A strange looking block of Ice", 1, Skill("Freeze")));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Live Wire", "Still sparking at the tip", 1, Skill("Zap")));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Dented Airhorn", "Old, red-ended airhorn which somehow still works", 1, Skill("Gust")));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new Item("Chipped Diamond", "Exposed diamond which appears chipped and frozen over, might still carry some value", 4));
	}
	return VEC_Enemy_Drops[rand() % VEC_Enemy_Drops.size()];
}

Item* DungeonGlacier::getItemFromChest()
{
	vector<Item*> VEC_Chest_Loot = { };
	// Default Loot for Dungeon 1
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1));
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new Item("Ripped Shoes", "A pair of ripped shoes", 1));
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new ItemSkill("Old Cross", "An old church cross emitting a blessing aura", 1, Skill("Blight")));
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new ItemSkill("Shattered Molotov", "Ash remains inside the bottle", 1, Skill("Flame")));
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 40));
	for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new Item("Foreign Coin", "A coin which you don't recognise", 2));
	for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new ItemMelee("Nail Board", "Plank of frozen wood with a nail pointing out the end", 2, (((rand() % 7) - 3) + 21), true));
	for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new ItemSkill("Box of Matches", "Withered box of fire matches, can they still alight?", 2, Skill("Meflame")));
	for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemMelee("Ice-Axe", "Battleaxe frozen to time", 3, (((rand() % 11) - 5) + 36), true));

	// Additional Loot added per Room
	if (this->INT_Dungeon_Room >= 2)
	{
		for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 35));
	}
	if (this->INT_Dungeon_Room >= 3)
	{
		for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemMelee("Ice Crossbow", "Icified crossbow which fires icicles", 3, (((rand() % 13) - 6) + 46), true));
	}
	if (this->INT_Dungeon_Room >= 4)
	{
		for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new ItemSkill("Goat Horn", "Remains of what looks like a goat, what is it even doing here?", 2, Skill("Megust")));
		for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Worn Field Kit", "Can still be used for emergencies", 2, "HP", 100));
		for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new ItemMelee("Wingman", "Familiar looking revolver, it seems damaged but could still work", 4, (((rand() % 15) - 7) + 67), true));
	}
	if (this->INT_Dungeon_Room >= 5)
	{
		for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemSkill("Electrical Wire", "Exposed electric wire that still packs some spark", 3, Skill("Zapao")));
		for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemSkill("Old Pendant", "An old heart pendant emitting a healthy aura", 3, Skill("Heal")));
		for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new Item("Chipped Diamond", "Exposed diamond which appears chipped and frozen over, might still carry some value", 4));
	}
	Item* ITEM_New_Item = VEC_Chest_Loot[rand() % (VEC_Chest_Loot.size())];
	return ITEM_New_Item;
}