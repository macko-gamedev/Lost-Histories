#pragma once
#include "Dungeon.h"

class DungeonDomain : public Dungeon
{
private:
public:
	DungeonDomain(string N_Name);
	Enemy newEnemy() override;
	Item* getItemFromChest() override;
};
