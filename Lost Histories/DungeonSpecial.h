#pragma once
#include "Dungeon.h"

class DungeonSpecial : public Dungeon
{
private:
public:
	DungeonSpecial(string N_Name);
	Enemy newEnemy() override;
	Item* getItemFromChest() override;
};

