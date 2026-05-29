#include "DungeonMagma.h"

// X = Wall, ! = Enemy, > = Next Room, <  = Last Room, + = Player

DungeonMagma::DungeonMagma(string N_Name)
{
	this->STR_Dungeon_Name = "Magma Fields";
	this->INT_Dungeon_Room = 1;
	this->INT_Pos_X = 3;
	this->INT_Pos_Y = 7;
	this->STR_Player_Name = N_Name;
	this->VEC_Dungeon_Map =
	{
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '>' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', '+', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
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
			{ 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', 'X', 'X' },
			{ 'X', ' ', 'X', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', 'X', 'X', 'X', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', ' ', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', 'X', ' ', ' ', '>' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ '<', '+', ' ', 'X', 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', '?', 'X' },
			{ 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', ' ', 'X', 'X' },
			{ '<', '+', ' ', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', 'X', 'X', ' ', 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
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
	this->MAP_Encounter_Dialogue =
	{
		{ 4, {
				"??? > Well well well",
				"??? > Look who decided to finally show up",
				("??? > " + STR_Player_Name),
				(STR_Player_Name + " > Who... are you?"),
				"??? > The one you are in persuit of...",
				"??? > ...The Mastermind",
				"The Mastermind > I quickly relocated The Device upon hearing about your coming",
				"The Mastermind > I am terribly sorry, but your little adventure must end here",
				"The Mastermind > You have caused quite the disturbance in my plan",
				"The Mastermind > Prepare to face your consequences"
			 }
		}
	};
	this->MAP_Encounter_Enemy =
	{
		{ 4, Enemy("The Mastermind", 90, 1982, 1752, { Skill("Flamadia") }, true, 148) }
	};
}

void DungeonMagma::displayDungeon()
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
				cout << dye::black_on_light_red(" ");
				if ((j + 1) == 15 && this->getDungeonMap()[(this->getDungeonRoom() - 1)][i][j] == 'X')
				{
					cout << dye::black_on_light_red(" ");
				}
				else if ((j + 1) < 15)
				{
					if (this->getDungeonMap()[(this->getDungeonRoom() - 1)][i][(j + 1)] == 'X')
					{
						cout << dye::black_on_light_red(" ");
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

Enemy DungeonMagma::newEnemy()
{
	if (this->getDungeonRoom() == 1)
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
	else if (this->getDungeonRoom() == 2)
	{
		// Enemy level for this floor: 72-80		Lava Spirit: 72-76   Japanese Soldier: 74-80   Fire Prowler: 76-80   Gold Entity VII: 75
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity VII", 75, 650, 0, { }, true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 11)
		{
			return Enemy("Japanese Soldier", ((rand() % 7) + 74), 302, 189, { Skill("Splashadia"), Skill("Splashadiaran"), Skill("Gustadia"), Skill("Blightaon") }, false, 89);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("Fire Prowler", ((rand() % 5) + 76), 287, 92, { Skill("Flamadia"), Skill("Meflamadia"), Skill("Flamadiaran"), Skill("Zapadia") }, false, 57);
		}
		else
		{
			return Enemy("Lava Spirit", ((rand() % 5) + 72), 264, 57, { Skill("Flamadia"), Skill("Flamadiaran"), Skill("Freezadia"), Skill("Frei"), Skill("Healan") }, false, 45);
		}
	}
	else if (this->getDungeonRoom() == 3)
	{
		// Enemy level for this floor: 78-86		Japanese Soldier: 78-82   Fire Prowler: 80-84   Master's Servant: 82-86   Gold Entity VII: 80
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity VII", 80, 650, 0, { }, true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 11)
		{
			return Enemy("Japanese Soldier", ((rand() % 7) + 78), 302, 189, { Skill("Splashadia"), Skill("Splashadiaran"), Skill("Gustadia"), Skill("Blightaon") }, false, 89);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("Fire Prowler", ((rand() % 5) + 80), 287, 92, { Skill("Flamadia"), Skill("Meflamadia"), Skill("Flamadiaran"), Skill("Zapadia") }, false, 57);
		}
		else
		{
			return Enemy("Master's Servant", ((rand() % 5) + 82), 316, 163, { Skill("Zapadia"), Skill("Zapadiaran"), Skill("Gustadia"), Skill("Gustadiaran"), Skill("Hexaon"), Skill("Mehexaon"), Skill("Healan") }, false, 109);
		}
	}
	else if (this->getDungeonRoom() == 4)
	{
		// Enemy level for this floor: 84-90		Master's Servant: 84-90   Gold Entity VII: 85
		int INT_Enemy_Spawn_Chance = (rand() % 10) + 1;
		if (INT_Enemy_Spawn_Chance > 7)
		{
			return Enemy("Gold Entity VII", 85, 650, 0, { }, true, 10);
		}
		else
		{
			return Enemy("Master's Servant", ((rand() % 5) + 82), 316, 163, { Skill("Zapadia"), Skill("Zapadiaran"), Skill("Gustadia"), Skill("Gustadiaran"), Skill("Hexaon"), Skill("Mehexaon"), Skill("Healan") }, false, 109);
		}
	}
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
	for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Power Supplements 50mg", "Drugs used to increase users power massively", 5, "ATK", 3.5));
	for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Concentration Pills 50mg", "Drugs used to increase users concentration massively", 5, "MAG", 3.5));

	// Additional Loot added per Room
	if (this->INT_Dungeon_Room >= 2)
	{
		for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemMelee("Volcanic Blade", "Sharp blade created by civilians who lived near the volcanoes", 3, (((rand() % 29) - 14) + 184), true));
		for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Emergency Defibrillator", "Last chance of survival, only use when absolutely necessary", 5, "HP", 999));
		for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Enhancement Flask", "A shiny purple tint covers the flask, drinking this makes you feel more alive", 5, "STA", 999));
		for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemSkill("Figurine of God - 2064 Edition", "A figure of what God is supposed to look like", 5, Skill("God's Power Punch")));
	}
	if (this->INT_Dungeon_Room >= 3)
	{
		for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemMelee("Magma Forged Sword", "A sword forged from molten magma, gloves need to be worn", 5, (((rand() % 45) - 22) + 286), true));
	}
	if (this->INT_Dungeon_Room >= 3)
	{
		for (int i = 0; i < 1; i++) VEC_Chest_Loot.push_back(new ItemSkill("Nuclear Numchucks", "A hyper-solution to any threat!", 5, Skill("Decaying Chucks")));
	}

	Item* ITEM_New_Item = VEC_Chest_Loot[rand() % (VEC_Chest_Loot.size())];
	return ITEM_New_Item;
}