#pragma once
#include "Dungeon.h"

class DungeonMagma : public Dungeon
{
private:
public:
	DungeonMagma();
	void fillWithEnemies() override;
	void fillWithChests() override;
	void elementSetter(Enemy& ENEMY_Enemy) override;
	Enemy newEnemy() override;
	Item* getItemFromLootTable(string STR_Enemy_Name) override;
	Item* getItemFromChest() override;
};

