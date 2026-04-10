#pragma once
#include "Dungeon.h"

class DungeonFacility : public Dungeon
{
private:
public:
	DungeonFacility();
	void fillWithEnemies() override;
	void fillWithChests() override;
	//DungeonGlacier(Player& player);
};

