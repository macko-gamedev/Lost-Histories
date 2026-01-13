#pragma once
#include <iostream>

using namespace std;

class Item
{
protected:
	string name;
	string desc;
	int rarity;
public:
	Item();
	Item(string nName, string nDesc, int nRarity);
	virtual string toString();
	string getName();
	string getDesc();
	int getRarity();
};

