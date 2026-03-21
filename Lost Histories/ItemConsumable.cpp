#include "ItemConsumable.h"

ItemConsumable::ItemConsumable() {}

ItemConsumable::ItemConsumable(string nName, string nDesc, int nRarity, string nType, double nAmount) : Item(nName, nDesc, nRarity)
{
	this->type = nType;
	this->amount = nAmount;
	this->meleeItem = false;
	this->skillInheritance = false;
	this->consumable = true;
}

string ItemConsumable::toString()
{
	string convertedText;
	if (this->type == "ATK")
	{
		convertedText = "   x" + to_string(this->getQuantity()) + " " + this->name + " (" + to_string(this->rarity) + "*)\n   Desc: " + this->desc + "\n   Increases damage of next MELEE Attack by " + to_string(this->amount) + "x";
	}
	else
	{
		convertedText = "   x" + to_string(this->getQuantity()) + " " + this->name + " (" + to_string(this->rarity) + "*)\n   Desc: " + this->desc + "\n   Restores " + to_string(this->amount) + " " + this->type;
	}
	return convertedText;
}
