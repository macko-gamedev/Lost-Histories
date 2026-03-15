#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Story
{
private:
	vector<string> dialogue;
	string player_name;
	int dialogueIndex;
	bool event;
public:
	Story();
	Story(string player);
	string getDialogue();
	int getDialogueIndex();
	void setDialogueIndex(int index);
	bool isEvent();
	void increaseDialogueIndex();
	void startOfDialogue();
	void endOfDialogue();
};

