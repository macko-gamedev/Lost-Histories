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
	battleState ENUM_State;
	vector<Skill> VEC_Skills;
	map<string, string> MAP_Elements;
	Item* ITEM_Dropped_Item;
	bool BOOL_Alive;
	bool BOOL_Boss;
	int INT_Damage;
	string STR_Turn_Phrase;
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
	void update(Player& PLAYER_Player) override;
};