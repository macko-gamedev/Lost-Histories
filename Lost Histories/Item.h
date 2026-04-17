#pragma once
#include <iostream>
#include <string>
#include "Skill.h"
#include "include/color.hpp"

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
	double amount;
	string type;

	bool BOOL_Has_Element;
	bool BOOL_Has_Attribute;
	string STR_Modified_Name;
	string STR_Elemental_Type;
	string STR_Attribute_Type;
	float FLT_Bonus_Value;
public:
	Item();
	Item(string nName, string nDesc, int nRarity);
	virtual void toString();
	string getName();
	string getDesc();
	string getType();
	double getAmount();
	int getRarity();
	int getQuantity();
	bool isMeleeWeapon();
	bool isConsumable();
	bool canInheritSkill();
	int getMeleeDamage();
	Skill getSkill();
	void increaseQuantity(int amount);
	string getAttributeType();
	string getElementalType();
	string getModifiedName();
	float getBonusValue();
	bool hasElementCoverage();
	bool hasModifiedAttribute();
	void setAttributeType(string N_Attribute_Type, float N_Bonus_Value);
	void setElementalType(string N_Elemental_Type, float N_Bonus_Value);
	void setModifiedName(string N_Modified_Name);
	void applyModifications();
};

