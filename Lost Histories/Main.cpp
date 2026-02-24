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
void battle(Player& player, Enemy enemy); // Battle sequence
void map_movement(string dialogue_choice, Player& player, Enemy& newEnemy, Dungeon* current_dungeon); // Map Movement

enum storyStatus
{
	TUTORIAL,
	ACT_ONE_EXPLORE,
};

/* ---------------------------------------------------------------------------------------------------- */

// MAIN PROGRAM
int main()
{
	main_menu();
	// Setup
	string player_name;
	string dialogue_choice;
	storyStatus story_status = storyStatus::TUTORIAL;
	int weak_element = -1;
	int resist_element = -1;
	cout << "Your Character Name: "; 
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
	Enemy newEnemy = Enemy("Ice Monster", 1, 10, 24, { Skill("Freeze") }, new ItemSkill("Ice Core", "A strange looking block of ice", 1, Skill("Freeze")));
	battle(player, newEnemy);
	story.startOfDialogue();
	story.increaseDialogueIndex();
	story_status = storyStatus::ACT_ONE_EXPLORE;

	// DUNGEON 1: GLACIER WASTELAND
	DungeonGlacier current_dungeon = DungeonGlacier();
	current_dungeon.fillWithEnemies();
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
						cout << "          >: Next Floor";
					}
					if (i == 11 && j == 14)
					{
						cout << "          <: Prev Floor";
					}
					if (i == 13 && j == 14)
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
		cout << "--> New Game\n--> Load Game\n--> Settings\n--> Quit\n\n> ";
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
			if (current_dungeon->getDungeonName() == "Glacier Wasteland")
			{
				newEnemy.setElements({ "Wk", "Rst", "-", "-", "-", "-" });
			}
			battle(player, newEnemy);
		}
		else if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() + 1)) == '>')
		{
			current_dungeon->changeDungeonRoom(1);
			current_dungeon->fillWithEnemies();

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
			if (current_dungeon->getDungeonName() == "Glacier Wasteland")
			{
				newEnemy.setElements({ "Wk", "Rst", "-", "-", "-", "-" });
			}
			battle(player, newEnemy);
		}
		else if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() - 1)) == '<')
		{
			current_dungeon->changeDungeonRoom(-1);
		}

		if (current_dungeon->getDungeonName() == "Glacier Wasteland")
		{
			if (current_dungeon->getDungeonRoom() == 3) // Snow Golem Mini Boss, drops key used to advance
			{
				if (current_dungeon->getPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() - 1)) == '?')
				{
					current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), current_dungeon->getPosX(), ' ');
					current_dungeon->setPosition((current_dungeon->getDungeonRoom() - 1), current_dungeon->getPosY(), (current_dungeon->getPosX() - 1), '+');
					current_dungeon->changePosY(-1);
					Enemy newEnemy = Enemy("Snow Golem", 10, 232, 54, { Skill("Mefreeze"), Skill("Freezan"), Skill("Hexaon") }, new ItemSkill("Glacier F3 Key","Frozen key lost in time, maybe can be used for something?", 3, Skill("")));
					if (current_dungeon->getDungeonName() == "Glacier Wasteland")
					{
						newEnemy.setElements({ "Wk", "Rst", "-", "-", "Wk", "Rst" });
					}
					battle(player, newEnemy);
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
			if (current_dungeon->getDungeonName() == "Glacier Wasteland")
			{
				newEnemy.setElements({ "Wk", "Rst", "-", "-", "-", "-" });
			}
			battle(player, newEnemy);
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
			if (current_dungeon->getDungeonName() == "Glacier Wasteland")
			{
				newEnemy.setElements({ "Wk", "Rst", "-", "-", "-", "-" });
			}
			battle(player, newEnemy);
		}
	}
}

Item* open_chest(Player&, Dungeon* current_dungeon)
{
	if (current_dungeon->getDungeonName() == "Glacier Wasteland")
	{
		vector<Item*> chestLoot =
		{
			new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1),
			new ItemMelee("Nail Board", "Plank of frozen wood with a nail pointing out the end", 2, 17),
			new ItemMelee("Ice-Axe", "Battleaxe frozen to time", 3, 29),
			new ItemSkill("Box of Matches", "Withered box of fire matches, can they still alight?", 2, Skill("Meflame")),
			new ItemSkill("Old Cross", "An old church cross emitting a blessing aura", 3, Skill("Blightan"))
		};
		if (current_dungeon->getDungeonRoom() >= 3)
		{
			chestLoot.push_back(new ItemMelee("Ice Crossbow", "Icified crossbow which fires icicles", 3, 46));
		}
		if (current_dungeon->getDungeonRoom() >= 4)
		{
			chestLoot.push_back(new ItemSkill("Goat Horn", "Remains of what looks like a goat, what is it even doing here?", 2, Skill("Megust")));
		}
		if (current_dungeon->getDungeonRoom() >= 5)
		{
			chestLoot.push_back(new ItemSkill("Electrical Wire", "Exposed electric wire that still packs some spark", 3, Skill("Zapao")));
		}
	}
}

void battle(Player &player, Enemy enemy)
{
	system("CLS");
	bool player_turn = true; // Is it player turn or enemy turn?
	bool battle = true; // Whilst the battle is in play
	string choice; // Selecting a skill
	string player_page; // Battle menu page
	ItemSkill* enemyDrop = enemy.getDroppedItem();
	int skillIndex = 0; // Selected skill index (to display)
	cout << "You have encountered " << enemy.getName() << endl;
	this_thread::sleep_for(chrono::seconds(3));
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
				cout << "--> Melee\n--> Skill\n--> Item\n--> Guard\n--> Analyse\n\n>> ";
				getline(cin, player_page);
				player_page = convert_string_tolower(player_page);
				if (player.getSkills().empty() && player_page == "skill")
				{
					system("CLS");
					cout << "You have no skills currently." << endl;
					this_thread::sleep_for(chrono::seconds(2));
					player_page = "";
				}
				if (/*player.getSkills().empty() &&*/ player_page == "item")
				{
					system("CLS");
					cout << "You have no useable items currently." << endl;
					this_thread::sleep_for(chrono::seconds(2));
					player_page = "";
				}
			}
			// Page : Skill
			while (player_page == "skill")
			{
				system("CLS");
				show_battle_stats(player);
				show_skill(player, skillIndex);
				cout << "\n\n--> Next\n--> Back\n--> Return\n\n>> ";
				getline(cin, choice);
				choice = convert_string_tolower(choice);
				// Validates if the skill selected exists
				for (Skill skill : player.getSkills())
				{
					if ((choice == convert_string_tolower(skill.getName())) && (player.getStamina() >= skill.getStaminaCost()))
					{
						Skill skillSelected = skill;
						system("CLS");
						// Determines what the skill does
						if (skillSelected.getType() == "support")
						{
							// Heal the player
							player.changeHealth(skillSelected.getHPGain());
							cout << "You have healed yourself restoring " << skillSelected.getHPGain() << " health\n\n";
						}
						else
						{
							// Damage the enemy
							if (skillSelected.isSingleTarget())
							{
								cout << "You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << skillSelected.getBaseDamage() << " damage\n\n";
							}
							else
							{
								cout << "You casted " << skillSelected.getName() << " upon all enemies dealing " << skillSelected.getBaseDamage() << " damage each\n\n";
							}
							enemy.changeHealth(-(skillSelected.getBaseDamage()));
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
			// Page : Melee
			while (player_page == "melee")
			{
				system("CLS");
				show_battle_stats(player);
				cout << player.getMeleeWeapon().toString();
				cout << "\n\n--> Use\n--> Return\n\n>> ";
				getline(cin, choice);
				choice = convert_string_tolower(choice);

				// If choice is "use", attack the enemy with melee weapon
				if (choice == "use" || choice == "u")
				{
					system("CLS");
					cout << "You attacked " << enemy.getName() << " using " << player.getMeleeWeapon().getName() << " dealing " << player.getMeleeWeapon().getDamage() << " damage\n\n";
					enemy.changeHealth(-(player.getMeleeWeapon().getDamage()));
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
				cout << "Reduce incoming damage by 33% and negates weaknesses";
				cout << "\n\n--> Guard\n--> Return\n\n>> ";
				getline(cin, choice);
				choice = convert_string_tolower(choice);

				// If choice is "guard", guards against incoming attack
				if (choice == "guard" || choice == "g")
				{
					system("CLS");
					player.setGuard(true);
					cout << "You have guarded yourself\n\n";
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
				cout << "\nItem: " << enemyDrop->getName();
				cout << "\n\n--> Return\n\n>> ";
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
			system("CLS");
			player.increaseExp(int(enemy.getMaxHealth() * 2));
			cout << "You gained " << to_string(int(enemy.getMaxHealth() * 2)) << " experience" << endl << endl;
			cout << enemy.getName() << " dropped " << enemyDrop->getName() << "!" << endl;
			bool itemDupe = false;
			for (Item* item : player.getItems())
			{
				if (enemyDrop->getName() == item->getName())
				{
					item->increaseQuantity();
					itemDupe = true;
				}
			}
			if (!itemDupe)
			{
				player.addItem(enemyDrop);
				cout << "+ Unlocked Skill: " << enemyDrop->getSkill().getName() << endl;
			}
			cout << endl;
			player.getPlayerStats();
			system("pause");
			system("CLS");
			battle = false;
		}
		else
		{
			while (!player_turn)
			{
				this_thread::sleep_for(chrono::seconds(2));
				enemy.update(player);
				this_thread::sleep_for(chrono::seconds(2));
				player_turn = true;
				break;
			}
		}

		if (!battle) break;
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
			"/help  : Displays this menu!" <<
			"\n/items : Displays all of your items + melee weapon" <<
			"\n/stats : Displays your player stats" <<
			"\n/debugfight : Initiate a fight at Lv 99 for testing purposes" << endl;
		system("pause");
		cout << "\033[A" << "\33[2K\r" << endl;
	}
	if (dialogue_choice == "/items") // Displays all items the player has
	{
		system("CLS");
		for (Item* item : player.getItems())
		{
			cout << item->toString() << endl << endl;
		}
		system("pause");
		cout << "\033[A" << "\33[2K\r" << endl;
	}
	if (dialogue_choice == "/stats") // Displays the players levelling stats
	{
		system("CLS");
		cout << player.getName() << "'s Stats" << endl << endl;
		player.getPlayerStats();
		player.getPlayerElements();
		cout << endl;
		system("pause");
		cout << "\033[A" << "\33[2K\r" << endl;
	}
	if (dialogue_choice == "/debugfight") // Initiates a secret fight against the creator
	{
		Enemy newEnemy = Enemy("Macko", 99, 2000, 500, { Skill("Flamadia"), Skill("Freezadia"), Skill("Zapadia"), Skill("Gustadia"), Skill("Hexaon"), Skill("Blightaon"), Skill("Eye of the 'Berg"), Skill("Eye of the Storm") }, new ItemSkill("???", "I actually don't know what this is.", 5, Skill("Hex of Death")));
		player.setSkills({ Skill("Flamadia"), Skill("Freezadia"), Skill("Zapadia"), Skill("Gustadia"), Skill("Hexaon"), Skill("Blightaon"), Skill("Hex of Death"), Skill("Healadia") });
		player.setMelee(ItemMelee("Sword of Lost Histories", "Only true completionists have found this relic", 5, 304));
		for (int i = 0; i < 99; i++)
		{
			player.increaseExp(9999999);
		}
		battle(player, newEnemy);
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
		cout << "\nChoose an element to be weak to:\nFire, Ice, Electric, Wind, Curse, Bless\n"; cin >> inp_we;
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
		cout << "\nChoose an element to be resistant to:\nFire, Ice, Electric, Wind, Curse, Bless\n"; cin >> inp_re;
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
	//return weak_element, resist_element;
}

void show_enemy_stats(Enemy enemy)
{
	cout << convert_string_toupper(enemy.getName()) << " | Lv " << enemy.getLevel() << endl << endl;
	/*for (string element : enemy.getElements())
	{
		cout << element << " ";
	}*/
	cout << "HP: " << enemy.getHealth();
	cout << "\nSTA: " << enemy.getStamina() << endl << endl;
}

void show_battle_stats(Player player)
{
	system("CLS");
	cout << "YOUR TURN" << endl << endl;
	cout << "HP: " << player.getHealth() << " / " << player.getMaxHealth() << endl;
	cout << "STA: " << player.getStamina() << " / " << player.getMaxStamina() << endl << endl;
}

void show_skill(Player player, int index)
{
	vector<Skill> tempSkills = player.getSkills();
	cout << "--> " << convert_string_toupper(tempSkills[index].getName()) << endl;
	cout << "Type: " << tempSkills[index].getType() << endl;
	cout << "Desc: " << tempSkills[index].getDesc() << endl;
	cout << "STA: " << tempSkills[index].getStaminaCost() << endl;
	if (tempSkills[index].getName() == "Heal" || tempSkills[index].getName() == "Healan" || tempSkills[index].getName() == "Healadia")
	{
		cout << "HP+: " << tempSkills[index].getHPGain() << endl;
	}
	else
	{
		cout << "DMG: " << tempSkills[index].getBaseDamage() << endl;
	}
	cout << "[Skill " << (index + 1) << " of " << tempSkills.size() << "]";
}

