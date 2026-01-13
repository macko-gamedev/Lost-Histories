#pragma once
#include <string>
#include <vector>
#include "BattleStat.h"

using namespace std;

class Enemy : public BattleStat
{
private:
	vector<string> elements;
public:
	Enemy(string name, int level, int health, int stamina);
	vector<string> getElements();
	void takeDamage(int amount);
};