#ifndef enemies_h
#define enemies_h
#include <iostream>
#include <string>
#include "Equipment.h"
using namespace std;


class player;
class enemies
{
public:
	//constructors
	enemies();
	enemies(const enemies &obj);

	//selecting enemies
	void set_enemies(string n, player* hero);
	string get_enemies();

	void set_enum(string h);
	int get_enum();

	//stats
	void set_strenght(int i, player* hero);
	int get_strength();

	void set_speed(int i);
	int get_speed();

	void set_durability(int i, player* hero);
	int get_durability();

	void set_Cskill(int i, player* hero);
	int get_Cskill();

	void set_energy(int i, player* hero);
	int get_energy();

	void set_intelligence(int i, player* hero);
	int get_intelligence();

	//attributes
	void set_health(int i);
	int get_health();

	void set_experience();
	int get_experience();

	void set_level(player* h);
	int get_level();

	void set_weapon();
	string get_weapon();

	void set_defense(int i);
	int get_defense();
	void reset_defense();

	void set_reputation();
	double get_reputation();

	void set_power(string s);
	string get_power();

	void max_health(int i);
	int get_max();

	void set_boss();
	bool get_boss();

	void set_villian();
	bool get_villian();

	void reset_rnd();

	//selects attack
	void set_attack(player* h, enemies* e);
	int get_attack();

	//special abilities
	void set_regen();
	int get_regen();

	void set_reduce();
	int get_reduce();

	int get_bleed();
	void set_rage(int i);
	int get_rage();

	void set_web_str(int i);
	int get_web_str();

	//chance to dodge
	void set_evade();
	int get_evade();

	//determine if an enemies is incompactitated
	void set_defense_mod(int i);
	bool get_defense_mod();

	//for bleeding powers
	void set_bleeding(); //check to see if a hero is bleeding
	bool get_bleeding(); 
	void set_bleed_dmg(int i); // set the bleed damage
	int get_bleed_dmg();

	//for ice power
	void set_ice(int i);
	int get_ice();

	//nitro stat for powderkeg
	void set_nitro(int i);
	int get_nitro();

	//Generate Equipment
	void set_item(string);
	Equipment** get_item();

	//fighting turns
	void set_turn(bool);
	bool check_turn();


private:
	//Items
	Equipment* items[6];
	
	//strings
	string e_power;
	string name;
	string weapon;

	//int
	int bleed;
	int bleed_dmg;
	int e_attack;
	int e_defe;
	int e_dmg;
	int e_dur;
	int e_energy;
	int e_exp;
	int e_hlth;
	int e_intell;
	int e_lvl;
	int e_skill;
	int e_spd;
	int e_str;
	int evade;
	int ice_str;
	int max;
	int number_enemies;
	int rage;
	int nitro;
	int reduce;
	int regen;
	int rnd_defe;
	int web_str;
	int int_name;

	//bool
	bool bleeding;
	bool evades;
	bool ko;
	bool is_boss;
	bool is_villian;
	bool is_turn;
	
	//double
	double rep;	
};

#endif
