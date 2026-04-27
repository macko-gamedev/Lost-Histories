#include "DungeonFacility.h"

// X = Wall, ! = Enemy, > = Next Room, <  = Last Room, + = Player

DungeonFacility::DungeonFacility()
{
	this->STR_Dungeon_Name = "Facility";
	this->INT_Dungeon_Room = 1;
	this->INT_Pos_X = 3;
	this->INT_Pos_Y = 7;
	this->VEC_Dungeon_Map =
	{
		{
			{ 'O', 'X', 'O', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'O', 'X', 'X', 'X', 'X' },
			{ 'O', 'X', ' ', ' ', 'X', 'O', 'O', 'O', 'X', ' ', ' ', 'X', ' ', ' ', 'X' },
			{ 'O', 'X', ' ', ' ', 'X', 'X', 'X', 'O', 'X', ' ', ' ', 'X', ' ', 'X', 'X' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'O' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X' },
			{ 'O', ' ', ' ', '+', ' ', ' ', 'X', 'O', 'O', 'O', 'O', 'X', ' ', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', '>' },
			{ 'O', 'X', 'X', 'X', ' ', ' ', 'X', 'O', 'O', 'X', ' ', ' ', 'X', 'X', 'X' },
			{ 'O', 'O', 'O', 'X', ' ', ' ', 'X', 'O', 'O', 'X', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'O', 'O', 'X', 'O', 'O', 'X', 'O', 'O', 'X', 'O', 'O', 'X', 'O', 'O' }
		},
		{
			{ 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'O', 'O', 'X', 'O' },
			{ 'O', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'O' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O' },
			{ 'O', 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'O', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'O', 'X', ' ', ' ', ' ', '>' },
			{ 'O', 'X', ' ', ' ', 'X', '*', 'X', ' ', 'X', 'O', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'O' },
			{ '<', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O' },
			{ 'O', 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O' },
			{ 'O', 'X', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' }
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', ' ', ' ', 'X', 'X' },
			{ 'O', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X' },
			{ 'O', 'X', ' ', ' ', 'X', ' ', 'X', 'X', 'X', 'X', 'X', ' ', ' ', '|', '>' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ '<', '+', ' ', ' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', ' ', ' ', 'X', 'O' },
			{ 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'X', ' ', ' ', 'X', '?', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'O' },
			{ 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', 'X' },
			{ 'O', 'X', ' ', ' ', 'X', 'O', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', ' ', 'X', 'X', ' ', 'X', 'X', 'X' },
			{ '<', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O' },
			{ 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'O', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'O', 'X', ' ', ' ', ' ', '>' },
			{ 'O', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'O', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', 'X', ' ', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'O' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O' }
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', ' ', '*', '*', '*', 'X', '*', '*', '*', ' ', 'X', ' ', ' ', ' ', 'X' },
			{ 'X', ' ', '*', '*', '*', 'X', '*', '*', '*', ' ', 'X', ' ', ' ', ' ', 'X' },
			{ 'X', ' ', '*', '*', '*', 'X', '*', '*', '*', ' ', 'X', ' ', ' ', ' ', 'X' },
			{ 'X', ' ', '*', '*', '*', 'X', '*', '*', '*', ' ', 'X', ' ', 'X', 'X', 'X' },
			{ 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X', ' ', ' ', 'X', 'O' },
			{ 'X', ' ', '|', ' ', 'X', 'O', 'X', ' ', '|', ' ', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', ' ', ' ', '>' },
			{ 'X', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ '<', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O' },
			{ 'X', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'O' },
			{ 'O', 'O', 'X', ' ', 'X', 'O', 'X', ' ', 'X', 'X', 'O', 'O', 'O', 'X', 'O' },
			{ 'O', 'O', 'X', '?', 'X', 'O', 'X', ' ', '?', 'X', 'O', 'O', 'O', 'X', 'O' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'X', 'O' }
		},
		{
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'X', '?', ' ', ' ', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'X', 'X', 'X', ' ', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'X', ' ', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ '<', '+', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '?', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' }
		}
	};

	this->VEC_Explored_Rooms = { true, false, false, false, false, false };
	this->MAP_New_Room_Text =
	{
		{ 1, { "..." } },
		{ 2, { "...", "Each corner you turn is a new hallway", "This place is like a maze", "Yourself > Does this place even have an ending?"} },
		{ 3, { "...", "You feel a strong presence in this section", "The next area looks to be locked behind a door", "Perhaps try searching for the key" , "Yourself > Here we go again..." } },
		{ 4, { "...", "You feel like your reaching the end", "Maybe you'll reach your destination soon...", "Yourself > Am I going crazy who is that?" , "Yourself > This place is making me crazy", "Your Mysterious Machine Part is glowing", "Yourself > Maybe I am nearly at the end", "Yourself > I need to refreeze the planet", "Yourself > Then what do I do?", "Yourself > I'm not sure..." } },
		{ 5, { "...", "You feel two strong presences in this section", "However, the next area looks to be unlocked already", "Yourself > What are they even here for then?" } },
		{ 6, { "...", "This is the final room", "The last entity roaming this place is beyond a locked door", "This will be the hardest battle you've fought yet", "Make sure you are fully prepared for what's ahead", "You can travel to previous locations to make sure you have found everything you are looking for [SPACE + travel]", "Yourself > *gulp*" } },
	};
}

void DungeonFacility::fillWithEnemies()
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

void DungeonFacility::fillWithChests()
{
	// 8% chance for each tile to have a chest
	for (int r = 0; r < 6; r++)
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

void DungeonFacility::elementSetter(Enemy& ENEMY_Enemy)
{
	// Normal Enemies
	if (ENEMY_Enemy.getName() == "Unknown Creature")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Wk"}, {"Water", "Wk"}, {"Ice", "Nul"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "Rst"}, {"Bless", "Rst"} });
	}
	else if (ENEMY_Enemy.getName() == "Nuclear Spirit")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Abs"}, {"Water", "Wk"}, {"Ice", "Rst"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "Nul"}, {"Bless", "-"} });
	}
	else if (ENEMY_Enemy.getName() == "Corrupt Researcher")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Abs"}, {"Water", "-"}, {"Ice", "-"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "Wk"}, {"Bless", "Abs"} });
	}
	else if (ENEMY_Enemy.getName() == "German Soldier")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Rst"}, {"Water", "Wk"}, {"Ice", "Wk"}, {"Electric", "Rpl"}, {"Wind", "Rst"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (ENEMY_Enemy.getName() == "French Soldier")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Wk"}, {"Water", "Rst"}, {"Ice", "Rst"}, {"Electric", "Wk"}, {"Wind", "Rpl"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (ENEMY_Enemy.getName() == "American Soldier")
	{
		ENEMY_Enemy.setElements({ {"Fire", "-"}, {"Water", "-"}, {"Ice", "Abs"}, {"Electric", "Nul"}, {"Wind", "Wk"}, {"Curse", "Rst"}, {"Bless", "Rst"} });
	}
	// Rare Enemies
	else if (ENEMY_Enemy.getName() == "Gold Entity IV")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Nul"}, {"Water", "Nul"}, {"Ice", "Nul"}, {"Electric", "Nul"}, {"Wind", "Nul"}, {"Curse", "Nul"}, {"Bless", "Nul"} });
	}
	else if (ENEMY_Enemy.getName() == "Gold Entity V")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Rpl"}, {"Water", "Rpl"}, {"Ice", "Rpl"}, {"Electric", "Rpl"}, {"Wind", "Rpl"}, {"Curse", "Rpl"}, {"Bless", "Rpl"} });
	}
	else if (ENEMY_Enemy.getName() == "Gold Entity VI")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Wk"}, {"Water", "Wk"}, {"Ice", "Wk"}, {"Electric", "Wk"}, {"Wind", "Wk"}, {"Curse", "Wk"}, {"Bless", "Wk"} });
	}
	// Mini Bosses 
	else if (ENEMY_Enemy.getName() == "Mutated Lab Researcher")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Abs"}, {"Water", "Wk"}, {"Ice", "-"}, {"Electric", "Wk"}, {"Wind", "Nul"}, {"Curse", "Abs"}, {"Bless", "Wk"} });
	}
	else if (ENEMY_Enemy.getName() == "Mutated Security Sector 4B")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Wk"}, {"Water", "Rst"}, {"Ice", "-"}, {"Electric", "Rpl"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "Rpl"} });
	}
	else if (ENEMY_Enemy.getName() == "Mutated Security Sector 16A")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Rst"}, {"Water", "Wk"}, {"Ice", "-"}, {"Electric", "-"}, {"Wind", "Rpl"}, {"Curse", "Rpl"}, {"Bless", "-"} });
	}
	else if (ENEMY_Enemy.getName() == "Mutated Security Sector 46D")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Nul"}, {"Water", "-"}, {"Ice", "Rst"}, {"Electric", "Wk"}, {"Wind", "Rst"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	// Main Boss
	else if (ENEMY_Enemy.getName() == "Master of the Facility")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Abs"}, {"Water", "Abs"}, {"Ice", "Wk"}, {"Electric", "Wk"}, {"Wind", "Nul"}, {"Curse", "Rpl"}, {"Bless", "Rpl"} });
	}
}

Enemy DungeonFacility::newEnemy()
{
	if (this->getDungeonRoom() == 1)
	{
		// Enemy level for this floor: 38-44		Unknown Creature: 38-41   Nuclear Spirit: 40-44   Gold Entity IV: 40
		int INT_Enemy_Spawn_Chance = (rand() % 10) + 1;
		if (INT_Enemy_Spawn_Chance == 10)
		{
			return Enemy("Gold Entity IV", 40, 350, 0, { }, getItemFromLootTable("Gold Entity IV"), true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("Nuclear Spirit", ((rand() % 5) + 40), 231, 189, { Skill("Meflamao"), Skill("Frei"), Skill("Freila") }, getItemFromLootTable("Nuclear Spirit"), false, 24);
		}
		else
		{
			return Enemy("Unknown Creature", ((rand() % 4) + 38), 277, 57, { Skill("Freezadia"), Skill("Gustan"), Skill("Blighta"), Skill("Blightaon"), Skill("Hexaon") }, getItemFromLootTable("Unknown Creature"), false, 35);
		}
	}
	else if (this->getDungeonRoom() == 2)
	{
		// Enemy level for this floor: 42-49		Unknown Creature: 42-45   Nuclear Spirit: 44-48   Corrupt Researcher: 46-49   Gold Entity IV: 45
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity IV", 45, 350, 0, { }, getItemFromLootTable("Gold Entity IV"), true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 11)
		{
			return Enemy("Corrupt Researcher", ((rand() % 4) + 46), 257, 189, { Skill("Flamao"), Skill("Flamadia"), Skill("Blighta"), Skill("Blightaon"), Skill("Healan") }, getItemFromLootTable("Corrupt Researcher"), false, 24);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("Nuclear Spirit", ((rand() % 5) + 44), 231, 189, { Skill("Meflamao"), Skill("Frei"), Skill("Freila") }, getItemFromLootTable("Nuclear Spirit"), false, 24);
		}
		else
		{
			return Enemy("Unknown Creature", ((rand() % 4) + 42), 277, 57, { Skill("Freezadia"), Skill("Gustan"), Skill("Blighta"), Skill("Blightaon"), Skill("Hexaon") }, getItemFromLootTable("Unknown Creature"), false, 35);
		}
	}
	else if (this->getDungeonRoom() == 3)
	{
		// Enemy level for this floor: 45-55		Nuclear Spirit: 45-50   Corrupt Researcher: 48-53   German Soldier: 51-55   Gold Entity V: 50
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity V", 50, 400, 0, { }, getItemFromLootTable("Gold Entity V"), true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 11)
		{
			return Enemy("Corrupt Researcher", ((rand() % 6) + 48), 257, 189, { Skill("Flamao"), Skill("Flamadia"), Skill("Blighta"), Skill("Blightaon"), Skill("Healan") }, getItemFromLootTable("Corrupt Researcher"), false, 24);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("Nuclear Spirit", ((rand() % 6) + 45), 231, 189, { Skill("Meflamao"), Skill("Frei"), Skill("Freila") }, getItemFromLootTable("Nuclear Spirit"), false, 24);
		}
		else
		{
			return Enemy("German Soldier", ((rand() % 5) + 51), 282, 57, { Skill("Flamadia"), Skill("Zapao"), Skill("Zapadia"), Skill("Gustan"), Skill("Gustadia") }, getItemFromLootTable("German Soldier"), false, 95);
		}
	}
	else if (this->getDungeonRoom() == 4)
	{
		// Enemy level for this floor: 49-59		Corrupt Researcher: 49-54   German Soldier: 55-59   French Soldier: 55-59   Gold Entity V: 50
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity V", 50, 400, 0, { }, getItemFromLootTable("Gold Entity V"), true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 11)
		{
			return Enemy("Corrupt Researcher", ((rand() % 6) + 49), 257, 189, { Skill("Flamao"), Skill("Flamadia"), Skill("Blighta"), Skill("Blightaon"), Skill("Healan") }, getItemFromLootTable("Corrupt Researcher"), false, 24);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("French Soldier", ((rand() % 5) + 55), 278, 68, { Skill("Splashadia"), Skill("Freezan"), Skill("Freezadia"), Skill("Gustan"), Skill("Gustadia") }, getItemFromLootTable("French Soldier"), false, 101);
		}
		else
		{
			return Enemy("German Soldier", ((rand() % 5) + 55), 282, 57, { Skill("Flamadia"), Skill("Zapao"), Skill("Zapadia"), Skill("Gustan"), Skill("Gustadia") }, getItemFromLootTable("German Soldier"), false, 95);
		}
	}
	else if (this->getDungeonRoom() == 5)
	{
		// Enemy level for this floor: 57-67		German Soldier: 57-62   French Soldier: 59-64   American Soldier: 61-67   Gold Entity VI: 60
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity VI", 60, 500, 0, { }, getItemFromLootTable("Gold Entity VI"), true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 12)
		{
			return Enemy("American Soldier", ((rand() % 7) + 61), 269, 83, { Skill("Zapadia"), Skill("Hexo"), Skill("Hexaon"), Skill("Blighta"), Skill("Blightaon") }, getItemFromLootTable("American Soldier"), false, 106);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("French Soldier", ((rand() % 6) + 59), 278, 68, { Skill("Splashadia"), Skill("Freezan"), Skill("Freezadia"), Skill("Gustan"), Skill("Gustadia") }, getItemFromLootTable("French Soldier"), false, 101);
		}
		else
		{
			return Enemy("German Soldier", ((rand() % 6) + 57), 282, 57, { Skill("Flamadia"), Skill("Zapao"), Skill("Zapadia"), Skill("Gustan"), Skill("Gustadia") }, getItemFromLootTable("German Soldier"), false, 95);
		}
	}
}

Item* DungeonFacility::getItemFromLootTable(string STR_Enemy_Name)
{
	vector<Item*> VEC_Enemy_Drops = { };
	if (STR_Enemy_Name == "Unknown Creature")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Test Tube", "Empty glass test tube for lab purposes", 1));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Cracked Syringe", "Used for injections", 1));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Glass Shard", "Prone to shattering immediately", 2, (((rand() % 13) - 6) + 73), true));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Chemical Pipette", "Used for transferring liquids", 3));
	}
	else if (STR_Enemy_Name == "Nuclear Spirit")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Test Tube", "Empty glass test tube for lab purposes", 1));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Chemical Pipette", "Used for transferring liquids", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Radioactive Core", "May need a suit for this one!", 3, Skill("Frei")));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Radioactive Chunk", "A small intake of this could spell the end", 4, Skill("Freila")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Reactor Heart", "Those who are in it's presence are said to die within minutes", 5, Skill("Freiladia")));
	}
	else if (STR_Enemy_Name == "Corrupt Researcher")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Test Tube", "Empty glass test tube for lab purposes", 1));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Cracked Syringe", "Used for injections", 1));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Glass Shard", "Prone to shattering immediately", 2, (((rand() % 13) - 6) + 73), true));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Chemical Pipette", "Used for transferring liquids", 3));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Potion of Instant Health", "Red liquid fills the blocky bottle", 4, "HP", 350));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Potion of Mutated Souls", "Screaming can be heard inside the bottle", 4, "STA", 150));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Acid Injected Sword", "One slice is enough to poison the heart", 4, (((rand() % 19) - 9) + 165), true));
	}
	else if (STR_Enemy_Name == "German Soldier")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Foreign Coin", "A coin which you don't recognise", 2));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("10 Euro Coin", "Since when were ten euro coins a thing?", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Medkit", "For a quick patch up", 3, "HP", 200));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements", "Drugs used to increase users power moderately", 3, "ATK", 2.5));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills", "Drugs used to increase users concentration moderately", 3, "MAG", 2.5));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemMelee("AK-47", "Brr brr brrrrrrrrr!", 3, (((rand() % 21) - 10) + 120), true));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Breach Hammer", "Designed for house raids", 4, (((rand() % 19) - 9) + 139), true));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Overpower Capsules", "Drugs used to increase users power and concentration moderately", 4, "ATK/MAG", 2.5));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements X", "Drugs used to increase users power significantly", 4, "ATK", 4));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills X", "Drugs used to increase users concentration significantly", 4, "MAG", 4));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Frosted Railgun", "Has incredible piercing capabilities", 5, Skill("Mefreezadia")));
	}
	else if (STR_Enemy_Name == "French Soldier")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Foreign Coin", "A coin which you don't recognise", 2));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("10 Euro Coin", "Since when were ten euro coins a thing?", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemMelee("AK-47", "Brr brr brrrrrrrrr!", 3, (((rand() % 21) - 10) + 120), true));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Breach Hammer", "Designed for house raids", 4, (((rand() % 19) - 9) + 139), true));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Overpower Capsules", "Drugs used to increase users power and concentration moderately", 4, "ATK/MAG", 2.5));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements X", "Drugs used to increase users power significantly", 4, "ATK", 4));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills X", "Drugs used to increase users concentration significantly", 4, "MAG", 4));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemMelee("M6 Gerand", "One bullet is all it takes to end a life", 5, (((rand() % 29) - 14) + 194), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Explosive TNT", "Set it off to set enemies ablaze!", 5, Skill("Meflamadia")));
	}
	else if (STR_Enemy_Name == "American Soldier")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Foreign Coin", "A coin which you don't recognise", 2));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("10 Dollar Coin", "Since when were ten dollar coins a thing?", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemMelee("AK-47", "Brr brr brrrrrrrrr!", 3, (((rand() % 21) - 10) + 120), true));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Overpower Capsules", "Drugs used to increase users power and concentration moderately", 4, "ATK/MAG", 2.5));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements X", "Drugs used to increase users power significantly", 4, "ATK", 4));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills X", "Drugs used to increase users concentration significantly", 4, "MAG", 4));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemMelee("M6 Gerand", "One bullet is all it takes to end a life", 5, (((rand() % 29) - 14) + 194), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Kraber 50-Caliber", "This could be used in a FaZe montages, if... they're still a thing...", 5, ((rand() % 21) + 210), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("F5 Twister in a Barrel", "Wreck havoc!!!", 5, Skill("Eye of the Storm")));
	}
	else if (STR_Enemy_Name == "Gold Entity IV")
	{
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Waterproof Flamethrower", "How this combination works is beyond comprehension", 4, Skill("Flamadia")));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Fire Hydrant", "Very powerful water beam!", 4, Skill("Splashadia")));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Bag of Powdered Snow", "The coldness even hurts just grabbing it out of the bag", 4, Skill("Freezadia")));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Jellyfish Tenticle", "Dead or Alive it still carries some current", 4, Skill("Zapadia")));;
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Suction Device", "No one stands a chance once hit with the extreme wind force", 4, Skill("Gustadia")));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Radioactive Chunk", "A small intake of this could spell the end", 4, Skill("Freila")));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Acid Injected Sword", "One slice is enough to poison the heart", 4, (((rand() % 19) - 9) + 165), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Diamond", "A natural chunk of raw diamond from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Emerald", "A natural chunk of raw emerald from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Ruby", "A natural chunk of raw ruby from the earth", 5));
	}
	else if (STR_Enemy_Name == "Gold Entity V")
	{
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Orb of Dark Matter", "A mysterious black orb emitting an overwhelming curseful aura", 4, Skill("Hexaon")));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Book of God - 2049 Edition", "A book dedicated to god, created and published in 2049, emits an overwhelming blessful aura", 4, Skill("Blightaon")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Explosive TNT", "Set it off to set enemies ablaze!", 5, Skill("Meflamadia")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("World's Biggest Hose", "Says it in the name, does this facility really make these?", 5, Skill("Mesplashadia")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Frosted Railgun", "Has incredible piercing capabilities", 5, Skill("Mefreezadia")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Broken Powerline", "A segment from a powerline, still charged", 5, Skill("Mezapadia")));;
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Portable Black Hole", "'Sending out my singularity!'", 5, Skill("Megustadia")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Reactor Heart", "Those who are in it's presence are said to die within minutes", 5, Skill("Freiladia")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Prototype Heat Rod", "Flame spouted rod, can burn through anything!", 5, (((rand() % 25) - 12) + 214), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Diamond", "A natural chunk of raw diamond from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Emerald", "A natural chunk of raw emerald from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Ruby", "A natural chunk of raw ruby from the earth", 5));
	}
	else if (STR_Enemy_Name == "Gold Entity VI")
	{
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Fitzroy Motherload", "'Motherlode's droppin'. Hold onto ya hats'", 5, Skill("Eye of the Sun")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Paquette Pylon", "'Fuses set and capacitors charged'", 5, Skill("Eye of the Spark")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("F5 Twister in a Barrel", "Wreck havoc!!!", 5, Skill("Eye of the Storm")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Red Button", "A scratched engraving reads 'KJU'", 5, Skill("End of the World")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Prototype Heat Rod", "Flame spouted rod, can burn through anything!", 5, (((rand() % 25) - 12) + 214), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Diamond", "A natural chunk of raw diamond from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Emerald", "A natural chunk of raw emerald from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Ruby", "A natural chunk of raw ruby from the earth", 5));
	}
	return VEC_Enemy_Drops[rand() % VEC_Enemy_Drops.size()];
}

Item* DungeonFacility::getItemFromChest()
{
	vector<Item*> VEC_Chest_Loot = { };
	// Default Loot for Dungeon 3
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new Item("Test Tube", "Empty glass test tube for lab purposes", 1));
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new Item("Cracked Syringe", "Used for injections", 1));
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new ItemMelee("Screwdriver", "Can be used lethally", 1, (((rand() % 9) - 4) + 39), true));
	for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new Item("Foreign Coin", "A coin which you don't recognise", 2));
	for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new Item("Jar of Substance", "Weird purple goo in a jar", 2));
	for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new ItemMelee("Glass Shard", "Prone to shattering immediately", 2, (((rand() % 13) - 6) + 73), true));
	for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemSkill("Holy Cross", "A crucifix emitting a blessful aura", 3, Skill("Blighta")));
	for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Power Supplements X", "Drugs used to increase users power significantly", 4, "ATK", 4));
	for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Concentration Pills X", "Drugs used to increase users concentration significantly", 4, "MAG", 4));
	for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Potion of Instant Health", "Red liquid fills the blocky bottle", 4, "HP", 350));
	for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Potion of Mutated Souls", "Screaming can be heard inside the bottle", 4, "STA", 150));
	for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new ItemSkill("Bag of Powdered Snow", "The coldness even hurts just grabbing it out of the bag", 4, Skill("Freezadia")));
	for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new ItemSkill("Orb of Dark Matter", "A mysterious black orb emitting an overwhelming curseful aura", 4, Skill("Hexaon")));

	// Additional Loot added per Room
	if (this->INT_Dungeon_Room >= 2)
	{
		for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemMelee("Mega Bunsen Burner", "Bigger than usual, could be weaponised", 3, (((rand() % 11) - 5) + 108), true));
		for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new ItemSkill("Book of God - 2049 Edition", "A book dedicated to god, created and published in 2049, emits an overwhelming blessful aura", 4, Skill("Blightaon")));
		for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Enhancement Flask", "A shiny purple tint covers the flask, drinking this makes you feel more alive", 5, "STA", 999));
	}
	if (this->INT_Dungeon_Room >= 3)
	{
		for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Emergency Defibrillator", "Last chance of survival, only use when absolutely necessary", 5, "HP", 999));
		for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemSkill("Enchanted Pendant", "An enchanted heart pendant emitting an overwhelming healthy aura", 5, Skill("Healadia")));
	}
	if (this->INT_Dungeon_Room >= 4)
	{
		for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new Item("Chemical Pipette", "Used for transferring liquids", 3));
		for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemSkill("Paquette Pylon", "'Fuses set and capacitors charged'", 5, Skill("Eye of the Spark")));
		for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Power Supplements 50mg", "Drugs used to increase users power massively", 5, "ATK", 7));
		for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Concentration Pills 50mg", "Drugs used to increase users concentration massively", 5, "MAG", 7));
	}
	if (this->INT_Dungeon_Room >= 5)
	{
		for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new ItemSkill("Suction Device", "No one stands a chance once hit with the extreme wind force", 4, Skill("Gustadia")));
		for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemSkill("Reactor Heart", "Those who are in it's presence are said to die within minutes", 5, Skill("Freiladia")));
		for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemSkill("Fitzroy Motherload", "'Motherlode's droppin'. Hold onto ya hats'", 5, Skill("Eye of the Sun")));
	}

	Item* ITEM_New_Item = VEC_Chest_Loot[rand() % (VEC_Chest_Loot.size())];
	return ITEM_New_Item;
}