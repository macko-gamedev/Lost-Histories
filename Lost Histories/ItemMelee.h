#pragma once
#include <iostream>
#include "Item.h"

using namespace std;

class ItemMelee : public Item
{
private:
public:
	ItemMelee();
	ItemMelee(string nName, string nDesc, int nRarity, int nDamage, bool BOOL_Is_New);
	void toString() override;
};

