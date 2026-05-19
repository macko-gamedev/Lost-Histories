#pragma once
#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

class Story
{
private:
	int INDEX_Dialogue;
	string STR_Player_Name;
	bool BOOL_Event;
	vector<string> VEC_Dialogue;
	Player PLAYER_Reference;
public:
	Story();
	string getDialogue();
	int getDialogueIndex();
	void setDialogueIndex(int N_Index);
	bool isEvent();
	void increaseDialogueIndex();
	void startOfDialogue();
	void endOfDialogue();
	void setPlayerReference(Player N_Player);
};

