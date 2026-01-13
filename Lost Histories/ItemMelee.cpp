#include "ItemMelee.h"

ItemMelee::ItemMelee() { }

ItemMelee::ItemMelee(string nName, string nDesc, int nRarity, int nDamage) : Item(nName, nDesc, nRarity)
{
	this->damage = nDamage;
}

string ItemMelee::toString()
{
	string convertedText = "Item: " + this->name + " (" + to_string(this->rarity) + "*)\nDesc: " + this->desc + "\nAtk: " + to_string(this->damage);
	return convertedText;
}

int ItemMelee::getDamage()
{
	return this->damage;
}
