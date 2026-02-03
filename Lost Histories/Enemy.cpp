#include "Enemy.h"
#include "Player.h"

Enemy::Enemy() { }

Enemy::Enemy(string nName, int nLevel, int nHealth, int nStamina, vector<Skill> nSkills, ItemSkill nDroppedItem) : BattleStat(nName, nLevel, nHealth, nStamina)
{
	this->elements = { "-", "-", "-", "-", "-", "-" };
	this->skills = nSkills;
	this->droppedItem = nDroppedItem;
}

vector<string> Enemy::getElements()
{
	return this->elements;
}

vector<Skill> Enemy::getSkills()
{
	return this->skills;
}

ItemSkill Enemy::getDroppedItem()
{
	return this->droppedItem;
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
				Skill useSkill;
				if (this->skills.size() == 1)
				{
					useSkill = this->skills[0];
				}
				else
				{
					useSkill = this->skills[rand() % (this->skills.size() - 1)];
				}

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
				cout << this->name << " attacked you dealing _(not set yet)_ damage" << endl;
			}
			this->state = battleState::WAITING;
		}
	//}
}
