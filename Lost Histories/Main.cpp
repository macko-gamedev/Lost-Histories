#include "Player.h"
#include "Enemy.h"
#include "Skill.h"
#include "Story.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>

using namespace std;

/* 

###### LOST HISTORIES ######
Last Updated: 15/12/25

--- Class ---
. Player	: 
. Enemy		: 
. Location	: 

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
			while ((player_page != "melee") && (player_page != "skill") && (player_page != "item") && (player_page != "guard"))
			{
				show_battle_stats(player);
				cout << "--> Melee\n--> Skill\n--> Item\n--> Guard\n\n>> ";
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
							cout << "You casted " << skillSelected.getName() << " upon " << enemy.getName() << " dealing " << skillSelected.getBaseDamage() << " dmg\n\n";
						}
						else
						{
							cout << "You casted " << skillSelected.getName() << " upon all enemies dealing " << skillSelected.getBaseDamage() << " dmg each\n\n";
						}
						enemy.takeDamage(skillSelected.getBaseDamage());
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
		while (!player_turn)
		{
			show_enemy_stats(enemy);
			cin >> player_turn;
		}
		//system("CLS");
	}
}

// MAIN PROGRAM
int main()
{
	// Setup
	string player_name;
	int weak_element = -1;
	int resist_element = -1;
	cout << "Your Character Name: "; 
	getline(cin, player_name);
	set_starting_elements(weak_element, resist_element);
	Player player = Player(player_name, weak_element, resist_element, 1, 70, 42);
	Story story = Story(player_name);
	system("CLS");
	while (!story.isEvent())
	{
		cout << story.getDialogue() << endl;
		story.increaseDialogueIndex();
		if (story.getDialogue() == "END DIALOGUE")
		{
			story.endOfDialogue();
		}
		system("pause");
		cout << "\033[A" << "\33[2K\r" << endl;
	}
	Enemy newEnemy = Enemy("Ice Monster", 1, 50, 20);
	battle(player, newEnemy);
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
	cout << convert_string_toupper(enemy.getName()) << "'s TURN" << endl << endl;
	for (string element : enemy.getElements())
	{
		cout << element << " ";
	}
	cout << "\n\nHP: " << enemy.getHealth();
	cout << "\nSTA: " << enemy.getStamina() << endl << endl;
}

void show_battle_stats(Player player)
{
	system("CLS");
	cout << "\nYOUR TURN" << endl << endl;
	for (string element : player.getElements())
	{
		cout << element << " ";
	}
	cout << "\n\nHP: " << player.getHealth() << " / " << player.getMaxHealth();
	cout << "\nSTA: " << player.getStamina() << " / " << player.getMaxStamina() << endl << endl;
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
