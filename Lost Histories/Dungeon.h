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
	vector<bool> VEC_Explored_Rooms;
	map<int, vector<string>> MAP_New_Room_Text;
	map<int, vector<string>> MAP_Encounter_Dialogue;
	map<int, Enemy> MAP_Encounter_Enemy;
	string STR_Dungeon_Name;
	string STR_Player_Name;
	int INT_Dungeon_Room;
	int INT_Pos_X;
	int INT_Pos_Y;
public:
	Dungeon();
	Dungeon(string N_Name);
	vector<vector<vector<char>>> getDungeonMap();
	string getDungeonName();
	vector<string> getNewRoomDialogue();
	char getPosition(int INT_Get_Room, int INT_Get_X, int INT_Get_Y);
	int getDungeonRoom();
	int getPosX();
	int getPosY();
	bool isExploredRoom();
	void changeDungeonRoom(int INT_Amount);
	void setPosition(int INT_Set_Room, int INT_Set_X, int INT_Set_Y, char CHAR_Set_Icon);
	void setPosX(int x);
	void setPosY(int y);
	void changePosX(int INT_Amount);
	void changePosY(int INT_Amount);
	void exploredRoom();
	void fillWithEnemies();
	void fillWithChests();

	// Virtual: Returns a new Enemy object
	virtual Enemy newEnemy();

	// Virtual: Returns a new Item object
	virtual Item* getItemFromChest();

	// Returns a vector of current encounter dialogue
	vector<string> getEncounterDialogue();

	// Returns a new Enemy object from current encounter 
	Enemy getEncounterEnemy();
};

