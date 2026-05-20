#pragma once
#include "Dungeon.h"

class DungeonMagma : public Dungeon
{
private:
public:
	DungeonMagma(string N_Name);
	Enemy newEnemy() override;
	Item* getItemFromChest() override;
};

