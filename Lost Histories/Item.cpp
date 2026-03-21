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
}

string Item::toString()
{
	string convertedText = "   x" + to_string(this->getQuantity()) + " " + this->name + " (" + to_string(this->rarity) + "*)\n   Desc: " + this->desc;
	return convertedText;
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
