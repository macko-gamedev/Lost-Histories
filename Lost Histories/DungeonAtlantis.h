#pragma once
#include "Dungeon.h"

class DungeonAtlantis : public Dungeon
{
private:
public:
	DungeonAtlantis();
	void fillWithEnemies() override;
	void fillWithChests() override;
	//DungeonGlacier(Player& player);
};

