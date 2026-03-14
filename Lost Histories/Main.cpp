#include "Player.h"
#include "Enemy.h"
#include "Skill.h"
#include "Story.h"
#include "Item.h"
#include "ItemSkill.h"
#include "ItemMelee.h"
#include "DungeonGlacier.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <Windows.h>
#include "mmsystem.h"
#pragma comment(lib, "winmm.lib")

using namespace std;

/* 

###### LOST HISTORIES ######
Last Updated: 24/02/26 (15:37)

--- Parent Classes ---
. BattleStat	# Contains key variables to battles such as health and stamina values
				: Player, Enemy
. Item			# Contains name, description and rarity of an item
                : ItemMelee, ItemSkill
. Dungeon       # Contains name, floor number
				: DungeonGlacier

--- Child Classes ---
. Enemy		     : Inherits BattleStat
. DungeonGlacier : Inherits Dungeon, dungeon 1 of the game
. ItemMelee      : Inherits Item, is the player's current melee weapon
. ItemSkill      : Inherits Item, an item which contains a skill the player can inherit
. Player         : Inherits BattleStat, contains all things the player can do and their stats

--- Classes ---
. Skill			: Contains name, description, type, damage/healing value and stamina cost of a skill
. Story			: Contains a vector which has all story dialogue and functions which alter the pathing

############################

 */

string convert_string_tolower(string text); // Quite obvious 1
string convert_string_toupper(string text); // Quite obvious 2
void set_starting_elements(int& weak_element, int& resist_element); // Sets the starting elements (weakness and resistant)
void show_enemy_stats(Enemy enemy); // Shows the enemy's battle stats
void show_battle_stats(Player player); // Shows the player's battle stats (name, hp, sta)
void show_skill(Player player, int index); // Shows the player's current skill
void dialogue_input(Player player, string dialogue_choice); // Story player input
int main_menu(); // Main menu when the game is executed
void battle(Player& player, Dungeon* current_dungeon, Enemy enemy); // Battle sequence
void map_movement(string dialogue_choice, Player& player, Enemy& newEnemy, Dungeon* current_dungeon); // Map Movement
void open_chest(Player& player, Dungeon* current_dungeon); // Open chests
void play_audio(string to_play); // Plays music

enum storyStatus
{
	TUTORIAL,
	ACT_ONE_EXPLORE,
	ACT_TWO_EXPLORE,
};

/* ---------------------------------------------------------------------------------------------------- */

// MAIN PROGRAM
int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	main_menu();
	// Setup
	string player_name;
	string dialogue_choice;
	storyStatus story_status = storyStatus::TUTORIAL;
	int weak_element = -1;
	int resist_element = -1;
	cout << "\n   Your Character Name: "; 
	getline(cin, player_name);
	set_starting_elements(weak_element, resist_element); // Player chooeses their starting elements
	Player player = Player(player_name, weak_element, resist_element, 1, 140, 62); // Instantiates object of type Player
	Story story = Story(player_name); // Instantiates object of type Story
	system("CLS");
	cout << ">>> TYPE /help TO VIEW ALL POSSIBLE COMMANDS <<<" << endl << endl;

	// INTRO DIALOGUE/TUTORIAL BATTLE
	while (story_status == storyStatus::TUTORIAL && !story.isEvent())
	{
		cout << "   " << story.getDialogue() << endl;
		story.increaseDialogueIndex();
		if (story.getDialogue() == "END DIALOGUE")
		{
			story.endOfDialogue();
		}
		cin >> dialogue_choice;
		dialogue_input(player, dialogue_choice);
	}
	DungeonGlacier current_dungeon = DungeonGlacier();
	Enemy newEnemy = Enemy("Ice Monster", 1, 10, 24, { Skill("Freeze") }, new ItemSkill("Ice Core", "A strange looking block of ice", 1, Skill("Freeze")), false, 12);
	play_audio("Dungeon Battle");
	battle(player, &current_dungeon, newEnemy);
	story.startOfDialogue();
	story.increaseDialogueIndex();
	story_status = storyStatus::ACT_ONE_EXPLORE;

	// DUNGEON 1: GLACIER WASTELAND
	current_dungeon.fillWithEnemies();
	current_dungeon.fillWithChests();
	play_audio(current_dungeon.getDungeonName() + " F" + to_string(current_dungeon.getDungeonRoom()));
	while (story_status == storyStatus::ACT_ONE_EXPLORE)
	{
		system("CLS");
		cout << "\n   " << current_dungeon.getDungeonName() << " " << current_dungeon.getDungeonRoom() << "F\n\n";
		for (int i = 0; i < 15; i++)
		{
			cout << "   ";
			for (int j = 0; j < 15; j++)
			{
				if (current_dungeon.getDungeonMap()[(current_dungeon.getDungeonRoom() - 1)][i][j] == 'O')
				{
					cout << "  ";
				}
				else
				{
					cout << current_dungeon.getDungeonMap()[(current_dungeon.getDungeonRoom() - 1)][i][j] << " ";
				}
				if (current_dungeon.getDungeonMap()[(current_dungeon.getDungeonRoom() - 1)][i][j] == '+')
				{
					current_dungeon.setPosX(j);
					current_dungeon.setPosY(i);
				}
				if (story.isEvent())
				{
					if (i == 1 && j == 14)
					{
						cout << "          Controls";
					}
					if (i == 2 && j == 14)
					{
						cout << "          W: Up";
					}
					if (i == 3 && j == 14)
					{
						cout << "          A: Left";
					}
					if (i == 4 && j == 14)
					{
						cout << "          S: Down";
					}
					if (i == 5 && j == 14)
					{
						cout << "          D: Right";
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
						cout << "          X: " << current_dungeon.getPosX() << " | Y: " << current_dungeon.getPosY();
					}
				}
			}
			cout << endl;
		}
		cout << "\n\n\n";
		if (!story.isEvent())
		{
			cout << "   " << story.getDialogue() << endl;
			story.increaseDialogueIndex();
			if (story.getDialogue() == "END DIALOGUE")
			{
				story.endOfDialogue();
			}
		}
		else
		{
			cout << "   > ";
		}
		cin >> dialogue_choice;
		dialogue_choice = convert_string_tolower(dialogue_choice);
		dialogue_input(player, dialogue_choice);
		map_movement(dialogue_choice, player, newEnemy, &current_dungeon);
	}
}

int main_menu()
{
	string menu_choice;
	while (menu_choice != "new game" && menu_choice != "load game" && menu_choice != "settings" && menu_choice != "quit")
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
		cout << "\n\n";
		cout << "--> New Game\n--> Load Game\n--> Settings\n--> Credits\n--> Quit\n\n> ";
		getline(cin, menu_choice);
		menu_choice = convert_string_tolower(menu_choice);
	}
	system("CLS");
	if (menu_choice == "new game")
	{
		return 0;
	}
	if (menu_choice == "load game")
	{
		cout << "Sorry but this feature doesn't exist yet, please restart the game\n";
		exit(0);
	}
	if (menu_choice == "settings")
	{
		cout << "Sorry but this feature doesn't exist yet, please restart the game\n";
		exit(0);
	}
	if (menu_choice == "credits")
	{
		cout << "Sorry but this feature doesn't exist yet, please restart the game\n";
		exit(0);
	}
	if (menu_choice == "quit")
	{
		exit(0);
	}
	return 0;
}

void map_movement(string dialogue_choice, Player& player, Enemy& newEnemy, Dungeon* current_dungeon)
{
	if (dialogue_choice == "d")
	{
		if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() + 1)) == ' ')
		{
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), current_dungeon->getPosX(), ' ');
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() + 1), '+');
			current_dungeon->changePosY(1);
		}
		else if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() + 1)) == '!')
		{
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), current_dungeon->getPosX(), ' ');
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() + 1), '+');
			current_dungeon->changePosY(1);
			Enemy newEnemy = current_dungeon->newEnemy(current_dungeon);
			play_audio("Dungeon Battle");
			battle(player, current_dungeon, newEnemy);
		}
		else if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() + 1)) == '>')
		{
			current_dungeon->changeDungeonRoom(1);
			play_audio(current_dungeon->getDungeonName() + " F" + to_string(current_dungeon->getDungeonRoom()));

		}
		else if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() + 1)) == '*')
		{
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), current_dungeon->getPosX(), ' ');
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() + 1), '+');
			current_dungeon->changePosY(1);
			open_chest(player, current_dungeon);
			cout << "\n\n";
			system("pause");
		}

		if (current_dungeon->getDungeonName() == "Glacier Wasteland")
		{
			if (current_dungeon->getDungeonRoom() == 3)
			{
				if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() + 1)) == '|')
				{
					bool hasKey = false;
					for (Item* item : player.getItems())
					{
						if (item->getName() == "Glacier F3 Key")
						{
							hasKey = true;
						}
					}
					if (hasKey)
					{
						current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), current_dungeon->getPosX(), ' ');
						current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() + 1), '+');
						current_dungeon->changePosY(1);
					}
					else
					{
						cout << "   Requires Glacier F3 Key";
						this_thread::sleep_for(chrono::seconds(2));
					}
				}
			}
			else if (current_dungeon->getDungeonRoom() == 5)
			{
				if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() + 1)) == '|')
				{
					bool hasKey = false;
					for (Item* item : player.getItems())
					{
						if (item->getName() == "Glacier F5 Key")
						{
							hasKey = true;
						}
					}
					if (hasKey)
					{
						current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), current_dungeon->getPosX(), ' ');
						current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() + 1), '+');
						current_dungeon->changePosY(1);
					}
					else
					{
						cout << "   Requires Glacier F5 Key";
						this_thread::sleep_for(chrono::seconds(2));
					}
				}
			}
			else if (current_dungeon->getDungeonRoom() == 6)
			{
				if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() + 1)) == '?')
				{
					current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), current_dungeon->getPosX(), ' ');
					current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() + 1), '+');
					current_dungeon->changePosY(1);
					Enemy newEnemy = Enemy("Russian Sergeant", 18, 537, 93, { Skill("Meflamao"), Skill("Freezan"), Skill("Gust"), Skill("Meblight"), Skill("Hex")}, new ItemSkill("Battery Reserve", "Incase of power cut emergencies", 4, Skill("Mezapao")), true, 56);
					play_audio("Dungeon Main Boss");
					battle(player, current_dungeon, newEnemy);
				}
			}
		}
	}
	if (dialogue_choice == "a")
	{
		if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() - 1)) == ' ')
		{
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), current_dungeon->getPosX(), ' ');
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() - 1), '+');
			current_dungeon->changePosY(-1);
		}
		else if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() - 1)) == '!')
		{
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), current_dungeon->getPosX(), ' ');
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() - 1), '+');
			current_dungeon->changePosY(-1);
			Enemy newEnemy = current_dungeon->newEnemy(current_dungeon);
			play_audio("Dungeon Battle");
			battle(player, current_dungeon, newEnemy);
		}
		else if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() - 1)) == '<')
		{
			current_dungeon->changeDungeonRoom(-1);
			play_audio(current_dungeon->getDungeonName() + " F" + to_string(current_dungeon->getDungeonRoom()));
		}
		else if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() - 1)) == '*')
		{
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), current_dungeon->getPosX(), ' ');
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() - 1), '+');
			current_dungeon->changePosY(-1);
			open_chest(player, current_dungeon);
			cout << "\n\n";
			system("pause");
		}
		else if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() - 1)) == '?')
		{
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), current_dungeon->getPosX(), ' ');
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() - 1), '+');
			current_dungeon->changePosY(-1);
			if (current_dungeon->getDungeonName() == "Glacier Wasteland")
			{
				if (current_dungeon->getDungeonRoom() == 3) // Snow Golem Mini Boss, drops key used to advance
				{
					Enemy newEnemy = Enemy("Snow Golem", 10, 232, 54, { Skill("Mefreeze"), Skill("Freezan"), Skill("Hex") }, new Item("Glacier F3 Key", "Frozen key lost in time, maybe can be used for something?", 3), true, 31);
					play_audio("Dungeon Mini Boss");
					battle(player, current_dungeon, newEnemy);
				}
				else if (current_dungeon->getDungeonRoom() == 5) // Duty Soldier Mini Boss, drops key used to advance
				{
					Enemy newEnemy = Enemy("Duty Soldier", 15, 384, 67, { Skill("Flame"), Skill("Zap"), Skill("Zapao"), Skill("Blight")}, new Item("Glacier F5 Key", "Frozen key lost in time, maybe can be used for something?", 3), true, 37);
					play_audio("Dungeon Mini Boss");
					battle(player, current_dungeon, newEnemy);
				}
			}
		}

	}
	if (dialogue_choice == "w")
	{
		if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), (current_dungeon->getPosY() - 1), current_dungeon->getPosX()) == ' ')
		{
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), current_dungeon->getPosX(), ' ');
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), (current_dungeon->getPosY() - 1), current_dungeon->getPosX(), '+');
			current_dungeon->changePosX(-1);
		}
		else if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), (current_dungeon->getPosY() - 1), current_dungeon->getPosX()) == '!')
		{
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), current_dungeon->getPosX(), ' ');
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), (current_dungeon->getPosY() - 1), current_dungeon->getPosX(), '+');
			current_dungeon->changePosX(-1);
			Enemy newEnemy = current_dungeon->newEnemy(current_dungeon);
			play_audio("Dungeon Battle");
			battle(player, current_dungeon, newEnemy);
		}
		else if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), (current_dungeon->getPosY() - 1), current_dungeon->getPosX()) == '*')
		{
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), current_dungeon->getPosX(), ' ');
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), (current_dungeon->getPosY() - 1), current_dungeon->getPosX(), '+');
			current_dungeon->changePosX(-1);
			open_chest(player, current_dungeon);
			cout << "\n\n";
			system("pause");
		}
	}
	if (dialogue_choice == "s")
	{
		if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), (current_dungeon->getPosY() + 1), current_dungeon->getPosX()) == ' ')
		{
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), current_dungeon->getPosX(), ' ');
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), (current_dungeon->getPosY() + 1), current_dungeon->getPosX(), '+');
			current_dungeon->changePosX(1);
		}
		else if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), (current_dungeon->getPosY() + 1), current_dungeon->getPosX()) == '!')
		{
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), current_dungeon->getPosX(), ' ');
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), (current_dungeon->getPosY() + 1), current_dungeon->getPosX(), '+');
			current_dungeon->changePosX(1);
			Enemy newEnemy = current_dungeon->newEnemy(current_dungeon);
			play_audio("Dungeon Battle");
			battle(player, current_dungeon, newEnemy);
		}
		else if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), (current_dungeon->getPosY() + 1), current_dungeon->getPosX()) == '*')
		{
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), current_dungeon->getPosX(), ' ');
			current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), (current_dungeon->getPosY() + 1), current_dungeon->getPosX(), '+');
			current_dungeon->changePosX(1);
			open_chest(player, current_dungeon);
			cout << "\n\n";
			system("pause");
		}
	}
}

void open_chest(Player& player, Dungeon* current_dungeon)
{
	vector<Item*> chestLoot;
	if (current_dungeon->getDungeonName() == "Glacier Wasteland")
	{
		chestLoot =
		{
			new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1),
			new Item("Ripped Shoes", "A pair of ripped shoes", 1),
			new Item("Foreign Coin", "A coin which you don't recognise", 2),
			new ItemMelee("Nail Board", "Plank of frozen wood with a nail pointing out the end", 2, 17),
			new ItemMelee("Ice-Axe", "Battleaxe frozen to time", 3, 29),
			new ItemSkill("Box of Matches", "Withered box of fire matches, can they still alight?", 2, Skill("Meflame")),
			new ItemSkill("Old Cross", "An old church cross emitting a blessing aura", 3, Skill("Blighta"))
		};
		if (current_dungeon->getDungeonRoom() >= 3)
		{
			chestLoot.push_back(new ItemMelee("Ice Crossbow", "Icified crossbow which fires icicles", 3, 46));
		}
		if (current_dungeon->getDungeonRoom() >= 4)
		{
			chestLoot.push_back(new ItemSkill("Goat Horn", "Remains of what looks like a goat, what is it even doing here?", 2, Skill("Megust")));
			chestLoot.push_back(new ItemMelee("Wingman", "Familiar looking revolver, it seems damaged but could still work", 4, 97));
		}
		if (current_dungeon->getDungeonRoom() >= 5)
		{
			chestLoot.push_back(new Item("Chipped Diamond", "Exposed diamond which appears chipped and frozen over, might still carry some value", 4));
			chestLoot.push_back(new ItemSkill("Electrical Wire", "Exposed electric wire that still packs some spark", 3, Skill("Zapao")));
			chestLoot.push_back(new ItemSkill("Old Pendant", "An old heart pendant emitting a healthy aura", 3, Skill("Heal")));
		}
	}
	Item* newItem = chestLoot[rand() % (chestLoot.size() - 1)];
	bool itemDupe = false;
	for (Item* item : player.getItems())
	{
		if (newItem->getName() == item->getName())
		{
			item->increaseQuantity(1);
			itemDupe = true;
		}
	}
	if (!itemDupe)
	{
		player.addItem(newItem);
	}
	cout << "   Something is shining on the ground...\n\n";
	this_thread::sleep_for(chrono::seconds(2));
	cout << "   You found " << newItem->getName() << "!";
	if (!itemDupe)
	{
		cout << " (NEW)";
	}
	cout << "\n\n";
	cout << newItem->toString();
	player.update();
	this_thread::sleep_for(chrono::seconds(2));
	if (newItem->isMeleeWeapon() && !itemDupe)
	{
		cout << "\n\n   You currently have " << player.getMeleeWeapon().getName() << " equipped.\n   Would you like to replace it with " << newItem->getName() << "? [y] or [n]\n\n   Atk: " << player.getMeleeWeapon().getMeleeDamage() << " --> " << newItem->getMeleeDamage() << "\n\n>";
		string choice;
		cin >> choice;
		while (convert_string_tolower(choice) != "y" && convert_string_tolower(choice) != "n")
		{
			if (convert_string_tolower(choice) == "y" || convert_string_tolower(choice) == "n") break;
			cout << "   [!] Please choose 'y' or 'n': ";
			cin >> choice;
		}
		if (convert_string_tolower(choice) == "y")
		{
			ItemMelee newPlayerMelee = ItemMelee(newItem->getName(), newItem->getDesc(), newItem->getRarity(), newItem->getMeleeDamage());
			player.setMelee(newPlayerMelee);
			cout << "\n\n   You equipped " << player.getMeleeWeapon().getName();
		}
		else
		{
			cout << "\n\n   You decided to keep " << player.getMeleeWeapon().getName() << " equipped";
		}
		this_thread::sleep_for(chrono::seconds(2));
	}
}

void battle(Player& player, Dungeon* current_dungeon, Enemy enemy)
{
	system("CLS");
	bool player_turn = true; // Is it player turn or enemy turn?
	bool battle = true; // Whilst the battle is in play
	string choice; // Selecting a skill
	string player_page; // Battle menu page
	Item* enemyDrop = enemy.getDroppedItem();
	current_dungeon->elementSetter(enemy);
	enemy.setHealth();
	int skillIndex = 0; // Selected skill index (to display)
	cout << "\n   You have encountered " << enemy.getName() << endl;
	this_thread::sleep_for(chrono::seconds(3));
	player.update();
	// Battle Loop
	while (battle)
	{
		bool validSkill = false;
		player_page = "";
		while (player_turn)
		{
			// Starts the player's turn
			player.setGuard(false);
			while ((player_page != "melee") && (player_page != "skill") && (player_page != "item") && (player_page != "guard") && (player_page != "analyse"))
			{
				show_battle_stats(player);
				cout << "\n--> Melee\n--> Skill\n--> Item\n--> Guard\n--> Analyse\n\n  > ";
				getline(cin, player_page);
				player_page = convert_string_tolower(player_page);
			}
			while (player_page == "item" && player_turn)
			{
				system("CLS");
				show_battle_stats(player);
				cout << endl;
				bool hasItems = false;
				for (Item* item : player.getItems())
				{
					if (item->isConsumable() && item->getQuantity() > 0)
					{
						hasItems = true;
					}
				}
				if (!hasItems)
				{
					cout << "   You have no useable items currently." << endl;
					this_thread::sleep_for(chrono::seconds(2));
					player_page = "";
				}
				else
				{
					for (Item* item : player.getItems())
					{
						if (item->isConsumable())
						{
							cout << item->toString() << endl << endl;
						}
					}
					cout << "--> Return\n\n  > ";
					getline(cin, choice);
					choice = convert_string_tolower(choice);
					for (Item* item : player.getItems())
					{
						if (convert_string_tolower(item->getName()) == choice && item->isConsumable())
						{
							system("CLS");
							show_battle_stats(player);
							if (item->getType() == "HP")
							{
								player.changeHealth(item->getAmount());
								if (player.getHealth() > player.getMaxHealth())
								{
									player.fullHealth();
								}
							}
							else if (item->getType() == "STA")
							{
								player.changeStamina(item->getAmount());
								if (player.getStamina() > player.getMaxStamina())
								{
									player.fullStamina();
								}
							}
							cout << "\n   You used " << item->getName() << " restoring " << item->getAmount() << " " << item->getType();
							item->increaseQuantity(-1);
							if (item->getQuantity() == 0)
							{
								vector<Item*> temp_player_items = player.getItems();
								temp_player_items.erase(find(temp_player_items.begin(), temp_player_items.end(), item));
								player.setItems(temp_player_items);
							}
							player_turn = false;
							break;
						}
					}
					if (choice == "return" || choice == "r")
					{
						player_page = "";
						break;
					}
				}
			}
			// Page : Skill
			while (player_page == "skill")
			{
				system("CLS");
				show_battle_stats(player);
				cout << endl;
				if (player.getSkills().empty())
				{
					cout << "   You have no skills currently." << endl;
					this_thread::sleep_for(chrono::seconds(2));
					player_page = "";
				}
				else
				{
					show_skill(player, skillIndex);
					cout << "\n\n--> Next\n--> Back\n--> Return\n\n  > ";
					getline(cin, choice);
					choice = convert_string_tolower(choice);
					// Validates if the skill selected exists
					for (Skill skill : player.getSkills())
					{
						if ((choice == convert_string_tolower(skill.getName())) && (player.getStamina() >= skill.getStaminaCost()))
						{
							Skill skillSelected = skill;
							system("CLS");
							show_battle_stats(player);
							// Determines what the skill does
							if (skillSelected.getType() == "support")
							{
								// Heal the player
								player.changeHealth(skillSelected.getHPGain());
								cout << "\n   You have healed yourself restoring " << skillSelected.getHPGain() << " health\n\n";
							}
							else
							{
								// Damage the enemy
								if (true)
								{
									if (skillSelected.getType() == "fire")
									{
										if (enemy.getElements()[0] == "Wk")
										{
											cout << "\n   You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << int(skillSelected.getBaseDamage() * 1.5) << " damage (WEAK)\n\n";
											enemy.changeHealth(-int(skillSelected.getBaseDamage() * 1.5));

										}
										else if (enemy.getElements()[0] == "Rst")
										{
											cout << "\n   You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << int(skillSelected.getBaseDamage() * 0.5) << " damage (RESIST)\n\n";
											enemy.changeHealth(-int(skillSelected.getBaseDamage() * 0.5));
										}
										else
										{
											cout << "\n   You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << skillSelected.getBaseDamage() << " damage\n\n";
											enemy.changeHealth(-(skillSelected.getBaseDamage()));
										}
									}
									else if (skillSelected.getType() == "ice")
									{
										if (enemy.getElements()[1] == "Wk")
										{
											cout << "\n   You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << int(skillSelected.getBaseDamage() * 1.5) << " damage (WEAK)\n\n";
											enemy.changeHealth(-int(skillSelected.getBaseDamage() * 1.5));

										}
										else if (enemy.getElements()[1] == "Rst")
										{
											cout << "\n   You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << int(skillSelected.getBaseDamage() * 0.5) << " damage (RESIST)\n\n";
											enemy.changeHealth(-int(skillSelected.getBaseDamage() * 0.5));
										}
										else
										{
											cout << "\n   You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << skillSelected.getBaseDamage() << " damage\n\n";
											enemy.changeHealth(-(skillSelected.getBaseDamage()));
										}
									}
									else if (skillSelected.getType() == "electric")
									{
										if (enemy.getElements()[2] == "Wk")
										{
											cout << "\n   You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << int(skillSelected.getBaseDamage() * 1.5) << " damage (WEAK)\n\n";
											enemy.changeHealth(-int(skillSelected.getBaseDamage() * 1.5));

										}
										else if (enemy.getElements()[2] == "Rst")
										{
											cout << "\n   You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << int(skillSelected.getBaseDamage() * 0.5) << " damage (RESIST)\n\n";
											enemy.changeHealth(-int(skillSelected.getBaseDamage() * 0.5));
										}
										else
										{
											cout << "\n   You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << skillSelected.getBaseDamage() << " damage\n\n";
											enemy.changeHealth(-(skillSelected.getBaseDamage()));
										}
									}
									else if (skillSelected.getType() == "wind")
									{
										if (enemy.getElements()[3] == "Wk")
										{
											cout << "\n   You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << int(skillSelected.getBaseDamage() * 1.5) << " damage (WEAK)\n\n";
											enemy.changeHealth(-int(skillSelected.getBaseDamage() * 1.5));

										}
										else if (enemy.getElements()[3] == "Rst")
										{
											cout << "\n   You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << int(skillSelected.getBaseDamage() * 0.5) << " damage (RESIST)\n\n";
											enemy.changeHealth(-int(skillSelected.getBaseDamage() * 0.5));
										}
										else
										{
											cout << "\n   You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << skillSelected.getBaseDamage() << " damage\n\n";
											enemy.changeHealth(-(skillSelected.getBaseDamage()));
										}
									}
									else if (skillSelected.getType() == "curse")
									{
										if (enemy.getElements()[4] == "Wk")
										{
											cout << "\n   You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << int(skillSelected.getBaseDamage() * 1.5) << " damage (WEAK)\n\n";
											enemy.changeHealth(-int(skillSelected.getBaseDamage() * 1.5));

										}
										else if (enemy.getElements()[4] == "Rst")
										{
											cout << "\n   You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << int(skillSelected.getBaseDamage() * 0.5) << " damage (RESIST)\n\n";
											enemy.changeHealth(-int(skillSelected.getBaseDamage() * 0.5));
										}
										else
										{
											cout << "\n   You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << skillSelected.getBaseDamage() << " damage\n\n";
											enemy.changeHealth(-(skillSelected.getBaseDamage()));
										}
									}
									else if (skillSelected.getType() == "bless")
									{
										if (enemy.getElements()[5] == "Wk")
										{
											cout << "\n   You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << int(skillSelected.getBaseDamage() * 1.5) << " damage (WEAK)\n\n";
											enemy.changeHealth(-int(skillSelected.getBaseDamage() * 1.5));

										}
										else if (enemy.getElements()[5] == "Rst")
										{
											cout << "\n   You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << int(skillSelected.getBaseDamage() * 0.5) << " damage (RESIST)\n\n";
											enemy.changeHealth(-int(skillSelected.getBaseDamage() * 0.5));
										}
										else
										{
											cout << "\n   You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << skillSelected.getBaseDamage() << " damage\n\n";
											enemy.changeHealth(-(skillSelected.getBaseDamage()));
										}
									}
									else if (skillSelected.getType() == "nuclear")
									{
										cout << "\n   You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << skillSelected.getBaseDamage() << " damage\n\n";
										enemy.changeHealth(-(skillSelected.getBaseDamage()));
									}
								}
								else
								{
									cout << "\n   You casted " << skillSelected.getName() << " upon all enemies dealing " << skillSelected.getBaseDamage() << " damage each\n\n";
								}
							}
							player.changeStamina(-skillSelected.getStaminaCost());
							player_turn = false;
							break;
						}
					}
					if (!player_turn) break;
					// If choice is "next", show the player their next skill
					if (choice == "next" || choice == "n" || choice == ">")
					{
						skillIndex++;
						if (skillIndex > player.getSkills().size() - 1)
						{
							skillIndex = 0;
						}
					}
					// If choice is "back", show the player their previous skill
					else if (choice == "back" || choice == "b" || choice == "<")
					{
						skillIndex--;
						if (skillIndex < 0)
						{
							skillIndex = player.getSkills().size() - 1;
						}
					}
					// If choice is "return", take the player back to the main battle menu
					else if (choice == "return" || choice == "r")
					{
						player_page = "";
						break;
					}
				}
			}
			// Page : Melee
			while (player_page == "melee")
			{
				system("CLS");
				show_battle_stats(player);
				cout << endl;
				cout << player.getMeleeWeapon().toString();
				cout << "\n\n--> Use\n--> Return\n\n  > ";
				getline(cin, choice);
				choice = convert_string_tolower(choice);

				// If choice is "use", attack the enemy with melee weapon
				if (choice == "use" || choice == "u")
				{
					int critical_chance = (rand() % 100) + 1;
					system("CLS");
					show_battle_stats(player);
					if (critical_chance > 79)
					{
						cout << "\n   You attacked " << enemy.getName() << " using " << player.getMeleeWeapon().getName() << " landing a CRITICAL HIT dealing " << (player.getMeleeWeapon().getMeleeDamage() * 2) << " damage\n\n";
						enemy.changeHealth(-(player.getMeleeWeapon().getMeleeDamage() * 2));
					}
					else
					{
						cout << "\n   You attacked " << enemy.getName() << " using " << player.getMeleeWeapon().getName() << " dealing " << player.getMeleeWeapon().getMeleeDamage() << " damage\n\n";
						enemy.changeHealth(-(player.getMeleeWeapon().getMeleeDamage()));
					}
					player_turn = false;
					break;
				}
				// If choice is "return", take the player back to the main battle menu
				else if (choice == "return" || choice == "r")
				{
					player_page = "";
					break;
				}
			}
			// Page : Guard
			while (player_page == "guard")
			{
				system("CLS");
				show_battle_stats(player);
				cout << endl;
				cout << "   Reduce incoming damage by 33% and negates weaknesses\n   (Does stack if resistant)";
				cout << "\n\n--> Guard\n--> Return\n\n  > ";
				getline(cin, choice);
				choice = convert_string_tolower(choice);

				// If choice is "guard", guards against incoming attack
				if (choice == "guard" || choice == "g")
				{
					system("CLS");
					show_battle_stats(player);
					player.setGuard(true);
					cout << "\n   You have guarded yourself\n\n";
					player_turn = false;
					break;
				}
				// If choice is "return", take the player back to the main battle menu
				else if (choice == "return" || choice == "r")
				{
					player_page = "";
					break;
				}
			}
			// Page : Analyse
			while (player_page == "analyse")
			{
				system("CLS");
				show_enemy_stats(enemy);
				cout << "\n   Item: " << enemyDrop->getName();
				cout << "\n\n--> Return\n\n  > ";
				getline(cin, choice);
				choice = convert_string_tolower(choice);

				// If choice is "return", take the player back to the main battle menu
				if (choice == "return" || choice == "r")
				{
					player_page = "";
					break;
				}
			}
		}
		if (enemy.getHealth() <= 0)
		{
			play_audio("Victory");
			float exp_earned;
			bool itemDupe = false;
			if (enemy.isBoss())
			{
				exp_earned = enemy.getMaxHealth() * 3;
			}
			else
			{
				exp_earned = enemy.getMaxHealth() * 2;
			}
			for (Item* item : player.getItems())
			{
				if (enemyDrop->getName() == item->getName())
				{
					item->increaseQuantity(1);
					itemDupe = true;
				}
			}
			if (!itemDupe)
			{
				player.addItem(enemyDrop);
			}
			for (int i = 0; i < 20; i++)
			{
				Sleep(10);
				//system("CLS");
				player.increaseExp(exp_earned/20);
				cout << "\n   You gained " << exp_earned << " experience" << endl << endl;
				cout << "   " << enemy.getName() << " dropped " << enemyDrop->getName() << "!" << endl;
				if (!itemDupe)
				{
					if (enemyDrop->canInheritSkill())
					{
						cout << "   + Unlocked Skill: " << enemyDrop->getSkill().getName() << endl;
					}
				}
				cout << "\n   Level " << player.getLevel() << " | Next EXP: " << int(player.getNextEXP());
				cout << "\n   HP: " << player.getHealth() << "/" << player.getMaxHealth() << " | STA: " << player.getStamina() << "/" << player.getMaxStamina() << endl << endl;
				//player.getPlayerStats();
			}
			player.update();
			system("pause");
			system("CLS");
			battle = false;
			play_audio(current_dungeon->getDungeonName() + " F" + to_string(current_dungeon->getDungeonRoom()));
		}
		else
		{
			while (!player_turn)
			{
				this_thread::sleep_for(chrono::seconds(3));
				system("CLS");
				show_battle_stats(player);
				cout << "\n   " << enemy.getName() << "'s turn...";
				this_thread::sleep_for(chrono::seconds(2));
				system("CLS");
				show_battle_stats(player);
				enemy.update(player);
				cout << enemy.getTurnPhrase();
				this_thread::sleep_for(chrono::seconds(1));
				system("CLS");
				show_battle_stats(player);
				cout << enemy.getTurnPhrase();
				this_thread::sleep_for(chrono::seconds(2));
				player_turn = true;
				break;
			}
		}
		if (!battle) break;
	}
}

void play_audio(string to_play)
{
	if (to_play == "Glacier Wasteland F1")
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
	else if (to_play == "Glacier Wasteland F6")
	{
		PlaySound(TEXT("music/glacier_floor_5.wav"), NULL, SND_ASYNC | SND_LOOP);
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
	else if (to_play == "Victory")
	{
		PlaySound(TEXT("music/victory.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
}

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

void dialogue_input(Player player, string dialogue_choice)
{
	if (dialogue_choice == "/help") // Displays full list of commands
	{
		system("CLS");
		cout <<
			"\n   /help  : Displays this menu!" <<
			"\n\n   items : Displays all of your items + melee weapon" <<
			"\n\n   stats : Displays your player stats" <<
			"\n\n   debugfight : Initiate a fight at Lv 99 for testing purposes" << endl;
		system("pause");
		cout << "\033[A" << "\33[2K\r" << endl;
	}
	if (dialogue_choice == "items") // Displays all items the player has
	{
		system("CLS");
		cout << "\n   " << player.getName() << "'s Inventory\n";
		vector<int> rarityNumbers = { 0, 0, 0, 0, 0 };
		for (int i = 1; i < 6; i++)
		{
			for (Item* item : player.getItems())
			{
				if (item->getRarity() == i)
				{
					rarityNumbers[(i - 1)] = rarityNumbers[(i - 1)] + item->getQuantity();
				}
			}
		}
		cout << "   [ " << rarityNumbers[0] << " (1*) | " << rarityNumbers[1] << " (2*) | " << rarityNumbers[2] << " (3*) | " << rarityNumbers[3] << " (4*) | " << rarityNumbers[4] << " (5*) ]\n\n";
		for (int i = 1; i < 6; i++)
		{
			for (Item* item : player.getItems())
			{
				if (item->getRarity() == i)
				{
					cout << item->toString() << endl << endl;
				}
			}
		}
		system("pause");
		cout << "\033[A" << "\33[2K\r" << endl;
	}
	if (dialogue_choice == "stats") // Displays the players levelling stats
	{
		system("CLS");
		cout << "\n   " << player.getName() << "\n";
		player.getPlayerStats();
		player.getPlayerElements();
		cout << endl;
		system("pause");
		cout << "\033[A" << "\33[2K\r" << endl;
	}
	if (dialogue_choice == "debugfight") // Initiates a secret fight against the creator
	{
		Enemy newEnemy = Enemy("Macko", 99, 2000, 500, { Skill("Flamadia"), Skill("Freezadia"), Skill("Zapadia"), Skill("Gustadia"), Skill("Hexaon"), Skill("Blightaon"), Skill("Eye of the 'Berg"), Skill("Eye of the Storm") }, new ItemSkill("???", "I actually don't know what this is.", 5, Skill("Hex of Death")), true, 218);
		player.setSkills({ Skill("Flamadia"), Skill("Freezadia"), Skill("Zapadia"), Skill("Gustadia"), Skill("Hexaon"), Skill("Blightaon"), Skill("Hex of Death"), Skill("Healadia") });
		player.setMelee(ItemMelee("Sword of Lost Histories", "Only true completionists have found this relic", 5, 304));
		for (int i = 0; i < 99; i++)
		{
			player.increaseExp(9999999);
		}
		DungeonGlacier current_dungeon = DungeonGlacier();
		battle(player, &current_dungeon, newEnemy);
	}
	else
	{
		cout << "\033[A" << "\33[2K\r" << endl;
	}
}

void set_starting_elements(int& weak_element, int& resist_element)
{
	bool valid_option = false;
	vector<string> list_of_elements = { "fire", "ice", "electric", "wind", "curse", "bless" };
	string inp_we, inp_re;
	while (true)
	{
		cout << "\n   Choose an element to be weak to:\n   Fire, Ice, Electric, Wind, Curse, Bless\n   > "; cin >> inp_we;
		inp_we = convert_string_tolower(inp_we);
		for (string element : list_of_elements)
		{
			if (inp_we == element)
			{
				valid_option = true;
			}
		}
		if (valid_option) break;
	}
	if (inp_we == "fire")
	{
		weak_element = 0;
	}
	else if (inp_we == "ice")
	{
		weak_element = 1;
	}
	else if (inp_we == "electric")
	{
		weak_element = 2;
	}
	else if (inp_we == "wind")
	{
		weak_element = 3;
	}
	else if (inp_we == "curse")
	{
		weak_element = 4;
	}
	else if (inp_we == "bless")
	{
		weak_element = 5;
	}

	valid_option = false;
	while (true)
	{
		cout << "\n   Choose an element to be resistant to:\n   Fire, Ice, Electric, Wind, Curse, Bless   \n   > "; cin >> inp_re;
		inp_re = convert_string_tolower(inp_re);
		for (string element : list_of_elements)
		{
			if (inp_re == element)
			{
				valid_option = true;
			}
		}
		if (valid_option) break;
	}
	if (inp_re == "fire")
	{
		resist_element = 0;
	}
	else if (inp_re == "ice")
	{
		resist_element = 1;
	}
	else if (inp_re == "electric")
	{
		resist_element = 2;
	}
	else if (inp_re == "wind")
	{
		resist_element = 3;
	}
	else if (inp_re == "curse")
	{
		resist_element = 4;
	}
	else if (inp_re == "bless")
	{
		resist_element = 5;
	}
}

void show_enemy_stats(Enemy enemy)
{
	cout << "\n   " << enemy.getName() << " (Lv " << enemy.getLevel() << ")" << endl;
	cout << "   HP: " << enemy.getHealth() << " | STA: " << enemy.getStamina() << endl << endl << endl;
	vector<string> element_names = { "Fire", "Ice", "Electric", "Wind", "Curse", "Bless" };
	for (int i = 0; i < 6; i++)
	{
		cout << ".  " << element_names[i] << ": " << enemy.getElements()[i] << "\n";
	}
}

void show_battle_stats(Player player)
{
	system("CLS");
	cout << "\n   " << player.getName() << "\n";
	cout << "   HP: " << player.getHealth() << " / " << player.getMaxHealth() << " | STA: " << player.getStamina() << " / " << player.getMaxStamina() << endl << endl;
}

void show_skill(Player player, int index)
{
	vector<Skill> tempSkills = player.getSkills();
	cout << "--> " << convert_string_toupper(tempSkills[index].getName()) << endl;
	cout << "    Type: " << tempSkills[index].getType() << endl;
	cout << "    Desc: " << tempSkills[index].getDesc() << endl;
	cout << "    STA: " << tempSkills[index].getStaminaCost() << endl;
	if (tempSkills[index].getName() == "Heal" || tempSkills[index].getName() == "Healan" || tempSkills[index].getName() == "Healadia")
	{
		cout << "    HP+: " << tempSkills[index].getHPGain() << endl;
	}
	else
	{
		cout << "    DMG: " << tempSkills[index].getBaseDamage() << endl;
	}
	cout << "    [Skill " << (index + 1) << " of " << tempSkills.size() << "]";
}

