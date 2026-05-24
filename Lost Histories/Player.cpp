#include "Player.h"
#include <iostream>
#include <string>

Player::Player() { }

Player::Player(string name, int INT_Level, int INT_Health, int INT_Stamina) : BattleStat(name, INT_Level, INT_Health, INT_Stamina)
{
	// EXP : Granted after battles
	this->FLT_Curr_EXP = 0;
	this->FLT_Next_EXP = 22;

	// Guard : Reduces incoming damage by 33% and sets element to -/Rst
	this->BOOL_Guard = false;

	// Status : Effects Player in battle
	this->STR_Status = "Great";

	// Attack Multiplier : Increases with use of items or skills
	this->FLT_Melee_Attack_Multiplier = 1.0;
	this->FLT_Magic_Attack_Multiplier = 1.0;

	// Attributes : On levelling up, Player can choose to increase one of these
	/*
	Strength  - Increases Melee Damage by (1 + (melee value / 10))x
	Magic     - Increases Skill Damage by (1 + (magic value / 10))x
	Endurance - Decreases Incoming Damage by (1 + (endurance value / 10))x
	*/
	this->MAP_Player_Attributes = { { "Strength", 1 }, { "Magic", 1 }, { "Endurance", 1 } };

	// Elements : Fire, Ice, Electric, Wind, Curse, Bless
	/*
	-   - No effect
	Wk  - Deals 1.5x damage
	Rst - Deals 0.5x damage
	Nul - Deals 0.0x damage
	Rpl - Attacks self
	*/
	this->MAP_Elements = { {"Fire", "-"}, {"Water", "-"}, {"Ice", "-"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "-"} };
	this->VEC_Element_Names = { "Fire", "Water", "Ice", "Electric", "Wind", "Curse", "Bless", "Support", "Nuclear" };

	// Items : Giving the player a backpack by default and equipping the player with a basic melee weapon
	this->VEC_Items = { new Item("Torn Backpack", "Your trusty backpack for storing items, has seen better days", 1), new ItemMelee("Sharp Stick", "A long wooden stick with a pointy end", 1, 4, false)};
	this->ITEM_MELEE_Equipped_Melee = ItemMelee("Sharp Stick", "A long wooden stick with a pointy end", 1, 4, false); // Name, Desc, Rarity 1-5, Damage

	// Skills : Player starts with no skills, so just declaring the vector here
	this->VEC_Skills = { };

	// Stars : How many stars are on the player save file, default to "- - -" unless changed by loading data
	this->MAP_Stars_On_File = { { "Main Story" , '-' }, { "Special World", '-' }, { "Lv 99", '-' }, { "Secret", '-' } };
}

// Outputs Player name, HP and STA
void Player::getPlayerStats()
{
	cout << dye::light_green("\n   HP: ") << dye::light_green(this->getHealth()) << dye::light_green(" / ") << dye::light_green(this->getMaxHealth()) << " | " << dye::light_aqua("STA: ") << dye::light_aqua(this->getStamina()) << dye::light_aqua(" / ") << dye::light_aqua(this->getMaxStamina()) << endl << endl;
	cout << dye::light_yellow("   Level ") << dye::light_yellow(this->INT_Level) << dye::yellow("\n   EXP Next: ") << dye::yellow(int(this->getNextEXP() - this->getCurrEXP())) << dye::yellow("\n   EXP Total: ") << dye::yellow(this->INT_Total_EXP) << endl << endl;
}

// Outputs Player elements
void Player::getPlayerElements()
{
	int INDEX_Element = 0;
	while (INDEX_Element < 7)
	{
		cout << ".  " << VEC_Element_Names[INDEX_Element] << ": ";
		if (MAP_Elements.find(VEC_Element_Names[INDEX_Element])->second == "Wk")
		{
			cout << dye::light_yellow("Wk\n");
		}
		else if (MAP_Elements.find(VEC_Element_Names[INDEX_Element])->second == "Rst")
		{
			cout << dye::light_red("Rst\n");
		}
		else
		{
			cout << "-\n";
		}
		INDEX_Element++;
	}
}

// Returns Player melee weapon object
ItemMelee Player::getMeleeWeapon()
{
	return this->ITEM_MELEE_Equipped_Melee;
}

// Returns Player status
string Player::getStatus()
{
	return this->STR_Status;
}

// Returns Player equipped skills
vector<Skill> Player::getSkills()
{
	return this->VEC_Skills;
}

// Sets manually the Player's equipped skills
void Player::setSkills(vector<Skill> nSkills)
{
	this->VEC_Skills = nSkills;
}

// Sets skill at index with a new skill
void Player::swapSkill(int INDEX_Skill, Skill SKILL_Skill)
{
	this->VEC_Skills[(INDEX_Skill - 1)] = SKILL_Skill;
}

// Sets Player melee weapon
void Player::setMelee(ItemMelee nMelee)
{
	this->ITEM_MELEE_Equipped_Melee = nMelee;
}

// Returns Player inventory
vector<Item*> Player::getItems()
{
	return this->VEC_Items;
}

// Returns Player attributes  (St, Ma, En)
map<string, int> Player::getPlayerAttributes()
{
	return this->MAP_Player_Attributes;
}

// Returns Stars * on current save file
map<string, char> Player::getStarsOnFile()
{
	return this->MAP_Stars_On_File;
}

// Gets next EXP
int Player::getNextEXP()
{
	return this->FLT_Next_EXP;
}

// Gets current EXP
int Player::getCurrEXP()
{
	return this->FLT_Curr_EXP;
}

// Gets total EXP
int Player::getTotEXP()
{
	return this->INT_Total_EXP;
}

// Returns if Player is guarded
bool Player::isGuard()
{
	return this->BOOL_Guard;
}

// Returns if Player has levelled up
bool Player::isLevelUp()
{
	return this->BOOL_Level_Up;
}

// Gets melee attack multiplier
float Player::getMeleeAttackMultiplier()
{
	return this->FLT_Melee_Attack_Multiplier;
}

// Gets magic attack multiplier
float Player::getMagicAttackMultiplier()
{
	return this->FLT_Magic_Attack_Multiplier;
}

// Sets melee attack multiplier
void Player::setMeleeAttackMultiplier(float N_Value)
{
	this->FLT_Melee_Attack_Multiplier = N_Value;
}

// Sets magic attack multiplier
void Player::setMagicAttackMultiplier(float N_Value)
{
	this->FLT_Magic_Attack_Multiplier = N_Value;
}

// Set an attribute to a specific value (St, Ma, En)
void Player::setPlayerAttribute(string STR_Attribute, int N_VALUE)
{
	auto it = this->MAP_Player_Attributes.find(STR_Attribute);
	it->second = N_VALUE;
}

// Sets the starting elements for the Player: 1 Weak and 1 Resistant
void Player::setStartingElements()
{
	bool BOOL_Valid_Option = false;
	vector<string> VEC_List_Of_Available_Elements = { "Fire", "Water", "Ice", "Electric", "Wind", "Curse", "Bless" };
	string STR_Element_Choice;
	while (!BOOL_Valid_Option)
	{
		cout << "\n   Choose an element to be weak to:\n   Fire, Water, Ice, Electric, Wind, Curse, Bless\n   > ";
		cin >> STR_Element_Choice;
		for (int i = 0; i < VEC_List_Of_Available_Elements.size(); i++)
		{
			if (STR_Element_Choice == VEC_List_Of_Available_Elements[i])
			{
				BOOL_Valid_Option = true;
				break;
			}
		}
	}
	this->setPlayerElement(STR_Element_Choice, "Wk");
	BOOL_Valid_Option = false;
	while (!BOOL_Valid_Option)
	{
		cout << "\n   Choose an element to be resistant to:\n   Fire, Water, Ice, Electric, Wind, Curse, Bless   \n   > ";
		cin >> STR_Element_Choice;
		for (int i = 0; i < VEC_List_Of_Available_Elements.size(); i++)
		{
			if (STR_Element_Choice == VEC_List_Of_Available_Elements[i])
			{
				BOOL_Valid_Option = true;
				break;
			}
		}
	}
	this->setPlayerElement(STR_Element_Choice, "Rst");
}

// Set an ailment to a specific element
void Player::setPlayerElement(string N_Element, string N_Ailment)
{
	this->MAP_Elements.find(N_Element)->second = N_Ailment;
}

// Sets all Stars * on current save file
void Player::setStarsOnFile(map<string, char> N_File)
{
	this->MAP_Stars_On_File = N_File;
}

// Sets specific Star * on current save file
void Player::setSpecificStarOnFile(string N_Name, char N_Char)
{
	this->MAP_Stars_On_File.find(N_Name)->second = N_Char;
}

// Level up function end
void Player::notLevelUp()
{
	this->BOOL_Level_Up = false;
}

// Increases Player EXP
void Player::increaseExp(float INT_Amount)
{
	// Increases EXP
	this->INT_Total_EXP += INT_Amount;
	if (this->INT_Level == 99)
	{
		this->setSpecificStarOnFile("Lv 99", '*');
	}
	this->FLT_Curr_EXP += INT_Amount;
	while (this->FLT_Curr_EXP >= this->FLT_Next_EXP)
	{
		BOOL_Level_Up = true;
		int TEMP_EXP_Value = this->FLT_Curr_EXP - this->FLT_Next_EXP;

		// Increases Player Stats
		this->INT_Level++;
		this->INT_Max_Health += 7;
		this->INT_Max_Stamina += 4;
		this->INT_Health = this->INT_Max_Health;
		this->INT_Stamina = this->INT_Max_Stamina;
		this->FLT_Curr_EXP = TEMP_EXP_Value;

		// Calculates next EXP required
		if (this->INT_Level > 99)
		{
			this->FLT_Next_EXP = int(((float)this->FLT_Next_EXP) * 1.015);
		}
		else if (this->INT_Level > 49)
		{
			this->FLT_Next_EXP = int(((float)this->FLT_Next_EXP) * 1.03);
		}
		else if (this->INT_Level > 19)
		{
			this->FLT_Next_EXP = int(((float)this->FLT_Next_EXP) * 1.0725);
		}
		else
		{
			this->FLT_Next_EXP = int(((float)this->FLT_Next_EXP) * 1.35);
		}
	}
}

// Sets Player guard
void Player::setGuard(bool guardState)
{
	this->BOOL_Guard = guardState;
}

// Adds Item object to Player inventory
void Player::addItem(Item* ITEM_Item)
{
	this->VEC_Items.push_back(ITEM_Item);
}

// Sets Player inventory
void Player::setItems(vector<Item*> nItems)
{
	this->VEC_Items = nItems;
}

// Sets all Player EXP
void Player::setLevelXP(int N_Tot, int N_Curr, int N_Next)
{
	this->INT_Total_EXP = N_Tot;
	this->FLT_Next_EXP = N_Next;
	this->FLT_Curr_EXP = N_Curr;
	this->notLevelUp();
}

// Loads data from current save file
void Player::loadData(vector<string> N_Data)
{
	this->setLevelXP(stoi(N_Data[4]), stoi(N_Data[2]), stoi(N_Data[3]));
	cout << dye::blue("\n   Loading player attributes");
	this->setPlayerAttribute("Strength", stoi(N_Data[5]));
	this->setPlayerAttribute("Magic", stoi(N_Data[6]));
	this->setPlayerAttribute("Endurance", stoi(N_Data[7]));
	cout << dye::blue("\n   Sucessfully loaded player attributes");
	cout << dye::blue("\n   Loading game star states");
	this->setSpecificStarOnFile("Main Story", N_Data[N_Data.size() - 4][0]);
	this->setSpecificStarOnFile("Special World", N_Data[N_Data.size() - 3][0]);
	this->setSpecificStarOnFile("Lv 99", N_Data[N_Data.size() - 2][0]);
	this->setSpecificStarOnFile("Secret", N_Data[N_Data.size() - 1][0]);
	cout << dye::blue("\n   Sucessfully loaded game star states");
	// Adding items to inventory
	for (int i = 0; i < N_Data.size(); i++)
	{
		if (N_Data[i] == "item")
		{
			cout << dye::blue("\n   Loading item " + N_Data[(i + 1)]);
			Item* ITEM_To_Add = new Item(N_Data[(i + 1)], N_Data[(i + 2)], stoi(N_Data[(i + 3)]));
			ITEM_To_Add->increaseQuantity(stoi(N_Data[(i + 4)]) - 1);
			this->addItem(ITEM_To_Add);
			cout << dye::blue("\n   Sucessfully added item " + N_Data[(i + 1)] + " to player inventory");
		}
		else if (N_Data[i] == "skill")
		{
			cout << dye::blue("\n   Loading item " + N_Data[(i + 2)]);
			Item* ITEM_To_Add = new ItemSkill(N_Data[(i + 2)], N_Data[(i + 3)], stoi(N_Data[(i + 4)]), Skill(N_Data[(i + 1)]));
			ITEM_To_Add->increaseQuantity(stoi(N_Data[(i + 5)]) - 1);
			this->addItem(ITEM_To_Add);
			cout << dye::blue("\n   Sucessfully added item " + N_Data[(i + 2)] + " to player inventory");
		}
		else if (N_Data[i] == "melee")
		{
			cout << dye::blue("\n   Loading item " + N_Data[(i + 2)]);
			Item* ITEM_To_Add = new ItemMelee(N_Data[(i + 2)], N_Data[(i + 3)], stoi(N_Data[(i + 4)]), stoi(N_Data[(i + 1)]), true);
			ITEM_To_Add->increaseQuantity(stoi(N_Data[(i + 5)]) - 1);
			this->addItem(ITEM_To_Add);
			cout << dye::blue("\n   Sucessfully added item " + N_Data[(i + 2)] + " to player inventory");
		}
		else if (N_Data[i] == "consumable")
		{
			cout << dye::blue("\n   Loading item " + N_Data[(i + 3)]);
			Item* ITEM_To_Add = new ItemConsumable(N_Data[(i + 3)], N_Data[(i + 4)], stoi(N_Data[(i + 5)]), N_Data[(i + 1)], stof(N_Data[(i + 2)]));
			ITEM_To_Add->increaseQuantity(stoi(N_Data[(i + 6)]) - 1);
			this->addItem(ITEM_To_Add);
			cout << dye::blue("\n   Sucessfully added item " + N_Data[(i + 3)] + " to player inventory");
		}
	}
	this->update();
}

// Returns new data from current save file to a vector
vector<string> Player::saveData(vector<Dungeon*> N_Visited_Dungeons)
{
	vector<string> SAVE_Data = { };
	SAVE_Data.push_back(this->getName());
	SAVE_Data.push_back(to_string(this->getLevel()));
	SAVE_Data.push_back(to_string(this->getCurrEXP()));
	SAVE_Data.push_back(to_string(this->getNextEXP()));
	SAVE_Data.push_back(to_string(this->getTotEXP()));
	SAVE_Data.push_back(to_string(this->getPlayerAttributes().find("Strength")->second));
	SAVE_Data.push_back(to_string(this->getPlayerAttributes().find("Magic")->second));
	SAVE_Data.push_back(to_string(this->getPlayerAttributes().find("Endurance")->second));
	for (int i = (N_Visited_Dungeons.size() - 1); i > -1; i--)
	{
		SAVE_Data.push_back(N_Visited_Dungeons[i]->getDungeonName());
		SAVE_Data.push_back(to_string(N_Visited_Dungeons[i]->getDungeonRoom()));
	}
	for (Item* ITEM_Item : this->getItems())
	{
		if (ITEM_Item->getName() != "Sharp Stick" && ITEM_Item->getName() != "Torn Backpack")
		{
			if (ITEM_Item->isConsumable())
			{
				SAVE_Data.push_back("consumable");
				SAVE_Data.push_back(ITEM_Item->getType());
				SAVE_Data.push_back(to_string(ITEM_Item->getAmount()));
			}
			else if (ITEM_Item->isMeleeWeapon())
			{
				SAVE_Data.push_back("melee");
				SAVE_Data.push_back(to_string(ITEM_Item->getMeleeDamage()));
			}
			else if (ITEM_Item->canInheritSkill())
			{
				SAVE_Data.push_back("skill");
				SAVE_Data.push_back(ITEM_Item->getSkill().getName());
			}
			else
			{
				SAVE_Data.push_back("item");
			}
			SAVE_Data.push_back(ITEM_Item->getName());
			SAVE_Data.push_back(ITEM_Item->getDesc());
			SAVE_Data.push_back(to_string(ITEM_Item->getRarity()));
			SAVE_Data.push_back(to_string(ITEM_Item->getQuantity()));
		}
	}
	vector<string> VEC_Star_Names = { "Main Story", "Special World", "Lv 99", "Secret" };
	for (string STR_Star_Name : VEC_Star_Names)
	{
		if (this->getStarsOnFile().find(STR_Star_Name)->second == '*')
		{
			SAVE_Data.push_back("*");
		}
		else
		{
			SAVE_Data.push_back("-");
		}
	}
	return SAVE_Data;
}

// Updates the Player selected skills (if >8 requires manual change, else sets in order)
void Player::update()
{
	if (VEC_Skills.size() < 8)
	{
		this->setSkills({});
		vector<Skill> VEC_Items_With_Skill = { };
		for (int i = 0; i < VEC_Element_Names.size(); i++)
		{
			for (Item* ITEM_Item : this->getItems())
			{
				if (ITEM_Item->canInheritSkill())
				{
					if (ITEM_Item->getSkill().getType() == VEC_Element_Names[i])
					{
						VEC_Items_With_Skill.push_back(ITEM_Item->getSkill());
					}
					if (VEC_Items_With_Skill.size() >= 8) break;
				}
			}
			if (VEC_Items_With_Skill.size() >= 8) break;
		}
		this->setSkills(VEC_Items_With_Skill);
	}
}
