#include "BattleStat.h"
#include "Player.h"

BattleStat::BattleStat() { }

BattleStat::BattleStat(string nName, int nLevel, int nHealth, int nStamina)
{
	this->STR_Name = nName;
	this->INT_Level = nLevel;
	this->INT_Health = nHealth;
	this->INT_Stamina = nStamina;
	this->INT_Max_Health = nHealth;
	this->INT_Max_Stamina = nStamina;
}

string BattleStat::getName()
{
	return this->STR_Name;
}

int BattleStat::getLevel()
{
	return this->INT_Level;
}

int BattleStat::getHealth()
{
	return this->INT_Health;
}

int BattleStat::getStamina()
{
	return this->INT_Stamina;
}

int BattleStat::getMaxHealth()
{
	return this->INT_Max_Health;
}

int BattleStat::getMaxStamina()
{
	return this->INT_Max_Stamina;
}

map<string, string> BattleStat::getElements()
{
	return this->MAP_Elements;
}

void BattleStat::changeHealth(int INT_Amount)
{
	this->INT_Health += INT_Amount;
	if (this->INT_Health > this->INT_Max_Health)
	{
		this->INT_Health = this->INT_Max_Health;
	}
}

void BattleStat::changeStamina(int INT_Amount)
{
	this->INT_Stamina += INT_Amount;
	if (this->INT_Stamina > this->INT_Max_Stamina)
	{
		this->INT_Stamina = this->INT_Max_Stamina;
	}
}

void BattleStat::fullHealth()
{
	this->INT_Health = this->INT_Max_Health;
}

void BattleStat::fullStamina()
{
	this->INT_Stamina = this->INT_Max_Stamina;
}

void BattleStat::setElements(map<string, string> nElements)
{
	this->MAP_Elements = nElements;
}

void BattleStat::update(Player& PLAYER_Player)
{

}

