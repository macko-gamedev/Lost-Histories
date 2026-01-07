#pragma once
#include <string>
#include <vector>
#include "Skill.h"

using namespace std;

class Player
{
private:
	string name;
	string status;
	string location;
	vector<string> elements;
	vector<Skill> skills;
	int level;
	int health;
	int max_health;
	int stamina;
	int max_stamina;
	float curr_exp;
	float next_exp;

public:
	Player(string name, int weak_element, int resist_element);
	string getName();
	string getStatus();
	string getLocation();
	vector<string> getElements();
	vector<Skill> getSkills();
	int getHealth();
	int getMaxHealth();
	int getStamina();
	int getMaxStamina();
	int getLevelStats();
	void fullHealth();
	void fullStamina();
	void changeHealth(int amount);
	void changeStamina(int amount);
	void increaseExp(int amount);
	void getPlayerStats();
};

