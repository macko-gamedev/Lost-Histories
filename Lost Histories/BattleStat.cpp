#include "BattleStat.h"
#include "Player.h"

BattleStat::BattleStat() { }

BattleStat::BattleStat(string nName, int nLevel, int nHealth, int nStamina)
{
	this->name = nName;
	this->level = nLevel;
	this->health = nHealth;
	this->stamina = nStamina;
	this->max_health = nHealth;
	this->max_stamina = nStamina;
}

string BattleStat::getName()
{
	return this->name;
}

int BattleStat::getLevel()
{
	return this->level;
}

int BattleStat::getHealth()
{
	return this->health;
}

int BattleStat::getStamina()
{
	return this->stamina;
}

int BattleStat::getMaxHealth()
{
	return this->max_health;
}

int BattleStat::getMaxStamina()
{
	return this->max_stamina;
}

void BattleStat::changeHealth(int amount)
{
	this->health += amount;
	if (this->health > this->max_health)
	{
		this->health = this->max_health;
	}
}

void BattleStat::changeStamina(int amount)
{
	this->stamina += amount;
	if (this->stamina > this->max_stamina)
	{
		this->stamina = this->max_stamina;
	}
}

void BattleStat::update(Player& player)
{
	cout << "Joey is a smelly poo poo head";
}

