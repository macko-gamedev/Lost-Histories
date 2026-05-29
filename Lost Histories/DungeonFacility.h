#pragma once
#include "Dungeon.h"

class DungeonFacility : public Dungeon
{
private:
public:
	DungeonFacility(string N_Name);
	void displayDungeon() override;
	Enemy newEnemy() override;
	Item* getItemFromChest() override;
};

