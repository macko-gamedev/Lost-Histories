#include "DungeonGlacier.h"

// X = Wall, ! = Enemy, > = Next Room, <  = Last Room, + = Player
 
//DungeonGlacier::DungeonGlacier() { }

DungeonGlacier::DungeonGlacier(string N_Name)
{
	this->STR_Dungeon_Name = "Glacier Wasteland";
	this->INT_Dungeon_Room = 1;
	this->INT_Pos_X = 3;
	this->INT_Pos_Y = 10;
	this->STR_Player_Name = N_Name;
	this->VEC_Dungeon_Map =
	{
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, //       XXXXXXXX
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', '>' }, //    XXXX      >
			{ 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' }, //   XX       XXX
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X' }, //   X      XXX
			{ 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X' }, //   XX    XX
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X' }, //    XX    XXX
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' }, //     X      XX
			{ 'X', 'X', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' }, //  XXXX       X
			{ 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' }, // XX  XX      X
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X' }, // X    XXXXX  XX
			{ 'X', 'X', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X' }, // X P      X   X
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' }, // X            X
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X' }, // XX    XXXX   X
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X' }, //  XXXXXX  XX  X
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }  //           XXXX
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, // XXXX  XXXXX 
			{ 'X', '<', '+', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X' }, // <  XXXX   XX
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' }, // XX  X      XXX 
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', 'X' }, //  X     XX    X
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X' }, //  X      X    X
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' }, //  XX        XXX
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X' }, //   X       XX
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X' }, //   XXX XX   XX
			{ 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X' }, //   XX   XXX  XX
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X', 'X' }, //  XX     X  XX 
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' }, //  X  X      X   
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X', 'X' }, //  X      X  XX
			{ 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X' }, //  X   XX     XX
			{ 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '>' }, //  XXX         >
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }  //    XXXXXXXXXXX
		},
		{                                                                                  
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, // XXXX  XXXXXXXX 
			{ 'X', 'X', '?', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X' }, // X? XXXX   X  X
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', 'X', ' ', 'X', 'X' }, // XX  X   X X XX 
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X' }, //  X  X XXX X X 
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'X' }, //  X  X   X   X 
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X' }, //  XX   XXXXX X 
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X', 'X' }, //  XXXX     X X
			{ 'X', 'X', 'X', ' ', 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X' }, //  X XX XXXXX XX
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', '|', '>' }, //  X        X |>
			{ 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', 'X' }, //  X X XX X XXXX
			{ 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', 'X' }, //  X X XX X X X  
			{ 'X', 'X', 'X', ' ', 'X', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', 'X', 'X' }, //  X X    X X X
			{ 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', 'X' }, //  XXX XX X X XX
			{ 'X', 'X', '<', '+', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X' }, //  <      X    X
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }  //  XXXXXXXXXXXXX
		},
		{                                                                                  // --------------
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, //     XXXXXX 
			{ 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, //    XX    XX
			{ 'X', 'S', '!', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X' }, //   XX  XX  XX  
			{ 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X' }, //  XX   XX   XX
			{ 'X', 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' }, // XX          XX
			{ 'X', 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X' }, // X            X
			{ 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', '>' }, // X  XX    XX  >
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' }, // X            X
			{ 'X', '<', '+', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X' }, // <+   XXXX    X 
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X' }, // X            X
			{ 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' }, // X   XXXXXX   X
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X' }, // XX          XX
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X' }, //  XX   XX   XX 
			{ 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X' }, //   XXX    XXX
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }  //     XXXXXX
		},
		{                                                                                  // --------------
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, //   XXXXXXXXXXX 
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' }, //  XX         XX
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' }, //  X           X
			{ 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X' }, //  XXX X   X XXX
			{ 'X', 'X', 'X', 'X', 'X', ' ', 'X', '?', ' ', ' ', 'X', ' ', 'X', 'X', 'X' }, //    X X ? X X
			{ 'X', 'X', 'X', 'X', 'X', '!', 'X', 'X', 'X', 'X', 'X', '!', 'X', 'X', 'X' }, // XXXX!XXXXX!XXX
			{ 'X', '<', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '>' }, // <           |>
			{ 'X', 'X', 'X', 'X', 'X', '!', 'X', ' ', ' ', ' ', 'X', '!', 'X', 'X', 'X' }, // XXXX!X   X!XXX
			{ 'X', 'X', 'X', 'X', 'X', ' ', 'X', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X' }, //    X X   X X
			{ 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', ' ', 'X', 'X', ' ', 'X', 'X', 'X' }, //   XX XX XX XX
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X' }, //  XX   XXX   XX
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', 'X' }, //  X     X     X
			{ 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X' }, //  XX   XXX   XX
			{ 'X', 'X', 'X', 'X', 'X', '*', 'X', 'X', 'X', 'X', 'X', '*', 'X', 'X', 'X' }, //   XX*XX XX*XX
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }  //    XXX   XXX
		},
		{
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, //
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, //
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, //
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, //
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, //
			{ 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, //
			{ 'X', '<', '+', ' ', ' ', '!', ' ', ' ', '!', ' ', ' ', 'X', 'X', 'X', 'X' }, // <    !  !  ! ?
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X' }, //
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X' }, //
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X' }, //
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', '?', 'X' }, //
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X' }, //
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, //
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, //
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
		}
	};
	this->VEC_Explored_Rooms = { true, false, false, false, false, false };
	this->MAP_New_Room_Text =
	{
		{ 1, { "..." } },
		{ 2, { "...", "You feel a sharp chill down your spine", "Maybe you should take extra care whilst exploring", "[You can press SPACE and type /help for a list of commands!]"}},
		{ 3, { "...", "You feel a strong presence in this section", "The next area looks to be locked behind a door", "Perhaps try searching for the key" } },
		{ 4, { "...", "An overwhelming panic is starting to set in", "Yourself > What is this place!?" } },
		{ 5, { "...", "You feel a strong presence in this section", "The next area looks to be locked behind a door", "Perhaps try searching for the key", "Yourself > Another locked door?", "Yourself > The last strong 'thing' was hard enough..."} },
		{ 6, { "...", "The land is void of enemies but two guards and a formidable opponent", "Make sure you're ready for whats up ahead" } }
	};
	this->MAP_Encounter_Dialogue =
	{
		{ 3, { 
				"Yourself > What is this creature...",
				"Yourself > Regardless, it seems to have a key embedded on it's torso",
				"Yourself > I should probably try grabbing it",
				"??? > *growls angrily*",
				("??? > *charges towards " + STR_Player_Name + "*")
			 }
		},
		{ 5, { 
				"Duty Soldier > Aha! Another worthless twat trying to get in our way!",
				"Yourself > There seems to be a key dangling on his belt",
				"Yourself > Perhaps I need to grab it by force",
				"Duty Soldier > Come here little one let me put you out of your misery...",
				(STR_Player_Name + " > Bring it!")
	         } 
	    },
		{ 6, {
				"??? > Who goes there!?",
				"??? > Only authorised personal can go enter this unexplored point of interest",
				(this->STR_Player_Name + " > What's going on?"),
				(this->STR_Player_Name + " > What year even is it??"),
				"??? > The year is 2067, the date is the 31st of January. And who are you weakling?",
				(this->STR_Player_Name + " > " + this->STR_Player_Name + "."),
				"??? > I'm an active sergeant for the russians who currently compromise this area",
				"Russian Sergeant > State your reason for being here",
				(this->STR_Player_Name + " > I want to know what's going on"),
				"Russian Sergeant > I'm afraid I cannot tell you",
				"Russian Sergeant > If you can prove to me you are capable, I may let you pass",
				(this->STR_Player_Name + " > Huh? Prove to you what?"),
				"Russian Sergeant > This..."
			 }
		}
	}; 
	this->MAP_Encounter_Enemy =
	{
		{ 3, Enemy("Snow Golem", 10, 232, 54, { Skill("Mefreeze"), Skill("Freezan"), Skill("Hex") }, true, 31) },
		{ 5, Enemy("Duty Soldier", 12, 384, 67, { Skill("Flame"), Skill("Zap"), Skill("Zapao"), Skill("Blight")}, true, 37) },
		{ 6, Enemy("Russian Sergeant", 15, 537, 93, { Skill("Meflamao"), Skill("Freezan"), Skill("Gust"), Skill("Meblight"), Skill("Hex") }, true, 56) }
	};
}

Enemy DungeonGlacier::newEnemy()
{
	if (this->getDungeonRoom() == 1)
	{
		// Enemy level for this floor: 1-3		Ice Monster: 1-3
		return Enemy("Ice Monster", ((rand() % 3) + 1), 30, 24, { Skill("Freeze") }, false, 14);
	}
	else if (this->getDungeonRoom() == 2)
	{
		// Enemy Level for this floor: 2-5		Ice Monster: 2-5
		return Enemy("Ice Monster", ((rand() % 4) + 2), 30, 24, { Skill("Freeze") }, false, 14);
	}
	else if (this->getDungeonRoom() == 3)
	{
		// Enemy Level for this floor: 3-7		Ice Monster: 3-6	Ice Fiend: 4-7
		if (((rand() % 5) + 1) > 3)
		{
			return Enemy("Ice Fiend", ((rand() % 4) + 4), 45, 18, { Skill("Freeze"), Skill("Freezan") }, false, 21);
		}
		else
		{
			return Enemy("Ice Monster", ((rand() % 4) + 3), 30, 24, { Skill("Freeze") }, false, 14);
		}
	}
	else if (this->getDungeonRoom() == 4)
	{
		// Enemy Level for this floor: 4-9		Ice Monster: 4-8	Ice Fiend: 5-8	 Bergmite: 5-9   Gold Entity I: 5
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 18)
		{
			return Enemy("Gold Entity I", 5, 200, 0, { }, true, 10);
		}
		else if (INT_Enemy_Spawn_Chance > 11)
		{
			return Enemy("Bergmite", ((rand() % 5) + 5), 62, 27, { Skill("Freezan"), Skill("Gust") }, false, 26);
		}
		else if (INT_Enemy_Spawn_Chance > 5)
		{
			return Enemy("Ice Fiend", ((rand() % 4) + 5), 45, 18, { Skill("Freeze"), Skill("Freezan") }, false, 21);
		}
		else
		{
			return Enemy("Ice Monster", ((rand() % 5) + 4), 30, 24, { Skill("Freeze") }, false, 14);
		}
	}
	else if (this->getDungeonRoom() == 5)
	{
		// Enemy Level for this floor: 8-15		Ice Monster: 8-12	Ice Fiend: 9-13	 Bergmite: 10-15   Wasteland Spirit: 12-15
		int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
		if (INT_Enemy_Spawn_Chance > 17)
		{
			return Enemy("Wasteland Spirit", ((rand() % 4) + 12), 79, 41, { Skill("Flame"), Skill("Freeze"), Skill("Zap"), Skill("Gust") }, false, 34);
		}
		if (INT_Enemy_Spawn_Chance > 11)
		{
			return Enemy("Bergmite", ((rand() % 6) + 10), 62, 27, { Skill("Freezan"), Skill("Gust") }, false, 26);
		}
		else if (INT_Enemy_Spawn_Chance > 6)
		{
			return Enemy("Ice Fiend", ((rand() % 5) + 9), 45, 18, { Skill("Freeze"), Skill("Freezan") }, false, 21);
		}
		else
		{
			return Enemy("Ice Monster", ((rand() % 5) + 8), 30, 24, { Skill("Freeze") }, false, 14);
		}
	}

	else if (this->getDungeonRoom() == 6)
	{
		// Enemy Level for this floor: 15		Patrol Soldier: 15
		return Enemy("Patrol Soldier", 15, 146, 27, { Skill("Flamao"), Skill("Meflamao"), Skill("Gustan"), Skill("Blighta") }, true, 48);
	}
}

Item* DungeonGlacier::getItemFromChest()
{
	vector<Item*> VEC_Chest_Loot = { };
	// Default Loot for Dungeon 1
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1));
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new Item("Ripped Shoes", "A pair of ripped shoes", 1));
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new ItemSkill("Old Cross", "An old church cross emitting a blessing aura", 1, Skill("Blight")));
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new ItemSkill("Shattered Molotov", "Ash remains inside the bottle", 1, Skill("Flame")));
	for (int i = 0; i < 5; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 40));
	for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new Item("Foreign Coin", "A coin which you don't recognise", 2));
	for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new ItemMelee("Nail Board", "Plank of frozen wood with a nail pointing out the end", 2, (((rand() % 7) - 3) + 21), true));
	for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new ItemSkill("Box of Matches", "Withered box of fire matches, can they still alight?", 2, Skill("Meflame")));
	for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemMelee("Ice-Axe", "Battleaxe frozen to time", 3, (((rand() % 11) - 5) + 36), true));

	// Additional Loot added per Room
	if (this->INT_Dungeon_Room >= 2)
	{
		for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 35));
	}
	if (this->INT_Dungeon_Room >= 3)
	{
		for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemMelee("Ice Crossbow", "Icified crossbow which fires icicles", 3, (((rand() % 13) - 6) + 46), true));
	}
	if (this->INT_Dungeon_Room >= 4)
	{
		for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new ItemSkill("Goat Horn", "Remains of what looks like a goat, what is it even doing here?", 2, Skill("Megust")));
		for (int i = 0; i < 4; i++) VEC_Chest_Loot.push_back(new ItemConsumable("Worn Field Kit", "Can still be used for emergencies", 2, "HP", 100));
		for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new ItemMelee("Wingman", "Familiar looking revolver, it seems damaged but could still work", 4, (((rand() % 15) - 7) + 67), true));
	}
	if (this->INT_Dungeon_Room >= 5)
	{
		for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemSkill("Electrical Wire", "Exposed electric wire that still packs some spark", 3, Skill("Zapao")));
		for (int i = 0; i < 3; i++) VEC_Chest_Loot.push_back(new ItemSkill("Old Pendant", "An old heart pendant emitting a healthy aura", 3, Skill("Heal")));
		for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new Item("Chipped Diamond", "Exposed diamond which appears chipped and frozen over, might still carry some value", 4));
	}
	Item* ITEM_New_Item = VEC_Chest_Loot[rand() % (VEC_Chest_Loot.size())];
	return ITEM_New_Item;
}