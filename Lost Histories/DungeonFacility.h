#pragma once
#include "Dungeon.h"

class DungeonFacility : public Dungeon
{
private:
public:
	DungeonFacility(string N_Name);
	Enemy newEnemy() override;
	Item* getItemFromChest() override;
};

