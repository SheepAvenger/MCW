#ifndef Hero_h
#define Hero_h
#include <iostream>
#include <string>
using namespace std;

class enemies;

class player
{
public:
	//constructors
	player();

	//stats
	void set_hero(string o);
	string get_hero();

	void set_strenght(int s);
	int get_strength();

	void set_speed(int i);
	int get_speed();

	void set_durability(int s);
	int get_durability();

	void set_Cskill(int s);
	int get_Cskill();

	void set_energy(int i);
	int get_energy();

	void set_intelligence(int i);
	int get_intelligence();

	void set_health(int i);
	int get_health();

	void set_experience(int s); // how much the player needs
	int get_experience();

	void set_current_experience(enemies* h, int s); //how much the player has
	int get_current_experience();

	void set_defense(int i);
	int get_defense();
	void reset_defense();

	void set_level(int s);
	int get_level();

	void set_reputation(double i);
	double get_reputation();

	void max_hlth();
	int get_max();

	void set_registration(string h);
	string get_registration();

	//attacks and powers
	void set_attack(enemies* h, player* p);
	int get_attack();
	string get_power();
	void set_conditon(enemies* h);

	//abilities
	void set_regen();
	int get_regen();

	void set_reduce();
	int get_reduce();

	void set_bleed_dmg(int i);
	int get_bleed_dmg();
	int get_bleed();

	void set_web_strength(int i);
	int get_web_strength();

	void set_evade();
	int get_evade();

	//determines if a hero is able to fight
	void set_defense_mod(int i, string h, int ice);
	bool get_defense_mod();

	//output stats
	void print_stat();

private:
	//strings
	string hero;
	string power;
	string reg;

	//int
	int attack;
	int bleed;
	int bleed_dmg;
	int Cexp;
	int defe;
	int dmg;
	int dur;
	int energy;
	int evade;
	int exp;
	int hlth;
	int intell;
	int lvl;
	int max;
	int regen;
	int reduce;
	int rnd_defe;
	int skill;
	int str;
	int spd;
	int web_str;
	

	//bool
	bool ko;

	//double
	double rep;
};

#endif