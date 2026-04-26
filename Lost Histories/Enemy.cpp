#include "Player.h"
#include "Enemy.h"
#include <ctime>
#include <cstdlib>

Enemy::Enemy() { }

Enemy::Enemy(string nName, int nLevel, int nHealth, int nStamina, vector<Skill> nSkills, Item* nDroppedItem, bool nBoss, int nDamage) : BattleStat(nName, nLevel, nHealth, nStamina)
{
	this->MAP_Elements = { {"Fire", "-"}, {"Water", "-"}, {"Ice", "-"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "-"} };
	this->VEC_Skills = nSkills;
	this->ITEM_Dropped_Item = nDroppedItem;
	this->BOOL_Boss = nBoss;
	this->INT_Damage = nDamage;
	this->INT_Boss_Stat_Cycle = 2;
}

map<string, string> Enemy::getElements()
{
	return this->MAP_Elements;
}

vector<Skill> Enemy::getSkills()
{
	return this->VEC_Skills;
}

Item* Enemy::getDroppedItem()
{
	return this->ITEM_Dropped_Item;
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

void Enemy::setElements(map<string, string> nElements)
{
	this->MAP_Elements = nElements;
}

string Enemy::getTurnPhrase()
{
	return this->STR_Turn_Phrase;
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
		if (this->getName() == "The Mastermind")
		{
			this->INT_Boss_Stat_Cycle++;
			if (this->INT_Boss_Stat_Cycle == 4)
			{
				this->INT_Boss_Stat_Cycle = 0;
				vector<string> VEC_Ailments = { "-", "Wk", "Rst", "Rpl", "Abs", "Nul" };
				vector<Skill> VEC_Skills_Available = { Skill("Flamadia"), Skill("Meflamadia"), Skill("Eye of the Sun"), Skill("Freezadia"), Skill("Mefreezadia"), Skill("Eye of the 'Berg"), Skill("Splashadia"), Skill("Mesplashadia"), Skill("Eye of the Ocean"), Skill("Zapadia"), Skill("Mezapadia"), Skill("Eye of the Spark"), Skill("Gustadia"), Skill("Megustadia"), Skill("Eye of the Storm"), Skill("Hexaon"), Skill("Mehexaon"), Skill("Blightaon"), Skill("Meblightaon"), Skill("Frei"), Skill("Freiladia"), Skill("Healan") };

				this->VEC_Skills = { };
				for (int i = 0; i < 8; i++)
				{
					VEC_Skills.push_back(VEC_Skills_Available[rand() % VEC_Skills_Available.size()]);
				}
				this->setElements({ {"Fire", VEC_Ailments[rand() % 6]},{"Water", VEC_Ailments[rand() % 6]},{"Ice", VEC_Ailments[rand() % 6]},{"Electric", VEC_Ailments[rand() % 6]},{"Wind", VEC_Ailments[rand() % 6]},{"Curse", VEC_Ailments[rand() % 6]}, { "Bless", VEC_Ailments[rand() % 6] } });
				this->STR_Turn_Phrase = "\n   The Mastermind is shifting their elemental coverage and magic attacks!";
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
							INT_Calculated_Damage = SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * FLT_Guard_Multiplier;
							this->STR_Turn_Phrase = "\n   " + this->STR_Name + " casted " + SKILL_Skill_Selected.getName() + " dealing " + to_string(INT_Calculated_Damage) + " damage ";
						}
						else if (PLAYER_Player.getElements().find(SKILL_Skill_Selected.getType())->second == "-")
						{
							INT_Calculated_Damage = SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * FLT_Guard_Multiplier;
							this->STR_Turn_Phrase = "\n   " + this->STR_Name + " casted " + SKILL_Skill_Selected.getName() + " dealing " + to_string(INT_Calculated_Damage) + " damage ";
						}
						else if (PLAYER_Player.getElements().find(SKILL_Skill_Selected.getType())->second == "Wk")
						{
							INT_Calculated_Damage = SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * FLT_Guard_Multiplier * 1.5;
							this->STR_Turn_Phrase = "\n   " + this->STR_Name + " casted " + SKILL_Skill_Selected.getName() + " dealing " + to_string(INT_Calculated_Damage) + " damage (WEAK) ";
						}
						else if (PLAYER_Player.getElements().find(SKILL_Skill_Selected.getType())->second == "Rst")
						{
							INT_Calculated_Damage = SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * FLT_Guard_Multiplier * 0.5;
							this->STR_Turn_Phrase = "\n   " + this->STR_Name + " casted " + SKILL_Skill_Selected.getName() + " dealing " + to_string(INT_Calculated_Damage) + " damage (RESIST) ";
						}
						else if (PLAYER_Player.getElements().find(SKILL_Skill_Selected.getType())->second == "Nul")
						{
							INT_Calculated_Damage = 0;
							this->STR_Turn_Phrase = "\n   " + this->STR_Name + " casted " + SKILL_Skill_Selected.getName() + " dealing " + to_string(INT_Calculated_Damage) + " damage (BLOCK) ";
						}
						if (this->getName() == "The Mastermind") INT_Calculated_Damage *= 1.25;
						PLAYER_Player.changeHealth(-INT_Calculated_Damage);
					}
					this->INT_Stamina -= SKILL_Skill_Selected.getStaminaCost();
				}
				else
				{
					INT_Calculated_Damage = this->getDamage() * FLT_Attribute_Multiplier * FLT_Guard_Multiplier;
					if (this->getName() == "The Mastermind") INT_Calculated_Damage *= 1.25;
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
