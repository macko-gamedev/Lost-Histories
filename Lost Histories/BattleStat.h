#pragma once
#include <iostream>

using namespace std;

class BattleStat
{
protected:
	string name;
	int health;
	int stamina;
	int max_health;
	int max_stamina;
	int level;
public:
	BattleStat();
	BattleStat(string nName, int nLevel, int nHealth, int nStamina);
	string getName();
	int getLevel();
	int getHealth();
	int getStamina();
	int getMaxHealth();
	int getMaxStamina();
	void changeHealth(int amount);
	void changeStamina(int amount);
};

