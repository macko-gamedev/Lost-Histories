#pragma once
#include "Dungeon.h"

class DungeonAtlantis : public Dungeon
{
private:
public:
	DungeonAtlantis();
	Enemy newEnemy() override;
	Item* getItemFromChest() override;
};

