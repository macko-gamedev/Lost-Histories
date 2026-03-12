#include "ItemSkill.h"

ItemSkill::ItemSkill() { }

ItemSkill::ItemSkill(string nName, string nDesc, int nRarity, Skill nSkill) : Item(nName, nDesc, nRarity)
{
	this->inherit_skill = nSkill;
	this->meleeItem = false;
	this->skillInheritance = true;
	this->consumable = false;
}

string ItemSkill::toString()
{
	string convertedText = "   x" + to_string(this->getQuantity()) + " " + this->name + " (" + to_string(this->rarity) + "*)\n   Desc: " + this->desc + "\n   Inherit: " + this->inherit_skill.getName();
	return convertedText;
}
