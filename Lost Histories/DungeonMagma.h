#pragma once
#include "Dungeon.h"

class DungeonMagma : public Dungeon
{
private:
public:
	DungeonMagma();
	Enemy newEnemy() override;
	Item* getItemFromChest() override;
};

