#pragma once
#include "Dungeon.h"

class DungeonSpecial : public Dungeon
{
private:
public:
	DungeonSpecial();
	Enemy newEnemy() override;
	Item* getItemFromChest() override;
};

