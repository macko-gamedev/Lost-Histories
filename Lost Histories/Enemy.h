#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "BattleStat.h"
#include "Skill.h"
#include "ItemSkill.h"

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
	Item* droppedItem;
	bool alive;
	bool boss;
public:
	Enemy();
	Enemy(string nName, int nLevel, int nHealth, int nStamina, vector<Skill> nSkills, Item* nDroppedItem, bool nBoss);
	bool isAlive();
	bool isBoss();
	vector<string> getElements();
	vector<Skill> getSkills();
	Item* getDroppedItem();
	void setElements(vector<string> nElements);
	void update(Player& player) override;
};