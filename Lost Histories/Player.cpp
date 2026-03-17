#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player(string name, int weak_element, int resist_element, int INT_Level, int INT_Health, int INT_Stamina) : BattleStat(name, INT_Level, INT_Health, INT_Stamina)
{
	// EXP : Granted after battles
	this->FLT_Curr_EXP = 0;
	this->FLT_Next_EXP = 22;

	// Guard : Reduces incoming damage by 33% and sets element to -/Rst
	this->BOOL_Guard = false;

	// Status : Effects Player in battle
	this->STR_Status = "Great";

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
	this->MAP_Elements = { {"Fire", "-"}, {"Ice", "-"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "-"} };
	this->VEC_Element_Names = { "Fire", "Ice", "Electric", "Wind", "Curse", "Bless" };
	this->MAP_Elements.find(VEC_Element_Names[weak_element])->second = "Wk";
	this->MAP_Elements.find(VEC_Element_Names[weak_element])->second = "Rst";

	// Items: Giving the player a backpack by default and equipping the player with a basic melee weapon
	this->VEC_Items = { new Item("Torn Backpack", "Your trusty backpack for storing VEC_Items, has seen better days", 1), new ItemMelee("Sharp Stick", "A long wooden stick with a pointy end", 1, 4), new ItemSkill("Insta-Kill","Testing purposes only", 5, Skill("Death"))};
	this->ITEM_MELEE_Equipped_Melee = ItemMelee("Sharp Stick", "A long wooden stick with a pointy end", 1, 4); // Name, Desc, Rarity 1-5, Damage

	// Skills: Player starts with no VEC_Skills, so just declaring the vector here
	this->VEC_Skills = { };
}

void Player::getPlayerStats()
{
	cout << "   HP: " << this->INT_Health << " / " << this->INT_Max_Health << " | STA: " << this->INT_Stamina << " / " << this->INT_Max_Stamina << endl << endl;
	cout << "   Level " << this->INT_Level << "\n   EXP Next: " << int(this->getNextEXP()) << "\n   EXP Total: " << this->INT_Total_EXP << endl << endl;
}

void Player::getPlayerElements()
{
	int INDEX_Element = 0;
	while (INDEX_Element < 6)
	{
		cout << ".  " << VEC_Element_Names[INDEX_Element] << ": " << MAP_Elements.find(VEC_Element_Names[INDEX_Element])->second << endl;
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

void Player::increaseExp(float INT_Amount)
{
	this->FLT_Curr_EXP += INT_Amount;
	this->INT_Total_EXP += INT_Amount;
	while (FLT_Curr_EXP >= FLT_Next_EXP)
	{
		if (this->INT_Level < 99)
		{
			int tempVal = this->FLT_Curr_EXP - this->FLT_Next_EXP;
			this->INT_Level++;
			this->INT_Max_Health += 7;
			this->INT_Max_Stamina += 4;
			this->INT_Health = this->INT_Max_Health;
			this->INT_Stamina = this->INT_Max_Stamina;
			this->FLT_Curr_EXP = tempVal;
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
	this->setSkills({ });
	vector<Skill> items_with_skill = { };
	vector<string> temp_element_names = { "fire", "ice", "electric", "wind", "curse", "bless", "nuclear", "support"};
	for (int i = 0; i < temp_element_names.size(); i++)
	{
		for (Item* ITEM_Item : this->getItems())
		{
			if (ITEM_Item->canInheritSkill())
			{
				if (ITEM_Item->getSkill().getType() == temp_element_names[i])
				{
					items_with_skill.push_back(ITEM_Item->getSkill());
				}
			}
		}
	}
	this->setSkills(items_with_skill);
}