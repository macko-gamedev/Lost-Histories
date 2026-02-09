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
	bool isEvent();
	void increaseDialogueIndex();
	void startOfDialogue();
	void endOfDialogue();
};

