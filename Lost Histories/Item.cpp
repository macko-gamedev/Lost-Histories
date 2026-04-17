#include "Item.h"

Item::Item() { }

Item::Item(string nName, string nDesc, int nRarity)
{
	this->name = nName;
	this->desc = nDesc;
	this->rarity = nRarity;
	this->quantity = 1;
	this->meleeItem = false;
	this->skillInheritance = false;
	this->consumable = false;

	this->BOOL_Has_Attribute = false;
	this->BOOL_Has_Element = false;
	this->STR_Attribute_Type = "";
	this->STR_Elemental_Type = "";
	this->STR_Modified_Name = "";
	this->FLT_Bonus_Value = 1.0;
}

void Item::toString()
{
	cout << "   " << dye::grey_on_white("x") << dye::grey_on_white(this->getQuantity()) << dye::black_on_white(" ") << dye::black_on_white(this->name) << dye::black_on_white(" ") << dye::black_on_yellow(" ") << dye::black_on_yellow(this->rarity) << dye::black_on_yellow("*") << dye::black_on_yellow(" ") << "\n   " << this->desc;
}

string Item::getName()
{
	return this->name;
}

string Item::getDesc()
{
	return this->desc;
}

int Item::getRarity()
{
	return this->rarity;
}

int Item::getQuantity()
{
	return this->quantity;
}

bool Item::isMeleeWeapon()
{
	return this->meleeItem;
}

bool Item::isConsumable()
{
	return this->consumable;
}

bool Item::canInheritSkill()
{
	return this->skillInheritance;
}

int Item::getMeleeDamage()
{
	return this->damage;
}

double Item::getAmount()
{
	return this->amount;
}

string Item::getType()
{
	return this->type;
}


Skill Item::getSkill()
{
	return this->inherit_skill;
}

void Item::increaseQuantity(int amount)
{
	this->quantity += amount;
}


string Item::getElementalType()
{
	return this->STR_Elemental_Type;
}

string Item::getAttributeType()
{
	return this->STR_Attribute_Type;
}

string Item::getModifiedName()
{
	return this->STR_Modified_Name;
}

float Item::getBonusValue()
{
	return this->FLT_Bonus_Value;
}

bool Item::hasModifiedAttribute()
{
	return this->BOOL_Has_Attribute;
}

bool Item::hasElementCoverage()
{
	return this->BOOL_Has_Element;
}

void Item::setAttributeType(string N_Attribute_Type, float N_Bonus_Value)
{
	this->STR_Attribute_Type = N_Attribute_Type;
	this->FLT_Bonus_Value = N_Bonus_Value;
	this->BOOL_Has_Attribute = true;
}

void Item::setElementalType(string N_Elemental_Type, float N_Bonus_Value)
{
	this->STR_Elemental_Type = N_Elemental_Type;
	this->FLT_Bonus_Value = N_Bonus_Value;
	this->BOOL_Has_Element = true;
}

void Item::applyModifications()
{
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