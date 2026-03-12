#include "Dungeon.h"

Dungeon::Dungeon() {}

Dungeon::Dungeon(Player& player)
{
	this->pos_x = 0;
	this->pos_y = 0;
}

vector<vector<vector<char>>> Dungeon::getDungeonMap()
{
	return this->dungeon_map;
}

string Dungeon::getDungeonName()
{
	return this->dungeon_name;
}

char Dungeon::getPosition(int room, int x, int y)
{
	return this->dungeon_map[room][x][y];
}

int Dungeon::getDungeonRoom()
{
	return this->dungeon_room;
}

int Dungeon::getPosX()
{
	return this->pos_x;
}

int Dungeon::getPosY()
{
	return this->pos_y;
}

void Dungeon::changeDungeonRoom(int value)
{
	this->dungeon_room += value;
}

void Dungeon::setPosition(int room, int x, int y, char icon)
{
	this->dungeon_map[room][x][y] = icon;
}

void Dungeon::setPosX(int x)
{
	this->pos_x = x;
}

void Dungeon::setPosY(int y)
{
	this->pos_y = y;
}

void Dungeon::changePosX(int amount)
{
	this->pos_x += amount;
}

void Dungeon::changePosY(int amount)
{
	this->pos_y += amount;
}

void Dungeon::fillWithEnemies()
{

}

void Dungeon::fillWithChests()
{

}

void Dungeon::elementSetter(Enemy& enemy)
{
	if (enemy.getName() == "Ice Monster")
	{
		enemy.setElements({ "Wk", "Rst", "-", "-", "-", "-" });
	}
	else if (enemy.getName() == "Ice Fiend")
	{
		enemy.setElements({ "Rst", "Rst", "-", "-", "-", "-" });
	}
	else if (enemy.getName() == "Snow Golem")
	{
		enemy.setElements({ "Wk", "Rst", "-", "Rst", "-", "-" });
	}
	else if (enemy.getName() == "Bergmite")
	{
		enemy.setElements({ "Wk", "-", "-", "Rst", "-", "-" });
	}
	else if (enemy.getName() == "Wasteland Spirit")
	{
		enemy.setElements({ "Wk", "Rst", "Rst", "-", "-", "Wk" });
	}
	else if (enemy.getName() == "Patrol Soldier")
	{
		enemy.setElements({ "-", "Rst", "Wk", "Rst", "-", "-" });
	}
	else if (enemy.getName() == "Duty Soldier")
	{
		enemy.setElements({ "-", "Rst", "Wk", "Rst", "-", "-" });
	}
	else if (enemy.getName() == "Russian Sergeant")
	{
		enemy.setElements({ "Rst", "Rst", "Wk", "Rst", "Wk", "Wk" });
	}
}

Enemy Dungeon::newEnemy(Dungeon* curr_dungeon)
{
	// Similar to Skill.h, cycles through each possible dungeon to determine which enemy is encountered
	if (curr_dungeon->getDungeonName() == "Glacier Wasteland") // There will be 6 floors with the ending of floor 6 being a boss
	{
		if (curr_dungeon->getDungeonRoom() == 1)
		{
			// Enemy level for this floor: 1-3		Ice Monster: 1-3
			return Enemy("Ice Monster", ((rand() % 3) + 1), 30, 24, { Skill("Freeze") }, getItemFromLootTable("Ice Monster"), false, 14);
		}
		else if (curr_dungeon->getDungeonRoom() == 2)
		{
			// Enemy Level for this floor: 2-5		Ice Monster: 2-5
			return Enemy("Ice Monster", ((rand() % 4) + 2), 30, 24, { Skill("Freeze") }, getItemFromLootTable("Ice Monster"), false, 14);
		}
		else if (curr_dungeon->getDungeonRoom() == 3)
		{
			// Enemy Level for this floor: 3-7		Ice Monster: 3-6	Ice Fiend: 4-7
			if (((rand() % 5) + 1) > 3)
			{
				return Enemy("Ice Fiend", ((rand() % 4) + 4), 45, 18, { Skill("Freeze"), Skill("Freezan") }, getItemFromLootTable("Ice Fiend"), false, 21);
			}
			else
			{
				return Enemy("Ice Monster", ((rand() % 4) + 3), 30, 24, { Skill("Freeze") }, getItemFromLootTable("Ice Monster"), false, 14);
			}
		}
		else if (curr_dungeon->getDungeonRoom() == 4)
		{
			// Enemy Level for this floor: 4-9		Ice Monster: 4-8	Ice Fiend: 5-8	 Bergmite: 5-9
			int enemySpawnChance = (rand() % 10) + 1;
			if (enemySpawnChance > 7)
			{
				return Enemy("Bergmite", ((rand() % 5) + 5), 62, 27, { Skill("Freezan"), Skill("Gust") }, getItemFromLootTable("Bergmite"), false, 26);
			}
			else if (enemySpawnChance > 3)
			{
				return Enemy("Ice Fiend", ((rand() % 4) + 5), 45, 18, { Skill("Freeze"), Skill("Freezan") }, getItemFromLootTable("Ice Fiend"), false, 21);
			}
			else
			{
				return Enemy("Ice Monster", ((rand() % 5) + 4), 30, 24, { Skill("Freeze") }, getItemFromLootTable("Ice Monster"), false, 14);
			}
		}
		else if (curr_dungeon->getDungeonRoom() == 5)
		{
			// Enemy Level for this floor: 8-15		Ice Monster: 8-12	Ice Fiend: 9-13	 Bergmite: 10-15   Wasteland Spirit: 12-15
			int enemySpawnChance = (rand() % 20) + 1;
			if (enemySpawnChance > 17)
			{
				return Enemy("Wasteland Spirit", ((rand() % 4) + 12), 79, 41, { Skill("Flame"), Skill("Freeze"), Skill("Zap"), Skill("Gust") }, new ItemSkill("Power Cord", "Unfrozen exposed power cable. Wonder if it still sparks?", 2, Skill("Zapao")), false, 34);
			}
			if (enemySpawnChance > 11)
			{
				return Enemy("Bergmite", ((rand() % 6) + 10), 62, 27, { Skill("Freezan"), Skill("Gust") }, getItemFromLootTable("Bergmite"), false, 26);
			}
			else if (enemySpawnChance > 6)
			{
				return Enemy("Ice Fiend", ((rand() % 5) + 9), 45, 18, { Skill("Freeze"), Skill("Freezan") }, getItemFromLootTable("Ice Fiend"), false, 21);
			}
			else
			{
				return Enemy("Ice Monster", ((rand() % 5) + 8), 30, 24, { Skill("Freeze") }, getItemFromLootTable("Ice Monster"), false, 14);
			}
		}

		else if (curr_dungeon->getDungeonRoom() == 6)
		{
			// Enemy Level for this floor: 15		Patrol Soldier: 15
			return Enemy("Patrol Soldier", 15, 146, 27, { Skill("Flamao"), Skill("Meflamao"), Skill("Gustan"), Skill("Blighta") }, new Item("Gun Fragment", "A piece of fragment from a Soldiers gun.", 3), false, 48);
		}
	}
}

Item* Dungeon::getItemFromLootTable(string enemyName)
{
	vector<Item*> drops;
	if (enemyName == "Ice Monster")
	{
		vector<Item*> drops =
		{
			/* 1 STAR */ new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1),
			/*        */ new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1),
			/* 1 STAR */ new ItemSkill("Ice Core", "A strange looking block of ice", 1, Skill("Freeze")),
			/*        */ new ItemSkill("Ice Core", "A strange looking block of ice", 1, Skill("Freeze")),
			/* 1 STAR */ new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 20),
			/*        */ new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 20),
			/* 2 STAR */ new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2)
		};
	}
	else if (enemyName == "Ice Fiend")
	{
		vector<Item*> drops =
		{
			/* 1 STAR */ new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1),
			/*        */ new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1),
			/*        */ new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1),
			/* 1 STAR */ new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 20),
			/*        */ new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 20),
			/*        */ new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 20),
			/* 2 STAR */ new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2),
			/*        */ new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2),
			/* 2 STAR */ new ItemSkill("Ice Shard", "A sharp ended icicle which could shatter", 2, Skill("Mefreeze")),
			/*        */ new ItemSkill("Ice Shard", "A sharp ended icicle which could shatter", 2, Skill("Mefreeze")),
			/* 2 STAR */ new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 15),
			/*        */ new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 15),
			/* 3 STAR */ new ItemSkill("Crystalised Flake", "A snowflake fully crystalised, emitting a frosty aura", 3, Skill("Freezan"))
		};
	}
	else if (enemyName == "Bergmite")
	{
		vector<Item*> drops =
		{
			/* 1 STAR */ new ItemSkill("Dented Airhorn", "Old, red-ended airhorn which somehow still works", 1, Skill("Gust")),
			/*        */ new ItemSkill("Dented Airhorn", "Old, red-ended airhorn which somehow still works", 1, Skill("Gust")),
			/*        */ new ItemSkill("Dented Airhorn", "Old, red-ended airhorn which somehow still works", 1, Skill("Gust")),
			/* 1 STAR */ new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 20),
			/*        */ new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 20),
			/*        */ new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 20),
			/* 1 STAR */ new ItemConsumable("Energy Pills", "Unopened tub of energy pills", 1, "STA", 10),
			/*        */ new ItemConsumable("Energy Pills", "Unopened tub of energy pills", 1, "STA", 10),
			/*        */ new ItemConsumable("Energy Pills", "Unopened tub of energy pills", 1, "STA", 10),
			/* 2 STAR */ new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2),
			/*        */ new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2),
			/* 2 STAR */ new ItemConsumable("Worn Field Kit", "Can still be used for emergencies", 2, "HP", 50),
			/*        */ new ItemConsumable("Worn Field Kit", "Can still be used for emergencies", 2, "HP", 50),
			/* 2 STAR */ new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 15),
			/*        */ new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 15),
			/* 3 STAR */ new ItemSkill("Cold Hairdryer", "Lethalised hairdryer from the 2040s, the air is even more colder.", 2, Skill("Gustan"))
		};
	}
	return drops[rand() % drops.size()];
}