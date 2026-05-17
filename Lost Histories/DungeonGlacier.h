#pragma once
#include "Dungeon.h"

class DungeonGlacier : public Dungeon
{
private:
public:
	DungeonGlacier();
	Enemy newEnemy() override;
	Item* getItemFromChest() override;
};

