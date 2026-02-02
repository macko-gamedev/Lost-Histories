#include "Enemy.h"
#include "Player.h"

Enemy::Enemy() { }

Enemy::Enemy(string nName, int nLevel, int nHealth, int nStamina, vector<Skill> nSkills) : BattleStat(nName, nLevel, nHealth, nStamina)
{
	this->elements = { "-", "-", "-", "-", "-", "-" };
	this->skills = nSkills;
}

vector<string> Enemy::getElements()
{
	return this->elements;
}

vector<Skill> Enemy::getSkills()
{
	return this->skills;
}

bool Enemy::isAlive()
{
	return this->alive;
}

void Enemy::update(Player& player)
{
	//if (this->alive)
	//{
		system("CLS");
		if (this->state == battleState::WAITING)
		{
			cout << this->name << " is waiting...";
			this->state = battleState::ATTACKING;
		}
		else if (this->state == battleState::ATTACKING)
		{
			if (!this->skills.empty())
			{
				Skill useSkill = this->skills[rand() % (this->skills.size() - 1)];
				if (player.isGuard())
				{
					cout << this->name << " casted " << useSkill.getName() << " dealing " << to_string(int(useSkill.getBaseDamage() * 0.67)) << " damage" << endl;
					player.changeHealth(-(int(useSkill.getBaseDamage() * 0.67)));
				}
				else
				{
					cout << this->name << " casted " << useSkill.getName() << " dealing " << to_string(useSkill.getBaseDamage()) << " damage" << endl;
					player.changeHealth(-(useSkill.getBaseDamage()));
				}
				this->stamina -= useSkill.getStaminaCost();
			}
			else
			{

			}
			this->state = battleState::WAITING;
		}
	//}
}
