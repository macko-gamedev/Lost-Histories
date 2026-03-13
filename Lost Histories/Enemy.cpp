#include "player.h"
#include "Enemy.h"
#include <ctime>
#include <cstdlib>

Enemy::Enemy() { }

Enemy::Enemy(string nName, int nLevel, int nHealth, int nStamina, vector<Skill> nSkills, Item* nDroppedItem, bool nBoss, int nDamage) : BattleStat(nName, nLevel, nHealth, nStamina)
{
	this->elements = { "-", "-", "-", "-", "-", "-" };
	this->skills = nSkills;
	this->droppedItem = nDroppedItem;
	this->boss = nBoss;
	this->damage = nDamage;
}

vector<string> Enemy::getElements()
{
	return this->elements;
}

vector<Skill> Enemy::getSkills()
{
	return this->skills;
}

Item* Enemy::getDroppedItem()
{
	return this->droppedItem;
}

bool Enemy::isAlive()
{
	return this->alive;
}

bool Enemy::isBoss()
{
	return this->boss;
}

int Enemy::getDamage()
{
	return this->damage;
}

void Enemy::setHealth()
{
	this->health = int(float(this->health) * ((float(level) / 10) + 1));
	this->max_health = this->health;
}

void Enemy::setElements(vector<string> nElements)
{
	this->elements = nElements;
}

string Enemy::getTurnPhrase()
{
	return this->turnPhrase;
}

void Enemy::update(Player& player)
{
	srand(time(0));
	vector<string> waitingPhases = { (this->name + " is waiting..."), (this->name + " is staring at you intensly..."),  (this->name + " is planning their next move...") };
	if (this->isBoss() == false)
	{
		this->state = battleState::ATTACKING;
	}
	
	if (this->state == battleState::WAITING)
	{
		this->turnPhrase = "\n   " + waitingPhases[rand() % 3];
		this->state = battleState::ATTACKING;
	}
	else if (this->state == battleState::ATTACKING)
	{
		if (!this->skills.empty())
		{
			Skill useSkill;
			useSkill = this->skills[(rand() % this->skills.size())];
			float guardMultiplier;
			if (player.isGuard())
			{
				guardMultiplier = 0.67;
			}
			else
			{
				guardMultiplier = 1;
			}

			int skillChance = (rand() % 10) + 1;
			if (this->getStamina() >= useSkill.getStaminaCost() && skillChance > 3)
			{
				if (useSkill.getType() == "fire")
				{
					if (player.getElements()[0] == "Wk")
					{
						if (player.isGuard())
						{
							this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * guardMultiplier)) + " damage";
							player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
						}
						else
						{
							this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * 1.5 * guardMultiplier)) + " damage (WEAK)";
							player.changeHealth(-int(useSkill.getBaseDamage() * 1.5 * guardMultiplier));
						}

					}
					else if (player.getElements()[0] == "Rst")
					{
						this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * 0.5 * guardMultiplier)) + " damage (RESIST)";
						player.changeHealth(-int(useSkill.getBaseDamage() * 0.5 * guardMultiplier));
					}
					else
					{
						this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * guardMultiplier)) + " damage";
						player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
					}
				}
				else if (useSkill.getType() == "ice")
				{
					if (player.getElements()[1] == "Wk")
					{
						if (player.isGuard())
						{
							this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * guardMultiplier)) + " damage";
							player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
						}
						else
						{
							this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * 1.5 * guardMultiplier)) + " damage (WEAK)";
							player.changeHealth(-int(useSkill.getBaseDamage() * 1.5 * guardMultiplier));
						}
					}
					else if (player.getElements()[1] == "Rst")
					{
						this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * 0.5 * guardMultiplier)) + " damage (RESIST)";
						player.changeHealth(-int(useSkill.getBaseDamage() * 0.5 * guardMultiplier));
					}
					else
					{
						this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * guardMultiplier)) + " damage";
						player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
					}
				}
				else if (useSkill.getType() == "electric")
				{
					if (player.getElements()[2] == "Wk")
					{
						if (player.isGuard())
						{
							this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * guardMultiplier)) + " damage";
							player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
						}
						else
						{
							this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * 1.5 * guardMultiplier)) + " damage (WEAK)";
							player.changeHealth(-int(useSkill.getBaseDamage() * 1.5 * guardMultiplier));
						}
					}
					else if (player.getElements()[2] == "Rst")
					{
						this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * 0.5 * guardMultiplier)) + " damage (RESIST)";
						player.changeHealth(-int(useSkill.getBaseDamage() * 0.5 * guardMultiplier));
					}
					else
					{
						this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * guardMultiplier)) + " damage";
						player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
					}
				}
				else if (useSkill.getType() == "wind")
				{
					if (player.getElements()[3] == "Wk")
					{
						if (player.isGuard())
						{
							this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * guardMultiplier)) + " damage";
							player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
						}
						else
						{
							this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * 1.5 * guardMultiplier)) + " damage (WEAK)";
							player.changeHealth(-int(useSkill.getBaseDamage() * 1.5 * guardMultiplier));
						}
					}
					else if (player.getElements()[3] == "Rst")
					{
						this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * 0.5 * guardMultiplier)) + " damage (RESIST)";
						player.changeHealth(-int(useSkill.getBaseDamage() * 0.5 * guardMultiplier));
					}
					else
					{
						this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * guardMultiplier)) + " damage";
						player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
					}
				}
				else if (useSkill.getType() == "curse")
				{
					if (player.getElements()[4] == "Wk")
					{
						if (player.isGuard())
						{
							this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * guardMultiplier)) + " damage";
							player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
						}
						else
						{
							this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * 1.5 * guardMultiplier)) + " damage (WEAK)";
							player.changeHealth(-int(useSkill.getBaseDamage() * 1.5 * guardMultiplier));
						}
					}
					else if (player.getElements()[4] == "Rst")
					{
						this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * 0.5 * guardMultiplier)) + " damage (RESIST)";
						player.changeHealth(-int(useSkill.getBaseDamage() * 0.5 * guardMultiplier));
					}
					else
					{
						this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * guardMultiplier)) + " damage";
						player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
					}
				}
				else if (useSkill.getType() == "bless")
				{
					if (player.getElements()[5] == "Wk")
					{
						if (player.isGuard())
						{
							this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * guardMultiplier)) + " damage";
							player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
						}
						else
						{
							this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * 1.5 * guardMultiplier)) + " damage (WEAK)";
							player.changeHealth(-int(useSkill.getBaseDamage() * 1.5 * guardMultiplier));
						}
					}
					else if (player.getElements()[5] == "Rst")
					{
						this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * 0.5 * guardMultiplier)) + " damage (RESIST)";
						player.changeHealth(-int(useSkill.getBaseDamage() * 0.5 * guardMultiplier));
					}
					else
					{
						this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * guardMultiplier)) + " damage";
						player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
					}
				}
				else if (useSkill.getType() == "nuclear")
				{
					this->turnPhrase = "\n   " + this->name + " casted " + useSkill.getName() + " dealing " + to_string(int(useSkill.getBaseDamage() * guardMultiplier)) + " damage";
					player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
				}
				this->stamina -= useSkill.getStaminaCost();
			}
			else
			{
				this->turnPhrase = "\n   " + this->name + " attacked you dealing " + to_string(int(this->getDamage() * guardMultiplier)) + " damage";
				player.changeHealth(-int(this->getDamage() * guardMultiplier));
			}
		}
		this->state = battleState::WAITING;
	}
}
