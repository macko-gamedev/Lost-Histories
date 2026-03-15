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
		{ "END DIALOGUE" },
		{ "..." },
		{ "Russian Sergeant > How... did... you... beat me?" },
		{ "Russian Sergeant > I have let HIM down" },
		{ "Russian Sergeant > You will never find the artifact in Atlantis" },
		{ (player_name + " > Artifact? What do you mean?") },
		{ "Russian Sergeant > I shall not go against my master" },
		{ "Russian Sergeant > You will never know from me..." },
		{ (player_name + " > And who's, HIM?") },
		{ "Russian Sergeant > You shall meet him soon..." },
		{ "Russian Sergeant > You are worthy, I will give you that" },
		{ "Russian Sergeant > I will let you pass, but this is no joke" },
		{ "Russian Sergeant > Whatever your intention is, it will not be easy" },
		{ "Russian Sergeant > The ice caps melted, and Atlantis has revealed itself before our eyes" },
		{ "Russian Sergeant > Break through this barricade to proceed, only if you dare" },
		{ "Yourself > Is this guy crazy?" },
		{ "Yourself > Maybe I should proceed to figure out whats going on..." },
		{ "You stare at the barricade eagerly" },
		{ "The barricade snaps after you kick it multiple times" },
		{ "What lies ahead?" },
		{ "END DIALOGUE" },
		{ "Yourself > Well this looks depressing" },
		{ "Ruins of what looked like a fine underwater city lies ahead" },
		{ "You can hear faint shouting from within" },
		{ "Yourself > I may encounter a problem along the way" },
		{ "Yourself > By the sounds of it, the next room..." },
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

void Story::setDialogueIndex(int index)
{
	this->dialogueIndex = index;
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
