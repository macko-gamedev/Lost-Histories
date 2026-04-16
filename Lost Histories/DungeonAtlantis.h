#pragma once
#include "Dungeon.h"

class DungeonAtlantis : public Dungeon
{
private:
public:
	DungeonAtlantis();
	void fillWithEnemies() override;
	void fillWithChests() override;
	void elementSetter(Enemy& ENEMY_Enemy) override;
	Enemy newEnemy() override;
	Item* getItemFromLootTable(string STR_Enemy_Name) override;
	Item* getItemFromChest() override;
};

