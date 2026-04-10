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
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X', 'X', 'X', 'X' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', ' ', ' ', 'X', ' ', ' ', 'X' },
			{ 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', ' ', ' ', 'X' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O', 'O' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'O' },
			{ 'O', ' ', ' ', '+', ' ', ' ', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
			{ 'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X' },
			{ 'O', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', '>' },
			{ 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'X', ' ', ' ', 'X', 'X', 'X' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', ' ', ' ', 'X', 'O', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X', 'O', 'O' }
		}
	};
}

void DungeonFacility::fillWithEnemies()
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

void DungeonFacility::fillWithChests()
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