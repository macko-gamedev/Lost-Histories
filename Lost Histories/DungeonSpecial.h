#pragma once
#include "Dungeon.h"

class DungeonSpecial : public Dungeon
{
private:
public:
	DungeonSpecial(string N_Name);
	void displayDungeon() override;
	Enemy newEnemy() override;
	Item* getItemFromChest() override;
};

