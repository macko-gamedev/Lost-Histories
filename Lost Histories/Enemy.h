#pragma once
#include <string>
#include <vector>

using namespace std;

class Enemy
{
private:
	string name;
	vector<string> elements;
	int level;
	int health;
	int stamina;
public:
	Enemy(string name, int level);
	string getName();
	vector<string> getElements();
	int getLevel();
	int getHealth();
	int getStamina();
	void takeDamage(int amount);
};