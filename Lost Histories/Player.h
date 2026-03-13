#pragma once
#include <string>
#include <vector>
#include "Skill.h"
#include "Item.h"
#include "ItemSkill.h"
#include "ItemMelee.h"
#include "ItemConsumable.h"
#include "BattleStat.h"

using namespace std;

class Player : public BattleStat
{
private:
	ItemMelee equippedMelee;
	string status;
	string location;
	vector<string> elements;
	vector<string> elementNames;
	vector<Skill> skills;
	vector<Item*> items;
	float curr_exp;
	float next_exp;
	int tot_exp;
	bool guard;

public:
	Player(string name, int weak_element, int resist_element, int level, int health, int stamina);
	ItemMelee getMeleeWeapon();
	string getStatus();
	string getLocation();
	vector<string> getElements();
	vector<Skill> getSkills();
	void setSkills(vector<Skill> nSkills);
	void setMelee(ItemMelee nMelee);
	vector<Item*> getItems();
	int getLevelStats();
	bool isGuard();
	void increaseExp(int amount);
	void setGuard(bool guardState);
	void getPlayerStats();
	void getPlayerElements();
	void addItem(Item* item);
	void setItems(vector<Item*> nItems);
	void update();
};

