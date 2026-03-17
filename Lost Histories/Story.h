#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Story
{
private:
	vector<string> VEC_Dialogue;
	string STR_Player_Name;
	int INDEX_Dialogue;
	bool BOOL_Event;
public:
	Story();
	Story(string N_Player_Name);
	string getDialogue();
	int getDialogueIndex();
	void setDialogueIndex(int N_Index);
	bool isEvent();
	void increaseDialogueIndex();
	void startOfDialogue();
	void endOfDialogue();
};

