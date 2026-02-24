#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Dungeon
{
protected:
	vector<vector<vector<char>>> dungeon_map;
	string dungeon_name;
	int dungeon_room;
	int pos_x;
	int pos_y;
public:
	Dungeon();
	Dungeon(Player& player);
	vector<vector<vector<char>>> getDungeonMap();
	string getDungeonName();
	char getPosition(int room, int x, int y);
	int getDungeonRoom();
	int getPosX();
	int getPosY();
	void changeDungeonRoom(int value);
	void setPosition(int room, int x, int y, char icon);
	void setPosX(int x);
	void setPosY(int y);
	void changePosX(int amount);
	void changePosY(int amount);
	void virtual fillWithEnemies();
	Enemy newEnemy(Dungeon* curr_dungeon);
};

