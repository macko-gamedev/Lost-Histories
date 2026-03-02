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
	int damage;
	Skill inherit_skill;
public:
	Item();
	Item(string nName, string nDesc, int nRarity);
	virtual string toString();
	string getName();
	string getDesc();
	int getRarity();
	int getQuantity();
	bool isMeleeWeapon();
	bool canInheritSkill();
	int getMeleeDamage();
	Skill getSkill();
	void increaseQuantity();
};

