#include "ItemConsumable.h"

ItemConsumable::ItemConsumable() {}

ItemConsumable::ItemConsumable(string nName, string nDesc, int nRarity, string nType, double nAmount) : Item(nName, nDesc, nRarity)
{
	this->type = nType;
	this->amount = nAmount;
	this->meleeItem = false;
	this->skillInheritance = false;
	this->consumable = true;
}

void ItemConsumable::toString()
{
	if (this->type == "ATK")
	{
		cout << "   " << dye::grey_on_white(" x") << dye::grey_on_white(this->getQuantity()) << dye::black_on_white(" ") << dye::black_on_white(this->name) << dye::black_on_white(" ") << dye::black_on_yellow(" ") << dye::black_on_yellow(this->rarity) << dye::black_on_yellow("*") << dye::black_on_yellow(" ") << "\n   " << this->desc << dye::light_aqua("\n   Increases damage of next melee attack by ") << dye::light_aqua(to_string(int((this->amount * 100) - 100))) << dye::light_aqua("%");
	}
	else if (this->type == "MAG")
	{
		cout << "   " << dye::grey_on_white(" x") << dye::grey_on_white(this->getQuantity()) << dye::black_on_white(" ") << dye::black_on_white(this->name) << dye::black_on_white(" ") << dye::black_on_yellow(" ") << dye::black_on_yellow(this->rarity) << dye::black_on_yellow("*") << dye::black_on_yellow(" ") << "\n   " << this->desc << dye::light_aqua("\n   Increases damage of next magic attack by ") << dye::light_aqua(to_string(int((this->amount * 100) - 100))) << dye::light_aqua("%");
	}
	else if (this->type == "ATK/MAG")
	{
		cout << "   " << dye::grey_on_white(" x") << dye::grey_on_white(this->getQuantity()) << dye::black_on_white(" ") << dye::black_on_white(this->name) << dye::black_on_white(" ") << dye::black_on_yellow(" ") << dye::black_on_yellow(this->rarity) << dye::black_on_yellow("*") << dye::black_on_yellow(" ") << "\n   " << this->desc << dye::light_aqua("\n   Increases damage of next melee and magic attack by ") << dye::light_aqua(to_string(int((this->amount * 100) - 100))) << dye::light_aqua("%");
	}
	else
	{
		cout << "   " << dye::grey_on_white(" x") << dye::grey_on_white(this->getQuantity()) << dye::black_on_white(" ") << dye::black_on_white(this->name) << dye::black_on_white(" ") << dye::black_on_yellow(" ") << dye::black_on_yellow(this->rarity) << dye::black_on_yellow("*") << dye::black_on_yellow(" ") << "\n   " << this->desc << dye::light_aqua("\n   Restores ") << dye::light_aqua(this->amount) << " " << dye::light_aqua(this->type);
	}
}
