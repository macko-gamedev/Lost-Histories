#include "Skill.h"

Skill::Skill() { }

Skill::Skill(string name)
{
	this->skill_name = name;

	// All skills which can be obtained


	// ATTACK : FIRE
	if (this->skill_name == "Flame")
	{
		this->skill_type = "fire";
		this->skill_desc = "Deal low fire damage to one enemy";
		this->base_dmg = 40;
		this->stamina_cost = 6;
		this->single_target = true;
	}
	if (this->skill_name == "Meflame")
	{
		this->skill_type = "fire";
		this->skill_desc = "Deal low fire damage to all enemies";
		this->base_dmg = 32;
		this->stamina_cost = 10;
		this->single_target = false;
	}
	else if (this->skill_name == "Flamao")
	{
		this->skill_type = "fire";
		this->skill_desc = "Deal medium fire damage to one enemy";
		this->base_dmg = 65;
		this->stamina_cost = 12;
		this->single_target = true;
	}
	if (this->skill_name == "Meflamao")
	{
		this->skill_type = "fire";
		this->skill_desc = "Deal medium fire damage to all enemies";
		this->base_dmg = 52;
		this->stamina_cost = 16;
		this->single_target = false;
	}
	else if (this->skill_name == "Flamadia")
	{
		this->skill_type = "fire";
		this->skill_desc = "Deal heavy fire damage to one enemy";
		this->base_dmg = 105;
		this->stamina_cost = 20;
		this->single_target = true;
	}
	else if (this->skill_name == "Meflamadia")
	{
		this->skill_type = "fire";
		this->skill_desc = "Deal heavy fire damage to all enemies";
		this->base_dmg = 84;
		this->stamina_cost = 24;
		this->single_target = false;
	}
	else if (this->skill_name == "Eye of the Sun")
	{
		this->skill_type = "fire";
		this->skill_desc = "Channel the inner heat of the sun upon one foe";
		this->base_dmg = 445;
		this->stamina_cost = 64;
		this->single_target = true;
	}

	// ATTACK : ICE
	else if (this->skill_name == "Freeze")
	{
		this->skill_type = "ice";
		this->skill_desc = "Deal low ice damage to one enemy";
		this->base_dmg = 36;
		this->stamina_cost = 5;
		this->single_target = true;
	}
	if (this->skill_name == "Mefreeze")
	{
		this->skill_type = "ice";
		this->skill_desc = "Deal low ice damage to all enemies";
		this->base_dmg = 29;
		this->stamina_cost = 8;
		this->single_target = false;
	}
	else if (this->skill_name == "Freezan")
	{
		this->skill_type = "ice";
		this->skill_desc = "Deal medium ice damage to one enemy";
		this->base_dmg = 60;
		this->stamina_cost = 10;
		this->single_target = true;
	}
	if (this->skill_name == "Mefreezan")
	{
		this->skill_type = "ice";
		this->skill_desc = "Deal medium ice damage to all enemies";
		this->base_dmg = 48;
		this->stamina_cost = 14;
		this->single_target = false;
	}
	else if (this->skill_name == "Freezadia")
	{
		this->skill_type = "ice";
		this->skill_desc = "Deal heavy ice damage to one enemy";
		this->base_dmg = 95;
		this->stamina_cost = 16;
		this->single_target = true;
	}
	else if (this->skill_name == "Mefreezadia")
	{
		this->skill_type = "ice";
		this->skill_desc = "Deal heavy ice damage to all enemies";
		this->base_dmg = 76;
		this->stamina_cost = 20;
		this->single_target = false;
	}
	else if (this->skill_name == "Eye of the 'Berg")
	{
		this->skill_type = "ice";
		this->skill_desc = "Channel the inner cold of an iceberg upon one foe";
		this->base_dmg = 380;
		this->stamina_cost = 60;
		this->single_target = true;
	}

	// ATTACK : ELECTRIC
	if (this->skill_name == "Zap")
	{
		this->skill_type = "electric";
		this->skill_desc = "Deal low electric damage to one enemy";
		this->base_dmg = 40;
		this->stamina_cost = 6;
		this->single_target = true;
	}
	if (this->skill_name == "Mezap")
	{
		this->skill_type = "electric";
		this->skill_desc = "Deal low electric damage to all enemies";
		this->base_dmg = 32;
		this->stamina_cost = 10;
		this->single_target = false;
	}
	else if (this->skill_name == "Zapao")
	{
		this->skill_type = "electric";
		this->skill_desc = "Deal medium electric damage to one enemy";
		this->base_dmg = 65;
		this->stamina_cost = 12;
		this->single_target = true;
	}
	if (this->skill_name == "Mezapao")
	{
		this->skill_type = "electric";
		this->skill_desc = "Deal medium electric damage to all enemies";
		this->base_dmg = 52;
		this->stamina_cost = 16;
		this->single_target = false;
	}
	else if (this->skill_name == "Zapadia")
	{
		this->skill_type = "electric";
		this->skill_desc = "Deal heavy electric damage to one enemy";
		this->base_dmg = 105;
		this->stamina_cost = 20;
		this->single_target = true;
	}
	else if (this->skill_name == "Mezapadia")
	{
		this->skill_type = "electric";
		this->skill_desc = "Deal heavy electric damage to all enemies";
		this->base_dmg = 84;
		this->stamina_cost = 24;
		this->single_target = false;
	}
	else if (this->skill_name == "Eye of the Spark")
	{
		this->skill_type = "electric";
		this->skill_desc = "Channel the inner static of electricity upon one foe";
		this->base_dmg = 445;
		this->stamina_cost = 64;
		this->single_target = true;
	}

	// ATTACK : WIND
	else if (this->skill_name == "Gust")
	{
		this->skill_type = "wind";
		this->skill_desc = "Deal low wind damage to one enemy";
		this->base_dmg = 36;
		this->stamina_cost = 5;
		this->single_target = true;
	}
	if (this->skill_name == "Megust")
	{
		this->skill_type = "wind";
		this->skill_desc = "Deal low wind damage to all enemies";
		this->base_dmg = 29;
		this->stamina_cost = 8;
		this->single_target = false;
	}
	else if (this->skill_name == "Gustan")
	{
		this->skill_type = "wind";
		this->skill_desc = "Deal medium wind damage to one enemy";
		this->base_dmg = 60;
		this->stamina_cost = 10;
		this->single_target = true;
	}
	if (this->skill_name == "Megustan")
	{
		this->skill_type = "wind";
		this->skill_desc = "Deal medium wind damage to all enemies";
		this->base_dmg = 48;
		this->stamina_cost = 14;
		this->single_target = false;
	}
	else if (this->skill_name == "Gustadia")
	{
		this->skill_type = "wind";
		this->skill_desc = "Deal heavy wind damage to one enemy";
		this->base_dmg = 95;
		this->stamina_cost = 16;
		this->single_target = true;
	}
	else if (this->skill_name == "Megustadia")
	{
		this->skill_type = "wind";
		this->skill_desc = "Deal heavy wind damage to all enemies";
		this->base_dmg = 76;
		this->stamina_cost = 20;
		this->single_target = false;
	}
	else if (this->skill_name == "Eye of the Storm")
	{
		this->skill_type = "wind";
		this->skill_desc = "Channel the inner power of the storm upon one foe";
		this->base_dmg = 445;
		this->stamina_cost = 64;
		this->single_target = true;
	}

	// ATTACK : CURSE
	if (this->skill_name == "Hex")
	{
		this->skill_type = "curse";
		this->skill_desc = "Deal low curse damage to one enemy";
		this->base_dmg = 44;
		this->stamina_cost = 8;
		this->single_target = true;
	}
	if (this->skill_name == "Mehex")
	{
		this->skill_type = "curse";
		this->skill_desc = "Deal low curse damage to all enemies";
		this->base_dmg = 35;
		this->stamina_cost = 12;
		this->single_target = false;
	}
	else if (this->skill_name == "Hexo")
	{
		this->skill_type = "curse";
		this->skill_desc = "Deal medium curse damage to one enemy";
		this->base_dmg = 70;
		this->stamina_cost = 14;
		this->single_target = true;
	}
	if (this->skill_name == "Mehexo")
	{
		this->skill_type = "curse";
		this->skill_desc = "Deal medium curse damage to all enemies";
		this->base_dmg = 56;
		this->stamina_cost = 18;
		this->single_target = false;
	}
	else if (this->skill_name == "Hexaon")
	{
		this->skill_type = "curse";
		this->skill_desc = "Deal heavy curse damage to one enemy";
		this->base_dmg = 120;
		this->stamina_cost = 24;
		this->single_target = true;
	}
	else if (this->skill_name == "Mehexaon")
	{
		this->skill_type = "curse";
		this->skill_desc = "Deal heavy curse damage to all enemies";
		this->base_dmg = 96;
		this->stamina_cost = 28;
		this->single_target = false;
	}
	else if (this->skill_name == "Hex of Death")
	{
		this->skill_type = "curse";
		this->skill_desc = "Curse attack with a chance of insta-kill to one enemy";
		this->stamina_cost = 40;
		this->single_target = true;
	}

	// ATTACK : BLESS
	if (this->skill_name == "Blight")
	{
		this->skill_type = "bless";
		this->skill_desc = "Deal low bless damage to one enemy";
		this->base_dmg = 44;
		this->stamina_cost = 8;
		this->single_target = true;
	}
	if (this->skill_name == "Meblight")
	{
		this->skill_type = "bless";
		this->skill_desc = "Deal low bless damage to all enemies";
		this->base_dmg = 35;
		this->stamina_cost = 12;
		this->single_target = false;
	}
	else if (this->skill_name == "Blighta")
	{
		this->skill_type = "bless";
		this->skill_desc = "Deal medium bless damage to one enemy";
		this->base_dmg = 70;
		this->stamina_cost = 14;
		this->single_target = true;
	}
	if (this->skill_name == "Meblighta")
	{
		this->skill_type = "bless";
		this->skill_desc = "Deal medium bless damage to all enemies";
		this->base_dmg = 56;
		this->stamina_cost = 18;
		this->single_target = false;
	}
	else if (this->skill_name == "Blightaon")
	{
		this->skill_type = "bless";
		this->skill_desc = "Deal heavy bless damage to one enemy";
		this->base_dmg = 120;
		this->stamina_cost = 24;
		this->single_target = true;
	}
	else if (this->skill_name == "Meblightaon")
	{
		this->skill_type = "bless";
		this->skill_desc = "Deal heavy bless damage to all enemies";
		this->base_dmg = 96;
		this->stamina_cost = 28;
		this->single_target = false;
	}
	else if (this->skill_name == "Heavenly Judgement")
	{
		this->skill_type = "bless";
		this->skill_desc = "Bless attack with a chance of insta-kill to one enemy";
		this->stamina_cost = 40;
		this->single_target = true;
	}

	// SUPPORT : HEALING
	if (this->skill_name == "Heal")
	{
		this->skill_type = "support";
		this->skill_desc = "Restores a small amount of health";
		this->hp_gain = 60;
		this->stamina_cost = 6;
	}
	else if (this->skill_name == "Healan")
	{
		this->skill_type = "support";
		this->skill_desc = "Restores a moderate amount of health";
		this->hp_gain = 150;
		this->stamina_cost = 12;
	}
	else if (this->skill_name == "Healadia")
	{
		this->skill_type = "support";
		this->skill_desc = "Fully restores your health";
		this->hp_gain = 999;
		this->stamina_cost = 32;
	}
}

string Skill::getName()
{
	return this->skill_name;
}

string Skill::getDesc()
{
	return this->skill_desc;
}

string Skill::getType()
{
	return this->skill_type;
}

int Skill::getStaminaCost()
{
	return this->stamina_cost;
}

int Skill::getBaseDamage()
{
	return this->base_dmg;
}

int Skill::getHPGain()
{
	return this->hp_gain;
}
bool Skill::isSingleTarget()
{
	return this->single_target;
}
