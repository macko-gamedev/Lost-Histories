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
		convertedText = "   x" + to_string(this->getQuantity()) + " " + this->name + " (" + to_string(this->rarity) + "*)\n   Desc: " + this->desc + "\n   Increases damage of next melee attack by " + to_string(int((this->amount * 100) - 100)) + "%";
	}
	else if (this->type == "MAG")
	{
		convertedText = "   x" + to_string(this->getQuantity()) + " " + this->name + " (" + to_string(this->rarity) + "*)\n   Desc: " + this->desc + "\n   Increases damage of next magic attack by " + to_string(int((this->amount * 100) - 100)) + "%";
	}
	else if (this->type == "ATK/MAG")
	{
		convertedText = "   x" + to_string(this->getQuantity()) + " " + this->name + " (" + to_string(this->rarity) + "*)\n   Desc: " + this->desc + "\n   Increases damage of next melee and magic attack by " + to_string(int((this->amount * 100) - 100)) + "%";
	}
	else
	{
		convertedText = "   x" + to_string(this->getQuantity()) + " " + this->name + " (" + to_string(this->rarity) + "*)\n   Desc: " + this->desc + "\n   Restores " + to_string(int(this->amount)) + " " + this->type;
	}
	return convertedText;
}
