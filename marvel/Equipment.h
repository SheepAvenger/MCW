#pragma once
#ifndef EQUIP_h
#define EQUIP_h
#include <iostream>
#include <string>
using namespace std;

/*struct Item {
	string name;
	int value;
	int stats[6];
	int attributes[9];
};*/

class Equipment
{
private:
	enum STATS{STRENGTH, SPEED, DURABILITY, ENERGY, INTELLIGENCE, COMBAT_SKILL};
	struct Item {
		string type;
		string rarity;
		string name;
		int value;
		int stats[6];
		int attributes[9];
	};
	Item* item;
	void set_type();
	void set_rarity();
	void set_name();
	void set_value();
	void set_stats();
	void set_attributes();
public:
	Equipment();
	string get_type();
	string get_rarity();
	string get_name();
	int get_value();
	void print_stats();
	void print_attributes();
};


#endif
