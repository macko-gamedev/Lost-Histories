#include "Story.h"

Story::Story(string player)
{
	this->player_name = player;
	this->dialogue =
	{
		{ "THIS IS PLACE HOLDER TEXT TO NOT ZERO INDEX" },
		{ "??? > January 1st, 2067..." },
		{ "??? > The planet's heat has peaked, and thus devasting disasters are about to happen..." },
		{ "??? > What's that?" },
		{ "??? > The ice is melting." },
		{ "??? > You're alive?" },
		{ (player_name + " has awoken from deep slumber, after being captive in a block of ice for 41 years") },
		{ "??? > Why hello brave adventurer!" },
		{ "??? > You can see we have problem here don't ya?" },
		{ "??? > You shouldn't be here." },
		{ "??? > ...." },
		{ "??? > Enough chitter chatter, looks like someone, or something is approaching." },
		{ "??? A moving block of ice? No. An ice monster?" },
		{ "You look around quickly for any sort of weapon." },
		{ "+ Received Melee: Sharp Stick" },
		{ ("??? > Here it comes " + player_name + "!") },
		{ "END DIALOGUE" },
		{ "..." },
		{ "How am I alive?" },
		{ "And what was that thing?" },
		{ "That... thing... dropped something" },
		{ "Maybe this ice block thingy can come in handy" },
		{ "[You can now use elemental skills]" },
		{ "I should probably explore for now" },
		{ "It's cold..." },
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

void Story::startOfDialogue()
{
	this->event = false;
}

void Story::endOfDialogue()
{
	this->event = true;
}
