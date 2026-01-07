#include "Enemy.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Enemy::Enemy(string name, int level)
{
	this->name = name;
	this->level = level;
	this->health = 50 + (50 * this->level);
	this->stamina = 20 + (20 * this->level);
	this->elements = { "-", "-", "-", "-", "-", "-" };
}

string Enemy::getName()
{
	return this->name;
}

vector<string> Enemy::getElements()
{
	return this->elements;
}

int Enemy::getLevel()
{
	return this->level;
}

int Enemy::getHealth()
{
	return this->health;
}

int Enemy::getStamina()
{
	return this->stamina;
}

void Enemy::takeDamage(int amount)
{
	this->health -= amount;
}
