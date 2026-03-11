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

void Enemy::update(Player& player)
{
	system("CLS");
	srand(time(0));
	vector<string> waitingPhases = { (this->name + " is waiting..."), (this->name + " is staring at you intensly..."),  (this->name + " is planning their next move...") };
	if (this->isBoss() == false)
	{
		this->state = battleState::ATTACKING;
	}
	
	if (this->state == battleState::WAITING)
	{
		cout << "\n   " << waitingPhases[rand() % 2];
		this->state = battleState::ATTACKING;
	}
	else if (this->state == battleState::ATTACKING)
	{
		if (!this->skills.empty())
		{
			Skill useSkill;
			if (this->skills.size() == 1)
			{
				useSkill = this->skills[0];
			}
			else
			{
				useSkill = this->skills[(rand() % this->skills.size())];
			}
			//
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
							cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * guardMultiplier) << " damage" << endl;
							player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
						}
						else
						{
							cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * 1.5 * guardMultiplier) << " damage (WEAK)" << endl;
							player.changeHealth(-int(useSkill.getBaseDamage() * 1.5 * guardMultiplier));
						}

					}
					else if (player.getElements()[0] == "Rst")
					{
						cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * 0.5 * guardMultiplier) << " damage (RESIST)" << endl;
						player.changeHealth(-int(useSkill.getBaseDamage() * 0.5 * guardMultiplier));
					}
					else
					{
						cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * guardMultiplier) << " damage" << endl;
						player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
					}
				}
				else if (useSkill.getType() == "ice")
				{
					if (player.getElements()[1] == "Wk")
					{
						if (player.isGuard())
						{
							cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * guardMultiplier) << " damage" << endl;
							player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
						}
						else
						{
							cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * 1.5 * guardMultiplier) << " damage (WEAK)" << endl;
							player.changeHealth(-int(useSkill.getBaseDamage() * 1.5 * guardMultiplier));
						}
					}
					else if (player.getElements()[1] == "Rst")
					{
						cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * 0.5 * guardMultiplier) << " damage (RESIST)" << endl;
						player.changeHealth(-int(useSkill.getBaseDamage() * 0.5 * guardMultiplier));
					}
					else
					{
						cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * guardMultiplier) << " damage" << endl;
						player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
					}
				}
				else if (useSkill.getType() == "electric")
				{
					if (player.getElements()[2] == "Wk")
					{
						if (player.isGuard())
						{
							cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * guardMultiplier) << " damage" << endl;
							player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
						}
						else
						{
							cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * 1.5 * guardMultiplier) << " damage (WEAK)" << endl;
							player.changeHealth(-int(useSkill.getBaseDamage() * 1.5 * guardMultiplier));
						}
					}
					else if (player.getElements()[2] == "Rst")
					{
						cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * 0.5 * guardMultiplier) << " damage (RESIST)" << endl;
						player.changeHealth(-int(useSkill.getBaseDamage() * 0.5 * guardMultiplier));
					}
					else
					{
						cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * guardMultiplier) << " damage" << endl;
						player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
					}
				}
				else if (useSkill.getType() == "wind")
				{
					if (player.getElements()[3] == "Wk")
					{
						if (player.isGuard())
						{
							cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * guardMultiplier) << " damage" << endl;
							player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
						}
						else
						{
							cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * 1.5 * guardMultiplier) << " damage (WEAK)" << endl;
							player.changeHealth(-int(useSkill.getBaseDamage() * 1.5 * guardMultiplier));
						}
					}
					else if (player.getElements()[3] == "Rst")
					{
						cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * 0.5 * guardMultiplier) << " damage (RESIST)" << endl;
						player.changeHealth(-int(useSkill.getBaseDamage() * 0.5 * guardMultiplier));
					}
					else
					{
						cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * guardMultiplier) << " damage" << endl;
						player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
					}
				}
				else if (useSkill.getType() == "curse")
				{
					if (player.getElements()[4] == "Wk")
					{
						if (player.isGuard())
						{
							cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * guardMultiplier) << " damage" << endl;
							player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
						}
						else
						{
							cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * 1.5 * guardMultiplier) << " damage (WEAK)" << endl;
							player.changeHealth(-int(useSkill.getBaseDamage() * 1.5 * guardMultiplier));
						}
					}
					else if (player.getElements()[4] == "Rst")
					{
						cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * 0.5 * guardMultiplier) << " damage (RESIST)" << endl;
						player.changeHealth(-int(useSkill.getBaseDamage() * 0.5 * guardMultiplier));
					}
					else
					{
						cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * guardMultiplier) << " damage" << endl;
						player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
					}
				}
				else if (useSkill.getType() == "bless")
				{
					if (player.getElements()[5] == "Wk")
					{
						if (player.isGuard())
						{
							cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * guardMultiplier) << " damage" << endl;
							player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
						}
						else
						{
							cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * 1.5 * guardMultiplier) << " damage (WEAK)" << endl;
							player.changeHealth(-int(useSkill.getBaseDamage() * 1.5 * guardMultiplier));
						}
					}
					else if (player.getElements()[5] == "Rst")
					{
						cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * 0.5 * guardMultiplier) << " damage (RESIST)" << endl;
						player.changeHealth(-int(useSkill.getBaseDamage() * 0.5 * guardMultiplier));
					}
					else
					{
						cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << int(useSkill.getBaseDamage() * guardMultiplier) << " damage" << endl;
						player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
					}
				}
				else if (useSkill.getType() == "nuclear")
				{
					cout << "\n   " << this->name << " casted " << useSkill.getName() << " dealing " << to_string(useSkill.getBaseDamage() * guardMultiplier) << " damage" << endl;
					player.changeHealth(-int(useSkill.getBaseDamage() * guardMultiplier));
				}
				this->stamina -= useSkill.getStaminaCost();
			}
			else
			{
				cout << "\n   " << this->name << " attacked you dealing " << int(this->getDamage() * guardMultiplier) << " damage" << endl;
				player.changeHealth(-int(this->getDamage() * guardMultiplier));
			}
		}
		this->state = battleState::WAITING;
	}
}
