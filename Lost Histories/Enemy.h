#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
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
	vector<Skill> skills;
	map<string, string> elements;
	Item* droppedItem;
	bool alive;
	bool boss;
	int damage;
	string turnPhrase;
public:
	Enemy();
	Enemy(string nName, int nLevel, int nHealth, int nStamina, vector<Skill> nSkills, Item* nDroppedItem, bool nBoss, int nDamage);
	bool isAlive();
	bool isBoss();
	map<string, string> getElements();
	vector<Skill> getSkills();
	int getDamage();
	Item* getDroppedItem();
	string getTurnPhrase();
	void setHealth();
	void setElements(map<string, string>  nElements);
	void update(Player& player) override;
};