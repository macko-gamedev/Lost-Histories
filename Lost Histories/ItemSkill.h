#pragma once
#include <iostream>
#include "Item.h"
#include "Skill.h"

using namespace std;

class ItemSkill : public Item
{
private:
public:
	ItemSkill();
	ItemSkill(string nName, string nDesc, int nRarity, Skill nSkill);
	void toString() override;
};

