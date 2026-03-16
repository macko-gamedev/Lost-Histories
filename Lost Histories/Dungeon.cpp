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
	else if (enemy.getName() == "Bergmite")
	{
		enemy.setElements({ "Wk", "-", "-", "Rst", "-", "-" });
	}
	else if (enemy.getName() == "Wasteland Spirit")
	{
		enemy.setElements({ "Wk", "Rst", "Rst", "-", "-", "Wk" });
	}
	else if (enemy.getName() == "Duty Soldier")
	{
		enemy.setElements({ "-", "Rst", "Wk", "Rst", "-", "-" });
	}
	else if (enemy.getName() == "Lab Fish")
	{
		enemy.setElements({ "-", "-", "Rst", "-", "Rst", "Wk" });
	}
	else if (enemy.getName() == "Gold Fish")
	{
		enemy.setElements({ "Rst", "Rst", "Rst", "Rst", "Rst", "Rst" });
	}
	// Mini Bosses
	if (enemy.getName() == "Snow Golem")
	{
		enemy.setElements({ "Wk", "Rst", "-", "Rst", "-", "-" });
	}
	else if (enemy.getName() == "Patrol Soldier")
	{
		enemy.setElements({ "-", "Rst", "Wk", "Rst", "-", "-" });
	}
	else if (enemy.getName() == "Reanimated Mermaid")
	{
		enemy.setElements({ "Rst", "Wk", "-", "-", "Rst", "-" });
	}
	// Bosses
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
				return Enemy("Wasteland Spirit", ((rand() % 4) + 12), 79, 41, { Skill("Flame"), Skill("Freeze"), Skill("Zap"), Skill("Gust") }, getItemFromLootTable("Wasteland Spirit"), false, 34);
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
			return Enemy("Patrol Soldier", 15, 146, 27, { Skill("Flamao"), Skill("Meflamao"), Skill("Gustan"), Skill("Blighta") }, new Item("Gun Fragment", "A piece of fragment from a Soldiers gun", 3), true, 48);
		}
	}
	else if (curr_dungeon->getDungeonName() == "Atlantis Ruins")
	{
		if (curr_dungeon->getDungeonRoom() == 1)
		{
			// Enemy level for this floor: 14-20		Patrol Soldier: 14-17   Lab Fish: 16-19   Gold Fish: 20
			int enemySpawnChance = (rand() % 10) + 1;
			if (enemySpawnChance == 10)
			{
				return Enemy("Gold Fish", 20, 150, 0, { }, getItemFromLootTable("Gold Fish"), true, 10);
			}
			else if (enemySpawnChance > 5)
			{
				return Enemy("Lab Fish", ((rand() % 3) + 16), 125, 109, { Skill("Freezan"), Skill("Zapao"), Skill("Mezapao"), Skill("Hex") }, getItemFromLootTable("Lab Fish"), false, 33);
			}
			else
			{
				return Enemy("Patrol Soldier", ((rand() % 3) + 14), 146, 27, { Skill("Flamao"), Skill("Meflamao"), Skill("Gustan"), Skill("Blighta") }, getItemFromLootTable("Patrol Soldier"), false, 48);
			}
		}
		else if (curr_dungeon->getDungeonRoom() == 2)
		{
			// Enemy level for this floor: 17-23		Patrol Soldier: 17-20   Lab Fish: 18-22   Royal Guard: 20-23   Gold Fish: 20
			int enemySpawnChance = (rand() % 20) + 1;
			if (enemySpawnChance > 18)
			{
				return Enemy("Gold Fish", 20, 150, 0, { }, getItemFromLootTable("Gold Fish"), true, 10);
			}
			else if (enemySpawnChance > 14)
			{
				return Enemy("Royal Guard", ((rand() % 3) + 20), 173, 69, { Skill("Flamao"), Skill("Freezan"), Skill("Hex"), Skill("Blight") }, getItemFromLootTable("Royal Guard"), false, 67);
			}
			else if (enemySpawnChance > 7)
			{
				return Enemy("Lab Fish", ((rand() % 4) + 18), 125, 109, { Skill("Freezan"), Skill("Zapao"), Skill("Mezapao"), Skill("Hex") }, getItemFromLootTable("Lab Fish"), false, 33);
			}
			else
			{
				return Enemy("Patrol Soldier", ((rand() % 3) + 17), 146, 27, { Skill("Flamao"), Skill("Meflamao"), Skill("Gustan"), Skill("Blighta") }, getItemFromLootTable("Patrol Soldier"), false, 48);
			}
		}
	}
}

Item* Dungeon::getItemFromLootTable(string enemyName)
{
	vector<Item*> drops = { };
	if (enemyName == "Ice Monster")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) drops.push_back(new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1));
		/* 1 STAR */ for (int i = 0; i < 5; i++) drops.push_back(new ItemSkill("Ice Core", "A strange looking block of ice", 1, Skill("Freeze")));
		/* 1 STAR */ for (int i = 0; i < 5; i++) drops.push_back(new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 40));
		/* 2 STAR */ for (int i = 0; i < 4; i++) drops.push_back(new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2));
	}
	else if (enemyName == "Ice Fiend")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) drops.push_back(new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1));
		/* 1 STAR */ for (int i = 0; i < 5; i++) drops.push_back(new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 40));
		/* 2 STAR */ for (int i = 0; i < 4; i++) drops.push_back(new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) drops.push_back(new ItemSkill("Ice Shard", "A sharp ended icicle which could shatter", 2, Skill("Mefreeze")));
		/* 2 STAR */ for (int i = 0; i < 4; i++) drops.push_back(new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 35));
		/* 3 STAR */ for (int i = 0; i < 3; i++) drops.push_back(new ItemSkill("Crystalised Flake", "A snowflake fully crystalised, emitting a frosty aura", 3, Skill("Freezan")));
	}
	else if (enemyName == "Bergmite")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) drops.push_back(new ItemSkill("Dented Airhorn", "Old, red-ended airhorn which somehow still works", 1, Skill("Gust")));
		/* 1 STAR */ for (int i = 0; i < 5; i++) drops.push_back(new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 40));
		/* 1 STAR */ for (int i = 0; i < 5; i++) drops.push_back(new ItemConsumable("Energy Pills", "Unopened tub of energy pills", 1, "STA", 15));
		/* 2 STAR */ for (int i = 0; i < 4; i++) drops.push_back(new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) drops.push_back(new ItemConsumable("Worn Field Kit", "Can still be used for emergencies", 2, "HP", 100));
		/* 2 STAR */ for (int i = 0; i < 4; i++) drops.push_back(new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 35));
		/* 3 STAR */ for (int i = 0; i < 3; i++) drops.push_back(new ItemSkill("Cold Hairdryer", "Lethalised hairdryer from the 2040s, the air is even more colder.", 2, Skill("Gustan")));
	}
	else if (enemyName == "Wasteland Spirit")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) drops.push_back(new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1));
		/* 1 STAR */ for (int i = 0; i < 5; i++) drops.push_back(new ItemSkill("Shattered Molotov", "Ash remains inside the bottle", 1, Skill("Flame")));
		/* 1 STAR */ for (int i = 0; i < 5; i++) drops.push_back(new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 40));
		/* 1 STAR */ for (int i = 0; i < 5; i++) drops.push_back(new ItemConsumable("Energy Pills", "Unopened tub of energy pills", 1, "STA", 15));
		/* 2 STAR */ for (int i = 0; i < 4; i++) drops.push_back(new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) drops.push_back(new ItemConsumable("Worn Field Kit", "Can still be used for emergencies", 2, "HP", 100));
		/* 2 STAR */ for (int i = 0; i < 4; i++) drops.push_back(new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 35));
		/* 3 STAR */ for (int i = 0; i < 3; i++) drops.push_back(new ItemSkill("Power Cord", "Unfrozen exposed power cable. Wonder if it still sparks?", 3, Skill("Zapao")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) drops.push_back(new ItemConsumable("Medkit", "For a quick patch up", 3, "HP", 200));
	}
	else if (enemyName == "Patrol Soldier")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) drops.push_back(new ItemConsumable("Worn Field Kit", "Can still be used for emergencies", 2, "HP", 100));
		/* 2 STAR */ for (int i = 0; i < 4; i++) drops.push_back(new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 35));
		/* 3 STAR */ for (int i = 0; i < 3; i++) drops.push_back(new ItemConsumable("Medkit", "For a quick patch up", 3, "HP", 200));
		/* 3 STAR */ for (int i = 0; i < 3; i++) drops.push_back(new ItemConsumable("Holy Water", "Drinking this feels godly", 3, "STA", 80));
		/* 3 STAR */ for (int i = 0; i < 3; i++) drops.push_back(new Item("Gun Fragment", "A piece of fragment from a Soldiers gun", 3));
		/* 4 STAR */ for (int i = 0; i < 2; i++) drops.push_back(new ItemSkill("Firecracker", "Who loves a little bit of fire play", 4, Skill("Meflamao")));
	}
	else if (enemyName == "Lab Fish")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) drops.push_back(new Item("Seaweed", "Lonely strand of seaweed", 1));
		/* 2 STAR */ for (int i = 0; i < 4; i++) drops.push_back(new Item("Fish Tooth", "Caution, may be sharp", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) drops.push_back(new ItemSkill("Squid Head", "Squirts black genetically modified ink", 2, Skill("Mehex")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) drops.push_back(new ItemConsumable("Holy Water", "Drinking this feels godly", 3, "STA", 80));
		/* 4 STAR */ for (int i = 0; i < 2; i++) drops.push_back(new ItemSkill("Jellyfish Tenticle", "Dead or Alive it still carries some charge", 4, Skill("Zapadia")));;
	}
	else if (enemyName == "Royal Guard")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) drops.push_back(new Item("Seaweed", "Lonely strand of seaweed", 1));
		/* 2 STAR */ for (int i = 0; i < 4; i++) drops.push_back(new Item("Mermaid Tail", "Sadly from a dead mermaid corpse", 2));
		/* 3 STAR */ for (int i = 0; i < 3; i++) drops.push_back(new Item("Gold Coin", "Made of real gold!", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) drops.push_back(new ItemConsumable("Holy Water", "Drinking this feels godly", 3, "STA", 80));
		/* 3 STAR */ for (int i = 0; i < 3; i++) drops.push_back(new ItemSkill("Old Pendant", "An old heart pendant emitting a healthy aura", 3, Skill("Heal")));
		/* 3 STAR */ for (int i = 0; i < 2; i++) drops.push_back(new ItemConsumable("Bottle o' Holy Water", "500ml of pure holy water!", 4, "STA", 150));
		/* 4 STAR */ for (int i = 0; i < 2; i++) drops.push_back(new ItemSkill("Dark Staff", "Some foul play is at work here...", 4, Skill("Mehexo")));;
	}
	else if (enemyName == "Gold Fish")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) drops.push_back(new ItemSkill("Box of Matches", "Withered box of fire matches, can they still alight?", 2, Skill("Meflame")));
		/* 2 STAR */ for (int i = 0; i < 4; i++) drops.push_back(new ItemSkill("Ice Shard", "A sharp ended icicle which could shatter", 2, Skill("Mefreeze")));
		/* 2 STAR */ for (int i = 0; i < 4; i++) drops.push_back(new ItemSkill("Live Cables", "A bundle of small exposed cables", 2, Skill("Mezap")));
		/* 2 STAR */ for (int i = 0; i < 4; i++) drops.push_back(new ItemSkill("Goat Horn", "Remains of what looks like a goat, what is it even doing here?", 2, Skill("Megust")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) drops.push_back(new Item("Diamond", "A natural chunk of diamond from the earth", 5));
	}
	return drops[rand() % drops.size()];
}