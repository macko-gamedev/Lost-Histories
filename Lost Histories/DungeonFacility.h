#pragma once
#include "Dungeon.h"

class DungeonFacility : public Dungeon
{
private:
public:
	DungeonFacility();
	void fillWithEnemies() override;
	void fillWithChests() override;
	void elementSetter(Enemy& ENEMY_Enemy) override;
	Enemy newEnemy() override;
	Item* getItemFromLootTable(string STR_Enemy_Name) override;
	Item* getItemFromChest() override;
};

