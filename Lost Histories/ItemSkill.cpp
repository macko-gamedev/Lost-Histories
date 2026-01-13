#include "ItemSkill.h"

ItemSkill::ItemSkill() { }

ItemSkill::ItemSkill(string nName, string nDesc, int nRarity, string nSkill) : Item(nName, nDesc, nRarity)
{
	this->inherit_skill = Skill(nSkill);
}

string ItemSkill::toString()
{
	string convertedText = "Item: " + this->name + " (" + to_string(this->rarity) + "*)\nDesc: " + this->desc + "\nInherit: " + this->inherit_skill.getName();
	return convertedText;
}

Skill ItemSkill::getSkill()
{
	return this->inherit_skill;
}
