#pragma once
#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

class Dungeon
{
protected:
	//char dungeon_map[21][21];
	vector<vector<char>> dungeon_map;
	string dungeon_name;
	int dungeon_room;
	int pos_x;
	int pos_y;
public:
	Dungeon();
	Dungeon(Player& player);
	vector<vector<char>> getDungeonMap();
	string getDungeonName();
	char getPosition(int x, int y);
	int getDungeonRoom();
	int getPosX();
	int getPosY();
	void setPosition(int x, int y, char icon);
	void setPosX(int x);
	void setPosY(int y);
	void changePosX(int amount);
	void changePosY(int amount);
};

