#include "ItemMelee.h"

ItemMelee::ItemMelee() { }

ItemMelee::ItemMelee(string nName, string nDesc, int nRarity, int nDamage, bool BOOL_Is_New) : Item(nName, nDesc, nRarity)
{
	this->damage = nDamage;
	this->meleeItem = true;
	this->skillInheritance = false;
	this->consumable = false;

	if (BOOL_Is_New)
	{
		this->applyModifications();
	}
}

void ItemMelee::toString()
{
	if (this->BOOL_Has_Attribute)
	{
		if (this->STR_Attribute_Type == "Melee" || this->STR_Attribute_Type == "Magic")
		{
			cout << dye::grey_on_white(" x") << dye::grey_on_white(this->getQuantity()) << dye::black_on_white(" ") << dye::black_on_white(this->name) << dye::black_on_white(" ") << dye::black_on_yellow(" ") << dye::black_on_yellow(this->rarity) << dye::black_on_yellow("*") << dye::black_on_yellow(" ") << "\n   " << this->desc << dye::light_red("\n   Deals ") << dye::light_red(this->damage) << dye::light_red(" melee damage") << dye::light_green("\n   Inceases ") << dye::light_green(this->STR_Attribute_Type) << dye::light_green(" attacks by ") << dye::light_green(int((this->FLT_Bonus_Value * 100) - 100)) << dye::light_green("%");
		}
		else
		{
			cout << dye::grey_on_white(" x") << dye::grey_on_white(this->getQuantity()) << dye::black_on_white(" ") << dye::black_on_white(this->name) << dye::black_on_white(" ") << dye::black_on_yellow(" ") << dye::black_on_yellow(this->rarity) << dye::black_on_yellow("*") << dye::black_on_yellow(" ") << "\n   " << this->desc << dye::light_red("\n   Deals ") << dye::light_red(this->damage) << dye::light_red(" melee damage") << dye::light_green("\n   Reduces incoming damage by ") << dye::light_green(int((this->FLT_Bonus_Value * 100) - 100)) << dye::light_green("%");
		}
	}
	else if (this->BOOL_Has_Element)
	{
		cout << dye::grey_on_white(" x") << dye::grey_on_white(this->getQuantity()) << dye::black_on_white(" ") << dye::black_on_white(this->name) << dye::black_on_white(" ") << dye::black_on_yellow(" ") << dye::black_on_yellow(this->rarity) << dye::black_on_yellow("*") << dye::black_on_yellow(" ") << "\n   " << this->desc << dye::light_red("\n   Deals ") << dye::light_red(this->damage) << dye::light_red(" melee damage") << dye::light_green("\n   Deals ") << dye::light_green(int((this->FLT_Bonus_Value * 100) - 100)) << dye::light_green("% extra damage against enemies weak to ") << dye::light_green(this->STR_Elemental_Type);
	}
	else
	{
		cout << dye::grey_on_white(" x") << dye::grey_on_white(this->getQuantity()) << dye::black_on_white(" ") << dye::black_on_white(this->name) << dye::black_on_white(" ") << dye::black_on_yellow(" ") << dye::black_on_yellow(this->rarity) << dye::black_on_yellow("*") << dye::black_on_yellow(" ") << "\n   " << this->desc << dye::light_red("\n   Deals ") << dye::light_red(this->damage) << dye::light_red(" melee damage");
	}
}
