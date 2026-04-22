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
	};

	this->VEC_Explored_Rooms = { true, false, false, false, false, false };
	this->MAP_New_Room_Text =
	{
		{ 1, { "..." } },
		{ 2, { "...", "Yourself > This place is so hot, compared to the last locations I've explored", "Yourself > I feel like I'm getting closer to the end" } },
		{ 3, { "...", "You feel a strong presence in this section", "The next area looks to be locked behind a door", "Perhaps try searching for the key" , "Yourself > Here we go again..." } },
		{ 4, { "...", "You feel like your reaching the end", "Maybe you'll reach your destination soon...", "Yourself > Am I going crazy who is that?" , "Yourself > This place is making me crazy", "Your Mysterious Machine Part is glowing", "Yourself > Maybe I am nearly at the end", "Yourself > I need to refreeze the planet", "Yourself > Then what do I do?", "Yourself > I'm not sure..." } },
		{ 5, { "...", "You feel two strong presences in this section", "However, the next area looks to be unlocked already", "Yourself > What are they even here for then?" } },
		{ 6, { "...", "This is the final room", "The last entity roaming this place is beyond a locked door", "This will be the hardest battle you've fought yet", "Make sure you are fully prepared for what's ahead", "You can travel to previous locations to make sure you have found everything you are looking for [SPACE + travel]", "Yourself > *gulp*" } },
	};
}

void DungeonMagma::fillWithEnemies()
{
	// 15% chance for each tile to have an enemy
	for (int r = 0; r < 2; r++)
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
	for (int r = 0; r < 2; r++)
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
	// Rare Enemies
	else if (ENEMY_Enemy.getName() == "Gold Entity VII")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Rpl"}, {"Water", "Abs"}, {"Ice", "Rpl"}, {"Electric", "Abs"}, {"Wind", "Rpl"}, {"Curse", "Abs"}, {"Bless", "Rpl"} });
	}
	// Mini Bosses 
	// Main Boss
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
		// Enemy level for this floor: 72-80		Lava Spirit: 72-76   Japanese Soldier: 74-80   Gold Entity VII: 75
		int INT_Enemy_Spawn_Chance = (rand() % 10) + 1;
		if (INT_Enemy_Spawn_Chance == 10)
		{
			return Enemy("Gold Entity VII", 75, 650, 0, { }, getItemFromLootTable("Gold Entity VII"), true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("Japanese Soldier", ((rand() % 7) + 74), 302, 189, { Skill("Splashadia"), Skill("Eye of the Ocean"), Skill("Gustadia"), Skill("Blightaon") }, getItemFromLootTable("Japanese Soldier"), false, 89);
		}
		else
		{
			return Enemy("Lava Spirit", ((rand() % 5) + 72), 264, 57, { Skill("Flamadia"), Skill("Eye of the Sun"), Skill("Freezadia"), Skill("Frei"), Skill("Healan") }, getItemFromLootTable("Lava Spirit"), false, 45);
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
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Volcanic Blade", "Sharp blade created by civilians who lived near the volcanoes", 3, (((rand() % 29) - 14) + 184), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Magma Forged Sword", "A sword forged from molten magma, gloves need to be worn", 5, (((rand() % 45) - 22) + 286), true));
	}
	else if (STR_Enemy_Name == "Japanese Soldier")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Foreign Coin", "A coin which you don't recognise", 2));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("10 Yen Coin", "Since when were ten yen coins a thing?", 3));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Golden Tachi", "A deeply curved sword used by the Samurai before the 15th Century, coated in gold", 4, (((rand() % 37) - 18) + 233), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Body Morphing Drugs", "Drugs used to increase users power and concentration massively", 5, "ATK/MAG", 7));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements 50mg", "Drugs used to increase users power massively", 5, "ATK", 7));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills 50mg", "Drugs used to increase users concentration massively", 5, "MAG", 7));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Batra's Staff of Reckoning", "Let's turn the tide!", 5, Skill("Eye of the Ocean")));
	}
	else if (STR_Enemy_Name == "Gold Entity VII")
	{
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Fitzroy Motherload", "'Motherlode's droppin'. Hold onto ya hats'", 5, Skill("Eye of the Sun")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Batra's Staff of Reckoning", "Let's turn the tide!", 5, Skill("Eye of the Ocean")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Paquette Pylon", "'Fuses set and capacitors charged'", 5, Skill("Eye of the Spark")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("F5 Twister in a Barrel", "Wreck havoc!!!", 5, Skill("Eye of the Storm")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Red Button", "A scratched engraving reads 'KJU'", 5, Skill("End of the World")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Magma Forged Sword", "A sword forged from molten magma, gloves need to be worn", 5, (((rand() % 45) - 22) + 286), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Body Morphing Drugs", "Drugs used to increase users power and concentration massively", 5, "ATK/MAG", 7));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Diamond", "A natural chunk of raw diamond from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Emerald", "A natural chunk of raw emerald from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Ruby", "A natural chunk of raw ruby from the earth", 5));
	}
	return VEC_Enemy_Drops[rand() % VEC_Enemy_Drops.size()];
}

Item* DungeonMagma::getItemFromChest()
{ 
	vector<Item*> VEC_Chest_Loot = { };
	// Default Loot for Dungeon 4
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new Item("Magma Rock", "Hot piece of magma rock", 1));
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new Item("Generic Stone", "Just a random piece of stone", 1));
	for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemMelee("Volcanic Blade", "Sharp blade created by civilians who lived near the volcanoes", 3, (((rand() % 29) - 14) + 184), true));
	for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Hot Heart in a Bottle", "A scorching hot human heart trapped inside a bottle, blood still leaking from the organ", 4, "HP", 400));
	for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Lighter of Life", "Modified lighter which burns life essence", 4, "STA", 180));
	for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Power Supplements 50mg", "Drugs used to increase users power massively", 5, "ATK", 7));
	for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Concentration Pills 50mg", "Drugs used to increase users concentration massively", 5, "MAG", 7));


	// Additional Loot added per Room
	if (this->INT_Dungeon_Room >= 2)
	{

	}
	if (this->INT_Dungeon_Room >= 3)
	{

	}

	Item* ITEM_New_Item = VEC_Chest_Loot[rand() % (VEC_Chest_Loot.size())];
	return ITEM_New_Item;
}