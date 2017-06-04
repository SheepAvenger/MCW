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
	void set_stats(int);
	void set_attributes(int, string);
public:
	Equipment(int, string);
	Equipment(string, string, string, int, int[6], int[9]);
	string get_type();
	string get_rarity();
	string get_name();
	int get_value();
	void print_stats();
	void print_attributes(string);
};


#endif
