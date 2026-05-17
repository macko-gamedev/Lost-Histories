#include "DungeonAtlantis.h"

// X = Wall, ! = Enemy, > = Next Room, <  = Last Room, + = Player

//DungeonAtlantis::DungeonAtlantis() { }

DungeonAtlantis::DungeonAtlantis()
{
	this->STR_Dungeon_Name = "Atlantis Ruins";
	this->INT_Dungeon_Room = 1;
	this->INT_Pos_X = 3;
	this->INT_Pos_Y = 7;
	this->VEC_Dungeon_Map =
	{
		{
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'O', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '>' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'O', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'O', 'O', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X', 'O' }
		},
		{
			{ 'O', 'O', 'X', 'O', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'X', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', '!', ' ', ' ', '*', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', 'X', 'O', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'X', 'X', ' ', ' ', 'X', 'O', 'O', 'O', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ '<', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '>' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'O', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', '?', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', '*', 'X', ' ', 'X', 'X' },
			{ 'O', 'O', 'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O' }
		},
		{
			{ 'X', 'X', 'X', 'O', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'O' },
			{ 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'O', 'O', 'X', ' ', ' ', 'X', 'O', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'O' },
			{ 'O', 'X', 'X', ' ', ' ', 'X', 'O', 'X', ' ', 'X', 'O', 'X', ' ', 'X', 'O' },
			{ 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X' },
			{ '<', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '>' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'O', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X' },
			{ 'O', 'O', ' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'O' },
			{ 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
		},
		{
			{ 'X', 'X', 'X', 'X', 'O', 'X', ' ', 'X', 'O', 'O', 'X', 'X', 'X', 'O', 'O' },
			{ 'O', ' ', ' ', 'X', ' ', 'X', 'X', 'X', ' ', ' ', 'X', ' ', 'X', 'X', 'O' },
			{ 'O', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'O' },
			{ 'O', 'O', 'X', ' ', 'X', ' ', ' ', 'X', 'X', 'X', ' ', 'X', ' ', ' ', 'O' },
			{ 'O', 'X', 'X', ' ', ' ', ' ', 'X', 'X', ' ', 'X', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', 'X', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'O' },
			{ '<', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '>', 'X', ' ', '*', 'O' },
			{ 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'O' },
			{ 'X', 'X', 'X', ' ', 'X', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', 'X', 'X', ' ', ' ', 'O' },
			{ 'X', ' ', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', '?', ' ', ' ', ' ', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', 'X', 'O' },
			{ 'X', 'X', 'X', 'O', 'O', 'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'O' }
		},
		{
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'X', ' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', ' ', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', 'X', 'X', ' ', 'X' },
			{ 'X', ' ', 'X', ' ', ' ', 'X', 'X', ' ', 'X', 'X', '?', 'X', ' ', ' ', 'X' },
			{ 'X', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', 'X', 'X' },
			{ 'X', ' ', 'X', 'O', '<', '+', ' ', '*', ' ', ' ', 'X', ' ', ' ', '|', '>' },
			{ 'X', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X' },
			{ 'X', ' ', 'X', ' ', ' ', 'X', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', 'X', ' ', '|', ' ', 'X' },
			{ 'X', ' ', 'X', 'X', 'X', 'X', 'X', '?', ' ', 'X', 'X', 'X', 'X', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' }
		},
		{
			{ 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'X', 'X', ' ', ' ', 'X', 'X', 'O', 'O', 'X', 'X', 'X' },
			{ 'O', 'O', 'O', 'O', 'X', ' ', ' ', ' ', ' ', 'X', 'O', 'X', 'X', ' ', '>' },
			{ 'O', 'O', 'O', 'X', 'X', ' ', 'X', 'X', ' ', 'X', 'X', 'X', ' ', ' ', 'X' },
			{ 'O', 'O', 'O', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X' },
			{ 'O', 'O', 'X', 'X', ' ', 'X', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', 'O' },
			{ 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ', 'O' },
			{ '<', '+', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X' },
			{ 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X', ' ', 'X' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', 'X' },
			{ 'O', 'X', 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X' },
			{ 'O', 'O', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X' },
			{ 'O', 'O', 'O', 'O', 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'O', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'X', 'X' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'X', 'X', 'O' }
		},
		{
			{ 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ '<', '+', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'O', 'O' },
			{ 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'O', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '?', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' },
			{ 'O', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'O', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'O', 'O' },
			{ 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'O', 'O' },
			{ 'O', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'O', 'O' },
			{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O' }
		}
	};
	this->VEC_Explored_Rooms = { true, false, false, false, false, false, false };
	this->MAP_New_Room_Text =
	{
		{ 1, { "..." } },
		{ 2, { "...", "You feel a strong presence in this section", "The next area looks to be locked behind a door", "Perhaps try searching for the key", "Yourself > Theres more locked doors here too!? "} },
		{ 3, { "...", "Yourself > Compared to the last area, this place 'looks' more peaceful", "Yourself > Maybe without the monsters"} },
		{ 4, { "...", "You feel a strong presence in this section", "The next area looks to be locked behind a door", "Perhaps try searching for the key", "Yourself > Can I catch a break?" } },
		{ 5, { "...", "You feel two strong presences in this section", "The next area looks to be locked behind two doors", "Yourself > This is a joke", "Yourself > Sometimes I wished I never unfronze..." } },
		{ 6, { "...", "A tunnel leads downwards and splits off two ways with one exit", "Yourself > Is it even worth fighting anymore..." } },
		{ 7, { "...", "This seems to be the last room of the dungeon", "The room is full of soldiers and a formidable opponent", "Make sure you're ready for whats up ahead" } },
	};
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
	}
	if (this->INT_Dungeon_Room >= 5)
	{
		for (int i = 0; i < 2; i++) VEC_Chest_Loot.push_back(new ItemSkill("Waterproof Flamethrower", "How this combination works is beyond comprehension", 4, Skill("Flamadia")));
	}
	Item* ITEM_New_Item = VEC_Chest_Loot[rand() % (VEC_Chest_Loot.size())];
	return ITEM_New_Item;
}