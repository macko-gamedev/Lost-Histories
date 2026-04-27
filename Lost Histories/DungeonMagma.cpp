#include "DungeonMagma.h"

// X = Wall, ! = Enemy, > = Next Room, <  = Last Room, + = Player

DungeonMagma::DungeonMagma()
{
	this->STR_Dungeon_Name = "Magma Fields";
	this->INT_Dungeon_Room = 1;
	this->INT_Pos_X = 3;
	this->INT_Pos_Y = 7;
	this->VEC_Dungeon_Map =
	{
		{
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'O', 'O', 'O', 'X', 'X', 'X', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'O', 'O', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '>' },
			{ 'O', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', 'X' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'O', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'X', ' ', '+', ' ', ' ', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'X', 'X', ' ', ' ', ' ', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		},
		{
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'O' },
			{ 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O', 'O', 'X', 'X', ' ', 'X', 'X' },
			{ 'X', ' ', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X' },
			{ '<', '+', ' ', ' ', 'X', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X', 'O', 'X', 'X', ' ', 'X', 'O', 'X' },
			{ 'X', ' ', ' ', 'X', 'X', ' ', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X' },
			{ 'O', 'X', 'X', ' ', 'X', 'X', ' ', 'X', 'X', ' ', 'X', 'X', ' ', ' ', '>' },
			{ 'O', 'O', 'X', ' ', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'O', 'O' },
			{ 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'X', 'X', 'O', 'O', 'O' },
		},
		{
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'O' },
			{ 'O', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'O' },
			{ 'X', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X', 'O' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', 'X', 'O' },
			{ 'X', ' ', 'X', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', 'X', 'X', 'X', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', ' ', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', 'X', ' ', ' ', '>' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ '<', '+', ' ', 'X', 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'O', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O', 'O' },
			{ 'O', 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		},
		{
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'X', 'X', ' ', 'X', 'X', ' ', ' ', 'X', 'X', 'O', 'O', 'O', 'O' },
			{ 'O', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'O' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', '?', 'X' },
			{ 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', ' ', 'X', 'X' },
			{ '<', '+', ' ', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'O' },
			{ 'X', 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O' },
			{ 'O', 'X', ' ', ' ', 'X', ' ', ' ', 'X', 'X', ' ', 'X', 'X', 'O', 'O', 'O' },
			{ 'O', 'X', 'X', ' ', 'X', 'X', ' ', 'X', ' ', ' ', 'X', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		}
	};

	this->VEC_Explored_Rooms = { true, false, false, false };
	this->MAP_New_Room_Text =
	{
		{ 1, { "..." } },
		{ 2, { "...", "Yourself > This place is so hot, compared to the last locations I've explored", "Yourself > I feel like I'm getting closer to the end" } },
		{ 3, { "...", "Yourself > I'm sweating buckets", "Yourself > Where can one find a fan around here?", "Yourself > I sense that the next area may be the last", "Yourself > I should be extra prepared" } },
		{ 4, { "...", "This is the final room", "This will be the hardest battle you've fought yet, and maybe the last", "Make sure you are fully prepared for what's ahead", "You can travel to previous locations to make sure you have found everything you are looking for [SPACE + travel]", "Yourself > Let's do this!" } },
	};
}

void DungeonMagma::fillWithEnemies()
{
	// 15% chance for each tile to have an enemy
	for (int r = 0; r < 4; r++)
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

void DungeonMagma::fillWithChests()
{
	// 8% chance for each tile to have a chest
	for (int r = 0; r < 4; r++)
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

void DungeonMagma::elementSetter(Enemy& ENEMY_Enemy)
{
	// Normal Enemies
	if (ENEMY_Enemy.getName() == "Lava Spirit")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Abs"}, {"Water", "Wk"}, {"Ice", "Rpl"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (ENEMY_Enemy.getName() == "Japanese Soldier")
	{
		ENEMY_Enemy.setElements({ {"Fire", "-"}, {"Water", "Abs"}, {"Ice", "-"}, {"Electric", "Wk"}, {"Wind", "Rpl"}, {"Curse", "Wk"}, {"Bless", "Abs"} });
	}
	else if (ENEMY_Enemy.getName() == "Fire Prowler")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Abs"}, {"Water", "Wk"}, {"Ice", "-"}, {"Electric", "Rpl"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (ENEMY_Enemy.getName() == "Master's Servant")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Rpl"}, {"Water", "-"}, {"Ice", "Wk"}, {"Electric", "Nul"}, {"Wind", "Nul"}, {"Curse", "Abs"}, {"Bless", "Wk"} });
	}
	// Rare Enemies
	else if (ENEMY_Enemy.getName() == "Gold Entity VII")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Rpl"}, {"Water", "Abs"}, {"Ice", "Rpl"}, {"Electric", "Abs"}, {"Wind", "Rpl"}, {"Curse", "Abs"}, {"Bless", "Rpl"} });
	}
	// Main Boss
	else if (ENEMY_Enemy.getName() == "The Mastermind")
	{
		// Gimmick: Every 2 turns, it's element coverage changes randomly, first 2 turns starts with repellent to everything
		ENEMY_Enemy.setElements({ {"Fire", "Rpl"}, {"Water", "Rpl"}, {"Ice", "Rpl"}, {"Electric", "Rpl"}, {"Wind", "Rpl"}, {"Curse", "Rpl"}, {"Bless", "Rpl"} });
	}
	else if (ENEMY_Enemy.getName() == "Mutated Mastermind")
	{
		// Gimmick: Every 2 turns, it's element coverage changes randomly, first 2 turns starts with repellent to everything
		ENEMY_Enemy.setElements({ {"Fire", "Rpl"}, {"Water", "Rpl"}, {"Ice", "Rpl"}, {"Electric", "Rpl"}, {"Wind", "Rpl"}, {"Curse", "Rpl"}, {"Bless", "Rpl"} });
	}
	else if (ENEMY_Enemy.getName() == "Keeper of The Device")
	{
		// Gimmick: Every 2 turns, it's element coverage changes randomly, first 2 turns starts with repellent to everything
		ENEMY_Enemy.setElements({ {"Fire", "Rpl"}, {"Water", "Rpl"}, {"Ice", "Rpl"}, {"Electric", "Rpl"}, {"Wind", "Rpl"}, {"Curse", "Rpl"}, {"Bless", "Rpl"} });
	}
}

Enemy DungeonMagma::newEnemy()
{
	if (this->getDungeonRoom() == 1)
	{
		// Enemy level for this floor: 65-75		Lava Spirit: 65-71   Japanese Soldier: 70-75   Gold Entity VII: 70
		int INT_Enemy_Spawn_Chance = (rand() % 10) + 1;
		if (INT_Enemy_Spawn_Chance == 10)
		{
			return Enemy("Gold Entity VII", 70, 650, 0, { }, getItemFromLootTable("Gold Entity VII"), true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("Japanese Soldier", ((rand() % 6) + 70), 302, 189, { Skill("Splashadia"), Skill("Eye of the Ocean"), Skill("Gustadia"), Skill("Blightaon") }, getItemFromLootTable("Japanese Soldier"), false, 89);
		}
		else
		{
			return Enemy("Lava Spirit", ((rand() % 7) + 65), 264, 57, { Skill("Flamadia"), Skill("Eye of the Sun"), Skill("Freezadia"), Skill("Frei"), Skill("Healan") }, getItemFromLootTable("Lava Spirit"), false, 45);
		}
	}
	else if (this->getDungeonRoom() == 2)
	{
		// Enemy level for this floor: 72-80		Lava Spirit: 72-76   Japanese Soldier: 74-80   Fire Prowler: 76-80   Gold Entity VII: 75
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity VII", 75, 650, 0, { }, getItemFromLootTable("Gold Entity VII"), true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 11)
		{
			return Enemy("Japanese Soldier", ((rand() % 7) + 74), 302, 189, { Skill("Splashadia"), Skill("Eye of the Ocean"), Skill("Gustadia"), Skill("Blightaon") }, getItemFromLootTable("Japanese Soldier"), false, 89);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("Fire Prowler", ((rand() % 5) + 76), 287, 92, { Skill("Flamadia"), Skill("Meflamadia"), Skill("Eye of the Sun"), Skill("Zapadia") }, getItemFromLootTable("Fire Prowler"), false, 57);
		}
		else
		{
			return Enemy("Lava Spirit", ((rand() % 5) + 72), 264, 57, { Skill("Flamadia"), Skill("Eye of the Sun"), Skill("Freezadia"), Skill("Frei"), Skill("Healan") }, getItemFromLootTable("Lava Spirit"), false, 45);
		}
	}
	else if (this->getDungeonRoom() == 3)
	{
		// Enemy level for this floor: 78-86		Japanese Soldier: 78-82   Fire Prowler: 80-84   Master's Servant: 82-86   Gold Entity VII: 80
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity VII", 80, 650, 0, { }, getItemFromLootTable("Gold Entity VII"), true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 11)
		{
			return Enemy("Japanese Soldier", ((rand() % 7) + 78), 302, 189, { Skill("Splashadia"), Skill("Eye of the Ocean"), Skill("Gustadia"), Skill("Blightaon") }, getItemFromLootTable("Japanese Soldier"), false, 89);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("Fire Prowler", ((rand() % 5) + 80), 287, 92, { Skill("Flamadia"), Skill("Meflamadia"), Skill("Eye of the Sun"), Skill("Zapadia") }, getItemFromLootTable("Fire Prowler"), false, 57);
		}
		else
		{
			return Enemy("Master's Servant", ((rand() % 5) + 82), 316, 163, { Skill("Zapadia"), Skill("Eye of the Spark"), Skill("Gustadia"), Skill("Eye of the Storm"), Skill("Hexaon"), Skill("Mehexaon"), Skill("Healan")}, getItemFromLootTable("Master's Servant"), false, 109);
		}
	}
	else if (this->getDungeonRoom() == 4)
	{
		// Enemy level for this floor: 84-90		Master's Servant: 84-90   Gold Entity VII: 85
		int INT_Enemy_Spawn_Chance = (rand() % 10) + 1;
		if (INT_Enemy_Spawn_Chance > 7)
		{
			return Enemy("Gold Entity VII", 85, 650, 0, { }, getItemFromLootTable("Gold Entity VII"), true, 10);
		}
		else
		{
			return Enemy("Master's Servant", ((rand() % 5) + 82), 316, 163, { Skill("Zapadia"), Skill("Eye of the Spark"), Skill("Gustadia"), Skill("Eye of the Storm"), Skill("Hexaon"), Skill("Mehexaon"), Skill("Healan") }, getItemFromLootTable("Master's Servant"), false, 109);
		}
	}
}

Item* DungeonMagma::getItemFromLootTable(string STR_Enemy_Name)
{
	vector<Item*> VEC_Enemy_Drops = { };
	if (STR_Enemy_Name == "Lava Spirit")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Magma Rock", "Hot piece of magma rock", 1));
		/* 1 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Lava Spirit Plush", "A plush toy of the Lava Spirit", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Sword of Fire Aspect", "A purple tinted sword which ignites it's opponent in flames", 2, (((rand() % 21) - 10) + 132), true));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Volcanic Blade", "Sharp blade created by civilians who lived near the volcanoes", 3, (((rand() % 29) - 14) + 184), true));
	}
	else if (STR_Enemy_Name == "Japanese Soldier")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Foreign Coin", "A coin which you don't recognise", 2));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("10 Yen Coin", "Since when were ten yen coins a thing?", 3));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Golden Tachi", "A deeply curved sword used by the Samurai before the 15th Century, coated in gold", 4, (((rand() % 37) - 18) + 233), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Body Morphing Drugs", "Drugs used to increase users power and concentration significantly", 5, "ATK/MAG", 4));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements 50mg", "Drugs used to increase users power massively", 5, "ATK", 7));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills 50mg", "Drugs used to increase users concentration massively", 5, "MAG", 7));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Batra's Staff of Reckoning", "Let's turn the tide!", 5, Skill("Eye of the Ocean")));
	}
	else if (STR_Enemy_Name == "Fire Prowler")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Magma Rock", "Hot piece of magma rock", 1));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Bag of Ash", "Leather bag filled with dried, coolen ash", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Cube of Basalt", "A piece of the earth's crust in cube form", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Sword of Fire Aspect", "A purple tinted sword which ignites it's opponent in flames", 2, (((rand() % 21) - 10) + 132), true));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Volcanic Blade", "Sharp blade created by civilians who lived near the volcanoes", 3, (((rand() % 29) - 14) + 184), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Magma Forged Sword", "A sword forged from molten magma, gloves need to be worn", 5, (((rand() % 45) - 22) + 286), true));
	}
	else if (STR_Enemy_Name == "Master's Servant")
	{
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Poison Tipped Knife", "A knife coated in poison dripping, perfect for eliminating targets, quietly...", 4, (((rand() % 45) - 22) + 241), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Body Morphing Drugs", "Drugs used to increase users power and concentration significantly", 5, "ATK/MAG", 4));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements 50mg", "Drugs used to increase users power massively", 5, "ATK", 7));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills 50mg", "Drugs used to increase users concentration massively", 5, "MAG", 7));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Diamond", "A natural chunk of raw diamond from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Emerald", "A natural chunk of raw emerald from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Ruby", "A natural chunk of raw ruby from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Obsidian", "A natural chunk of raw obsidian from the earth", 5));
	}
	else if (STR_Enemy_Name == "Gold Entity VII")
	{
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Fitzroy Motherload", "'Motherlode's droppin'. Hold onto ya hats'", 5, Skill("Eye of the Sun")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Batra's Staff of Reckoning", "Let's turn the tide!", 5, Skill("Eye of the Ocean")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Paquette Pylon", "'Fuses set and capacitors charged'", 5, Skill("Eye of the Spark")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("F5 Twister in a Barrel", "Wreck havoc!!!", 5, Skill("Eye of the Storm")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Red Button", "A scratched engraving reads 'KJU'", 5, Skill("End of the World")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Magma Forged Sword", "A sword forged from molten magma, gloves need to be worn", 5, (((rand() % 45) - 22) + 286), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Body Morphing Drugs", "Drugs used to increase users power and concentration significantly", 5, "ATK/MAG", 4));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Diamond", "A natural chunk of raw diamond from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Emerald", "A natural chunk of raw emerald from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Ruby", "A natural chunk of raw ruby from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Obsidian", "A natural chunk of raw obsidian from the earth", 5));
	}
	return VEC_Enemy_Drops[rand() % VEC_Enemy_Drops.size()];
}

Item* DungeonMagma::getItemFromChest()
{ 
	vector<Item*> VEC_Chest_Loot = { };
	// Default Loot for Dungeon 4
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new Item("Magma Rock", "Hot piece of magma rock", 1));
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new Item("Generic Stone", "Just a random piece of stone", 1));
	for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new Item("Bag of Ash", "Leather bag filled with dried, coolen ash", 2));
	for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new Item("Cube of Basalt", "A piece of the earth's crust in cube form", 2));
	for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new ItemMelee("Sword of Fire Aspect", "A purple tinted sword which ignites it's opponent in flames", 2, (((rand() % 21) - 10) + 132), true));
	for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Hot Heart in a Bottle", "A scorching hot human heart trapped inside a bottle, blood still leaking from the organ", 4, "HP", 400));
	for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Lighter of Life", "Modified lighter which burns life essence", 4, "STA", 180));
	for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Power Supplements 50mg", "Drugs used to increase users power massively", 5, "ATK", 7));
	for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Concentration Pills 50mg", "Drugs used to increase users concentration massively", 5, "MAG", 7));

	// Additional Loot added per Room
	if (this->INT_Dungeon_Room >= 2)
	{
		for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemMelee("Volcanic Blade", "Sharp blade created by civilians who lived near the volcanoes", 3, (((rand() % 29) - 14) + 184), true));
		for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Emergency Defibrillator", "Last chance of survival, only use when absolutely necessary", 5, "HP", 999));
		for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Enhancement Flask", "A shiny purple tint covers the flask, drinking this makes you feel more alive", 5, "STA", 999));
	}
	if (this->INT_Dungeon_Room >= 3)
	{
		for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemMelee("Magma Forged Sword", "A sword forged from molten magma, gloves need to be worn", 5, (((rand() % 45) - 22) + 286), true));
	}

	Item* ITEM_New_Item = VEC_Chest_Loot[rand() % (VEC_Chest_Loot.size())];
	return ITEM_New_Item;
}