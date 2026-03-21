#pragma once
#include <iostream>
#include "Item.h"

using namespace std;

class ItemConsumable : public Item
{
private:
public:
	ItemConsumable();
	ItemConsumable(string nName, string nDesc, int nRarity, string nType, double nAmount);
	string toString() override;
};

