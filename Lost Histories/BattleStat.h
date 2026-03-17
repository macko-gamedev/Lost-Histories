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
	string STR_Name;
	int INT_Health;
	int INT_Stamina;
	int INT_Max_Health;
	int INT_Max_Stamina;
	int INT_Level;
public:
	BattleStat();
	BattleStat(string nName, int nLevel, int nHealth, int nStamina);
	string getName();
	int getLevel();
	int getHealth();
	int getStamina();
	int getMaxHealth();
	int getMaxStamina();
	void changeHealth(int INT_Amount);
	void changeStamina(int INT_Amount);
	void fullHealth();
	void fullStamina();
	virtual void update(Player& PLAYER_Player);
};

