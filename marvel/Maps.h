#pragma once
#ifndef Map_h
#define Map_h
#include <vector>
#include <iostream>
#include <string>
#include "Mission.h"
using namespace std;

class player;

class Map
{
public:
	Map();
	void generate_map();
	void set_player(int x, int y);
	int get_playerx();
	int get_playery();
	void set_city(string i);
	string get_city();
	void set_c_city(player* h);
	string get_map_spot(int x, int y);
	void set_city_travel(string c);
	int get_length();
	void clear_map();
	void num_people(player* h);
	void set_people(int p);
	int get_people();
	void saved_people_push(string);
	int get_saved_people_size();
	void saved_people_clear();
	vector<string>citys;

private:
	Mission* mission;
	int people;
	int map_height;
	int map_length;
	int change_h();
	int change_l();
	const static int player_xy = 2;
	vector<vector<string>> the_path;// normal map
	vector<vector<string>> m_the_path;// mission map
	vector <string> saved_people; //possible use for the sewer levels
	int p_pos[player_xy];
	string city;
	string c_city;
};

#endif
