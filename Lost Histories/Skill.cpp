#include "Skill.h"

Skill::Skill() { }

Skill::Skill(string N_NAME)
{
	this->STR_Skill_Name = N_NAME;
	this->BOOL_Is_Valid_Skill = true;
	this->INT_Base_Damage = 0;
	this->INT_Health_Gain = 0;
	this->INT_Stamina_Cost = 0;
	this->INT_Physical_Hit_Amount = 1;
	this->FLT_Health_Cost = 1.0;
	// All skills which can be obtained

	// ATTACK : PHYSICAL
	if (this->STR_Skill_Name == "Sucker Punch")
	{
		this->STR_Skill_Type = "Physical";
		this->STR_Skill_Desc = "Deal low physical damage to one enemy";
		this->INT_Base_Damage = 30;
		this->INT_Physical_Hit_Amount = 1;
		this->FLT_Health_Cost = 0.12;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Hacker Slash")
	{
		this->STR_Skill_Type = "Physical";
		this->STR_Skill_Desc = "Deal low physical damage to one enemy, hits 2x";
		this->INT_Base_Damage = 26;
		this->INT_Physical_Hit_Amount = 2;
		this->FLT_Health_Cost = 0.15;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Quick Jab")
	{
		this->STR_Skill_Type = "Physical";
		this->STR_Skill_Desc = "Deal medium physical damage to one enemy";
		this->INT_Base_Damage = 73;
		this->INT_Physical_Hit_Amount = 1;
		this->FLT_Health_Cost = 0.18;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Sickle Dance")
	{
		this->STR_Skill_Type = "Physical";
		this->STR_Skill_Desc = "Deal medium physical damage to one enemy, hits 2x";
		this->INT_Base_Damage = 91;
		this->INT_Physical_Hit_Amount = 2;
		this->FLT_Health_Cost = 0.24;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Decisive Strike")
	{
		this->STR_Skill_Type = "Physical";
		this->STR_Skill_Desc = "Deal massive physical damage to one enemy";
		this->INT_Base_Damage = 329;
		this->INT_Physical_Hit_Amount = 1;
		this->FLT_Health_Cost = 0.3;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "God's Power Punch")
	{
		this->STR_Skill_Type = "Physical";
		this->STR_Skill_Desc = "Deal colossal physical damage to one enemy";
		this->INT_Base_Damage = 578;
		this->INT_Physical_Hit_Amount = 1;
		this->FLT_Health_Cost = 0.35;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Impulse Strike")
	{
		this->STR_Skill_Type = "Physical";
		this->STR_Skill_Desc = "Deal heavy physical damage to one enemy, hits 2x";
		this->INT_Base_Damage = 253;
		this->INT_Physical_Hit_Amount = 2;
		this->FLT_Health_Cost = 0.32;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Akasha Arts")
	{
		this->STR_Skill_Type = "Physical";
		this->STR_Skill_Desc = "Deal heavy physical damage to one enemy, hits 4x";
		this->INT_Base_Damage = 239;
		this->INT_Physical_Hit_Amount = 4;
		this->FLT_Health_Cost = 0.19;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Decaying Chucks")
	{
		this->STR_Skill_Type = "Physical";
		this->STR_Skill_Desc = "Deal low physical damage to one enemy, hits 8x";
		this->INT_Base_Damage = 57;
		this->INT_Physical_Hit_Amount = 8;
		this->FLT_Health_Cost = 0.4;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Gaming Splash")
	{
		this->STR_Skill_Type = "Physical";
		this->STR_Skill_Desc = "Deal critical physical damage to one enemy";
		this->INT_Base_Damage = 795;
		this->INT_Physical_Hit_Amount = 1;
		this->FLT_Health_Cost = 0.4;
		this->BOOL_Single_Target = true;
	}

	// ATTACK : FIRE
	if (this->STR_Skill_Name == "Flame")
	{
		this->STR_Skill_Type = "Fire";
		this->STR_Skill_Desc = "Deal low fire damage to one enemy";
		this->INT_Base_Damage = 40;
		this->INT_Stamina_Cost = 6;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Meflame")
	{
		this->STR_Skill_Type = "Fire";
		this->STR_Skill_Desc = "Deal low fire damage to one enemy, hits 2x";
		this->INT_Base_Damage = 32;
		this->INT_Physical_Hit_Amount = 2;
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
	else if (this->STR_Skill_Name == "Meflamao")
	{
		this->STR_Skill_Type = "Fire";
		this->STR_Skill_Desc = "Deal medium fire damage to one enemy, hits 2x";
		this->INT_Base_Damage = 52;
		this->INT_Physical_Hit_Amount = 2;
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
		this->STR_Skill_Desc = "Deal heavy fire damage to one enemy, hits 2x";
		this->INT_Base_Damage = 84;
		this->INT_Physical_Hit_Amount = 2;
		this->INT_Stamina_Cost = 24;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Flamadiaran")
	{
		this->STR_Skill_Type = "Fire";
		this->STR_Skill_Desc = "Deal massive fire damage to one enemy";
		this->INT_Base_Damage = 262;
		this->INT_Stamina_Cost = 44;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Inferno")
	{
		this->STR_Skill_Type = "Fire";
		this->STR_Skill_Desc = "Deal colossal fire damage to one enemy";
		this->INT_Base_Damage = 485;
		this->INT_Stamina_Cost = 72;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Volcanic Blast")
	{
		this->STR_Skill_Type = "Fire";
		this->STR_Skill_Desc = "Deal low fire damage to one enemy, hits 32x";
		this->INT_Base_Damage = 40;
		this->INT_Physical_Hit_Amount = 32;
		this->INT_Stamina_Cost = 124;
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
	else if (this->STR_Skill_Name == "Mesplash")
	{
		this->STR_Skill_Type = "Water";
		this->STR_Skill_Desc = "Deal low water damage to one enemy, hits 2x";
		this->INT_Base_Damage = 29;
		this->INT_Physical_Hit_Amount = 2;
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
	else if (this->STR_Skill_Name == "Mesplashan")
	{
		this->STR_Skill_Type = "Water";
		this->STR_Skill_Desc = "Deal medium water damage to one enemy, hits 2x";
		this->INT_Base_Damage = 48;
		this->INT_Physical_Hit_Amount = 2;
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
		this->STR_Skill_Desc = "Deal heavy water damage to one enemy, hits 2x";
		this->INT_Base_Damage = 76;
		this->INT_Physical_Hit_Amount = 2;
		this->INT_Stamina_Cost = 20;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Splashadiaran")
	{
		this->STR_Skill_Type = "Water";
		this->STR_Skill_Desc = "Deal massive water damage to one enemy";
		this->INT_Base_Damage = 246;
		this->INT_Stamina_Cost = 38;
		this->BOOL_Single_Target = true;
		}
	else if (this->STR_Skill_Name == "Tsunami")
	{
		this->STR_Skill_Type = "Water";
		this->STR_Skill_Desc = "Deal colossal water damage to one enemy";
		this->INT_Base_Damage = 445;
		this->INT_Stamina_Cost = 68;
		this->BOOL_Single_Target = true;
		}
	else if (this->STR_Skill_Name == "Waternado")
	{
		this->STR_Skill_Type = "Water";
		this->STR_Skill_Desc = "Deal heavy water damage to one enemy, hits 8x";
		this->INT_Base_Damage = 95;
		this->INT_Physical_Hit_Amount = 8;
		this->INT_Stamina_Cost = 106;
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
	else if (this->STR_Skill_Name == "Mefreeze")
	{
		this->STR_Skill_Type = "Ice";
		this->STR_Skill_Desc = "Deal low ice damage to one enemy, hits 2x";
		this->INT_Physical_Hit_Amount = 2;
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
	else if (this->STR_Skill_Name == "Mefreezan")
	{
		this->STR_Skill_Type = "Ice";
		this->STR_Skill_Desc = "Deal medium ice damage to one enemy, hits 2x";
		this->INT_Base_Damage = 48;
		this->INT_Physical_Hit_Amount = 2;
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
		this->STR_Skill_Desc = "Deal heavy ice damage to one enemy, hits 2x";
		this->INT_Base_Damage = 76;
		this->INT_Physical_Hit_Amount = 2;
		this->INT_Stamina_Cost = 20;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Freezadiaran")
	{
		this->STR_Skill_Type = "Ice";
		this->STR_Skill_Desc = "Deal massive ice damage to one enemy";
		this->INT_Base_Damage = 246;
		this->INT_Stamina_Cost = 38;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Blizzard")
	{
		this->STR_Skill_Type = "Ice";
		this->STR_Skill_Desc = "Deal colossal ice damage to one enemy";
		this->INT_Base_Damage = 445;
		this->INT_Stamina_Cost = 68;
		this->BOOL_Single_Target = true;
		}
	else if (this->STR_Skill_Name == "Ice Age")
	{
		this->STR_Skill_Type = "Ice";
		this->STR_Skill_Desc = "Deal colossal ice damage to one enemy, hits 3x";
		this->INT_Base_Damage = 398;
		this->INT_Physical_Hit_Amount = 3;
		this->INT_Stamina_Cost = 138;
		this->BOOL_Single_Target = true;
		}

	// ATTACK : ELECTRIC
	else if (this->STR_Skill_Name == "Zap")
	{
		this->STR_Skill_Type = "Electric";
		this->STR_Skill_Desc = "Deal low electric damage to one enemy";
		this->INT_Base_Damage = 40;
		this->INT_Stamina_Cost = 6;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Mezap")
	{
		this->STR_Skill_Type = "Electric";
		this->STR_Skill_Desc = "Deal low electric damage to one enemy, hits 2x";
		this->INT_Base_Damage = 32;
		this->INT_Physical_Hit_Amount = 2;
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
	else if (this->STR_Skill_Name == "Mezapao")
	{
		this->STR_Skill_Type = "Electric";
		this->STR_Skill_Desc = "Deal medium electric damage to one enemy, hits 2x";
		this->INT_Base_Damage = 52;
		this->INT_Physical_Hit_Amount = 2;
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
		this->STR_Skill_Desc = "Deal heavy electric damage to one enemy, hits 2x";
		this->INT_Base_Damage = 84;
		this->INT_Physical_Hit_Amount = 2;
		this->INT_Stamina_Cost = 24;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Zapadiaran")
	{
		this->STR_Skill_Type = "Electric";
		this->STR_Skill_Desc = "Deal massive electric damage to one enemy";
		this->INT_Base_Damage = 262;
		this->INT_Stamina_Cost = 44;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Thunder Bolt")
	{
		this->STR_Skill_Type = "Electric";
		this->STR_Skill_Desc = "Deal colossal electric damage to one enemy";
		this->INT_Base_Damage = 485;
		this->INT_Stamina_Cost = 72;
		this->BOOL_Single_Target = true;
		}
	else if (this->STR_Skill_Name == "Voltage Shock")
	{
		this->STR_Skill_Type = "Electric";
		this->STR_Skill_Desc = "Deal massive electric damage to one enemy, hits 4x";
		this->INT_Base_Damage = 262;
		this->INT_Physical_Hit_Amount = 4;
		this->INT_Stamina_Cost = 116;
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
	else if (this->STR_Skill_Name == "Megust")
	{
		this->STR_Skill_Type = "Wind";
		this->STR_Skill_Desc = "Deal low wind damage to one enemy, hits 2x";
		this->INT_Base_Damage = 29;
		this->INT_Physical_Hit_Amount = 2;
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
	else if (this->STR_Skill_Name == "Megustan")
	{
		this->STR_Skill_Type = "Wind";
		this->STR_Skill_Desc = "Deal medium wind damage to one enemy, hits 2x";
		this->INT_Base_Damage = 48;
		this->INT_Physical_Hit_Amount = 2;
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
		this->STR_Skill_Desc = "Deal heavy wind damage to one enemy, hits 2x";
		this->INT_Base_Damage = 76;
		this->INT_Physical_Hit_Amount = 2;
		this->INT_Stamina_Cost = 20;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Gustadiaran")
	{
		this->STR_Skill_Type = "Wind";
		this->STR_Skill_Desc = "Deal massive wind damage to one enemy";
		this->INT_Base_Damage = 246;
		this->INT_Stamina_Cost = 38;
		this->BOOL_Single_Target = true;
		}
	else if (this->STR_Skill_Name == "Hurricane")
	{
		this->STR_Skill_Type = "Wind";
		this->STR_Skill_Desc = "Deal colossal wind damage to one enemy";
		this->INT_Base_Damage = 445;
		this->INT_Stamina_Cost = 68;
		this->BOOL_Single_Target = true;
		}
	else if (this->STR_Skill_Name == "Whirlwind")
	{
		this->STR_Skill_Type = "Wind";
		this->STR_Skill_Desc = "Deal medium wind damage to one enemy, hits 16x";
		this->INT_Base_Damage = 36;
		this->INT_Physical_Hit_Amount = 16;
		this->INT_Stamina_Cost = 112;
		this->BOOL_Single_Target = true;
		}

	// ATTACK : CURSE
	else if (this->STR_Skill_Name == "Hex")
	{
		this->STR_Skill_Type = "Curse";
		this->STR_Skill_Desc = "Deal low curse damage to one enemy";
		this->INT_Base_Damage = 44;
		this->INT_Stamina_Cost = 8;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Mehex")
	{
		this->STR_Skill_Type = "Curse";
		this->STR_Skill_Desc = "Deal low curse damage to one enemy, hits 2x";
		this->INT_Base_Damage = 35;
		this->INT_Physical_Hit_Amount = 2;
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
	else if (this->STR_Skill_Name == "Mehexo")
	{
		this->STR_Skill_Type = "Curse";
		this->STR_Skill_Desc = "Deal medium curse damage to one enemy, hits 2x";
		this->INT_Base_Damage = 56;
		this->INT_Physical_Hit_Amount = 2;
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
		this->STR_Skill_Desc = "Deal heavy curse damage to one enemy, hits 2x";
		this->INT_Base_Damage = 96;
		this->INT_Physical_Hit_Amount = 2;
		this->INT_Stamina_Cost = 28;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Hexaonia")
	{
		this->STR_Skill_Type = "Curse";
		this->STR_Skill_Desc = "Deal massive curse damage to one enemy";
		this->INT_Base_Damage = 308;
		this->INT_Stamina_Cost = 76;
		this->BOOL_Single_Target = true;
		}
	else if (this->STR_Skill_Name == "Crucifix of Death")
	{
		this->STR_Skill_Type = "Curse";
		this->STR_Skill_Desc = "Deal colossal curse damage to one enemy";
		this->INT_Base_Damage = 535;
		this->INT_Stamina_Cost = 104;
		this->BOOL_Single_Target = true;
	}

	// ATTACK : BLESS
	else if (this->STR_Skill_Name == "Blight")
	{
		this->STR_Skill_Type = "Bless";
		this->STR_Skill_Desc = "Deal low bless damage to one enemy";
		this->INT_Base_Damage = 44;
		this->INT_Stamina_Cost = 8;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Meblight")
	{
		this->STR_Skill_Type = "Bless";
		this->STR_Skill_Desc = "Deal low bless damage to one enemy, hits 2x";
		this->INT_Base_Damage = 35;
		this->INT_Physical_Hit_Amount = 2;
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
	else if (this->STR_Skill_Name == "Meblighta")
	{
		this->STR_Skill_Type = "Bless";
		this->STR_Skill_Desc = "Deal medium bless damage to one enemy, hits 2x";
		this->INT_Base_Damage = 56;
		this->INT_Physical_Hit_Amount = 2;
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
		this->STR_Skill_Desc = "Deal heavy bless damage to one enemy, hits 2x";
		this->INT_Base_Damage = 96;
		this->INT_Physical_Hit_Amount = 2;
		this->INT_Stamina_Cost = 28;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Blightaonia")
	{
		this->STR_Skill_Type = "Bless";
		this->STR_Skill_Desc = "Deal massive bless damage to one enemy";
		this->INT_Base_Damage = 308;
		this->INT_Stamina_Cost = 76;
		this->BOOL_Single_Target = true;
	}
	else if (this->STR_Skill_Name == "Fist of Justice")
	{
		this->STR_Skill_Type = "Bless";
		this->STR_Skill_Desc = "Deal colossal bless damage to one enemy";
		this->INT_Base_Damage = 535;
		this->INT_Stamina_Cost = 104;
		this->BOOL_Single_Target = true;
	}

	// ATTACK : NUCLEAR
	else if (this->STR_Skill_Name == "Frei")
	{
		this->STR_Skill_Type = "Nuclear";
		this->STR_Skill_Desc = "Deal low nuclear damage to one enemy, hits 2x";
		this->INT_Base_Damage = 98;
		this->INT_Stamina_Cost = 20;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Freila")
	{
		this->STR_Skill_Type = "Nuclear";
		this->STR_Skill_Desc = "Deal medium nuclear damage to one enemy, hits 2x";
		this->INT_Base_Damage = 174;
		this->INT_Stamina_Cost = 36;
		this->BOOL_Single_Target = false;
	}
	else if (this->STR_Skill_Name == "Freiladia")
	{
		this->STR_Skill_Type = "Nuclear";
		this->STR_Skill_Desc = "Deal heavy nuclear damage to one enemy, hits 2x";
		this->INT_Base_Damage = 269;
		this->INT_Stamina_Cost = 48;
		this->BOOL_Single_Target = false;
		}
	else if (this->STR_Skill_Name == "Freiladiaran")
	{
		this->STR_Skill_Type = "Nuclear";
		this->STR_Skill_Desc = "Deal massive nuclear damage to one enemy, hits 2x";
		this->INT_Base_Damage = 612;
		this->INT_Stamina_Cost = 110;
		this->BOOL_Single_Target = false;
		}
	else if (this->STR_Skill_Name == "End of the World")
	{
		this->STR_Skill_Type = "Nuclear";
		this->STR_Skill_Desc = "Deal colossal nuclear damage to one enemy, hits 2x";
		this->INT_Base_Damage = 974;
		this->INT_Stamina_Cost = 148;
		this->BOOL_Single_Target = false;
		} 
	else if (this->STR_Skill_Name == "Death")
	{
		this->STR_Skill_Type = "Nuclear";
		this->STR_Skill_Desc = "Instantly kill the enemy";
		this->INT_Base_Damage = 99999;
		this->INT_Stamina_Cost = 0;
		this->BOOL_Single_Target = true;
	}

	// SUPPORT : HEALING
	else if (this->STR_Skill_Name == "Heal")
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
	else
	{
		this->BOOL_Is_Valid_Skill = false;
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

int Skill::getPhysicalHitAmount()
{
	return this->INT_Physical_Hit_Amount;
}

bool Skill::isSingleTarget()
{
	return this->BOOL_Single_Target;
}

bool Skill::isValid()
{
	return this->BOOL_Is_Valid_Skill;
}

float Skill::getHealthCostMultiplier()
{
	return this->FLT_Health_Cost;
}