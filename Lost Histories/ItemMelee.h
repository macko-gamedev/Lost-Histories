#pragma once
#include <iostream>
#include "Item.h"

using namespace std;

class ItemMelee : public Item
{
private:
	int damage;
public:
	ItemMelee();
	ItemMelee(string nName, string nDesc, int nRarity, int nDamage);
	string toString() override;
	int getDamage();
};

