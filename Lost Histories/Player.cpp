#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player(string name, int weak_element, int resist_element)
{
	system("CLS");
	this->name = name;
	this->status = "Great";
	this->health = 70;
	this->max_health = 70;
	this->stamina = 42;
	this->max_stamina = 42;
	this->level = 1;
	this->curr_exp = 0;
	this->next_exp = 167;

	// Elements : Fire, Ice, Electric, Wind, Curse, Bless
	this->elements = { "-", "-", "-", "-", "-", "-" };
	this->elements[weak_element] = "Wk";
	this->elements[resist_element] = "Rst";

	this->skills.push_back(Skill("Flamao"));
	this->skills.push_back(Skill("Meflamadia"));
	this->skills.push_back(Skill("Hexaon"));
	this->skills.push_back(Skill("Blightaon"));
}

void Player::getPlayerStats()
{
	cout << this->name << "'s Stats : " << endl << endl;
	cout << "Level " << this->level << endl;
	cout << "EXP Next: " << (this->next_exp - this->curr_exp) << endl << endl;

	cout << "HP: " << this->health << " / " << this->max_health << endl;
	cout << "STA: " << this->stamina << " / " << this->max_stamina << endl << endl;
	cout << "Elements:" << endl;
	for (string element : this->elements)
	{
		cout << element << " ";
	} 
}

string Player::getName()
{
	return this->name;
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

int Player::getHealth()
{
	return this->health;
}

int Player::getMaxHealth()
{
	return this->max_health;
}

int Player::getStamina()
{
	return this->stamina;
}

int Player::getMaxStamina()
{
	return this->max_stamina;
}

void Player::fullHealth()
{
	this->health = this->max_health;
}

void Player::fullStamina()
{
	this->stamina = this->max_stamina;
}

void Player::changeHealth(int amount)
{
	this->health += amount;
	if (this ->health > this->max_health)
	{
		fullHealth();
	}
}

void Player::changeStamina(int amount)
{
	this->stamina += amount;
	if (this->stamina > this->max_stamina)
	{
		fullStamina();
	}
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