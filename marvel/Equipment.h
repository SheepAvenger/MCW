#pragma once
#ifndef EQUIP_h
#define EQUIP_h
#include <iostream>
#include <string>
using namespace std;

class Equipment
{
private:
	struct Item {
		string type;
		string rarity;
		string name;
		string setName;
		int level;
		int rank;
		int value;
		int stats[6];
		int attributes[9];
	};
	const string Lnames[25] = { "Lock Jaw", "Deadpool", "Howard the Duck", "Dr. Strange", "Hawkeye"
						"Ghost Rider", "Johnny Storm", "Sue Storm", "Phil Coulson", "Moon Knight"
						"Squirl Girl", "Spider-Woman", "Nightcralwer", "Star Lord", "Rocket Raccon"
						"Drax", "Gamora", "Groot", "Yondu", "Ronan" };

	const string Rnames[25] = { "a", "b", "c", "d", "e"
		"f", "g", "h", "i", "j"
		"j", "k", "l", "m", "n"
		"o", "p", "q", "r", "s" };// Place holders

	Item* item;
	void set_type();
	void set_rarity(bool);
	void set_name();
	void set_value();
	void set_stats(int, string);
	void set_attributes(int, string, string);
	void set_level(int);
public:
	Equipment(int, string, bool);
	Equipment(string, string, string, int, int, int[6], int[9]);
	string get_type();
	string get_rarity();
	string get_name();
	string get_setName();
	int get_value();
	int get_stats(int);
	int get_attribute(int);
	int get_level();
	void print_stats();
	void print_attributes(string);
	void print(string);
};


#endif
