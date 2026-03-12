#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>

using namespace std;

class Player;

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
	void fullHealth();
	void fullStamina();
	virtual void update(Player& player);
};

