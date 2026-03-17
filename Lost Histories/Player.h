#pragma once
#include <string>
#include <vector>
#include <map>
#include "Skill.h"
#include "Item.h"
#include "ItemSkill.h"
#include "ItemMelee.h"
#include "ItemConsumable.h"
#include "BattleStat.h"

using namespace std;

class Player : public BattleStat
{
private:
	ItemMelee ITEM_MELEE_Equipped_Melee;
	string STR_Status;
	string STR_Location;
	vector<string> VEC_Element_Names;
	vector<Skill> VEC_Skills;
	vector<Item*> VEC_Items;
	map<string, int> MAP_Player_Attributes;
	map<string, string> MAP_Elements;
	float FLT_Curr_EXP;
	float FLT_Next_EXP;
	int INT_Total_EXP;
	bool BOOL_Guard;
	bool BOOL_Level_Up;

public:
	Player(string name, int weak_element, int resist_element, int level, int health, int stamina);
	ItemMelee getMeleeWeapon();
	string getStatus();
	string getLocation();
	vector<Skill> getSkills();
	void setSkills(vector<Skill> nSkills);
	void setMelee(ItemMelee nMelee);
	vector<Item*> getItems();
	map<string, int> getPlayerAttributes();
	map<string, string> getElements();
	int getLevelStats();
	int getNextEXP();
	bool isGuard();
	bool isLevelUp();
	void setPlayerAttribute(string STR_Attribute, int N_VALUE);
	void notLevelUp();
	void increaseExp(float INT_Amount);
	void setGuard(bool BOOL_Guard_State);
	void getPlayerStats();
	void getPlayerElements();
	void addItem(Item* ITEM_Item);
	void setItems(vector<Item*> nItems);
	void update();
};

