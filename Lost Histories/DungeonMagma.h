#pragma once
#include "Dungeon.h"

class DungeonMagma : public Dungeon
{
private:
public:
	DungeonMagma(string N_Name);
	void displayDungeon() override;
	Enemy newEnemy() override;
	Item* getItemFromChest() override;
};

