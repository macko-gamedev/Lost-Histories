#pragma once
#include <string>
#include <vector>
#include "Skill.h"
#include "ItemMelee.h"
#include "BattleStat.h"

using namespace std;

class Player : public BattleStat
{
private:
	ItemMelee equippedMelee;
	string status;
	string location;
	vector<string> elements;
	vector<Skill> skills;
	float curr_exp;
	float next_exp;

public:
	Player(string name, int weak_element, int resist_element, int level, int health, int stamina);
	ItemMelee getMeleeWeapon();
	string getStatus();
	string getLocation();
	vector<string> getElements();
	vector<Skill> getSkills();
	int getLevelStats();
	void increaseExp(int amount);
	void getPlayerStats();
};

