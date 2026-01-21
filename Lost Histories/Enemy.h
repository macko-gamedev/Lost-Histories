#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "BattleStat.h"
#include "Skill.h"

using namespace std;

enum battleState
{
	WAITING,
	ATTACKING
};

class Enemy : public BattleStat
{
private:
	battleState state;
	vector<string> elements;
	vector<Skill> skills;
	bool alive;
public:
	Enemy();
	Enemy(string nName, int nLevel, int nHealth, int nStamina, vector<Skill> nSkills);
	bool isAlive();
	vector<string> getElements();
	vector<Skill> getSkills();
	void update(Player& player) override;
};