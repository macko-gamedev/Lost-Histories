#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "BattleStat.h"
#include "Skill.h"

using namespace std;

class Enemy : public BattleStat
{
private:
	vector<string> elements;
	vector<Skill> skills;
public:
	Enemy();
	Enemy(string nName, int nLevel, int nHealth, int nStamina, vector<Skill> nSkills);
	vector<string> getElements();
	vector<Skill> getSkills();
};