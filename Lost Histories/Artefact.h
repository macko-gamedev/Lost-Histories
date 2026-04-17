#pragma once
#include <iostream>
#include "Item.h"

using namespace std;

class Artefact : public Item
{
private:
public:
	Artefact();
	Artefact(string nName, string nDesc, int nRarity, string nType, int nValue);
	void toString() override;
};

