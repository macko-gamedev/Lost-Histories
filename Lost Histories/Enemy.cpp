#include "Player.h"
#include "Enemy.h"
#include <ctime>
#include <cstdlib>

Enemy::Enemy() { }

Enemy::Enemy(string nName, int nLevel, int nHealth, int nStamina, vector<Skill> nSkills, bool nBoss, int nDamage) : BattleStat(nName, nLevel, nHealth, nStamina)
{
	this->MAP_Elements = { {"Fire", "-"}, {"Water", "-"}, {"Ice", "-"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "-"} };
	this->VEC_Skills = nSkills;
	this->ITEM_Dropped_Item = this->getItemFromLootTable();
	this->BOOL_Boss = nBoss;
	this->INT_Damage = nDamage;
	this->INT_Boss_Stat_Cycle = 2;
}

vector<Skill> Enemy::getSkills()
{
	return this->VEC_Skills;
}

Item* Enemy::getDroppedItem()
{
	return this->ITEM_Dropped_Item;
}

Item* Enemy::getItemFromLootTable()
{
	vector<Item*> VEC_Enemy_Drops = { };
	// Dungeon 1: Glacier Wasteland
	if (this->getName() == "Ice Monster")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Ice Core", "A strange looking block of Ice", 1, Skill("Freeze")));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 40));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Sharp Icicle", "Caution, fragile!", 1, (((rand() % 7) - 3) + 13), true));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2));
	}
	else if (this->getName() == "Ice Fiend")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 40));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Sharp Icicle", "Caution, fragile!", 1, (((rand() % 7) - 3) + 13), true));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Ice Shard", "A sharp ended icicle which could shatter", 2, Skill("Mefreeze")));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 35));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Crystalised Flake", "A snowflake fully crystalised, emitting a frosty aura", 3, Skill("Freezan")));
	}
	else if (this->getName() == "Bergmite")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Dented Airhorn", "Old, red-ended airhorn which somehow still works", 1, Skill("Gust")));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Thawn Bandage", "Could still be used for a scratch", 1, "HP", 40));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Energy Pills", "Unopened tub of energy pills", 1, "STA", 15));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Worn Field Kit", "Can still be used for emergencies", 2, "HP", 100));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 35));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Cold Hairdryer", "Lethalised hairdryer from the 2040s, the air is even more colder.", 3, Skill("Gustan")));
	}
	else if (this->getName() == "Wasteland Spirit")
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
	else if (this->getName() == "Patrol Soldier")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Worn Field Kit", "Can still be used for emergencies", 2, "HP", 100));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 35));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Medkit", "For a quick patch up", 3, "HP", 200));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Holy Water", "Drinking this feels godly", 3, "STA", 80));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Gun Fragment", "A piece of fragment from a Soldiers gun", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Glock-17", "Perfect for quick execution", 3, 78, true));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Firecracker", "Who loves a little bit of Fire play", 4, Skill("Meflamao")));
	}
	// Dungeon 2: Atlantis Ruins
	else if (this->getName() == "Lab Fish")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Seaweed", "Lonely strand of seaweed", 1));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Fish Tooth", "Caution, may be sharp", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Squid Head", "Squirts black genetically modified ink", 2, Skill("Mehex")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Holy Water", "Drinking this feels godly", 3, "STA", 80));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Jellyfish Tenticle", "Dead or Alive it still carries some current", 4, Skill("Zapadia")));;
	}
	else if (this->getName() == "Royal Guard")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Seaweed", "Lonely strand of seaweed", 1));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Mermaid Tail", "Sadly from a dead mermaid corpse", 2));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Gold Coin", "Made of real gold!", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Holy Water", "Drinking this feels godly", 3, "STA", 80));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Old Pendant", "An old heart pendant emitting a healthy aura", 3, Skill("Heal")));
		/* 3 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Bottle o' Holy Water", "500ml of pure holy water!", 4, "STA", 150));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Royal Trident", "Trident yielded by the Old Royal Gaurds of Atlantis", 4, 103, true));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Dark Staff", "Some foul play is at work here...", 4, Skill("Mehexo")));
	}
	else if (this->getName() == "Armed Soldier")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Worn Field Kit", "Can still be used for emergencies", 2, "HP", 100));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Bottle o' Spirit", "A strange looking bottle containing dead souls", 2, "STA", 35));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Gold Coin", "Made of real gold!", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Medkit", "For a quick patch up", 3, "HP", 200));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Holy Water", "Drinking this feels godly", 3, "STA", 80));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements", "Drugs used to increase users power", 3, "ATK", 2.5));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills", "Drugs used to increase users concentration", 3, "MAG", 2.5));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Radioactive Core", "May need a suit for this one!", 3, Skill("Frei")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Glock-17", "Perfect for quick execution", 3, (((rand() % 15) - 7) + 78), true));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Waterproof Flamethrower", "How this combination works is beyond comprehension", 4, Skill("Flamadia")));
	}
	else if (this->getName() == "Sharkman")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Shark Tooth", "Caution, may be sharp", 2));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Gold Coin", "Made of real gold!", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements", "Drugs used to increase users power", 3, "ATK", 2.5));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills", "Drugs used to increase users concentration", 3, "MAG", 2.5));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Water Blaster 9000", "Graded PSA 10, worth an absolute fortune!", 3, Skill("Splashan")));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Fire Hydrant", "Very powerful water beam!", 4, Skill("Splashadia")));
	}
	else if (this->getName() == "Reanimated Entity")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Snowball", "A cold ball of snow, perfect for throwing at people!", 1));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Seaweed", "Lonely strand of seaweed", 1));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Mermaid Tail", "Sadly from a dead mermaid corpse", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Shark Tooth", "Caution, may be sharp", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Fish Tooth", "Caution, may be sharp", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Scratched Coin", "A coin coated in scratches, the date on it says 2026", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Foreign Coin", "A coin which you don't recognise", 2));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Gold Coin", "Made of real gold!", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Gun Fragment", "A piece of fragment from a Soldiers gun", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Radioactive Core", "May need a suit for this one!", 3, Skill("Frei")));
		/* 2 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Radioactive Chunk", "A small intake of this could spell the end", 4, Skill("Freila")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Diamond", "A natural chunk of diamond from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Emerald", "A natural chunk of raw emerald from the earth", 5));
	}
	else if (this->getName() == "British Soldier")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Foreign Coin", "A coin which you don't recognise", 2));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("£10 Coin", "Since when were £10 coins a thing?", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Medkit", "For a quick patch up", 3, "HP", 200));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements", "Drugs used to increase users power moderately", 3, "ATK", 2.5));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills", "Drugs used to increase users concentration moderately", 3, "MAG", 2.5));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Glock-17", "Perfect for quick execution", 3, (((rand() % 15) - 7) + 78), true));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Breach Hammer", "Designed for house raids", 4, (((rand() % 19) - 9) + 139), true));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Overpower Capsules", "Drugs used to increase users power and concentration moderately", 4, "ATK/MAG", 2.5));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements X", "Drugs used to increase users power significantly", 4, "ATK", 4));
		/* 4 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills X", "Drugs used to increase users concentration significantly", 4, "MAG", 4));
	}
	// Dungeon 3: Facility
	else if (this->getName() == "Unknown Creature")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Test Tube", "Empty glass test tube for lab purposes", 1));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Cracked Syringe", "Used for injections", 1));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Glass Shard", "Prone to shattering immediately", 2, (((rand() % 13) - 6) + 73), true));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Chemical Pipette", "Used for transferring liquids", 3));
	}
	else if (this->getName() == "Nuclear Spirit")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Test Tube", "Empty glass test tube for lab purposes", 1));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Chemical Pipette", "Used for transferring liquids", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Radioactive Core", "May need a suit for this one!", 3, Skill("Frei")));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Radioactive Chunk", "A small intake of this could spell the end", 4, Skill("Freila")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Reactor Heart", "Those who are in it's presence are said to die within minutes", 5, Skill("Freiladia")));
	}
	else if (this->getName() == "Corrupt Researcher")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Test Tube", "Empty glass test tube for lab purposes", 1));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Cracked Syringe", "Used for injections", 1));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Glass Shard", "Prone to shattering immediately", 2, (((rand() % 13) - 6) + 73), true));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("Chemical Pipette", "Used for transferring liquids", 3));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Potion of Instant Health", "Red liquid fills the blocky bottle", 4, "HP", 350));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Potion of Mutated Souls", "Screaming can be heard inside the bottle", 4, "STA", 150));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Acid Injected Sword", "One slice is enough to poison the heart", 4, (((rand() % 19) - 9) + 165), true));
	}
	else if (this->getName() == "German Soldier")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Foreign Coin", "A coin which you don't recognise", 2));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("10 Euro Coin", "Since when were ten euro coins a thing?", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Medkit", "For a quick patch up", 3, "HP", 200));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements", "Drugs used to increase users power moderately", 3, "ATK", 2.5));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills", "Drugs used to increase users concentration moderately", 3, "MAG", 2.5));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemMelee("AK-47", "Brr brr brrrrrrrrr!", 3, (((rand() % 21) - 10) + 120), true));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Breach Hammer", "Designed for house raids", 4, (((rand() % 19) - 9) + 139), true));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Overpower Capsules", "Drugs used to increase users power and concentration moderately", 4, "ATK/MAG", 2.5));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements X", "Drugs used to increase users power significantly", 4, "ATK", 4));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills X", "Drugs used to increase users concentration significantly", 4, "MAG", 4));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Frosted Railgun", "Has incredible piercing capabilities", 5, Skill("Mefreezadia")));
	}
	else if (this->getName() == "French Soldier")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Foreign Coin", "A coin which you don't recognise", 2));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("10 Euro Coin", "Since when were ten euro coins a thing?", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemMelee("AK-47", "Brr brr brrrrrrrrr!", 3, (((rand() % 21) - 10) + 120), true));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Breach Hammer", "Designed for house raids", 4, (((rand() % 19) - 9) + 139), true));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Overpower Capsules", "Drugs used to increase users power and concentration moderately", 4, "ATK/MAG", 2.5));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements X", "Drugs used to increase users power significantly", 4, "ATK", 4));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills X", "Drugs used to increase users concentration significantly", 4, "MAG", 4));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemMelee("M6 Gerand", "One bullet is all it takes to end a life", 5, (((rand() % 29) - 14) + 194), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Explosive TNT", "Set it off to set enemies ablaze!", 5, Skill("Meflamadia")));
	}
	else if (this->getName() == "American Soldier")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Foreign Coin", "A coin which you don't recognise", 2));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("10 Dollar Coin", "Since when were ten dollar coins a thing?", 3));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemMelee("AK-47", "Brr brr brrrrrrrrr!", 3, (((rand() % 21) - 10) + 120), true));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Overpower Capsules", "Drugs used to increase users power and concentration moderately", 4, "ATK/MAG", 2.5));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements X", "Drugs used to increase users power significantly", 4, "ATK", 4));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills X", "Drugs used to increase users concentration significantly", 4, "MAG", 4));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemMelee("M6 Gerand", "One bullet is all it takes to end a life", 5, (((rand() % 29) - 14) + 194), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Kraber 50-Caliber", "This could be used in a FaZe montages, if... they're still a thing...", 5, ((rand() % 21) + 210), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("F5 Twister in a Barrel", "Wreck havoc!!!", 5, Skill("Eye of the Storm")));
	}
	
	// Dungeon 4: Magma Fields
	else if (this->getName() == "Lava Spirit")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Magma Rock", "Hot piece of magma rock", 1));
		/* 1 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Lava Spirit Plush", "A plush toy of the Lava Spirit", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Sword of Fire Aspect", "A purple tinted sword which ignites it's opponent in flames", 2, (((rand() % 21) - 10) + 132), true));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Volcanic Blade", "Sharp blade created by civilians who lived near the volcanoes", 3, (((rand() % 29) - 14) + 184), true));
	}
	else if (this->getName() == "Japanese Soldier")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Foreign Coin", "A coin which you don't recognise", 2));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new Item("10 Yen Coin", "Since when were ten yen coins a thing?", 3));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Golden Tachi", "A deeply curved sword used by the Samurai before the 15th Century, coated in gold", 4, (((rand() % 37) - 18) + 233), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Body Morphing Drugs", "Drugs used to increase users power and concentration significantly", 5, "ATK/MAG", 4));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements 50mg", "Drugs used to increase users power massively", 5, "ATK", 7));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills 50mg", "Drugs used to increase users concentration massively", 5, "MAG", 7));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Batra's Staff of Reckoning", "Let's turn the tide!", 5, Skill("Eye of the Ocean")));
	}
	else if (this->getName() == "Fire Prowler")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new Item("Magma Rock", "Hot piece of magma rock", 1));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Bag of Ash", "Leather bag filled with dried, coolen ash", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new Item("Cube of Basalt", "A piece of the earth's crust in cube form", 2));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Sword of Fire Aspect", "A purple tinted sword which ignites it's opponent in flames", 2, (((rand() % 21) - 10) + 132), true));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Volcanic Blade", "Sharp blade created by civilians who lived near the volcanoes", 3, (((rand() % 29) - 14) + 184), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Magma Forged Sword", "A sword forged from molten magma, gloves need to be worn", 5, (((rand() % 45) - 22) + 286), true));
	}
	else if (this->getName() == "Master's Servant")
	{
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Poison Tipped Knife", "A knife coated in poison dripping, perfect for eliminating targets, quietly...", 4, (((rand() % 45) - 22) + 241), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Body Morphing Drugs", "Drugs used to increase users power and concentration significantly", 5, "ATK/MAG", 4));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Power Supplements 50mg", "Drugs used to increase users power massively", 5, "ATK", 7));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Concentration Pills 50mg", "Drugs used to increase users concentration massively", 5, "MAG", 7));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Diamond", "A natural chunk of raw diamond from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Emerald", "A natural chunk of raw emerald from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Ruby", "A natural chunk of raw ruby from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Obsidian", "A natural chunk of raw obsidian from the earth", 5));
	}
	
	// Rare Enemies
	else if (this->getName() == "Gold Entity I")
	{
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Shattered Molotov", "Ash remains inside the bottle", 1, Skill("Flame")));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Bubble Blower", "POP!", 1, Skill("Splash")));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Ice Core", "A strange looking block of Ice", 1, Skill("Freeze")));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Live Wire", "Still sparking at the tip", 1, Skill("Zap")));
		/* 1 STAR */ for (int i = 0; i < 5; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Dented Airhorn", "Old, red-ended airhorn which somehow still works", 1, Skill("Gust")));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new Item("Chipped Diamond", "Exposed diamond which appears chipped and frozen over, might still carry some value", 4));
		}
	else if (this->getName() == "Gold Entity II")
	{
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Box of Matches", "Withered box of Fire matches, can they still alight?", 2, Skill("Meflame")));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Water Balloon", "May annoy some people", 2, Skill("Mesplash")));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Ice Shard", "A sharp ended icicle which could shatter", 2, Skill("Mefreeze")));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Live Cables", "A bundle of small exposed cables", 2, Skill("Mezap")));
		/* 2 STAR */ for (int i = 0; i < 4; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Goat Horn", "Remains of what looks like a goat, what is it even doing here?", 2, Skill("Megust")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Diamond", "A natural chunk of diamond from the earth", 5));
	}
	else if (this->getName() == "Gold Entity III")
	{
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Portable Mini-Cannon", "Old cannons dated back to the 1800s", 3, Skill("Flamao")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Water Blaster 9000", "Graded PSA 10, worth an absolute fortune!", 3, Skill("Splashan")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Crystalised Flake", "A snowflake fully crystalised, emitting a frosty aura", 3, Skill("Freezan")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Electrical Wire", "Exposed electric wire that still packs some spark", 3, Skill("Zapao")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Cold Hairdryer", "Lethalised hairdryer from the 2040s, the air is even more colder.", 3, Skill("Gustan")));
		/* 3 STAR */ for (int i = 0; i < 3; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Radioactive Core", "May need a suit for this one!", 3, Skill("Frei")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Diamond", "A natural chunk of raw diamond from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Emerald", "A natural chunk of raw emerald from the earth", 5));
	}
	else if (this->getName() == "Gold Entity IV")
	{
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Waterproof Flamethrower", "How this combination works is beyond comprehension", 4, Skill("Flamadia")));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Fire Hydrant", "Very powerful water beam!", 4, Skill("Splashadia")));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Bag of Powdered Snow", "The coldness even hurts just grabbing it out of the bag", 4, Skill("Freezadia")));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Jellyfish Tenticle", "Dead or Alive it still carries some current", 4, Skill("Zapadia")));;
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Suction Device", "No one stands a chance once hit with the extreme wind force", 4, Skill("Gustadia")));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Radioactive Chunk", "A small intake of this could spell the end", 4, Skill("Freila")));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Acid Injected Sword", "One slice is enough to poison the heart", 4, (((rand() % 19) - 9) + 165), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Diamond", "A natural chunk of raw diamond from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Emerald", "A natural chunk of raw emerald from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Ruby", "A natural chunk of raw ruby from the earth", 5));
	}
	else if (this->getName() == "Gold Entity V")
	{
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Orb of Dark Matter", "A mysterious black orb emitting an overwhelming curseful aura", 4, Skill("Hexaon")));
		/* 4 STAR */ for (int i = 0; i < 2; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Book of God - 2049 Edition", "A book dedicated to god, created and published in 2049, emits an overwhelming blessful aura", 4, Skill("Blightaon")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Explosive TNT", "Set it off to set enemies ablaze!", 5, Skill("Meflamadia")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("World's Biggest Hose", "Says it in the name, does this facility really make these?", 5, Skill("Mesplashadia")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Frosted Railgun", "Has incredible piercing capabilities", 5, Skill("Mefreezadia")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Broken Powerline", "A segment from a powerline, still charged", 5, Skill("Mezapadia")));;
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Portable Black Hole", "'Sending out my singularity!'", 5, Skill("Megustadia")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Reactor Heart", "Those who are in it's presence are said to die within minutes", 5, Skill("Freiladia")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Prototype Heat Rod", "Flame spouted rod, can burn through anything!", 5, (((rand() % 25) - 12) + 214), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Diamond", "A natural chunk of raw diamond from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Emerald", "A natural chunk of raw emerald from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Ruby", "A natural chunk of raw ruby from the earth", 5));
	}
	else if (this->getName() == "Gold Entity VI")
	{
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Fitzroy Motherload", "'Motherlode's droppin'. Hold onto ya hats'", 5, Skill("Eye of the Sun")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Paquette Pylon", "'Fuses set and capacitors charged'", 5, Skill("Eye of the Spark")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("F5 Twister in a Barrel", "Wreck havoc!!!", 5, Skill("Eye of the Storm")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Red Button", "A scratched engraving reads 'KJU'", 5, Skill("End of the World")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Prototype Heat Rod", "Flame spouted rod, can burn through anything!", 5, (((rand() % 25) - 12) + 214), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Diamond", "A natural chunk of raw diamond from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Emerald", "A natural chunk of raw emerald from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Ruby", "A natural chunk of raw ruby from the earth", 5));
	}
	else if (this->getName() == "Gold Entity VII")
	{
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Fitzroy Motherload", "'Motherlode's droppin'. Hold onto ya hats'", 5, Skill("Eye of the Sun")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Batra's Staff of Reckoning", "Let's turn the tide!", 5, Skill("Eye of the Ocean")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Paquette Pylon", "'Fuses set and capacitors charged'", 5, Skill("Eye of the Spark")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("F5 Twister in a Barrel", "Wreck havoc!!!", 5, Skill("Eye of the Storm")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemSkill("Red Button", "A scratched engraving reads 'KJU'", 5, Skill("End of the World")));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemMelee("Magma Forged Sword", "A sword forged from molten magma, gloves need to be worn", 5, (((rand() % 45) - 22) + 286), true));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new ItemConsumable("Body Morphing Drugs", "Drugs used to increase users power and concentration significantly", 5, "ATK/MAG", 4));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Diamond", "A natural chunk of raw diamond from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Emerald", "A natural chunk of raw emerald from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Ruby", "A natural chunk of raw ruby from the earth", 5));
		/* 5 STAR */ for (int i = 0; i < 1; i++) VEC_Enemy_Drops.push_back(new Item("Obsidian", "A natural chunk of raw obsidian from the earth", 5));
		}
	else if (this->getName() == "Gold Entity VIII")
	{
		VEC_Enemy_Drops = { new Item("Rainbow Crystal", "A sparkling rainbow crystal from the special realm!", 5) };
		}
	else if (this->getName() == "Gold Entity IX")
	{
		VEC_Enemy_Drops = { new Item("Rainbow Crystal", "A sparkling rainbow crystal from the special realm!", 5) };
		}
	else if (this->getName() == "Gold Entity X")
	{
		VEC_Enemy_Drops = { new Item("Rainbow Crystal", "A sparkling rainbow crystal from the special realm!", 5) };
		}

	// Dungeon Mini Bosses
	else if (this->getName() == "Snow Golem")
	{
		VEC_Enemy_Drops = { new Item("Glacier F3 Key", "Frozen key lost in time, maybe can be used for something?", 3) };
	}
	else if (this->getName() == "Duty Soldier")
	{
		VEC_Enemy_Drops = { new Item("Glacier F5 Key", "Frozen key lost in time, maybe can be used for something?", 3) };
	}
	else if (this->getName() == "Reanimated Mermaid")
	{
		VEC_Enemy_Drops = { new Item("Atlantis F2 Key", "Rusted key from Atlantis, maybe can be used for something?", 3) };
	}
	else if (this->getName() == "Reanimated Jellyfisherman")
	{
		VEC_Enemy_Drops = { new Item("Atlantis F4 Key", "Rusted key from Atlantis, maybe can be used for something?", 3) };
		}
	else if (this->getName() == "Radioactive Atlantis Survivor")
	{
		VEC_Enemy_Drops = { new Item("Atlantis F5 Key A", "Rusted key from Atlantis, maybe can be used for something?", 3) };
		}
	else if (this->getName() == "Radioactive Atlantis Guard")
	{
		VEC_Enemy_Drops = { new Item("Atlantis F5 Key B", "Rusted key from Atlantis, maybe can be used for something?", 3) };
	}
	else if (this->getName() == "Mutated Lab Researcher")
	{
		VEC_Enemy_Drops = { new Item("Facility F3 Keycard", "Shiny keycard from Facility, maybe can be used for something?", 3) };
		}
	else if (this->getName() == "Mutated Security Sector 4B")
	{
		VEC_Enemy_Drops = { new Item("Facility F5 Keycard A", "Shiny keycard from Facility, maybe can be used for something?", 3) };
		}
	else if (this->getName() == "Mutated Security Sector 16A")
	{
		VEC_Enemy_Drops = { new Item("Facility F5 Keycard B", "Shiny keycard from Facility, maybe can be used for something?", 3) };
		}
	else if (this->getName() == "Mutated Security Sector 46D")
	{
		VEC_Enemy_Drops = { new Item("Facility F6 Keycard", "Shiny keycard from Facility, maybe can be used for something?", 3) };
	}
	else if (this->getName() == "Ghost of Katie Cooper")
	{
		VEC_Enemy_Drops = { new Item("Special F2 Unlocker", "An unlocker device from a special realm, maybe can be used for something?", 3) };
	}
	else if (this->getName() == "Rice Monster of Tooley")
	{
		VEC_Enemy_Drops = { new Item("Special F3 Unlocker", "An unlocker device from a special realm, maybe can be used for something?", 3) };
	}
	else if (this->getName() == "Mucus Poocus")
	{
		VEC_Enemy_Drops = { new Item("Special F4 Unlocker", "An unlocker device from a special realm, maybe can be used for something?", 3) };
		}
	else if (this->getName() == "Performative Boxer")
	{
		VEC_Enemy_Drops = { new Item("Special F5 Unlocker", "An unlocker device from a special realm, maybe can be used for something?", 3) };
		}

	// Dungeon Bosses
	else if (this->getName() == "Russian Sergeant")
	{
		VEC_Enemy_Drops = { new ItemSkill("Battery Reserve", "Incase of power cut emergencies", 4, Skill("Mezapao")) };
	}
	else if (this->getName() == "Reawoken Guardian of Atlantis")
	{
		VEC_Enemy_Drops = { new Item("Mysterious Machine Part", "It seems like some sort of part from a machine, maybe this could play a vital part in saving the world?", 4) };
	}
	else if (this->getName() == "Master of the Facility")
	{
		VEC_Enemy_Drops = { new Item("Frozen Crystal of Bitter Cold", "This is the core component of a machine, its purpose is to restore the balance between hot and cold on the planet", 5) };
	}
	else if (this->getName() == "Reincarnation of George Shaw")
	{
		VEC_Enemy_Drops = { new ItemMelee("Blunt Kunai", "A replica of George Shaw's favourite video game character's melee skin from 2026", 5, 224, true) };
	}
	else if (this->getName() == "The Mastermind")
	{
		VEC_Enemy_Drops = { new Item("Device Compass", "A small metallic compass pointing directly towards The Device, you're almost there!", 5) };
		}
	else if (this->getName() == "Mutated Mastermind")
	{
		VEC_Enemy_Drops = { new ItemSkill("Gem of Mass Destruction", "Suprisingly, it has an in-built mp3 player playing tunes from Lotus Juice himself", 5, Skill("End of the World")) };
	}
	else if (this->getName() == "Keeper of The Device")
	{
		VEC_Enemy_Drops = { new Item("Trophy of Lost Histories", "You have completed this game! Congratulations!", 5) };
	}
	else if (this->getName() == "Tyson Mondeo")
	{
		VEC_Enemy_Drops = { new Item("Golden Super Macko Plush", "A golden plushie of the Super Macko tower from ENobia!", 5) };
		}

	return VEC_Enemy_Drops[rand() % VEC_Enemy_Drops.size()];
}

bool Enemy::isAlive()
{
	return this->BOOL_Alive;
}

bool Enemy::isBoss()
{
	return this->BOOL_Boss;
}

int Enemy::getDamage()
{
	return this->INT_Damage;
}

void Enemy::setHealth()
{
	this->INT_Health = int(float(this->INT_Health) * ((float(INT_Level) / 10) + 1));
	this->INT_Max_Health = this->INT_Health;
}

string Enemy::getTurnPhrase()
{
	return this->STR_Turn_Phrase;
}

void Enemy::elementSetter()
{
	// Normal Enemies
	if (this->getName() == "Ice Monster")
	{
		this->setElements({ {"Fire", "Wk"}, {"Water", "-"}, {"Ice", "Rst"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (this->getName() == "Ice Fiend")
	{
		this->setElements({ {"Fire", "Rst"}, {"Water", "-"}, {"Ice", "Rst"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (this->getName() == "Bergmite")
	{
		this->setElements({ {"Fire", "Wk"}, {"Water", "-"}, {"Ice", "-"}, {"Electric", "-"}, {"Wind", "Rst"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (this->getName() == "Wasteland Spirit")
	{
		this->setElements({ {"Fire", "Wk"}, {"Water", "Wk"}, {"Ice", "Rst"}, {"Electric", "Rst"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "Wk"} });
	}
	else if (this->getName() == "Patrol Soldier")
	{
		this->setElements({ {"Fire", "-"}, {"Water", "-"}, {"Ice", "Rst"}, {"Electric", "Wk"}, {"Wind", "Rst"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (this->getName() == "Lab Fish")
	{
		this->setElements({ {"Fire", "-"}, {"Water", "Rst"}, {"Ice", "-"}, {"Electric", "Rst"}, {"Wind", "-"}, {"Curse", "Rst"}, {"Bless", "Wk"} });
	}
	else if (this->getName() == "Royal Guard")
	{
		this->setElements({ {"Fire", "Wk"}, {"Water", "Rpl"}, {"Ice", "Rst"}, {"Electric", "Rst"}, {"Wind", "-"}, {"Curse", "Nul"}, {"Bless", "Wk"} });
	}
	else if (this->getName() == "Armed Soldier")
	{
		this->setElements({ {"Fire", "Rst"}, {"Water", "Rst"}, {"Ice", "Wk"}, {"Electric", "Rpl"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (this->getName() == "Sharkman")
	{
		this->setElements({ {"Fire", "Wk"}, {"Water", "Abs"}, {"Ice", "Wk"}, {"Electric", "-"}, {"Wind", "Rst"}, {"Curse", "-"}, {"Bless", "Rst"} });
	}
	else if (this->getName() == "Reanimated Entity")
	{
		this->setElements({ {"Fire", "-"}, {"Water", "Nul"}, {"Ice", "Rst"}, {"Electric", "-"}, {"Wind", "Wk"}, {"Curse", "Rst"}, {"Bless", "-"} });
	}
	else if (this->getName() == "British Soldier")
	{
		this->setElements({ {"Fire", "-"}, {"Water", "Rst"}, {"Ice", "Wk"}, {"Electric", "Rpl"}, {"Wind", "Nul"}, {"Curse", "Wk"}, {"Bless", "Abs"} });
	}
	else if (this->getName() == "Unknown Creature")
	{
		this->setElements({ {"Fire", "Wk"}, {"Water", "Wk"}, {"Ice", "Nul"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "Rst"}, {"Bless", "Rst"} });
	}
	else if (this->getName() == "Nuclear Spirit")
	{
		this->setElements({ {"Fire", "Abs"}, {"Water", "Wk"}, {"Ice", "Rst"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "Nul"}, {"Bless", "-"} });
	}
	else if (this->getName() == "Corrupt Researcher")
	{
		this->setElements({ {"Fire", "Abs"}, {"Water", "-"}, {"Ice", "-"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "Wk"}, {"Bless", "Abs"} });
	}
	else if (this->getName() == "German Soldier")
	{
		this->setElements({ {"Fire", "Rst"}, {"Water", "Wk"}, {"Ice", "Wk"}, {"Electric", "Rpl"}, {"Wind", "Rst"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (this->getName() == "French Soldier")
	{
		this->setElements({ {"Fire", "Wk"}, {"Water", "Rst"}, {"Ice", "Rst"}, {"Electric", "Wk"}, {"Wind", "Rpl"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (this->getName() == "American Soldier")
	{
		this->setElements({ {"Fire", "-"}, {"Water", "-"}, {"Ice", "Abs"}, {"Electric", "Nul"}, {"Wind", "Wk"}, {"Curse", "Rst"}, {"Bless", "Rst"} });
	}
	else if (this->getName() == "Lava Spirit")
	{
		this->setElements({ {"Fire", "Abs"}, {"Water", "Wk"}, {"Ice", "Rpl"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (this->getName() == "Japanese Soldier")
	{
		this->setElements({ {"Fire", "-"}, {"Water", "Abs"}, {"Ice", "-"}, {"Electric", "Wk"}, {"Wind", "Rpl"}, {"Curse", "Wk"}, {"Bless", "Abs"} });
	}
	else if (this->getName() == "Fire Prowler")
	{
		this->setElements({ {"Fire", "Abs"}, {"Water", "Wk"}, {"Ice", "-"}, {"Electric", "Rpl"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (this->getName() == "Master's Servant")
	{
		this->setElements({ {"Fire", "Rpl"}, {"Water", "-"}, {"Ice", "Wk"}, {"Electric", "Nul"}, {"Wind", "Nul"}, {"Curse", "Abs"}, {"Bless", "Wk"} });
	}
	
	// Mini Bosses
	else if (this->getName() == "Snow Golem")
	{
		this->setElements({ {"Fire", "Wk"}, {"Water", "-"}, {"Ice", "Abs"}, {"Electric", "-"}, {"Wind", "Rst"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (this->getName() == "Duty Soldier")
	{
		this->setElements({ {"Fire", "-"}, {"Water", "-"}, {"Ice", "Rst"}, {"Electric", "Wk"}, {"Wind", "Rst"}, {"Curse", "-"}, {"Bless", "-"} });
	}
	else if (this->getName() == "Reanimated Mermaid")
	{
		this->setElements({ {"Fire", "Nul"}, {"Water", "Abs"}, {"Ice", "Wk"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "Rst"}, {"Bless", "-"} });
	}
	else if (this->getName() == "Reanimated Jellyfisherman")
	{
		this->setElements({ {"Fire", "-"}, {"Water", "Abs"}, {"Ice", "-"}, {"Electric", "Abs"}, {"Wind", "-"}, {"Curse", "Rst"}, {"Bless", "Rst"} });
	}
	else if (this->getName() == "Radioactive Atlantis Survivor")
	{
		this->setElements({ {"Fire", "Wk"}, {"Water", "Rpl"}, {"Ice", "Wk"}, {"Electric", "Wk"}, {"Wind", "Rst"}, {"Curse", "Rpl"}, {"Bless", "Rpl"} });
	}
	else if (this->getName() == "Radioactive Atlantis Guard")
	{
		this->setElements({ {"Fire", "Rst"}, {"Water", "Rpl"}, {"Ice", "Wk"}, {"Electric", "-"}, {"Wind", "Rst"}, {"Curse", "Rpl"}, {"Bless", "Rpl"} });
	}
	else if (this->getName() == "Mutated Lab Researcher")
	{
		this->setElements({ {"Fire", "Abs"}, {"Water", "Wk"}, {"Ice", "-"}, {"Electric", "Wk"}, {"Wind", "Nul"}, {"Curse", "Abs"}, {"Bless", "Wk"} });
		}
	else if (this->getName() == "Mutated Security Sector 4B")
	{
		this->setElements({ {"Fire", "Wk"}, {"Water", "Rst"}, {"Ice", "-"}, {"Electric", "Rpl"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "Rpl"} });
		}
	else if (this->getName() == "Mutated Security Sector 16A")
	{
		this->setElements({ {"Fire", "Rst"}, {"Water", "Wk"}, {"Ice", "-"}, {"Electric", "-"}, {"Wind", "Rpl"}, {"Curse", "Rpl"}, {"Bless", "-"} });
		}
	else if (this->getName() == "Mutated Security Sector 46D")
	{
		this->setElements({ {"Fire", "Nul"}, {"Water", "-"}, {"Ice", "Rst"}, {"Electric", "Wk"}, {"Wind", "Rst"}, {"Curse", "-"}, {"Bless", "-"} });
		}
	else if (this->getName() == "Ghost of Katie Cooper")
	{
		this->setElements({ {"Fire", "Rpl"}, {"Water", "-"}, {"Ice", "Rpl"}, {"Electric", "-"}, {"Wind", "Rpl"}, {"Curse", "Wk"}, {"Bless", "Rpl"} });
		}
	else if (this->getName() == "Rice Monster of Tooley")
	{
		this->setElements({ {"Fire", "Rpl"}, {"Water", "-"}, {"Ice", "Wk"}, {"Electric", "Nul"}, {"Wind", "Nul"}, {"Curse", "-"}, {"Bless", "Wk"} });
		}
	else if (this->getName() == "Mucus Poocus")
	{
		this->setElements({ {"Fire", "Wk"}, {"Water", "Nul"}, {"Ice", "Rpl"}, {"Electric", "Rst"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "-"} });
		}
	else if (this->getName() == "Performative Boxer")
	{
		this->setElements({ {"Fire", "Rst"}, {"Water", "Rst"}, {"Ice", "Rst"}, {"Electric", "Rst"}, {"Wind", "Rst"}, {"Curse", "Rst"}, {"Bless", "Wk"} });
		}

	// Dungeon Bosses
	else if (this->getName() == "Russian Sergeant")
	{
		this->setElements({ {"Fire", "Rst"}, {"Water", "-"}, {"Ice", "Rpl"}, {"Electric", "Wk"}, {"Wind", "Rst"}, {"Curse", "Wk"}, {"Bless", "Wk"} });
	}
	else if (this->getName() == "Reawoken Guardian of Atlantis")
	{
		this->setElements({ {"Fire", "Rst"}, {"Water", "Abs"}, {"Ice", "Rst"}, {"Electric", "Wk"}, {"Wind", "Rpl"}, {"Curse", "Wk"}, {"Bless", "Wk"} });
	}
	else if (this->getName() == "Master of the Facility")
	{
		this->setElements({ {"Fire", "Abs"}, {"Water", "Abs"}, {"Ice", "Wk"}, {"Electric", "Wk"}, {"Wind", "Nul"}, {"Curse", "Rpl"}, {"Bless", "Rpl"} });
		}
	else if (this->getName() == "Reincarnation of George Shaw")
	{
		this->setElements({ {"Fire", "Nul"}, {"Water", "Wk"}, {"Ice", "-"}, {"Electric", "Abs"}, {"Wind", "Nul"}, {"Curse", "Wk"}, {"Bless", "-"} });
		}
	else if (this->getName() == "The Mastermind")
	{
		// Gimmick: Every 2 turns, it's element coverage changes randomly, first 2 turns starts with repellent to everything
		this->setElements({ {"Fire", "Rpl"}, {"Water", "Rpl"}, {"Ice", "Rpl"}, {"Electric", "Rpl"}, {"Wind", "Rpl"}, {"Curse", "Rpl"}, {"Bless", "Rpl"} });
	}
	else if (this->getName() == "Mutated Mastermind")
	{
		// Gimmick: Every 2 turns, it's element coverage changes randomly, first 2 turns starts with repellent to everything
		this->setElements({ {"Fire", "Rpl"}, {"Water", "Rpl"}, {"Ice", "Rpl"}, {"Electric", "Rpl"}, {"Wind", "Rpl"}, {"Curse", "Rpl"}, {"Bless", "Rpl"} });
	}
	else if (this->getName() == "Keeper of The Device")
	{
		// Gimmick: Every 2 turns, it's element coverage changes randomly, first 2 turns starts with repellent to everything
		this->setElements({ {"Fire", "Rpl"}, {"Water", "Rpl"}, {"Ice", "Rpl"}, {"Electric", "Rpl"}, {"Wind", "Rpl"}, {"Curse", "Rpl"}, {"Bless", "Rpl"} });
	}
	else if (this->getName() == "Tyson Mondeo")
	{
		this->setElements({ {"Fire", "Wk"}, {"Water", "Nul"}, {"Ice", "Wk"}, {"Electric", "N ul"}, {"Wind", "Rpl"}, {"Curse", "-"}, {"Bless", "-"} });
		}

	// Rare Enemies
	else if (this->getName() == "Gold Entity I")
	{
		this->setElements({ {"Fire", "Wk"}, {"Water", "Wk"}, {"Ice", "Wk"}, {"Electric", "Wk"}, {"Wind", "Wk"}, {"Curse", "Wk"}, {"Bless", "Wk"} });
	}
	else if (this->getName() == "Gold Entity II")
	{
		this->setElements({ {"Fire", "Rst"}, {"Water", "Rst"}, {"Ice", "Rst"}, {"Electric", "Rst"}, {"Wind", "Rst"}, {"Curse", "Rst"}, {"Bless", "Rst"} });
	}
	else if (this->getName() == "Gold Entity III")
	{
		this->setElements({ {"Fire", "Nul"}, {"Water", "Abs"}, {"Ice", "Nul"}, {"Electric", "Abs"}, {"Wind", "Nul"}, {"Curse", "Abs"}, {"Bless", "Nul"} });
	}
	else if (this->getName() == "Gold Entity IV")
	{
		this->setElements({ {"Fire", "Nul"}, {"Water", "Nul"}, {"Ice", "Nul"}, {"Electric", "Nul"}, {"Wind", "Nul"}, {"Curse", "Nul"}, {"Bless", "Nul"} });
		}
	else if (this->getName() == "Gold Entity V")
	{
		this->setElements({ {"Fire", "Rpl"}, {"Water", "Rpl"}, {"Ice", "Rpl"}, {"Electric", "Rpl"}, {"Wind", "Rpl"}, {"Curse", "Rpl"}, {"Bless", "Rpl"} });
		}
	else if (this->getName() == "Gold Entity VI")
	{
		this->setElements({ {"Fire", "Wk"}, {"Water", "Wk"}, {"Ice", "Wk"}, {"Electric", "Wk"}, {"Wind", "Wk"}, {"Curse", "Wk"}, {"Bless", "Wk"} });
		}
	else if (this->getName() == "Gold Entity VII")
	{
		this->setElements({ {"Fire", "Rpl"}, {"Water", "Abs"}, {"Ice", "Rpl"}, {"Electric", "Abs"}, {"Wind", "Rpl"}, {"Curse", "Abs"}, {"Bless", "Rpl"} });
		}
	else if (this->getName() == "Gold Entity VIII")
	{
		this->setElements({ {"Fire", "Rpl"}, {"Water", "Rpl"}, {"Ice", "Rpl"}, {"Electric", "Rpl"}, {"Wind", "Rpl"}, {"Curse", "Rpl"}, {"Bless", "Rpl"} });
		}
	else if (this->getName() == "Gold Entity IX")
	{
		this->setElements({ {"Fire", "Abs"}, {"Water", "Abs"}, {"Ice", "Abs"}, {"Electric", "Abs"}, {"Wind", "Abs"}, {"Curse", "Abs"}, {"Bless", "Abs"} });
		}
	else if (this->getName() == "Gold Entity X")
	{
		this->setElements({ {"Fire", "Rst"}, {"Water", "Rst"}, {"Ice", "Rst"}, {"Electric", "Rst"}, {"Wind", "Rst"}, {"Curse", "Rst"}, {"Bless", "Rst"} });
		}
}

void Enemy::update(Player& PLAYER_Player)
{
	srand(time(0));
	vector<string> VEC_Waiting_Phases = { (this->STR_Name + " is waiting..."), (this->STR_Name + " is staring at you intensly..."),  (this->STR_Name + " is planning their next move...") };
	
	if (this->isBoss() == false)
	{
		this->ENUM_State = battleState::ATTACKING;
	}
	
	if (this->ENUM_State == battleState::WAITING)
	{
		if (this->getName() == "The Mastermind" || this->getName() == "Mutated Mastermind" || this->getName() == "Keeper of The Device")
		{
			this->INT_Boss_Stat_Cycle++;
			if (this->INT_Boss_Stat_Cycle == 4)
			{
				this->INT_Boss_Stat_Cycle = 0;
				vector<string> VEC_Ailments = { "-", "Wk", "Rst", "Rpl", "Abs", "Nul" };
				vector<Skill> VEC_Skills_Available = { Skill("Flamadia"), Skill("Meflamadia"), Skill("Eye of the Sun"), Skill("Freezadia"), Skill("Mefreezadia"), Skill("Eye of the 'Berg"), Skill("Splashadia"), Skill("Mesplashadia"), Skill("Eye of the Ocean"), Skill("Zapadia"), Skill("Mezapadia"), Skill("Eye of the Spark"), Skill("Gustadia"), Skill("Megustadia"), Skill("Eye of the Storm"), Skill("Hexaon"), Skill("Mehexaon"), Skill("Blightaon"), Skill("Meblightaon"), Skill("Freila"), Skill("Freiladia"), Skill("Healan") };

				this->VEC_Skills = { };
				for (int i = 0; i < 8; i++)
				{
					VEC_Skills.push_back(VEC_Skills_Available[rand() % VEC_Skills_Available.size()]);
				}
				this->setElements({ {"Fire", VEC_Ailments[rand() % 6]},{"Water", VEC_Ailments[rand() % 6]},{"Ice", VEC_Ailments[rand() % 6]},{"Electric", VEC_Ailments[rand() % 6]},{"Wind", VEC_Ailments[rand() % 6]},{"Curse", VEC_Ailments[rand() % 6]}, { "Bless", VEC_Ailments[rand() % 6] } });
				this->STR_Turn_Phrase = "\n   " + this->getName() + " is shifting their elemental coverage and magic attacks!";
			}
			else
			{
				this->STR_Turn_Phrase = "\n   " + VEC_Waiting_Phases[rand() % 3];
			}
		}
		else
		{
			this->STR_Turn_Phrase = "\n   " + VEC_Waiting_Phases[rand() % 3];
		}
		this->ENUM_State = battleState::ATTACKING;
	}
	else if (this->ENUM_State == battleState::ATTACKING)
	{
		int INT_Miss_Chance = (rand() & 100) + 1;
		if (INT_Miss_Chance > 14) // 15% chance to miss their attack
		{
			if (!this->VEC_Skills.empty())
			{
				Skill SKILL_Skill_Selected;
				SKILL_Skill_Selected = this->VEC_Skills[(rand() % this->VEC_Skills.size())];
				int INT_Calculated_Damage;
				float FLT_Attribute_Multiplier = 1 - (float(PLAYER_Player.getPlayerAttributes().find("Endurance")->second) / 200);
				float FLT_Guard_Multiplier;
				if (PLAYER_Player.isGuard())
				{
					FLT_Guard_Multiplier = 0.67;
				}
				else
				{
					FLT_Guard_Multiplier = 1;
				}

				if (PLAYER_Player.getMeleeWeapon().hasModifiedAttribute())
				{
					if (PLAYER_Player.getMeleeWeapon().getAttributeType() == "Endurance")
					{
						FLT_Attribute_Multiplier *= 1 - (PLAYER_Player.getMeleeWeapon().getBonusValue() - 1);
					}
				}
				int INT_Skill_Chance = (rand() % 10) + 1;
				int INT_Boss_Multiplier = 1;
				if (this->getName() == "The Mastermind")
				{
					INT_Boss_Multiplier = 1.25;
				}
				else if (this->getName() == "Mutated Mastermind")
				{
					INT_Boss_Multiplier = 1.5;
				}
				else if (this->getName() == "Keeper of The Device")
				{
					INT_Boss_Multiplier = 1.75;
				}
				if (this->getStamina() >= SKILL_Skill_Selected.getStaminaCost() && INT_Skill_Chance > 3)
				{
					if (SKILL_Skill_Selected.getType() == "Support")
					{
						int INT_HP_Gain = SKILL_Skill_Selected.getHPGain() * 3;
						this->STR_Turn_Phrase = "\n   " + this->STR_Name + " casted " + SKILL_Skill_Selected.getName() + " restoring " + to_string(INT_HP_Gain) + " HP";
						this->INT_Health += INT_HP_Gain;
						if (this->INT_Health > this->INT_Max_Health)
						{
							this->INT_Health = this->INT_Max_Health;
						}
					}
					else
					{
						if (SKILL_Skill_Selected.getType() == "Nuclear")
						{
							INT_Calculated_Damage = SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * FLT_Guard_Multiplier * INT_Boss_Multiplier;
							this->STR_Turn_Phrase = "\n   " + this->STR_Name + " casted " + SKILL_Skill_Selected.getName() + " dealing " + to_string(INT_Calculated_Damage) + " damage ";
						}
						else if (PLAYER_Player.getElements().find(SKILL_Skill_Selected.getType())->second == "-")
						{
							INT_Calculated_Damage = SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * FLT_Guard_Multiplier * INT_Boss_Multiplier;
							this->STR_Turn_Phrase = "\n   " + this->STR_Name + " casted " + SKILL_Skill_Selected.getName() + " dealing " + to_string(INT_Calculated_Damage) + " damage ";
						}
						else if (PLAYER_Player.getElements().find(SKILL_Skill_Selected.getType())->second == "Wk")
						{
							INT_Calculated_Damage = SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * FLT_Guard_Multiplier * 1.5 * INT_Boss_Multiplier;
							this->STR_Turn_Phrase = "\n   " + this->STR_Name + " casted " + SKILL_Skill_Selected.getName() + " dealing " + to_string(INT_Calculated_Damage) + " damage (WEAK) ";
						}
						else if (PLAYER_Player.getElements().find(SKILL_Skill_Selected.getType())->second == "Rst")
						{
							INT_Calculated_Damage = SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * FLT_Guard_Multiplier * 0.5 * INT_Boss_Multiplier;
							this->STR_Turn_Phrase = "\n   " + this->STR_Name + " casted " + SKILL_Skill_Selected.getName() + " dealing " + to_string(INT_Calculated_Damage) + " damage (RESIST) ";
						}
						else if (PLAYER_Player.getElements().find(SKILL_Skill_Selected.getType())->second == "Nul")
						{
							INT_Calculated_Damage = 0;
							this->STR_Turn_Phrase = "\n   " + this->STR_Name + " casted " + SKILL_Skill_Selected.getName() + " dealing " + to_string(INT_Calculated_Damage) + " damage (BLOCK) ";
						}
						PLAYER_Player.changeHealth(-INT_Calculated_Damage);
					}
					this->INT_Stamina -= SKILL_Skill_Selected.getStaminaCost();
				}
				else
				{
					INT_Calculated_Damage = this->getDamage() * FLT_Attribute_Multiplier * FLT_Guard_Multiplier * INT_Boss_Multiplier;
					this->STR_Turn_Phrase = "\n   " + this->STR_Name + " attacked you dealing " + to_string(INT_Calculated_Damage) + " damage ";
					PLAYER_Player.changeHealth(-INT_Calculated_Damage);
				}
			}
		}
		else
		{
			this->STR_Turn_Phrase = "\n   " + this->STR_Name + " missed their attack!";
		}
		this->ENUM_State = battleState::WAITING;
	}
}
