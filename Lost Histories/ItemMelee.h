#pragma once
#include <iostream>
#include "Item.h"

using namespace std;

class ItemMelee : public Item
{
private:
	bool BOOL_Has_Element;
	bool BOOL_Has_Attribute;
	string STR_Modified_Name;
	string STR_Elemental_Type;
	string STR_Attribute_Type;
	float FLT_Bonus_Value;
public:
	ItemMelee();
	ItemMelee(string nName, string nDesc, int nRarity, int nDamage);
	string getAttributeType();
	string getElementalType();
	string getModifiedName();
	float getBonusValue();
	bool hasElementCoverage();
	bool hasBonusValue();
	string toString() override;
	void setAttributeType(string N_Attribute_Type, float N_Bonus_Value);
	void setElementalType(string N_Elemental_Type, float N_Bonus_Value);
	void setModifiedName(string N_Modified_Name);
	void applyModifications();
};

