#include "DungeonAtlantis.h"

// X = Wall, ! = Enemy, > = Next Room, <  = Last Room, + = Player

//DungeonAtlantis::DungeonAtlantis() { }

DungeonAtlantis::DungeonAtlantis()
{
	this->dungeon_name = "Atlantis Ruins";
	this->dungeon_room = 1;
	this->pos_x = 3;
	this->pos_y = 7;
	this->dungeon_map =
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
			{ 'O', 'O', ' ', 'X', 'X', 'X', 'X', 'X', 'O', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', ' ', ' ', 'X', 'O' },
			{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X', 'O' }
		}
	};
}

void DungeonAtlantis::fillWithEnemies()
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
					int spawnChance = (rand() % 100) + 1;
					if (spawnChance > 84)
					{
						this->setPosition(r, i, j, '!');
					}
				}
			}
		}
	}
}

void DungeonAtlantis::fillWithChests()
{
	// 5% chance for each tile to have a chest
	for (int r = 0; r < 1; r++)
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (this->getDungeonMap()[r][i][j] == ' ')
				{
					int spawnChance = (rand() % 100) + 1;
					if (spawnChance > 94)
					{
						this->setPosition(r, i, j, '*');
					}
				}
			}
		}
	}
}