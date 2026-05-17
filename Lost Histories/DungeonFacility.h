#pragma once
#include "Dungeon.h"

class DungeonFacility : public Dungeon
{
private:
public:
	DungeonFacility();
	Enemy newEnemy() override;
	Item* getItemFromChest() override;
};

