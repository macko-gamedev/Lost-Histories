#include "Player.h"
#include "Enemy.h"
#include "Skill.h"
#include "Story.h"
#include "Item.h"
#include "ItemSkill.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>

using namespace std;

/* 

###### LOST HISTORIES ######
Last Updated: 13/01/26

--- Parent Classes ---
. BattleStat	# Contains key variables to battles such as health and stamina values
				: Player, Enemy
. Item			# Contains name, description and rarity of an item
                : ItemMelee, ItemSkill

--- Child Classes ---
. Enemy		    : Inherits BattleStat
. ItemMelee     : Inherits Item, is the player's current melee weapon
. ItemSkill     : Inherits Item, an item which contains a skill the player can inherit
. Player        : Inherits BattleStat, contains all things the player can do and their stats

--- Classes ---
. Skill			: Contains name, description, type, damage/healing value and stamina cost of a skill
. Story			: Contains a vector which has all story dialogue and functions which alter the pathing

############################

 */

// Quite obvious 1
string convert_string_tolower(string text);
// Quite obvious 2
string convert_string_toupper(string text);
// Sets the starting elements (weakness and resistant)
void set_starting_elements(int& weak_element, int& resist_element);
// Shows the enemy's battle stats
void show_enemy_stats(Enemy enemy);
// Shows the player's battle stats (name, hp, sta)
void show_battle_stats(Player player);
// Shows the player's current skill
void show_skill(Player player, int index);

// BATTLE
void battle(Player &player, Enemy enemy)
{
	system("CLS");
	bool player_turn = true; // Is it player turn or enemy turn?
	bool battle = true; // Whilst the battle is in play
	string choice; // Selecting a skill
	string player_page; // Battle menu page
	int skillIndex = 0; // Selected skill index (to display)
	cout << "You have encountered " << enemy.getName() << endl;
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
					cout << "! You have no skills currently." << endl;
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
						// Damage the enemy
						system("CLS");
						if (skillSelected.isSingleTarget())
						{
							cout << "You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << skillSelected.getBaseDamage() << " damage\n\n";
						}
						else
						{
							cout << "You casted " << skillSelected.getName() << " upon all enemies dealing " << skillSelected.getBaseDamage() << " damage each\n\n";
						}
						enemy.changeHealth(-(skillSelected.getBaseDamage()));
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

// MAIN PROGRAM
int main()
{
	// Setup
	string player_name;
	string dialogue_choice;
	int weak_element = -1;
	int resist_element = -1;
	cout << "Your Character Name: "; 
	getline(cin, player_name);
	set_starting_elements(weak_element, resist_element); // Player chooeses their starting elements
	Player player = Player(player_name, weak_element, resist_element, 1, 140, 62); // Instantiates object of type Player
	Story story = Story(player_name); // Instantiates object of type Story
	system("CLS");
	cout << ">>> TYPE /help TO VIEW ALL POSSIBLE COMMANDS <<<" << endl << endl;
	while (true)
	{
		while (!story.isEvent())
		{
			cout << story.getDialogue() << endl;
			story.increaseDialogueIndex();
			if (story.getDialogue() == "END DIALOGUE")
			{
				story.endOfDialogue();
			}
			cin >> dialogue_choice;
			if (dialogue_choice == "/help") // Displays full list of commands
			{
				system("CLS");
				cout <<
					"/help  : Displays this menu!" <<
					"\n/items : Displays all of your items + melee weapon" <<
					"\n/stats : Displays your player stats" << endl;
				system("pause");
				cout << "\033[A" << "\33[2K\r" << endl;
			}
			if (dialogue_choice == "/items") // Displays all items the player has
			{
				system("CLS");
				for (int i = 0; i < player.getItems().size(); i++)
				{
					cout << player.getItems()[i].toString() << endl << endl;
				}
				cout << player.getMeleeWeapon().toString() << endl << endl;
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
			else
			{
				cout << "\033[A" << "\33[2K\r" << endl;
			}
		}
		vector<Skill> enemySkills = { Skill("Freeze") };
		Enemy newEnemy = Enemy("Ice Monster", 1, 10, 24, enemySkills);
		battle(player, newEnemy);
		cout << "DEBUG";
		system("pause");
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
	cout << convert_string_toupper(enemy.getName()) << endl << endl;
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
	cout << endl << "--> " << convert_string_toupper(tempSkills[index].getName()) << endl;
	cout << "Type: " << tempSkills[index].getType() << endl;
	cout << "Desc: " << tempSkills[index].getDesc() << endl;
	cout << "STA: " << tempSkills[index].getStaminaCost() << endl;
	cout << "DMG: " << tempSkills[index].getBaseDamage() << endl;
	cout << "[Skill " << (index + 1) << " of " << tempSkills.size() << "]";
}
