#include "DungeonAtlantis.h"

// X = Wall, ! = Enemy, > = Next Room, <  = Last Room, + = Player

//DungeonAtlantis::DungeonAtlantis() { }

DungeonAtlantis::DungeonAtlantis(string N_Name)
{
	this->STR_Dungeon_Name = "Atlantis Ruins";
	this->INT_Dungeon_Room = 1;
	this->INT_Pos_X = 3;
	this->INT_Pos_Y = 7;
	this->STR_Player_Name = N_Name;
	this->VEC_Dungeon_Map =
	{
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '>' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', '!', ' ', ' ', '*', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ '<', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '>' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', '?', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', '*', 'X', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '?', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X' },
			{ '<', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '>' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', 'X', ' ', 'X', 'X', 'X', ' ', ' ', 'X', ' ', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', 'X', ' ', ' ', 'X', 'X', 'X', ' ', 'X', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', ' ', 'X', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', 'X', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X' },
			{ '<', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '>', 'X', ' ', '*', 'X' },
			{ 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', 'X', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', 'X', 'X', ' ', ' ', 'X' },
			{ 'X', ' ', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', '?', ' ', ' ', ' ', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', ' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', 'X', 'X', ' ', 'X' },
			{ 'X', ' ', 'X', ' ', ' ', 'X', 'X', ' ', 'X', 'X', '?', 'X', ' ', ' ', 'X' },
			{ 'X', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', 'X', 'X' },
			{ 'X', ' ', 'X', 'X', '<', '+', ' ', '*', ' ', ' ', 'X', ' ', ' ', '|', '>' },
			{ 'X', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X' },
			{ 'X', ' ', 'X', ' ', ' ', 'X', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X' },
			{ 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', ' ', '>' },
			{ 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', ' ', 'X', 'X', 'X', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', ' ', 'X', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', 'X' },
			{ '<', '+', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' },
			{ '<', '+', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '?', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
		}
	};
	this->VEC_Explored_Rooms = { true, false, false, false, false, false, false };
	this->MAP_New_Room_Text =
	{
		{ 1, { "..." } },
		{ 2, { "...", "You feel a strong presence in this section", "The next area looks to be locked behind a door", "Perhaps try searching for the key", "Yourself > Theres more locked doors here too!? "} },
		{ 3, { "...", "You feel a strong presence in this section", "The next area looks to be locked behind a door", "Yourself > Compared to the last area, this place 'looks' more peaceful", "Yourself > Maybe without the monsters"} },
		{ 4, { "...", "You feel a strong presence in this section", "The next area looks to be locked behind a door", "Yourself > Can I catch a break?" } },
		{ 5, { "...", "You feel a strong presence in this section", "The next area looks to be locked behind a door", "Yourself > This is a joke", "Yourself > Sometimes I wished I never unfronze..." } },
		{ 6, { "...", "A tunnel leads downwards and splits off two ways with one exit", "Yourself > Is it even worth fighting anymore..." } },
		{ 7, { "...", "This seems to be the last room of the dungeon", "The room is full of soldiers and a formidable opponent", "Make sure you're ready for whats up ahead" } },
	};
	this->MAP_Encounter_Dialogue =
	{
		{ 2, {
				"??? > Who the fuck are you? What are you doing here!?",
				(STR_Player_Name + " > I beat that Russian Sergeant back in the Glacier Wastelands, and now I am here"),
				"??? > Russian Sergeant? You mean the russians are here?",
				(STR_Player_Name + " > Uh... yeah..."),
				"??? > Bloody outrageous! I am a soldier from the UK, how can they be here already!",
				"British Soldier > What are your intentions anyway? Can't you see we're busy?",
				(STR_Player_Name + " > I'm not sure... but I want answers, why am I here? I thought I was a goner 41 years ago!"),
				(STR_Player_Name + " > So if I was you I'd hand over that key so I can advance..."),
				"British Soldier > Christ almighty! Aren't you a tough guy?",
				"British Soldier > We've been experimenting with reanimations with all this new uncovered knowledge",
				"British Soldier > Why don't you fight one of our little subjects?"
			 }
		},
		{ 3, {
				"Yourself > Heyyyy, could you like lowkey gimme that key?",
				"??? > ...",
				"??? > *gargling*",
				"British Soldier > You beat that mermaid thingy?",
				"British Soldier > Bloody hell! That subject was useless!",
				"British Soldier > Well behold! Our 'newest' creation!",
				"British Soldier > We dragged the dead corpses of one of the many civilizations that used to inhabit here",
				"British Soldier > Isn't that right, Jellyfisherman?",
				"Reanimated Jellyfisherman > *gargles more*",
				("Reanimated Jellyfisherman > *shoots bolts towards " + STR_Player_Name + "*")
			 }
		},
		{ 4, {
				"You notice something feels off",
				"British Soldier > Notice the radical looking hazmat?",
				"??? > *gargling*",
				"British Soldier > Looks like that Jellyfisherman was utter pointless aswell!",
				"British Soldier > Blooming heck! Can anything round here be useful?",
				"The soldier storms off in a fit of rage",
				"The air feels poisonous",
				("??? > *lunges towards " + STR_Player_Name + "*")
			 }
		},
		{ 5, {
				"??? > *gargles*",
				("??? > *charges at " + STR_Player_Name + "*")
			 }
	    },
		{ 7, {
				"??? > Why must you come here!??",
				"??? > Our sancturary!",
				"??? > Why must another pest such as yourself come here and ruin everything!?",
				(STR_Player_Name + " > I don't even know who you are..."),
				"A small object is glowing on the creatures waistband",
				(STR_Player_Name + " > That object seems important, give it to me or I'll take it by force"),
				"??? > ARGHHHHH!!!!!"
			 }
		}
	};
	this->MAP_Encounter_Enemy =
	{
		{ 2, Enemy("Reanimated Mermaid", 20, 586, 126, { Skill("Flame"), Skill("Flamao"), Skill("Flamadia"), Skill("Zapao"), Skill("Hexo"), Skill("Blighta") }, true, 53) },
		{ 3, Enemy("Reanimated Jellyfisherman", 25, 636, 174, { Skill("Splashan"), Skill("Splashadia"), Skill("Zapadia"), Skill("Mezapadia"), Skill("Hexo"), Skill("Blighta") }, true, 28) },
		{ 4, Enemy("Radioactive Atlantis Survivor", 28, 746, 214, { Skill("Splashadia"), Skill("Mesplashadia"), Skill("Frei"), Skill("Heal") }, true, 6) },
		{ 5, Enemy("Radioactive Atlantis Guard", 30, 813, 214, { Skill("Meflamao"), Skill("Mesplashan"), Skill("Zapao"), Skill("Hexaon"), Skill("Frei"), Skill("Heal") }, true, 95) },
		{ 7, Enemy("Reawoken Guardian of Atlantis", 35, 976, 214, { Skill("Flamao"), Skill("Splashan"), Skill("Splashadia"), Skill("Freezan"), Skill("Hexo"), Skill("Mehexaon"), Skill("Heal") }, true, 47) }
	};
}

void DungeonAtlantis::displayDungeon()
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
				cout << dye::black_on_aqua(" ");
				if ((j + 1) == 15 && this->getDungeonMap()[(this->getDungeonRoom() - 1)][i][j] == 'X')
				{
					cout << dye::black_on_aqua(" ");
				}
				else if ((j + 1) < 15)
				{
					if (this->getDungeonMap()[(this->getDungeonRoom() - 1)][i][(j + 1)] == 'X')
					{
						cout << dye::black_on_aqua(" ");
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


Enemy DungeonAtlantis::newEnemy()
{
	if (this->getDungeonRoom() == 1)
	{
		// Enemy level for this floor: 14-20		Patrol Soldier: 14-17   Lab Fish: 16-19   Gold Entity: 20
		int INT_Enemy_Spawn_Chance = (rand() % 10) + 1;
		if (INT_Enemy_Spawn_Chance == 10)
		{
			return Enemy("Gold Entity II", 20, 150, 0, { }, true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("Lab Fish", ((rand() % 3) + 16), 125, 109, { Skill("Freezan"), Skill("Zapao"), Skill("Mezapao"), Skill("Hex") }, false, 33);
		}
		else
		{
			return Enemy("Patrol Soldier", ((rand() % 3) + 14), 146, 27, { Skill("Flamao"), Skill("Meflamao"), Skill("Gustan"), Skill("Blighta") }, false, 48);
		}
	}
	else if (this->getDungeonRoom() == 2)
	{
		// Enemy level for this floor: 17-23		Patrol Soldier: 17-20   Lab Fish: 18-22   Royal Guard: 20-23   Gold Entity: 20
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity II", 20, 150, 0, { }, true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 14)
		{
			return Enemy("Royal Guard", ((rand() % 4) + 20), 173, 69, { Skill("Flamao"), Skill("Freezan"), Skill("Hex"), Skill("Blight") }, false, 67);
		}
		else if (INT_Enemy_Spawn_Chance > 6)
		{
			return Enemy("Lab Fish", ((rand() % 5) + 18), 125, 109, { Skill("Freezan"), Skill("Zapao"), Skill("Mezapao"), Skill("Hex") }, false, 33);
		}
		else
		{
			return Enemy("Patrol Soldier", ((rand() % 4) + 17), 146, 27, { Skill("Flamao"), Skill("Meflamao"), Skill("Gustan"), Skill("Blighta") }, false, 48);
		}
	}
	else if (this->getDungeonRoom() == 3)
	{
		// Enemy level for this floor: 21-26		Lab Fish: 21-25   Royal Guard: 22-26   Armed Soldier: 25-27   Gold Entity: 25
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity III", 25, 250, 0, { }, true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 14)
		{
			return Enemy("Royal Guard", ((rand() % 5) + 22), 173, 69, { Skill("Flamao"), Skill("Freezan"), Skill("Hex"), Skill("Blight") }, false, 67);
		}
		else if (INT_Enemy_Spawn_Chance > 6)
		{
			return Enemy("Lab Fish", ((rand() % 5) + 21), 125, 109, { Skill("Freezan"), Skill("Zapao"), Skill("Mezapao"), Skill("Hex") }, false, 33);
		}
		else
		{
			return Enemy("Armed Soldier", ((rand() % 3) + 25), 219, 27, { Skill("Flamao"), Skill("Flamadia"), Skill("Zapao"), Skill("Gust"), Skill("Hex") }, false, 73);
		}
	}
	else if (this->getDungeonRoom() == 4)
	{
		// Enemy level for this floor: 24-30		Royal Guard: 24-28   Armed Soldier: 27-30   Sharkman: 26-30   Gold Entity: 25
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity III", 25, 250, 0, { }, true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 14)
		{
			return Enemy("Royal Guard", ((rand() % 5) + 24), 173, 69, { Skill("Flamao"), Skill("Freezan"), Skill("Hex"), Skill("Blight") }, false, 67);
		}
		else if (INT_Enemy_Spawn_Chance > 6)
		{
			return Enemy("Sharkman", ((rand() % 5) + 26), 192, 156, { Skill("Splashan"), Skill("Mesplashan"), Skill("Gustan"), Skill("Blighta") }, false, 56);
		}
		else
		{
			return Enemy("Armed Soldier", ((rand() % 4) + 27), 219, 27, { Skill("Flamao"), Skill("Flamadia"), Skill("Zapao"), Skill("Gust"), Skill("Hex") }, false, 73);
		}
	}
	else if (this->getDungeonRoom() == 5)
	{
		// Enemy level for this floor: 28-34		Armed Soldier: 28-33   Sharkman: 31-34   Reanimated Entity: 29-34   Gold Entity: 30
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity III", 30, 250, 0, { }, true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 14)
		{
			return Enemy("Reanimated Entity", ((rand() % 6) + 29), ((rand() % 50) + 175), 100, { Skill("Flamao"), Skill("Splashan"), Skill("Freezan"), Skill("Zapao"), Skill("Gustan"), Skill("Hexo"), Skill("Blighta") }, false, 67);
		}
		else if (INT_Enemy_Spawn_Chance > 6)
		{
			return Enemy("Sharkman", ((rand() % 5) + 26), 192, 156, { Skill("Splashan"), Skill("Mesplashan"), Skill("Gustan"), Skill("Blighta") }, false, 56);
		}
		else
		{
			return Enemy("Armed Soldier", ((rand() % 4) + 27), 219, 27, { Skill("Flamao"), Skill("Flamadia"), Skill("Zapao"), Skill("Gust"), Skill("Hex") }, false, 73);
		}
	}
	else if (this->getDungeonRoom() == 6)
	{
		// Enemy level for this floor: 31-37		Sharkman: 33-37   Reanimated Entity: 31-37   British Soldier: 34-37   Gold Entity: 35
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity III", 35, 250, 0, { }, true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 14)
		{
			return Enemy("Reanimated Entity", ((rand() % 8) + 31), ((rand() % 50) + 175), 100, { Skill("Flamao"), Skill("Splashan"), Skill("Freezan"), Skill("Zapao"), Skill("Gustan"), Skill("Hexo"), Skill("Blighta") }, false, 67);
		}
		else if (INT_Enemy_Spawn_Chance > 6)
		{
			return Enemy("Sharkman", ((rand() % 5) + 33), 192, 156, { Skill("Splashan"), Skill("Mesplashan"), Skill("Gustan"), Skill("Blighta") }, false, 56);
		}
		else
		{
			return Enemy("British Soldier", ((rand() % 4) + 34), 241, 27, { Skill("Gustan"), Skill("Zapao"), Skill("Blighta"), Skill("Blightaon"), Skill("Heal") }, false, 84);
		}
	}
	else if (this->getDungeonRoom() == 7)
	{
		// Enemy level for this floor: 36-40		British Soldier: 36-40   Gold Entity: 35
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 15)
		{
			return Enemy("Gold Entity III", 35, 250, 0, { }, true, 10);
		}
		else
		{
			return Enemy("British Soldier", ((rand() % 5) + 36), 241, 27, { Skill("Gustan"), Skill("Zapao"), Skill("Blighta"), Skill("Blightaon"), Skill("Heal") }, false, 84);
		}
	}
}

Item* DungeonAtlantis::getItemFromChest()
{
	vector<Item*> VEC_Chest_Loot = { };
	// Default Loot for Dungeon 2
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new Item("Ripped Shoes", "A pair of ripped shoes", 1));
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new Item("Half Eaten Sandwich", "Some would call it a penguin classic(s)", 1));
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new Item("Crocodile Floaty", "For a nice summers day", 1));
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new ItemSkill("Vial of Ink", "An old vial with ink emitting a curseful aura", 1, Skill("Hex")));
	for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new Item("Foreign Coin", "A coin which you don't recognise", 2));
	for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new ItemMelee("Rusty Anchor", "A ship's anchor mainly covered in rust", 2, (((rand() % 11) - 5) + 56), true));
	for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Worn Field Kit", "Can still be used for emergencies", 2, "HP", 100));
	for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemMelee("Trident", "Sharp spike-like ends perfect for impaling", 3, (((rand() % 15) - 7) + 73), true));
	for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemSkill("Old Pendant", "An old heart pendant emitting a healthy aura", 3, Skill("Heal")));
	for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemSkill("Silver Jab Stick", "They use these in the olympics!", 3, Skill("Quick Jab")));

	// Additional Loot added per Room
	if (this->INT_Dungeon_Room >= 2)
	{
		for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new ItemSkill("Water Balloon", "May annoy some people", 2, Skill("Mesplash")));
		for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemMelee("Iron Spear", "Has great reach!", 3, (((rand() % 15) - 7) + 86), true));
		for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Power Supplements", "Drugs used to increase users power", 3, "ATK", 2.5));
		for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Concentration Pills", "Drugs used to increase users concentration", 3, "MAG", 2.5));
		for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new ItemSkill("Glass Pendant", "A glass heart pendant emitting a strong healthy aura", 4, Skill("Healan")));
	}
	if (this->INT_Dungeon_Room >= 3)
	{
		for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Medkit", "For a quick patch up", 3, "HP", 200));
	}
	if (this->INT_Dungeon_Room >= 4)
	{
		for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new Item("Gold Coin", "Made of real gold!", 3));
		for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Holy Water", "Drinking this feels godly", 3, "STA", 80));
		for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemSkill("Pair of Sickles", "Twice the slice!", 3, Skill("Sickle Dance")));
	}
	if (this->INT_Dungeon_Room >= 5)
	{
		for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new ItemSkill("Waterproof Flamethrower", "How this combination works is beyond comprehension", 4, Skill("Flamadia")));
	}
	Item* ITEM_New_Item = VEC_Chest_Loot[rand() % (VEC_Chest_Loot.size())];
	return ITEM_New_Item;
}