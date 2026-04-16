#include "ItemMelee.h"

ItemMelee::ItemMelee() { }

ItemMelee::ItemMelee(string nName, string nDesc, int nRarity, int nDamage) : Item(nName, nDesc, nRarity)
{
	this->damage = nDamage;
	this->meleeItem = true;
	this->skillInheritance = false;
	this->consumable = false;
	this->applyModifications();
}

string ItemMelee::getElementalType()
{
	return this->STR_Elemental_Type;
}

string ItemMelee::getAttributeType()
{
	return this->STR_Attribute_Type;
}

string ItemMelee::getModifiedName()
{
	return this->STR_Modified_Name;
}

float ItemMelee::getBonusValue()
{
	return this->FLT_Bonus_Value;
}

string ItemMelee::toString()
{
	string convertedText;
	if (this->BOOL_Has_Attribute)
	{
		if (this->STR_Attribute_Type == "Melee" || this->STR_Attribute_Type == "Magic")
		{
			convertedText = "   x" + to_string(this->getQuantity()) + " " + this->name + " (" + to_string(this->rarity) + "*)\n   Desc: " + this->desc + "\n   Atk: " + to_string(this->damage) + "\n   + " + this->STR_Attribute_Type + " attacks deal " + to_string(int((this->FLT_Bonus_Value * 100) - 100)) + "% extra damage";
		}
		else
		{
			convertedText = "   x" + to_string(this->getQuantity()) + " " + this->name + " (" + to_string(this->rarity) + "*)\n   Desc: " + this->desc + "\n   Atk: " + to_string(this->damage) + "\n   + Reduces incoming damage by " + to_string(int((this->FLT_Bonus_Value * 100) - 100)) + "%";
		}
	}
	else if (this->BOOL_Has_Element)
	{
		convertedText = "   x" + to_string(this->getQuantity()) + " " + this->name + " (" + to_string(this->rarity) + "*)\n   Desc: " + this->desc + "\n   Atk: " + to_string(this->damage) + "\n   + Deals " + to_string(int((this->FLT_Bonus_Value * 100) - 100)) + "% extra damage against enemies weak to " + this->STR_Elemental_Type;
	}
	else
	{
		convertedText = "   x" + to_string(this->getQuantity()) + " " + this->name + " (" + to_string(this->rarity) + "*)\n   Desc: " + this->desc + "\n   Atk: " + to_string(this->damage);
	}
	return convertedText;
}

void ItemMelee::setAttributeType(string N_Attribute_Type, float N_Bonus_Value)
{
	this->STR_Attribute_Type = N_Attribute_Type;
	this->FLT_Bonus_Value = N_Bonus_Value;
	this->BOOL_Has_Attribute = true;
}

void ItemMelee::setElementalType(string N_Elemental_Type, float N_Bonus_Value)
{
	this->STR_Elemental_Type = N_Elemental_Type;
	this->FLT_Bonus_Value = N_Bonus_Value;
	this->BOOL_Has_Element = true;
}

void ItemMelee::applyModifications()
{
	this->BOOL_Has_Attribute = false;
	this->BOOL_Has_Element = false;
	int INT_Modified_Chance = (rand() % 20) + 1;
	vector<float> VEC_Bonus_Values = { 1.05, 1.10, 1.15, 1.20, 1.25, 1.30, 1.35, 1.40 };
	if (INT_Modified_Chance > 15)
	{
		// Picks an Attribute to deal bonus damage with with a multiplier between 5% - 40%
		vector<string> VEC_Attributes = { "Melee", "Magic", "Endurance" };
		this->STR_Attribute_Type = VEC_Attributes[rand() % 3];
		this->FLT_Bonus_Value = VEC_Bonus_Values[rand() % VEC_Bonus_Values.size()];
		this->BOOL_Has_Attribute = true;
	}
	else if (INT_Modified_Chance > 10)
	{
		// Picks an Element to deal bonus damage to with a multiplier between 5% - 40%
		vector<string> VEC_Elements = { "Fire", "Water", "Ice", "Electric", "Wind", "Curse", "Bless" };
		this->STR_Elemental_Type = VEC_Elements[rand() % 7];
		this->FLT_Bonus_Value = VEC_Bonus_Values[rand() % VEC_Bonus_Values.size()];
		this->BOOL_Has_Element = true;
	}
}
