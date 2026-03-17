#include "Player.h"
#include "Enemy.h"
#include <ctime>
#include <cstdlib>

Enemy::Enemy() { }

Enemy::Enemy(string nName, int nLevel, int nHealth, int nStamina, vector<Skill> nSkills, Item* nDroppedItem, bool nBoss, int nDamage) : BattleStat(nName, nLevel, nHealth, nStamina)
{
	this->MAP_Elements = { {"Fire", "-"}, {"Ice", "-"}, {"Electric", "-"}, {"Wind", "-"}, {"Curse", "-"}, {"Bless", "-"} };
	this->VEC_Skills = nSkills;
	this->ITEM_Dropped_Item = nDroppedItem;
	this->BOOL_Boss = nBoss;
	this->INT_Damage = nDamage;
}

map<string, string>  Enemy::getElements()
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
	this->health = int(float(this->health) * ((float(level) / 10) + 1));
	this->max_health = this->health;
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
	vector<string> VEC_Waiting_Phases = { (this->name + " is waiting..."), (this->name + " is staring at you intensly..."),  (this->name + " is planning their next move...") };
	if (this->isBoss() == false)
	{
		this->ENUM_State = battleState::ATTACKING;
	}
	
	if (this->ENUM_State == battleState::WAITING)
	{
		this->STR_Turn_Phrase = "\n   " + VEC_Waiting_Phases[rand() % 3];
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
				float FLT_Attribute_Multiplier = 1 - (float(PLAYER_Player.getPlayerAttributes().find("Endurnace")->second) / 100); // Player Attribute "Magic" Multiplier
				float FLT_Guard_Multiplier;
				if (PLAYER_Player.isGuard())
				{
					FLT_Guard_Multiplier = 0.67;
				}
				else
				{
					FLT_Guard_Multiplier = 1;
				}

				int INT_Skill_Chance = (rand() % 10) + 1;
				if (this->getStamina() >= SKILL_Skill_Selected.getStaminaCost() && INT_Skill_Chance > 3)
				{
					if (true)
					{
						if (PLAYER_Player.getElements().find(SKILL_Skill_Selected.getType())->second == "-")
						{
							INT_Calculated_Damage = SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * FLT_Guard_Multiplier;
							this->STR_Turn_Phrase = "\n   " + this->name + " casted " + SKILL_Skill_Selected.getName() + " dealing " + to_string(INT_Calculated_Damage) + " INT_Damage";
						}
						else if (PLAYER_Player.getElements().find(SKILL_Skill_Selected.getType())->second == "Wk")
						{
							INT_Calculated_Damage = SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * FLT_Guard_Multiplier * 1.5;
							this->STR_Turn_Phrase = "\n   " + this->name + " casted " + SKILL_Skill_Selected.getName() + " dealing " + to_string(INT_Calculated_Damage) + " INT_Damage (WEAK)";
						}
						else if (PLAYER_Player.getElements().find(SKILL_Skill_Selected.getType())->second == "Rst")
						{
							INT_Calculated_Damage = SKILL_Skill_Selected.getBaseDamage() * FLT_Attribute_Multiplier * FLT_Guard_Multiplier * 0.5;
							this->STR_Turn_Phrase = "\n   " + this->name + " casted " + SKILL_Skill_Selected.getName() + " dealing " + to_string(INT_Calculated_Damage) + " INT_Damage (RESIST)";
						}
						else if (PLAYER_Player.getElements().find(SKILL_Skill_Selected.getType())->second == "Nul")
						{
							INT_Calculated_Damage = 0;
							this->STR_Turn_Phrase = "\n   " + this->name + " casted " + SKILL_Skill_Selected.getName() + " dealing " + to_string(INT_Calculated_Damage) + " INT_Damage (BLOCK)";
						}
					}
					this->stamina -= SKILL_Skill_Selected.getStaminaCost();
				}
				else
				{
					INT_Calculated_Damage = this->getDamage() * FLT_Attribute_Multiplier * FLT_Guard_Multiplier;
					this->STR_Turn_Phrase = "\n   " + this->name + " attacked you dealing " + to_string(INT_Calculated_Damage) + " INT_Damage";
				}
				PLAYER_Player.changeHealth(-INT_Calculated_Damage);
			}
		}
		else
		{
			this->STR_Turn_Phrase = "\n   " + this->name + " missed their attack!";
		}
		this->ENUM_State = battleState::WAITING;
	}
}
