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
	bool skillInheritance;
	Skill inherit_skill;
public:
	Item();
	Item(string nName, string nDesc, int nRarity);
	virtual string toString();
	string getName();
	string getDesc();
	int getRarity();
	int getQuantity();
	bool canInheritSkill();
	Skill getSkill();
	void increaseQuantity();
};

