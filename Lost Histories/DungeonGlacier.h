#pragma once
#include "Dungeon.h"

class DungeonGlacier : public Dungeon
{
private:
public:
	DungeonGlacier(string N_Name);
	void displayDungeon() override;
	Enemy newEnemy() override;
	Item* getItemFromChest() override;
};

