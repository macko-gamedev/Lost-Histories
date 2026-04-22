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

void DungeonMagma::fillWithEnemies()
{
	// 15% chance for each tile to have an enemy
	for (int r = 0; r < 1; r++)
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
	for (int r = 0; r < 1; r++)
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
		// Enemy level for this floor: 65-75
		int INT_Enemy_Spawn_Chance = (rand() % 10) + 1;
		if (INT_Enemy_Spawn_Chance == 10)
		{
			return Enemy("Gold Entity VII", 70, 650, 0, { }, getItemFromLootTable("Gold Entity VII"), true, 10);
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
}

Item* DungeonMagma::getItemFromLootTable(string STR_Enemy_Name)
{
	vector<Item*> VEC_Enemy_Drops = { };
	if (STR_Enemy_Name == "Lava Spirit")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Test Tube", "Empty glass test tube for lab purposes", 1));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Cracked Syringe", "Used for injections", 1));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Glass Shard", "Prone to shattering immediately", 2, (((rand() % 13) - 6) + 73), true));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Chemical Pipette", "Used for transferring liquids", 3));
	}
	else if (STR_Enemy_Name == "Gold Entity VII")
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

Item* DungeonMagma::getItemFromChest()
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