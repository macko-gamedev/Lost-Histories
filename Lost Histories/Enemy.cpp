#include "Enemy.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Enemy::Enemy(string name, int level, int health, int stamina) : BattleStat(name, level, health, stamina)
{
	this->elements = { "-", "-", "-", "-", "-", "-" };
}

vector<string> Enemy::getElements()
{
	return this->elements;
}


void Enemy::takeDamage(int amount)
{
	this->health -= amount;
}
