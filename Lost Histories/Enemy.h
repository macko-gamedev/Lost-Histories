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
	ATTACKING,
	AILMENTCHANGE,
};

class Enemy : public BattleStat
{
private:
	battleState ENUM_State;
	vector<Skill> VEC_Skills;
	Item* ITEM_Dropped_Item;
	bool BOOL_Alive;
	bool BOOL_Boss;
	int INT_Damage;
	int INT_Boss_Stat_Cycle;
	int INT_Turns_Left;
	string STR_Turn_Phrase;
public:
	Enemy();
	Enemy(string nName, int nLevel, int nHealth, int nStamina, vector<Skill> nSkills, /*Item* nDroppedItem,*/ bool nBoss, int nDamage);
	bool isAlive();
	bool isBoss();
	vector<Skill> getSkills();
	int getDamage();
	int getTurnsLeft();
	Item* getDroppedItem();
	Item* getItemFromLootTable();
	string getTurnPhrase();
	void setHealth();
	void elementSetter();
	void update(Player& PLAYER_Player) override;
};