#include "Skill.h"

Skill::Skill() { }

Skill::Skill(string N_NAME)
{
	this->STR_Skill_Name = N_NAME;

	// All skills which can be obtained


	// ATTACK : FIRE
	if (this->STR_Skill_Name == "Flame")
	{
		this->STR_Skill_Type = "Fire";
		this->STR_Skill_Desc = "Deal low fire damage to one enemy";
		this->INT_Base_Damage = 40;
		this->INT_Stamina_Cost = 6;
		this->BOOL_Single_Target = true;
	}
	if (this->STR_Skill_Name == "Meflame")
	{
		this->STR_Skill_Type = "Fire";
		this->STR_Skill_Desc = "Deal low fire damage to all enemies";
		this->INT_Base_Damage = 32;
		this->INT_Stamina_Cost = 10;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Flamao")
	{
		this->STR_Skill_Type = "Fire";
		this->STR_Skill_Desc = "Deal medium fire damage to one enemy";
		this->INT_Base_Damage = 65;
		this->INT_Stamina_Cost = 12;
		this->BOOL_Single_Target = true;
	}
	if (this->STR_Skill_Name == "Meflamao")
	{
		this->STR_Skill_Type = "Fire";
		this->STR_Skill_Desc = "Deal medium fire damage to all enemies";
		this->INT_Base_Damage = 52;
		this->INT_Stamina_Cost = 16;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Flamadia")
	{
		this->STR_Skill_Type = "Fire";
		this->STR_Skill_Desc = "Deal heavy fire damage to one enemy";
		this->INT_Base_Damage = 105;
		this->INT_Stamina_Cost = 20;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Meflamadia")
	{
		this->STR_Skill_Type = "Fire";
		this->STR_Skill_Desc = "Deal heavy fire damage to all enemies";
		this->INT_Base_Damage = 84;
		this->INT_Stamina_Cost = 24;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Eye of the Sun")
	{
		this->STR_Skill_Type = "Fire";
		this->STR_Skill_Desc = "Channel the inner heat of the sun upon one foe";
		this->INT_Base_Damage = 445;
		this->INT_Stamina_Cost = 64;
		this->BOOL_Single_Target = true;
	}

	// ATTACK : WATER
	else if (this->STR_Skill_Name == "Splash")
	{
		this->STR_Skill_Type = "Water";
		this->STR_Skill_Desc = "Deal low water damage to one enemy";
		this->INT_Base_Damage = 36;
		this->INT_Stamina_Cost = 5;
		this->BOOL_Single_Target = true;
	}
	if (this->STR_Skill_Name == "Mesplash")
	{
		this->STR_Skill_Type = "Water";
		this->STR_Skill_Desc = "Deal low water damage to all enemies";
		this->INT_Base_Damage = 29;
		this->INT_Stamina_Cost = 8;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Splashan")
	{
		this->STR_Skill_Type = "Water";
		this->STR_Skill_Desc = "Deal medium water damage to one enemy";
		this->INT_Base_Damage = 60;
		this->INT_Stamina_Cost = 10;
		this->BOOL_Single_Target = true;
	}
	if (this->STR_Skill_Name == "Mesplashan")
	{
		this->STR_Skill_Type = "Water";
		this->STR_Skill_Desc = "Deal medium water damage to all enemies";
		this->INT_Base_Damage = 48;
		this->INT_Stamina_Cost = 14;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Splashadia")
	{
		this->STR_Skill_Type = "Water";
		this->STR_Skill_Desc = "Deal heavy water damage to one enemy";
		this->INT_Base_Damage = 95;
		this->INT_Stamina_Cost = 16;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Mesplashadia")
	{
		this->STR_Skill_Type = "Water";
		this->STR_Skill_Desc = "Deal heavy water damage to all enemies";
		this->INT_Base_Damage = 76;
		this->INT_Stamina_Cost = 20;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Eye of the 'Shell")
	{
		this->STR_Skill_Type = "Water";
		this->STR_Skill_Desc = "Channel the inner water of the ocean upon one foe";
		this->INT_Base_Damage = 380;
		this->INT_Stamina_Cost = 60;
		this->BOOL_Single_Target = true;
	}

	// ATTACK : ICE
	else if (this->STR_Skill_Name == "Freeze")
	{
		this->STR_Skill_Type = "Ice";
		this->STR_Skill_Desc = "Deal low ice damage to one enemy";
		this->INT_Base_Damage = 36;
		this->INT_Stamina_Cost = 5;
		this->BOOL_Single_Target = true;
	}
	if (this->STR_Skill_Name == "Mefreeze")
	{
		this->STR_Skill_Type = "Ice";
		this->STR_Skill_Desc = "Deal low ice damage to all enemies";
		this->INT_Base_Damage = 29;
		this->INT_Stamina_Cost = 8;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Freezan")
	{
		this->STR_Skill_Type = "Ice";
		this->STR_Skill_Desc = "Deal medium ice damage to one enemy";
		this->INT_Base_Damage = 60;
		this->INT_Stamina_Cost = 10;
		this->BOOL_Single_Target = true;
	}
	if (this->STR_Skill_Name == "Mefreezan")
	{
		this->STR_Skill_Type = "Ice";
		this->STR_Skill_Desc = "Deal medium ice damage to all enemies";
		this->INT_Base_Damage = 48;
		this->INT_Stamina_Cost = 14;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Freezadia")
	{
		this->STR_Skill_Type = "Ice";
		this->STR_Skill_Desc = "Deal heavy ice damage to one enemy";
		this->INT_Base_Damage = 95;
		this->INT_Stamina_Cost = 16;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Mefreezadia")
	{
		this->STR_Skill_Type = "Ice";
		this->STR_Skill_Desc = "Deal heavy ice damage to all enemies";
		this->INT_Base_Damage = 76;
		this->INT_Stamina_Cost = 20;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Eye of the 'Berg")
	{
		this->STR_Skill_Type = "Ice";
		this->STR_Skill_Desc = "Channel the inner cold of an iceberg upon one foe";
		this->INT_Base_Damage = 380;
		this->INT_Stamina_Cost = 60;
		this->BOOL_Single_Target = true;
	}

	// ATTACK : ELECTRIC
	if (this->STR_Skill_Name == "Zap")
	{
		this->STR_Skill_Type = "Electric";
		this->STR_Skill_Desc = "Deal low electric damage to one enemy";
		this->INT_Base_Damage = 40;
		this->INT_Stamina_Cost = 6;
		this->BOOL_Single_Target = true;
	}
	if (this->STR_Skill_Name == "Mezap")
	{
		this->STR_Skill_Type = "Electric";
		this->STR_Skill_Desc = "Deal low electric damage to all enemies";
		this->INT_Base_Damage = 32;
		this->INT_Stamina_Cost = 10;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Zapao")
	{
		this->STR_Skill_Type = "Electric";
		this->STR_Skill_Desc = "Deal medium electric damage to one enemy";
		this->INT_Base_Damage = 65;
		this->INT_Stamina_Cost = 12;
		this->BOOL_Single_Target = true;
	}
	if (this->STR_Skill_Name == "Mezapao")
	{
		this->STR_Skill_Type = "Electric";
		this->STR_Skill_Desc = "Deal medium electric damage to all enemies";
		this->INT_Base_Damage = 52;
		this->INT_Stamina_Cost = 16;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Zapadia")
	{
		this->STR_Skill_Type = "Electric";
		this->STR_Skill_Desc = "Deal heavy electric damage to one enemy";
		this->INT_Base_Damage = 105;
		this->INT_Stamina_Cost = 20;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Mezapadia")
	{
		this->STR_Skill_Type = "Electric";
		this->STR_Skill_Desc = "Deal heavy electric damage to all enemies";
		this->INT_Base_Damage = 84;
		this->INT_Stamina_Cost = 24;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Eye of the Spark")
	{
		this->STR_Skill_Type = "Electric";
		this->STR_Skill_Desc = "Channel the inner static of electricity upon one foe";
		this->INT_Base_Damage = 445;
		this->INT_Stamina_Cost = 64;
		this->BOOL_Single_Target = true;
	}

	// ATTACK : WIND
	else if (this->STR_Skill_Name == "Gust")
	{
		this->STR_Skill_Type = "Wind";
		this->STR_Skill_Desc = "Deal low wind damage to one enemy";
		this->INT_Base_Damage = 36;
		this->INT_Stamina_Cost = 5;
		this->BOOL_Single_Target = true;
	}
	if (this->STR_Skill_Name == "Megust")
	{
		this->STR_Skill_Type = "Wind";
		this->STR_Skill_Desc = "Deal low wind damage to all enemies";
		this->INT_Base_Damage = 29;
		this->INT_Stamina_Cost = 8;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Gustan")
	{
		this->STR_Skill_Type = "Wind";
		this->STR_Skill_Desc = "Deal medium wind damage to one enemy";
		this->INT_Base_Damage = 60;
		this->INT_Stamina_Cost = 10;
		this->BOOL_Single_Target = true;
	}
	if (this->STR_Skill_Name == "Megustan")
	{
		this->STR_Skill_Type = "Wind";
		this->STR_Skill_Desc = "Deal medium wind damage to all enemies";
		this->INT_Base_Damage = 48;
		this->INT_Stamina_Cost = 14;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Gustadia")
	{
		this->STR_Skill_Type = "Wind";
		this->STR_Skill_Desc = "Deal heavy wind damage to one enemy";
		this->INT_Base_Damage = 95;
		this->INT_Stamina_Cost = 16;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Megustadia")
	{
		this->STR_Skill_Type = "Wind";
		this->STR_Skill_Desc = "Deal heavy wind damage to all enemies";
		this->INT_Base_Damage = 76;
		this->INT_Stamina_Cost = 20;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Eye of the Storm")
	{
		this->STR_Skill_Type = "Wind";
		this->STR_Skill_Desc = "Channel the inner power of the storm upon one foe";
		this->INT_Base_Damage = 445;
		this->INT_Stamina_Cost = 64;
		this->BOOL_Single_Target = true;
	}

	// ATTACK : CURSE
	if (this->STR_Skill_Name == "Hex")
	{
		this->STR_Skill_Type = "Curse";
		this->STR_Skill_Desc = "Deal low curse damage to one enemy";
		this->INT_Base_Damage = 44;
		this->INT_Stamina_Cost = 8;
		this->BOOL_Single_Target = true;
	}
	if (this->STR_Skill_Name == "Mehex")
	{
		this->STR_Skill_Type = "Curse";
		this->STR_Skill_Desc = "Deal low curse damage to all enemies";
		this->INT_Base_Damage = 35;
		this->INT_Stamina_Cost = 12;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Hexo")
	{
		this->STR_Skill_Type = "Curse";
		this->STR_Skill_Desc = "Deal medium curse damage to one enemy";
		this->INT_Base_Damage = 70;
		this->INT_Stamina_Cost = 14;
		this->BOOL_Single_Target = true;
	}
	if (this->STR_Skill_Name == "Mehexo")
	{
		this->STR_Skill_Type = "Curse";
		this->STR_Skill_Desc = "Deal medium curse damage to all enemies";
		this->INT_Base_Damage = 56;
		this->INT_Stamina_Cost = 18;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Hexaon")
	{
		this->STR_Skill_Type = "Curse";
		this->STR_Skill_Desc = "Deal heavy curse damage to one enemy";
		this->INT_Base_Damage = 120;
		this->INT_Stamina_Cost = 24;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Mehexaon")
	{
		this->STR_Skill_Type = "Curse";
		this->STR_Skill_Desc = "Deal heavy curse damage to all enemies";
		this->INT_Base_Damage = 96;
		this->INT_Stamina_Cost = 28;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Hex of Death")
	{
		this->STR_Skill_Type = "Curse";
		this->STR_Skill_Desc = "Curse attack with a chance of insta-kill to one enemy";
		this->INT_Stamina_Cost = 40;
		this->BOOL_Single_Target = true;
	}

	// ATTACK : BLESS
	if (this->STR_Skill_Name == "Blight")
	{
		this->STR_Skill_Type = "Bless";
		this->STR_Skill_Desc = "Deal low bless damage to one enemy";
		this->INT_Base_Damage = 44;
		this->INT_Stamina_Cost = 8;
		this->BOOL_Single_Target = true;
	}
	if (this->STR_Skill_Name == "Meblight")
	{
		this->STR_Skill_Type = "Bless";
		this->STR_Skill_Desc = "Deal low bless damage to all enemies";
		this->INT_Base_Damage = 35;
		this->INT_Stamina_Cost = 12;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Blighta")
	{
		this->STR_Skill_Type = "Bless";
		this->STR_Skill_Desc = "Deal medium bless damage to one enemy";
		this->INT_Base_Damage = 70;
		this->INT_Stamina_Cost = 14;
		this->BOOL_Single_Target = true;
	}
	if (this->STR_Skill_Name == "Meblighta")
	{
		this->STR_Skill_Type = "Bless";
		this->STR_Skill_Desc = "Deal medium bless damage to all enemies";
		this->INT_Base_Damage = 56;
		this->INT_Stamina_Cost = 18;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Blightaon")
	{
		this->STR_Skill_Type = "Bless";
		this->STR_Skill_Desc = "Deal heavy bless damage to one enemy";
		this->INT_Base_Damage = 120;
		this->INT_Stamina_Cost = 24;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Meblightaon")
	{
		this->STR_Skill_Type = "Bless";
		this->STR_Skill_Desc = "Deal heavy bless damage to all enemies";
		this->INT_Base_Damage = 96;
		this->INT_Stamina_Cost = 28;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Heavenly Judgement")
	{
		this->STR_Skill_Type = "Bless";
		this->STR_Skill_Desc = "Bless attack with a chance of insta-kill to one enemy";
		this->INT_Stamina_Cost = 40;
		this->BOOL_Single_Target = true;
	}

	if (this->STR_Skill_Name == "Death")
	{
		this->STR_Skill_Type = "Nuclear";
		this->STR_Skill_Desc = "Instantly kill the enemy";
		this->INT_Base_Damage = 9999;
		this->INT_Stamina_Cost = 0;
		this->BOOL_Single_Target = true;
	}

	// SUPPORT : HEALING
	if (this->STR_Skill_Name == "Heal")
	{
		this->STR_Skill_Type = "Support";
		this->STR_Skill_Desc = "Restores a small amount of health";
		this->INT_Health_Gain = 60;
		this->INT_Stamina_Cost = 6;
	}
	else if (this->STR_Skill_Name == "Healan")
	{
		this->STR_Skill_Type = "Support";
		this->STR_Skill_Desc = "Restores a moderate amount of health";
		this->INT_Health_Gain = 150;
		this->INT_Stamina_Cost = 12;
	}
	else if (this->STR_Skill_Name == "Healadia")
	{
		this->STR_Skill_Type = "Support";
		this->STR_Skill_Desc = "Fully restores your health";
		this->INT_Health_Gain = 999;
		this->INT_Stamina_Cost = 32;
	}
}

string Skill::getName()
{
	return this->STR_Skill_Name;
}

string Skill::getDesc()
{
	return this->STR_Skill_Desc;
}

string Skill::getType()
{
	return this->STR_Skill_Type;
}

int Skill::getStaminaCost()
{
	return this->INT_Stamina_Cost;
}

int Skill::getBaseDamage()
{
	return this->INT_Base_Damage;
}

int Skill::getHPGain()
{
	return this->INT_Health_Gain;
}
bool Skill::isSingleTarget()
{
	return this->BOOL_Single_Target;
}
