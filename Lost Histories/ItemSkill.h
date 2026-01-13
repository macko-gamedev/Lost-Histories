#pragma once
#include <iostream>
#include "Item.h"
#include "Skill.h"

using namespace std;

class ItemSkill : public Item
{
private:
	Skill inherit_skill;
public:
	ItemSkill();
	ItemSkill(string nName, string nDesc, int nRarity, string nSkill);
	Skill getSkill();
	string toString() override;
};

