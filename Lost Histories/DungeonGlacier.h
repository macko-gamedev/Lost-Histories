#pragma once
#include "Dungeon.h"

class DungeonGlacier : public Dungeon
{
private:
public:
	DungeonGlacier(string N_Name);
	Enemy newEnemy() override;
	Item* getItemFromChest() override;
};

