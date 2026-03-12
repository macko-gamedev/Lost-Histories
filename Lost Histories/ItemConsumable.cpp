#include "ItemConsumable.h"

ItemConsumable::ItemConsumable() {}

ItemConsumable::ItemConsumable(string nName, string nDesc, int nRarity, string nType, int nAmount) : Item(nName, nDesc, nRarity)
{
	this->type = nType;
	this->amount = nAmount;
	this->meleeItem = false;
	this->skillInheritance = false;
	this->consumable = true;
}

string ItemConsumable::toString()
{
	string convertedText = "   x" + to_string(this->getQuantity()) + " " + this->name + " (" + to_string(this->rarity) + "*)\n   Desc: " + this->desc + "\n   Restores " + to_string(this->amount) + " " + this->type;
	return convertedText;
}
