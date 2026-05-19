#include "DungeonSpecial.h"

// X = Wall, ! = Enemy, > = Next Room, <  = Last Room, + = Player

DungeonSpecial::DungeonSpecial()
{
	this->STR_Dungeon_Name = "Special Passage";
	this->INT_Dungeon_Room = 1;
	this->INT_Pos_X = 3;
	this->INT_Pos_Y = 7;
	this->VEC_Dungeon_Map =
	{
		{
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'X', ' ', 'X', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O' },
			{ 'O', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'O' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '>', 'X' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'O', 'O', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'O' },
			{ 'O', 'X', ' ', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'X', ' ', 'X', 'O' },
			{ 'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'O', 'O' },
		},
		{
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'X', ' ', 'X', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O' },
			{ 'O', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'O' },
			{ 'X', '<', '+', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', '|', '>', 'X' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', ' ', '?', 'X', ' ', ' ', ' ', 'X', 'X', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'O', 'O', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'O' },
			{ 'O', 'X', ' ', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'X', ' ', 'X', 'O' },
			{ 'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'O', 'O' },
		},
		{
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'X', ' ', 'X', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O' },
			{ 'O', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'O' },
			{ 'X', '<', '+', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', '|', '>', 'X' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', ' ', '?', 'X', ' ', ' ', ' ', 'X', 'X', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'O', 'O', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'O' },
			{ 'O', 'X', ' ', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'X', ' ', 'X', 'O' },
			{ 'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'O', 'O' },
		},
		{
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'X', ' ', 'X', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O' },
			{ 'O', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'O' },
			{ 'X', '<', '+', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', '|', '>', 'X' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', ' ', '?', 'X', ' ', ' ', ' ', 'X', 'X', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'O', 'O', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'O' },
			{ 'O', 'X', ' ', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'X', ' ', 'X', 'O' },
			{ 'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'O', 'O' },
		},
		{
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'X', ' ', 'X', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O' },
			{ 'O', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'O' },
			{ 'X', '<', '+', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', '|', '>', 'X' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', ' ', '?', 'X', ' ', ' ', ' ', 'X', 'X', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'O', 'O', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'O' },
			{ 'O', 'X', ' ', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'X', ' ', 'X', 'O' },
			{ 'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'O', 'O' },
		},
		{
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'X', ' ', 'X', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O' },
			{ 'O', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'O' },
			{ 'X', '<', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'O', 'O', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'X', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'O' },
			{ 'O', 'X', ' ', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'X', ' ', '?', 'X' },
			{ 'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'O' },
		},
	};

	this->VEC_Explored_Rooms = { true, true, true, true, true, true };
	this->MAP_New_Room_Text =
	{
		{ 1, { "..." } },
		{ 2, { "..." } },
		{ 3, { "..." } },
		{ 4, { "..." } },
		{ 5, { "..." } },
		{ 6, { "..." } }
	};
}

Enemy DungeonSpecial::newEnemy()
{
	if (this->getDungeonRoom() == 1)
	{
		// Enemy level for this floor: 85-92		Ice Monster: 85-89   Ice Fiend: 87-90   Bergmite: 89-91   Wasteland Spirit: 90-92   Gold Entity VIII: 90
		int INT_Enemy_Spawn_Chance = (rand() % 5) + 1;
		if (INT_Enemy_Spawn_Chance == 1)
		{
			return Enemy("Wasteland Spirit", ((rand() % 3) + 90), 79, 41, { Skill("Flamadia"), Skill("Freezadia"), Skill("Zapadia"), Skill("Gustan") },  false, 34);
		}
		else if (INT_Enemy_Spawn_Chance == 2)
		{
			return Enemy("Bergmite", ((rand() % 3) + 89), 62, 27, { Skill("Eye of the 'Berg"), Skill("Gustan") },  false, 26);
		}
		else if (INT_Enemy_Spawn_Chance == 3)
		{
			return Enemy("Ice Fiend", ((rand() % 4) + 87), 45, 18, { Skill("Freezadia"), Skill("Eye of the 'Berg") },  false, 21);
		}
		else if (INT_Enemy_Spawn_Chance == 4)
		{
			return Enemy("Ice Monster", ((rand() % 5) + 85), 30, 24, { Skill("Freezadia") },  false, 14);
		}
		else if (INT_Enemy_Spawn_Chance == 5)
		{
			return Enemy("Gold Entity VIII", 90, 700, 0, { Skill("Freila") },  true, 10);
		}
	}
	else if (this->getDungeonRoom() == 2)
	{
		// Enemy level for this floor: 88-95		Lab Fish: 88-92   Royal Guard: 89-92   Sharkman: 91-94   Reanimated Entity: 93-95   Gold Entity VIII: 90
		int INT_Enemy_Spawn_Chance = (rand() % 5) + 1;
		if (INT_Enemy_Spawn_Chance == 1)
		{
			return Enemy("Reanimated Entity", ((rand() % 3) + 93), ((rand() % 50) + 175), 100, { Skill("Eye of the Sun"), Skill("Eye of the Ocean"), Skill("Eye of the 'Berg"), Skill("Eye of the Spark"), Skill("Eye of the Storm"), Skill("Hexaon"), Skill("Blightaon") },  false, 67);
		}
		else if (INT_Enemy_Spawn_Chance == 2)
		{
			return Enemy("Sharkman", ((rand() % 4) + 91), 192, 156, { Skill("Splashan"), Skill("Eye of the Ocean"), Skill("Eye of the Storm"), Skill("Blightaon") },  false, 56);
		}
		else if (INT_Enemy_Spawn_Chance == 3)
		{
			return Enemy("Royal Guard", ((rand() % 4) + 89), 173, 69, { Skill("Eye of the Sun"), Skill("Eye of the 'Berg"), Skill("Hexaon"), Skill("Blightaon") },  false, 67);
		}
		else if (INT_Enemy_Spawn_Chance == 4)
		{
			return Enemy("Lab Fish", ((rand() % 5) + 88), 125, 109, { Skill("Eye of the 'Berg"), Skill("Eye of the Spark"), Skill("Zapadia"), Skill("Hexaon") },  false, 33);
		}
		else if (INT_Enemy_Spawn_Chance == 5)
		{
			return Enemy("Gold Entity VIII", 90, 700, 0, { Skill("Freila") }, true, 10);
		}
	}
	else if (this->getDungeonRoom() == 3)
	{
		// Enemy level for this floor: 91-97		Unknown Creature: 91-94   Nuclear Spirit: 93-96   Corrupt Researcher: 95-97   Gold Entity IX: 95
		int INT_Enemy_Spawn_Chance = (rand() % 4) + 1;
		if (INT_Enemy_Spawn_Chance == 1)
		{
			return Enemy("Corrupt Researcher", ((rand() % 3) + 95), 257, 189, { Skill("Eye of the Sun"), Skill("Flamadia"), Skill("Blightaon"), Skill("Hexaon"), Skill("Healadia") },  false, 24);
		}
		else if (INT_Enemy_Spawn_Chance == 2)
		{
			return Enemy("Nuclear Spirit", ((rand() % 4) + 93), 231, 189, { Skill("Eye of the Sun"), Skill("Freiladia"), Skill("Freila") },  false, 24);
		}
		else if (INT_Enemy_Spawn_Chance == 3)
		{
			return Enemy("Unknown Creature", ((rand() % 4) + 91), 277, 57, { Skill("Eye of the 'Berg"), Skill("Eye of the Storm"), Skill("Blighta"), Skill("Blightaon"), Skill("Hexaon") },  false, 35);
		}
		else if (INT_Enemy_Spawn_Chance == 4)
		{
			return Enemy("Gold Entity IX", 95, 750, 0, { Skill("Freiladia"), Skill("Healan") },  true, 10);
		}
	}
	else if (this->getDungeonRoom() == 4)
	{
		// Enemy level for this floor: 94-99		Lava Spirit: 94-96   Lava Spirit: 96-98   Master's Servant: 97-99   Gold Entity IX: 95
		int INT_Enemy_Spawn_Chance = (rand() % 4) + 1;
		if (INT_Enemy_Spawn_Chance == 1)
		{
			return Enemy("Master's Servant", ((rand() % 3) + 97), 316, 163, { Skill("Zapadia"), Skill("Eye of the Spark"), Skill("Gustadia"), Skill("Eye of the Storm"), Skill("Hexaon"), Skill("Mehexaon"), Skill("Healadia") },  false, 109);
		}
		else if (INT_Enemy_Spawn_Chance == 2)
		{
			return Enemy("Fire Prowler", ((rand() % 3) + 96), 287, 92, { Skill("Flamadia"), Skill("Meflamadia"), Skill("Eye of the Sun"), Skill("Eye of the Spark") },  false, 57);
		}
		else if (INT_Enemy_Spawn_Chance == 3)
		{
			return Enemy("Lava Spirit", ((rand() % 3) + 94), 264, 57, { Skill("Flamadia"), Skill("Eye of the Sun"), Skill("Eye of the 'Berg"), Skill("Freiladia"), Skill("Healadia") },  false, 45);
		}
		else if (INT_Enemy_Spawn_Chance == 4)
		{
			return Enemy("Gold Entity IX", 95, 750, 0, { Skill("Freiladia"), Skill("Healan") },  true, 10);
		}
	}
	else if (this->getDungeonRoom() == 5)
	{
		// Enemy level for this floor: 96-99		British Soldier: 96-99   German Soldier: 96-99   American Soldier: 96-99   French Soldier: 96-99   Japanese Soldier: 96-99   Gold Entity X: 99
		int INT_Enemy_Spawn_Chance = (rand() % 6) + 1;
		if (INT_Enemy_Spawn_Chance == 1)
		{
			return Enemy("Japanese Soldier", ((rand() % 4) + 96), 302, 189, { Skill("Splashadia"), Skill("Eye of the Ocean"), Skill("Eye of the Storm"), Skill("Blightaon") },  false, 89);
		}
		else if (INT_Enemy_Spawn_Chance == 2)
		{
			return Enemy("American Soldier", ((rand() % 4) + 96), 269, 83, { Skill("Eye of the Spark"), Skill("Hexo"), Skill("Hexaon"), Skill("Blighta"), Skill("Blightaon") },  false, 106);
		}
		else if (INT_Enemy_Spawn_Chance == 3)
		{
			return Enemy("German Soldier", ((rand() % 4) + 96), 282, 57, { Skill("Eye of the Sun"), Skill("Eye of the Spark"), Skill("Zapadia"), Skill("Eye of the Storm"), Skill("Gustadia") },  false, 95);
		}
		else if (INT_Enemy_Spawn_Chance == 4)
		{
			return Enemy("French Soldier", ((rand() % 4) + 96), 278, 68, { Skill("Eye of the Ocean"), Skill("Eye of the 'Berg"), Skill("Freezadia"), Skill("Eye of the Storm"), Skill("Gustadia") },  false, 101);
		}
		else if (INT_Enemy_Spawn_Chance == 5)
		{
			return Enemy("British Soldier", ((rand() % 4) + 96), 241, 27, { Skill("Eye of the Storm"), Skill("Eye of the Spark"), Skill("Blighta"), Skill("Blightaon"), Skill("Healan") },  false, 84);
		}
		else if (INT_Enemy_Spawn_Chance == 6)
		{
			return Enemy("Gold Entity X", 99, 800, 0, { Skill("End of the World"), Skill("Healadia") },  true, 10);
		}
	}
}

Item* DungeonSpecial::getItemFromChest()
{
	vector<Item*> VEC_Chest_Loot = { };
	// Default Loot for Dungeon Special
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new Item("Rainbow Crystal", "A sparkling rainbow crystal from the special realm!", 5));

	// Additional Loot added per Room
	if (this->INT_Dungeon_Room >= 2)
	{
	}

	Item* ITEM_New_Item = VEC_Chest_Loot[rand() % (VEC_Chest_Loot.size())];
	return ITEM_New_Item;
}