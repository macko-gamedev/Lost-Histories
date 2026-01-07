#include "Story.h"

Story::Story(string player)
{
	this->player_name = player;
	this->dialogue =
	{
		{ "THIS IS PLACE HOLDER TEXT TO NOT ZERO INDEX" },
		{ "> January 1st, 2067..." },
		{ "> The planet's heat has peaked, and thus devasting disasters are about to happen..." },
		{ "> What's that?" },
		{ "> The ice is melting." },
		{ "> You're alive?" },
		{ (player_name + " has awoken from deep slumber, after being captive in a block of ice for 41 years") },
		{ "> Why hello brave adventurer!" },
		{ "> You can see we have problem here don't ya?" },
		{ "> You shouldn't be here." },
		{ "> Maybe take a look around and see what you can do." },
		{ "END DIALOGUE" }
	};
	this->dialogueIndex = 1;
	this->event = false;
}

string Story::getDialogue()
{
	return this->dialogue[this->dialogueIndex];
}

int Story::getDialogueIndex()
{
	return this->dialogueIndex;
}

bool Story::isEvent()
{
	return this->event;
}

void Story::increaseDialogueIndex()
{
	this->dialogueIndex++;
}
