#include "Equipment.h"
#include "Enum.h"



Equipment::Equipment(int lvl, string p_name)
{
	item = new Item;
	set_name();
	set_type();
	set_rarity();
	set_value();
	set_stats(lvl);
	set_attributes(lvl, p_name);
}
//For special Boss equipment
Equipment::Equipment(string name, string type, string rarity, int value, int stats[6], int attributes[9])
{
	item = new Item;
	item->name = name;
	item->type = type;
	item->rarity = rarity;
	item->value = value;
	for (int i = 0; i < 9; i++)
	{
		if(i < 6) item->stats[i] = stats[i];
		item->attributes[i] = attributes[i];
	}
}


void Equipment::set_name()
{
	//TODO
	item->name = "item";//place holder
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
	item->value = 0; //place holder
}
int Equipment::get_value()
{

	return item->value;
}


void Equipment::set_stats(int lvl)
{
	//TODO
	for (int i = 0; i < 6; i++)
		item->stats[i] = rand() % lvl;
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


void Equipment::set_attributes(int lvl, string p_name)
{
	//TODO
	for (int i = 0; i < 9; i++)
		item->stats[i] = rand() % lvl;
}
void Equipment::print_attributes(string p_name)
{
	cout << "Bleed Damage: " << item->attributes[BLEED_DMG] << endl;
	cout << "Defence: " << item->attributes[DEFENCE] << endl;
	cout << "Damage: " << item->attributes[DAMAGE] << endl;
	cout << "Evade: " << item->attributes[EVADE] << endl;
	cout << "Experience: " << item->attributes[EXP] << endl;
	cout << "Health: " << item->attributes[HEALTH] << endl;
	if(p_name == "Wolverine") cout << "Regeneration: " << item->attributes[REGEN] << endl;
	if(p_name == "Iron Man" || p_name == "Mr. Fantastic") cout << "Damage Reduction: " << item->attributes[REDUCE] << endl;
	if(p_name == "Spiderman") cout << "Web Strength: " << item->attributes[WEB_STR] << endl;

}
