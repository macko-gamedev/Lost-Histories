#include "Item.h"

Item::Item() { }

Item::Item(string nName, string nDesc, int nRarity)
{
	this->name = nName;
	this->desc = nDesc;
	this->rarity = nRarity;
	this->quantity = 1;
}

string Item::toString()
{
	string convertedText = "x" + to_string(this->getQuantity()) + " " + this->name + " (" + to_string(this->rarity) + "*)\nDesc: " + this->desc;
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

void Item::increaseQuantity()
{
	this->quantity++;
}
