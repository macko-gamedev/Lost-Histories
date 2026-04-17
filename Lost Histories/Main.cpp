#include "Player.h"
#include "Enemy.h"
#include "Skill.h"
#include "Story.h"
#include "Item.h"
#include "ItemSkill.h"
#include "ItemMelee.h"
#include "DungeonGlacier.h"
#include "DungeonAtlantis.h"
#include "DungeonFacility.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <Windows.h>
#include "mmsystem.h"
#include <conio.h>
#include <map>
#include "include/color.hpp"

#pragma comment(lib, "winmm.lib")

using namespace std;

/* 

###### LOST HISTORIES ######
Last Updated: 17/03/26 (14:30)

--- Parent Classes ---
. BattleStat	 # Contains key variables to battles such as health and stamina values
				 : Player, Enemy
. Item			 # Contains name, description and rarity of an item
                 : ItemMelee, ItemSkill, ItemConsumable
. Dungeon        # Contains name, floor number
				 : DungeonGlacier, DungeonAtlantis

--- Child Classes ---
. Enemy		      : Inherits BattleStat
. DungeonAtlantis : Inherits Dungeon, dungeon 2 of the game
. DungeonGlacier  : Inherits Dungeon, dungeon 1 of the game
. ItemConsumable  : Inherits Item, an item which can be used in battle
. ItemMelee       : Inherits Item, an item which can be equipped as a Melee
. ItemSkill       : Inherits Item, an item which contains a skill the PLAYER_Player can inherit
. Player          : Inherits BattleStat, contains all things the PLAYER_Player can do and their stats

--- Classes ---
. Skill			 : Contains name, description, type, damage/healing value and stamina cost of a skill
. Story			 : Contains a vector which has all STORY_Story dialogue and functions which alter the pathing

############################

 */

// Enumerator for story status, what act the player is in
enum storyStatus
{
	INTRO,
	ACT_ONE,
	ACT_TWO,
	ACT_THREE,
};

// Enumerator for game status, what game state is the player in
enum gameStatus
{
	DIALOGUE,
	DUNGEON,
	BATTLE
};

string convert_string_tolower(string text); // Quite obvious 1
string convert_string_toupper(string text); // Quite obvious 2
void set_starting_elements(int& weak_element, int& resist_element); // Sets the starting elements (weakness and resistant)
void show_enemy_stats(Enemy ENEMY_Enemy); // Shows the ENEMY_Enemy's battle stats
void show_battle_stats(Player PLAYER_Player); // Shows the PLAYER_Player's battle stats (name, hp, sta)
void show_skill(Player PLAYER_Player, int INDEX_Skill); // Shows the PLAYER_Player's current skill
void dialogue_input(Player& PLAYER_Player, string STR_Dialogue_Choice, vector<Dungeon*> VEC_Visited_Dungeons, Dungeon*& DUNGEON_Current_Dungeon); // Story PLAYER_Player input
int main_menu(); // Main menu when the game is executed
void battle(Player& PLAYER_Player, Dungeon* DUNGEON_Current_Dungeon, Enemy ENEMY_Enemy); // Battle sequence
void map_movement(string STR_Dialogue_Choice, Player& PLAYER_Player, Enemy& ENEMY_New_Enemy, Dungeon* DUNGEON_Current_Dungeon, storyStatus& ENUM_Story_Status, gameStatus& ENUM_Game_Status, Story& STORY_Story); // Map Movement
void open_chest(Player& PLAYER_Player, Dungeon* DUNGEON_Current_Dungeon); // Open chests
void output_dungeon(Dungeon* DUNGEON_Current_Dungeon, Story STORY_Story); // Outputs current dungeon
void play_audio(string to_play); // Plays music


/* ---------------------------------------------------------------------------------------------------- */

// MAIN PROGRAM
int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	main_menu();
	// Setup
	string STR_Player_Name;
	string STR_Dialogue_Choice;
	storyStatus ENUM_Story_Status = storyStatus::INTRO;
	gameStatus ENUM_Game_Status = gameStatus::DIALOGUE;
	Dungeon* DUNGEON_Current_Dungeon = NULL;
	vector<Dungeon*> VEC_Visited_Dungeons = { };
	Enemy ENEMY_New_Enemy;
	int weak_element = -1;
	int resist_element = -1;
	cout << "\n   Your Character Name: "; 
	getline(cin, STR_Player_Name);
	set_starting_elements(weak_element, resist_element); // Player chooeses their starting elements
	Player PLAYER_Player = Player(STR_Player_Name, weak_element, resist_element, 1, 140, 62); // Instantiates object of type Player
	Story STORY_Story = Story(STR_Player_Name); // Instantiates object of type Story
	string STR_Intro_Choice = "";
	while (STR_Intro_Choice != "y" && STR_Intro_Choice != "n")
	{
		system("CLS");
		cout << "\n   You are playing Prototype 2\n   . This build includes Dungeon 1, Dungeon 2 and up to Floor 3 of Dungeon 3\n   . Try and break the game if you feel like it\n\n   This game through self playtest may be challenging, would you like to add a insta-kill skill in battle? [y]/[n]\n   > ";
		getline(cin, STR_Intro_Choice);
		if (STR_Intro_Choice == "y")
		{
			PLAYER_Player.addItem(new ItemSkill("Get Out Of Jail Free Card", "Incase you need it", 5, Skill("Death"))); break;
		}
		if (STR_Intro_Choice == "n") break;
	}
	cout << "\n\n   ! For dialogue scenes, press any key to advance\n   ! Whilst dungeon exploring, press SPACE to make an input\n\n   Have Fun!\n\n\n   ";
	system("pause");
	system("CLS");
	while (true)
	{
		// INTRO DIALOGUE/TUTORIAL BATTLE
		while (ENUM_Story_Status == storyStatus::INTRO)
		{
			clock_t start = clock();

			cout << "   " << STORY_Story.getDialogue() << endl << endl;
			STORY_Story.increaseDialogueIndex();
			if (STORY_Story.getDialogue() == "END DIALOGUE")
			{
				STORY_Story.endOfDialogue();
			}
			_getch();
			clock_t end = clock();
			int ms_duration = end - start;
			int ms_remaining = 33 - ms_duration;
			this_thread::sleep_for(chrono::milliseconds(ms_remaining));

			if (STORY_Story.isEvent())
			{
				// DUNGEON 1: GLACIER WASTELAND
				ENUM_Game_Status = gameStatus::BATTLE;
				DUNGEON_Current_Dungeon = new DungeonGlacier();
				DUNGEON_Current_Dungeon->fillWithEnemies();
				DUNGEON_Current_Dungeon->fillWithChests();
				ENEMY_New_Enemy = Enemy("Ice Monster", 1, 10, 24, { Skill("Freeze") }, new ItemSkill("Ice Core", "A strange looking block of ice", 1, Skill("Freeze")), false, 12);
				play_audio("Dungeon Battle");
				battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);
				STORY_Story.startOfDialogue();
				STORY_Story.increaseDialogueIndex();
				ENUM_Story_Status = storyStatus::ACT_ONE;
				ENUM_Game_Status = gameStatus::DUNGEON;
				break;
			}
		}

		while (ENUM_Story_Status == storyStatus::ACT_TWO && ENUM_Game_Status == gameStatus::DIALOGUE)
		{
			clock_t start = clock();

			cout << "\n   " << STORY_Story.getDialogue() << endl;
			STORY_Story.increaseDialogueIndex();
			if (STORY_Story.getDialogue() == "END DIALOGUE")
			{
				STORY_Story.endOfDialogue();
			}
			_getch();
			clock_t end = clock();
			int ms_duration = end - start;
			int ms_remaining = 33 - ms_duration;
			this_thread::sleep_for(chrono::milliseconds(ms_remaining));

			if (STORY_Story.isEvent())
			{
				// DUNGEON 2: ATLANTIS RUINS
				DUNGEON_Current_Dungeon->fillWithEnemies();
				DUNGEON_Current_Dungeon->fillWithChests();
				VEC_Visited_Dungeons.push_back(DUNGEON_Current_Dungeon);
				DUNGEON_Current_Dungeon = new DungeonAtlantis();
				DUNGEON_Current_Dungeon->fillWithEnemies();
				DUNGEON_Current_Dungeon->fillWithChests();
				VEC_Visited_Dungeons.push_back(DUNGEON_Current_Dungeon);
				STORY_Story.startOfDialogue();
				STORY_Story.increaseDialogueIndex();
				ENUM_Game_Status = gameStatus::DUNGEON;
				break;
			}
		}
		play_audio(DUNGEON_Current_Dungeon->getDungeonName() + " F" + to_string(DUNGEON_Current_Dungeon->getDungeonRoom()));

		while (ENUM_Story_Status == storyStatus::ACT_THREE && ENUM_Game_Status == gameStatus::DIALOGUE)
		{
			clock_t start = clock();

			cout << "\n   " << STORY_Story.getDialogue() << endl;
			STORY_Story.increaseDialogueIndex();
			if (STORY_Story.getDialogue() == "END DIALOGUE")
			{
				STORY_Story.endOfDialogue();
			}
			_getch();
			clock_t end = clock();
			int ms_duration = end - start;
			int ms_remaining = 33 - ms_duration;
			this_thread::sleep_for(chrono::milliseconds(ms_remaining));

			if (STORY_Story.isEvent())
			{
				// DUNGEON 3: FACILITY
				DUNGEON_Current_Dungeon->fillWithEnemies();
				DUNGEON_Current_Dungeon->fillWithChests();
				VEC_Visited_Dungeons[1] = DUNGEON_Current_Dungeon;
				DUNGEON_Current_Dungeon = new DungeonFacility();
				DUNGEON_Current_Dungeon->fillWithEnemies();
				DUNGEON_Current_Dungeon->fillWithChests();
				VEC_Visited_Dungeons.push_back(DUNGEON_Current_Dungeon);
				STORY_Story.startOfDialogue();
				STORY_Story.increaseDialogueIndex();
				ENUM_Game_Status = gameStatus::DUNGEON;
				break;
			}
		}
		play_audio(DUNGEON_Current_Dungeon->getDungeonName() + " F" + to_string(DUNGEON_Current_Dungeon->getDungeonRoom()));

		while (ENUM_Game_Status == gameStatus::DUNGEON)
		{
			clock_t start = clock();
			output_dungeon(DUNGEON_Current_Dungeon, STORY_Story);
			if (!STORY_Story.isEvent())
			{
				cout << "   " << STORY_Story.getDialogue() << endl;
				STORY_Story.increaseDialogueIndex();
				if (STORY_Story.getDialogue() == "END DIALOGUE")
				{
					STORY_Story.endOfDialogue();
				}
				_getch();
			}
			else if (!DUNGEON_Current_Dungeon->isExploredRoom())
			{
				vector<string> VEC_New_Room_Dialogue = DUNGEON_Current_Dungeon->getNewRoomDialogue();
				for (string STR_Dialogue : VEC_New_Room_Dialogue)
				{
					cout << "   " << STR_Dialogue;
					_getch(); cout << "\33[2K\r" << flush;;
				}
				DUNGEON_Current_Dungeon->exploredRoom();
			}
			else
			{
				_getch();
				if (GetAsyncKeyState(VK_SPACE))
				{
					cout << "   > ";
					cin >> STR_Dialogue_Choice;
					STR_Dialogue_Choice = convert_string_tolower(STR_Dialogue_Choice);
					dialogue_input(PLAYER_Player, STR_Dialogue_Choice, VEC_Visited_Dungeons, DUNGEON_Current_Dungeon);
				}
				else if (GetAsyncKeyState(VK_RIGHT)) map_movement("d", PLAYER_Player, ENEMY_New_Enemy, DUNGEON_Current_Dungeon, ENUM_Story_Status, ENUM_Game_Status, STORY_Story);
				else if (GetAsyncKeyState(VK_LEFT)) map_movement("a", PLAYER_Player, ENEMY_New_Enemy, DUNGEON_Current_Dungeon, ENUM_Story_Status, ENUM_Game_Status, STORY_Story);
				else if (GetAsyncKeyState(VK_UP)) map_movement("w", PLAYER_Player, ENEMY_New_Enemy, DUNGEON_Current_Dungeon, ENUM_Story_Status, ENUM_Game_Status, STORY_Story);
				else if (GetAsyncKeyState(VK_DOWN)) map_movement("s", PLAYER_Player, ENEMY_New_Enemy, DUNGEON_Current_Dungeon, ENUM_Story_Status, ENUM_Game_Status, STORY_Story);
				//Sleep(100);
			}
			clock_t end = clock();
			int ms_duration = end - start;
			int ms_remaining = 200 - ms_duration;
			//this_thread::sleep_for(chrono::milliseconds(ms_remaining));
		}
	}
}

// Main Menu
int main_menu()
{
	play_audio("Menu");
	string STR_Menu_Choice;
	while (STR_Menu_Choice != "new game" && STR_Menu_Choice != "load game" && STR_Menu_Choice != "credits" && STR_Menu_Choice != "settings" && STR_Menu_Choice != "quit")
	{
		system("CLS");
		cout << "\n\n";
		cout << "   #        ###     ####   ##### " << endl;
		cout << "   #       #   #   #         #   " << endl;
		cout << "   #       #   #    ###      #   " << endl;
		cout << "   #       #   #       #     #   " << endl;
		cout << "   #####    ###    ####      #   " << endl;
		cout << "\n";
		cout << "         H I S T O R I E S       " << endl;
		cout << "            Prototype 2          " << endl;
		cout << "\n\n";
		cout << "--> New Game\n--> Load Game\n--> Settings\n--> Credits\n--> Quit\n\n> ";
		getline(cin, STR_Menu_Choice);
		STR_Menu_Choice = convert_string_tolower(STR_Menu_Choice);
	}
	system("CLS");
	if (STR_Menu_Choice == "new game")
	{
		return 0;
	}
	if (STR_Menu_Choice == "load game")
	{
		cout << "Sorry but this feature doesn't exist yet, please restart the game\n";
		exit(0);
	}
	if (STR_Menu_Choice == "settings")
	{
		cout << "Sorry but this feature doesn't exist yet, please restart the game\n";
		exit(0);
	}
	if (STR_Menu_Choice == "credits")
	{
		cout << "Sorry but this feature doesn't exist yet, please restart the game\n";
		exit(0);
	}
	if (STR_Menu_Choice == "quit")
	{
		exit(0);
	}
	return 0;
}

// Outputs the Current Dungeon
void output_dungeon(Dungeon* DUNGEON_Current_Dungeon, Story STORY_Story)
{
	system("CLS");
	cout << "\n   " << dye::black_on_white(" ") << dye::black_on_white(DUNGEON_Current_Dungeon->getDungeonName()) << dye::black_on_white(" ") << dye::black_on_white(DUNGEON_Current_Dungeon->getDungeonRoom()) << dye::black_on_white("F \n\n");
	for (int i = 0; i < 15; i++)
	{
		cout << "   ";
		for (int j = 0; j < 15; j++)
		{
			if (DUNGEON_Current_Dungeon->getDungeonMap()[(DUNGEON_Current_Dungeon->getDungeonRoom() - 1)][i][j] == 'O')
			{
				if (DUNGEON_Current_Dungeon->getDungeonName() == "Glacier Wasteland")
				{
					cout << dye::black_on_bright_white("  ");
				}
				else if (DUNGEON_Current_Dungeon->getDungeonName() == "Atlantis Ruins")
				{
					cout << dye::black_on_aqua("  ");
				}
				else if (DUNGEON_Current_Dungeon->getDungeonName() == "Facility")
				{
					cout << dye::black_on_purple("  ");
				}
			}
			else if (DUNGEON_Current_Dungeon->getDungeonMap()[(DUNGEON_Current_Dungeon->getDungeonRoom() - 1)][i][j] == 'X')
			{
				cout << dye::black_on_grey(" ");
				if ((j + 1) == 15 && DUNGEON_Current_Dungeon->getDungeonMap()[(DUNGEON_Current_Dungeon->getDungeonRoom() - 1)][i][j] == 'X')
				{
					cout << dye::black_on_grey(" ");
				}
				else if ((j + 1) < 15)
				{
					if (DUNGEON_Current_Dungeon->getDungeonMap()[(DUNGEON_Current_Dungeon->getDungeonRoom() - 1)][i][(j + 1)] == 'X' || DUNGEON_Current_Dungeon->getDungeonMap()[(DUNGEON_Current_Dungeon->getDungeonRoom() - 1)][i][(j + 1)] == 'O')
					{
						cout << dye::black_on_grey(" ");
					}
					else
					{
						cout << " ";
					}
				}
			}
			else if (DUNGEON_Current_Dungeon->getDungeonMap()[(DUNGEON_Current_Dungeon->getDungeonRoom() - 1)][i][j] == '!' || DUNGEON_Current_Dungeon->getDungeonMap()[(DUNGEON_Current_Dungeon->getDungeonRoom() - 1)][i][j] == '?')
			{
				cout << dye::red(DUNGEON_Current_Dungeon->getDungeonMap()[(DUNGEON_Current_Dungeon->getDungeonRoom() - 1)][i][j]) << " ";
			}
			else if (DUNGEON_Current_Dungeon->getDungeonMap()[(DUNGEON_Current_Dungeon->getDungeonRoom() - 1)][i][j] == '*')
			{
				cout << dye::yellow("*") << " ";
			}
			else
			{
				cout << DUNGEON_Current_Dungeon->getDungeonMap()[(DUNGEON_Current_Dungeon->getDungeonRoom() - 1)][i][j] << " ";
			}
			if (DUNGEON_Current_Dungeon->getDungeonMap()[(DUNGEON_Current_Dungeon->getDungeonRoom() - 1)][i][j] == '+')
			{
				DUNGEON_Current_Dungeon->setPosX(j);
				DUNGEON_Current_Dungeon->setPosY(i);
			}
			if (STORY_Story.isEvent())
			{
				if (i == 0 && j == 14)
				{
					cout << "          Controls";
				}
				if (i == 1 && j == 14)
				{
					cout << "          SPACE: Input";
				}
				if (i == 2 && j == 14)
				{
					cout << "          MOVE:  Arrow Keys";
				}
				if (i == 4 && j == 14)
				{
					cout << "          Commands";
				}
				if (i == 5 && j == 14)
				{
					cout << "          SPACE + /help";
				}
				if (i == 7 && j == 14)
				{
					cout << "          Key";
				}
				if (i == 8 && j == 14)
				{
					cout << "          +: Player";
				}
				if (i == 9 && j == 14)
				{
					cout << "          !: Enemy";
				}
				if (i == 10 && j == 14)
				{
					cout << "          *: Item";
				}
				if (i == 11 && j == 14)
				{
					cout << "          >: Next Floor";
				}
				if (i == 12 && j == 14)
				{
					cout << "          <: Prev Floor";
				}
				if (i == 14 && j == 14)
				{
					cout << "          X: " << DUNGEON_Current_Dungeon->getPosX() << " | Y: " << DUNGEON_Current_Dungeon->getPosY();
				}
			}
		}
		cout << endl;
	}
	cout << "\n\n\n";
}

// Controls Player movement
void map_movement(string STR_Dialogue_Choice, Player& PLAYER_Player, Enemy& ENEMY_New_Enemy, Dungeon* DUNGEON_Current_Dungeon, storyStatus& ENUM_Story_Status, gameStatus& ENUM_Game_Status, Story& STORY_Story)
{
	// I will only comment for the first IF statement as its the same principal for each movement key
	if (STR_Dialogue_Choice == "d")
	{
		// Checks if the next tile is empty
		if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1)) == ' ')
		{
			// Moves the player to the next tile
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1), '+');
			DUNGEON_Current_Dungeon->changePosY(1);
		}

		// Checks if the next tile contains an Enemy (!)
		else if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1)) == '!')
		{
			// Moves the player to the next tile
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1), '+');
			DUNGEON_Current_Dungeon->changePosY(1);
			
			// Picks an enemy from the Dungeon class to fight
			Enemy ENEMY_New_Enemy = DUNGEON_Current_Dungeon->newEnemy();

			// Starts battle
			play_audio("Dungeon Battle");
			battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);
		}

		// Checks if the next tile changes the Dungeon Room (>)
		else if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1)) == '>')
		{
			// Changes the Dungeon Room number by 1
			DUNGEON_Current_Dungeon->changeDungeonRoom(1);
			if (DUNGEON_Current_Dungeon->getDungeonName() == "Glacier Wasteland" || (DUNGEON_Current_Dungeon->getDungeonName() == "Atlantis Ruins" && DUNGEON_Current_Dungeon->getDungeonRoom() == 5) || (DUNGEON_Current_Dungeon->getDungeonName() == "Atlantis Ruins" && DUNGEON_Current_Dungeon->getDungeonRoom() == 7))
			{
				play_audio(DUNGEON_Current_Dungeon->getDungeonName() + " F" + to_string(DUNGEON_Current_Dungeon->getDungeonRoom()));
			}
		}

		// Checks if the next tile contains a Chest (*)
		else if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1)) == '*')
		{
			// Moves the player to the next tile
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1), '+');
			DUNGEON_Current_Dungeon->changePosY(1);

			// Calls the open_chest function to give the Player a new Item
			open_chest(PLAYER_Player, DUNGEON_Current_Dungeon);
			cout << "\n\n";
			system("pause");
		}

		// For Mini Bosses and Key Doors
		if (DUNGEON_Current_Dungeon->getDungeonName() == "Glacier Wasteland")
		{
			if (DUNGEON_Current_Dungeon->getDungeonRoom() == 3)
			{
				// Checks to see if the next tile is a Key Door (|)
				if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1)) == '|')
				{
					// Checks if the Player has the key
					bool BOOL_Has_Key = false;
					for (Item* ITEM_Item : PLAYER_Player.getItems())
					{
						if (ITEM_Item->getName() == "Glacier F3 Key")
						{
							BOOL_Has_Key = true;
						}
					}
					if (BOOL_Has_Key)
					{
						// Moves the player to the next tile (by unlocking the Key Door)
						DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
						DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1), '+');
						DUNGEON_Current_Dungeon->changePosY(1);
					}
					else
					{
						// Outputs the Key which is required
						cout << "   Requires Glacier F3 Key";
						this_thread::sleep_for(chrono::seconds(2));
					}
				}
			}
			else if (DUNGEON_Current_Dungeon->getDungeonRoom() == 5)
			{
				// Checks to see if the next tile is a Key Door (|)
				if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1)) == '|')
				{
					// Checks if the Player has the key
					bool BOOL_Has_Key = false;
					for (Item* ITEM_Item : PLAYER_Player.getItems())
					{
						if (ITEM_Item->getName() == "Glacier F5 Key")
						{
							BOOL_Has_Key = true;
						}
					}
					if (BOOL_Has_Key)
					{
						// Moves the player to the next tile (by unlocking the Key Door)
						DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
						DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1), '+');
						DUNGEON_Current_Dungeon->changePosY(1);
					}
					else
					{
						// Outputs the Key which is required
						cout << "   Requires Glacier F5 Key";
						this_thread::sleep_for(chrono::seconds(2));
					}
				}
			}
			else if (DUNGEON_Current_Dungeon->getDungeonRoom() == 6)
			{
				// Checks to see if the next tile is a Mini Boss or Main Boss (?)
				if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1)) == '?')
				{
					// Moves the player to the next tile
					DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
					DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1), '+');
					DUNGEON_Current_Dungeon->changePosY(1);

					// Initiates dialogue sequence
					play_audio("Encounter");
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   ??? > Who goes there!?";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   ??? > Only authorised personal can go enter this unexplored point of interest";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   " << PLAYER_Player.getName() << " > What's going on?";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   " << PLAYER_Player.getName() << " > What year even is it??";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   ??? > The year is 2067, the date is the 31st of January. And who are you weakling?";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   " << PLAYER_Player.getName() << " > " << PLAYER_Player.getName() << ".";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   ??? > I'm an active sergeant for the russians who currently compromise this area";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   Russian Sergeant > State your reason for being here";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   " << PLAYER_Player.getName() << " > I want to know what's going on";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   Russian Sergeant > I'm afraid I cannot tell you";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   Russian Sergeant > If you can prove to me you are capable, I may let you pass";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   " << PLAYER_Player.getName() << " > Huh? Prove to you what?";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   Russian Sergeant > This...";
					_getch();

					// Assigns the Enemy object a custom Enemy, this being the Main Boss of the dungeon
					Enemy ENEMY_New_Enemy = Enemy("Russian Sergeant", 15, 537, 93, { Skill("Meflamao"), Skill("Freezan"), Skill("Gust"), Skill("Meblight"), Skill("Hex") }, new ItemSkill("Battery Reserve", "Incase of power cut emergencies", 4, Skill("Mezapao")), true, 56);
					
					// Starts battle
					play_audio("Dungeon Main Boss");
					battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);

					// Once out of the battle gameplay loop, start dialogue and story between dungeons
					STORY_Story.startOfDialogue();
					STORY_Story.increaseDialogueIndex();
					ENUM_Story_Status = storyStatus::ACT_TWO;
					ENUM_Game_Status = gameStatus::DIALOGUE;
				}
			}
		}
		else if (DUNGEON_Current_Dungeon->getDungeonName() == "Atlantis Ruins")
		{
			if (DUNGEON_Current_Dungeon->getDungeonRoom() == 2)
			{
				// Checks to see if the next tile is a Key Door (|)
				if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1)) == '|')
				{
					bool BOOL_Has_Key = false;
					for (Item* ITEM_Item : PLAYER_Player.getItems())
					{
						if (ITEM_Item->getName() == "Atlantis F2 Key")
						{
							BOOL_Has_Key = true;
						}
					}
					if (BOOL_Has_Key)
					{
						// Moves the player to the next tile (by unlocking the Key Door)
						DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
						DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1), '+');
						DUNGEON_Current_Dungeon->changePosY(1);
					}
					else
					{
						// Outputs the Key which is required
						cout << "   Requires Atlantis F2 Key";
						this_thread::sleep_for(chrono::seconds(2));
					}
				}

				// Checks to see if the next tile is a Mini Boss or Main Boss (?)
				else if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1)) == '?')
				{ 
					// Reanimated Mermaid Mini Boss, drops key used to advance
					// Moves the player to the next tile
					DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
					DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1), '+');
					DUNGEON_Current_Dungeon->changePosY(1);

					// Initiates dialogue sequence
					play_audio("Encounter");
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   ??? > Who the fuck are you? What are you doing here!?";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   Yourself > I beat that Russian Sergeant back in the Glacier Wastelands, and now I am here";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   ??? > Russian Sergeant? You mean the russians are here?";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   Yourself > Uh... yeah...";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   ??? > Bloody outrageous! I am a soldier from the UK, how can they be here already!";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   British Soldier > What are your intentions anyway? Can't you see we're busy?";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   Yourself > I'm not sure... but I want answers, why am I here? I thought I was a goner 41 years ago!";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   Yourself > So if I was you I'd hand over that key so I can advance...";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   British Soldier > Christ almighty! Aren't you a tough guy?";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   British Soldier > We've been experimenting with reanimations with all this new uncovered knowledge";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   British Soldier > Why don't you fight one of our little subjects?";
					_getch(); cout << "\33[2K\r" << flush;;

					// Assigns the Enemy object a custom Enemy, this being the Mini Boss of floor 2
					Enemy ENEMY_New_Enemy = Enemy("Reanimated Mermaid", 20, 586, 126, { Skill("Flame"), Skill("Flamao"), Skill("Flamadia"), Skill("Zapao"), Skill("Hexo"), Skill("Blighta")}, new Item("Atlantis F2 Key", "Rusted key from Atlantis, maybe can be used for something?", 3), true, 53);

					// Starts battle
					play_audio("Dungeon Mini Boss");
					battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);
				}
			}
			if (DUNGEON_Current_Dungeon->getDungeonRoom() == 4)
			{
				// Checks to see if the next tile is a Key Door (|)
				if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1)) == '|')
				{
					bool BOOL_Has_Key = false;
					for (Item* ITEM_Item : PLAYER_Player.getItems())
					{
						if (ITEM_Item->getName() == "Atlantis F4 Key")
						{
							BOOL_Has_Key = true;
						}
					}
					if (BOOL_Has_Key)
					{
						// Moves the player to the next tile (by unlocking the Key Door)
						DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
						DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1), '+');
						DUNGEON_Current_Dungeon->changePosY(1);
					}
					else
					{
						// Outputs the Key which is required
						cout << "   Requires Atlantis F4 Key";
						this_thread::sleep_for(chrono::seconds(2));
					}
				}
			}
			if (DUNGEON_Current_Dungeon->getDungeonRoom() == 5)
			{
				// Checks to see if the next tile is a Key Door (|)
				if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1)) == '|')
				{
					bool BOOL_Has_Key = false;
					for (Item* ITEM_Item : PLAYER_Player.getItems())
					{
						if (ITEM_Item->getName() == "Atlantis F5 Key B")
						{
							BOOL_Has_Key = true;
						}
					}
					if (BOOL_Has_Key)
					{
						// Moves the player to the next tile (by unlocking the Key Door)
						DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
						DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1), '+');
						DUNGEON_Current_Dungeon->changePosY(1);
					}
					else
					{
						// Outputs the Key which is required
						cout << "   Requires Atlantis F5 Key B";
						this_thread::sleep_for(chrono::seconds(2));
					}
				}
			}
			if (DUNGEON_Current_Dungeon->getDungeonRoom() == 7)
			{
				// Checks to see if the next tile is a Mini Boss or Main Boss (?)
				if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1)) == '?')
				{
					// Moves the player to the next tile
					DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
					DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1), '+');
					DUNGEON_Current_Dungeon->changePosY(1);

					// Initiates dialogue sequence
					play_audio("Encounter");
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   need to code dialogue";
					_getch(); cout << "\33[2K\r" << flush;;

					// Assigns the Enemy object a custom Enemy, this being the Main Boss of the dungeon
					Enemy ENEMY_New_Enemy = Enemy("Reawoken Guardian of Atlantis", 35, 976, 214, { Skill("Flamao"), Skill("Splashan"), Skill("Splashadia"), Skill("Freezan"), Skill("Hexo"), Skill("Mehexaon"), Skill("Heal")}, new Item("Mysterious Machine Part", "It seems like some sort of part from a machine, maybe this could play a vital part in saving the world?", 4), true, 47);

					// Starts battle
					play_audio("Dungeon Main Boss");
					battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);

					// Once out of the battle gameplay loop, start dialogue and story between dungeons
					STORY_Story.startOfDialogue();
					STORY_Story.increaseDialogueIndex();
					ENUM_Story_Status = storyStatus::ACT_THREE;
					ENUM_Game_Status = gameStatus::DIALOGUE;
				}
			}
		}
	}
	if (STR_Dialogue_Choice == "a")
	{
		if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() - 1)) == ' ')
		{
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() - 1), '+');
			DUNGEON_Current_Dungeon->changePosY(-1);
		}
		else if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() - 1)) == '!')
		{
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() - 1), '+');
			DUNGEON_Current_Dungeon->changePosY(-1);
			Enemy ENEMY_New_Enemy = DUNGEON_Current_Dungeon->newEnemy();
			play_audio("Dungeon Battle");
			battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);
		}
		else if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() - 1)) == '<')
		{
			DUNGEON_Current_Dungeon->changeDungeonRoom(-1);
			if (DUNGEON_Current_Dungeon->getDungeonName() == "Glacier Wasteland" || (DUNGEON_Current_Dungeon->getDungeonName() == "Atlantis Ruins" && DUNGEON_Current_Dungeon->getDungeonRoom() == 4) || (DUNGEON_Current_Dungeon->getDungeonName() == "Atlantis Ruins" && DUNGEON_Current_Dungeon->getDungeonRoom() == 6))
			{
				play_audio(DUNGEON_Current_Dungeon->getDungeonName() + " F" + to_string(DUNGEON_Current_Dungeon->getDungeonRoom()));
			}
		}
		else if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() - 1)) == '*')
		{
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() - 1), '+');
			DUNGEON_Current_Dungeon->changePosY(-1);
			open_chest(PLAYER_Player, DUNGEON_Current_Dungeon);
			cout << "\n\n";
			system("pause");
		}
		else if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() - 1)) == '?')
		{
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() - 1), '+');
			DUNGEON_Current_Dungeon->changePosY(-1);
			if (DUNGEON_Current_Dungeon->getDungeonName() == "Glacier Wasteland")
			{
				if (DUNGEON_Current_Dungeon->getDungeonRoom() == 3) // Snow Golem Mini Boss, drops key used to advance
				{
					play_audio("Encounter");
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   What is this creature...";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   Regardless, it seems to have a key embedded on it's torso";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   I should probably try grabbing it";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   ??? > *growls angrily*";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   ??? > *charges towards " << PLAYER_Player.getName() << "*";
					_getch(); cout << "\33[2K\r" << flush;;
					Enemy ENEMY_New_Enemy = Enemy("Snow Golem", 10, 232, 54, { Skill("Mefreeze"), Skill("Freezan"), Skill("Hex") }, new Item("Glacier F3 Key", "Frozen key lost in time, maybe can be used for something?", 3), true, 31);
					play_audio("Dungeon Mini Boss");
					battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);
				}
				else if (DUNGEON_Current_Dungeon->getDungeonRoom() == 5) // Duty Soldier Mini Boss, drops key used to advance
				{
					play_audio("Encounter");
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   Duty Soldier > Aha! Another worthless twat trying to get in our way!";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   Yourself > There seems to be a key dangling on his belt";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   Yourself > Perhaps I need to grab it by force";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   Duty Soldier > Come here little one let me put you out of your misery...";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   " << PLAYER_Player.getName() << " > Bring it!";
					_getch(); cout << "\33[2K\r" << flush;;
					Enemy ENEMY_New_Enemy = Enemy("Duty Soldier", 12, 384, 67, { Skill("Flame"), Skill("Zap"), Skill("Zapao"), Skill("Blight")}, new Item("Glacier F5 Key", "Frozen key lost in time, maybe can be used for something?", 3), true, 37);
					play_audio("Dungeon Mini Boss");
					battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);
				}
			}
			else if (DUNGEON_Current_Dungeon->getDungeonName() == "Atlantis Ruins")
			{
				if (DUNGEON_Current_Dungeon->getDungeonRoom() == 4) // Reanimated Jellyfisherman Mini Boss, drops key used to advance
				{
					play_audio("Encounter");
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   Yourself > Heyyyy, could you like lowkey gimme that key?";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   ??? > ...";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   ??? > *gargling*";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   British Soldier > You beat that mermaid thingy?";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   British Soldier > Bloody hell! That subject was useless!";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   British Soldier > Well behold! Our 'newest' creation!";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   British Soldier > We dragged the dead corpses of one of the many civilizations that used to inhabit here";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   British Soldier > Isn't that right, Jellyfisherman?";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   Reanimated Jellyfisherman > *gargles more*";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   Reanimated Jellyfisherman > *shoots bolts towards " << PLAYER_Player.getName() << "*";
					_getch(); cout << "\33[2K\r" << flush;;
					Enemy ENEMY_New_Enemy = Enemy("Reanimated Jellyfisherman", 25, 636, 174, { Skill("Splashan"), Skill("Splashadia"), Skill("Zapadia"), Skill("Mezapadia"), Skill("Hexo"), Skill("Blighta") }, new Item("Atlantis F4 Key", "Rusted key from Atlantis, maybe can be used for something?", 3), true, 28);
					play_audio("Dungeon Mini Boss");
					battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);
				}
				if (DUNGEON_Current_Dungeon->getDungeonRoom() == 5) // Radioactive Atlantis Survivor Mini Boss, drops key used to advance
				{
					play_audio("Encounter");
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   You notice something feels off";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   British Soldier > Notice the radical looking hazmat?";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   ??? > *gargling*";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   British Soldier > Looks like that Jellyfisherman was utter pointless aswell!";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   British Soldier > Blooming heck! Can anything round here be useful?";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   The soldier storms off in a fit of rage";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   The air feels poisonous";
					_getch(); cout << "\33[2K\r" << flush;;
					cout << "   ??? > *lunges towards " << PLAYER_Player.getName() << "*";
					_getch(); cout << "\33[2K\r" << flush;;
					Enemy ENEMY_New_Enemy = Enemy("Radioactive Atlantis Survivor", 28, 746, 214, { Skill("Splashadia"), Skill("Mesplashadia"), Skill("Frei"), Skill("Heal") }, new Item("Atlantis F5 Key A", "Rusted key from Atlantis, maybe can be used for something?", 3), true, 6);
					play_audio("Dungeon Mini Boss");
					battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);
				}
			}
		}
		else if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() - 1)) == '|')
		{
			if (DUNGEON_Current_Dungeon->getDungeonName() == "Atlantis Ruins")
			{
				if (DUNGEON_Current_Dungeon->getDungeonRoom() == 5)
				{
					bool BOOL_Has_Key = false;
					for (Item* ITEM_Item : PLAYER_Player.getItems())
					{
						if (ITEM_Item->getName() == "Atlantis F5 Key A")
						{
							BOOL_Has_Key = true;
						}
					}
					if (BOOL_Has_Key)
					{
						DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
						DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() - 1), '+');
						DUNGEON_Current_Dungeon->changePosY(-1);
					}
					else
					{
						cout << "   Requires Atlantis F5 Key A";
						this_thread::sleep_for(chrono::seconds(2));
					}
				}
			}
		}
	}
	if (STR_Dialogue_Choice == "w")
	{
		if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), (DUNGEON_Current_Dungeon->getPosY() - 1), DUNGEON_Current_Dungeon->getPosX()) == ' ')
		{
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), (DUNGEON_Current_Dungeon->getPosY() - 1), DUNGEON_Current_Dungeon->getPosX(), '+');
			DUNGEON_Current_Dungeon->changePosX(-1);
		}
		else if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), (DUNGEON_Current_Dungeon->getPosY() - 1), DUNGEON_Current_Dungeon->getPosX()) == '!')
		{
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), (DUNGEON_Current_Dungeon->getPosY() - 1), DUNGEON_Current_Dungeon->getPosX(), '+');
			DUNGEON_Current_Dungeon->changePosX(-1);
			Enemy ENEMY_New_Enemy = DUNGEON_Current_Dungeon->newEnemy();
			play_audio("Dungeon Battle");
			battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);
		}
		else if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), (DUNGEON_Current_Dungeon->getPosY() - 1), DUNGEON_Current_Dungeon->getPosX()) == '*')
		{
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), (DUNGEON_Current_Dungeon->getPosY() - 1), DUNGEON_Current_Dungeon->getPosX(), '+');
			DUNGEON_Current_Dungeon->changePosX(-1);
			open_chest(PLAYER_Player, DUNGEON_Current_Dungeon);
			cout << "\n\n";
			system("pause");
		}
	}
	if (STR_Dialogue_Choice == "s")
	{
		if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), (DUNGEON_Current_Dungeon->getPosY() + 1), DUNGEON_Current_Dungeon->getPosX()) == ' ')
		{
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), (DUNGEON_Current_Dungeon->getPosY() + 1), DUNGEON_Current_Dungeon->getPosX(), '+');
			DUNGEON_Current_Dungeon->changePosX(1);
		}
		else if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), (DUNGEON_Current_Dungeon->getPosY() + 1), DUNGEON_Current_Dungeon->getPosX()) == '!')
		{
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), (DUNGEON_Current_Dungeon->getPosY() + 1), DUNGEON_Current_Dungeon->getPosX(), '+');
			DUNGEON_Current_Dungeon->changePosX(1);
			Enemy ENEMY_New_Enemy = DUNGEON_Current_Dungeon->newEnemy();
			play_audio("Dungeon Battle");
			battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);
		}
		else if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), (DUNGEON_Current_Dungeon->getPosY() + 1), DUNGEON_Current_Dungeon->getPosX()) == '*')
		{
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), (DUNGEON_Current_Dungeon->getPosY() + 1), DUNGEON_Current_Dungeon->getPosX(), '+');
			DUNGEON_Current_Dungeon->changePosX(1);
			open_chest(PLAYER_Player, DUNGEON_Current_Dungeon);
			cout << "\n\n";
			system("pause");
		}
		else if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), (DUNGEON_Current_Dungeon->getPosY() + 1), DUNGEON_Current_Dungeon->getPosX()) == '?')
		{
			if (DUNGEON_Current_Dungeon->getDungeonName() == "Atlantis Ruins" && DUNGEON_Current_Dungeon->getDungeonRoom() == 5)
			{
				DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
				DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), (DUNGEON_Current_Dungeon->getPosY() + 1), DUNGEON_Current_Dungeon->getPosX(), '+');
				DUNGEON_Current_Dungeon->changePosX(1);
				Enemy ENEMY_New_Enemy = Enemy("Radioactive Atlantis Guard", 30, 813, 214, { Skill("Meflamao"), Skill("Mesplashan"), Skill("Zapao"), Skill("Hexaon"), Skill("Frei"), Skill("Heal") }, new Item("Atlantis F5 Key B", "Rusted key from Atlantis, maybe can be used for something?", 3), true, 95);
				play_audio("Dungeon Mini Boss");
				battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);
			}
		}
	}
}

// Chest function which grants the player a new Item
void open_chest(Player& PLAYER_Player, Dungeon* DUNGEON_Current_Dungeon)
{
	// Picks a random Item object pointer from the Current Dungeon's loot pool
	Item* ITEM_New_Item = DUNGEON_Current_Dungeon->getItemFromChest();
	bool BOOL_Item_Dupe = false;
	
	// Checks if the Item chosen is a duplicate
	for (Item* ITEM_Item : PLAYER_Player.getItems())
	{
		if (ITEM_New_Item->getName() == ITEM_Item->getName())
		{
			if (!ITEM_New_Item->isMeleeWeapon() || (ITEM_New_Item->isMeleeWeapon() && ITEM_New_Item->getMeleeDamage() == ITEM_Item->getMeleeDamage()))
			{
				ITEM_Item->increaseQuantity(1);
				BOOL_Item_Dupe = true;
			}
		}
	}
	if (!BOOL_Item_Dupe)
	{
		PLAYER_Player.addItem(ITEM_New_Item);
	}

	// Outputs the new Item
	cout << dye::yellow("   Something is shining on the ground...\n\n");
	this_thread::sleep_for(chrono::seconds(2));
	cout << dye::yellow("   You found ") << dye::light_yellow(ITEM_New_Item->getName()) << dye::yellow("!");
	if (!BOOL_Item_Dupe)
	{
		cout << dye::green(" (NEW)");
	}
	cout << "\n\n";
	ITEM_New_Item->toString();
	PLAYER_Player.update();
	this_thread::sleep_for(chrono::seconds(2));
}

// Battle gameplay loop
void battle(Player& PLAYER_Player, Dungeon* DUNGEON_Current_Dungeon, Enemy ENEMY_Enemy)
{
	system("CLS");
	bool BOOL_Player_Turn = true; // Is it PLAYER_Player turn or ENEMY_Enemy turn?
	bool battle = true; // Whilst the battle is in play
	string STR_Battle_Choice; // Selecting a skill
	string STR_Player_Page; // Battle menu page
	int INT_Skill_Index = 0; // Selected skill INDEX_Skill (to display)

	// Sets up the Enemy
	Item* enemyDrop = ENEMY_Enemy.getDroppedItem();
	DUNGEON_Current_Dungeon->elementSetter(ENEMY_Enemy);
	ENEMY_Enemy.setHealth();

	cout << "\n   You have encountered " << ENEMY_Enemy.getName() << endl;
	this_thread::sleep_for(chrono::seconds(3));
	PLAYER_Player.update();
	// Battle Loop
	while (battle)
	{
		bool BOOL_Valid_Skill = false;
		STR_Player_Page = "";
		while (BOOL_Player_Turn)
		{
			// Starts the PLAYER_Player's turn
			PLAYER_Player.setGuard(false);
			while ((STR_Player_Page != "melee") && (STR_Player_Page != "skill") && (STR_Player_Page != "item") && (STR_Player_Page != "guard") && (STR_Player_Page != "analyse"))
			{
				show_battle_stats(PLAYER_Player);
				cout << "\n--> Melee";
				if (PLAYER_Player.getMeleeAttackMultiplier() != 1.0) cout << " ^^";
				cout << "\n--> Skill";
				if (PLAYER_Player.getMagicAttackMultiplier() != 1.0) cout << " ^^"; 
				cout << "\n--> Item\n--> Guard\n--> Analyse\n\n  > ";
				getline(cin, STR_Player_Page);
				STR_Player_Page = convert_string_tolower(STR_Player_Page);
			}
			while (STR_Player_Page == "item" && BOOL_Player_Turn)
			{
				system("CLS");
				show_battle_stats(PLAYER_Player);
				cout << endl;
				bool hasItems = false;
				for (Item* ITEM_Item : PLAYER_Player.getItems())
				{
					if (ITEM_Item->isConsumable() && ITEM_Item->getQuantity() > 0)
					{
						hasItems = true;
					}
				}
				if (!hasItems)
				{
					cout << "   You have no useable items currently." << endl;
					this_thread::sleep_for(chrono::seconds(2));
					STR_Player_Page = "";
				}
				else
				{
					for (Item* ITEM_Item : PLAYER_Player.getItems())
					{
						if (ITEM_Item->isConsumable())
						{
							ITEM_Item->toString();
							cout << endl << endl;
						}
					}
					cout << "--> Return\n\n  > ";
					getline(cin, STR_Battle_Choice);
					STR_Battle_Choice = convert_string_tolower(STR_Battle_Choice);
					for (Item* ITEM_Item : PLAYER_Player.getItems())
					{
						if (convert_string_tolower(ITEM_Item->getName()) == STR_Battle_Choice && ITEM_Item->isConsumable())
						{
							system("CLS");
							show_battle_stats(PLAYER_Player);
							if (ITEM_Item->getType() == "HP")
							{
								PLAYER_Player.changeHealth(ITEM_Item->getAmount());
								if (PLAYER_Player.getHealth() > PLAYER_Player.getMaxHealth())
								{
									PLAYER_Player.fullHealth();
								}
								cout << "\n   You used " << ITEM_Item->getName() << " restoring " << ITEM_Item->getAmount() << " " << ITEM_Item->getType();
							}
							else if (ITEM_Item->getType() == "STA")
							{
								PLAYER_Player.changeStamina(ITEM_Item->getAmount());
								if (PLAYER_Player.getStamina() > PLAYER_Player.getMaxStamina())
								{
									PLAYER_Player.fullStamina();
								}
								cout << "\n   You used " << ITEM_Item->getName() << " restoring " << ITEM_Item->getAmount() << " " << ITEM_Item->getType();
							}
							else if (ITEM_Item->getType() == "ATK")
							{
								cout << "\n   You used " << ITEM_Item->getName() << " increasing your next melee attack damage by " << round((ITEM_Item->getAmount()) * 100 - 100) << "%";
								PLAYER_Player.setMeleeAttackMultiplier(ITEM_Item->getAmount());
							}
							else if (ITEM_Item->getType() == "MAG")
							{
								cout << "\n   You used " << ITEM_Item->getName() << " increasing your next magic attack damage by " << round((ITEM_Item->getAmount()) * 100 - 100) << "%";
								PLAYER_Player.setMagicAttackMultiplier(ITEM_Item->getAmount());
							}
							else if (ITEM_Item->getType() == "ATK/MAG")
							{
								cout << "\n   You used " << ITEM_Item->getName() << " increasing your next melee and magic attack damage by " << round((ITEM_Item->getAmount()) * 100 - 100) << "%";
								PLAYER_Player.setMeleeAttackMultiplier(ITEM_Item->getAmount());
								PLAYER_Player.setMagicAttackMultiplier(ITEM_Item->getAmount());
							}
							ITEM_Item->increaseQuantity(-1);
							if (ITEM_Item->getQuantity() == 0)
							{
								vector<Item*> TEMP_Player_Items = PLAYER_Player.getItems();
								TEMP_Player_Items.erase(find(TEMP_Player_Items.begin(), TEMP_Player_Items.end(), ITEM_Item));
								PLAYER_Player.setItems(TEMP_Player_Items);
							}
							BOOL_Player_Turn = false;
							break;
						}
					}
					if (STR_Battle_Choice == "return" || STR_Battle_Choice == "r")
					{
						STR_Player_Page = "";
						break;
					}
				}
			}
			// Page : Skill
			while (STR_Player_Page == "skill")
			{
				system("CLS");
				show_battle_stats(PLAYER_Player);
				cout << endl;
				if (PLAYER_Player.getSkills().empty())
				{
					cout << "   You have no skills currently." << endl;
					this_thread::sleep_for(chrono::seconds(2));
					STR_Player_Page = "";
				}
				else
				{
					show_skill(PLAYER_Player, INT_Skill_Index);
					cout << "\n\n--> Next\n--> Back\n--> Return\n\n  > ";
					getline(cin, STR_Battle_Choice);
					STR_Battle_Choice = convert_string_tolower(STR_Battle_Choice);
					// Validates if the skill selected exists
					for (Skill skill : PLAYER_Player.getSkills())
					{
						if ((STR_Battle_Choice == convert_string_tolower(skill.getName())) && (PLAYER_Player.getStamina() >= skill.getStaminaCost()))
						{
							Skill SKILL_Skill_Selected = skill;
							system("CLS");
							show_battle_stats(PLAYER_Player);
							// Determines what the skill does
							if (SKILL_Skill_Selected.getType() == "Support")
							{
								// Heal the PLAYER_Player
								PLAYER_Player.changeHealth(SKILL_Skill_Selected.getHPGain());
								cout << "\n   You have healed yourself restoring " << SKILL_Skill_Selected.getHPGain() << " health\n\n";
							}
							else
							{
								// Damage the ENEMY_Enemy
								int INT_Calculated_Damage; // Player Skill Damage after calculations
								float FLT_Attribute_Multiplier = 1 + (float(PLAYER_Player.getPlayerAttributes().find("Magic")->second) / 25); // Player Attribute "Magic" Multiplier
								if (PLAYER_Player.getMeleeWeapon().hasModifiedAttribute())
								{
									if (PLAYER_Player.getMeleeWeapon().getAttributeType() == "Magic")
									{
										FLT_Attribute_Multiplier *= PLAYER_Player.getMeleeWeapon().getBonusValue();
									}
								}

								if (SKILL_Skill_Selected.getType() == "Nuclear")
								{
									INT_Calculated_Damage = SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * PLAYER_Player.getMagicAttackMultiplier();
									cout << "\n   You casted " << SKILL_Skill_Selected.getName() << " upon all enemies dealing " << INT_Calculated_Damage << " damage ";
								}
								else
								{
									if (ENEMY_Enemy.getElements().find(SKILL_Skill_Selected.getType())->second == "-")
									{
										INT_Calculated_Damage = SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * PLAYER_Player.getMagicAttackMultiplier();
										cout << "\n   You casted " << SKILL_Skill_Selected.getName() << " upon " << ENEMY_Enemy.getName() << " dealing " << INT_Calculated_Damage << " damage ";
									}
									else if (ENEMY_Enemy.getElements().find(SKILL_Skill_Selected.getType())->second == "Wk")
									{
										INT_Calculated_Damage = SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * 1.5 * PLAYER_Player.getMagicAttackMultiplier();
										cout << "\n   You casted " << SKILL_Skill_Selected.getName() << " upon " << ENEMY_Enemy.getName() << " dealing " << INT_Calculated_Damage << " damage " << dye::black_on_yellow(" WEAK ") << " ";
									}
									else if (ENEMY_Enemy.getElements().find(SKILL_Skill_Selected.getType())->second == "Rst")
									{
										INT_Calculated_Damage = SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * 0.5 * PLAYER_Player.getMagicAttackMultiplier();
										cout << "\n   You casted " << SKILL_Skill_Selected.getName() << " upon " << ENEMY_Enemy.getName() << " dealing " << INT_Calculated_Damage << " damage " << dye::black_on_red(" RESIST ") << " ";
									}
									else if (ENEMY_Enemy.getElements().find(SKILL_Skill_Selected.getType())->second == "Nul")
									{
										INT_Calculated_Damage = 0;
										cout << "\n   You casted " << SKILL_Skill_Selected.getName() << " upon " << ENEMY_Enemy.getName() << " dealing " << INT_Calculated_Damage << " damage " << dye::black_on_grey(" BLOCK ") << " ";
									}
								}

								if (PLAYER_Player.getMeleeWeapon().hasModifiedAttribute() && PLAYER_Player.getMeleeWeapon().getAttributeType() == "Magic")
								{
									cout << dye::aqua_on_light_aqua(" BONUS ");
								}
								cout << "\n\n";
								ENEMY_Enemy.changeHealth(-INT_Calculated_Damage);
							}
							PLAYER_Player.changeStamina(-SKILL_Skill_Selected.getStaminaCost());
							PLAYER_Player.setMagicAttackMultiplier(1.0);
							BOOL_Player_Turn = false;
							break;
						}
					}
					if (!BOOL_Player_Turn) break;
					// If STR_Battle_Choice is "next", show the PLAYER_Player their next skill
					if (STR_Battle_Choice == "next" || STR_Battle_Choice == "n" || STR_Battle_Choice == ">")
					{
						INT_Skill_Index++;
						if (INT_Skill_Index > PLAYER_Player.getSkills().size() - 1)
						{
							INT_Skill_Index = 0;
						}
					}
					// If STR_Battle_Choice is "back", show the PLAYER_Player their previous skill
					else if (STR_Battle_Choice == "back" || STR_Battle_Choice == "b" || STR_Battle_Choice == "<")
					{
						INT_Skill_Index--;
						if (INT_Skill_Index < 0)
						{
							INT_Skill_Index = PLAYER_Player.getSkills().size() - 1;
						}
					}
					// If STR_Battle_Choice is "return", take the PLAYER_Player back to the main battle menu
					else if (STR_Battle_Choice == "return" || STR_Battle_Choice == "r")
					{
						STR_Player_Page = "";
						break;
					}
				}
			}
			// Page : Melee
			while (STR_Player_Page == "melee")
			{
				system("CLS");
				show_battle_stats(PLAYER_Player);
				cout << endl;
				PLAYER_Player.getMeleeWeapon().toString();
				cout << "\n\n--> Use\n--> Return\n\n  > ";
				getline(cin, STR_Battle_Choice);
				STR_Battle_Choice = convert_string_tolower(STR_Battle_Choice);

				// If STR_Battle_Choice is "use", attack the ENEMY_Enemy with melee weapon
				if (STR_Battle_Choice == "use" || STR_Battle_Choice == "u")
				{
					int INT_Critical_Chance = (rand() % 100) + 1; // Number 1-100, if >79 deal a Critical Hit
					int INT_Calculated_Damage; // Player Melee Damage after calculations
					float FLT_Attribute_Multiplier = 1 + (float(PLAYER_Player.getPlayerAttributes().find("Strength")->second) / 25); // Player Attribute "Strength" Multiplier
					if (PLAYER_Player.getMeleeWeapon().hasModifiedAttribute())
					{
						if (PLAYER_Player.getMeleeWeapon().getAttributeType() == "Melee")
						{
							FLT_Attribute_Multiplier *= PLAYER_Player.getMeleeWeapon().getBonusValue();
						}
					}
					else if (PLAYER_Player.getMeleeWeapon().hasElementCoverage())
					{
						if (ENEMY_Enemy.getElements().find(PLAYER_Player.getMeleeWeapon().getElementalType())->second == "Wk")
						{
							FLT_Attribute_Multiplier *= PLAYER_Player.getMeleeWeapon().getBonusValue();
						}
					}
					system("CLS");
					show_battle_stats(PLAYER_Player);
					if (INT_Critical_Chance > 79)
					{
						INT_Calculated_Damage = PLAYER_Player.getMeleeWeapon().getMeleeDamage() * FLT_Attribute_Multiplier * 2 * PLAYER_Player.getMeleeAttackMultiplier();
						cout << "\n   You attacked " << ENEMY_Enemy.getName() << " using " << PLAYER_Player.getMeleeWeapon().getName() << " landing a CRITICAL HIT dealing " << INT_Calculated_Damage << " damage ";
					}
					else
					{
						INT_Calculated_Damage = PLAYER_Player.getMeleeWeapon().getMeleeDamage() * FLT_Attribute_Multiplier * PLAYER_Player.getMeleeAttackMultiplier();
						cout << "\n   You attacked " << ENEMY_Enemy.getName() << " using " << PLAYER_Player.getMeleeWeapon().getName() << " dealing " << INT_Calculated_Damage << " damage ";
					}

					if (PLAYER_Player.getMeleeWeapon().hasModifiedAttribute() && PLAYER_Player.getMeleeWeapon().getAttributeType() == "Melee")
					{
						cout << dye::aqua_on_light_aqua(" BONUS ");
					}
					cout << "\n\n";
					ENEMY_Enemy.changeHealth(-INT_Calculated_Damage);
					PLAYER_Player.setMeleeAttackMultiplier(1.0);
					BOOL_Player_Turn = false;
					break;
				}
				// If STR_Battle_Choice is "return", take the PLAYER_Player back to the main battle menu
				else if (STR_Battle_Choice == "return" || STR_Battle_Choice == "r")
				{
					STR_Player_Page = "";
					break;
				}
			}
			// Page : Guard
			while (STR_Player_Page == "guard")
			{
				system("CLS");
				show_battle_stats(PLAYER_Player);
				cout << endl;
				cout << "   Reduce incoming damage by 33% and negates weaknesses\n   (Does stack if resistant)";
				cout << "\n\n--> Guard\n--> Return\n\n  > ";
				getline(cin, STR_Battle_Choice);
				STR_Battle_Choice = convert_string_tolower(STR_Battle_Choice);

				// If STR_Battle_Choice is "guard", guards against incoming attack
				if (STR_Battle_Choice == "guard" || STR_Battle_Choice == "g")
				{
					system("CLS");
					show_battle_stats(PLAYER_Player);
					PLAYER_Player.setGuard(true);
					cout << "\n   You have guarded yourself\n\n";
					BOOL_Player_Turn = false;
					break;
				}
				// If STR_Battle_Choice is "return", take the PLAYER_Player back to the main battle menu
				else if (STR_Battle_Choice == "return" || STR_Battle_Choice == "r")
				{
					STR_Player_Page = "";
					break;
				}
			}
			// Page : Analyse
			while (STR_Player_Page == "analyse")
			{
				system("CLS");
				show_enemy_stats(ENEMY_Enemy);
				cout << "\n   Item: " << enemyDrop->getName();
				cout << "\n\n--> Return\n\n  > ";
				getline(cin, STR_Battle_Choice);
				STR_Battle_Choice = convert_string_tolower(STR_Battle_Choice);

				// If STR_Battle_Choice is "return", take the PLAYER_Player back to the main battle menu
				if (STR_Battle_Choice == "return" || STR_Battle_Choice == "r")
				{
					STR_Player_Page = "";
					break;
				}
			}
		}
		if (ENEMY_Enemy.getHealth() <= 0)
		{
			play_audio("Victory");
			float FLT_EXP_Earned;
			bool BOOL_Item_Dupe = false;
			if (ENEMY_Enemy.getName() == "Gold Entity I" || ENEMY_Enemy.getName() == "Gold Entity II" || ENEMY_Enemy.getName() == "Gold Entity III" || ENEMY_Enemy.getName() == "Gold Entity IV")
			{
				FLT_EXP_Earned = int(ENEMY_Enemy.getMaxHealth() * 7.7);
			}
			else if (ENEMY_Enemy.isBoss())
			{
				FLT_EXP_Earned = ENEMY_Enemy.getMaxHealth() * 5;
			}
			else
			{
				FLT_EXP_Earned = ENEMY_Enemy.getMaxHealth() * 2;
			}
			for (Item* ITEM_Item : PLAYER_Player.getItems())
			{
				if (enemyDrop->getName() == ITEM_Item->getName())
				{
					if (!enemyDrop->isMeleeWeapon() || (enemyDrop->isMeleeWeapon() && enemyDrop->getMeleeDamage() == ITEM_Item->getMeleeDamage()))
					{
						ITEM_Item->increaseQuantity(1);
						BOOL_Item_Dupe = true;
					}
				}
			}
			if (!BOOL_Item_Dupe)
			{
				PLAYER_Player.addItem(enemyDrop);
			}
			for (int i = 0; i < 20; i++)
			{
				Sleep(10);
				system("CLS");
				PLAYER_Player.increaseExp(FLT_EXP_Earned / 20);
				cout << "\n   You gained " << FLT_EXP_Earned << " experience" << endl << endl;
				cout << "   " << ENEMY_Enemy.getName() << " dropped " << enemyDrop->getName() << "!" << endl;
				if (!BOOL_Item_Dupe)
				{
					if (enemyDrop->canInheritSkill())
					{
						cout << "   + Unlocked Skill: " << enemyDrop->getSkill().getName() << endl;
					}
				}
				cout << "\n   Level " << PLAYER_Player.getLevel() << " | Next EXP: " << int(PLAYER_Player.getNextEXP());
				cout << "\n   HP: " << PLAYER_Player.getHealth() << "/" << PLAYER_Player.getMaxHealth() << " | STA: " << PLAYER_Player.getStamina() << "/" << PLAYER_Player.getMaxStamina() << endl << endl;
				if (PLAYER_Player.isLevelUp())
				{
					// Increase a chosen Attribute
					string STR_Attribute_Choice = "";
					while (STR_Attribute_Choice != "Strength" && STR_Attribute_Choice != "Magic" && STR_Attribute_Choice != "Endurance")
					{
						cout << "\n   Choose an Attribute to Increment\n.  Strength:  ";
						for (int i = 0; i < PLAYER_Player.getPlayerAttributes().find("Strength")->second; i++)
						{
							cout << "|";
						}
						cout << "\n.  Magic:     ";
						for (int i = 0; i < PLAYER_Player.getPlayerAttributes().find("Magic")->second; i++)
						{
							cout << "|";
						}
						cout << "\n.  Endurance: ";
						for (int i = 0; i < PLAYER_Player.getPlayerAttributes().find("Endurance")->second; i++)
						{
							cout << "|";
						}
						cout << "\n\n   > ";
						getline(cin, STR_Attribute_Choice);
					}
					cout << "\n   You added 2 points to " << STR_Attribute_Choice << endl << endl << "   ";
					PLAYER_Player.setPlayerAttribute(STR_Attribute_Choice, (PLAYER_Player.getPlayerAttributes().find(STR_Attribute_Choice)->second + 2));
					PLAYER_Player.notLevelUp();
					this_thread::sleep_for(chrono::seconds(2));
				}
			}
			PLAYER_Player.update();
			system("pause");
			system("CLS");
			battle = false;
			play_audio(DUNGEON_Current_Dungeon->getDungeonName() + " F" + to_string(DUNGEON_Current_Dungeon->getDungeonRoom()));
		}
		else
		{
			while (!BOOL_Player_Turn)
			{
				this_thread::sleep_for(chrono::seconds(3));
				system("CLS");
				show_battle_stats(PLAYER_Player);
				cout << "\n   " << ENEMY_Enemy.getName() << "'s turn...";
				this_thread::sleep_for(chrono::seconds(2));
				system("CLS");
				show_battle_stats(PLAYER_Player);
				ENEMY_Enemy.update(PLAYER_Player);
				cout << ENEMY_Enemy.getTurnPhrase();
				this_thread::sleep_for(chrono::seconds(1));
				system("CLS");
				show_battle_stats(PLAYER_Player);
				cout << ENEMY_Enemy.getTurnPhrase();
				this_thread::sleep_for(chrono::seconds(2));
				BOOL_Player_Turn = true;
				break;
			}
		}
		if (!battle) break;
	}
}

// Play Music
void play_audio(string to_play)
{
	if (to_play == "Menu")
	{
		PlaySound(TEXT("music/main_menu.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Glacier Wasteland F1")
	{
		PlaySound(TEXT("music/glacier_floor_1.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Glacier Wasteland F2")
	{
		PlaySound(TEXT("music/glacier_floor_2.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Glacier Wasteland F3")
	{
		PlaySound(TEXT("music/glacier_floor_3.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Glacier Wasteland F4")
	{
		PlaySound(TEXT("music/glacier_floor_4.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Glacier Wasteland F5")
	{
		PlaySound(TEXT("music/glacier_floor_6.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Glacier Wasteland F6" || to_play == "Atlantis Ruins F7")
	{
		PlaySound(TEXT("music/dungeon_final_floor.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Atlantis Ruins F1" || to_play == "Atlantis Ruins F2" || to_play == "Atlantis Ruins F3" || to_play == "Atlantis Ruins F4")
	{
		PlaySound(TEXT("music/atlantis_above_floors.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Atlantis Ruins F5" || to_play == "Atlantis Ruins F6")
	{
		PlaySound(TEXT("music/atlantis_below_floors.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Facility F1" || to_play == "Facility F2" || to_play == "Facility F3" || to_play == "Facility F4")
	{
		PlaySound(TEXT("music/facility_below_floors.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Dungeon Battle")
	{
		PlaySound(TEXT("music/dungeon_battle_custom.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Dungeon Mini Boss")
	{
		PlaySound(TEXT("music/dungeon_mini_boss.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Dungeon Main Boss")
	{
		PlaySound(TEXT("music/dungeon_main_boss.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Victory")
	{
		PlaySound(TEXT("music/victory.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Encounter")
	{
		PlaySound(TEXT("music/encounter.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Macko Fight")
	{
		PlaySound(TEXT("music/macko_fight.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
}

// Converts strings to LOWERCASE
string convert_string_tolower(string text)
{
	string converted_text;
	for (char& c : text)
	{
		c = tolower(static_cast<unsigned char>(c));
		converted_text += c;
	}
	return converted_text;
}

// Converts strings to UPPERCASE
string convert_string_toupper(string text)
{
	string converted_text;
	for (char& c : text)
	{
		c = toupper(static_cast<unsigned char>(c));
		converted_text += c;
	}
	return converted_text;
}

// This function acts upon the player input whilst dungeon exploring
void dialogue_input(Player& PLAYER_Player, string STR_Dialogue_Choice, vector<Dungeon*> VEC_Visited_Dungeons, Dungeon* &DUNGEON_Current_Dungeon)
{
	// Displays the Help menu
	if (STR_Dialogue_Choice == "/help")
	{ 
		// Displays full list of commands
		system("CLS");
		cout <<
			"\n   /help      : Displays this menu!" <<
			"\n\n   items      : Displays all of your items + melee weapon" <<
			"\n\n   stats      : Displays your stats" <<
			"\n\n   travel     : Quick travel between dungeons" <<
			"\n\n   debugfight : Initiate a fight at Lv 99 for testing purposes\n\n";
		system("pause");
		cout << "\033[A" << "\33[2K\r" << endl;
	}

	// Displays the Item menu
	else if (STR_Dialogue_Choice == "items")
	{
		string STR_Item_Page = "all";
		while (STR_Dialogue_Choice == "items")
		{
			system("CLS");
			cout << "\n   " << PLAYER_Player.getName() << "'s Inventory\n";
			cout << "   [ " << convert_string_toupper(STR_Item_Page) << " ] ";
			vector<int> VEC_Rarity_Numbers = { 0, 0, 0, 0, 0 };

			// Displays all parent Item and child Item objects
			if (STR_Item_Page == "all")
			{
				// Calculates how many items of each Rarity
				for (int i = 1; i < 6; i++)
				{
					for (Item* ITEM_Item : PLAYER_Player.getItems())
					{
						if (ITEM_Item->getRarity() == i)
						{
							VEC_Rarity_Numbers[(i - 1)] = VEC_Rarity_Numbers[(i - 1)] + ITEM_Item->getQuantity();
						}
					}
				}
				cout << "[ " << VEC_Rarity_Numbers[0] << " (1*) | " << VEC_Rarity_Numbers[1] << " (2*) | " << VEC_Rarity_Numbers[2] << " (3*) | " << VEC_Rarity_Numbers[3] << " (4*) | " << VEC_Rarity_Numbers[4] << " (5*) ]\n\n";

				// Outputs the objects sorted by Rarity
				for (int i = 1; i < 6; i++)
				{
					for (Item* ITEM_Item : PLAYER_Player.getItems())
					{
						if (ITEM_Item->getRarity() == i)
						{
							ITEM_Item->toString();
							if (ITEM_Item->getName() == PLAYER_Player.getMeleeWeapon().getName() && ITEM_Item->getMeleeDamage() == PLAYER_Player.getMeleeWeapon().getMeleeDamage())
							{
								cout << "   [Equipped]";
							}
							cout << "\n\n";
						}
					}
				}
			}

			// Displays all ItemMelee objects
			else if (STR_Item_Page == "weapons")
			{
				// Calculates how many items of each Rarity
				for (int i = 1; i < 6; i++)
				{
					for (Item* ITEM_Item : PLAYER_Player.getItems())
					{
						if (ITEM_Item->getRarity() == i && ITEM_Item->isMeleeWeapon())
						{
							VEC_Rarity_Numbers[(i - 1)] = VEC_Rarity_Numbers[(i - 1)] + ITEM_Item->getQuantity();
						}
					}
				}
				cout << "[ " << VEC_Rarity_Numbers[0] << " (1*) | " << VEC_Rarity_Numbers[1] << " (2*) | " << VEC_Rarity_Numbers[2] << " (3*) | " << VEC_Rarity_Numbers[3] << " (4*) | " << VEC_Rarity_Numbers[4] << " (5*) ]\n\n";

				// Outputs the objects sorted by Rarity
				for (int i = 1; i < 6; i++)
				{
					for (Item* ITEM_Item : PLAYER_Player.getItems())
					{
						if (ITEM_Item->getRarity() == i && ITEM_Item->isMeleeWeapon())
						{
							ITEM_Item->toString();
							if (ITEM_Item->getName() == PLAYER_Player.getMeleeWeapon().getName() && ITEM_Item->getMeleeDamage() == PLAYER_Player.getMeleeWeapon().getMeleeDamage())
							{
								cout << "   [Equipped]";
							}
							cout << "\n\n";
						}
					}
				}
				cout << "   To change weapons, type '(Atk):(Weapon Name)'\n";
			}

			// Displays all ItemConsumable objects
			else if (STR_Item_Page == "consumables")
			{
				// Calculates how many items of each Rarity
				for (int i = 1; i < 6; i++)
				{
					for (Item* ITEM_Item : PLAYER_Player.getItems())
					{
						if (ITEM_Item->getRarity() == i && ITEM_Item->isConsumable())
						{
							VEC_Rarity_Numbers[(i - 1)] = VEC_Rarity_Numbers[(i - 1)] + ITEM_Item->getQuantity();
						}
					}
				}
				cout << "[ " << VEC_Rarity_Numbers[0] << " (1*) | " << VEC_Rarity_Numbers[1] << " (2*) | " << VEC_Rarity_Numbers[2] << " (3*) | " << VEC_Rarity_Numbers[3] << " (4*) | " << VEC_Rarity_Numbers[4] << " (5*) ]\n\n";

				// Outputs the objects sorted by Rarity
				for (int i = 1; i < 6; i++)
				{
					for (Item* ITEM_Item : PLAYER_Player.getItems())
					{
						if (ITEM_Item->getRarity() == i && ITEM_Item->isConsumable())
						{
							ITEM_Item->toString();
							cout << endl << endl;
						}
					}
				}
			}

			// Displays all ItemSkill objects
			else if (STR_Item_Page == "skills")
			{
				// Calculates how many items of each Rarity
				for (int i = 1; i < 6; i++)
				{
					for (Item* ITEM_Item : PLAYER_Player.getItems())
					{
						if (ITEM_Item->getRarity() == i && ITEM_Item->canInheritSkill())
						{
							VEC_Rarity_Numbers[(i - 1)] = VEC_Rarity_Numbers[(i - 1)] + ITEM_Item->getQuantity();
						}
					}
				}
				cout << "[ " << VEC_Rarity_Numbers[0] << " (1*) | " << VEC_Rarity_Numbers[1] << " (2*) | " << VEC_Rarity_Numbers[2] << " (3*) | " << VEC_Rarity_Numbers[3] << " (4*) | " << VEC_Rarity_Numbers[4] << " (5*) ]\n\n";

				// Outputs the objects sorted by Rarity
				for (int i = 1; i < 6; i++)
				{
					for (Item* ITEM_Item : PLAYER_Player.getItems())
					{
						if (ITEM_Item->getRarity() == i && ITEM_Item->canInheritSkill())
						{
							ITEM_Item->toString();
							for (int i = 0; i < PLAYER_Player.getSkills().size(); i++)
							{
								if (ITEM_Item->getSkill().getName() == PLAYER_Player.getSkills()[i].getName())
								{
									cout << "   [" << (i + 1) << "]";
								}
							}
							cout << "\n\n";
						}
					}
				}
				if (PLAYER_Player.getSkills().size() == 8)
				{
					cout << "   To change skills, type '(1-8):(Skill Name)'\n";
				}
			}

			// Displays all Item parent objects
			else if (STR_Item_Page == "items")
			{
				for (int i = 1; i < 6; i++)
				{
					for (Item* ITEM_Item : PLAYER_Player.getItems())
					{
						if (ITEM_Item->getRarity() == i && !ITEM_Item->canInheritSkill() && !ITEM_Item->isConsumable() && !ITEM_Item->isMeleeWeapon())
						{
							VEC_Rarity_Numbers[(i - 1)] = VEC_Rarity_Numbers[(i - 1)] + ITEM_Item->getQuantity();
						}
					}
				}
				cout << "[ " << VEC_Rarity_Numbers[0] << " (1*) | " << VEC_Rarity_Numbers[1] << " (2*) | " << VEC_Rarity_Numbers[2] << " (3*) | " << VEC_Rarity_Numbers[3] << " (4*) | " << VEC_Rarity_Numbers[4] << " (5*) ]\n\n";
				for (int i = 1; i < 6; i++)
				{
					for (Item* ITEM_Item : PLAYER_Player.getItems())
					{
						if (ITEM_Item->getRarity() == i && !ITEM_Item->canInheritSkill() && !ITEM_Item->isConsumable() && !ITEM_Item->isMeleeWeapon())
						{
							ITEM_Item->toString();
							cout << endl << endl;
						}
					}
				}
			}

			// Takes player input to determine which page to display, or to back out of the Items menu enirely
			cout << "   > ";
			string STR_Items_Input;
			getline(cin, STR_Items_Input);
			STR_Item_Page = convert_string_tolower(STR_Items_Input);

			if (STR_Items_Input == "return") break;

			// Checks to see if player switches skills
			// ex:   5:Healan
			int TEMP_Skill_Placement = (STR_Items_Input[0] - 48);
			if ((TEMP_Skill_Placement > 0 && TEMP_Skill_Placement < 9) && PLAYER_Player.getSkills().size() == 8)
			{
				string TEMP_Skill_Name = "";
				for (int i = 2; i < STR_Items_Input.size(); i++)
				{
					TEMP_Skill_Name += STR_Items_Input[i];
				}
				// Checks if the input is Valid
				Skill TEMP_Skill = Skill(TEMP_Skill_Name);
				if (TEMP_Skill.isValid())
				{
					// Swap skills at PLAYER_Player: VEC_Skills[TEMP_Skill_Placement] with TEMP_Skill
					PLAYER_Player.swapSkill(TEMP_Skill_Placement, TEMP_Skill);
					STR_Item_Page = "skills";
				}
			}

			// Checks to see if player switches melee
			STR_Items_Input = convert_string_tolower(STR_Items_Input);
			string TEMP_Damage_Input = "";
			for (int i = 0; i < STR_Items_Input.length(); i++)
			{
				if (STR_Items_Input[i] == ':') break;
				TEMP_Damage_Input += STR_Items_Input[i];
			}
			string TEMP_Melee_Name = "";
			for (int i = STR_Items_Input.length() - 1; i > 0; i--)
			{
				if (STR_Items_Input[i] == ':') break;
				TEMP_Melee_Name = STR_Items_Input[i] + TEMP_Melee_Name;
			}
			for (Item* ITEM_Item : PLAYER_Player.getItems())
			{
				if (ITEM_Item->isMeleeWeapon() && convert_string_tolower(ITEM_Item->getName()) == TEMP_Melee_Name && ITEM_Item->getMeleeDamage() == stoi(TEMP_Damage_Input))
				{
					ItemMelee ITEM_MELEE_Equipping = ItemMelee(ITEM_Item->getName(), ITEM_Item->getDesc(), ITEM_Item->getRarity(), ITEM_Item->getMeleeDamage(), false);
					if (ITEM_Item->hasModifiedAttribute())
					{
						ITEM_MELEE_Equipping.setAttributeType(ITEM_Item->getAttributeType(), ITEM_Item->getBonusValue());
					}
					else if (ITEM_Item->hasElementCoverage())
					{
						ITEM_MELEE_Equipping.setElementalType(ITEM_Item->getElementalType(), ITEM_Item->getBonusValue());
					}
					PLAYER_Player.setMelee(ITEM_MELEE_Equipping);
					STR_Item_Page = "weapons";
					break;
				}
			}

			if (STR_Item_Page != "weapons" && STR_Item_Page != "consumables" && STR_Item_Page != "skills" && STR_Item_Page != "items")
			{
				STR_Item_Page = "all";
			}
		}
	}

	// Displays the Player Stat's menu
	else if (STR_Dialogue_Choice == "stats")
	{
		system("CLS");
		cout << "\n   " << PLAYER_Player.getName() << "\n";
		PLAYER_Player.getPlayerStats();
		PLAYER_Player.getPlayerElements();
		cout << "\n.  St: ";
		for (int i = 0; i < PLAYER_Player.getPlayerAttributes().find("Strength")->second; i++)
		{
			cout << "|";
		}
		cout << "\n.  Ma: ";
		for (int i = 0; i < PLAYER_Player.getPlayerAttributes().find("Magic")->second; i++)
		{
			cout << "|";
		}
		cout <<  "\n.  En: ";
		for (int i = 0; i < PLAYER_Player.getPlayerAttributes().find("Endurance")->second; i++)
		{
			cout << "|";
		}
		cout << endl << endl;
		cout << "   Equipped Skills:";
		for (int i = 0; i < PLAYER_Player.getSkills().size(); i++)
		{
			cout << "\n   " << dye::light_purple(PLAYER_Player.getSkills()[i].getName());
		}
		cout << "\n\n   Equipped Melee:\n";
		PLAYER_Player.getMeleeWeapon().toString();
		cout << endl << endl;
		system("pause");
		cout << "\033[A" << "\33[2K\r" << endl;
	}

	// Displays the Travel menu
	else if (STR_Dialogue_Choice == "travel")
	{
		// Checks to see if any dungeons have been completed
		// Travelling unlocks after completing Dungeon 1
		if (VEC_Visited_Dungeons.size() == 0)
		{
			cout << "\033[A" << "\33[2K\r" << endl;
			cout << "   You have explored no other places...";
			this_thread::sleep_for(chrono::seconds(2));
		}
		else
		{
			system("CLS");
			bool BOOL_Is_Valid_Travel = false;
			int INDEX_Dungeon;
			string STR_Dungeon_Choice;
			// Validation
			while (!BOOL_Is_Valid_Travel)
			{
				system("CLS");
				cout << "\n   Where would you like to go?\n\n";

				// Outputs each dungeon name
				for (Dungeon* DUNGEON_Dungeon : VEC_Visited_Dungeons)
				{
					cout << ".  " << DUNGEON_Dungeon->getDungeonName() << " (F" << DUNGEON_Dungeon->getDungeonRoom() << ")" << endl;
				}
				cout << "\n   > ";
				getline(cin, STR_Dungeon_Choice);
				INDEX_Dungeon = 0;
				for (Dungeon* DUNGEON_Dungeon : VEC_Visited_Dungeons)
				{
					if (convert_string_tolower(STR_Dungeon_Choice) == convert_string_tolower(DUNGEON_Dungeon->getDungeonName()))
					{
						// Updates the Current Dungeon from the Vector
						BOOL_Is_Valid_Travel = true;
						VEC_Visited_Dungeons[INDEX_Dungeon] = DUNGEON_Current_Dungeon;
						// Sets the Current Dungeon to the one chosen from the Vector
						DUNGEON_Current_Dungeon = DUNGEON_Dungeon;
						system("CLS");
						cout << "\n   Travelling to " << DUNGEON_Dungeon->getDungeonName();
						this_thread::sleep_for(chrono::seconds(2));
						play_audio(DUNGEON_Current_Dungeon->getDungeonName() + " F" + to_string(DUNGEON_Current_Dungeon->getDungeonRoom()));
						break;
					}
					INDEX_Dungeon++;
				}
			}
		}
	} 
	
	// Initiates a secret fight against the creator
	else if (STR_Dialogue_Choice == "debugfight")
	{
		Enemy TEMP_New_Enemy = Enemy("Macko", 99, 2000, 500, { Skill("Flamadia"), Skill("Freezadia"), Skill("Zapadia"), Skill("Gustadia"), Skill("Hexaon"), Skill("Blightaon"), Skill("Eye of the 'Berg"), Skill("Eye of the Storm") }, new ItemSkill("???", "I actually don't know what this is.", 5, Skill("Hex of Death")), true, 218);
		PLAYER_Player.setSkills({ Skill("Flamadia"), Skill("Splashadia"), Skill("Freezadia"), Skill("Zapadia"), Skill("Gustadia"), Skill("Hexaon"), Skill("Blightaon"), Skill("Freiladia"), Skill("Healadia") });
		PLAYER_Player.setMelee(ItemMelee("Sword of Lost Histories", "Only true completionists have found this relic", 5, 304, true));
		PLAYER_Player.setLevelStats(99, 826, 454);
		play_audio("Macko Fight");
		system("pause");
		battle(PLAYER_Player, DUNGEON_Current_Dungeon, TEMP_New_Enemy);
	}
	else
	{
		cout << "\033[A" << "\33[2K\r" << endl;
	}
}

// Sets the starting elements for the Player: 1 Weak and 1 Resistant
void set_starting_elements(int& weak_element, int& resist_element)
{
	bool BOOL_Valid_Option = false;
	vector<string> VEC_List_Of_Elements = { "Fire", "Water", "Ice", "Electric", "Wind", "Curse", "Bless"};
	string inp_we, inp_re;
	while (true)
	{
		cout << "\n   Choose an element to be weak to:\n   Fire, Water, Ice, Electric, Wind, Curse, Bless\n   > "; cin >> inp_we;
		for (string element : VEC_List_Of_Elements)
		{
			if (inp_we == element)
			{
				BOOL_Valid_Option = true;
			}
		}
		if (BOOL_Valid_Option) break;
	}
	if (inp_we == "Fire")
	{
		weak_element = 0;
	}
	else if (inp_we == "Water")
	{
		weak_element = 1;
	}
	else if (inp_we == "Ice")
	{
		weak_element = 2;
	}
	else if (inp_we == "Electric")
	{
		weak_element = 3;
	}
	else if (inp_we == "Wind")
	{
		weak_element = 4;
	}
	else if (inp_we == "Curse")
	{
		weak_element = 5;
	}
	else if (inp_we == "Bless")
	{
		weak_element = 6;
	}

	BOOL_Valid_Option = false;
	while (true)
	{
		cout << "\n   Choose an element to be resistant to:\n   Fire, Water, Ice, Electric, Wind, Curse, Bless   \n   > "; cin >> inp_re;
		for (string element : VEC_List_Of_Elements)
		{
			if (inp_re == element)
			{
				BOOL_Valid_Option = true;
			}
		}
		if (BOOL_Valid_Option) break;
	}
	if (inp_re == "Fire")
	{
		resist_element = 0;
	}
	else if (inp_re == "Water")
	{
		resist_element = 1;
	}
	else if (inp_re == "Ice")
	{
		resist_element = 2;
	}
	else if (inp_re == "Electric")
	{
		resist_element = 3;
	}
	else if (inp_re == "Wind")
	{
		resist_element = 4;
	}
	else if (inp_re == "Curse")
	{
		resist_element = 5;
	}
	else if (inp_re == "Bless")
	{
		resist_element = 6;
	}
}

// Outputs Enemy's name, HP, STA and Elements
void show_enemy_stats(Enemy ENEMY_Enemy)
{
	cout << "\n   " << ENEMY_Enemy.getName() << " (Lv " << ENEMY_Enemy.getLevel() << ")" << endl;
	cout << "   HP: " << ENEMY_Enemy.getHealth() << " | STA: " << ENEMY_Enemy.getStamina() << endl << endl << endl;
	vector<string> VEC_Element_Names = { "Fire", "Water", "Ice", "Electric", "Wind", "Curse", "Bless"};
	for (int i = 0; i < 7; i++)
	{
		cout << ".  " << VEC_Element_Names[i] << ": " << ENEMY_Enemy.getElements().find(VEC_Element_Names[i])->second << "\n";
	}
}

// Outputs Player's name, HP and STA
void show_battle_stats(Player PLAYER_Player)
{
	system("CLS");
	cout << "\n   " << dye::grey_on_white(" ") << dye::grey_on_white(PLAYER_Player.getName()) << dye::grey_on_white(" ");
	cout << dye::light_green("\n   HP: ") << dye::light_green(PLAYER_Player.getHealth()) << dye::light_green(" / ") << dye::light_green(PLAYER_Player.getMaxHealth()) << " | " << dye::light_aqua("STA: ") << dye::light_aqua(PLAYER_Player.getStamina()) << dye::light_aqua(" / ") << dye::light_aqua(PLAYER_Player.getMaxStamina()) << endl << endl;
}

// Outputs a specific Skill whilst in battle
void show_skill(Player PLAYER_Player, int INDEX_Skill)
{
	vector<Skill> TEMP_Player_Skills = PLAYER_Player.getSkills();
	cout << "--> " << convert_string_toupper(TEMP_Player_Skills[INDEX_Skill].getName()) << endl;
	cout << "    Type: " << TEMP_Player_Skills[INDEX_Skill].getType() << endl;
	cout << "    Desc: " << TEMP_Player_Skills[INDEX_Skill].getDesc() << endl;
	cout << "    STA: " << TEMP_Player_Skills[INDEX_Skill].getStaminaCost() << endl;
	if (TEMP_Player_Skills[INDEX_Skill].getName() == "Heal" || TEMP_Player_Skills[INDEX_Skill].getName() == "Healan" || TEMP_Player_Skills[INDEX_Skill].getName() == "Healadia")
	{
		cout << "    HP+: " << TEMP_Player_Skills[INDEX_Skill].getHPGain() << endl;
	}
	else
	{
		cout << "    DMG: " << TEMP_Player_Skills[INDEX_Skill].getBaseDamage() << endl;
	}
	cout << "    [Skill " << (INDEX_Skill + 1) << " of " << TEMP_Player_Skills.size() << "]";
}

