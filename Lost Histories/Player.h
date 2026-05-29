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
#include "Dungeon.h"

using namespace std;
class Dungeon;

class Player : public BattleStat
{
private:
	ItemMelee ITEM_MELEE_Equipped_Melee;
	string STR_Status;
	vector<string> VEC_Element_Names;
	vector<Skill> VEC_Skills;
	vector<Item*> VEC_Items;
	map<string, int> MAP_Player_Attributes;
	map<string, char> MAP_Stars_On_File;
	float FLT_Curr_EXP;
	float FLT_Next_EXP;
	float FLT_Melee_Attack_Multiplier;
	float FLT_Magic_Attack_Multiplier;
	int INT_Total_EXP;
	bool BOOL_Guard;
	bool BOOL_Level_Up;

public:
	Player();
	Player(string name, int level, int health, int stamina);
	ItemMelee getMeleeWeapon();
	string getStatus();
	vector<Skill> getSkills();
	void setSkills(vector<Skill> nSkills);
	void swapSkill(int INDEX_Skill, Skill SKILL_Skill);
	void setMelee(ItemMelee nMelee);
	vector<Item*> getItems();
	map<string, int> getPlayerAttributes();
	map<string, char> getStarsOnFile();
	int getNextEXP();
	int getCurrEXP();
	int getTotEXP();
	bool isGuard();
	bool isLevelUp();
	float getMeleeAttackMultiplier();
	float getMagicAttackMultiplier();
	void setLevelXP(int N_Tot, int N_Curr, int N_Next);
	void setMeleeAttackMultiplier(float N_VALUE);
	void setMagicAttackMultiplier(float N_VALUE);
	void setPlayerAttribute(string STR_Attribute, int N_VALUE);
	void setStartingElements();
	void setPlayerElement(string N_Element, string N_Ailment);
	void setStarsOnFile(map<string, char> N_File);
	void setSpecificStarOnFile(string N_Name, char N_Char);
	void notLevelUp();
	void increaseExp(float INT_Amount);
	void setGuard(bool BOOL_Guard_State);
	void getPlayerStats();
	void getPlayerElements();
	void addItem(Item* ITEM_Item);
	void setItems(vector<Item*> nItems);
	void showBattleStats();
	void loadData(vector<string> N_Data);
	vector<string> saveData(vector<Dungeon*> N_Visited_Dungeons);
	void update();
};

