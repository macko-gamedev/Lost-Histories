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

Enemy Dungeon::newEnemy(Dungeon* curr_dungeon)
{
	// Similar to Skill.h, cycles through each possible dungeon to determine which enemy is encountered
	if (curr_dungeon->getDungeonName() == "Glacier Wasteland") // There will be 6 floors with the ending of floor 6 being a boss
	{
		if (curr_dungeon->getDungeonRoom() == 1)
		{
			// Enemy level for this floor: 1-3		Ice Monster: 1-3
			return Enemy("Ice Monster", ((rand() % 3) + 1), 10, 24, { Skill("Freeze") }, new ItemSkill("Ice Core", "A strange looking block of ice", 1, Skill("Freeze")));
		}
		else if (curr_dungeon->getDungeonRoom() == 2)
		{
			// Enemy Level for this floor: 2-5		Ice Monster: 2-5
			return Enemy("Ice Monster", ((rand() % 4) + 2), 10, 24, { Skill("Freeze") }, new ItemSkill("Ice Core", "A strange looking block of ice", 1, Skill("Freeze")));
		}
		else if (curr_dungeon->getDungeonRoom() == 3)
		{
			// Enemy Level for this floor: 3-7		Ice Monster: 3-6	Ice Fiend: 4-7
			int dropChance = (rand() % 100) + 1;
			if (((rand() % 5) + 1) > 3)
			{
				if (dropChance > 89)
				{
					return Enemy("Ice Fiend", ((rand() % 4) + 4), 45, 18, { Skill("Freeze"), Skill("Freezan") }, new ItemSkill("Ice Shard", "A sharp ended icicle", 2, Skill("Freezan")));
				}
				else
				{
					return Enemy("Ice Fiend", ((rand() % 4) + 4), 45, 18, { Skill("Freeze"), Skill("Freezan") }, new Item("Scratched Coin", "A corn coated in scratches, the date on it says 2026", 2));
				}
			}
			else
			{
				return Enemy("Ice Monster", ((rand() % 4) + 3), 10, 24, { Skill("Freeze") }, new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1));
			}
		}
		else if (curr_dungeon->getDungeonRoom() == 4)
		{
			// Enemy Level for this floor: 4-9		Ice Monster: 4-8	Ice Fiend: 5-8	 Bergmite: 5-9
			int enemySpawnChance = (rand() % 10) + 1;
			int dropChance = (rand() % 100) + 1;
			if (enemySpawnChance > 7)
			{
				return Enemy("Bergmite", ((rand() % 5) + 5), 62, 27, { Skill("Freezan"), Skill("Gust") }, new ItemSkill("Dented Airhorn", "Old, red-ended airhorn which somehow still works", 1, Skill("Gust")));
			}
			else if (enemySpawnChance > 3)
			{
				if (dropChance > 64)
				{
					return Enemy("Ice Fiend", ((rand() % 4) + 5), 45, 18, { Skill("Freeze"), Skill("Freezan") }, new ItemSkill("Ice Shard", "A sharp ended icicle", 2, Skill("Freezan")));
				}
				else
				{
					return Enemy("Ice Fiend", ((rand() % 4) + 5), 45, 18, { Skill("Freeze"), Skill("Freezan") }, new Item("Scratched Coin", "A corn coated in scratches, the date on it says 2026", 2));
				}
			}
			else
			{
				return Enemy("Ice Monster", ((rand() % 5) + 4), 10, 24, { Skill("Freeze") }, new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1));
			}
		}
		else if (curr_dungeon->getDungeonRoom() == 5)
		{
			// Enemy Level for this floor: 8-15		Ice Monster: 8-12	Ice Fiend: 9-13	 Bergmite: 10-15   Wasteland Spirit: 12-15
			int enemySpawnChance = (rand() % 20) + 1;
			int dropChance = (rand() % 100) + 1;
			if (enemySpawnChance > 17)
			{
				return Enemy("Wasteland Spirit", ((rand() % 4) + 12), 79, 41, { Skill("Flame"), Skill("Freeze"), Skill("Zap"), Skill("Gust") }, new ItemSkill("Power Cord", "Unfrozen exposed power cable. Wonder if it still sparks?", 2, Skill("Zapao")));
			}
			if (enemySpawnChance > 11)
			{
				if (dropChance > 84)
				{
					return Enemy("Bergmite", ((rand() % 6) + 810), 62, 27, { Skill("Freezan"), Skill("Gust") }, new ItemSkill("Cold Hairdryer", "Lethalised hairdryer from the 2040s, the air is even more colder.", 2, Skill("Gustan")));
				}
				else if (dropChance > 69)
				{
					return Enemy("Bergmite", ((rand() % 6) + 10), 62, 27, { Skill("Freezan"), Skill("Gust") }, new ItemSkill("Dented Airhorn", "Old, red-ended airhorn which somehow still works", 1, Skill("Gust")));
				}
				else
				{
					return Enemy("Bergmite", ((rand() % 6) + 10), 62, 27, { Skill("Freezan"), Skill("Gust") }, new ItemSkill("Dented Airhorn", "Old, red-ended airhorn which somehow still works", 1, Skill("Gust")));
				}
			}
			else if (enemySpawnChance > 6)
			{
				if (dropChance > 89)
				{
					return Enemy("Ice Fiend", ((rand() % 5) + 9), 45, 18, { Skill("Freeze"), Skill("Freezan") }, new ItemSkill("Ice Crystal", "Crysalised ice emitting a strong frosty aura", 3, Skill("Mefreezan")));
				}
				else if (dropChance > 49)
				{
					return Enemy("Ice Fiend", ((rand() % 5) + 9), 45, 18, { Skill("Freeze"), Skill("Freezan") }, new ItemSkill("Ice Shard", "A sharp ended icicle", 2, Skill("Freezan")));
				}
				else
				{
					return Enemy("Ice Fiend", ((rand() % 5) + 9), 45, 18, { Skill("Freeze"), Skill("Freezan") }, new Item("Scratched Coin", "A corn coated in scratches, the date on it says 2026", 2));
				}
			}
			else
			{
				return Enemy("Ice Monster", ((rand() % 5) + 8), 10, 24, { Skill("Freeze") }, new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1));
			}
		}

		else if (curr_dungeon->getDungeonRoom() == 6)
		{
			// Enemy Level for this floor: 15		Patrol Soldier: 15
			return Enemy("Patrol Soldier", 12, 146, 27, { Skill("Flamao"), Skill("Meflamao"), Skill("Gustan"), Skill("Blighta") }, new Item("Gun Fragment", "A piece of fragment from a Soldiers gun.", 3));
		}
	}
}