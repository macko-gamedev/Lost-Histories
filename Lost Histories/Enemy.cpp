#include "Enemy.h"

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
