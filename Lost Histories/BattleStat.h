#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <map>

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
	map<string, string> MAP_Elements;
public:
	BattleStat();
	BattleStat(string nName, int nLevel, int nHealth, int nStamina);
	string getName();
	int getLevel();
	int getHealth();
	int getStamina();
	int getMaxHealth();
	int getMaxStamina();
	map<string, string> getElements();
	void changeHealth(int INT_Amount);
	void changeStamina(int INT_Amount);
	void fullHealth();
	void fullStamina();
	void setElements(map<string, string> nElements);
	virtual void update(Player& PLAYER_Player);
};

