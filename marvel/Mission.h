//#pragma once
#ifndef Mission_h
#define Mission_h
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Mission {
public:
	Mission();

	void set_rebuild(bool);
	bool get_rebuild();

	void add_event(string);
	void delete_event();
	void event_clear();
	int get_event_size();

	void add_event_m(string);
	void delete_event_m();
	int get_event_m_size();
	string get_event_m(int);
	void event_m_clear();


	void mission_push(string);
	void mission_pop();
	int get_mission_size();
	string get_mission(int);
	void mission_clear();
	string get_mission_back();

	void set_menu(bool);
	bool get_menu();

	void mission_stat(int);
	bool get_mission_stat();

	void mission_run(int);
	bool get_mission_run();

	void set_mission_complete(bool);
	bool get_mission_complete();

private:
	bool mission_complete;
	bool rebuild;
	bool mission_stats;
	bool mission_runs;
	bool menu;
	vector<string>events; //used to select and load a mission
	vector<string>missions; //used to hold mission that have not been completed
	vector<string>events_m; //used to hold current missions
};
#endif
