#pragma once
#include <string>
#include <vector>

using namespace std;

class Skill
{
private:
	string skill_name;
	string skill_type;
	string skill_desc;
	int base_dmg;
	int hp_gain;
	int stamina_cost;
	bool single_target;

public:
	Skill();
	Skill(string name);
	string getName();
	string getDesc();
	string getType();
	int getBaseDamage();
	int getStaminaCost();
	int getHPGain();
	bool isSingleTarget();
};

