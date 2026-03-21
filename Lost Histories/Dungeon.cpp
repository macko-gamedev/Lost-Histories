#include "Dungeon.h"

Dungeon::Dungeon() {}

Dungeon::Dungeon(Player& PLAYER_Player)
{
	this->INT_Pos_X = 0;
	this->INT_Pos_Y = 0;
}

vector<vector<vector<char>>> Dungeon::getDungeonMap()
{
	return this->VEC_Dungeon_Map;
}

string Dungeon::getDungeonName()
{
	return this->STR_Dungeon_Name;
}

char Dungeon::getPosition(int INT_Get_Room, int INT_Get_X, int INT_Get_Y)
{
	return this->VEC_Dungeon_Map[INT_Get_Room][INT_Get_X][INT_Get_Y];
}

int Dungeon::getDungeonRoom()
{
	return this->INT_Dungeon_Room;
}

int Dungeon::getPosX()
{
	return this->INT_Pos_X;
}

int Dungeon::getPosY()
{
	return this->INT_Pos_Y;
}

void Dungeon::changeDungeonRoom(int INT_Amount)
{
	this->INT_Dungeon_Room += INT_Amount;
}

void Dungeon::setPosition(int INT_Set_Room, int INT_Set_X, int INT_Set_Y, char CHAR_Set_Icon)
{
	this->VEC_Dungeon_Map[INT_Set_Room][INT_Set_X][INT_Set_Y] = CHAR_Set_Icon;
}

void Dungeon::setPosX(int x)
{
	this->INT_Pos_X = x;
}

void Dungeon::setPosY(int y)
{
	this->INT_Pos_Y = y;
}

void Dungeon::changePosX(int INT_Amount)
{
	this->INT_Pos_X += INT_Amount;
}

void Dungeon::changePosY(int INT_Amount)
{
	this->INT_Pos_Y += INT_Amount;
}

void Dungeon::fillWithEnemies()
{

}

void Dungeon::fillWithChests()
{

}

void Dungeon::elementSetter(Enemy& ENEMY_Enemy)
{
	if (ENEMY_Enemy.getName() == "Ice Monster")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Wk"}, {"Water", "-"}, {"Ice", "Rst"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (ENEMY_Enemy.getName() == "Ice Fiend")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Rst"}, {"Water", "-"}, {"Ice", "Rst"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (ENEMY_Enemy.getName() == "Bergmite")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Wk"}, {"Water", "-"}, {"Ice", "-"}, {"Electric", "-"}, {"Wind", "Rst"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (ENEMY_Enemy.getName() == "Wasteland Spirit")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Wk"}, {"Water", "Wk"}, {"Ice", "Rst"}, {"Electric", "Rst"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "Wk"} });
	}
	else if (ENEMY_Enemy.getName() == "Duty Soldier")
	{
		ENEMY_Enemy.setElements({ {"Fire", "-"}, {"Water", "-"}, {"Ice", "Rst"}, {"Electric", "Wk"}, {"Wind", "Rst"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (ENEMY_Enemy.getName() == "Lab Fish")
	{
		ENEMY_Enemy.setElements({ {"Fire", "-"}, {"Water", "Rst"}, {"Ice", "-"}, {"Electric", "Rst"}, {"Wind", "-"}, {"Curse", "Rst"}, {"Bless", "Wk"} });
	}
	else if (ENEMY_Enemy.getName() == "Royal Guard")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Wk"}, {"Water", "Nul"}, {"Ice", "Rst"}, {"Electric", "Rst"}, {"Wind", "-"}, {"Curse", "Nul"}, {"Bless", "Wk"} });
	}
	// Rare Enemies
	else if (ENEMY_Enemy.getName() == "Gold Fish I")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Rst"}, {"Water", "Rst"}, {"Ice", "Rst"}, {"Electric", "Rst"}, {"Wind", "Rst"}, {"Curse", "Rst"}, {"Bless", "Rst"} });
	}
	else if (ENEMY_Enemy.getName() == "Gold Fish II")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Nul"}, {"Water", "-"}, {"Ice", "Nul"}, {"Electric", "-"}, {"Wind", "Nul"}, {"Curse", "-"}, {"Bless", "Nul"} });
	}
	// Mini Bosses
	else if (ENEMY_Enemy.getName() == "Snow Golem")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Wk"}, {"Water", "-"}, {"Ice", "Nul"}, {"Electric", "-"}, {"Wind", "Rst"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (ENEMY_Enemy.getName() == "Patrol Soldier")
	{
		ENEMY_Enemy.setElements({ {"Fire", "-"}, {"Water", "-"}, {"Ice", "Rst"}, {"Electric", "Wk"}, {"Wind", "Rst"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (ENEMY_Enemy.getName() == "Reanimated Mermaid")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Nul"}, {"Water", "Nul"}, {"Ice", "Wk"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "Rst"}, {"Bless", "-"} });
	}
	// Bosses
	else if (ENEMY_Enemy.getName() == "Russian Sergeant")
	{
		ENEMY_Enemy.setElements({ {"Fire", "Rst"}, {"Water", "-"}, {"Ice", "Rst"}, {"Electric", "Wk"}, {"Wind", "Rst"}, {"Curse", "Wk"}, {"Bless", "Wk"} });
	}
}

Enemy Dungeon::newEnemy(Dungeon* DUNGEON_Current_Dungeon)
{
	// Similar to Skill.h, cycles through each possible dungeon to determine which ENEMY_Enemy is encountered
	if (DUNGEON_Current_Dungeon->getDungeonName() == "Glacier Wasteland") // There will be 6 floors with the ending of floor 6 being a boss
	{
		if (DUNGEON_Current_Dungeon->getDungeonRoom() == 1)
		{
			// Enemy level for this floor: 1-3		Ice Monster: 1-3
			return Enemy("Ice Monster", ((rand() % 3) + 1), 30, 24, { Skill("Freeze") }, getItemFromLootTable("Ice Monster"), false, 14);
		}
		else if (DUNGEON_Current_Dungeon->getDungeonRoom() == 2)
		{
			// Enemy Level for this floor: 2-5		Ice Monster: 2-5
			return Enemy("Ice Monster", ((rand() % 4) + 2), 30, 24, { Skill("Freeze") }, getItemFromLootTable("Ice Monster"), false, 14);
		}
		else if (DUNGEON_Current_Dungeon->getDungeonRoom() == 3)
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
		else if (DUNGEON_Current_Dungeon->getDungeonRoom() == 4)
		{
			// Enemy Level for this floor: 4-9		Ice Monster: 4-8	Ice Fiend: 5-8	 Bergmite: 5-9
			int INT_Enemy_Spawn_Chance = (rand() % 10) + 1;
			if (INT_Enemy_Spawn_Chance > 7)
			{
				return Enemy("Bergmite", ((rand() % 5) + 5), 62, 27, { Skill("Freezan"), Skill("Gust") }, getItemFromLootTable("Bergmite"), false, 26);
			}
			else if (INT_Enemy_Spawn_Chance > 3)
			{
				return Enemy("Ice Fiend", ((rand() % 4) + 5), 45, 18, { Skill("Freeze"), Skill("Freezan") }, getItemFromLootTable("Ice Fiend"), false, 21);
			}
			else
			{
				return Enemy("Ice Monster", ((rand() % 5) + 4), 30, 24, { Skill("Freeze") }, getItemFromLootTable("Ice Monster"), false, 14);
			}
		}
		else if (DUNGEON_Current_Dungeon->getDungeonRoom() == 5)
		{
			// Enemy Level for this floor: 8-15		Ice Monster: 8-12	Ice Fiend: 9-13	 Bergmite: 10-15   Wasteland Spirit: 12-15
			int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
			if (INT_Enemy_Spawn_Chance > 17)
			{
				return Enemy("Wasteland Spirit", ((rand() % 4) + 12), 79, 41, { Skill("Flame"), Skill("Freeze"), Skill("Zap"), Skill("Gust") }, getItemFromLootTable("Wasteland Spirit"), false, 34);
			}
			if (INT_Enemy_Spawn_Chance > 11)
			{
				return Enemy("Bergmite", ((rand() % 6) + 10), 62, 27, { Skill("Freezan"), Skill("Gust") }, getItemFromLootTable("Bergmite"), false, 26);
			}
			else if (INT_Enemy_Spawn_Chance > 6)
			{
				return Enemy("Ice Fiend", ((rand() % 5) + 9), 45, 18, { Skill("Freeze"), Skill("Freezan") }, getItemFromLootTable("Ice Fiend"), false, 21);
			}
			else
			{
				return Enemy("Ice Monster", ((rand() % 5) + 8), 30, 24, { Skill("Freeze") }, getItemFromLootTable("Ice Monster"), false, 14);
			}
		}

		else if (DUNGEON_Current_Dungeon->getDungeonRoom() == 6)
		{
			// Enemy Level for this floor: 15		Patrol Soldier: 15
			return Enemy("Patrol Soldier", 15, 146, 27, { Skill("Flamao"), Skill("Meflamao"), Skill("Gustan"), Skill("Blighta") }, new Item("Gun Fragment", "A piece of fragment from a Soldiers gun", 3), true, 48);
		}
	}
	else if (DUNGEON_Current_Dungeon->getDungeonName() == "Atlantis Ruins")
	{
		if (DUNGEON_Current_Dungeon->getDungeonRoom() == 1)
		{
			// Enemy level for this floor: 14-20		Patrol Soldier: 14-17   Lab Fish: 16-19   Gold Fish: 20
			int INT_Enemy_Spawn_Chance = (rand() % 10) + 1;
			if (INT_Enemy_Spawn_Chance == 10)
			{
				return Enemy("Gold Fish I", 20, 150, 0, { }, getItemFromLootTable("Gold Fish"), true, 10);
			}
			else if (INT_Enemy_Spawn_Chance > 5)
			{
				return Enemy("Lab Fish", ((rand() % 3) + 16), 125, 109, { Skill("Freezan"), Skill("Zapao"), Skill("Mezapao"), Skill("Hex") }, getItemFromLootTable("Lab Fish"), false, 33);
			}
			else
			{
				return Enemy("Patrol Soldier", ((rand() % 3) + 14), 146, 27, { Skill("Flamao"), Skill("Meflamao"), Skill("Gustan"), Skill("Blighta") }, getItemFromLootTable("Patrol Soldier"), false, 48);
			}
		}
		else if (DUNGEON_Current_Dungeon->getDungeonRoom() == 2)
		{
			// Enemy level for this floor: 17-23		Patrol Soldier: 17-20   Lab Fish: 18-22   Royal Guard: 20-23   Gold Fish: 20
			int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
			if (INT_Enemy_Spawn_Chance > 18)
			{
				return Enemy("Gold Fish I", 20, 150, 0, { }, getItemFromLootTable("Gold Fish I"), true, 10);
			}
			else if (INT_Enemy_Spawn_Chance > 14)
			{
				return Enemy("Royal Guard", ((rand() % 4) + 20), 173, 69, { Skill("Flamao"), Skill("Freezan"), Skill("Hex"), Skill("Blight") }, getItemFromLootTable("Royal Guard"), false, 67);
			}
			else if (INT_Enemy_Spawn_Chance > 6)
			{
				return Enemy("Lab Fish", ((rand() % 5) + 18), 125, 109, { Skill("Freezan"), Skill("Zapao"), Skill("Mezapao"), Skill("Hex") }, getItemFromLootTable("Lab Fish"), false, 33);
			}
			else
			{
				return Enemy("Patrol Soldier", ((rand() % 4) + 17), 146, 27, { Skill("Flamao"), Skill("Meflamao"), Skill("Gustan"), Skill("Blighta") }, getItemFromLootTable("Patrol Soldier"), false, 48);
			}
		}
		else if (DUNGEON_Current_Dungeon->getDungeonRoom() == 3)
		{
			// Enemy level for this floor: 21-26		Lab Fish: 21-25   Royal Guard: 22-26   Armed Soldier: 25-27   Gold Fish: 25
			int INT_Enemy_Spawn_Chance = (rand() % 20) + 1;
			if (INT_Enemy_Spawn_Chance > 18)
			{
				return Enemy("Gold Fish II", 25, 250, 0, { }, getItemFromLootTable("Gold Fish II"), true, 10);
			}
			else if (INT_Enemy_Spawn_Chance > 14)
			{
				return Enemy("Royal Guard", ((rand() % 5) + 22), 173, 69, { Skill("Flamao"), Skill("Freezan"), Skill("Hex"), Skill("Blight") }, getItemFromLootTable("Royal Guard"), false, 67);
			}
			else if (INT_Enemy_Spawn_Chance > 6)
			{
				return Enemy("Lab Fish", ((rand() % 5) + 21), 125, 109, { Skill("Freezan"), Skill("Zapao"), Skill("Mezapao"), Skill("Hex") }, getItemFromLootTable("Lab Fish"), false, 33);
			}
			else
			{
				return Enemy("Armed Soldier", ((rand() % 3) + 25), 219, 27, { Skill("Flamao"), Skill("Flamadia"), Skill("Zapao"), Skill("Gust"), Skill("Hex") }, getItemFromLootTable("Patrol Soldier"), false, 73);
			}
		}
	}
}

Item* Dungeon::getItemFromLootTable(string STR_Enemy_Name)
{
	vector<Item*> VEC_Enemy_Drops = { };
	if (STR_Enemy_Name == "Ice Monster")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Ice Core", "A strange looking block of Ice", 1, Skill("Freeze")));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 40));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2));
	}
	else if (STR_Enemy_Name == "Ice Fiend")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 40));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Ice Shard", "A sharp ended icicle which could shatter", 2, Skill("Mefreeze")));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 35));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Crystalised Flake", "A snowflake fully crystalised, emitting a frosty aura", 3, Skill("Freezan")));
	}
	else if (STR_Enemy_Name == "Bergmite")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Dented Airhorn", "Old, red-ended airhorn which somehow still works", 1, Skill("Gust")));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 40));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Energy Pills", "Unopened tub of energy pills", 1, "STA", 15));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Worn Field Kit", "Can still be used for emergencies", 2, "HP", 100));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 35));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Cold Hairdryer", "Lethalised hairdryer from the 2040s, the air is even more colder.", 3, Skill("Gustan")));
	}
	else if (STR_Enemy_Name == "Wasteland Spirit")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Shattered Molotov", "Ash remains inside the bottle", 1, Skill("Flame")));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 40));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Energy Pills", "Unopened tub of energy pills", 1, "STA", 15));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Worn Field Kit", "Can still be used for emergencies", 2, "HP", 100));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 35));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Power Cord", "Unfrozen exposed power cable. Wonder if it still sparks?", 3, Skill("Zapao")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Medkit", "For a quick patch up", 3, "HP", 200));
	}
	else if (STR_Enemy_Name == "Patrol Soldier")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Worn Field Kit", "Can still be used for emergencies", 2, "HP", 100));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 35));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Medkit", "For a quick patch up", 3, "HP", 200));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Holy Water", "Drinking this feels godly", 3, "STA", 80));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Gun Fragment", "A piece of fragment from a Soldiers gun", 3));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Firecracker", "Who loves a little bit of Fire play", 4, Skill("Meflamao")));
	}
	else if (STR_Enemy_Name == "Lab Fish")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Seaweed", "Lonely strand of seaweed", 1));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Fish Tooth", "Caution, may be sharp", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Squid Head", "Squirts black genetically modified ink", 2, Skill("Mehex")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Holy Water", "Drinking this feels godly", 3, "STA", 80));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Jellyfish Tenticle", "Dead or Alive it still carries some current", 4, Skill("Zapadia")));;
	}
	else if (STR_Enemy_Name == "Royal Guard")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Seaweed", "Lonely strand of seaweed", 1));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Mermaid Tail", "Sadly from a dead mermaid corpse", 2));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Gold Coin", "Made of real gold!", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Holy Water", "Drinking this feels godly", 3, "STA", 80));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Old Pendant", "An old heart pendant emitting a healthy aura", 3, Skill("Heal")));
		/* 3 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Bottle o' Holy Water", "500ml of pure holy water!", 4, "STA", 150));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Dark Staff", "Some foul play is at work here...", 4, Skill("Mehexo")));;
	}
	else if (STR_Enemy_Name == "Armed Soldier")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Worn Field Kit", "Can still be used for emergencies", 2, "HP", 100));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 35));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Gold Coin", "Made of real gold!", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Medkit", "For a quick patch up", 3, "HP", 200));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Holy Water", "Drinking this feels godly", 3, "STA", 80));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements", "Drugs used to increase users power", 3, "ATK", 2.5));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills", "Drugs used to increase users concentration", 3, "MAG", 2.5));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Waterproof Flamethrower", "How this combination works is beyond comprehension", 4, Skill("Flamadia")));
	}
	else if (STR_Enemy_Name == "Gold Fish I")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Box of Matches", "Withered box of Fire matches, can they still alight?", 2, Skill("Meflame")));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Water Balloon", "May annoy some people", 2, Skill("Mesplash")));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Ice Shard", "A sharp ended icicle which could shatter", 2, Skill("Mefreeze")));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Live Cables", "A bundle of small exposed cables", 2, Skill("Mezap")));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Goat Horn", "Remains of what looks like a goat, what is it even doing here?", 2, Skill("Megust")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Diamond", "A natural chunk of diamond from the earth", 5));
	}
	else if (STR_Enemy_Name == "Gold Fish II")
	{
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Portable Mini-Cannon", "Old cannons dated back to the 1800s", 3, Skill("Flamao")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Water Blaster 9000", "Graded PSA 10, worth an absolute fortune!", 3, Skill("Splashan")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Crystalised Flake", "A snowflake fully crystalised, emitting a frosty aura", 3, Skill("Freezan")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Electrical Wire", "Exposed electric wire that still packs some spark", 3, Skill("Zapao")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Cold Hairdryer", "Lethalised hairdryer from the 2040s, the air is even more colder.", 3, Skill("Gustan")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Diamond", "A natural chunk of raw diamond from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Emerald", "A natural chunk of raw emerald from the earth", 5));
	}
	return VEC_Enemy_Drops[rand() % VEC_Enemy_Drops.size()];
}