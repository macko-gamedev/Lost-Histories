#include "Story.h"

Story::Story(string N_Player_Name)
{
	this->STR_Player_Name = N_Player_Name;
	this->VEC_Dialogue =
	{
		{ "THIS IS PLACE HOLDER TEXT TO NOT ZERO INDEX" },
		{ "??? > January 1st, 2067..." },
		{ "??? > The planet's heat has peaked, and thus devasting disasters are about to happen..." },
		{ "??? > What's that?" },
		{ "??? > The ice is melting." },
		{ "??? > You're alive?" },
		{ (STR_Player_Name + " has awoken from deep slumber, after being captive in a block of ice for 41 years") },
		{ "??? > Why hello brave adventurer!" },
		{ "??? > You can see we have problem here don't ya?" },
		{ "??? > You shouldn't be here." },
		{ "??? > ...." },
		{ "??? > Enough chitter chatter, looks like someone, or something is approaching." },
		{ "??? A moving block of ice? No. An ice monster?" },
		{ "You look around quickly for any sort of weapon." },
		{ "+ Received Melee: Sharp Stick" },
		{ ("??? > Here it comes " + STR_Player_Name + "!") },
		{ "END DIALOGUE" },
		{ "..." },
		{ "Yourself > How am I alive?" },
		{ "Yourself > And what was that thing?" },
		{ "Yourself > That... thing... dropped something" },
		{ "Yourself > Maybe this ice block thingy can come in handy" },
		{ "[You can now use elemental skills]" },
		{ "Yourself > I should probably explore for now" },
		{ "Yourself > It's cold..." },
		{ "END DIALOGUE" },
		{ "..." },
		{ "Russian Sergeant > How... did... you... beat me?" },
		{ "Russian Sergeant > I have let HIM down" },
		{ "Russian Sergeant > You will never find the artifact in Atlantis" },
		{ (STR_Player_Name + " > Artifact? What do you mean?") },
		{ "Russian Sergeant > I shall not go against my master" },
		{ "Russian Sergeant > You will never know from me..." },
		{ (STR_Player_Name + " > And who's, HIM?") },
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
		{ "END DIALOGUE" },
		{ "..." },
		{ "need to code" },
		{ "END DIALOGUE" },
		{ "The entrance breeze is a painful cold" },
		{ "Yourself > This facility, how is it still operational?" },
		{ "Yourself > Perhaps this machine part could some in handy somewhere" },
		{ "Yourself > I should look around" },
		{ "END DIALOGUE" }
	};
	this->INDEX_Dialogue = 1;
	this->BOOL_Event = false;
}

string Story::getDialogue()
{
	return this->VEC_Dialogue[this->INDEX_Dialogue];
}

int Story::getDialogueIndex()
{
	return this->INDEX_Dialogue;
}

void Story::setDialogueIndex(int N_Index)
{
	this->INDEX_Dialogue = N_Index;
}

bool Story::isEvent()
{
	return this->BOOL_Event;
}

void Story::increaseDialogueIndex()
{
	this->INDEX_Dialogue++;
}

void Story::startOfDialogue()
{
	this->BOOL_Event = false;
}

void Story::endOfDialogue()
{
	this->BOOL_Event = true;
}
