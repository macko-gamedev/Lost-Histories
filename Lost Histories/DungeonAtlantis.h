#pragma once
#include "Dungeon.h"

class DungeonAtlantis : public Dungeon
{
private:
public:
	DungeonAtlantis(string N_Name);
	Enemy newEnemy() override;
	Item* getItemFromChest() override;
};

