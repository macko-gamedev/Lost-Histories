#include "Dungeon.h"

Dungeon::Dungeon() {}

Dungeon::Dungeon(string N_Name)
{
	this->INT_Pos_X = 0;
	this->INT_Pos_Y = 0;
	this->STR_Player_Name = N_Name;
}

vector<vector<vector<char>>> Dungeon::getDungeonMap()
{
	return this->VEC_Dungeon_Map;
}

string Dungeon::getDungeonName()
{
	return this->STR_Dungeon_Name;
}

char Dungeon::getPosition(int INT_Get_Room, int INT_Get_X, int INT_Get_Y)
{
	return this->VEC_Dungeon_Map[INT_Get_Room][INT_Get_X][INT_Get_Y];
}

int Dungeon::getDungeonRoom()
{
	return this->INT_Dungeon_Room;
}

int Dungeon::getPosX()
{
	return this->INT_Pos_X;
}

int Dungeon::getPosY()
{
	return this->INT_Pos_Y;
}

vector<string> Dungeon::getNewRoomDialogue()
{
	return this->MAP_New_Room_Text.find(this->INT_Dungeon_Room)->second;
}

bool Dungeon::isExploredRoom()
{
	return this->VEC_Explored_Rooms[(this->INT_Dungeon_Room - 1)];
}

void Dungeon::exploredRoom()
{
	this->VEC_Explored_Rooms[(this->INT_Dungeon_Room - 1)] = true;
}

void Dungeon::changeDungeonRoom(int INT_Amount)
{
	this->INT_Dungeon_Room += INT_Amount;
}

void Dungeon::setPosition(int INT_Set_Room, int INT_Set_X, int INT_Set_Y, char CHAR_Set_Icon)
{
	this->VEC_Dungeon_Map[INT_Set_Room][INT_Set_X][INT_Set_Y] = CHAR_Set_Icon;
}

void Dungeon::setPosX(int x)
{
	this->INT_Pos_X = x;
}

void Dungeon::setPosY(int y)
{
	this->INT_Pos_Y = y;
}

void Dungeon::changePosX(int INT_Amount)
{
	this->INT_Pos_X += INT_Amount;
}

void Dungeon::changePosY(int INT_Amount)
{
	this->INT_Pos_Y += INT_Amount;
}

void Dungeon::fillWithEnemies()
{
	// 15% chance for each tile to have an enemy
	for (int r = 0; r < this->VEC_Dungeon_Map.size(); r++)
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

void Dungeon::fillWithChests()
{
	// 8% chance for each tile to have a chest
	for (int r = 0; r < this->VEC_Dungeon_Map.size(); r++)
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

Enemy Dungeon::newEnemy()
{
	return Enemy("", 1, 1, 1, { }, false, 0);
}

Item* Dungeon::getItemFromChest()
{
	return new Item("", "", 1);
}

vector<string> Dungeon::getEncounterDialogue()
{
	return MAP_Encounter_Dialogue.find(this->getDungeonRoom())->second;
}

Enemy Dungeon::getEncounterEnemy()
{
	return MAP_Encounter_Enemy.find(this->getDungeonRoom())->second;
}