#pragma once
#include <string>
#include <vector>

using namespace std;

class Skill
{
private:
	string STR_Skill_Name;
	string STR_Skill_Type;
	string STR_Skill_Desc;
	int INT_Base_Damage;
	int INT_Health_Gain;
	int INT_Stamina_Cost;
	bool BOOL_Single_Target;
	bool BOOL_Is_Valid_Skill;

public:
	Skill();
	Skill(string N_NAME);
	string getName();
	string getDesc();
	string getType();
	int getBaseDamage();
	int getStaminaCost();
	int getHPGain();
	bool isSingleTarget();
	bool isValid();
};

