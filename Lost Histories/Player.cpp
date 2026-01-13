#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player(string name, int weak_element, int resist_element, int level, int health, int stamina) : BattleStat(name, level, health, stamina)
{
	this->status = "Great";
	this->max_health = health;
	this->max_stamina = stamina;
	this->curr_exp = 0;
	this->next_exp = 167;

	// Elements : Fire, Ice, Electric, Wind, Curse, Bless
	this->elements = { "-", "-", "-", "-", "-", "-" };
	this->elementNames = { "Fire", "Ice", "Electric", "Wind", "Curse", "Bless" };
	this->elements[weak_element] = "Wk";
	this->elements[resist_element] = "Rst";

	// Items: Giving the player a backpack by default and equipping the player with a basic melee weapon
	this->items = { (Item("Torn Backpack", "Your trusty backpack for storing items, has seen better days", 1)) };
	this->equippedMelee = ItemMelee("Sharp Stick", "A long wooden stick with a pointy end", 1, 4); // Name, Desc, Rarity 1-5, Damage

	// Skills: Player starts with no skills, so just declaring the vector here
	this->skills = { };
}

void Player::getPlayerStats()
{
	cout << this->name << "'s Stats" << endl << endl;
	cout << ">> Battle <<" << endl;
	cout << "Level " << this->level << endl;
	cout << "EXP Next: " << (this->next_exp - this->curr_exp) << endl;
	cout << "HP: " << this->health << " / " << this->max_health << endl;
	cout << "STA: " << this->stamina << " / " << this->max_stamina << endl << endl;

	cout << ">> Elements <<" << endl;
	int elementIndex = 0;
	while (elementIndex < 6)
	{
		cout << ". " << elementNames[elementIndex] << ": " << elements[elementIndex] << endl;
		elementIndex++;
	}
	
}

ItemMelee Player::getMeleeWeapon()
{
	return this->equippedMelee;
}

string Player::getStatus()
{
	return this->status;
}

string Player::getLocation()
{
	return this->location;
}

vector<string> Player::getElements()
{
	return this->elements;
}

vector<Skill> Player::getSkills()
{
	return this->skills;
}

vector<Item> Player::getItems()
{
	return this->items;
}

int Player::getLevelStats()
{
	return level, curr_exp, next_exp;
}

void Player::increaseExp(int amount)
{
	this->curr_exp += amount;
	if (curr_exp >= next_exp)
	{
		int tempVal = this->curr_exp - this->next_exp;
		this->level++;
		this->curr_exp = -tempVal;
		this->next_exp = int(((float)this->next_exp) * 1.1);
	}
}