#include "Item.h"

Item::Item() { }

Item::Item(string nName, string nDesc, int nRarity)
{
	this->name = nName;
	this->desc = nDesc;
	this->rarity = nRarity;
}

string Item::toString()
{
	string convertedText = "Item: " + this->name + "\*" + to_string(this->rarity) + "\nDesc: " + this->desc;
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
