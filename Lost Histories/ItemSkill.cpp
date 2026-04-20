#include "ItemSkill.h"

ItemSkill::ItemSkill() { }

ItemSkill::ItemSkill(string nName, string nDesc, int nRarity, Skill nSkill) : Item(nName, nDesc, nRarity)
{
	this->inherit_skill = nSkill;
	this->meleeItem = false;
	this->skillInheritance = true;
	this->consumable = false;
}

void ItemSkill::toString()
{
	cout << dye::grey_on_white(" x") << dye::grey_on_white(this->getQuantity()) << dye::black_on_white(" ") << dye::black_on_white(this->name) << dye::black_on_white(" ") << dye::black_on_yellow(" ") << dye::black_on_yellow(this->rarity) << dye::black_on_yellow("*") << dye::black_on_yellow(" ") << "\n   " << this->desc << "\n   " << dye::light_purple(this->inherit_skill.getName()) << dye::light_purple(" - ") << dye::light_purple(this->inherit_skill.getDesc());
}
