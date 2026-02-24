#pragma once
#include "Dungeon.h"

class DungeonGlacier : public Dungeon
{
private:
public:
	DungeonGlacier();
	void fillWithEnemies() override;
	//DungeonGlacier(Player& player);
};

