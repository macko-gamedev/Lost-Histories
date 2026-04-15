#include "DungeonAtlantis.h"

// X = Wall, ! = Enemy, > = Next Room, <  = Last Room, + = Player

//DungeonAtlantis::DungeonAtlantis() { }

DungeonAtlantis::DungeonAtlantis()
{
	this->STR_Dungeon_Name = "Atlantis Ruins";
	this->INT_Dungeon_Room = 1;
	this->INT_Pos_X = 3;
	this->INT_Pos_Y = 7;
	this->VEC_Dungeon_Map =
	{
		{
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'O', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '>' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'O', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'O', 'O', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X', 'O' }
		},
		{
			{ 'O', 'O', 'X', 'O', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'X', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', '!', ' ', ' ', '*', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', 'X', 'O', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'X', 'X', ' ', ' ', 'X', 'O', 'O', 'O', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ '<', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '>' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'O', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', '?', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', '*', 'X', ' ', 'X', 'X' },
			{ 'O', 'O', 'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O' }
		},
		{
			{ 'X', 'X', 'X', 'O', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'O' },
			{ 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'O', 'O', 'X', ' ', ' ', 'X', 'O', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'O' },
			{ 'O', 'X', 'X', ' ', ' ', 'X', 'O', 'X', ' ', 'X', 'O', 'X', ' ', 'X', 'O' },
			{ 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X' },
			{ '<', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '>' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'O', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'O', 'O', ' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'O' },
			{ 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
		},
		{
			{ 'X', 'X', 'X', 'X', 'O', 'X', ' ', 'X', 'O', 'O', 'X', 'X', 'X', 'O', 'O' },
			{ 'O', ' ', ' ', 'X', ' ', 'X', 'X', 'X', ' ', ' ', 'X', ' ', 'X', 'X', 'O' },
			{ 'O', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'O' },
			{ 'O', 'O', 'X', ' ', 'X', ' ', ' ', 'X', 'X', 'X', ' ', 'X', ' ', ' ', 'O' },
			{ 'O', 'X', 'X', ' ', ' ', ' ', 'X', 'X', ' ', 'X', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', 'X', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'O' },
			{ '<', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '>', 'X', ' ', '*', 'O' },
			{ 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'O' },
			{ 'X', 'X', 'X', ' ', 'X', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', 'X', 'X', ' ', ' ', 'O' },
			{ 'X', ' ', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', '?', ' ', ' ', ' ', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'X', 'O' },
			{ 'X', 'X', 'X', 'O', 'O', 'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'O' }
		},
		{
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', ' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', 'X', 'X', ' ', 'X' },
			{ 'X', ' ', 'X', ' ', ' ', 'X', 'X', ' ', 'X', 'X', '?', 'X', ' ', ' ', 'X' },
			{ 'X', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', 'X', 'X' },
			{ 'X', ' ', 'X', 'O', '<', '+', ' ', '*', ' ', ' ', 'X', ' ', ' ', '|', '>' },
			{ 'X', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X' },
			{ 'X', ' ', 'X', ' ', ' ', 'X', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', 'X', ' ', '|', ' ', 'X' },
			{ 'X', ' ', 'X', 'X', 'X', 'X', 'X', '?', ' ', 'X', 'X', 'X', 'X', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' }
		},
		{
			{ 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'X', 'X', ' ', ' ', 'X', 'X', 'O', 'O', 'X', 'X', 'X' },
			{ 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', 'X', 'O', 'X', 'X', ' ', '>' },
			{ 'O', 'O', 'O', 'X', 'X', ' ', 'X', 'X', ' ', 'X', 'X', 'X', ' ', ' ', 'X' },
			{ 'O', 'O', 'O', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X' },
			{ 'O', 'O', 'X', 'X', ' ', 'X', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', 'O' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', 'O' },
			{ '<', '+', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X' },
			{ 'O', 'X', 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'O', 'O', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X' },
			{ 'O', 'O', 'O', 'O', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'X', 'X' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'X', 'X', 'O' }
		},
		{
			{ 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ '<', '+', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'O', 'O' },
			{ 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'O', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '?', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'O', 'O' },
			{ 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'O', 'O' },
			{ 'O', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'O', 'O' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O' }
		}
	};
	this->VEC_Explored_Rooms = { true, false, false, false, false, false, false };
	this->MAP_New_Room_Text =
	{
		{ 1, { "..." } },
		{ 2, { "...", "You feel a strong presence in this section", "The next area looks to be locked behind a door", "Perhaps try searching for the key", "Yourself > Theres more locked doors here too!? "} },
		{ 3, { "...", "Yourself > Compared to the last area, this place 'looks' more peaceful", "Yourself > Maybe without the monsters"} },
		{ 4, { "...", "You feel a strong presence in this section", "The next area looks to be locked behind a door", "Perhaps try searching for the key", "Yourself > Can I catch a break?" } },
		{ 5, { "...", "You feel two strong presences in this section", "The next area looks to be locked behind two doors", "Yourself > This is a joke", "Yourself > Sometimes I wished I never unfronze..." } },
		{ 6, { "...", "A tunnel leads downwards and splits off two ways with one exit", "Yourself > Is it even worth fighting anymore..." } },
		{ 7, { "...", "This seems to be the last room of the dungeon", "The room is full of soldiers and a formidable opponent", "Make sure you're ready for whats up ahead" } },
	};
}

void DungeonAtlantis::fillWithEnemies()
{
	// 15% chance for each tile to have an enemy
	for (int r = 0; r < 7; r++)
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

void DungeonAtlantis::fillWithChests()
{
	// 8% chance for each tile to have a chest
	for (int r = 0; r < 7; r++)
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (this->getDungeonMap()[r][i][j] == ' ')
				{
					int INT_Spawn_Chance = (rand() % 100) + 1;
					if (INT_Spawn_Chance > 92)
					{
						this->setPosition(r, i, j, '*');
					}
				}
			}
		}
	}
}

void DungeonAtlantis::elementSetter(Enemy& ENEMY_Enemy)
{
	// Normal Enemies
	if (ENEMY_Enemy.getName() == "Lab Fish")
	{
		ENEMY_Enemy.setElements({ {"Fire", "-"}, {"Water", "Rst"}, {"Ice", "-"}, {"Electric", "Rst"}, {"Wind", "-"}, {"Curse", "Rst"}, {"Bless", "Wk"} });
	}
	else if (ENEMY_Enemy.getName() == "Royal Guard")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Wk"}, {"Water", "Nul"}, {"Ice", "Rst"}, {"Electric", "Rst"}, {"Wind", "-"}, {"Curse", "Nul"}, {"Bless", "Wk"} });
	}
	else if (ENEMY_Enemy.getName() == "Armed Soldier")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Rst"}, {"Water", "Rst"}, {"Ice", "Wk"}, {"Electric", "Rst"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (ENEMY_Enemy.getName() == "Sharkman")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Wk"}, {"Water", "Nul"}, {"Ice", "Wk"}, {"Electric", "-"}, {"Wind", "Rst"}, {"Curse", "-"}, {"Bless", "Rst"} });
	}
	else if (ENEMY_Enemy.getName() == "Reanimated Entity")
	{
		ENEMY_Enemy.setElements({ {"Fire", "-"}, {"Water", "Nul"}, {"Ice", "Rst"}, {"Electric", "-"}, {"Wind", "Wk"}, {"Curse", "Rst"}, {"Bless", "-"} });
	}
	else if (ENEMY_Enemy.getName() == "British Soldier")
	{
		ENEMY_Enemy.setElements({ {"Fire", "-"}, {"Water", "Rst"}, {"Ice", "Wk"}, {"Electric", "Nul"}, {"Wind", "Nul"}, {"Curse", "Wk"}, {"Bless", "Nul"} });
	}
	// Rare Enemies
	else if (ENEMY_Enemy.getName() == "Gold Entity II")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Rst"}, {"Water", "Rst"}, {"Ice", "Rst"}, {"Electric", "Rst"}, {"Wind", "Rst"}, {"Curse", "Rst"}, {"Bless", "Rst"} });
	}
	else if (ENEMY_Enemy.getName() == "Gold Entity III")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Nul"}, {"Water", "-"}, {"Ice", "Nul"}, {"Electric", "-"}, {"Wind", "Nul"}, {"Curse", "-"}, {"Bless", "Nul"} });
	}
	// Mini Bosses
	else if (ENEMY_Enemy.getName() == "Reanimated Mermaid")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Nul"}, {"Water", "Nul"}, {"Ice", "Wk"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "Rst"}, {"Bless", "-"} });
	}
	else if (ENEMY_Enemy.getName() == "Reanimated Jellyfisherman")
	{
		ENEMY_Enemy.setElements({ {"Fire", "-"}, {"Water", "Nul"}, {"Ice", "-"}, {"Electric", "Nul"}, {"Wind", "-"}, {"Curse", "Rst"}, {"Bless", "Rst"} });
	}
	else if (ENEMY_Enemy.getName() == "Radioactive Atlantis Survivor")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Wk"}, {"Water", "Nul"}, {"Ice", "Wk"}, {"Electric", "Wk"}, {"Wind", "Rst"}, {"Curse", "Nul"}, {"Bless", "Nul"} });
	}
	else if (ENEMY_Enemy.getName() == "Radioactive Atlantis Guard")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Rst"}, {"Water", "Nul"}, {"Ice", "Wk"}, {"Electric", "-"}, {"Wind", "Rst"}, {"Curse", "Nul"}, {"Bless", "Nul"} });
	}
	// Dungeon Boss
	else if (ENEMY_Enemy.getName() == "Russian Sergeant")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Rst"}, {"Water", "-"}, {"Ice", "Rst"}, {"Electric", "Wk"}, {"Wind", "Rst"}, {"Curse", "Wk"}, {"Bless", "Wk"} });
	}
}

Enemy DungeonAtlantis::newEnemy()
{
	if (this->getDungeonRoom() == 1)
	{
		// Enemy level for this floor: 14-20		Patrol Soldier: 14-17   Lab Fish: 16-19   Gold Entity: 20
		int INT_Enemy_Spawn_Chance = (rand() % 10) + 1;
		if (INT_Enemy_Spawn_Chance == 10)
		{
			return Enemy("Gold Entity II", 20, 150, 0, { }, getItemFromLootTable("Gold Entity II"), true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("Lab Fish", ((rand() % 3) + 16), 125, 109, { Skill("Freezan"), Skill("Zapao"), Skill("Mezapao"), Skill("Hex") }, getItemFromLootTable("Lab Fish"), false, 33);
		}
		else
		{
			return Enemy("Patrol Soldier", ((rand() % 3) + 14), 146, 27, { Skill("Flamao"), Skill("Meflamao"), Skill("Gustan"), Skill("Blighta") }, getItemFromLootTable("Patrol Soldier"), false, 48);
		}
	}
	else if (this->getDungeonRoom() == 2)
	{
		// Enemy level for this floor: 17-23		Patrol Soldier: 17-20   Lab Fish: 18-22   Royal Guard: 20-23   Gold Entity: 20
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity II", 20, 150, 0, { }, getItemFromLootTable("Gold Entity II"), true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 14)
		{
			return Enemy("Royal Guard", ((rand() % 4) + 20), 173, 69, { Skill("Flamao"), Skill("Freezan"), Skill("Hex"), Skill("Blight") }, getItemFromLootTable("Royal Guard"), false, 67);
		}
		else if (INT_Enemy_Spawn_Chance > 6)
		{
			return Enemy("Lab Fish", ((rand() % 5) + 18), 125, 109, { Skill("Freezan"), Skill("Zapao"), Skill("Mezapao"), Skill("Hex") }, getItemFromLootTable("Lab Fish"), false, 33);
		}
		else
		{
			return Enemy("Patrol Soldier", ((rand() % 4) + 17), 146, 27, { Skill("Flamao"), Skill("Meflamao"), Skill("Gustan"), Skill("Blighta") }, getItemFromLootTable("Patrol Soldier"), false, 48);
		}
	}
	else if (this->getDungeonRoom() == 3)
	{
		// Enemy level for this floor: 21-26		Lab Fish: 21-25   Royal Guard: 22-26   Armed Soldier: 25-27   Gold Entity: 25
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity III", 25, 250, 0, { }, getItemFromLootTable("Gold Entity III"), true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 14)
		{
			return Enemy("Royal Guard", ((rand() % 5) + 22), 173, 69, { Skill("Flamao"), Skill("Freezan"), Skill("Hex"), Skill("Blight") }, getItemFromLootTable("Royal Guard"), false, 67);
		}
		else if (INT_Enemy_Spawn_Chance > 6)
		{
			return Enemy("Lab Fish", ((rand() % 5) + 21), 125, 109, { Skill("Freezan"), Skill("Zapao"), Skill("Mezapao"), Skill("Hex") }, getItemFromLootTable("Lab Fish"), false, 33);
		}
		else
		{
			return Enemy("Armed Soldier", ((rand() % 3) + 25), 219, 27, { Skill("Flamao"), Skill("Flamadia"), Skill("Zapao"), Skill("Gust"), Skill("Hex") }, getItemFromLootTable("Armed Soldier"), false, 73);
		}
	}
	else if (this->getDungeonRoom() == 4)
	{
		// Enemy level for this floor: 24-30		Royal Guard: 24-28   Armed Soldier: 27-30   Sharkman: 26-30   Gold Entity: 25
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity III", 25, 250, 0, { }, getItemFromLootTable("Gold Entity III"), true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 14)
		{
			return Enemy("Royal Guard", ((rand() % 5) + 24), 173, 69, { Skill("Flamao"), Skill("Freezan"), Skill("Hex"), Skill("Blight") }, getItemFromLootTable("Royal Guard"), false, 67);
		}
		else if (INT_Enemy_Spawn_Chance > 6)
		{
			return Enemy("Sharkman", ((rand() % 5) + 26), 192, 156, { Skill("Splashan"), Skill("Mesplashan"), Skill("Gustan"), Skill("Blighta") }, getItemFromLootTable("Sharkman"), false, 56);
		}
		else
		{
			return Enemy("Armed Soldier", ((rand() % 4) + 27), 219, 27, { Skill("Flamao"), Skill("Flamadia"), Skill("Zapao"), Skill("Gust"), Skill("Hex") }, getItemFromLootTable("Armed Soldier"), false, 73);
		}
	}
	else if (this->getDungeonRoom() == 5)
	{
		// Enemy level for this floor: 28-34		Armed Soldier: 28-33   Sharkman: 31-34   Reanimated Entity: 29-34   Gold Entity: 30
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity III", 30, 250, 0, { }, getItemFromLootTable("Gold Entity III"), true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 14)
		{
			return Enemy("Reanimated Entity", ((rand() % 6) + 29), ((rand() % 50) + 175), 100, { Skill("Flamao"), Skill("Splashan"), Skill("Freezan"), Skill("Zapao"), Skill("Gustan"), Skill("Hexo"), Skill("Blighta") }, getItemFromLootTable("Reanimated Entity"), false, 67);
		}
		else if (INT_Enemy_Spawn_Chance > 6)
		{
			return Enemy("Sharkman", ((rand() % 5) + 26), 192, 156, { Skill("Splashan"), Skill("Mesplashan"), Skill("Gustan"), Skill("Blighta") }, getItemFromLootTable("Sharkman"), false, 56);
		}
		else
		{
			return Enemy("Armed Soldier", ((rand() % 4) + 27), 219, 27, { Skill("Flamao"), Skill("Flamadia"), Skill("Zapao"), Skill("Gust"), Skill("Hex") }, getItemFromLootTable("Armed Soldier"), false, 73);
		}
	}
	else if (this->getDungeonRoom() == 6)
	{
		// Enemy level for this floor: 31-37		Sharkman: 33-37   Reanimated Entity: 31-37   British Soldier: 34-37   Gold Entity: 35
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity III", 35, 250, 0, { }, getItemFromLootTable("Gold Entity III"), true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 14)
		{
			return Enemy("Reanimated Entity", ((rand() % 8) + 31), ((rand() % 50) + 175), 100, { Skill("Flamao"), Skill("Splashan"), Skill("Freezan"), Skill("Zapao"), Skill("Gustan"), Skill("Hexo"), Skill("Blighta") }, getItemFromLootTable("Reanimated Entity"), false, 67);
		}
		else if (INT_Enemy_Spawn_Chance > 6)
		{
			return Enemy("Sharkman", ((rand() % 5) + 33), 192, 156, { Skill("Splashan"), Skill("Mesplashan"), Skill("Gustan"), Skill("Blighta") }, getItemFromLootTable("Sharkman"), false, 56);
		}
		else
		{
			return Enemy("British Soldier", ((rand() % 4) + 34), 241, 27, { Skill("Gustan"), Skill("Zapao"), Skill("Blighta"), Skill("Blightaon"), Skill("Heal") }, getItemFromLootTable("British Soldier"), false, 84);
		}
	}
	else if (this->getDungeonRoom() == 7)
	{
		// Enemy level for this floor: 36-40		British Soldier: 36-40   Gold Entity: 35
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 15)
		{
			return Enemy("Gold Entity III", 35, 250, 0, { }, getItemFromLootTable("Gold Entity III"), true, 10);
		}
		else
		{
			return Enemy("British Soldier", ((rand() % 5) + 36), 241, 27, { Skill("Gustan"), Skill("Zapao"), Skill("Blighta"), Skill("Blightaon"), Skill("Heal") }, getItemFromLootTable("British Soldier"), false, 84);
		}
	}
}

Item* DungeonAtlantis::getItemFromLootTable(string STR_Enemy_Name)
{
	vector<Item*> VEC_Enemy_Drops = { };
	if (STR_Enemy_Name == "Patrol Soldier")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Worn Field Kit", "Can still be used for emergencies", 2, "HP", 100));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 35));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Medkit", "For a quick patch up", 3, "HP", 200));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Holy Water", "Drinking this feels godly", 3, "STA", 80));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Gun Fragment", "A piece of fragment from a Soldiers gun", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Glock-17", "Perfect for quick execution", 3, 78));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Firecracker", "Who loves a little bit of Fire play", 4, Skill("Meflamao")));
	}
	else if (STR_Enemy_Name == "Lab Fish")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Seaweed", "Lonely strand of seaweed", 1));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Fish Tooth", "Caution, may be sharp", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Squid Head", "Squirts black genetically modified ink", 2, Skill("Mehex")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Holy Water", "Drinking this feels godly", 3, "STA", 80));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Jellyfish Tenticle", "Dead or Alive it still carries some current", 4, Skill("Zapadia")));;
	}
	else if (STR_Enemy_Name == "Royal Guard")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Seaweed", "Lonely strand of seaweed", 1));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Mermaid Tail", "Sadly from a dead mermaid corpse", 2));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Gold Coin", "Made of real gold!", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Holy Water", "Drinking this feels godly", 3, "STA", 80));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Old Pendant", "An old heart pendant emitting a healthy aura", 3, Skill("Heal")));
		/* 3 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Bottle o' Holy Water", "500ml of pure holy water!", 4, "STA", 150));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Royal Trident", "Trident yielded by the Old Royal Gaurds of Atlantis", 4, 103));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Dark Staff", "Some foul play is at work here...", 4, Skill("Mehexo")));
	}
	else if (STR_Enemy_Name == "Armed Soldier")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Worn Field Kit", "Can still be used for emergencies", 2, "HP", 100));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 35));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Gold Coin", "Made of real gold!", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Medkit", "For a quick patch up", 3, "HP", 200));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Holy Water", "Drinking this feels godly", 3, "STA", 80));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements", "Drugs used to increase users power", 3, "ATK", 2.5));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills", "Drugs used to increase users concentration", 3, "MAG", 2.5));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Radioactive Core", "May need a suit for this one!", 3, Skill("Frei")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Glock-17", "Perfect for quick execution", 3, (((rand() % 15) - 7) + 78)));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Waterproof Flamethrower", "How this combination works is beyond comprehension", 4, Skill("Flamadia")));
	}
	else if (STR_Enemy_Name == "Sharkman")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Shark Tooth", "Caution, may be sharp", 2));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Gold Coin", "Made of real gold!", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements", "Drugs used to increase users power", 3, "ATK", 2.5));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills", "Drugs used to increase users concentration", 3, "MAG", 2.5));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Water Blaster 9000", "Graded PSA 10, worth an absolute fortune!", 3, Skill("Splashan")));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Fire Hydrant", "Very powerful water beam!", 4, Skill("Splashadia")));
	}
	else if (STR_Enemy_Name == "Reanimated Entity")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Seaweed", "Lonely strand of seaweed", 1));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Mermaid Tail", "Sadly from a dead mermaid corpse", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Shark Tooth", "Caution, may be sharp", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Fish Tooth", "Caution, may be sharp", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Foreign Coin", "A coin which you don't recognise", 2));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Gold Coin", "Made of real gold!", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Gun Fragment", "A piece of fragment from a Soldiers gun", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Radioactive Core", "May need a suit for this one!", 3, Skill("Frei")));
		/* 2 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Radioactive Chunk", "A small intake of this could spell the end", 4, Skill("Freila")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Diamond", "A natural chunk of diamond from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Emerald", "A natural chunk of raw emerald from the earth", 5));
	}
	else if (STR_Enemy_Name == "British Soldier")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Foreign Coin", "A coin which you don't recognise", 2));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("£10 Coin", "Since when were £10 coins a thing?", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Medkit", "For a quick patch up", 3, "HP", 200));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements", "Drugs used to increase users power moderately", 3, "ATK", 2.5));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills", "Drugs used to increase users concentration moderately", 3, "MAG", 2.5));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Glock-17", "Perfect for quick execution", 3, (((rand() % 15) - 7) + 78)));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Breach Hammer", "Designed for house raids", 4, (((rand() % 19) - 9) + 139)));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Overpower Capsules", "Drugs used to increase users power and concentration moderately", 4, "ATK/MAG", 2.5));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements X", "Drugs used to increase users power significantly", 4, "ATK", 4));
		/* 4 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills X", "Drugs used to increase users concentration significantly", 4, "MAG", 4));
	}
	else if (STR_Enemy_Name == "Gold Entity II")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Box of Matches", "Withered box of Fire matches, can they still alight?", 2, Skill("Meflame")));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Water Balloon", "May annoy some people", 2, Skill("Mesplash")));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Ice Shard", "A sharp ended icicle which could shatter", 2, Skill("Mefreeze")));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Live Cables", "A bundle of small exposed cables", 2, Skill("Mezap")));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Goat Horn", "Remains of what looks like a goat, what is it even doing here?", 2, Skill("Megust")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Diamond", "A natural chunk of diamond from the earth", 5));
	}
	else if (STR_Enemy_Name == "Gold Entity III")
	{
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Portable Mini-Cannon", "Old cannons dated back to the 1800s", 3, Skill("Flamao")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Water Blaster 9000", "Graded PSA 10, worth an absolute fortune!", 3, Skill("Splashan")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Crystalised Flake", "A snowflake fully crystalised, emitting a frosty aura", 3, Skill("Freezan")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Electrical Wire", "Exposed electric wire that still packs some spark", 3, Skill("Zapao")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Cold Hairdryer", "Lethalised hairdryer from the 2040s, the air is even more colder.", 3, Skill("Gustan")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Radioactive Core", "May need a suit for this one!", 3, Skill("Frei")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Diamond", "A natural chunk of raw diamond from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Emerald", "A natural chunk of raw emerald from the earth", 5));
	}
	return VEC_Enemy_Drops[rand() % VEC_Enemy_Drops.size()];
}