#pragma once
#include <iostream>
#include <string>

using namespace std;

class Item
{
protected:
	string name;
	string desc;
	int rarity;
	int quantity;
public:
	Item();
	Item(string nName, string nDesc, int nRarity);
	virtual string toString();
	string getName();
	string getDesc();
	int getRarity();
	int getQuantity();
	void increaseQuantity();
};

