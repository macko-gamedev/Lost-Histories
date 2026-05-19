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

Enemy DungeonFacility::newEnemy()
{
	if (this->getDungeonRoom() == 1)
	{
		// Enemy level for this floor: 38-44		Unknown Creature: 38-41   Nuclear Spirit: 40-44   Gold Entity IV: 40
		int INT_Enemy_Spawn_Chance = (rand() % 10) + 1;
		if (INT_Enemy_Spawn_Chance == 10)
		{
			return Enemy("Gold Entity IV", 40, 350, 0, { }, true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("Nuclear Spirit", ((rand() % 5) + 40), 231, 189, { Skill("Meflamao"), Skill("Frei"), Skill("Freila") }, false, 24);
		}
		else
		{
			return Enemy("Unknown Creature", ((rand() % 4) + 38), 277, 57, { Skill("Freezadia"), Skill("Gustan"), Skill("Blighta"), Skill("Blightaon"), Skill("Hexaon") }, false, 35);
		}
	}
	else if (this->getDungeonRoom() == 2)
	{
		// Enemy level for this floor: 42-49		Unknown Creature: 42-45   Nuclear Spirit: 44-48   Corrupt Researcher: 46-49   Gold Entity IV: 45
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity IV", 45, 350, 0, { }, true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 11)
		{
			return Enemy("Corrupt Researcher", ((rand() % 4) + 46), 257, 189, { Skill("Flamao"), Skill("Flamadia"), Skill("Blighta"), Skill("Blightaon"), Skill("Healan") }, false, 24);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("Nuclear Spirit", ((rand() % 5) + 44), 231, 189, { Skill("Meflamao"), Skill("Frei"), Skill("Freila") }, false, 24);
		}
		else
		{
			return Enemy("Unknown Creature", ((rand() % 4) + 42), 277, 57, { Skill("Freezadia"), Skill("Gustan"), Skill("Blighta"), Skill("Blightaon"), Skill("Hexaon") }, false, 35);
		}
	}
	else if (this->getDungeonRoom() == 3)
	{
		// Enemy level for this floor: 45-55		Nuclear Spirit: 45-50   Corrupt Researcher: 48-53   German Soldier: 51-55   Gold Entity V: 50
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity V", 50, 400, 0, { }, true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 11)
		{
			return Enemy("Corrupt Researcher", ((rand() % 6) + 48), 257, 189, { Skill("Flamao"), Skill("Flamadia"), Skill("Blighta"), Skill("Blightaon"), Skill("Healan") }, false, 24);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("Nuclear Spirit", ((rand() % 6) + 45), 231, 189, { Skill("Meflamao"), Skill("Frei"), Skill("Freila") }, false, 24);
		}
		else
		{
			return Enemy("German Soldier", ((rand() % 5) + 51), 282, 57, { Skill("Flamadia"), Skill("Zapao"), Skill("Zapadia"), Skill("Gustan"), Skill("Gustadia") }, false, 95);
		}
	}
	else if (this->getDungeonRoom() == 4)
	{
		// Enemy level for this floor: 49-59		Corrupt Researcher: 49-54   German Soldier: 55-59   French Soldier: 55-59   Gold Entity V: 50
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity V", 50, 400, 0, { }, true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 11)
		{
			return Enemy("Corrupt Researcher", ((rand() % 6) + 49), 257, 189, { Skill("Flamao"), Skill("Flamadia"), Skill("Blighta"), Skill("Blightaon"), Skill("Healan") }, false, 24);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("French Soldier", ((rand() % 5) + 55), 278, 68, { Skill("Splashadia"), Skill("Freezan"), Skill("Freezadia"), Skill("Gustan"), Skill("Gustadia") }, false, 101);
		}
		else
		{
			return Enemy("German Soldier", ((rand() % 5) + 55), 282, 57, { Skill("Flamadia"), Skill("Zapao"), Skill("Zapadia"), Skill("Gustan"), Skill("Gustadia") }, false, 95);
		}
	}
	else if (this->getDungeonRoom() == 5)
	{
		// Enemy level for this floor: 57-67		German Soldier: 57-62   French Soldier: 59-64   American Soldier: 61-67   Gold Entity VI: 60
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity VI", 60, 500, 0, { }, true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 12)
		{
			return Enemy("American Soldier", ((rand() % 7) + 61), 269, 83, { Skill("Zapadia"), Skill("Hexo"), Skill("Hexaon"), Skill("Blighta"), Skill("Blightaon") }, false, 106);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("French Soldier", ((rand() % 6) + 59), 278, 68, { Skill("Splashadia"), Skill("Freezan"), Skill("Freezadia"), Skill("Gustan"), Skill("Gustadia") }, false, 101);
		}
		else
		{
			return Enemy("German Soldier", ((rand() % 6) + 57), 282, 57, { Skill("Flamadia"), Skill("Zapao"), Skill("Zapadia"), Skill("Gustan"), Skill("Gustadia") }, false, 95);
		}
	}
	else if (this->getDungeonRoom() == 6)
	{
		// Enemy level for this floor: 60-69		German Soldier: 60-64   French Soldier: 62-67   American Soldier: 64-69   Gold Entity VI: 65
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity VI", 65, 500, 0, { }, true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 12)
		{
			return Enemy("American Soldier", ((rand() % 6) + 64), 269, 83, { Skill("Zapadia"), Skill("Hexo"), Skill("Hexaon"), Skill("Blighta"), Skill("Blightaon") }, false, 106);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("French Soldier", ((rand() % 6) + 62), 278, 68, { Skill("Splashadia"), Skill("Freezan"), Skill("Freezadia"), Skill("Gustan"), Skill("Gustadia") }, false, 101);
		}
		else
		{
			return Enemy("German Soldier", ((rand() % 5) + 60), 282, 57, { Skill("Flamadia"), Skill("Zapao"), Skill("Zapadia"), Skill("Gustan"), Skill("Gustadia") }, false, 95);
		}
	}
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