#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Dungeon
{
protected:
	vector<vector<vector<char>>> VEC_Dungeon_Map;
	string STR_Dungeon_Name;
	int INT_Dungeon_Room;
	int INT_Pos_X;
	int INT_Pos_Y;
public:
	Dungeon();
	Dungeon(Player& PLAYER_Player);
	vector<vector<vector<char>>> getDungeonMap();
	string getDungeonName();
	char getPosition(int INT_Get_Room, int INT_Get_X, int INT_Get_Y);
	int getDungeonRoom();
	int getPosX();
	int getPosY();
	void changeDungeonRoom(int INT_Amount);
	void setPosition(int INT_Set_Room, int INT_Set_X, int INT_Set_Y, char CHAR_Set_Icon);
	void setPosX(int x);
	void setPosY(int y);
	void changePosX(int INT_Amount);
	void changePosY(int INT_Amount);
	void elementSetter(Enemy& ENEMY_Enemy);
	void virtual fillWithEnemies();
	void virtual fillWithChests();
	Enemy newEnemy(Dungeon* DUNGEON_Current_Dungeon);
	virtual Item* getItemFromLootTable(string STR_Enemy_Name);
};

