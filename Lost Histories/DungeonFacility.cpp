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
	};

	this->VEC_Explored_Rooms = { true, false, false };
	this->MAP_New_Room_Text =
	{
		{ 1, { "..." } },
		{ 2, { "...", "Each corner you turn is a new hallway", "This place is like a maze", "Yourself > Does this place even have an ending?"} },
		{ 3, { "...", "You feel a strong presence in this section", "The next area looks to be locked behind a door", "Perhaps try searching for the key" , "Yourself > Here we go again..." } },
	};
}

void DungeonFacility::fillWithEnemies()
{
	// 15% chance for each tile to have an enemy
	for (int r = 0; r < 3; r++)
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
	for (int r = 0; r < 3; r++)
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
		ENEMY_Enemy.setElements({ {"Fire", "Rst"}, {"Water", "Wk"}, {"Ice", "Rst"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "Nul"}, {"Bless", "-"} });
	}
	else if (ENEMY_Enemy.getName() == "Corrupt Researcher")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Nul"}, {"Water", "-"}, {"Ice", "-"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "Wk"}, {"Bless", "Nul"} });
	}
	else if (ENEMY_Enemy.getName() == "German Soldier")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Rst"}, {"Water", "Wk"}, {"Ice", "Wk"}, {"Electric", "Rst"}, {"Wind", "Rst"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	// Rare Enemies
	else if (ENEMY_Enemy.getName() == "Gold Entity IV")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Nul"}, {"Water", "Nul"}, {"Ice", "Nul"}, {"Electric", "Nul"}, {"Wind", "Nul"}, {"Curse", "Nul"}, {"Bless", "Nul"} });
	}
	else if (ENEMY_Enemy.getName() == "Gold Entity V")
	{
		ENEMY_Enemy.setElements({ {"Fire", "-"}, {"Water", "-"}, {"Ice", "-"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "Nul"}, {"Bless", "Nul"} });
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
		// Enemy level for this floor: 45-55		Nuclear Spirit: 45-50   Corrupt Researcher: 48-53   Germain Soldier: 51-55   Gold Entity V: 50
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
}

Item* DungeonFacility::getItemFromLootTable(string STR_Enemy_Name)
{
	vector<Item*> VEC_Enemy_Drops = { };
	if (STR_Enemy_Name == "Unknown Creature")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Test Tube", "Empty glass test tube for lab purposes", 1));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Cracked Syringe", "Used for injections", 1));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Glass Shard", "Prone to shattering immediately", 2, (((rand() % 13) - 6) + 73), true));
	}
	else if (STR_Enemy_Name == "Nuclear Spirit")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Test Tube", "Empty glass test tube for lab purposes", 1));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Radioactive Core", "May need a suit for this one!", 3, Skill("Frei")));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Radioactive Chunk", "A small intake of this could spell the end", 4, Skill("Freila")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Reactor Heart", "Those who are in it's presence are said to die within minutes", 5, Skill("Freiladia")));
	}
	else if (STR_Enemy_Name == "Corrupt Researcher")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Test Tube", "Empty glass test tube for lab purposes", 1));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Cracked Syringe", "Used for injections", 1));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Glass Shard", "Prone to shattering immediately", 2, (((rand() % 13) - 6) + 73), true));
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
	for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Potion of Instant Health", "Red liquid fills the blocky bottle", 4, "HP", 350));
	for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Potion of Mutated Souls", "Screaming can be heard inside the bottle", 4, "STA", 150));

	Item* ITEM_New_Item = VEC_Chest_Loot[rand() % (VEC_Chest_Loot.size())];
	return ITEM_New_Item;
}