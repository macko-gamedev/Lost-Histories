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
#include "DungeonMagma.h"
#include "DungeonSpecial.h"
#include "DungeonDomain.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <Windows.h>
#include "mmsystem.h"
#include <conio.h>
#include <map>
#include <fstream>
#include "include/dirent.h"
#include "include/color.hpp"
#include <cstring>
#pragma comment(lib, "winmm.lib")

using namespace std;

/* 

###### LOST HISTORIES ######
Last Updated: 21/05/26 (20:27)

--- Parent Classes ---
. BattleStat	 # Contains key variables to battles such as health and stamina values
				 : Player, Enemy
. Item			 # Contains name, description and rarity of an item
                 : ItemMelee, ItemSkill, ItemConsumable
. Dungeon        # Contains name, floor number
				 : DungeonGlacier, DungeonAtlantis, DungeonFacility, Dungeon Magma, DungeonSpecial

--- Child Classes ---
. Enemy		      : Inherits BattleStat
. DungeonAtlantis : Inherits Dungeon, dungeon 2 of the game
. DungeonFacility : Inherits Dungeon, dungeon 3 of the game
. DungeonGlacier  : Inherits Dungeon, dungeon 1 of the game
. DungeonMagma    : Inherits Dungeon, dungeon 4 of the game
. DungeonSpecial  : Inherits Dungeon, dungeon 5 of the game
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
	ACT_FOUR,
	ACT_FIVE,
	ACT_SIX,
	ACT_SEVEN,
	COMPLETE,
	TRUE_ONE,
	TRUE_TWO,
	TRUE_COMPLETE,
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
void show_enemy_stats(Enemy ENEMY_Enemy); // Shows the ENEMY_Enemy's battle stats
void show_skill(Player PLAYER_Player, int INDEX_Skill, Enemy ENEMY_Enemy); // Shows the PLAYER_Player's current skill
vector<string> main_menu(); // Main menu when the game is executed
void battle(Player& PLAYER_Player, Dungeon* DUNGEON_Current_Dungeon, Enemy ENEMY_Enemy); // Battle sequence
void map_movement(char CHAR_Movement, Player& PLAYER_Player, Enemy& ENEMY_New_Enemy, Dungeon* DUNGEON_Current_Dungeon, storyStatus& ENUM_Story_Status, gameStatus& ENUM_Game_Status, Story& STORY_Story); // Map Movement
void open_chest(Player& PLAYER_Player, Dungeon* DUNGEON_Current_Dungeon); // Open chests
void play_audio(string to_play); // Plays music
void menuItems(Player& PLAYER_Player);
void menuStats(Player PLAYER_Player);
void menuTravel(vector<Dungeon*>& VEC_Visited_Dungeons, Dungeon*& DUNGEON_Current_Dungeon);
void saveGame(Player PLAYER_Player, vector<Dungeon*> VEC_Visited_Dungeons);
void closeGame();


/* ---------------------------------------------------------------------------------------------------- */

// MAIN PROGRAM
int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	vector<string> VEC_Save_Data = main_menu();
	system("CLS");

	// Declaring Enums
	storyStatus ENUM_Story_Status = storyStatus::INTRO;
	gameStatus ENUM_Game_Status = gameStatus::DIALOGUE;

	// Instantiates object of type Dungeon
	Dungeon* DUNGEON_Current_Dungeon = NULL;
	vector<Dungeon*> VEC_Visited_Dungeons = { };

	// Instantiates object of type Enemy
	Enemy ENEMY_New_Enemy;
	Player PLAYER_Player;
	string STR_Player_Name; 

	// Instantiates object of type Story
	Story STORY_Story;
	string STR_Intro_Choice = "";
	string STR_Dialogue_Choice;

	// NEW GAME
	if (VEC_Save_Data[0] == "NONE")
	{
		// Setting up the Player
		cout << "\n   Your Character Name: ";
		getline(cin, STR_Player_Name);
		
		// Instantiates object of type Player
		PLAYER_Player = Player(STR_Player_Name, 1, 140, 62);
		STORY_Story = Story(PLAYER_Player.getName());
		PLAYER_Player.setLevelXP(0, 0, 22);
		PLAYER_Player.setStartingElements();

		string STR_Intro_Choice = "";
		ENUM_Game_Status = gameStatus::DIALOGUE;
		ENUM_Story_Status = storyStatus::INTRO;
		while (STR_Intro_Choice != "y" && STR_Intro_Choice != "n")
		{
			system("CLS");
			cout << "\n   You are playing Release 1.1\n   . This build includes all 4 main dungeons + 1 special dungeon on completion\n   . Please note that this version is still in development and may contain issues\n\n   . Try and break the game if you feel like it\n\n   This game through self playtest may be challenging, would you like to add a insta-kill skill in battle? [y]/[n]\n   > ";
			getline(cin, STR_Intro_Choice);
			if (STR_Intro_Choice == "y")
			{
				PLAYER_Player.addItem(new ItemSkill("Get Out Of Jail Free Card", "Incase you need it", 5, Skill("Death"))); break;
			}
			if (STR_Intro_Choice == "n") break;
		}
		cout << "\n\n   ! For dialogue scenes, press ENTER to advance\n   ! Whilst dungeon exploring, press SPACE to make an input\n\n   ? Recommended Levels:\n   Dungeon 1: Lv 1-20, Dungeon 2: Lv 20-40, Dungeon 3: Lv 40-65, Dungeon 4: Lv 65+, Final Boss on Dungeon 4: Lv 85+\n\n   Have Fun!\n\n\n   ";
		system("pause");
		system("CLS");
	}
	// LOAD GAME
	else
	{
		PLAYER_Player = Player(VEC_Save_Data[0], stoi(VEC_Save_Data[3]), stoi(VEC_Save_Data[1]), (stoi(VEC_Save_Data[2])));
		cout << dye::blue("\n   Transferring save file data to Player()");
		STORY_Story = Story(PLAYER_Player.getName());
		PLAYER_Player.loadData(VEC_Save_Data); 
		ENUM_Game_Status = gameStatus::DUNGEON;
		for (int i = 0; i < VEC_Save_Data.size(); i++)
		{
			if (VEC_Save_Data[i] == "Glacier Wasteland")
			{
				cout << dye::blue("\n   Loading dungeon: " + VEC_Save_Data[i]);
				DUNGEON_Current_Dungeon = new DungeonGlacier(PLAYER_Player.getName());
				DUNGEON_Current_Dungeon->fillWithChests();
				DUNGEON_Current_Dungeon->fillWithEnemies();
				DUNGEON_Current_Dungeon->changeDungeonRoom(stoi(VEC_Save_Data[(i + 1)]) - 1);
				VEC_Visited_Dungeons.push_back(DUNGEON_Current_Dungeon);
				ENUM_Story_Status = storyStatus::ACT_ONE;
				STORY_Story.endOfDialogue();
				cout << dye::blue("\n   Sucessfully loaded dungeon: " + VEC_Save_Data[i]);
			}
			else if (VEC_Save_Data[i] == "Atlantis Ruins")
			{
				cout << dye::blue("\n   Loading dungeon: " + VEC_Save_Data[i]);
				DUNGEON_Current_Dungeon = new DungeonAtlantis(PLAYER_Player.getName());
				DUNGEON_Current_Dungeon->fillWithChests();
				DUNGEON_Current_Dungeon->fillWithEnemies();
				DUNGEON_Current_Dungeon->changeDungeonRoom(stoi(VEC_Save_Data[(i + 1)]) - 1);
				VEC_Visited_Dungeons.push_back(DUNGEON_Current_Dungeon);
				ENUM_Story_Status = storyStatus::ACT_TWO;
				STORY_Story.endOfDialogue();
				cout << dye::blue("\n   Sucessfully loaded dungeon: " + VEC_Save_Data[i]);
			}
			else if (VEC_Save_Data[i] == "Facility")
			{
				cout << dye::blue("\n   Loading dungeon: " + VEC_Save_Data[i]);
				DUNGEON_Current_Dungeon = new DungeonFacility(PLAYER_Player.getName());
				DUNGEON_Current_Dungeon->fillWithChests();
				DUNGEON_Current_Dungeon->fillWithEnemies();
				DUNGEON_Current_Dungeon->changeDungeonRoom(stoi(VEC_Save_Data[(i + 1)]) - 1);
				VEC_Visited_Dungeons.push_back(DUNGEON_Current_Dungeon);
				ENUM_Story_Status = storyStatus::ACT_THREE;
				STORY_Story.endOfDialogue();
				cout << dye::blue("\n   Sucessfully loaded dungeon: " + VEC_Save_Data[i]);
			}
			else if (VEC_Save_Data[i] == "Magma Fields")
			{
				cout << dye::blue("\n   Loading dungeon: " + VEC_Save_Data[i]);
				DUNGEON_Current_Dungeon = new DungeonMagma(PLAYER_Player.getName());
				DUNGEON_Current_Dungeon->fillWithChests();
				DUNGEON_Current_Dungeon->fillWithEnemies();
				DUNGEON_Current_Dungeon->changeDungeonRoom(stoi(VEC_Save_Data[(i + 1)]) - 1);
				VEC_Visited_Dungeons.push_back(DUNGEON_Current_Dungeon);
				ENUM_Story_Status = storyStatus::ACT_FIVE;
				STORY_Story.endOfDialogue();
				cout << dye::blue("\n   Sucessfully loaded dungeon: " + VEC_Save_Data[i]);
			}
			else if (VEC_Save_Data[i] == "Special Passage")
			{
				cout << dye::blue("\n   Loading dungeon: " + VEC_Save_Data[i]);
				DUNGEON_Current_Dungeon = new DungeonSpecial(PLAYER_Player.getName());
				DUNGEON_Current_Dungeon->fillWithChests();
				DUNGEON_Current_Dungeon->fillWithEnemies();
				DUNGEON_Current_Dungeon->changeDungeonRoom(stoi(VEC_Save_Data[(i + 1)]) - 1);
				VEC_Visited_Dungeons.push_back(DUNGEON_Current_Dungeon);
				ENUM_Story_Status = storyStatus::COMPLETE;
				STORY_Story.endOfDialogue();
				cout << dye::blue("\n   Sucessfully loaded dungeon: " + VEC_Save_Data[i]);
			}
			else if (VEC_Save_Data[i] == "Domain")
			{
				cout << dye::blue("\n   Loading dungeon: " + VEC_Save_Data[i]);
				DUNGEON_Current_Dungeon = new DungeonDomain(PLAYER_Player.getName());
				DUNGEON_Current_Dungeon->fillWithChests();
				DUNGEON_Current_Dungeon->fillWithEnemies();
				DUNGEON_Current_Dungeon->changeDungeonRoom(stoi(VEC_Save_Data[(i + 1)]) - 1);
				VEC_Visited_Dungeons.push_back(DUNGEON_Current_Dungeon);
				ENUM_Story_Status = storyStatus::TRUE_ONE;
				STORY_Story.endOfDialogue();
				cout << dye::blue("\n   Sucessfully loaded dungeon: " + VEC_Save_Data[i]);
			}
		}
		reverse(VEC_Visited_Dungeons.begin(), VEC_Visited_Dungeons.end());
		DUNGEON_Current_Dungeon = VEC_Visited_Dungeons[VEC_Visited_Dungeons.size() - 1];
		cout << dye::green("\n   Loaded save file completed");
		this_thread::sleep_for(chrono::seconds(1));
	}

	// Main Gameplay Loop
	while (true)
	{
		while (ENUM_Game_Status == gameStatus::DIALOGUE)
		{
			cout << "\n   " << STORY_Story.getDialogue() << endl;
			STORY_Story.increaseDialogueIndex();
			if (STORY_Story.getDialogue() == "END DIALOGUE")
			{
				STORY_Story.endOfDialogue();
			}
			_getch();

			if (STORY_Story.isEvent())
			{
				// INTRO -> Dungeon 1: Glacier Wasteland
				if (ENUM_Story_Status == storyStatus::INTRO)
				{
					ENUM_Game_Status = gameStatus::BATTLE;
					DUNGEON_Current_Dungeon = new DungeonGlacier(PLAYER_Player.getName());
					DUNGEON_Current_Dungeon->fillWithEnemies();
					DUNGEON_Current_Dungeon->fillWithChests();
					VEC_Visited_Dungeons.push_back(DUNGEON_Current_Dungeon);
					ENEMY_New_Enemy = Enemy("Ice Monster", 1, 10, 24, { Skill("Freeze") }, false, 12);
					play_audio("Story Battle");
					battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);
					ENUM_Story_Status = storyStatus::ACT_ONE;
					ENUM_Game_Status = gameStatus::DUNGEON;
					STORY_Story.startOfDialogue();
					STORY_Story.increaseDialogueIndex();
				}
				// Dungeon 1 -> Dungeon 2: Atlantis Ruins
				else if (ENUM_Story_Status == storyStatus::ACT_TWO)
				{
					DUNGEON_Current_Dungeon->fillWithEnemies();
					DUNGEON_Current_Dungeon->fillWithChests();
					VEC_Visited_Dungeons.push_back(DUNGEON_Current_Dungeon);
					DUNGEON_Current_Dungeon = new DungeonAtlantis(PLAYER_Player.getName());
					DUNGEON_Current_Dungeon->fillWithEnemies();
					DUNGEON_Current_Dungeon->fillWithChests();
					VEC_Visited_Dungeons.push_back(DUNGEON_Current_Dungeon);
					STORY_Story.startOfDialogue();
					STORY_Story.increaseDialogueIndex();
					ENUM_Game_Status = gameStatus::DUNGEON;
				}
				// Dungeon 2 -> Dungeon 3: Facility
				else if (ENUM_Story_Status == storyStatus::ACT_THREE)
				{
					DUNGEON_Current_Dungeon->fillWithEnemies();
					DUNGEON_Current_Dungeon->fillWithChests();
					VEC_Visited_Dungeons[1] = DUNGEON_Current_Dungeon;
					DUNGEON_Current_Dungeon = new DungeonFacility(PLAYER_Player.getName());
					DUNGEON_Current_Dungeon->fillWithEnemies();
					DUNGEON_Current_Dungeon->fillWithChests();
					VEC_Visited_Dungeons.push_back(DUNGEON_Current_Dungeon);
					STORY_Story.startOfDialogue();
					STORY_Story.increaseDialogueIndex();
					ENUM_Game_Status = gameStatus::DUNGEON;
				}
				// Dungeon 3 F7 -> Story Boss Fight: Reincarnation of George Shaw
				else if (ENUM_Story_Status == storyStatus::ACT_FOUR)
				{
					DUNGEON_Current_Dungeon->fillWithEnemies();
					DUNGEON_Current_Dungeon->fillWithChests();
					VEC_Visited_Dungeons[2] = DUNGEON_Current_Dungeon;

					ENEMY_New_Enemy = Enemy("Reincarnation of George Shaw", 65, 1145, 532, { Skill("Flamadia"), Skill("Flamadiaran"), Skill("Zapadia"), Skill("Zapadiaran"), Skill("Hexaon"), Skill("Freiladia"), Skill("Healan") }, false, 60);
					play_audio("Story Battle");
					battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);
					DUNGEON_Current_Dungeon = new DungeonMagma(PLAYER_Player.getName());
					DUNGEON_Current_Dungeon->fillWithEnemies();
					DUNGEON_Current_Dungeon->fillWithChests();
					VEC_Visited_Dungeons.push_back(DUNGEON_Current_Dungeon);
					STORY_Story.startOfDialogue();
					STORY_Story.increaseDialogueIndex();
					ENUM_Story_Status = storyStatus::ACT_FIVE;
					ENUM_Game_Status = gameStatus::DUNGEON;
				}
				// Dungeon 4 -> Story Boss Fight: Mutated Mastermind
				else if (ENUM_Story_Status == storyStatus::ACT_SIX)
				{
					DUNGEON_Current_Dungeon->fillWithEnemies();
					DUNGEON_Current_Dungeon->fillWithChests();
					VEC_Visited_Dungeons[3] = DUNGEON_Current_Dungeon;

					Enemy ENEMY_New_Enemy = Enemy("Mutated Mastermind", 95, 2193, 1948, { Skill("Flamadiaran") }, true, 189);
					play_audio("Boss - The Mastermind Pt 2");
					battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);
					STORY_Story.startOfDialogue();
					STORY_Story.increaseDialogueIndex();
					ENUM_Story_Status = storyStatus::ACT_SEVEN;
					ENUM_Game_Status = gameStatus::DIALOGUE;
					play_audio("Last Confront");
				}
				// Story Boss Fight: Mutated Mastermind -> Story Boss Fight: Keeper of The Device
				else if (ENUM_Story_Status == storyStatus::ACT_SEVEN)
				{
					Enemy ENEMY_New_Enemy = Enemy("Keeper of The Device", 99, 2523, 2092, { Skill("Freiladia") }, true, 201);
					play_audio("Boss - Finale");
					battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);
					STORY_Story.startOfDialogue();
					STORY_Story.increaseDialogueIndex();
					ENUM_Story_Status = storyStatus::COMPLETE;
					ENUM_Game_Status = gameStatus::DIALOGUE;
				}
				// Story Boss Fight: Keeper of The Device -> Dungeon 5: Special Passage, * on Save File
				else if (ENUM_Story_Status == storyStatus::COMPLETE)
				{
					Dungeon* DUNGEON_New = new DungeonSpecial(PLAYER_Player.getName());
					DUNGEON_New->fillWithChests();
					DUNGEON_New->fillWithEnemies();
					VEC_Visited_Dungeons.push_back(DUNGEON_New);
					PLAYER_Player.setSpecificStarOnFile("Main Story", '*');
					ENUM_Game_Status = gameStatus::DUNGEON;
				}
				// Dungeon 3 F10 -> Dungeon 6: Domain
				else if (ENUM_Story_Status == storyStatus::TRUE_ONE)
				{
					DUNGEON_Current_Dungeon->fillWithEnemies();
					DUNGEON_Current_Dungeon->fillWithChests();
					VEC_Visited_Dungeons[2] = DUNGEON_Current_Dungeon;
					DUNGEON_Current_Dungeon = new DungeonDomain(PLAYER_Player.getName());
					DUNGEON_Current_Dungeon->fillWithEnemies();
					DUNGEON_Current_Dungeon->fillWithChests();
					VEC_Visited_Dungeons.push_back(DUNGEON_Current_Dungeon);
					STORY_Story.startOfDialogue();
					STORY_Story.increaseDialogueIndex();
					ENUM_Game_Status = gameStatus::DUNGEON;
				}
				// Story Boss Fight: Macko -> Story Boss Fight: Max
				else if (ENUM_Story_Status == storyStatus::TRUE_TWO)
				{
					Enemy ENEMY_New_Enemy = Enemy("Max", 150, 6784, 15262, { Skill("End of the World") }, false, 426);
					play_audio("Boss - Max");
					battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);
					STORY_Story.startOfDialogue();
					STORY_Story.increaseDialogueIndex();
					ENUM_Story_Status = storyStatus::TRUE_COMPLETE;
				}
				// Story Boss Fight: Max -> * on Save File
				else if (ENUM_Story_Status == storyStatus::TRUE_COMPLETE)
				{
					DUNGEON_Current_Dungeon->fillWithEnemies();
					DUNGEON_Current_Dungeon->fillWithChests();
					PLAYER_Player.setSpecificStarOnFile("Secret", '*');
					ENUM_Game_Status = gameStatus::DUNGEON;
				}
				break;
			}
		}
						
		if (ENUM_Game_Status == gameStatus::DUNGEON) play_audio(DUNGEON_Current_Dungeon->getDungeonName() + " F" + to_string(DUNGEON_Current_Dungeon->getDungeonRoom()));

		while (ENUM_Game_Status == gameStatus::DUNGEON)
		{
			DUNGEON_Current_Dungeon->displayDungeon();
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
					cout << "   " << STR_Dialogue; _getch(); cout << "\33[2K\r" << flush;;
				}
				DUNGEON_Current_Dungeon->exploredRoom();
			}
			else
			{
				char key = _getch();
				if (key == 'w' || key == 'a' || key == 's' || key == 'd') map_movement(key, PLAYER_Player, ENEMY_New_Enemy, DUNGEON_Current_Dungeon, ENUM_Story_Status, ENUM_Game_Status, STORY_Story);
				else if (key == '1') menuItems(PLAYER_Player);
				else if (key == '2') menuStats(PLAYER_Player);
				else if (key == '3') menuTravel(VEC_Visited_Dungeons, DUNGEON_Current_Dungeon);
				else if (key == '4') saveGame(PLAYER_Player, VEC_Visited_Dungeons);
				else if (key == '5') closeGame();
			}
		}
	}
}

// Main Menu
vector<string> main_menu()
{
	play_audio("Menu");

	vector<string> VEC_Patch_Notes = { };
	ifstream file("PATCH_NOTES.txt");
	string line;
	if (file.is_open())
	{
		while (getline(file, line))
		{
			VEC_Patch_Notes.push_back(line);
		}
	}
	cout << "\n   " << dye::black_on_white(" ") << dye::black_on_white(VEC_Patch_Notes[0]) << dye::black_on_white(" ");
	reverse(VEC_Patch_Notes.begin(), VEC_Patch_Notes.end());
	VEC_Patch_Notes.pop_back();
	reverse(VEC_Patch_Notes.begin(), VEC_Patch_Notes.end());
	for (string STR_Update_Line : VEC_Patch_Notes)
	{
		cout << "\n   " << STR_Update_Line;
	}
	file.close();
	cout << dye::light_yellow("\n\n   Happy Playing!\n");
	_getch();
	system("CLS");

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
		cout << "             v05_26.07          " << endl;
		cout << "\n\n";
		cout << "--> New Game\n--> Load Game\n--> Credits\n--> Quit\n\n> ";
		getline(cin, STR_Menu_Choice);
		STR_Menu_Choice = convert_string_tolower(STR_Menu_Choice);
	}
	system("CLS");
	if (STR_Menu_Choice == "new game")
	{
		return { "NONE" };
	}
	if (STR_Menu_Choice == "load game")
	{
		system("CLS");
		cout << "\n   " << dye::black_on_bright_white(" Current Save Files \n\n");

		struct dirent* d;
		struct stat dst;
		vector<vector<string>> ALL_SAVE_Data;

		DIR* dr;
		string path = "data/";
		dr = opendir(path.c_str());

		if (dr != NULL)
		{
			for (d = readdir(dr); d != NULL; d = readdir(dr))
			{
				string type = d->d_name;
				type = path + type;
				if (stat(type.c_str(), &dst) == 0)
				{
					if (dst.st_mode & S_IFREG)
					{
						ifstream file(type);
						if (file.is_open())
						{
							vector<string> CURRENT_SAVE_Data = { };
							while (getline(file, line))
							{
								CURRENT_SAVE_Data.push_back(line);
							}
							cout << "   " << dye::grey(CURRENT_SAVE_Data[0]);
							if (CURRENT_SAVE_Data[CURRENT_SAVE_Data.size() - 1] == "*") cout << dye::yellow(" *");
							if (CURRENT_SAVE_Data[CURRENT_SAVE_Data.size() - 2] == "*") cout << dye::yellow(" *");
							if (CURRENT_SAVE_Data[CURRENT_SAVE_Data.size() - 3] == "*") cout << dye::yellow(" *");
							if (CURRENT_SAVE_Data[CURRENT_SAVE_Data.size() - 4] == "*") cout << dye::yellow(" *");
							cout << dye::light_yellow("\n   Lv ") << dye::light_yellow(CURRENT_SAVE_Data[3]) << " | " << CURRENT_SAVE_Data[10] << " F" << CURRENT_SAVE_Data[11];
							ALL_SAVE_Data.push_back(CURRENT_SAVE_Data);
							file.close();
						}
						cout << "\n\n";
					}
				}
			}
			closedir(dr);
		}
		cout << "   > ";
		string STR_Save_Name_Selected;
		getline(cin, STR_Save_Name_Selected);

		for (int i = 0; i < ALL_SAVE_Data.size(); i++)
		{
			if (ALL_SAVE_Data[i][0] == STR_Save_Name_Selected)
			{
				return ALL_SAVE_Data[i];
			}
		}
		return { "NONE" };
	}
	if (STR_Menu_Choice == "credits")
	{
		system("CLS");
		cout << "\n   " << dye::black_on_white(" General ");
		cout << "\n   This game is heavily inspired by the Persona franchise, it's my favourite video game series!";
		cout << "\n\n   The concept of 'Lost Histories':\n   The planet gets too hot and you (the player) unfreeze from a block of ice! Figure out what's going on by exploring, and save the planet!\n\n";
		cout << "\n   " << dye::black_on_white(" Music "); 
		cout << dye::yellow("\n   Main Menu") << " - " << dye::grey("TEMPLE - Riddle School, Jonochrome/pepsileo") << endl;
		cout << dye::yellow("   Dungeon: Glacier Wasteland F1-F5") << " - " << dye::grey("Abyss of Time - Persona 3 FES, ATLUS") << endl;
		cout << dye::yellow("   Dungeon: Atlantis Ruins F1-F4") << " - " << dye::grey("Secret Base - Persona 4, ATLUS") << endl;
		cout << dye::yellow("   Dungeon: Atlantis Ruins F5-F6") << " - " << dye::grey("Devil's Peak - Persona 1 (PSP), ATLUS") << endl;
		cout << dye::yellow("   Dungeon: Facility F1-F5") << " - " << dye::grey("The Snow Queen - Persona 3 FES, ATLUS") << endl;
		cout << dye::yellow("   Dungeon: Magma Fields F1-F3") << " - " << dye::grey("World 8 - New Super Mario Bros. Wii, Nintendo") << endl;
		cout << dye::yellow("   Dungeon: Glacier Wasteland F6, Atlantis Ruins F7, Facility F6") << " - " << dye::grey("Corridor - Persona 4, ATLUS") << endl;
		cout << dye::yellow("   Dungeon: Magma Fields F4") << " - " << dye::grey("Final World - Super Mario Bros. Wonder, Nintendo") << endl;
		cout << dye::yellow("   Dungeon: Special Passage F1-F7") << " - " << dye::grey("World 9 - New Super Mario Bros. Wii, Nintendo") << endl;
		cout << dye::yellow("   Dungeon: Domain") << " - " << dye::grey("Abandoned Factory - Persona 2 Eternal Punishment, ATLUS") << endl;
		cout << dye::yellow("   Battle: Dungeon") << " - " << dye::grey("Master of Tarturus - Persona 3, ATLUS") << endl;
		cout << dye::yellow("   Battle: Key Boss") << " - " << dye::grey("Never Let Up! - Mario and Luigi: Dream Team, Nintendo") << endl;
		cout << dye::yellow("   Battle: Special Key Boss") << " - " << dye::grey("Keeper of Lust - Persona 5, ATLUS") << endl;
		cout << dye::yellow("   Battle: Dungeon Boss") << " - " << dye::grey("I'll Face Myself -Battle- - Persona 4, ATLUS") << endl;
		cout << dye::yellow("   Battle: Victory") << " - " << dye::grey("After the Battle - Persona 3, ATLUS") << endl;
		cout << dye::yellow("   Boss: Reincarnation of George Shaw") << " - " << dye::grey("Unavoidable Battle - Persona 3, ATLUS") << endl;
		cout << dye::yellow("   Boss: The Mastermind") << " - " << dye::grey("New World Fool - Persona 4, ATLUS") << endl;
		cout << dye::yellow("   Boss: Mutated Mastermind") << " - " << dye::grey("The Almighty - Persona 4, ATLUS") << endl;
		cout << dye::yellow("   Boss: Keeper of The Device") << " - " << dye::grey("Darkness - Persona 3 FES, ATLUS") << endl;
		cout << dye::yellow("   Boss: Tyson Mondeo") << " - " << dye::grey("??? - ???") << endl;
		cout << dye::yellow("   Boss: Macko?") << " - " << dye::grey("Rivers in the Desert Instrumental - Persona 5, ATLUS") << endl;
		cout << dye::yellow("   Encounter: Dungeon") << " - " << dye::grey("That Which Escaped the Darkness - Persona 3, ATLUS") << endl;
		cout << dye::yellow("   Encounter: Story") << " - " << dye::grey("Borderline of Madness - Persona 4, ATLUS") << endl;
		cout << "\n   " << dye::green("Press any key to begin NEW GAME\n\n   ");
		_getch();
		system("CLS");
		return { "NONE" };
	}
	if (STR_Menu_Choice == "quit")
	{
		exit(0);
	}
	return { "NONE" };
}

// Controls Player movement
void map_movement(char CHAR_Movement, Player& PLAYER_Player, Enemy& ENEMY_New_Enemy, Dungeon* DUNGEON_Current_Dungeon, storyStatus& ENUM_Story_Status, gameStatus& ENUM_Game_Status, Story& STORY_Story)
{
	// I will only comment for the first IF statement as its the same principal for each movement key
	if (CHAR_Movement == 'd')
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
			if (DUNGEON_Current_Dungeon->getDungeonName() == "Glacier Wasteland" || (DUNGEON_Current_Dungeon->getDungeonName() == "Atlantis Ruins" && DUNGEON_Current_Dungeon->getDungeonRoom() == 5) || (DUNGEON_Current_Dungeon->getDungeonName() == "Atlantis Ruins" && DUNGEON_Current_Dungeon->getDungeonRoom() == 7) || (DUNGEON_Current_Dungeon->getDungeonName() == "Facility" && DUNGEON_Current_Dungeon->getDungeonRoom() == 7) || (DUNGEON_Current_Dungeon->getDungeonName() == "Facility" && DUNGEON_Current_Dungeon->getDungeonRoom() == 8) || (DUNGEON_Current_Dungeon->getDungeonName() == "Magma Fields" && DUNGEON_Current_Dungeon->getDungeonRoom() == 4))
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

		// Checks to see if the next tile is a Key Door (|)
		else if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1)) == '|')
		{
			bool BOOL_Has_Key = false;
			for (Item* ITEM_Item : PLAYER_Player.getItems())
			{
				if (ITEM_Item->getName() == DUNGEON_Current_Dungeon->getDungeonName() + " F" + to_string(DUNGEON_Current_Dungeon->getDungeonRoom()) + " Key")
				{
					DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
					DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1), '+');
					DUNGEON_Current_Dungeon->changePosY(1);
					BOOL_Has_Key = true;
				}
			}
			if (!BOOL_Has_Key)
			{
				cout << "   Requires " + DUNGEON_Current_Dungeon->getDungeonName() + " F" + to_string(DUNGEON_Current_Dungeon->getDungeonRoom()) + " Key";
				this_thread::sleep_for(chrono::seconds(2));
			}
		}

		// Checks to see if the next tile is a Mini Boss or Main Boss (?)
		else if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1)) == '?')
		{
			// Moves the player to the next tile
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() + 1), '+');
			DUNGEON_Current_Dungeon->changePosY(1);

			bool BOOL_Already_Fought = false;	

			// Assigns the Enemy object a custom Enemy, this being the Main Boss of the dungeon
			Enemy ENEMY_New_Enemy = DUNGEON_Current_Dungeon->getEncounterEnemy();

			for (Item* ITEM_Item : PLAYER_Player.getItems())
			{
				if (ITEM_Item->getName() == ENEMY_New_Enemy.getDroppedItem()->getName())
				{
					BOOL_Already_Fought = true;
				}
			}

			if (!BOOL_Already_Fought)
			{
				// Initiates dialogue sequence
				play_audio("Encounter"); _getch(); cout << "\33[2K\r" << flush;;
				for (string STR_Encounter_Dialogue : DUNGEON_Current_Dungeon->getEncounterDialogue())
				{
					cout << "   " << STR_Encounter_Dialogue;
					_getch();
					cout << "\33[2K\r" << flush;
				}

				// Starts battle
				if (ENEMY_New_Enemy.getName() == "Russian Sergeant" || ENEMY_New_Enemy.getName() == "Reawoken Guardian of Atlantis" || ENEMY_New_Enemy.getName() == "Master of the Facility")
				{
					play_audio("Dungeon Main Boss");
				}
				else if (ENEMY_New_Enemy.getName() == "The Mastermind")
				{
					play_audio("Boss - The Mastermind Pt 1");
				}
				else if (ENEMY_New_Enemy.getName() == "Macko?")
				{
					play_audio("Boss - Macko?");
				}
				else if (ENEMY_New_Enemy.getName() == "Macko")
				{
					play_audio("Boss - Macko");
				}
				else if (ENEMY_New_Enemy.getName() == "Max")
				{
					play_audio("Boss - Max");
				}
				else if (ENEMY_New_Enemy.getName() == "Tyson Mondeo")
				{
					play_audio("Boss - Tyson Mondeo");
				}
				else if (ENEMY_New_Enemy.getName() == "???")
				{
					play_audio("Story Battle");
				}
				else if (DUNGEON_Current_Dungeon->getDungeonName() == "Special Passage")
				{
					play_audio("Dungeon: Special Mini Boss");
				}
				else
				{
					play_audio("Dungeon Mini Boss");
				}

				battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);

				// Once out of the battle gameplay loop, start dialogue and story between dungeons
				if (DUNGEON_Current_Dungeon->getDungeonName() == "Glacier Wasteland" && DUNGEON_Current_Dungeon->getDungeonRoom() == 6)
				{
					STORY_Story.setDialogueIndex(26);
					STORY_Story.startOfDialogue();
					STORY_Story.increaseDialogueIndex();
					ENUM_Story_Status = storyStatus::ACT_TWO;
					ENUM_Game_Status = gameStatus::DIALOGUE;
					play_audio("Confront");
				}
				else if (DUNGEON_Current_Dungeon->getDungeonName() == "Atlantis Ruins" && DUNGEON_Current_Dungeon->getDungeonRoom() == 7)
				{
					STORY_Story.setDialogueIndex(53);
					STORY_Story.startOfDialogue();
					STORY_Story.increaseDialogueIndex();
					ENUM_Story_Status = storyStatus::ACT_THREE;
					ENUM_Game_Status = gameStatus::DIALOGUE;
					play_audio("Confront");
				}
				else if (DUNGEON_Current_Dungeon->getDungeonName() == "Facility" && DUNGEON_Current_Dungeon->getDungeonRoom() == 7)
				{
					STORY_Story.setDialogueIndex(86);
					STORY_Story.startOfDialogue();
					STORY_Story.increaseDialogueIndex();
					ENUM_Story_Status = storyStatus::ACT_FOUR;
					ENUM_Game_Status = gameStatus::DIALOGUE;
					play_audio("Confront");
				}
				else if (DUNGEON_Current_Dungeon->getDungeonName() == "Magma Fields" && DUNGEON_Current_Dungeon->getDungeonRoom() == 4)
				{
					STORY_Story.setDialogueIndex(124);
					STORY_Story.startOfDialogue();
					STORY_Story.increaseDialogueIndex();
					ENUM_Story_Status = storyStatus::ACT_SIX;
					ENUM_Game_Status = gameStatus::DIALOGUE;
					play_audio("Confront");
				}
				else if (DUNGEON_Current_Dungeon->getDungeonName() == "Facility" && DUNGEON_Current_Dungeon->getDungeonRoom() == 10)
				{
					STORY_Story.setDialogueIndex(199);
					STORY_Story.startOfDialogue();
					STORY_Story.increaseDialogueIndex();
					ENUM_Story_Status = storyStatus::TRUE_ONE;
					ENUM_Game_Status = gameStatus::DIALOGUE;
					play_audio("Confront");
				}
				else if (DUNGEON_Current_Dungeon->getDungeonName() == "Domain" && DUNGEON_Current_Dungeon->getDungeonRoom() == 15)
				{
					STORY_Story.setDialogueIndex(222);
					STORY_Story.startOfDialogue();
					STORY_Story.increaseDialogueIndex();
					ENUM_Story_Status = storyStatus::TRUE_TWO;
					ENUM_Game_Status = gameStatus::DIALOGUE;
					play_audio("Last Confront");
				}
			}
		}
	}
	if (CHAR_Movement == 'a')
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
			if (DUNGEON_Current_Dungeon->getDungeonName() == "Glacier Wasteland" || (DUNGEON_Current_Dungeon->getDungeonName() == "Atlantis Ruins" && DUNGEON_Current_Dungeon->getDungeonRoom() == 4) || (DUNGEON_Current_Dungeon->getDungeonName() == "Atlantis Ruins" && DUNGEON_Current_Dungeon->getDungeonRoom() == 6) || (DUNGEON_Current_Dungeon->getDungeonName() == "Facility" && DUNGEON_Current_Dungeon->getDungeonRoom() == 6) || (DUNGEON_Current_Dungeon->getDungeonName() == "Facility" && DUNGEON_Current_Dungeon->getDungeonRoom() == 7) || (DUNGEON_Current_Dungeon->getDungeonName() == "Magma Fields" && DUNGEON_Current_Dungeon->getDungeonRoom() == 3))
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

			// Initiates dialogue sequence
			play_audio("Encounter"); _getch(); cout << "\33[2K\r" << flush;;
			for (string STR_Encounter_Dialogue : DUNGEON_Current_Dungeon->getEncounterDialogue())
			{
				cout << "   " << STR_Encounter_Dialogue;
				_getch();
				cout << "\33[2K\r" << flush;
			}

			// Assigns the Enemy object a custom Enemy, this being the Main Boss of the dungeon
			Enemy ENEMY_New_Enemy = DUNGEON_Current_Dungeon->getEncounterEnemy();
			play_audio("Dungeon Mini Boss");
			battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);
		}
		else if (DUNGEON_Current_Dungeon->getPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() - 1)) == '|')
		{
			bool BOOL_Has_Key = false;
			for (Item* ITEM_Item : PLAYER_Player.getItems())
			{
				if (ITEM_Item->getName() == "Facility Treasure Room Key")
				{
					DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
					DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), (DUNGEON_Current_Dungeon->getPosX() - 1), '+');
					DUNGEON_Current_Dungeon->changePosY(-1);
					BOOL_Has_Key = true;
				}
			}
			if (!BOOL_Has_Key)
			{
				cout << "   Requires Facility Treasure Room Key";
				this_thread::sleep_for(chrono::seconds(2));
			}
		}
	}
	if (CHAR_Movement == 'w')
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
	if (CHAR_Movement == 's')
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
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), DUNGEON_Current_Dungeon->getPosY(), DUNGEON_Current_Dungeon->getPosX(), ' ');
			DUNGEON_Current_Dungeon->setPosition((DUNGEON_Current_Dungeon->getDungeonRoom() - 1), (DUNGEON_Current_Dungeon->getPosY() + 1), DUNGEON_Current_Dungeon->getPosX(), '+');
			DUNGEON_Current_Dungeon->changePosX(1);

			// Initiates dialogue sequence
			play_audio("Encounter"); _getch(); cout << "\33[2K\r" << flush;;
			for (string STR_Encounter_Dialogue : DUNGEON_Current_Dungeon->getEncounterDialogue())
			{
				cout << "   " << STR_Encounter_Dialogue;
				_getch();
				cout << "\33[2K\r" << flush;
			}

			// Assigns the Enemy object a custom Enemy, this being the Main Boss of the dungeon
			Enemy ENEMY_New_Enemy = DUNGEON_Current_Dungeon->getEncounterEnemy();
			play_audio("Dungeon Mini Boss");
			battle(PLAYER_Player, DUNGEON_Current_Dungeon, ENEMY_New_Enemy);
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
	if (ITEM_New_Item->isMeleeWeapon() || ITEM_New_Item->canInheritSkill())
	{
		cout << "   ";
	}
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
	ENEMY_Enemy.elementSetter();
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
				PLAYER_Player.showBattleStats();
				if (ENEMY_Enemy.getName() == "Macko" || ENEMY_Enemy.getName() == "Max")
				{
					cout << dye::light_red("   Turns left: ") << dye::red(ENEMY_Enemy.getTurnsLeft());
				}
				cout << "\n\n   " << dye::black_on_bright_white(" 1 ") << " Melee";
				cout << "\n\n   " << dye::black_on_bright_white(" 2 ") << " Skill";
				cout << "\n\n   " << dye::black_on_bright_white(" 3 ") << " Item";
				cout << "\n\n   " << dye::black_on_bright_white(" 4 ") << " Guard";
				cout << "\n\n   " << dye::black_on_bright_white(" 5 ") << " Analyse";
				if (!ENEMY_Enemy.isBoss()) cout << "\n\n   " << dye::black_on_bright_white(" 6 ") << " Flee";
				char key = _getch();
				if (key == '1') STR_Player_Page = "melee";
				if (key == '2') STR_Player_Page = "skill";
				if (key == '3') STR_Player_Page = "item";
				if (key == '4') STR_Player_Page = "guard";
				if (key == '5') STR_Player_Page = "analyse";
				if (!ENEMY_Enemy.isBoss() && key == '6') STR_Player_Page = "flee";
			}
			while (STR_Player_Page == "item" && BOOL_Player_Turn)
			{
				PLAYER_Player.showBattleStats();
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
							cout << "\n\n";
						}
					}
					cout << "--> Return\n\n  > ";
					getline(cin, STR_Battle_Choice);
					STR_Battle_Choice = convert_string_tolower(STR_Battle_Choice);
					for (Item* ITEM_Item : PLAYER_Player.getItems())
					{
						if (convert_string_tolower(ITEM_Item->getName()) == STR_Battle_Choice && ITEM_Item->isConsumable())
						{
							PLAYER_Player.showBattleStats();
							if (ITEM_Item->getType() == "HP")
							{
								PLAYER_Player.changeHealth(ITEM_Item->getAmount());
								if (PLAYER_Player.getHealth() > PLAYER_Player.getMaxHealth())
								{
									PLAYER_Player.fullHealth();
								}
								cout << "   You used " << ITEM_Item->getName() << " restoring " << ITEM_Item->getAmount() << " " << ITEM_Item->getType();
							}
							else if (ITEM_Item->getType() == "STA")
							{
								PLAYER_Player.changeStamina(ITEM_Item->getAmount());
								if (PLAYER_Player.getStamina() > PLAYER_Player.getMaxStamina())
								{
									PLAYER_Player.fullStamina();
								}
								cout << "   You used " << ITEM_Item->getName() << " restoring " << ITEM_Item->getAmount() << " " << ITEM_Item->getType();
							}
							else if (ITEM_Item->getType() == "ATK")
							{
								cout << "   You used " << ITEM_Item->getName() << " increasing your next melee attack damage by " << round((ITEM_Item->getAmount()) * 100 - 100) << "%";
								PLAYER_Player.setMeleeAttackMultiplier(ITEM_Item->getAmount());
							}
							else if (ITEM_Item->getType() == "MAG")
							{
								cout << "   You used " << ITEM_Item->getName() << " increasing your next magic attack damage by " << round((ITEM_Item->getAmount()) * 100 - 100) << "%";
								PLAYER_Player.setMagicAttackMultiplier(ITEM_Item->getAmount());
							}
							else if (ITEM_Item->getType() == "ATK/MAG")
							{
								cout << "   You used " << ITEM_Item->getName() << " increasing your next melee and magic attack damage by " << round((ITEM_Item->getAmount()) * 100 - 100) << "%";
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
				PLAYER_Player.showBattleStats();
				if (PLAYER_Player.getSkills().empty())
				{
					cout << "   You have no skills currently." << endl;
					this_thread::sleep_for(chrono::seconds(2));
					STR_Player_Page = "";
				}
				else
				{
					vector<string> VEC_Skill_Names = { };
					for (Skill SKILL_Skill : PLAYER_Player.getSkills())
					{
						VEC_Skill_Names.push_back(SKILL_Skill.getName());
					}
					show_skill(PLAYER_Player, INT_Skill_Index, ENEMY_Enemy);
					cout << "\n\n   " << dye::black_on_bright_white(" A ") << " Prev Skill";
					cout << "\n\n   " << dye::black_on_bright_white(" D ") << " Next Skill";
					cout << "\n\n   " << dye::black_on_bright_white(" E ") << " Use Skill";
					cout << "\n\n   " << dye::black_on_bright_white(" Q ") << " Return";
					char key = _getch();

					// If choice is "next", show the Player their next skill
					if (key == 'd')
					{
						INT_Skill_Index++;
						if (INT_Skill_Index > PLAYER_Player.getSkills().size() - 1)
						{
							INT_Skill_Index = 0;
						}
					}

					// If choice is "prev", show the Player their previous skill
					else if (key == 'a')
					{
						INT_Skill_Index--;
						if (INT_Skill_Index < 0)
						{
							INT_Skill_Index = PLAYER_Player.getSkills().size() - 1;
						}
					}

					// If choice is "use", use the selected skill
					else if (key == 'e')
					{
						Skill SKILL_Skill = Skill(VEC_Skill_Names[INT_Skill_Index]);
						if ((PLAYER_Player.getStamina() >= SKILL_Skill.getStaminaCost()) || (PLAYER_Player.getHealth() >= int(PLAYER_Player.getMaxHealth() * SKILL_Skill.getHealthCostMultiplier()) && SKILL_Skill.getType() == "Physical"))
						{
							Skill SKILL_Skill_Selected = Skill(VEC_Skill_Names[INT_Skill_Index]);
							int INT_Repeat_Attack = SKILL_Skill_Selected.getPhysicalHitAmount();
							int INT_Accumulated_Damage = 0;
							for (int i = 0; i < INT_Repeat_Attack; i++)
							{
								PLAYER_Player.showBattleStats();
								// Determines what the skill does
								if (SKILL_Skill_Selected.getType() == "Support")
								{
									// Heal the PLAYER_Player
									PLAYER_Player.changeHealth(SKILL_Skill_Selected.getHPGain());
									cout << "   You have healed yourself restoring " << SKILL_Skill_Selected.getHPGain() << " health\n\n";
								}
								else
								{
									// Damage the ENEMY_Enemy
									int INT_Calculated_Damage; // Player Skill Damage after calculations
									float FLT_Attribute_Multiplier;
									int INT_Critical_Chance = (rand() % 100) + 1; // Number 1-100, if >79 deal a Critical Hit

									if (SKILL_Skill_Selected.getType() == "Physical")
									{
										FLT_Attribute_Multiplier = 1 + (float(PLAYER_Player.getPlayerAttributes().find("Strength")->second) / 25); // Player Attribute "Strength" Multiplier
									}
									else
									{
										FLT_Attribute_Multiplier = 1 + (float(PLAYER_Player.getPlayerAttributes().find("Magic")->second) / 25); // Player Attribute "Magic" Multiplier
									}
									if (PLAYER_Player.getMeleeWeapon().hasModifiedAttribute() && PLAYER_Player.getMeleeWeapon().getAttributeType() == "Magic")
									{
										FLT_Attribute_Multiplier *= PLAYER_Player.getMeleeWeapon().getBonusValue();
									}
									if (SKILL_Skill_Selected.getType() == "Physical" && INT_Critical_Chance >= 85)
									{
										FLT_Attribute_Multiplier *= 2;
									}

									if (SKILL_Skill_Selected.getType() == "Nuclear")
									{
										INT_Calculated_Damage = SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * PLAYER_Player.getMagicAttackMultiplier();
										cout << "   You casted " << SKILL_Skill_Selected.getName() << " upon all enemies dealing " << INT_Calculated_Damage << " damage ";
									}
									else
									{
										if (ENEMY_Enemy.getElements().find(SKILL_Skill_Selected.getType())->second == "-")
										{
											INT_Calculated_Damage = SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * PLAYER_Player.getMagicAttackMultiplier();
											cout << "   You casted " << SKILL_Skill_Selected.getName() << " upon " << ENEMY_Enemy.getName() << " dealing " << INT_Calculated_Damage << " damage ";
										}
										else if (ENEMY_Enemy.getElements().find(SKILL_Skill_Selected.getType())->second == "Wk")
										{
											INT_Calculated_Damage = SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * 1.5 * PLAYER_Player.getMagicAttackMultiplier();
											cout << "   You casted " << SKILL_Skill_Selected.getName() << " upon " << ENEMY_Enemy.getName() << " dealing " << INT_Calculated_Damage << " damage " << dye::black_on_yellow(" WEAK ") << " ";
										}
										else if (ENEMY_Enemy.getElements().find(SKILL_Skill_Selected.getType())->second == "Rst")
										{
											INT_Calculated_Damage = SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * 0.5 * PLAYER_Player.getMagicAttackMultiplier();
											cout << "   You casted " << SKILL_Skill_Selected.getName() << " upon " << ENEMY_Enemy.getName() << " dealing " << INT_Calculated_Damage << " damage " << dye::black_on_red(" RESIST ") << " ";
										}
										else if (ENEMY_Enemy.getElements().find(SKILL_Skill_Selected.getType())->second == "Nul")
										{
											INT_Calculated_Damage = 0;
											cout << "   You casted " << SKILL_Skill_Selected.getName() << " upon " << ENEMY_Enemy.getName() << " dealing " << INT_Calculated_Damage << " damage " << dye::black_on_grey(" BLOCK ") << " ";
										}
										else if (ENEMY_Enemy.getElements().find(SKILL_Skill_Selected.getType())->second == "Abs")
										{
											INT_Calculated_Damage = -(SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * PLAYER_Player.getMagicAttackMultiplier());
											cout << "   You casted " << SKILL_Skill_Selected.getName() << " upon " << ENEMY_Enemy.getName() << " which absorbed your attack restoring " << -INT_Calculated_Damage << " health " << dye::black_on_green(" ABSORB ") << " ";
										}
										else if (ENEMY_Enemy.getElements().find(SKILL_Skill_Selected.getType())->second == "Rpl")
										{
											INT_Calculated_Damage = SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * PLAYER_Player.getMagicAttackMultiplier();
											cout << "   You casted " << SKILL_Skill_Selected.getName() << " upon " << ENEMY_Enemy.getName() << " which repelled your attack dealing " << INT_Calculated_Damage << " damage to yourself " << dye::red_on_light_red(" REPEL ") << " ";
										}


										if (SKILL_Skill_Selected.getPhysicalHitAmount() > 1)
										{
											INT_Accumulated_Damage += INT_Calculated_Damage;
											cout << " " << dye::grey_on_white(" ") << dye::red_on_white(INT_Accumulated_Damage) << dye::grey_on_white(" Total ");
										}

										if (SKILL_Skill_Selected.getType() == "Physical" && INT_Critical_Chance >= 85)
										{
											cout << dye::blue_on_aqua(" CRITICAL ") << " ";
										}
										if (PLAYER_Player.getMeleeWeapon().hasModifiedAttribute() && PLAYER_Player.getMeleeWeapon().getAttributeType() == "Magic")
										{
											cout << dye::aqua_on_light_aqua(" BONUS ");
										}
									}
									if (SKILL_Skill_Selected.getType() != "Nuclear")
									{
										if (ENEMY_Enemy.getElements().find(SKILL_Skill_Selected.getType())->second == "Rpl")
										{
											PLAYER_Player.changeHealth(-INT_Calculated_Damage);
										}
										else if (ENEMY_Enemy.getElements().find(SKILL_Skill_Selected.getType())->second == "Abs")
										{
											ENEMY_Enemy.changeHealth(INT_Calculated_Damage);
										}
										else
										{
											ENEMY_Enemy.changeHealth(-INT_Calculated_Damage);
										}
									}
									else
									{
										ENEMY_Enemy.changeHealth(-INT_Calculated_Damage);
									}
								}
								this_thread::sleep_for(chrono::milliseconds(225));
							}
							if (SKILL_Skill_Selected.getType() == "Physical")
							{
								PLAYER_Player.changeHealth(-int(PLAYER_Player.getMaxHealth() * SKILL_Skill_Selected.getHealthCostMultiplier()));
							}
							else
							{
								PLAYER_Player.changeStamina(-SKILL_Skill_Selected.getStaminaCost());
							}
							PLAYER_Player.setMagicAttackMultiplier(1.0);
							BOOL_Player_Turn = false;
							break;
						}
					}
					
					// If choice is "return", take the Player back to the main battle menu
					else if (key == 'q')
					{
						STR_Player_Page = "";
						break;
					}
				}
			}
			// Page : Melee
			while (STR_Player_Page == "melee")
			{
				PLAYER_Player.showBattleStats();
				cout << "   ";
				PLAYER_Player.getMeleeWeapon().toString();
				cout << "\n\n   " << dye::black_on_bright_white(" E ") << " Use";
				cout << "\n\n   " << dye::black_on_bright_white(" Q ") << " Return";
				char key = _getch();
				
				// If STR_Battle_Choice is "use", attack the Enemy with melee weapon
				if (key == 'e')
				{
					PLAYER_Player.showBattleStats();
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
					PLAYER_Player.showBattleStats();
					if (INT_Critical_Chance > 79)
					{
						INT_Calculated_Damage = PLAYER_Player.getMeleeWeapon().getMeleeDamage() * FLT_Attribute_Multiplier * 2 * PLAYER_Player.getMeleeAttackMultiplier();
					}
					else
					{
						INT_Calculated_Damage = PLAYER_Player.getMeleeWeapon().getMeleeDamage() * FLT_Attribute_Multiplier * PLAYER_Player.getMeleeAttackMultiplier();
					}

					cout << "   You attacked " << ENEMY_Enemy.getName() << " using " << PLAYER_Player.getMeleeWeapon().getName() << " dealing " << INT_Calculated_Damage << " damage ";
					if (INT_Critical_Chance >= 78)
					{
						cout << dye::blue_on_aqua(" CRITICAL ") << " ";
					}
					if ((PLAYER_Player.getMeleeWeapon().hasModifiedAttribute() && PLAYER_Player.getMeleeWeapon().getAttributeType() == "Melee") || (PLAYER_Player.getMeleeWeapon().hasElementCoverage() && ENEMY_Enemy.getElements().find(PLAYER_Player.getMeleeWeapon().getElementalType())->second == "Wk"))
					{
						cout << dye::aqua_on_light_aqua(" BONUS ");
					}
					cout << "\n\n";
					ENEMY_Enemy.changeHealth(-INT_Calculated_Damage);
					PLAYER_Player.setMeleeAttackMultiplier(1.0);
					BOOL_Player_Turn = false;
					break;
				}
				
				// If STR_Battle_Choice is "return", take the Player back to the main battle menu
				else if (key == 'q')
				{
					STR_Player_Page = "";
					break;
				}
			}
			// Page : Guard
			while (STR_Player_Page == "guard")
			{
				PLAYER_Player.showBattleStats();
				cout << "   Reduces incoming damage by 33% and negates weaknesses\n   (Does stack if resistant)";
				cout << "\n\n   " << dye::black_on_bright_white(" G ") << " Guard";
				cout << "\n\n   " << dye::black_on_bright_white(" Q ") << " Return";
				char key = _getch();

				// If STR_Battle_Choice is "guard", guards against incoming attack
				if (key == 'g')
				{
					PLAYER_Player.showBattleStats();
					PLAYER_Player.setGuard(true);
					cout << "   You have guarded yourself\n\n";
					BOOL_Player_Turn = false;
					break;
				}
				// If STR_Battle_Choice is "return", take the PLAYER_Player back to the main battle menu
				else if (key == 'q')
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
				cout << "\n   " << dye::black_on_white(" Item \n") << "   " << enemyDrop->getName();
				cout << "\n\n   " << dye::black_on_bright_white(" Q ") << " Return";
				char key = _getch();

				// If STR_Battle_Choice is "return", take the PLAYER_Player back to the main battle menu
				if (key == 'q')
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
			if (ENEMY_Enemy.getName() == "Gold Entity I" || ENEMY_Enemy.getName() == "Gold Entity II" || ENEMY_Enemy.getName() == "Gold Entity III" || ENEMY_Enemy.getName() == "Gold Entity IV" || ENEMY_Enemy.getName() == "Gold Entity V" || ENEMY_Enemy.getName() == "Gold Entity VI")
			{
				FLT_EXP_Earned = int(ENEMY_Enemy.getMaxHealth() * 7.77);
			}
			if (ENEMY_Enemy.getName() == "Gold Entity VII" || ENEMY_Enemy.getName() == "Gold Entity VIII" || ENEMY_Enemy.getName() == "Gold Entity IX" || ENEMY_Enemy.getName() == "Gold Entity X")
			{
				FLT_EXP_Earned = int(ENEMY_Enemy.getMaxHealth() * 9.99);
			}
			else if (ENEMY_Enemy.isBoss())
			{
				FLT_EXP_Earned = ENEMY_Enemy.getMaxHealth() * 5;
			}
			else
			{
				FLT_EXP_Earned = ENEMY_Enemy.getMaxHealth() * 2;
			}

			if (DUNGEON_Current_Dungeon->getDungeonName() == "Atlantis Ruins")
			{
				FLT_EXP_Earned *= 1.5;
			}
			else if (DUNGEON_Current_Dungeon->getDungeonName() == "Facility")
			{
				FLT_EXP_Earned *= 2.5;
			}
			else if (DUNGEON_Current_Dungeon->getDungeonName() == "Magma Fields")
			{
				FLT_EXP_Earned *= 4;
			}
			else if (DUNGEON_Current_Dungeon->getDungeonName() == "Special Passage")
			{
				FLT_EXP_Earned *= 5;
			}
			else if (DUNGEON_Current_Dungeon->getDungeonName() == "Domain")
			{
				FLT_EXP_Earned *= 6.6;
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
				cout << dye::green("\n   You gained ") << dye::light_green(int(FLT_EXP_Earned)) << dye::green(" experience") << endl << endl;
				cout << "   " << ENEMY_Enemy.getName() << " dropped " << enemyDrop->getName() << "!" << endl;
				if (!BOOL_Item_Dupe)
				{
					if (enemyDrop->canInheritSkill())
					{
						cout << dye::purple("   + Unlocked Skill: ") << dye::light_purple(enemyDrop->getSkill().getName()) << endl;
					}
				}
				cout << "\n   Level " << PLAYER_Player.getLevel() << " | Next EXP: " << int(PLAYER_Player.getNextEXP() - PLAYER_Player.getCurrEXP());
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
		else if (PLAYER_Player.getHealth() <= 0)
		{
			system("CLS");
			cout << "\n   " << dye::red_on_light_red(" GAME OVER \n") << "   Better luck on your next playthrough\n\n   ";
			system("pause");
			exit(0);
		}
		else
		{
			while (!BOOL_Player_Turn)
			{
				this_thread::sleep_for(chrono::seconds(3));
				PLAYER_Player.showBattleStats();
				cout << "   " << ENEMY_Enemy.getName() << "'s turn...";
				this_thread::sleep_for(chrono::seconds(2));
				PLAYER_Player.showBattleStats();
				ENEMY_Enemy.update(PLAYER_Player);
				this_thread::sleep_for(chrono::seconds(1));

				if (PLAYER_Player.getMeleeWeapon().hasModifiedAttribute() && PLAYER_Player.getMeleeWeapon().getAttributeType() == "Endurance")
				{
					cout << dye::aqua_on_light_aqua(" REDUCED ");
				}
				this_thread::sleep_for(chrono::seconds(1));
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
	else if (to_play == "Glacier Wasteland F6" || to_play == "Atlantis Ruins F7" || to_play == "Facility F7")
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
	else if (to_play == "Facility F1" || to_play == "Facility F2" || to_play == "Facility F3" || to_play == "Facility F4" || to_play == "Facility F5" || to_play == "Facility F6")
	{
		PlaySound(TEXT("music/facility_above_floors.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Facility F8" || to_play == "Facility F9" || to_play == "Facility F10")
	{
		PlaySound(TEXT("music/facility_below_floors.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Magma Fields F1" || to_play == "Magma Fields F2" || to_play == "Magma Fields F3")
	{
		PlaySound(TEXT("music/magma_fields_below_floors.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Magma Fields F4")
	{
		PlaySound(TEXT("music/magma_fields_above_floors.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Special Passage F1" || to_play == "Special Passage F2" || to_play == "Special Passage F3" || to_play == "Special Passage F4" || to_play == "Special Passage F5" || to_play == "Special Passage F6" || to_play == "Special Passage F7")
	{
		PlaySound(TEXT("music/special_passage.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Domain F1" || to_play == "Domain F2" || to_play == "Domain F3" || to_play == "Domain F4" || to_play == "Domain F5" || to_play == "Domain F6" || to_play == "Domain F7" || to_play == "Domain F8" || to_play == "Domain F9" || to_play == "Domain F10" || to_play == "Domain F11" || to_play == "Domain F12" || to_play == "Domain F13" || to_play == "Domain F14" || to_play == "Domain F15")
	{
		PlaySound(TEXT("music/domain.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Dungeon Battle")
	{
		PlaySound(TEXT("music/dungeon_battle.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Dungeon Mini Boss")
	{
		PlaySound(TEXT("music/dungeon_mini_boss.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Dungeon Main Boss")
	{
		PlaySound(TEXT("music/dungeon_main_boss.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Boss - The Mastermind Pt 2")
	{
		PlaySound(TEXT("music/boss_the_mastermind_part_1.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Boss - The Mastermind Pt 1")
	{
		PlaySound(TEXT("music/boss_the_mastermind_part_2.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Boss - Finale")
	{
		PlaySound(TEXT("music/boss_keeper_of_the_device.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Boss - Tyson Mondeo")
	{
		PlaySound(TEXT("music/boss_tyson_mondeo.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Story Battle")
	{
		PlaySound(TEXT("music/story_battle.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Dungeon: Special Mini Boss")
	{
		PlaySound(TEXT("music/dungeon_special_mini_boss.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Victory")
	{
		PlaySound(TEXT("music/victory.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Encounter")
	{
		PlaySound(TEXT("music/encounter.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Confront")
	{
		PlaySound(TEXT("music/confront.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Last Confront")
	{
		PlaySound(TEXT("music/confront_last.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Boss - Macko?")
	{
		PlaySound(TEXT("music/battle_fake_macko.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	else if (to_play == "Boss - Macko")
	{
		PlaySound(TEXT("music/boss_macko.wav"), NULL, SND_ASYNC | SND_LOOP);
		}
	else if (to_play == "Boss - Max")
	{
		PlaySound(TEXT("music/boss_max.wav"), NULL, SND_ASYNC | SND_LOOP);
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

// Outputs Enemy's name, HP, STA and Elements
void show_enemy_stats(Enemy ENEMY_Enemy)
{
	cout << "\n   " << dye::grey_on_white(" ") << dye::grey_on_white(ENEMY_Enemy.getName()) << dye::grey_on_white(" ") << dye::white_on_grey(" Lv ") << dye::white_on_grey(ENEMY_Enemy.getLevel()) << dye::white_on_grey(" ");
	int INT_Whole_Div;
	cout << dye::light_green("\n   HP: ") << dye::light_green(ENEMY_Enemy.getHealth()) << " ";
	INT_Whole_Div = float(ENEMY_Enemy.getHealth()) / float(ENEMY_Enemy.getMaxHealth()) * 20;
	if (INT_Whole_Div == 0)
	{
		INT_Whole_Div = 1;
	}
	for (int i = 0; i < INT_Whole_Div; i++)
	{
		cout << dye::black_on_light_green(" ");
	}
	for (int i = 0; i < 20 - INT_Whole_Div; i++)
	{
		cout << dye::black_on_grey(" ");
	}
	cout << dye::light_aqua("   STA: ") << dye::light_aqua(ENEMY_Enemy.getStamina()) << " ";
	INT_Whole_Div = float(ENEMY_Enemy.getStamina()) / float(ENEMY_Enemy.getMaxStamina()) * 20;
	for (int i = 0; i < INT_Whole_Div; i++)
	{
		cout << dye::black_on_light_aqua(" ");
	}
	for (int i = 0; i < 20 - INT_Whole_Div; i++)
	{
		cout << dye::black_on_grey(" ");
	}
	cout << "\n\n\n";	
	vector<string> VEC_Element_Names = { "Physical", "Fire", "Water", "Ice", "Electric", "Wind", "Curse", "Bless" };
	cout << "   " << dye::black_on_white(" Elements \n");
	for (int i = 0; i < 8; i++)
	{
		cout << ".  " << VEC_Element_Names[i] << ": ";
		if (ENEMY_Enemy.getElements().find(VEC_Element_Names[i])->second == "Wk")
		{
			cout << dye::light_yellow("Wk\n");
		}
		else if (ENEMY_Enemy.getElements().find(VEC_Element_Names[i])->second != "-")
		{
			cout << dye::light_red(ENEMY_Enemy.getElements().find(VEC_Element_Names[i])->second) << endl;
		}
		else
		{
			cout << "-\n";
		}
	}
	cout << endl;
	cout << "   " << dye::black_on_white(" Skills ");
	for (int i = 0; i < ENEMY_Enemy.getSkills().size(); i++)
	{
		cout << "\n   ";
		if (ENEMY_Enemy.getSkills()[i].getType() == "Physical")
		{
			cout << dye::grey(ENEMY_Enemy.getSkills()[i].getName());
		}
		else if (ENEMY_Enemy.getSkills()[i].getType() == "Fire")
		{
			cout << dye::light_red(ENEMY_Enemy.getSkills()[i].getName());
		}
		else if (ENEMY_Enemy.getSkills()[i].getType() == "Water")
		{
			cout << dye::light_blue(ENEMY_Enemy.getSkills()[i].getName());
		}
		else if (ENEMY_Enemy.getSkills()[i].getType() == "Ice")
		{
			cout << dye::blue(ENEMY_Enemy.getSkills()[i].getName());
		}
		else if (ENEMY_Enemy.getSkills()[i].getType() == "Electric")
		{
			cout << dye::yellow(ENEMY_Enemy.getSkills()[i].getName());
		}
		else if (ENEMY_Enemy.getSkills()[i].getType() == "Wind")
		{
			cout << dye::green(ENEMY_Enemy.getSkills()[i].getName());
		}
		else if (ENEMY_Enemy.getSkills()[i].getType() == "Curse")
		{
			cout << dye::light_purple(ENEMY_Enemy.getSkills()[i].getName());
		}
		else if (ENEMY_Enemy.getSkills()[i].getType() == "Bless")
		{
			cout << dye::light_yellow(ENEMY_Enemy.getSkills()[i].getName());
		}
		else if (ENEMY_Enemy.getSkills()[i].getType() == "Support")
		{
			cout << dye::light_green(ENEMY_Enemy.getSkills()[i].getName());
		}
		else if (ENEMY_Enemy.getSkills()[i].getType() == "Nuclear")
		{
			cout << dye::aqua(ENEMY_Enemy.getSkills()[i].getName());
		}
	}
	cout << endl;
}

// Outputs a specific Skill whilst in battle
void show_skill(Player PLAYER_Player, int INDEX_Skill, Enemy ENEMY_Enemy)
{
	vector<Skill> TEMP_Player_Skills = PLAYER_Player.getSkills();
	int INT_INDEX = INDEX_Skill;
	cout << "   " << dye::black_on_white(" ") << dye::black_on_white(TEMP_Player_Skills[INT_INDEX].getName()) << dye::black_on_white(" ");

	if (TEMP_Player_Skills[INT_INDEX].getType() != "Nuclear" && TEMP_Player_Skills[INT_INDEX].getType() != "Support")
	{
		if (ENEMY_Enemy.getElements().find(TEMP_Player_Skills[INT_INDEX].getType())->second == "Wk")
		{
			cout << dye::black_on_yellow(" WEAK ");
		}
		else if (ENEMY_Enemy.getElements().find(TEMP_Player_Skills[INT_INDEX].getType())->second == "Rst")
		{
			cout << dye::black_on_red(" RESIST ");
		}
		else if (ENEMY_Enemy.getElements().find(TEMP_Player_Skills[INT_INDEX].getType())->second == "Nul")
		{
			cout << dye::black_on_grey(" BLOCK ");
		}
		else if (ENEMY_Enemy.getElements().find(TEMP_Player_Skills[INT_INDEX].getType())->second == "Rpl")
		{
			cout << dye::red_on_light_red(" REPEL ");
		}
		else if (ENEMY_Enemy.getElements().find(TEMP_Player_Skills[INT_INDEX].getType())->second == "Abs")
		{
			cout << dye::red_on_grey(" ABSORB ");
		}
	}

	cout << "\n   Type: ";
	if (TEMP_Player_Skills[INT_INDEX].getType() == "Physical")
	{
		cout << dye::grey(TEMP_Player_Skills[INT_INDEX].getType());
	}
	else if (TEMP_Player_Skills[INT_INDEX].getType() == "Fire")
	{
		cout << dye::light_red(TEMP_Player_Skills[INT_INDEX].getType());
	}
	else if (TEMP_Player_Skills[INT_INDEX].getType() == "Water")
	{
		cout << dye::light_blue(TEMP_Player_Skills[INT_INDEX].getType());
	}
	else if (TEMP_Player_Skills[INT_INDEX].getType() == "Ice")
	{
		cout << dye::blue(TEMP_Player_Skills[INT_INDEX].getType());
	}
	else if (TEMP_Player_Skills[INT_INDEX].getType() == "Electric")
	{
		cout << dye::yellow(TEMP_Player_Skills[INT_INDEX].getType());
	}
	else if (TEMP_Player_Skills[INT_INDEX].getType() == "Wind")
	{
		cout << dye::green(TEMP_Player_Skills[INT_INDEX].getType());
	}
	else if (TEMP_Player_Skills[INT_INDEX].getType() == "Curse")
	{
		cout << dye::light_purple(TEMP_Player_Skills[INT_INDEX].getType());
	}
	else if (TEMP_Player_Skills[INT_INDEX].getType() == "Bless")
	{
		cout << dye::light_yellow(TEMP_Player_Skills[INT_INDEX].getType());
	}
	else if (TEMP_Player_Skills[INT_INDEX].getType() == "Support")
	{
		cout << dye::light_green(TEMP_Player_Skills[INT_INDEX].getType());
	}
	else if (TEMP_Player_Skills[INT_INDEX].getType() == "Nuclear")
	{
		cout << dye::aqua(TEMP_Player_Skills[INT_INDEX].getType());
	}
	cout << endl;
	cout << "   Desc: " << TEMP_Player_Skills[INT_INDEX].getDesc() << endl;

	if (TEMP_Player_Skills[INT_INDEX].getName() == "Heal" || TEMP_Player_Skills[INT_INDEX].getName() == "Healan" || TEMP_Player_Skills[INT_INDEX].getName() == "Healadia")
	{
		cout << dye::green("   HP+: ") << dye::green(TEMP_Player_Skills[INT_INDEX].getHPGain()) << endl;
	}
	else
	{
		cout << dye::light_red("   DMG: ") << dye::light_red(TEMP_Player_Skills[INT_INDEX].getBaseDamage()) << endl;
	}

	if (TEMP_Player_Skills[INT_INDEX].getType() == "Physical")
	{
		cout << dye::light_green("   HP: ") << dye::light_green(int(PLAYER_Player.getMaxHealth() * TEMP_Player_Skills[INT_INDEX].getHealthCostMultiplier())) << endl;
		cout << dye::light_yellow("   Hits: ") << dye::light_yellow(TEMP_Player_Skills[INT_INDEX].getPhysicalHitAmount()) << endl;
	}
	else
	{
		cout << dye::light_aqua("   STA: ") << dye::light_aqua(TEMP_Player_Skills[INT_INDEX].getStaminaCost()) << endl;
	}
	cout << "   [Skill " << (INT_INDEX + 1) << " of " << TEMP_Player_Skills.size() << "]";
}

void menuItems(Player& PLAYER_Player)
{
	string STR_Item_Page = "all";
	while (STR_Item_Page != "return")
	{
		system("CLS");
		cout << "\n   " << PLAYER_Player.getName() << "'s Inventory";
		if (STR_Item_Page == "consumables")
		{
			cout << " :: " << dye::light_green("HP: ") << dye::light_green(PLAYER_Player.getHealth()) << dye::light_green(" / ") << dye::light_green(PLAYER_Player.getMaxHealth()) << " | " << dye::light_aqua("STA: ") << dye::light_aqua(PLAYER_Player.getStamina()) << dye::light_aqua(" / ") << dye::light_aqua(PLAYER_Player.getMaxStamina());
		}
		cout << "\n   [ " << convert_string_toupper(STR_Item_Page) << " ] ";
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
						if (ITEM_Item->isMeleeWeapon() || ITEM_Item->canInheritSkill())
						{
							cout << "   ";
						}
						if (ITEM_Item->getName() == PLAYER_Player.getMeleeWeapon().getName() && ITEM_Item->getMeleeDamage() == PLAYER_Player.getMeleeWeapon().getMeleeDamage())
						{
							cout << dye::blue_on_aqua(" E ");
						}
						ITEM_Item->toString();
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
						cout << "   ";
						if (ITEM_Item->getName() == PLAYER_Player.getMeleeWeapon().getName() && ITEM_Item->getMeleeDamage() == PLAYER_Player.getMeleeWeapon().getMeleeDamage())
						{
							cout << dye::blue_on_aqua(" E ");
						}
						ITEM_Item->toString();
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
			cout << "   To use a consumable, type the name of item\n";
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
						cout << "   ";
						for (int i = 0; i < PLAYER_Player.getSkills().size(); i++)
						{
							if (ITEM_Item->getSkill().getName() == PLAYER_Player.getSkills()[i].getName())
							{
								cout << dye::blue_on_aqua(" " + to_string(i + 1) + " ");
							}
						}
						ITEM_Item->toString();
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

		// Checks to see if player uses a consumable
		for (Item* ITEM_Item : PLAYER_Player.getItems())
		{
			if (convert_string_tolower(ITEM_Item->getName()) == STR_Items_Input)
			{
				if (ITEM_Item->isConsumable())
				{
					if (ITEM_Item->getType() == "HP")
					{
						PLAYER_Player.changeHealth(ITEM_Item->getAmount());
						ITEM_Item->increaseQuantity(-1);
						if (ITEM_Item->getQuantity() == 0)
						{
							vector<Item*> TEMP_Player_Items = PLAYER_Player.getItems();
							TEMP_Player_Items.erase(find(TEMP_Player_Items.begin(), TEMP_Player_Items.end(), ITEM_Item));
							PLAYER_Player.setItems(TEMP_Player_Items);
						}
					}
					else if (ITEM_Item->getType() == "STA")
					{
						PLAYER_Player.changeStamina(ITEM_Item->getAmount());
						ITEM_Item->increaseQuantity(-1);
						if (ITEM_Item->getQuantity() == 0)
						{
							vector<Item*> TEMP_Player_Items = PLAYER_Player.getItems();
							TEMP_Player_Items.erase(find(TEMP_Player_Items.begin(), TEMP_Player_Items.end(), ITEM_Item));
							PLAYER_Player.setItems(TEMP_Player_Items);
						}
					}
					STR_Item_Page = "consumables";
				}
			}
		}

		if (STR_Item_Page != "weapons" && STR_Item_Page != "consumables" && STR_Item_Page != "skills" && STR_Item_Page != "items")
		{
			STR_Item_Page = "all";
		}
	}
}

void menuStats(Player PLAYER_Player)
{
	system("CLS");
	cout << "\n   " << dye::grey_on_white(" ") << dye::grey_on_white(PLAYER_Player.getName()) << dye::grey_on_white(" ") << " ";
	if (PLAYER_Player.getStarsOnFile().find("Main Story")->second == '*') cout << dye::yellow("*");
	if (PLAYER_Player.getStarsOnFile().find("Special World")->second == '*') cout << dye::yellow("*");
	if (PLAYER_Player.getStarsOnFile().find("Lv 99")->second == '*') cout << dye::yellow("*");
	if (PLAYER_Player.getStarsOnFile().find("Secret")->second == '*') cout << dye::yellow("*");
	PLAYER_Player.getPlayerStats();
	PLAYER_Player.getPlayerElements();
	cout << "\n.  St: ";
	if (PLAYER_Player.getPlayerAttributes().find("Strength")->second < 10) cout << "0";
	cout << PLAYER_Player.getPlayerAttributes().find("Strength")->second << " ";
	for (int i = 0; i < PLAYER_Player.getPlayerAttributes().find("Strength")->second; i++)
	{
		cout << dye::black_on_bright_white(" ");
	}
	for (int i = 0; i < (99 - PLAYER_Player.getPlayerAttributes().find("Strength")->second); i++)
	{
		cout << dye::black_on_grey(" ");
	}
	cout << "\n.  Ma: ";
	if (PLAYER_Player.getPlayerAttributes().find("Magic")->second < 10) cout << "0";
	cout << PLAYER_Player.getPlayerAttributes().find("Magic")->second << " ";
	for (int i = 0; i < PLAYER_Player.getPlayerAttributes().find("Magic")->second; i++)
	{
		cout << dye::black_on_bright_white(" ");
	}
	for (int i = 0; i < (99 - PLAYER_Player.getPlayerAttributes().find("Magic")->second); i++)
	{
		cout << dye::black_on_grey(" ");
	}
	cout << "\n.  En: ";
	if (PLAYER_Player.getPlayerAttributes().find("Endurance")->second < 10) cout << "0";
	cout << PLAYER_Player.getPlayerAttributes().find("Endurance")->second << " ";
	for (int i = 0; i < PLAYER_Player.getPlayerAttributes().find("Endurance")->second; i++)
	{
		cout << dye::black_on_bright_white(" ");
	}
	for (int i = 0; i < (99 - PLAYER_Player.getPlayerAttributes().find("Endurance")->second); i++)
	{
		cout << dye::black_on_grey(" ");
	}
	cout << endl << endl;
	cout << "   Equipped Skills:";
	for (int i = 0; i < PLAYER_Player.getSkills().size(); i++)
	{
		cout << "\n   " << dye::light_purple(PLAYER_Player.getSkills()[i].getName());
	}
	cout << "\n\n   Equipped Melee:\n   ";
	PLAYER_Player.getMeleeWeapon().toString();
	cout << endl << endl;
	system("pause");
	cout << "\033[A" << "\33[2K\r" << endl;
}

void menuTravel(vector<Dungeon*>& VEC_Visited_Dungeons, Dungeon*& DUNGEON_Current_Dungeon)
{
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
				if (DUNGEON_Dungeon->getDungeonName() == DUNGEON_Current_Dungeon->getDungeonName())
				{
					DUNGEON_Dungeon = DUNGEON_Current_Dungeon;
				}
			}
			cout << "\n   > ";
			getline(cin, STR_Dungeon_Choice);
			for (int i = 0; i < VEC_Visited_Dungeons.size(); i++)
			{
				if (convert_string_tolower(STR_Dungeon_Choice) == convert_string_tolower(VEC_Visited_Dungeons[i]->getDungeonName()))
				{
					BOOL_Is_Valid_Travel = true;
					DUNGEON_Current_Dungeon = VEC_Visited_Dungeons[i];
					system("CLS");
					cout << "\n   Travelling to " << VEC_Visited_Dungeons[i]->getDungeonName();
					this_thread::sleep_for(chrono::seconds(2));
					play_audio(DUNGEON_Current_Dungeon->getDungeonName() + " F" + to_string(DUNGEON_Current_Dungeon->getDungeonRoom()));
					break;
				}
			}
		}
	}
}

void saveGame(Player PLAYER_Player, vector<Dungeon*> VEC_Visited_Dungeons)
{
	ofstream file("data/player_" + PLAYER_Player.getName() + ".txt");
	vector<string> VEC_Player_Data = PLAYER_Player.saveData(VEC_Visited_Dungeons);
	for (string STR_Data_Line : VEC_Player_Data)
	{
		file << STR_Data_Line << "\n";
	}
	file.close();
	cout << dye::light_green("\n\n   Saved sucessfully!\n");
	cout << dye::green("   Your player data was sent to: data/player_") << dye::green(PLAYER_Player.getName()) << dye::green(".txt\n\n   ");
	system("pause");
}

void closeGame()
{
	cout << dye::red("\n\n   Closing game...");
	this_thread::sleep_for(chrono::seconds(2));
	exit(0);
}