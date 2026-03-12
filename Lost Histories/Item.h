#pragma once
#include <iostream>
#include <string>
#include "Skill.h"

using namespace std;

class Item
{
protected:
	string name;
	string desc;
	int rarity;
	int quantity;
	bool meleeItem;
	bool skillInheritance;
	bool consumable;
	int damage;
	Skill inherit_skill;
	int amount;
	string type;
public:
	Item();
	Item(string nName, string nDesc, int nRarity);
	virtual string toString();
	string getName();
	string getDesc();
	string getType();
	int getAmount();
	int getRarity();
	int getQuantity();
	bool isMeleeWeapon();
	bool isConsumable();
	bool canInheritSkill();
	int getMeleeDamage();
	Skill getSkill();
	void increaseQuantity(int amount);
};

