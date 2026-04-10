#pragma once
#include "Dungeon.h"

class DungeonAtlantis : public Dungeon
{
private:
public:
	DungeonAtlantis();
	void fillWithEnemies() override;
	void fillWithChests() override;
	Item* getItemFromLootTable(string STR_Enemy_Name) override;
	//DungeonGlacier(Player& player);
};

