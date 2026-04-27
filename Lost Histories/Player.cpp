#include "Player.h"
#include <iostream>
#include <string>

Player::Player() { }

Player::Player(string name, int weak_element, int resist_element, int INT_Level, int INT_Health, int INT_Stamina) : BattleStat(name, INT_Level, INT_Health, INT_Stamina)
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
	this->MAP_Elements.find(VEC_Element_Names[weak_element])->second = "Wk";
	this->MAP_Elements.find(VEC_Element_Names[resist_element])->second = "Rst";

	// Items: Giving the player a backpack by default and equipping the player with a basic melee weapon
	this->VEC_Items = { new Item("Torn Backpack", "Your trusty backpack for storing items, has seen better days", 1), new ItemMelee("Sharp Stick", "A long wooden stick with a pointy end", 1, 4, false)};
	this->ITEM_MELEE_Equipped_Melee = ItemMelee("Sharp Stick", "A long wooden stick with a pointy end", 1, 4, false); // Name, Desc, Rarity 1-5, Damage

	// Skills: Player starts with no skills, so just declaring the vector here
	this->VEC_Skills = { };
}

void Player::getPlayerStats()
{
	cout << dye::light_green("\n   HP: ") << dye::light_green(this->getHealth()) << dye::light_green(" / ") << dye::light_green(this->getMaxHealth()) << " | " << dye::light_aqua("STA: ") << dye::light_aqua(this->getStamina()) << dye::light_aqua(" / ") << dye::light_aqua(this->getMaxStamina()) << endl << endl;
	cout << dye::light_yellow("   Level ") << dye::light_yellow(this->INT_Level) << dye::yellow("\n   EXP Next: ") << dye::yellow(int(this->getNextEXP())) << dye::yellow("\n   EXP Total: ") << dye::yellow(this->INT_Total_EXP) << endl << endl;
}

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

ItemMelee Player::getMeleeWeapon()
{
	return this->ITEM_MELEE_Equipped_Melee;
}

string Player::getStatus()
{
	return this->STR_Status;
}

string Player::getLocation()
{
	return this->STR_Location;
}


map<string, string> Player::getElements()
{
	return this->MAP_Elements;
}

vector<Skill> Player::getSkills()
{
	return this->VEC_Skills;
}

void Player::setSkills(vector<Skill> nSkills)
{
	this->VEC_Skills = nSkills;
}

void Player::swapSkill(int INDEX_Skill, Skill SKILL_Skill)
{
	this->VEC_Skills[(INDEX_Skill - 1)] = SKILL_Skill;
}

void Player::setMelee(ItemMelee nMelee)
{
	this->ITEM_MELEE_Equipped_Melee = nMelee;
}

vector<Item*> Player::getItems()
{
	return this->VEC_Items;
}

map<string, int> Player::getPlayerAttributes()
{
	return this->MAP_Player_Attributes;
}

int Player::getLevelStats()
{
	return this->INT_Level, this->FLT_Curr_EXP, this->FLT_Next_EXP;
}

int Player::getNextEXP()
{
	return this->FLT_Next_EXP - this->FLT_Curr_EXP;
}

bool Player::isGuard()
{
	return this->BOOL_Guard;
}

bool Player::isLevelUp()
{
	return this->BOOL_Level_Up;
}

float Player::getMeleeAttackMultiplier()
{
	return this->FLT_Melee_Attack_Multiplier;
}

float Player::getMagicAttackMultiplier()
{
	return this->FLT_Magic_Attack_Multiplier;
}

void Player::setMeleeAttackMultiplier(float N_Value)
{
	this->FLT_Melee_Attack_Multiplier = N_Value;
}

void Player::setMagicAttackMultiplier(float N_Value)
{
	this->FLT_Magic_Attack_Multiplier = N_Value;
}

void Player::setPlayerAttribute(string STR_Attribute, int N_VALUE)
{
	auto it = this->MAP_Player_Attributes.find(STR_Attribute);
	it->second = N_VALUE;
}

void Player::notLevelUp()
{
	this->BOOL_Level_Up = false;
}

void Player::increaseExp(float INT_Amount)
{
	// Increases EXP
	this->INT_Total_EXP += INT_Amount;
	if (this->INT_Level == 99)
	{
		FLT_Curr_EXP = 0;
		FLT_Next_EXP = 0;
	}
	else
	{
		this->FLT_Curr_EXP += INT_Amount;
	}
	while (FLT_Curr_EXP >= FLT_Next_EXP && this->INT_Level != 99)
	{
		if (this->INT_Level < 99)
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
			if (this->INT_Level > 49)
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
}

void Player::setGuard(bool guardState)
{
	this->BOOL_Guard = guardState;
}

void Player::addItem(Item* ITEM_Item)
{
	this->VEC_Items.push_back(ITEM_Item);
}

void Player::setItems(vector<Item*> nItems)
{
	this->VEC_Items = nItems;
}

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
				}
			}
		}
		this->setSkills(VEC_Items_With_Skill);
	}
}

void Player::setLevelStats(int N_Level, int N_Health, int N_Stamina)
{
	this->INT_Level = N_Level;
	this->INT_Max_Health = N_Health;
	this->INT_Max_Stamina = N_Stamina;
	this->fullHealth();
	this->fullStamina();
}

void Player::setLevelXP(int N_Tot, int N_Next)
{
	this->INT_Total_EXP = N_Tot;
	this->FLT_Next_EXP = N_Next;
	this->FLT_Curr_EXP = 0;
	this->notLevelUp();
}