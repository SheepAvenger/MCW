#include "Equipment.h"



Equipment::Equipment()
{
	item = new Item;
	set_name();
	set_type();
	set_rarity();
	set_value();
	set_stats();
	set_attributes();
}


void Equipment::set_name()
{
	item->name = "";//TODO
}
string Equipment::get_name()
{
	return item->name;
}


void Equipment::set_type()
{
	int type = rand() % 3; //0-2
	item->type = (type == 0 ? "Gloves" : (type == 1 ? "Belt" : "Armour"));
}
string Equipment::get_type()
{
	return item->type;
}


void Equipment::set_rarity()
{
	//common, uncommon[40-70], rare[70-90], legendary[90-99]
	int rarity = rand() % 100; //0-99
	item->rarity = (rarity > 89 ? "Lengenday" : (rarity > 69 ? "Rare" : (rarity > 39 ? "Uncommon" : "Common")));
}
string Equipment::get_rarity()
{
	return item->rarity;
}


void Equipment::set_value()
{
	//TODO
}
int Equipment::get_value()
{

	return item->value;
}


void Equipment::set_stats()
{
	//TODO
}
void Equipment::print_stats()
{
	cout << "Strength: " << item->stats[STRENGTH] << endl;
	cout << "Speed: " << item->stats[SPEED] << endl;
	cout << "Durability: " << item->stats[DURABILITY] << endl;
	cout << "Energy: " << item->stats[ENERGY] << endl;
	cout << "Intelligence: " << item->stats[INTELLIGENCE] << endl;
	cout << "Combat Skill: " << item->stats[COMBAT_SKILL] << endl;

}


void Equipment::set_attributes()
{
	//TODO
}
void Equipment::print_attributes()
{
	//TODO
}
