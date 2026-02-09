#include "Dungeon.h"

Dungeon::Dungeon() {}

Dungeon::Dungeon(Player& player)
{
	this->pos_x = 0;
	this->pos_y = 0;
}

vector<vector<char>> Dungeon::getDungeonMap()
{
	return this->dungeon_map;
}

string Dungeon::getDungeonName()
{
	return this->dungeon_name;
}

int Dungeon::getDungeonRoom()
{
	return this->dungeon_room;
}

int Dungeon::getPosX()
{
	return this->pos_x;
}

int Dungeon::getPosY()
{
	return this->pos_y;
}

void Dungeon::changePosX(int amount)
{
	this->pos_x += amount;
}

void Dungeon::changePosY(int amount)
{
	this->pos_y += amount;
}