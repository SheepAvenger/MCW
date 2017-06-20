#include "Mission.h"


Mission::Mission()
{
	mission_complete = false;
	rebuild = false;
	menu = false;
}

void Mission::set_rebuild(bool r)
{
	rebuild = r;
}

bool Mission::get_rebuild()
{
	return rebuild;
}

void Mission::add_event(string item)
{
	events.push_back(item);
}
void Mission::delete_event()
{
	events.pop_back();
}

void Mission::event_clear()
{
	events.clear();
}

int Mission::get_event_size()
{
	return events.size();
}

void Mission::add_event_m(string s)
{
	events_m.push_back(s);
}

void Mission::delete_event_m()
{
	events_m.pop_back();
}

int Mission::get_event_m_size()
{
	return events_m.size();
}

string Mission::get_event_m(int i)
{
	return events_m[i];
}

void Mission::event_m_clear()
{
	events_m.clear();
}

void Mission::mission_push(string s)
{
	missions.push_back(s);
}

void Mission::mission_pop()
{
	missions.pop_back();
}

int Mission::get_mission_size()
{
	return missions.size();
}

string Mission::get_mission(int i)
{
	return missions[i];
}

void Mission::mission_clear()
{
	missions.clear();
}

string Mission::get_mission_back()
{
	return missions.back();
}

void Mission::set_menu(bool m)
{
	menu = m;
}

bool Mission::get_menu()
{
	return menu;
}

void Mission::mission_stat(int c) /*check to see if you start a mission*/
{

	if (c == 1)
	{
		mission_stats = true;

	}
	else
	{
		mission_stats = false;

	}

};
bool Mission::get_mission_stat()
{
	return mission_stats;
}
void Mission::mission_run(int r) /*insures no other mission start while on a mission*/
{
	if (r == 1)
	{
		mission_runs = true;

	}
	else
	{
		mission_runs = false;

	}

};
bool Mission::get_mission_run()
{
	return mission_runs;
}

void Mission::set_mission_complete(bool m)
{
	mission_complete = m;
}

bool Mission::get_mission_complete()
{
	return mission_complete;
}
