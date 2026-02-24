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
	this->guard = false;

	// Elements : Fire, Ice, Electric, Wind, Curse, Bless
	this->elements = { "-", "-", "-", "-", "-", "-" };
	this->elementNames = { "Fire", "Ice", "Electric", "Wind", "Curse", "Bless" };
	this->elements[weak_element] = "Wk";
	this->elements[resist_element] = "Rst";

	// Items: Giving the player a backpack by default and equipping the player with a basic melee weapon
	this->items = { new Item("Torn Backpack", "Your trusty backpack for storing items, has seen better days", 1) };
	this->equippedMelee = ItemMelee("Sharp Stick", "A long wooden stick with a pointy end", 1, 4); // Name, Desc, Rarity 1-5, Damage
	this->addItem(&equippedMelee);

	// Skills: Player starts with no skills, so just declaring the vector here
	this->skills = { Skill("Flamadia") };
	this->max_stamina = 999;
}

void Player::getPlayerStats()
{
	cout << ">> Battle <<" << endl;
	cout << "Level " << this->level << " | (" << curr_exp << "/" << next_exp << ")" << endl << endl;
	cout << "HP: " << this->health << " / " << this->max_health << endl;
	cout << "STA: " << this->stamina << " / " << this->max_stamina << endl << endl;
}

void Player::getPlayerElements()
{
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

void Player::setSkills(vector<Skill> nSkills)
{
	this->skills = nSkills;
}

void Player::setMelee(ItemMelee nMelee)
{
	this->equippedMelee = nMelee;
}

vector<Item*> Player::getItems()
{
	return this->items;
}

int Player::getLevelStats()
{
	return this->level, this->curr_exp, this->next_exp;
}

bool Player::isGuard()
{
	return this->guard;
}

void Player::increaseExp(int amount)
{
	this->curr_exp += amount;
	if (curr_exp >= next_exp)
	{
		if (this->level < 99)
		{
			int tempVal = this->curr_exp - this->next_exp;
			this->level++;
			this->max_health += 6;
			this->max_stamina += 2;
			this->health = this->max_health;
			this->stamina = this->max_stamina;
			this->curr_exp = tempVal;
			this->next_exp = int(((float)this->next_exp) * 1.075);
		}
	}
}

void Player::setGuard(bool guardState)
{
	this->guard = guardState;
}

void Player::addItem(Item* item)
{
	this->items.push_back(item);
}