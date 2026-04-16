#include "Dungeon.h"

Dungeon::Dungeon() {}

Dungeon::Dungeon(Player& PLAYER_Player)
{
	this->INT_Pos_X = 0;
	this->INT_Pos_Y = 0;
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

void Dungeon::fillWithChests() { }

void Dungeon::fillWithEnemies() { }

void Dungeon::elementSetter(Enemy& ENEMY_Enemy) { }

Enemy Dungeon::newEnemy()
{
	return Enemy("", 1, 1, 1, { }, new Item("", "", 1), false, 0);
}

Item* Dungeon::getItemFromLootTable(string STR_Enemy_Name)
{
	return new Item("", "", 1);
}

Item* Dungeon::getItemFromChest()
{
	return new Item("", "", 1);
}