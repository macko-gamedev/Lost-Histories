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
	int pos_x;
	int pos_y;
public:
	Dungeon();
	Dungeon(Player& player);
	vector<vector<char>> getDungeonMap();
	int getPosX();
	int getPosY();
	void changePosX(int amount);
	void changePosY(int amount);
};

