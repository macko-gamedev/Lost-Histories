#include "Story.h"

Story::Story(string N_Player_Name)
{
	this->STR_Player_Name = N_Player_Name;
	this->VEC_Dialogue =
	{
		{ "THIS IS PLACE HOLDER TEXT TO NOT ZERO INDEX" },
		{ "\n   ??? > January 1st, 2067..." },
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
		{ "A moving block of ice? No. An ice monster?" },
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
		{ "..." },
		{ "Yourself > Well this looks depressing" },
		{ "Ruins of what looked like a fine underwater city lies ahead" },
		{ "You can hear faint shouting from within" },
		{ "Yourself > I may encounter a problem along the way" },
		{ "Yourself > By the sounds of it, the next room..." },
		{ "END DIALOGUE" },
		{ "..." },
		{ "Reawoken Guardian of Atlantis > Just as we thought things were finally going well for us..." },
		{ "Reawoken Guardian of Atlantis > You come along and ruin everything!" },
		{ STR_Player_Name + " > Well I'm on a mission to save the world, and you was stood in my way I guess..." },
		{ STR_Player_Name + " > Tell me what you know and I may spare you" },
		{ "Reawoken Guardian of Atlantis > *gasps*" },
		{ "Reawoken Guardian of Atlantis > There is a device in a research facility not far from here" },
		{ "Reawoken Guardian of Atlantis > It's sole purpose is to shoot out a large ice beam into the atmosphere" },
		{ "Reawoken Guardian of Atlantis > But since everything has now melted and exposed itself, like this place" },
		{ "Reawoken Guardian of Atlantis > Countries from around the world are trying to exploit anything they find" },
		{ "Reawoken Guardian of Atlantis > They don't want to refreeze the planet until they have looted everything there is to find" },
		{ STR_Player_Name + " > You dropped this weird part on the floor" },
		{ STR_Player_Name + " > Can you tell me more about it?" },
		{ "Reawoken Guardian of Atlantis > This is a part to that device" },
		{ "Reawoken Guardian of Atlantis > Once you place it into the machine, it will activate and give the machine power" },
		{ "Reawoken Guardian of Atlantis > However, word goes around that the core component has gone missing" },
		{ "Reawoken Guardian of Atlantis > I personally don't want the planet to refreeze, we are now living and thriving like we haven't before!" },
		{ "Reawoken Guardian of Atlantis > But I do understand that we are constantly under pressure from other countries and civilisations" },
		{ "Reawoken Guardian of Atlantis > We are under 24/7 watch and it hurts our spirit" },
		{ "Reawoken Guardian of Atlantis > Go to that research facility, you may be able to do something" },
		{ "Reawoken Guardian of Atlantis > It is EAST from here, but you may run into more trouble" },
		{ STR_Player_Name + " > Thank you so much, and I am sorry for what I have done to you" },
		{ "Reawoken Guardian of Atlantis > It's okay, you've spared me after all I should say thanks" },
		{ "You begin to travel east in search of this research facility" },
		{ "After hours of travel, you finally reach your destination" },
		{ "You slowly open the rusted door and walk inside" },
		{ "END DIALOGUE" },
		{ "The entrance breeze is a painful cold" },
		{ "Yourself > This facility, how is it still operational?" },
		{ "Yourself > Perhaps this machine part could some in handy somewhere" },
		{ "Yourself > I should look around" },
		{ "END DIALOGUE" },
		{ "..." },
		{ "Master of the Facility > You bastard..." },
		{ "Master of the Facility > How DARE you oppose me, and manage to strike me down" },
		{ "Master of the Facility > Give that part back now!" },
		{ STR_Player_Name + " > Nuh uh, you tried to kill me! This seems important, and since that machine is 'behind you', I am keeping it!" },
		{ "Master of the Facility > I was lying to you, like I would tell you where The Device was" },
		{ "Master of the Facility > I'll give you a hint, you need to find The Mastermind, he holds the key to finding The Device" },
		{ "Master of the Facility > I don't think you have what it takes kid to beat him *cough*" },
		{ "Master of the Facility > From what I know, he is currently situated near a volcano, the trek won't be easy however" },
		{ "Master of the Facility > So I suggest you give me my little part back before you regret it..." },
		{ STR_Player_Name + " > No can do, I need this to save the world" },
		{ "Master of the Facility > Well, would you still say that after I show you this..." },
		{ "A shadow of a figure appears in the hallway infront of you" },
		{ "A tall, lanky figure" },
		{ "It looks familiar" },
		{ STR_Player_Name + " > George Shaw!?" },
		{ "??? > *robotic noises*" },
		{ "Master of the Facility > Behold!" },
		{ "Master of the Facility > I heard this is your dearest friend, unfortunately he did pass away in 2038" },
		{ "Master of the Facility > For my great research, I have implanted his memories inside a computer" },
		{ "Master of the Facility > I then built a robotic figure, resembling your friend, and implanted his memories into it" },
		{ "Master of the Facility > Ofcourse, I had no idea he was your friend" },
		{ "Master of the Facility > But word of mouth said you was coming, so I did a bit of background research on you" },
		{ "Master of the Facility > You should be dead." },
		{ "Master of the Facility > Somehow, your body was trapped in an ice block for 41 years, and your mind is still in tact" },
		{ "Master of the Facility > How truly fascinating..." },
		{ "??? > " + STR_Player_Name + "..." },
		{ STR_Player_Name + " > George..." },
		{ "Master of the Facility > Aren't I a monster?" },
		{ "Master of the Facility > I control him... and if you want to find that machine, you must go through HIM first" },
		{ STR_Player_Name + " > You, in a way, revived my dead friend to make me fight him?? You're sick!" },
		{ "??? > *charges towards " + STR_Player_Name + "*" },
		{ "END DIALOGUE" },
		{ "..." },
		{ "Yourself > That was a close one." },
		{ "Yourself > I can't believe I just did that..." },
		{ "Yourself > Kill my friend. I mean, it wasn't actually him, but..." },
		{ "Yourself > I need to find this damn machine" },
		{ "END DIALOGUE" },
		{ "..." },
		{ "The Mastermind > I'll give ya that, you do put up a hella a fight" },
		{ "The Mastermind > But say little kiddo, I think you should-" },
		{ "The Mastermind > GIVE" },
		{ "The Mastermind > THAT" },
		{ "The Mastermind > BACK" },
		{ "You can feel overwhelming power from the guy" },
		{ "You start trembling" },
		{ "The Mastermind > Hey, what's wrong?" },
		{ "The Mastermind > You thought I'd be all weak now didn't you?" },
		{ "The Mastermind > So, tell me, what are your intentions?" },
		{ STR_Player_Name + " > I-" },
		{ STR_Player_Name + " > don't know..." },
		{ STR_Player_Name + " > I was trapped, from the information I've gathered, for 41 years" },
		{ STR_Player_Name + " > I don't know how I'm here" },
		{ STR_Player_Name + " > But, I know, my mission..." },
		{ STR_Player_Name + " > ...is to save the world..." },
		{ "The Mastermind > Don't make me laugh!" },
		{ "The Mastermind > Why would you want to refreeze the planet?" },
		{ "The Mastermind > Don't you like your new power?" },
		{ "The Mastermind > Is life not exciting enough for you!?" },
		{ "The Mastermind > Sorry, but first, we need to exploit what's uncovered" },
		{ "The Mastermind > I mean, look around you outside, ancient artefacts scattered everywhere" },
		{ "The Mastermind > They're worth a bloody fortune!" },
		{ STR_Player_Name + " > You shouldn't exploit the planet of it's resources" },
		{ "The Mastermind > Oh not this nonsense" },
		{ "The Mastermind > Last time some idiot said that to me, they were as good as dead within 10 seconds flat" },
		{ "The Mastermind > You piss me off..." },
		{ STR_Player_Name + " > Sorry, but I'm keeping this little tool, and I am putting a stop to your scheme" },
		{ "The Mastermind > ARGH..." },
		{ "You can feel the ground shaking" },
		{ "The man starts to freak out in a fit of rage" },
		{ "His body begins to morph" },
		{ "His eyes glow a vicious red" },
		{ "The Mastermind > *sprints towards " + STR_Player_Name + "*" },
		{ STR_Player_Name + " > What the fu-" },
		{ "END DIALOGUE" },
		{ "..." },
		{ "You just barely managed to defeat the man" },
		{ "You're exhausted, but so close to the end" },
		{ "The compass is glowing blue whilst the pointer is in the north direction" },
		{ "You travel north, in hopes to find The Device, and finally restore the balance of the planet" },
		{ "7 hours of painful walking, and you reach " },
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
