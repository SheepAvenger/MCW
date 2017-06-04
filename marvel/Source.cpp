#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <time.h>
#include <random>
#include <windows.h>
#include<fstream>
#include "Hero.h"
#include "enemies.h"
#include "Enum.h"

using namespace std;

bool loaded = false;

//explosions
bool explosion = false;
vector <string> explosion_victim; // used to see when a person will explode
int count_down = 0; // used to see if a peron will explode

vector <string> saved_people; //possible use for the sewer levels

//characters
vector<enemies*>group; //hold the enemies
vector<player*> team; // hold the player
vector<string>die; // hold dead heros
vector<string>v_die; // hold dead villians
vector<string>mission_vill;

//missions
bool mission_complete = false;
bool rebuild = false;
bool mission_stats;
bool mission_runs;
bool menu = false;
vector<string>events; //used to select and load a mission
vector<string>missions; //used to hold mission that have not been completed
vector<string>events_m; //used to hold current missions

//used to offset player added stat increases
int pp_strength = 0;
int pp_speed = 0;
int pp_durability = 0;
int pp_Cskill = 0;
int pp_energy = 0;
int pp_intelligence = 0;

//map
int people = 0;
vector<string>city; //holds the map
int map_height = 6;
int map_length = 15;
const int player_xy = 2;

//options
vector<string>options; //used to make sure no event is trigged when a player selects the options menue.


void mission_stat(int c) /*check to see if you start a mission*/
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
bool get_mission_stat()
{
	return mission_stats;
}
void mission_run(int r) /*insures no other mission start while on a mission*/
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
bool get_mission_run()
{
	return mission_runs;
}
int change_h()//change map height
{
	
	int ran_map = rand() % 10;
	if (ran_map <= 6)
	{
		map_height = 6;
	}
	else
	{
		map_height = ran_map;

	}
	//map_di.push_back(map_height);

	return (map_height);
}
int change_l()//change the map length
{
	
	int ran_map = rand() % 20;
	if (ran_map == 0)
	{
		map_length = 5;
	}
	else if (ran_map == 1)
	{
		map_length = ran_map + 4;
	}
	else if (ran_map == 2)
	{
		map_length = ran_map + 3;
	}
	else if (ran_map == 3)
	{
		map_length = ran_map + 2;
	}
	else if (ran_map == 4)
	{
		map_length = ran_map + 1;
	}
	else
	{
		map_length = ran_map;

	}
	/*while (map_di.size() > 2)
	{
		map_di.pop_back();
	}
	map_di.push_back(map_length);*/
	return (map_length);
}
char selection(char i)// user input with out pressing enter
{
	i = _getch();

	return i;
}

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

private:
	vector<vector<string>> the_path;// normal map
	vector<vector<string>> m_the_path;// mission map
	int p_pos[player_xy];
	string city;
	string c_city;
};

Map::Map()
{
	p_pos[0] = 0;
	p_pos[1] = 2;
	string city = "";
	string c_city = "";
	
	int path_offset[] = { 2, 2, 2 };
	int num_cities = 0;
	int rand_int = 0;
	if (events.size() > 0)
	{
		/*while (m_the_path.size() > 0)
		{
			m_the_path.pop_back();
		}*/
		m_the_path.resize(map_length = (change_l() + 1), vector<string>(map_height = (change_h() + 1)));

		for (int x = 0; x < map_length; x++)
		{
			for (int y = 0; y < map_height; y++)
			{
				rand_int = rand() % 5;

				if (x == map_length - 1)
				{

					m_the_path[x][y] = ">";

				}
				else if (x == 0 && y == 2)
				{
					m_the_path[x][y] = "|";
					num_cities++;
				}
				else if (((x > 0 && x < 7 && rand_int == 0) || x == 7) && (num_cities == 1 && y == 2))
				{
					m_the_path[x][y] = "|";
					num_cities++;
					path_offset[0] = 1;
					path_offset[1] = 3;
					path_offset[2] = 10;
				}
				else if (((x > 10 && x < 17 && rand_int == 0) || x == 17) && (num_cities == 2 && (y == path_offset[0] || y == path_offset[1] || y == path_offset[2])))
				{
					m_the_path[x][y] = "|";
					num_cities++;
					path_offset[0] = 0;
					path_offset[1] = 2;
					path_offset[2] = 3;
				}
				else if (((x > 10 && x < 17 && rand_int == 0) || x == 17) && (num_cities == 3 && y == 3))
				{
					m_the_path[x][y] = "|";
					num_cities++;
					path_offset[0] = 0;
					path_offset[1] = 2;
					path_offset[2] = 4;
				}
				else if ((y == path_offset[0] || y == path_offset[1] || y == path_offset[2]))
				{
					for (size_t i = 0; i < 3; i++)
					{
						if (path_offset[i] != 10)
						{
							m_the_path[x][y] = "=";
							continue;
						}
						if ((m_the_path[x][y - 1] == "= ") || m_the_path[x][y - 1] == " =")
						{
							m_the_path[x][y] = "|";
						}
						if (m_the_path[x][y + 1] == " =" || m_the_path[x][y + 1] == "= ")
						{
							m_the_path[x][y] = "|";
						}
						if (m_the_path[x][y + 2] == " =")
						{
							m_the_path[x][y] = "|";

						}
					}
				}

				else
				{
					m_the_path[x][y] = " ";
				}
			}
		}


	}
	else
	{
		/*while (the_path.size() > 0)
		{
			the_path.pop_back();
		}*/
		the_path.resize(map_length = (change_l() + 1), vector<string>(map_height = (change_h() + 1)));

		for (int x = 0; x < map_length; x++)
		{
			for (int y = 0; y < map_height; y++)
			{
				rand_int = rand() % 5;

				if (x == map_length - 1)
				{

					the_path[x][y] = ">";

				}
				else if (x == 0 && y == 2)
				{
					the_path[x][y] = "|";
					num_cities++;
				}
				else if (((x > 0 && x < 7 && rand_int == 0) || x == 7) && (num_cities == 1 && y == 2))
				{
					the_path[x][y] = "|";
					num_cities++;
					path_offset[0] = 1;
					path_offset[1] = 3;
					path_offset[2] = 10;
				}
				else if (((x > 10 && x < 17 && rand_int == 0) || x == 17) && (num_cities == 2 && (y == path_offset[0] || y == path_offset[1] || y == path_offset[2])))
				{
					the_path[x][y] = "|";
					num_cities++;
					path_offset[0] = 0;
					path_offset[1] = 2;
					path_offset[2] = 3;
				}
				else if (((x > 10 && x < 17 && rand_int == 0) || x == 17) && (num_cities == 3 && y == 3))
				{
					the_path[x][y] = "|";
					num_cities++;
					path_offset[0] = 0;
					path_offset[1] = 2;
					path_offset[2] = 4;
				}
				else if ((y == path_offset[0] || y == path_offset[1] || y == path_offset[2]))
				{
					for (size_t i = 0; i < 3; i++)
					{
						if (path_offset[i] != 10)
						{
							the_path[x][y] = "=";
							continue;
						}
						if ((the_path[x][y - 1] == "= ") || the_path[x][y - 1] == " =")
						{
							the_path[x][y] = "|";
						}
						if (the_path[x][y + 1] == " =" || the_path[x][y + 1] == "= ")
						{
							the_path[x][y] = "|";

						}
						if (the_path[x][y + 2] == " =")
						{
							the_path[x][y] = "|";

						}
					}
				}

				else
				{
					the_path[x][y] = " ";
				}
			}
		}

	}


}
int Map::get_length()
{
	return map_length;
}
void num_people(player* h)
{
	people = rand() % 11;
	people += 5;
	std::cout << people << " people" << endl;
	system("pause");
}
void set_people(int p)
{
	cout << people << " befor" << endl;
	people = p - 1;
	cout << people << " after" << endl;
	system("pause");
}
int get_people()
{
	return people;
}
void Map::generate_map()
{

	for (int y = 0; y < map_height; y++)
	{
		for (int x = 0; x < map_length; x++)
		{
			if ((p_pos[0] == x) && (p_pos[1] == y))
			{
				std::cout<< "P";
			}
			else
			{
				if (events.size() > 0)
				{
					std::cout<< m_the_path[x][y];

				}
				else if (rebuild == false)
				{
					std::cout<< the_path[x][y];

				}
			}
		}
		std::cout << endl;
	}
}
void Map::set_player(int x, int y)
{
	p_pos[0] = x;
	p_pos[1] = y;
}
int Map::get_playerx()
{
	return p_pos[0];
}
int Map::get_playery()
{
	return p_pos[1];
}
string Map::get_map_spot(int x, int y)
{
	if (events.size() > 0)
	{
		return m_the_path[x][y];

	}
	else
		return the_path[x][y];
}
void Map::set_c_city(player* h)
{
	if (h->get_hero() == "Spiderman")
	{
		city = "Queens";

	}
	else if (h->get_hero() == "Iron Man")
	{
		city = "Long Island";
	}
	else if (h->get_hero() == "Captain America")
	{
		city = "Brooklyn";
	}
	else if (h->get_hero() == "Wolverine")
	{
		city = "New York City";
	}
	else if (h->get_hero() == "Black Panther")
	{
		city = "Wakanda";
	}
	else if (h->get_hero() == "Ms. Marvel")
	{
		city = "Long Island";
	}
	else if (h->get_hero() == "Mr. Fantastic")
	{
		city = "Manhattan";
	}
	else if (h->get_hero() == "Black Widow")
	{
		city = "New York City";
	}
}
void Map::set_city(string i)
{
	if (i == "Queens" || i == "Brooklyn" || i == "New York City"
		|| i == "Long Island" || i == "Wakanda" || i == "Manhattan")
	{
		std::cout<< "Returning to " << i << endl;
		city = i;
	}
	else
	{
		bool choice = true;

		while (choice)
		{
			std::cout<< "Which city would you like to travel to?" << endl;
			std::cout<< "1. Queens" << endl;
			std::cout<< "2. Brooklyn" << endl;
			std::cout<< "3. New York City" << endl;
			std::cout<< "4. Long Island" << endl;
			std::cout<< "5. Manhattan" << endl;
			std::cout<< "6. Wakanda" << endl;
			char inputc = 0;
			inputc = selection(inputc);
			switch (inputc)
			{
			case '1':
				std::cout << "Traveling to Queens" << endl;
				city = "Queens";
				choice = false;
				break;
			case '2':
				std::cout << "Traveling to Brooklyn" << endl;
				city = "Brooklyn";
				choice = false;
				break;
			case '3':
				std::cout << "Traveling to New York City" << endl;
				city = "New York City";
				choice = false;
				break;
			case '4':
				std::cout << "Traveling to Long Island" << endl;
				city = "Long Island";
				choice = false;
				break;
			case '5':
				std::cout << "Traveling to Manhattan" << endl;
				city = "Manhattan";
				choice = false;
				break;
			case '6':
				std::cout << "Traveling to Wakanda" << endl;
				city = "Wakanda";
				choice = false;
				break;
			default:
				std::cout << "Please enter a vaild input" << endl;
				break;

			}
			system("pause");
			system("cls");

		}

	}

}

void Map::set_city_travel(string c)
{
	city = c;
}
string Map::get_city()
{
	return city;
}
void Map::clear_map()
{
	if (the_path.size() > 0)
	{
		the_path.clear();
	}
	else if (m_the_path.size() > 0)
	{
		m_the_path.clear();
	}
}

void save(player* p, Map* m)
{
	string war = ("C:\\Marvel Civil War");
	system("mkdir \"C:\\Marvel Civil War\"");


	ofstream myfiledie;
	ofstream missionfile;
	
	string file;
	char input = 0;
	vector < string > name;
	ofstream fileofname;
	string command = "mkdir ";
	ofstream myfile;

	string name_file = "C:\\Marvel Civil War\\name.txt"; 
	string names;
	ifstream namefile(name_file);
	int i = 0;
	if (namefile.is_open())
	{
		std::cout << "Exsisting Files" << endl;
		while (namefile >> names)
		{

			if (names != "\n")
			{
				std::cout << i << ". " << names << endl;
				i++;
				name.push_back(names);
			}
		}
		namefile.close();
	}

	
	bool found = false;
	bool naming = true;
	if (!loaded)
	{
		while (naming)
		{
			std::cout << endl << "Please enter file name, no spaces please." << endl;
			cin >> file;
			namefile.open(war + "\\" + "name.txt");
			for (size_t ii = 0; ii < name.size(); ii++)
			{
				if (file == name[ii])
				{
					cout << "File already exisit." << endl;
					break;
				}
				else if (ii >= name.size() - 1)
				{
					naming = false;
				}
			}
		}
	}
	else
	{
		cout << "Select a file to overwrite." << endl;
		do
		{
			input = selection(input);
			if (input < '0' || input > i + '0')
			{
				cout << "Please select a valid choice." << endl;
				system("pause");
				system("cls");
			}

		} while (input < '0' || input > i + '0');
		found = true;
		i = input - '0';
		file = name[i];
	}
	
	string commandString = command + file;
	string newDir = (war + "\\" + file);
	
	string filename(war + "\\" + file + "\\" + file + ".bin");
	if (myfile.good())
	{
		if (!found)
		{
			SetCurrentDirectory(war.c_str());
			system(commandString.c_str());
			SetCurrentDirectory(newDir.c_str());
			system("echo on");
		}

	}
	else
	{
		SetCurrentDirectory(war.c_str());
		SetCurrentDirectory(newDir.c_str());
		system("echo on");

	}

	myfile.open(filename , ios::out | ios::binary);
	
	myfile << p->get_hero() << "\n";
	myfile << p->get_level() << "\n";
	myfile << p->get_strength() << "\n";
	myfile << p->get_speed() << "\n";
	myfile << p->get_durability() << "\n";
	myfile << p->get_Cskill() << "\n";
	myfile << p->get_energy() << "\n";
	myfile << p->get_intelligence() << "\n";
	myfile << p->get_health() << "\n";
	myfile << p->get_current_experience() << "\n";
	myfile << p->get_reputation() * 100 << "\n";

	if (missions.size() > 0)
	{
		missionfile.open(war + "\\" + file + "\\" + file + "_m.bin" , ios::out | ios::binary);
		for (size_t i = 0; i < 3; i++)
		{
			if (i < missions.size())
			{
				missionfile << missions[i] << "\n";
			}
			else
			{
				break;
			}
		}
		missionfile.close();
	}
	if (die.size() > 0)
	{
		myfiledie.open(war + "\\" + file + "\\" + file + "_h.bin", ios::out | ios::binary);
		for (size_t i = 0; i < die.size(); i++)
		{
			myfiledie << die[i] << "\n";
		}
		myfiledie.close();
	}

	if (mission_vill.size() > 0)
	{
		myfiledie.open(war + "\\" + file + "\\" + file + "_mv.bin", ios::out | ios::binary);
		for (size_t i = 0; i < mission_vill.size(); i++)
		{
			myfiledie << mission_vill[i] << "\n";
		}
		myfiledie.close();
	}

	if (v_die.size() > 0)
	{
		ofstream myfilediev(war + "\\" + file + "\\" + file + "_v.bin", ios::out | ios::binary);
		if (myfilediev.is_open())
		{
			for (size_t i= 0; i < v_die.size(); i++)
			{
				myfilediev << v_die[i] << "\n";
			}
		}
		else
		{
			std::cout << "It failed" << filename + "_v.txt  would not open."  << endl;
		}
		
		myfilediev.close();
	}
	SetCurrentDirectory(war.c_str());
	fileofname.open(war + "\\" + "name.txt", ios_base::app);

	if (!found)
	{
		fileofname << file << "\n";
	}
	std::cout << "Save Successful." << endl;
	myfile.close();
}

void reduce_dmg(enemies* e, player* h)
{
	e->set_reduce();
	if (h->get_attack() - e->get_reduce() <= 0)
	{
		std::cout << "0 Damage!" << endl;
		e->set_health(-0);
	}
	else
	{
		std::cout << h->get_attack() - h->get_reduce() << " Damage!" << endl;
		e->set_health(-h->get_attack());
		if (e->get_health() > 0)
		{
			e->set_health(+e->get_reduce());
		}
	}
	std::cout << e->get_enemies() << " has " << e->get_health() << " Health left" << endl;
	system("pause");
	system("cls");
}

void evade_condition(enemies* e)
{
	if (team[0]->get_power() == "Tear Gas")
	{
		e->set_defense_mod(1);
		std::cout << e->get_enemies() << " is unable to see due to the tear gas!" << endl;
	}
	else if (team[0]->get_power() == "Widow's Bite")
	{
		e->set_defense_mod(1);
		std::cout << e->get_enemies() << " is stunned from the electricity!" << endl;
		std::cout << team[0]->get_attack() << " Damage!" << endl;
		e->set_health(-team[0]->get_attack());
		std::cout << e->get_enemies() << " has " << e->get_health() << " Health left" << endl;
	}

	else if (team[0]->get_power() == "Elastic Crush")
	{
		for (size_t i = 0; i < group.size(); i++)
		{
			int new_dmg = team[0]->get_attack();
			if (group[i]->get_defense_mod() == true)
			{
				new_dmg = new_dmg * 2;
				std::cout << group[i]->get_enemies() << " is stunned and cannot defend from the oncoming attack!" << endl;
			}
			if (group[i]->get_reduce() > 0)
			{
				group[i]->set_reduce();
				if (new_dmg - group[i]->get_reduce() <= 0)
				{
					std::cout << "0 Damage!" << endl;
					group[i]->set_health(-0);
				}
				else
				{
					std::cout << new_dmg - team[0]->get_reduce() << " Damage!" << endl;
					group[i]->set_health(-new_dmg);
					if (group[i]->get_health() > 0)
					{
						group[i]->set_health(+group[i]->get_reduce());
					}
				}
				std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				team[0]->set_conditon(group[i]);
				group[i]->set_evade();
				if (group[i]->get_evade() == false)
				{
					std::cout << team[0]->get_attack() << " Damage!" << endl;
					group[i]->set_health(-team[0]->get_attack());
					std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
				system("pause");
				system("cls");
				}
				
			}
		}
	}
	else if (team[0]->get_power() == "Elastic Smash")
	{
		for (size_t i = 0; i < group.size(); i++)
		{
			
			int hit_speed = rand() % (team[0]->get_speed() + team[0]->get_strength());
			int protect = rand() % group[i]->get_defense();
			if (hit_speed >= protect)
			{
				group[i]->set_defense_mod(1);
				std::cout << group[i]->get_enemies() << " is stunned from the attack!" << endl;
			}
			if (group[i]->get_reduce() > 0)
			{
				reduce_dmg(group[i], team[0]);
			}
			else
			{
				team[0]->set_conditon(group[i]);
				group[i]->set_evade();
				if (group[i]->get_evade() == false)
				{
					std::cout << team[0]->get_attack() << " Damage!" << endl;
					group[i]->set_health(-team[0]->get_attack());
					std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
				system("pause");
				system("cls");
				}
				
			}
		}
	}
	else if (team[0]->get_power() == "Pin Ball")
	{
		int hit = 0;
		for (size_t i = 0; i < group.size(); i++)
		{
			
			int momentum = rand() % (team[0]->get_speed() + team[0]->get_Cskill());
			momentum += hit;
			int balance = rand() % (group[i]->get_Cskill() + group[i]->get_level());
			if (momentum >= balance)
			{
				group[i]->set_defense_mod(1);
				std::cout << group[i]->get_enemies() << " is knocked down from the attack!" << endl;
				hit++;
			}

			if (group[i]->get_reduce() > 0)
			{
				reduce_dmg(group[i], team[0]);
			}
			else
			{
				team[0]->set_conditon(group[i]);
				group[i]->set_evade();
				if (group[i]->get_evade() == false)
				{
					std::cout << team[0]->get_attack() << " Damage!" << endl;
					group[i]->set_health(-team[0]->get_attack());
					std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
					system("pause");
					system("cls");
				}
			}
		}
	}
	else if (team[0]->get_power() == "Explosive Touch")
	{
		explosion_victim.push_back(e->get_enemies());
		
		std::sort(explosion_victim.begin(), explosion_victim.end());
		explosion_victim.erase(unique(explosion_victim.begin(), explosion_victim.end()), explosion_victim.end());
		

		explosion = true;
		system("pause");
		system("cls");
	}
	else if (team[0]->get_power() == "Mega Blast" || team[0]->get_power() == "Photon Burst")
	{
		for (size_t i = 0; i < group.size(); i++)
		{
			if (group[i]->get_reduce() > 0)
			{
				reduce_dmg(group[i], team[0]);
			}
			else
			{
				team[0]->set_conditon(group[i]);
				group[i]->set_evade();
				if (group[i]->get_evade() == false)
				{
					std::cout << team[0]->get_attack() << " Damage!" << endl;
					group[i]->set_health(-team[0]->get_attack());
					std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
					system("pause");
					system("cls");
				}
			}
		}
	}
	else if (team[0]->get_power() == "Prism")
	{
		
		int split = rand() % 10;
		int split_hit = rand() % team[0]->get_energy();
		split_hit++;
		if ((size_t)split_hit > group.size())
		{
			split_hit = group.size() - 1;
		}
		if (split > 4)
		{
			for (int i = 0; i < split_hit; i++)
			{
				std::cout << "The beam splits and hits " << group[i]->get_enemies() << "!" << endl;
				if (group[i]->get_reduce() > 0)
				{
					reduce_dmg(group[i], team[0]);
				}
				else
				{
					team[0]->set_conditon(group[i]);
					group[i]->set_evade();
					if (group[i]->get_evade() == false)
					{
						std::cout << team[0]->get_attack() << " Damage!" << endl;
						group[i]->set_health(-team[0]->get_attack());
						std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
						system("pause");
						system("cls");
					}
				}
			}
		}
		else
		{
			std::cout << team[0]->get_attack() << " Damage!" << endl;
			e->set_health(-team[0]->get_attack());
			std::cout << e->get_enemies() << " has " << e->get_health() << " Health left" << endl;
			system("pause");
			system("cls");
		}
	}
	else if (team[0]->get_power() == "Cosmic Slam")
	{
		for (size_t i = 0; i < group.size(); i++)
		{
			if (team[0]->get_speed() > group[i]->get_speed())
			{
				std::cout << group[i]->get_enemies() << " is not fast enough to avoid the aftershock!" << endl;
				std::cout << group[i]->get_enemies() << " is knocked to the ground!" << endl;
				group[i]->set_defense_mod(1);
			}
			if (group[i]->get_reduce() > 0)
			{
				reduce_dmg(group[i], team[0]);
			}
			else
			{
				team[0]->set_conditon(group[i]);
				group[i]->set_evade();
				if (group[i]->get_evade() == false)
				{
					std::cout << team[0]->get_attack() << " Damage!" << endl;
					group[i]->set_health(-team[0]->get_attack());
					std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
					system("pause");
					system("cls");
				}
			}
		}
	}

	else if (team[0]->get_power() == "Nano Assault")
	{
		
		int r = rand() % 2;
		//std::cout<< r << endl;
		if (r == 0)
		{
			for (size_t i = 0; i < group.size(); i++)
			{
				if (group[i]->get_reduce() > 0)
				{
					group[i]->set_reduce();
					group[i]->set_attack(team[0], group[i]);
					group[i]->set_health(-group[i]->get_attack());
					if (group[i]->get_health() > 0)
					{
						group[i]->set_health(+group[i]->get_reduce());
					}
					std::cout << group[i]->get_attack() << " Damage!" << endl;
					std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
					system("pause");
					system("cls");

				}
				else

				{
					group[i]->set_attack(team[0], group[i]);
					group[i]->set_health(-group[i]->get_attack());
					std::cout << group[i]->get_attack() << " Damage!" << endl;
					std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
					system("pause");
					system("cls");
				}
			}

		}
		else if (r == 1)
		{
			for (size_t i = 1; i <= group.size(); i++)
			{
				if (i >= group.size())
				{
					break;
				}
				group[i]->set_attack(team[0], group[i]);
				group[i]->set_health(-group[i]->get_attack());
				std::cout << group[i]->get_attack() << " Damage!" << endl;
				std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
				system("pause");
				system("cls");
			}

		}
		else if (r == 2)
		{
			for (size_t i = 2; i <= group.size(); i++)
			{

				if (i >= group.size())
				{
					break;
				}
				group[i]->set_attack(team[0], group[i]);
				group[i]->set_health(-group[i]->get_attack());
				std::cout << group[i]->get_attack() << " Damage!" << endl;
				std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
				system("pause");
				system("cls");
			}

		}
		
	}
	else
	{
		std::cout << team[0]->get_attack() << " Damage!" << endl;
		e->set_health(-team[0]->get_attack());
		std::cout << e->get_enemies() << " has " << e->get_health() << " Health left" << endl;
	}
}
void counter_attack(player *p, enemies *e, string who, int h_counter, int e_counter)
{
	if (who == "hero" && h_counter > e_counter)
	{
		std::cout << p->get_hero() << " counters the attack!" << endl;
		std::cout << p->get_hero() << " attacks " << e->get_enemies() << endl;
		p->set_attack(e, p);
		if (p->get_power() != "p" && p->get_power() != "Bleed")
		{
			evade_condition(e);
		}
		else
		{
			e->set_evade();
			if (e->get_evade() == false)
			{
				std::cout << p->get_attack() << " Damage!" << endl;
				e->set_health(-p->get_attack());
				std::cout << e->get_enemies() << " has " << e->get_health() << " Health left" << endl;
				if (p->get_power() == "Bleed")
				{
					p->set_bleed_dmg(+p->get_bleed());
					e->set_health(-p->get_bleed_dmg());
					std::cout << e->get_enemies() << " is bleeding " << e->get_health() << " Health left" << endl;
					e->set_bleeding();
					//group[i]->set_bleed_dmg(+team[j]->get_bleed());
				}
			}
		}

	}
	else
	{
		std::cout << e->get_enemies() << " counters the attack!" << endl;
		std::cout << e->get_enemies() << " attacks " << p->get_hero() << endl;
		e->set_attack(p, e);
		h_counter > e_counter ? counter_attack(p, e, "hero", rand() % h_counter, rand() % e_counter) : 0;

		std::cout << p->get_attack() << " Damage!" << endl;
		e->set_health(-p->get_attack());
		std::cout << e->get_enemies() << " has " << e->get_health() << " Health left" << endl;
		if (e->get_power() == "Bleed")
		{
			e->set_bleed_dmg(+e->get_bleed());
			p->set_health(-e->get_bleed_dmg());
			std::cout << p->get_hero() << " is bleeding " << p->get_health() << " Health left" << endl;
			//group[i]->set_bleed_dmg(+team[j]->get_bleed());
		}
	}
}

void dead_enemy()
{
	for (size_t i = 0; i < 6; i++)
	{
		for (size_t i = 0; i < group.size(); i++)
		{
			if (group[i]->get_health() <= 0)
			{
				std::cout << group[i]->get_enemies() << " Has been killed!" << endl;
				system("pause");
				system("cls");
				std::cout << team[0]->get_hero() << " gained " << group[i]->get_experience() << " exp." << endl;
				team[0]->set_current_experience(group[i], 0);
				std::cout << "You now have " << team[0]->get_current_experience() << " exp." << endl;
				team[0]->set_reputation(group[i]->get_reputation());
				std::cout << "Your Current Reputation is: " << team[0]->get_reputation() << endl;
				if (group[i]->get_boss())
				{
					switch (group[i]->get_enum())
					{
					case IRON_MAN:
						die.push_back("Iron Man");
						break;
					case SPIDERMAN:
						die.push_back("Spiderman");
						break;
					case WOLVERINE:
						die.push_back("Wolverine");

						break;
					case CAPTAIN_AMERICA:
						die.push_back("Captain America");
						break;
					case BLACK_WIDOW:
						die.push_back("Black Widow");
						break;
					case BLACK_PANTHER:
						die.push_back("Black Panther");
						break;
					case MS_MARVEL:
						die.push_back("Ms. Marvel");
						break;
					case MR_FANTASTIC:
						die.push_back("Mr. Fantastic");
						break;
					case GREEN_GOBLIN:
						v_die.push_back("Green Goblin");
						break;
					case VENOM:
						v_die.push_back("Venom");
						break;
					case ZEMO:
						v_die.push_back("Zemo");
						break;
					case RED_SKULL:
						v_die.push_back("Red Skull");
						break;
					case SABRETOOTH:
						v_die.push_back("Sabretooth");
						break;
					case NITRO:
						v_die.push_back("Nitro");
						break;
					case WHIPLASH:
						v_die.push_back("Whiplash");
						break;
					case TITANIUM_MAN:
						v_die.push_back("Titanium Man");
						break;
					case MARROW:
						mission_vill.push_back("Marrow");
						break;
					case TRI_SENTINEL:
						mission_vill.push_back("Tri-Sentinel");
						break;
					case MAGNETO:
						mission_vill.push_back("Magneto");
						break;
					case STEGRON:
						mission_vill.push_back("Stegron");
						break;
					case SAURON:
						mission_vill.push_back("Sauron");
						break;
					case KINGPIN:
						mission_vill.push_back("Kingpin");
						break;
					case IRON_FIST:
						mission_vill.push_back("Iron Fist");
						break;
					case MISTER_SINISTER:
						mission_vill.push_back("Mister Sinister");
						break;
					case CALLISTO:
						mission_vill.push_back("Callisto");
						break;
					case DARK_BEAST:
						mission_vill.push_back("Dark Beast");
						break;
					case CALIBAN:
						mission_vill.push_back("Caliban");
						break;
					case BLOCKBUSTER:
						mission_vill.push_back("Blockbuster");
						break;
					case LADY_MASTERMIND:
						mission_vill.push_back("Lady Mastermind");
						break;
					case ARCLIGHT:
						mission_vill.push_back("Arclight");
						break;
					case MACHINE_MAN:
						mission_vill.push_back("Machine Man");
						break;
					case BASTION:
						mission_vill.push_back("Bastion");
						break;
					case QUICKSILVER:
						mission_vill.push_back("Quicksilver");
						break;
					case TOAD:
						mission_vill.push_back("Toad");
						break;
					case SCARLET_WITCH:
						mission_vill.push_back("Scarlet Witch");
						break;
					case DAREDEVIL:
						mission_vill.push_back("Daredevil");
						break;
					case LUKE_CAGE:
						mission_vill.push_back("Luke Cage");
						break;
					case DOCTOR_OCTOPUS:
						mission_vill.push_back("Doctor Octopus");
						break;
					case POWDERKEG:
						mission_vill.push_back("Powderkeg");
						break;
					case SHOCKER:
						mission_vill.push_back("Shocker");
						break;
					case TITANIA:
						mission_vill.push_back("Titania");
						break;
					}

				}

				enemies* temp = new enemies();
				temp = group[i];
				group[i] = group[group.size() - 1];
				group[group.size() - 1] = temp;
				delete group[group.size() - 1];
				group.pop_back();
				//delete temp;

				system("pause");
				system("cls");
			}

		}
	}

}

void regen_hlth(enemies* e)
{
	if (e->get_health() < e->get_max())
	{
		std::cout << e->get_enemies() << ", Regenerates " << e->get_regen() << " Health." << endl;
		e->set_health(+e->get_regen());
		system("pause");
		system("cls");
	}
}



void explosion_result(bool a, bool b)
{
	if (explosion == true)
	{
		
		int rand1;
		int rand2;
		if (count_down >= 10)
		{
			rand1 = 1;
			rand2 = 1;
		}
		else
		{
			rand1 = rand() % 10 - count_down;
			rand2 = rand() % 10 - count_down;
		}
		int dmg = 0;
		if (team[0]->get_registration() == "pro")
		{
			dmg = (rand1 + team[0]->get_energy()) * team[0]->get_level();
			if (rand1 == rand2)
			{
				explosion = false;
				count_down = 0;
				for (size_t i = 0; i < explosion_victim.size(); i++)
				{
					if (group[i]->get_health() <= 0)
					{
						std::cout << group[i]->get_enemies() << " Has been killed!" << endl;
						system("pause");
						system("cls");
						std::cout << team[0]->get_hero() << " gained " << group[i]->get_experience() << " exp." << endl;
						team[0]->set_current_experience(group[i], 0);
						std::cout << "You now have " << team[0]->get_current_experience() << " exp." << endl;
						team[0]->set_reputation(group[i]->get_reputation());
						std::cout << "Your Current Reputation is: " << team[0]->get_reputation() << endl;
						if (group[i]->get_boss())
						{

							switch (group[i]->get_enum())
							{
							case IRON_MAN:
								die.push_back("Iron Man");
								break;
							case SPIDERMAN:
								die.push_back("Spiderman");
								break;
							case WOLVERINE:
								die.push_back("Wolverine");

								break;
							case CAPTAIN_AMERICA:
								die.push_back("Captain America");
								break;
							case BLACK_WIDOW:
								die.push_back("Black Widow");
								break;
							case BLACK_PANTHER:
								die.push_back("Black Panther");
								break;
							case MS_MARVEL:
								die.push_back("Ms. Marvel");
								break;
							case MR_FANTASTIC:
								die.push_back("Mr. Fantastic");
								break;
							case GREEN_GOBLIN:
								v_die.push_back("Green Goblin");
								break;
							case VENOM:
								v_die.push_back("Venom");
								break;
							case ZEMO:
								v_die.push_back("Zemo");
								break;
							case RED_SKULL:
								v_die.push_back("Red Skull");
								break;
							case SABRETOOTH:
								v_die.push_back("Sabretooth");
								break;
							case NITRO:
								v_die.push_back("Nitro");
								break;
							case WHIPLASH:
								v_die.push_back("Whiplash");
								break;
							case TITANIUM_MAN:
								v_die.push_back("Titanium Man");
								break;
							case MARROW:
								mission_vill.push_back("Marrow");
								break;
							case TRI_SENTINEL:
								mission_vill.push_back("Tri-Sentinel");
								break;
							case MAGNETO:
								mission_vill.push_back("Magneto");
								break;
							case STEGRON:
								mission_vill.push_back("Stegron");
								break;
							case SAURON:
								mission_vill.push_back("Sauron");
								break;
							case KINGPIN:
								mission_vill.push_back("Kingpin");
								break;
							case IRON_FIST:
								mission_vill.push_back("Iron Fist");
								break;
							case MISTER_SINISTER:
								mission_vill.push_back("Mister Sinister");
								break;
							case CALLISTO:
								mission_vill.push_back("Callisto");
								break;
							case DARK_BEAST:
								mission_vill.push_back("Dark Beast");
								break;
							case CALIBAN:
								mission_vill.push_back("Caliban");
								break;
							case BLOCKBUSTER:
								mission_vill.push_back("Blockbuster");
								break;
							case LADY_MASTERMIND:
								mission_vill.push_back("Lady Mastermind");
								break;
							case ARCLIGHT:
								mission_vill.push_back("Arclight");
								break;
							case MACHINE_MAN:
								mission_vill.push_back("Machine Man");
								break;
							case BASTION:
								mission_vill.push_back("Bastion");
								break;
							case QUICKSILVER:
								mission_vill.push_back("Quicksilver");
								break;
							case TOAD:
								mission_vill.push_back("Toad");
								break;
							case SCARLET_WITCH:
								mission_vill.push_back("Scarlet Witch");
								break;
							case DAREDEVIL:
								mission_vill.push_back("Daredevil");
								break;
							case LUKE_CAGE:
								mission_vill.push_back("Luke Cage");
								break;
							case DOCTOR_OCTOPUS:
								mission_vill.push_back("Doctor Octopus");
								break;
							case POWDERKEG:
								mission_vill.push_back("Powderkeg");
								break;
							case SHOCKER:
								mission_vill.push_back("Shocker");
								break;
							case TITANIA:
								mission_vill.push_back("Titania");
								break;
							}
						}

						enemies* temp = new enemies();
						temp = group[i];
						group[i] = group[group.size() - 1];
						group[group.size() - 1] = temp;
						delete group[i];
						group.pop_back();
						delete temp;
						while (i != 0)
						{
							i--;
							std::cout << group.size() << " size of group" << endl;
						}
						system("pause");
						system("cls");
						a = false;
						if (group.size() <= 0)
						{
							b = false;
						}

					}// end if health
					else
					{
						std::cout << "The energy with in " << group[i]->get_enemies() << " explodes!" << endl;
						std::cout << dmg << " Damage!" << endl;
						group[i]->set_health(-dmg);
						std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
						system("pause");
						system("cls");
						if (group[i]->get_health() <= 0)
						{
							dead_enemy();
							a = false;
							if (group.size() <= 0)
							{
								b = false;
							}
						}



					}
				}// for loop with death
			}
			else
			{
				for (size_t i = 0; i < explosion_victim.size(); i++)
				{
					std::cout << "The energy is still inside of " << explosion_victim[i] << endl;
				}
				count_down++;
				system("pause");
				system("cls");
			}
		}
		else
		{
			if (team[0]->get_health() > 0)
			{
				if (rand1 == rand2)
				{
					explosion = false;
					count_down = 0;
					dmg = (rand1 + group[0]->get_energy()) * group[0]->get_level();
					std::cout << "The energy with in " << team[0]->get_hero() << " explodes!" << endl;
					std::cout << dmg << " Damage!" << endl;
					team[0]->set_health(-dmg);
					std::cout << team[0]->get_hero() << " has " << team[0]->get_health() << " Health left" << endl;
					system("pause");
					system("cls");
					explosion = false;
				}
				else
				{
					for (size_t i = 0; i < explosion_victim.size(); i++)
					{
						std::cout << "The energy is still inside of " << explosion_victim[i] << endl;
					}
					count_down++;
					system("pause");
					system("cls");
				}

			}
			else
			{
				std::cout << team[0]->get_hero() << " is dead!" << endl << "GAME OVER!" << endl;
			}

		}
		if (explosion == false)
		{
			while (explosion_victim.size() != 0)
			{
				explosion_victim.pop_back();
			}
		}

	}
}

void level_up()
{
	int j = 0;
	char input = 0;
	while (team[j]->get_current_experience() >= team[j]->get_experience()) // if
	{
		team[j]->set_level(+1);
		cout << team[j]->get_hero() << " has reached level " << team[j]->get_level() << "!" << endl;
		cout << "You have 4 Power Points to spend!" << endl << endl;

		int pp = 4;
		while (pp > 0)
		{
			cout << team[j]->get_hero() << "'s main attributes are:" << endl;
			if (team[j]->get_hero() == "Spiderman")
			{
				cout << "Offensive: Speed, Strength, and Combat Skill." << endl;
				cout << "Deffensive: Intellegence will increase your chance for evasion." << endl;
			}
			else if (team[j]->get_hero() == "Iron Man")
			{
				cout << "Offensive: Energy Projection, Combat Skill, and Strength." << endl;
				cout << "Deffensive: Durability will increase your damage reduction." << endl;
			}
			else if (team[j]->get_hero() == "Ms. Marvel")
			{
				cout << "Offensive: Energy Projection, Combat Skill, and Strength." << endl;
				cout << "Deffensive: Speed will increase your denfense." << endl;
			}
			else if (team[j]->get_hero() == "Mr. Fantastic")
			{
				cout << "Offensive: Strength, and Speed." << endl;
				cout << "Deffensive: Durability will increase your damage reduction." << endl;
			}
			else if (team[j]->get_hero() == "Black Widow")
			{
				cout << "Offensive: Combat Skill, Strength, and Speed." << endl;
				cout << "Deffensive: Intellegence will increase your defense." << endl;
			}
			else if (team[j]->get_hero() == "Wolverine")
			{
				cout << "Offensive: Strength and Durability." << endl;
				cout << "Deffensive: Durability will increase your health regeneration." << endl;
			}
			else if (team[j]->get_hero() == "Black Panther")
			{
				cout << "Offensive: Strength, Speed, and Combat Skill." << endl;
				cout << "Deffensive: Combat Skill will increase your defense." << endl;
			}
			else if (team[j]->get_hero() == "Captain America")
			{
				cout << "Offensive: Strength, Speed, and Combat Skill." << endl;
				cout << "Deffensive: Combat Skill will increase your defense." << endl;
			}
			cout << endl << "Points remaining: " << pp << endl;
			cout << "Please select which ability you want to increase." << endl;
			cout << "1. Strength\n2. Speed\n3. Durability\n4. Combat Skill\n5. Energy Projection\n6. Intelligence\n";
			input = selection(input);
			if (input == '1')
			{
				team[j]->set_strenght(+1);
				pp_strength++;
				pp--;
				cout << team[j]->get_hero() << "'s Strength has increased to " << team[j]->get_strength() << "!" << endl;
			}
			else if (input == '2')
			{
				team[j]->set_speed(+1);
				pp_speed++;
				pp--;
				cout << team[j]->get_hero() << "'s Speed has increased to " << team[j]->get_speed() << "!" << endl;
			}
			else if (input == '3')
			{
				team[j]->set_durability(+1);
				pp_durability++;
				pp--;
				cout << team[j]->get_hero() << "'s Durability has increased to " << team[j]->get_durability() << "!" << endl;
			}
			else if (input == '4')
			{
				team[j]->set_Cskill(+1);
				pp_Cskill++;
				pp--;
				cout << team[j]->get_hero() << "'s Combat Skill has increased to " << team[j]->get_Cskill() << "!" << endl;
			}
			else if (input == '5')
			{
				team[j]->set_energy(+1);
				pp_energy++;
				pp--;
				cout << team[j]->get_hero() << "'s Energy Projection has increased to " << team[j]->get_energy() << "!" << endl;
			}
			else if (input == '6')
			{
				team[j]->set_intelligence(+1);
				pp_intelligence++;
				pp--;
				cout << team[j]->get_hero() << "'s Intelligence has increased to " << team[j]->get_intelligence() << "!" << endl;
			}
			else
			{
				cout << "Please select a valid choice." << endl;
			}
			system("pause");
			system("cls");
		}
		team[j]->set_experience(0);
		team[j]->set_strenght(+1);
		team[j]->set_Cskill(+1);
		team[j]->set_durability(+1);
		team[j]->set_energy(+1);
		team[j]->set_intelligence(+1);
		team[j]->set_health(-team[j]->get_health());
		team[j]->set_health((team[j]->get_durability() * (15 + team[j]->get_level())) + 100);
		team[j]->set_speed(+1);
		if (team[j]->get_hero() == "Iron Man" || team[j]->get_hero() == "Mr. Fantastic")
		{
			team[j]->set_reduce();
		}
		if (team[j]->get_hero() == "Wolverine")
		{
			team[j]->set_regen();
		}
	}
}

void rest()
{
	int j = 0;

	if (team[j]->get_hero() == "Spiderman")
	{
		team[j]->set_speed(-team[j]->get_speed());
		team[j]->set_speed(team[j]->get_level() + 5 + pp_speed);
		team[j]->set_strenght(-team[j]->get_strength());
		team[j]->set_strenght(team[j]->get_level() + 3 + pp_strength);
		team[j]->set_durability(-team[j]->get_durability());
		team[j]->set_durability(team[j]->get_level() + 2 + pp_durability);
		team[j]->set_Cskill(-team[j]->get_Cskill());
		team[j]->set_Cskill(team[j]->get_level() + 4 + pp_Cskill);
		team[j]->set_energy(-team[j]->get_energy());
		team[j]->set_energy(+team[j]->get_level() + 3 + pp_energy);
		team[j]->set_intelligence(-team[j]->get_intelligence());
		team[j]->set_intelligence(+team[j]->get_level() + 3 + pp_intelligence);
	}
	else if (team[j]->get_hero() == "Iron Man")
	{
		team[j]->set_speed(-team[j]->get_speed());
		team[j]->set_speed(team[j]->get_level() + 4 + pp_speed);
		team[j]->set_strenght(-team[j]->get_strength());
		team[j]->set_strenght(team[j]->get_level() + 5 + pp_strength);
		team[j]->set_durability(-team[j]->get_durability());
		team[j]->set_durability(team[j]->get_level() + 5 + pp_durability);
		team[j]->set_Cskill(-team[j]->get_Cskill());
		team[j]->set_Cskill(team[j]->get_level() + 2 + pp_Cskill);
		team[j]->set_energy(-team[j]->get_energy());
		team[j]->set_energy(+team[j]->get_level() + 5 + pp_energy);
		team[j]->set_intelligence(-team[j]->get_intelligence());
		team[j]->set_intelligence(+team[j]->get_level() + 5 + pp_intelligence);
	}
	else if (team[j]->get_hero() == "Wolverine")
	{
		team[j]->set_speed(-team[j]->get_speed());
		team[j]->set_speed(team[j]->get_level() + 3 + pp_speed);
		team[j]->set_strenght(-team[j]->get_strength());
		team[j]->set_strenght(team[j]->get_level() + 4 + pp_strength);
		team[j]->set_durability(-team[j]->get_durability());
		team[j]->set_durability(team[j]->get_level() + 4 + pp_durability);
		team[j]->set_Cskill(-team[j]->get_Cskill());
		team[j]->set_Cskill(team[j]->get_level() + 4 + pp_Cskill);
		team[j]->set_energy(-team[j]->get_energy());
		team[j]->set_energy(+team[j]->get_level() + 0 + pp_energy);
		team[j]->set_intelligence(-team[j]->get_intelligence());
		team[j]->set_intelligence(+team[j]->get_level() + 1 + pp_intelligence);
		team[j]->set_regen();
	}
	else if (team[j]->get_hero() == "Captain America")
	{
		team[j]->set_speed(-team[j]->get_speed());
		team[j]->set_speed(team[j]->get_level() + 3 + pp_speed);
		team[j]->set_strenght(-team[j]->get_strength());
		team[j]->set_strenght(team[j]->get_level() + 3 + pp_strength);
		team[j]->set_durability(-team[j]->get_durability());
		team[j]->set_durability(team[j]->get_level() + 3 + pp_durability);
		team[j]->set_Cskill(-team[j]->get_Cskill());
		team[j]->set_Cskill(team[j]->get_level() + 6 + pp_Cskill);
		team[j]->set_energy(-team[j]->get_energy());
		team[j]->set_energy(+team[j]->get_level() + 0 + pp_energy);
		team[j]->set_intelligence(-team[j]->get_intelligence());
		team[j]->set_intelligence(+team[j]->get_level() + 3 + pp_intelligence);

	}
	else if (team[j]->get_hero() == "Ms. Marvel")
	{
		team[j]->set_speed(-team[j]->get_speed());
		team[j]->set_speed(team[j]->get_level() + 5 + pp_speed);
		team[j]->set_strenght(-team[j]->get_strength());
		team[j]->set_strenght(team[j]->get_level() + 4 + pp_strength);
		team[j]->set_durability(-team[j]->get_durability());
		team[j]->set_durability(team[j]->get_level() + 4 + pp_durability);
		team[j]->set_Cskill(-team[j]->get_Cskill());
		team[j]->set_Cskill(team[j]->get_level() + 4 + pp_Cskill);
		team[j]->set_energy(-team[j]->get_energy());
		team[j]->set_energy(+team[j]->get_level() + 4 + pp_energy);
		team[j]->set_intelligence(-team[j]->get_intelligence());
		team[j]->set_intelligence(+team[j]->get_level() + 2 + pp_intelligence);

	}
	else if (team[j]->get_hero() == "Black Widow")
	{
		team[j]->set_speed(-team[j]->get_speed());
		team[j]->set_speed(team[j]->get_level() + 2 + pp_speed);
		team[j]->set_strenght(-team[j]->get_strength());
		team[j]->set_strenght(team[j]->get_level() + 3 + pp_strength);
		team[j]->set_durability(-team[j]->get_durability());
		team[j]->set_durability(team[j]->get_level() + 3 + pp_durability);
		team[j]->set_Cskill(-team[j]->get_Cskill());
		team[j]->set_Cskill(team[j]->get_level() + 6 + pp_Cskill);
		team[j]->set_energy(-team[j]->get_energy());
		team[j]->set_energy(+team[j]->get_level() + 2 + pp_energy);
		team[j]->set_intelligence(-team[j]->get_intelligence());
		team[j]->set_intelligence(+team[j]->get_level() + 2 + pp_intelligence);

	}
	else if (team[j]->get_hero() == "Black Panther")
	{
		team[j]->set_speed(-team[j]->get_speed());
		team[j]->set_speed(team[j]->get_level() + 4 + pp_speed);
		team[j]->set_strenght(-team[j]->get_strength());
		team[j]->set_strenght(team[j]->get_level() + 4 + pp_strength);
		team[j]->set_durability(-team[j]->get_durability());
		team[j]->set_durability(team[j]->get_level() + 3 + pp_durability);
		team[j]->set_Cskill(-team[j]->get_Cskill());
		team[j]->set_Cskill(team[j]->get_level() + 6 + pp_Cskill);
		team[j]->set_energy(-team[j]->get_energy());
		team[j]->set_energy(+team[j]->get_level() + 0 + pp_energy);
		team[j]->set_intelligence(-team[j]->get_intelligence());
		team[j]->set_intelligence(+team[j]->get_level() + 4 + pp_intelligence);

	}
	else if (team[j]->get_hero() == "Mr. Fantastic")
	{
		team[j]->set_speed(-team[j]->get_speed());
		team[j]->set_speed(team[j]->get_level() + 2 + pp_speed);
		team[j]->set_strenght(-team[j]->get_strength());
		team[j]->set_strenght(team[j]->get_level() + 3 + pp_strength);
		team[j]->set_durability(-team[j]->get_durability());
		team[j]->set_durability(team[j]->get_level() + 6 + pp_durability);
		team[j]->set_Cskill(-team[j]->get_Cskill());
		team[j]->set_Cskill(team[j]->get_level() + 2 + pp_Cskill);
		team[j]->set_energy(-team[j]->get_energy());
		team[j]->set_energy(+team[j]->get_level() + 0 + pp_energy);
		team[j]->set_intelligence(-team[j]->get_intelligence());
		team[j]->set_intelligence(+team[j]->get_level() + 5 + pp_intelligence);

	}

	team[j]->set_health(-team[j]->get_health());
	team[j]->set_health(team[j]->get_durability() * (15 + team[j]->get_level()) + 100);
}


void fight(player* p, enemies* e)
{
	int j = 0;

	bool escape = true;
	bool fighting = true;
	char input = 0;
	if (group[0]->get_enemies().substr(0, 4) == "Civi")
	{
		input = '1';
	}
	else
	{
		std::cout<< "You hear someone screaming for help!" << endl << "What do you do?" << endl;
		std::cout<< "1. Run over and help" << endl;
		std::cout<< "2. Ignor it" << endl;
		input = selection(input);

	}



	if (input == '1')
	{

		//{
		for (size_t i = 0; i < group.size(); i++)
		{
			if (group[i]->get_enemies().substr(0, 4) == "Civi")
			{
				std::cout << "You are surrounded by Civilians!" << endl;;
				std::cout<< endl;

			}
			else
			{
				std::cout<< "You find ";
				std::cout<< group[i]->get_enemies();
				std::cout<< endl;

			}


		}




		std::cout<< "And a fight begins!" << endl;
		system("pause");
		system("cls");

		/*if (!group[0]->get_boss())
		{
			for (size_t i = 0; i < group.size(); i++)
			{
				/*group[i]->set_strenght(0, team[j]);
				group[i]->set_weapon();
				group[i]->set_Cskill(0, team[j]);
				group[i]->set_durability(0, team[j]);
				group[i]->set_intelligence(0, team[j]);
				group[i]->set_energy(0, team[j]);
				if (group[i]->get_health() <= 0)
				{
					group[i]->set_health(group[i]->get_durability() * 5);
				}

				//int rand_spd = rand() % (team[0]->get_speed() - team[0]->get_level());

				//group[i]->set_speed(rand_spd + 3 + group[i]->get_level());
				group[i]->reset_defense();
				group[i]->max_health(group[i]->get_health());

				int rand_int = rand() % 7;


				group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_level() + group[i]->get_speed() + group[i]->get_intelligence() + rand_int);
				group[i]->set_experience();
				group[i]->set_reputation();
			}
		}*/
		

		while (fighting)
		{
			bool player_att = true;
			bool fight = true;
			bool group_size = true;
			bool group_hlth = true;
			bool hero_hlth = true;

			while (fight)
			{
				for (size_t i = 0; i < group.size(); i++)
				{
					if (group.size() == 1)
					{
						break;
					}
					if (team[j]->get_defense() > group[i]->get_defense())
					{
						swap(group[i], group[0]);
						break;
					}
					else
					{
						player_att = false;
						if (group.size() == 3)
						{
							if (i == 0)
							{
								swap(group[0], group[2]);
							}
							else if (i == 1)
							{
								swap(group[0], group[2]);

							}
							else
							{
								continue;

							}
						}
						else if (group.size() == 4)
						{
							if (i == 0)
							{
								swap(group[0], group[3]);
							}
							else if (i == 1)
							{
								swap(group[0], group[2]);

							}
							else if (i == 2)
							{
								swap(group[0], group[3]);

							}
							else if (i == 3)
							{
								swap(group[2], group[3]);

							}
						}
						else
						{
							continue;
						}
					}

				}//for

				explosion_result(group_size, fight);

				if (player_att)
				{

					while (group_size)
					{

						std::cout<< team[j]->get_hero() << " Attacks!" << endl;
						if (group.size() <= 0)
						{
							group_size = false;
						}


						for (size_t i = 0; i < group.size(); i++)
						{
							if (group_hlth == false)
							{
								break;
							}

							std::cout<< "Who will you attack? ";
							std::cout<< endl;
							for (size_t i = 0; i < group.size(); i++)
							{
								if (group.size() == 1)
								{
									break;
								}
								std::cout<< i << ". " << group[i]->get_enemies() << endl;
							}
							string a;

							if (group.size() == 1)
							{
								a = group[i]->get_enemies();
							}
							else
							{
								bool attack = true;
								while (attack)
								{
									explosion_result(group_size, fight);

									char choice = 0;
									choice = selection(choice);
									if ((size_t)(choice - 48) >= group.size())
									{
										std::cout << "Please select a valid choice." << endl;
									}
									else
									{
										a = group[(choice - 48)]->get_enemies();
										swap(group[i], group[(choice - 48)]);
										attack = false;
									}
								}


							}


							if (a == group[i]->get_enemies())

							{
								explosion_result(group_size, fight);

								std::cout<< team[j]->get_hero() << " Attacks " << group[i]->get_enemies() << "!" << endl;
								system("pause");
								system("cls");



								while (group_hlth)
								{
									explosion_result(group_size, fight);

									if (team[j]->get_hero() == "Wolverine")
									{
										team[j]->max_hlth();
										if (team[j]->get_health() < team[j]->get_max())
										{
											if (group[i]->get_power() == "Power Steal")
											{
												std::cout << team[j]->get_hero() << " can't regenerate health!" << endl;
											}
											else
											{
												std::cout << team[j]->get_hero() << ", Regenerates " << team[j]->get_regen() << " Health." << endl;
												team[j]->set_health(+team[j]->get_regen());
												std::cout << "Current Health: " << team[j]->get_health() << endl;

											}
											
											system("pause");
											system("cls");
										}
									}
									if (group.size() > 0)
									{
										if (group[0]->get_regen() > 0)
										{
											regen_hlth(group[0]);
										}
									}
									

									std::cout<< team[j]->get_hero() << "'s " << " Attack list." << endl;
									if (i >= group.size())
									{
										i = group.size()-1;
									}
									team[j]->set_attack(group[i], team[j]);
									team[j]->get_power();
									if (team[j]->get_power() != "p" && team[j]->get_power() != "Bleed")
									{
										 if (team[j]->get_power() == "Elastic Crush")
										{
											 for (size_t i = 0; i < group.size(); i++)
											{
												int new_dmg = team[j]->get_attack();
												if (group[i]->get_defense_mod() == true)
												{
													new_dmg = new_dmg * 2;
													std::cout << group[i]->get_enemies() << " is stunned and cannot defend from the oncoming attack!" << endl;
												}
												if (group[i]->get_reduce() > 0)
												{
													group[i]->set_reduce();
													if (new_dmg - group[i]->get_reduce() <= 0)
													{
														std::cout << "0 Damage!" << endl;
														group[i]->set_health(-0);
													}
													else
													{
														std::cout << new_dmg - team[j]->get_reduce() << " Damage!" << endl;
														group[i]->set_health(-new_dmg);
														if (group[i]->get_health() > 0)
														{
															group[i]->set_health(+group[i]->get_reduce());
														}
													}
													std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
													system("pause");
													system("cls");
												}
												else
												{
													team[j]->set_conditon(group[i]);
													std::cout << new_dmg << " Damage!" << endl;
													group[i]->set_health(-new_dmg);
													std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
													system("pause");
													system("cls");
												}
											}
										}
										else if (team[j]->get_power() == "Elastic Smash")
										{
											for (size_t i = 0; i < group.size(); i++)
											{
												
												int hit_speed = rand() % (team[j]->get_speed() + team[j]->get_strength());
												int protect = rand() % group[i]->get_defense();
												if (hit_speed >= protect)
												{
													group[i]->set_defense_mod(1);
													std::cout << group[i]->get_enemies() << " is stunned from the attack!" << endl;
												}
												if (group[i]->get_reduce() > 0)
												{
													reduce_dmg(group[i], team[j]);
												}
												else
												{
													team[j]->set_conditon(group[i]);
													group[i]->set_evade();
													if (group[i]->get_evade() == false)
													{
														std::cout << team[j]->get_attack() << " Damage!" << endl;
														group[i]->set_health(-team[j]->get_attack());
														std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
														system("pause");
														system("cls");
													}
													
												}
											}
										}
										else if (team[j]->get_power() == "Pin Ball")
										{
											int hit = 0;
											for (size_t i = 0; i < group.size(); i++)
											{
												
												int momentum = rand() % (team[j]->get_speed() + team[j]->get_Cskill());
												momentum += hit;
												int balance = rand() % (group[i]->get_Cskill() + group[i]->get_level());
												if (momentum >= balance)
												{
													group[i]->set_defense_mod(1);
													std::cout << group[i]->get_enemies() << " is knocked down from the attack!" << endl;
													hit++;
												}

												if (group[i]->get_reduce() > 0)
												{
													reduce_dmg(group[i], team[j]);
												}
												else
												{
													team[j]->set_conditon(group[i]);
													group[i]->set_evade();
													if (group[i]->get_evade() == false)
													{
														std::cout << team[j]->get_attack() << " Damage!" << endl;
														group[i]->set_health(-team[j]->get_attack());
														std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
													system("pause");
													system("cls");
													}
													
												}
											}
										}
										else if (team[j]->get_power() == "Explosive Touch")
										{											
											explosion_victim.push_back(group[i]->get_enemies());

											std::sort(explosion_victim.begin(), explosion_victim.end());
											explosion_victim.erase(unique(explosion_victim.begin(), explosion_victim.end()), explosion_victim.end());
											
											explosion = true;
											system("pause");
											system("cls");
										}
										else if (team[j]->get_power() == "Mega Blast")
										{
											for (size_t i = 0; i < group.size(); i++)
											{
												if (group[i]->get_reduce() > 0)
												{
													reduce_dmg(group[i], team[j]);
												}
												else
												{
													team[0]->set_conditon(group[i]);
													group[i]->set_evade();
													if (group[i]->get_evade() == false)
													{
														std::cout << team[0]->get_attack() << " Damage!" << endl;
														group[i]->set_health(-team[0]->get_attack());
														std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
														system("pause");
														system("cls");
													}
												}
											}
										}
										else if (team[j]->get_power() == "Prism")
										{
											
											int split = rand() % 10;
											int split_hit = rand() % 3;
											split_hit++;
											if ((size_t)split_hit > group.size())
											{
												split_hit = group.size() - 1;
											}
											if (split > 4)
											{
												for (int i = 0; i < split_hit; i++)
												{
													std::cout<< "The beam splits and hits " << group[i]->get_enemies() << "!" << endl;
													if (group[i]->get_reduce() > 0)
													{
														reduce_dmg(group[i], team[j]);
													}
													else
													{
														team[j]->set_conditon(group[i]);
														group[i]->set_evade();
														if (group[i]->get_evade() == false)
														{
															std::cout << team[j]->get_attack() << " Damage!" << endl;
															group[i]->set_health(-team[j]->get_attack());
															std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
														system("pause");
														system("cls");
														}
														
													}
												}
											}
											else
											{
												group[i]->set_evade();
												if (group[i]->get_evade() == false)
												{
													std::cout << team[j]->get_attack() << " Damage!" << endl;
													group[i]->set_health(-team[j]->get_attack());
													std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
													system("pause");
													system("cls");
												}
											}
										}
										else if (team[j]->get_power() == "Cosmic Slam")
										{
											for (size_t i = 0; i < group.size(); i++)
											{
												if (team[j]->get_speed() > group[i]->get_speed())
												{
													std::cout<< group[i]->get_enemies() << " is not fast enough to avoid the aftershock!" << endl;
													std::cout<< group[i]->get_enemies() << " is knocked to the ground!" << endl;
													group[i]->set_defense_mod(1);
												}
												if (group[i]->get_reduce() > 0)
												{
													reduce_dmg(group[i], team[j]);
												}
												else
												{
													team[j]->set_conditon(group[i]);
													group[i]->set_evade();
													if (group[i]->get_evade() == false)
													{
														std::cout << team[j]->get_attack() << " Damage!" << endl;
														group[i]->set_health(-team[j]->get_attack());
														std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
														system("pause");
														system("cls");
													}
												}
											}
										}
										
									
									else if (team[j]->get_power() == "Nano Assault")
									{
										
										int r = rand() % 2;
										//std::cout<< r << endl;
										if (r == 0)
										{
											for (size_t i = 0; i < group.size(); i++)
											{
												if (group[i]->get_reduce() > 0)
												{
													group[i]->set_reduce();
													group[i]->set_attack(team[j], group[i]);
													group[i]->set_health(-group[i]->get_attack());
													if (group[i]->get_health() > 0)
													{
														group[i]->set_health(+group[i]->get_reduce());
													}
													std::cout<< group[i]->get_attack() << " Damage!" << endl;
													std::cout<< group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
													system("pause");
													system("cls");

												}
												else

												{
													group[i]->set_attack(team[j], group[i]);
													group[i]->set_health(-group[i]->get_attack());
													std::cout<< group[i]->get_attack() << " Damage!" << endl;
													std::cout<< group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
													system("pause");
													system("cls");
												}
											}

										}
										else if (r == 1)
										{
											for (size_t i = 1; i <= group.size(); i++)
											{
												if (i >= group.size())
												{
													break;
												}
												group[i]->set_attack(team[j], group[i]);
												group[i]->set_health(-group[i]->get_attack());
												std::cout<< group[i]->get_attack() << " Damage!" << endl;
												std::cout<< group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
												system("pause");
												system("cls");
											}

										}
										else if (r == 2)
										{
											for (size_t i = 2; i <= group.size(); i++)
											{

												if (i >= group.size())
												{
													break;
												}
												group[i]->set_attack(team[j], group[i]);
												group[i]->set_health(-group[i]->get_attack());
												std::cout<< group[i]->get_attack() << " Damage!" << endl;
												std::cout<< group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
												system("pause");
												system("cls");
											}

										}
										for (size_t i = 0; i < 5; i++)
										{
											if (group.size() == 0)
											{
												group_hlth = false;
											}
											if (i >= group.size())
											{
												break;
											}
											if (group[i]->get_health() <= 0)
											{
												dead_enemy();
												group_size = false;
												if (group.size() <= 0)
												{
													fight = false;
												}

											}

											else
												continue;

										}



									}





									else

									for (size_t i = 0; i < group.size(); i++)
									{
										if (team[j]->get_power() == "Tear Gas")
										{
											group[i]->set_defense_mod(1);
											std::cout << group[i]->get_enemies() << " is unable to see due to the tear gas!" << endl;
										}
										else if (team[j]->get_power() == "Widow's Bite")
										{
											group[i]->set_defense_mod(1);
											std::cout << group[i]->get_enemies() << " is stunned from the electricity!" << endl;
										}
										if (group[i]->get_reduce() > 0)
										{
											reduce_dmg(group[i], team[j]);
										}
										else
										{
											team[j]->set_conditon(group[i]);
											group[i]->set_evade();
											if (group[i]->get_evade() == false)
											{
												std::cout << team[j]->get_attack() << " Damage!" << endl;
												group[i]->set_health(-team[j]->get_attack());
												std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
												system("pause");
												system("cls");
											}
										}
									}
									for (size_t i = 0; i < 5; i++)
									{
										if (group.size() == 0)
										{
											group_hlth = false;
										}
										if (i >= group.size())
										{
											break;
										}
										if (group[i]->get_health() <= 0)
										{
											dead_enemy();
											if (group.size() == 0)
											{
												group_hlth = false;
											}

										}

										else
											continue;

									}



							}
							else
							{
								if (team[j]->get_power() == "Bleed" && group[i]->get_enemies() != "Mr. Fantastic")
								{
									std::cout<< team[j]->get_attack() << " Damage!" << endl;
									group[i]->set_health(-team[j]->get_attack());
									std::cout<< group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
									team[j]->set_bleed_dmg(+team[j]->get_bleed());
									group[i]->set_health(-team[j]->get_bleed_dmg());
									std::cout<< group[i]->get_enemies() << " is bleeding " << group[i]->get_health() << " Health left" << endl;
									group[i]->set_bleeding();
									//group[i]->set_bleed_dmg(+team[j]->get_bleed());
									system("pause");
									system("cls");
									if (group[i]->get_health() <= 0)
									{
										dead_enemy();
										break;
									}

								}

								else
								{
									if (group[i]->get_reduce() > 0)
									{
										reduce_dmg(group[i], team[j]);
									}
									else
									{
										group[i]->set_evade();
										if (group[i]->get_evade() == false)
										{
											std::cout << team[j]->get_attack() << " Damage!" << endl;
											group[i]->set_health(-team[j]->get_attack());
											std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " Health left" << endl;
											system("pause");
											system("cls");
										}
									}
								}
								if (group[i]->get_health() <= 0)
								{
									dead_enemy();
									break;
								}

							}


							if (group_hlth == false)
							{
								group_size = false;
							}
							if (group_size == false)
							{

								fight = false;

							}

							
							int rand_int = rand() % 5;

							team[j]->reset_defense();
							team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);
							if (team[j]->get_health() < (team[j]->get_durability() * (15 + team[j]->get_level()) + 100) / 3)
							{
								if (team[j]->get_defense_mod() == true)
								{
									if (group[i]->get_power() == "fire")
									{
										std::cout << team[j]->get_hero() << " is still on fire!" << endl;
										std::cout << group[i]->get_level() << " Damage!" << endl;
										team[j]->set_health(-group[i]->get_level());
										std::cout << team[j]->get_hero() << " has " << team[j]->get_health() << " health left!" << endl;
									}
									if (team[j]->get_defense() > 0)
									{
										while (team[j]->get_defense() > 0)
										{
											team[j]->set_defense(-1);
										}
									}
									team[j]->set_defense_mod(0, group[i]->get_power(), group[i]->get_ice());
								}
								else
								{
									team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 20);
								}
								
								int second_chance = rand() % 100;
								if (second_chance > 80)
								{
									if (escape == false)
									{
										escape = true;
									}
								}
								while (escape)
								{
									std::cout<< team[j]->get_hero() << " sees and opening to escape. will you runaway?" << endl;
									std::cout<< "1. Yes, try to runaway" << endl;
									std::cout<< "2. No, stay and fight" << endl;

									char to_run = 0;
									to_run = selection(to_run);

									if (to_run == '1')
									{
										
										int run = rand() % 500;
										int hero = rand() % team[j]->get_level();
										int bad = rand() % group[i]->get_level();
										if (hero + run >= bad)
										{
											std::cout<< team[j]->get_hero() << " manages to runaway." << endl;
											system("pause");
											system("cls");
											group.clear();
											escape = false;
											return;
											system("Pause");
											system("cls");

										}
										else
										{
											std::cout<< team[j]->get_hero() << " can't escape!" << endl;
											escape = false;
										}
									}
									else if (to_run == '2')
									{
										std::cout<< team[j]->get_hero() << " decides to stay and fight." << endl;
										escape = false;
									}
									else
									{
										std::cout<< "Please select a correct choice." << endl;
									}
								}
							}
							else
							{
								if (team[j]->get_defense_mod() == true)
								{
									if (group[i]->get_power() == "fire")
									{
										std::cout << team[j]->get_hero() << " is still on fire!" << endl;
										std::cout << group[i]->get_level() << " Damage!" << endl;
										team[j]->set_health(-group[i]->get_level());
										std::cout << team[j]->get_hero() << " has " << team[j]->get_health() << " health left!" << endl;
									}
									if (team[j]->get_defense() > 0)
									{
										while (team[j]->get_defense() > 0)
										{
											team[j]->set_defense(-1);
										}
									}
									team[j]->set_defense_mod(0, group[i]->get_power(), group[i]->get_ice());
								}
								else
								{
									team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);
								}
							}
							if (group.size() >= 1)
							{
								if (group[i]->get_health() > 0)
								{
									group[i]->reset_defense();
									group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_speed() + group[i]->get_level() + group[i]->get_intelligence() + rand_int);
								}
				
								if (group[i]->get_boss())
								{
									if (group[j]->get_health() < (group[j]->get_durability() * (15 + group[j]->get_level()) + 100) / 3)
									{
										
										int run = rand() % group[i]->get_level();
										if (group[i]->get_defense_mod() == true)
										{
											if (group[i]->get_defense() > 0)
											{
												while (group[i]->get_defense() > 0)
												{
													group[i]->set_defense(-1);
												}
											}
											group[i]->set_defense_mod(0);
										}
										else
										{
											group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_level() + group[i]->get_speed() + group[i]->get_intelligence() + rand_int + run);
										}
										if (run + 1 >= group[i]->get_level())
										{
											std::cout<< group[i]->get_enemies() << " manages to escape!" << endl;
											std::cout<< team[j]->get_hero() << " gained " << group[i]->get_experience() << " exp." << endl;
											team[j]->set_current_experience(group[i], 0);
											std::cout<< "You now have " << team[j]->get_current_experience() << " exp." << endl;
											team[j]->set_reputation(group[i]->get_reputation());
											std::cout<< "Your Current Reputation is: " << team[j]->get_reputation() << endl;

											system("pause");
											system("cls");
											group.clear();
											group_hlth = false;
											if (group_hlth == false)
											{
												group_size = false;
											}
											if (group_size == false)
											{

												fight = false;

											}
										}

									}
									else
									{
										if (group[i]->get_defense_mod() == true)
										{
											if (group[i]->get_defense() > 0)
											{
												while (group[i]->get_defense() > 0)
												{
													group[i]->set_defense(-1);
												}
											}
											group[i]->set_defense_mod(0);
										}
										else
										{
											group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_level() + group[i]->get_speed() + group[i]->get_intelligence() + rand_int);
										}

									}

								}
								else
								{
									if (group[i]->get_defense_mod() == true)
									{
										if (group[i]->get_defense() > 0)
										{
											while (group[i]->get_defense() > 0)
											{
												group[i]->set_defense(-1);
											}
										}

										group[i]->set_defense_mod(0);
									}
									else
									{
										group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_level() + group[i]->get_speed() + group[i]->get_intelligence() + rand_int);
									}

								}	

								for (size_t i = 0; i < group.size(); i++)
								{
									if (group[i]->get_bleeding() == true)
									{
										group[i]->set_health(-team[j]->get_bleed_dmg());
										std::cout << group[i]->get_enemies() << " is bleeding " << group[i]->get_health() << " Health left" << endl;
										system("pause");
										system("cls");

										if (group[i]->get_health() <= 0)
										{
											hero_hlth = false;
											if (hero_hlth == false)
											{
												dead_enemy();
												if (group.size() == 0)
												{
													while (team[j]->get_current_experience() >= team[j]->get_experience()) // if
													{
														level_up();

														
														int rand_int = rand() % 5;

														if (team[j]->get_defense_mod() == true)
														{
															if (group[i]->get_power() == "fire")
															{
																std::cout << team[j]->get_hero() << " is still on fire!" << endl;
																std::cout << group[i]->get_level() << " Damage!" << endl;
																team[j]->set_health(-group[i]->get_level());
																std::cout << team[j]->get_hero() << " has " << team[j]->get_health() << " health left!" << endl;
															}
															if (team[j]->get_defense() > 0)
															{
																while (team[j]->get_defense() > 0)
																{
																	team[j]->set_defense(-1);
																}
															}
															team[j]->set_defense_mod(0, group[i]->get_power(), group[i]->get_ice());
														}
														else
														{
															team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);
														}
													}

													std::cout << "Would you like to rest?" << endl;
													std::cout << "1. Yes" << endl;
													std::cout << "2. No" << endl;
													char a = 0;
													a = selection(a);
													if (a == '1')
													{
														std::cout << team[j]->get_hero() << " takes a short rest." << endl;
														rest();

														team[j]->print_stat();
														if (group.size() == 0)
														{
															std::cout << "here1" << endl;
															return;


														}

													}
													else if (a == '2')
													{
														team[j]->print_stat();
														if (group.size() == 0)
														{
															return;
														}
													}

												}
											}
										}
									}
								}

								for (size_t i = 0; i < group.size(); i++)
								{
									if (fight == false)
									{
										explosion = false;
										while (explosion_victim.size() != 0)
										{
											explosion_victim.pop_back();
										}
										break;
									}

// Bad Guys Attack*******************************************************************************************************************************
									if (!player_att)
									{
										if (group[i]->get_bleeding() == true)
										{
											group[i]->set_health(-team[j]->get_bleed_dmg());
											std::cout << group[i]->get_enemies() << " is bleeding " << group[i]->get_health() << " Health left" << endl;
											system("pause");
											system("cls");
											if (group[i]->get_health() <= 0)
											{
												hero_hlth = false;
												if (hero_hlth == false)
												{
													dead_enemy();
													if (group.size() == 0)
													{
														while (team[j]->get_current_experience() >= team[j]->get_experience()) // if
														{
															level_up();

															
															int rand_int = rand() % 5;

															if (team[j]->get_defense_mod() == true)
															{
																if (group[i]->get_power() == "fire")
																{
																	std::cout << team[j]->get_hero() << " is still on fire!" << endl;
																	std::cout << group[i]->get_level() << " Damage!" << endl;
																	team[j]->set_health(-group[i]->get_level());
																	std::cout << team[j]->get_hero() << " has " << team[j]->get_health() << " health left!" << endl;
																}
																if (team[j]->get_defense() > 0)
																{
																	while (team[j]->get_defense() > 0)
																	{
																		team[j]->set_defense(-1);
																	}
																}
																team[j]->set_defense_mod(0, group[i]->get_power(), group[i]->get_ice());
															}
															else
															{
																team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);
															}
														}

														std::cout << "Would you like to rest?" << endl;
														std::cout << "1. Yes" << endl;
														std::cout << "2. No" << endl;
														char a = 0;
														a = selection(a);
														if (a == '1')
														{
															std::cout << team[j]->get_hero() << " takes a short rest." << endl;
															rest();

															team[j]->print_stat();
															if (group.size() == 0)
															{
																std::cout << "here1" << endl;
																return;


															}

														}
														else if (a == '2')
														{
															team[j]->print_stat();
															if (group.size() == 0)
															{
																return;
															}
														}

													}
												}
											}
										}
										
										explosion_result(group_size, fight);

										std::cout<< group[i]->get_enemies() << " Is attacking!" << endl;

										
										
										int evade = rand() % team[j]->get_evade();
										if (team[j]->get_hero() == "Spiderman" || team[j]->get_hero() == "Black Widow")
										{
											if ((evade >= (team[j]->get_evade() * 0.7) && team[j]->get_defense_mod() > 0) && team[j]->get_hero() == "Spiderman")
											{
												system("pause");
												system("cls");
												
												std::cout<< "Spidy sense is tingling!" << endl;
												
												std::cout<< team[j]->get_hero() << " evades the on comming attack!" << endl;
												system("pause");
												system("cls");

												int h_counter = rand() % team[j]->get_speed() + team[j]->get_Cskill();
												int e_counter = rand() % group[i]->get_speed() + group[i]->get_Cskill();

												if (h_counter > e_counter)
												{
													counter_attack(team[j], group[i], "villian", h_counter, e_counter);
													system("pause");
													system("cls");
													if (team[j]->get_health() <= 0)
													{
														std::cout << p->get_hero() << " Has been killed!" << endl;
														std::cout << "GAME OVER!" << endl;
														return;
														//exit(_getch());
													}
												}
											}
											else if ((evade >= (team[j]->get_evade()* 0.9) && team[j]->get_defense_mod() > 0) && team[j]->get_hero() == "Black Widow")
											{
												system("pause");
												system("cls");
												
												std::cout << team[j]->get_hero() << " evades the on comming attack!" << endl;
												system("pause");
												system("cls");

												int h_counter = rand() % team[j]->get_speed() + team[j]->get_Cskill();
												int e_counter = rand() % group[i]->get_speed() + group[i]->get_Cskill();
												if (h_counter > e_counter)
												{
													counter_attack(team[j], group[i], "villian", h_counter, e_counter);
													system("pause");
													system("cls");
													if (team[j]->get_health() <= 0)
													{
														std::cout << p->get_hero() << " Has been killed!" << endl;
														std::cout << "GAME OVER!" << endl;
														return;
														//exit(_getch());
													}
												}

											}
											else
											{
												explosion_result(group_size, fight);

												
												int block = rand() % 10;
												group[i]->set_attack(team[j], group[i]);
												group[i]->get_power();
												if (group[i]->get_power() == "Multiply")
												{
													std::cout << group[i]->get_enemies() << " divided!" << endl;
													group[i]->set_power("");
													enemies *m3 = new enemies(*group[i]);
													group.push_back(m3);
												}
					
												if (group[i]->get_power() == "Explosive Touch")
												{
													explosion_victim.push_back(team[j]->get_hero());
													
													std::sort(explosion_victim.begin(), explosion_victim.end());
													explosion_victim.erase(unique(explosion_victim.begin(), explosion_victim.end()), explosion_victim.end());
													
													//problem here???
													explosion = true;
													system("pause");
													system("cls");
													
												}
												if (group[i]->get_power() == "Nano Assault")
												{
													team[j]->set_attack(group[i], team[j]);
													if (block >= 7)
													{


														std::cout<< team[j]->get_attack() / block << " Damage!" << endl;
														team[j]->set_health(-team[j]->get_attack() / block);
														std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
														system("pause");
														system("cls");


													}
													else
													{


														std::cout<< team[j]->get_attack() << " Damage!" << endl;
														team[j]->set_health(-team[j]->get_attack());
														std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
														system("pause");
														system("cls");


													}

												}
												else
												{
													if (block >= 7)
													{
														if (team[j]->get_hero() == "Iron Man" || team[j]->get_hero() == "Mr. Fantastic")
														{
															team[j]->set_reduce();
															if ((group[i]->get_attack() / block) - team[j]->get_reduce() <= 0)
															{
																std::cout<< "0 Damage!" << endl;
																team[j]->set_health(-0);
															}
															else
															{
																std::cout<< (group[i]->get_attack() / block) - team[j]->get_reduce() << " Damage!" << endl;
																team[j]->set_health(-group[i]->get_attack() / block);
																if (team[j]->get_health() > 0)
																{
																	team[j]->set_health(+team[j]->get_reduce());
																}

															}
															std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
															system("pause");
															system("cls");
														}
														else if (team[j]->get_hero() == "Captain America")
														{
															std::cout<< group[i]->get_attack() / block << " Damage!" << endl;
															team[j]->set_health(-group[i]->get_attack() / block);
															std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
															group[i]->set_evade();
															if (group[i]->get_evade() == false)
															{
																
															group[i]->set_health(-(group[i]->get_attack() - (group[i]->get_attack() / block)));
															std::cout<< team[j]->get_hero() << "'s shield reflects some of the Damage back!" << endl;
															std::cout<< group[i]->get_enemies() << " has " << group[i]->get_health() << " left" << endl;
															
															
															}
															system("pause");
															
														}
														else if (team[j]->get_hero() == "Black Panther")
														{
															std::cout<< group[i]->get_attack() / block << " Damage!" << endl;
															team[j]->set_health(-group[i]->get_attack() / block);
															std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
															group[i]->set_evade();
															if (group[i]->get_evade() == false)
															{

															group[i]->set_health(-(group[i]->get_attack() - (group[i]->get_attack() / block)));
															std::cout<< team[j]->get_hero() << "'s armor reflects some of the Damage back!" << endl;
															std::cout<< group[i]->get_enemies() << " has " << group[i]->get_health() << " left" << endl;
															
															
															}
															system("pause");
															
														}
														else
														{
															std::cout<< group[i]->get_attack() / block << " Damage!" << endl;
															team[j]->set_health(-group[i]->get_attack() / block);
															std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
															system("pause");
														}

													}
													else
													{
														if (team[j]->get_hero() == "Iron Man" || team[j]->get_hero() == "Mr. Fantastic")
														{
															team[j]->set_reduce();
															if (group[i]->get_attack() - team[j]->get_reduce() <= 0)
															{
																std::cout<< "0 Damage!" << endl;
																team[j]->set_health(-0);
															}
															else
															{
																std::cout<< group[i]->get_attack() - team[j]->get_reduce() << " Damage!" << endl;
																team[j]->set_health(-group[i]->get_attack());
																if (team[j]->get_health() > 0)
																{
																	team[j]->set_health(+team[j]->get_reduce());
																}

															}
															std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
															system("pause");
															system("cls");
														}
														else
														{
															std::cout<< group[i]->get_attack() << " Damage!" << endl;
															team[j]->set_health(-group[i]->get_attack());
															std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
															system("pause");
														}

													}
													system("cls");
													for (size_t i = 0; i < group.size(); i++)
													{
														if (group[i]->get_bleeding() == true)
														{
															group[i]->set_health(-team[j]->get_bleed_dmg());
															std::cout << group[i]->get_enemies() << " is bleeding " << group[i]->get_health() << " Health left" << endl;
															system("pause");
															system("cls");
															if (group[i]->get_health() <= 0)
															{
																hero_hlth = false;
																if (hero_hlth == false)
																{
																	dead_enemy();
																	if (group.size() == 0)
																	{
																		while (team[j]->get_current_experience() >= team[j]->get_experience()) // if
																		{
																			level_up();

																			
																			int rand_int = rand() % 5;

																			if (team[j]->get_defense_mod() == true)
																			{
																				if (group[i]->get_power() == "fire")
																				{
																					std::cout << team[j]->get_hero() << " is still on fire!" << endl;
																					std::cout << group[i]->get_level() << " Damage!" << endl;
																					team[j]->set_health(-group[i]->get_level());
																					std::cout << team[j]->get_hero() << " has " << team[j]->get_health() << " health left!" << endl;
																				}
																				if (team[j]->get_defense() > 0)
																				{
																					while (team[j]->get_defense() > 0)
																					{
																						team[j]->set_defense(-1);
																					}
																				}
																				team[j]->set_defense_mod(0, group[i]->get_power(), group[i]->get_ice());
																			}
																			else
																			{
																				team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);
																			}
																		}

																		std::cout << "Would you like to rest?" << endl;
																		std::cout << "1. Yes" << endl;
																		std::cout << "2. No" << endl;
																		char a = 0;
																		a = selection(a);
																		if (a == '1')
																		{
																			std::cout << team[j]->get_hero() << " takes a short rest." << endl;
																			rest();

																			team[j]->print_stat();
																			if (group.size() == 0)
																			{
																				std::cout << "here1" << endl;
																				return;


																			}

																		}
																		else if (a == '2')
																		{
																			team[j]->print_stat();
																			if (group.size() == 0)
																			{
																				return;
																			}
																		}

																	}
																}
															}
														}
													}
													if (group[i]->get_power() == "Bleed" && team[j]->get_hero() != "Mr. Fantastic")
													{
														std::cout<< group[i]->get_attack() << " Damage!" << endl;
														team[j]->set_health(-group[i]->get_attack());
														std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
														group[i]->set_bleed_dmg(+group[i]->get_bleed());
														team[j]->set_health(-group[i]->get_bleed_dmg());
														std::cout<< team[j]->get_hero() << " is bleeding " << team[j]->get_health() << " Health left" << endl;
														system("pause");
														system("cls");
														
														if (group[i]->get_health() <= 0)
														{
															dead_enemy();
															break;	
															
														}

													}


												}
											}
										}
										else
										{
											if (evade >= (team[j]->get_evade() * 0.9) && team[j]->get_defense_mod() > 0)
											{
												system("pause");
												system("cls");
												std::cout<< team[j]->get_hero() << " evades the on comming attack!" << endl;
												int h_counter = rand() % team[j]->get_speed() + team[j]->get_Cskill();
												int e_counter = rand() % group[i]->get_speed() + group[i]->get_Cskill();
												if (h_counter > e_counter)
												{
													counter_attack(team[j], group[i], "hero", h_counter, e_counter);
													system("pause");
													system("cls");
													if (group[i]->get_health() <= 0)
													{
														dead_enemy();
														break;
													}
												}
												
											}
											else
											{
												explosion_result(group_size, fight);

												
												int block = rand() % 10;
												group[i]->set_attack(team[j], group[i]);
												group[i]->get_power();
												if (group[i]->get_power() == "Multiply")
												{
													std::cout << group[i]->get_enemies() << " divided!" << endl;
													group[i]->set_power("");
													enemies *m0 = new enemies(*group[i]);
													group.push_back(m0);
												}
												
												if (group[i]->get_power() == "Nano Assault")
												{
													team[j]->set_attack(group[i], team[j]);
													if (block >= 7)
													{

														std::cout<< team[j]->get_attack() / block << " Damage!" << endl;
														team[j]->set_health(-team[j]->get_attack() / block);
														std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
														system("pause");
														system("cls");


													}
													else
													{

														std::cout<< team[j]->get_attack() << " Damage!" << endl;
														team[j]->set_health(-team[j]->get_attack());
														std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
														system("pause");
														system("cls");


													}


												}
												else
												{
													if (block >= 7)
													{
														if (team[j]->get_hero() == "Iron Man" || team[j]->get_hero() == "Mr. Fantastic")
														{
															team[j]->set_reduce();
															if ((group[i]->get_attack() / block) - team[j]->get_reduce() <= 0)
															{
																std::cout<< "block" << endl;
																std::cout<< group[i]->get_attack() << endl;
																std::cout<< team[j]->get_reduce() << endl;

																std::cout<< "0 Damage!" << endl;
																team[j]->set_health(-0);

															}
															else if (team[j]->get_hero() == "Captain America")
															{
																std::cout<< group[i]->get_attack() / block << " Damage!" << endl;
																team[j]->set_health(-group[i]->get_attack() / block);
																std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;

																group[i]->set_evade();
																if (group[i]->get_evade() == false)
																{
																	
																group[i]->set_health(-(group[i]->get_attack() - (group[i]->get_attack() / block)));
																std::cout<< team[j]->get_hero() << "'s shield reflects some of the Damage back!" << endl;
																std::cout<< group[i]->get_enemies() << " has " << group[i]->get_health() << " left" << endl;
																
																}
																system("pause");
															}
															else if (team[j]->get_hero() == "Black Panther")
															{
																std::cout<< group[i]->get_attack() / block << " Damage!" << endl;
																team[j]->set_health(-group[i]->get_attack() / block);
																std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;

																group[i]->set_evade();
																if (group[i]->get_evade() == false)
																{
																	
																group[i]->set_health(-(group[i]->get_attack() - (group[i]->get_attack() / block)));
																std::cout<< team[j]->get_hero() << "'s armor reflects some of the Damage back!" << endl;
																std::cout<< group[i]->get_enemies() << " has " << group[i]->get_health() << " left" << endl;
																
																
																}
																system("pause");
															}
															else
															{
																std::cout<< group[i]->get_attack() << endl;
																std::cout<< team[j]->get_reduce() << endl;

																std::cout<< (group[i]->get_attack() / block) - team[j]->get_reduce() << " Damage!" << endl;
																team[j]->set_health(-group[i]->get_attack() / block);
																if (team[j]->get_health() > 0)
																{
																	team[j]->set_health(+team[j]->get_reduce());
																}

															}
															std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
															system("pause");
															system("cls");
														}
														else
														{
															std::cout<< group[i]->get_attack() / block << " Damage!" << endl;
															team[j]->set_health(-group[i]->get_attack() / block);
															std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
															system("pause");
															system("cls");
														}

													}
													else
													{
														if (team[j]->get_hero() == "Iron Man" || team[j]->get_hero() == "Mr. Fantastic")
														{
															team[j]->set_reduce();
															if (group[i]->get_attack() - team[j]->get_reduce() <= 0)
															{
																std::cout<< "0 Damage!" << endl;
																team[j]->set_health(-0);
															}
															else
															{
																std::cout<< group[i]->get_attack() - team[j]->get_reduce() << " Damage!" << endl;
																team[j]->set_health(-group[i]->get_attack());
																if (team[j]->get_health() > 0)
																{
																	team[j]->set_health(+team[j]->get_reduce());
																}


															}
															std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
															system("pause");
															system("cls");
														}
														else
														{
															std::cout<< group[i]->get_attack() << " Damage!" << endl;
															team[j]->set_health(-group[i]->get_attack());
															std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
															system("pause");
															system("cls");
														}

													}
													for (size_t i = 0; i < group.size(); i++)
													{
														if (group[i]->get_bleeding() == true)
														{
															group[i]->set_health(-team[j]->get_bleed_dmg());
															std::cout << group[i]->get_enemies() << " is bleeding " << group[i]->get_health() << " Health left" << endl;
															system("pause");
															system("cls");
															if (group[i]->get_health() <= 0)
															{
																hero_hlth = false;
																if (hero_hlth == false)
																{
																	dead_enemy();
																	if (group.size() == 0)
																	{
																		while (team[j]->get_current_experience() >= team[j]->get_experience()) // if
																		{
																			level_up();

																			
																			int rand_int = rand() % 5;

																			if (team[j]->get_defense_mod() == true)
																			{
																				if (group[i]->get_power() == "fire")
																				{
																					std::cout << team[j]->get_hero() << " is still on fire!" << endl;
																					std::cout << group[i]->get_level() << " Damage!" << endl;
																					team[j]->set_health(-group[i]->get_level());
																					std::cout << team[j]->get_hero() << " has " << team[j]->get_health() << " health left!" << endl;
																				}
																				if (team[j]->get_defense() > 0)
																				{
																					while (team[j]->get_defense() > 0)
																					{
																						team[j]->set_defense(-1);
																					}
																				}
																				team[j]->set_defense_mod(0, group[i]->get_power(), group[i]->get_ice());
																			}
																			else
																			{
																				team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);
																			}
																		}

																		std::cout << "Would you like to rest?" << endl;
																		std::cout << "1. Yes" << endl;
																		std::cout << "2. No" << endl;
																		char a = 0;
																		a = selection(a);
																		if (a == '1')
																		{
																			std::cout << team[j]->get_hero() << " takes a short rest." << endl;
																			rest();

																			team[j]->print_stat();
																			if (group.size() == 0)
																			{
																				std::cout << "here1" << endl;
																				return;


																			}

																		}
																		else if (a == '2')
																		{
																			team[j]->print_stat();
																			if (group.size() == 0)
																			{
																				return;
																			}
																		}

																	}
																}
															}
														}
													}
													if (group[i]->get_power() == "Bleed" && team[j]->get_hero() != "Mr. Fantastic")
													{
														std::cout<< group[i]->get_attack() << " Damage!" << endl;
														team[j]->set_health(-group[i]->get_attack());
														std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
														group[i]->set_bleed_dmg(+group[i]->get_bleed());
														team[j]->set_health(-group[i]->get_bleed_dmg());
														std::cout<< team[j]->get_hero() << " is bleeding " << team[j]->get_health() << " Health left" << endl;
														system("pause");
														system("cls");
														if (group[i]->get_health() <= 0)
														{
															dead_enemy();
															break;
														}

													}

												}
											}
										}


										team[j]->reset_defense();
										team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);
										if (team[j]->get_health() < (team[j]->get_durability() * (15 + team[j]->get_level()) + 100) / 3)
										{
											if (team[j]->get_defense_mod() == true)
											{
												if (group[i]->get_power() == "fire")
												{
													std::cout << team[j]->get_hero() << " is still on fire!" << endl;
													std::cout << group[i]->get_level() << " Damage!" << endl;
													team[j]->set_health(-group[i]->get_level());
													std::cout << team[j]->get_hero() << " has " << team[j]->get_health() << " health left!" << endl;
												}
												if (team[j]->get_defense() > 0)
												{
													while (team[j]->get_defense() > 0)
													{
														team[j]->set_defense(-1);
													}
												}
												team[j]->set_defense_mod(0, group[i]->get_power(), group[i]->get_ice());
											}
											else
											{
												team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 20);
											}
											
											int second_chance = rand() % 100;
											if (second_chance > 80)
											{
												if (escape == false)
												{
													escape = true;
												}
											}
											while (escape)
											{
												std::cout<< team[j]->get_hero() << " sees and opening to escape. will you runaway?" << endl;
												std::cout<< "1. Yes, try to runaway" << endl;
												std::cout<< "2. No, stay and fight" << endl;

												char to_run = 0;
												to_run = selection(to_run);

												if (to_run == '1')
												{
													
													int run = rand() % 5;
													int hero = rand() % team[j]->get_level();
													int bad = rand() % group[i]->get_level();
													if (hero + run >= bad)
													{
														std::cout<< team[j]->get_hero() << " manages to runaway." << endl;
														system("pause");
														system("cls");
														group.clear();
														escape = false;
														return;



													}
													else
													{
														std::cout<< team[j]->get_hero() << " can't escape!" << endl;
														escape = false;
													}
												}
												else if (to_run == '2')
												{
													std::cout<< team[j]->get_hero() << " decides to stay and fight." << endl;
													escape = false;
												}
												else
												{
													std::cout<< "Please select a correct choice." << endl;
												}
											}


										}
										else
										{
											if (team[j]->get_defense_mod() == true)
											{
												if (group[i]->get_power() == "fire")
												{
													std::cout << team[j]->get_hero() << " is still on fire!" << endl;
													std::cout << group[i]->get_level() << " Damage!" << endl;
													team[j]->set_health(-group[i]->get_level());
													std::cout << team[j]->get_hero() << " has " << team[j]->get_health() << " health left!" << endl;
												}
												if (team[j]->get_defense() > 0)
												{
													while (team[j]->get_defense() > 0)
													{
														team[j]->set_defense(-1);
													}
												}
												team[j]->set_defense_mod(0, group[i]->get_power(), group[i]->get_ice());
											}
											else
											{
												team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);
											}
										}
										group[i]->reset_defense();
										group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_speed() + group[i]->get_level() + group[i]->get_intelligence() + rand_int);
										if (group[i]->get_boss())
										{
											if (group[j]->get_health() < (group[j]->get_durability() * (15 + group[j]->get_level()) + 100) / 3)
											{
												
												int run = rand() % group[i]->get_level();
												if (group[i]->get_defense_mod() == true)
												{
													if (group[i]->get_defense() > 0)
													{
														while (group[i]->get_defense() > 0)
														{
															group[i]->set_defense(-1);
														}
													}

													group[i]->set_defense_mod(0);
												}
												else
												{
													group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_level() + group[i]->get_speed() + group[i]->get_intelligence() + rand_int + run);
												}
												if (run + 1 >= group[i]->get_level())
												{
													std::cout<< group[i]->get_enemies() << " manages to escape!" << endl;
													std::cout<< team[j]->get_hero() << " gained " << group[i]->get_experience() << " exp." << endl;
													team[j]->set_current_experience(group[i], 0);
													std::cout<< "You now have " << team[j]->get_current_experience() << " exp." << endl;
													team[j]->set_reputation(group[i]->get_reputation());
													std::cout<< "Your Current Reputation is: " << team[j]->get_reputation() << endl;

													system("pause");
													system("cls");
													group.clear();
													group_hlth = false;
													if (group_hlth == false)
													{
														group_size = false;
													}
													if (group_size == false)
													{

														fight = false;

													}
												}
											}
											else
											{
												if (group[i]->get_defense_mod() == true)
												{
													if (group[i]->get_defense() > 0)
													{
														while (group[i]->get_defense() > 0)
														{
															group[i]->set_defense(-1);
														}
													}
													group[i]->set_defense_mod(0);
												}
												else
												{
													group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_level() + group[i]->get_speed() + group[i]->get_intelligence() + rand_int);
												}

											}

										}
										else
										{
											if (group[i]->get_defense_mod() == true)
											{
												if (group[i]->get_defense() > 0)
												{
													while (group[i]->get_defense() > 0)
													{
														group[i]->set_defense(-1);
													}
												}
												group[i]->set_defense_mod(0);
											}
											else
											{
												group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_level() + group[i]->get_speed() + group[i]->get_intelligence() + rand_int);
											}
										}

										if (team[j]->get_health() <= 0)
										{
											std::cout<< p->get_hero() << " Has been killed!" << endl;
											std::cout<< "GAME OVER!" << endl;
											return;
											//exit(_getch());
										}




										group_hlth = false;


									}//if bad guy attacks
									if (group[i]->get_defense_mod() == true)
									{
										std::cout << "defense check here" << endl;
										if (group[i]->get_defense() > 0)
										{
											while (group[i]->get_defense() > 0)
											{
												group[i]->set_defense(-1);
											}
										}
										group[i]->set_defense_mod(0);
									}

									if (team[j]->get_defense_mod() == true)
									{
										if (team[j]->get_defense() > 0)
										{
											while (team[j]->get_defense() > 0)
											{
												team[j]->set_defense(-1);
											}
										}
										team[j]->set_defense_mod(0, group[i]->get_power(), group[i]->get_ice());
									}

								}
							}




							if (group_hlth == false)
							{
								group_size = false;
							}
							if (group_size == false)
							{

								fight = false;

							}

							}


						}// group_hlth



					}


				}

			}// group_Size
			(group.size() > 0 ? (group[0]->get_enum() == POWDERKEG ? group[0]->set_nitro(1) : 0) : 0);
			if (group.size() == 0)
			{
				while (team[j]->get_current_experience() >= team[j]->get_experience()) // if
				{
					level_up();

					
					int rand_int = rand() % 5;

					if (team[j]->get_defense_mod() == true)
					{
						if (team[j]->get_defense() > 0)
						{
							while (team[j]->get_defense() > 0)
							{
								team[j]->set_defense(-1);
							}
						}
						team[j]->set_defense_mod(0, "", 0);
					}
					else
					{
						team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);
					}
				}

				std::cout << "Would you like to rest?" << endl;
				std::cout << "1. Yes" << endl;
				std::cout << "2. No" << endl;
				char a = 0;
				a = selection(a);
				if (a == '1')
				{
					std::cout<< team[j]->get_hero() << " takes a short rest." << endl;
					rest();
					team[j]->print_stat();
					if (group.size() == 0)
					{
						explosion = false;
						while (explosion_victim.size() != 0)
						{
							explosion_victim.pop_back();
						}
						fighting = false;
					}

				}
				else if (a == '2')
				{
					team[j]->print_stat();
					if (group.size() == 0)
					{
						explosion = false;
						while (explosion_victim.size() != 0)
						{
							explosion_victim.pop_back();
						}
						fighting = false;
					}
				}

			}

			//if loop



			// ENEMIES ATTACK STARTS HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

			else  if (!player_att)
			{

				while (hero_hlth)
				{
					//explosion_result(group_size, fight);

					if (team[j]->get_hero() == "Wolverine")
					{
						team[j]->max_hlth();
						if (team[j]->get_health() < team[j]->get_max())
						{
							if (group[0]->get_power() == "Power Steal")
							{
								std::cout << team[j]->get_hero() << " can't regenerate health!" << endl;
							}
							else
							{
								std::cout << team[j]->get_hero() << ", Regenerates " << team[j]->get_regen() << " Health." << endl;
								team[j]->set_health(+team[j]->get_regen());
								std::cout << "Current Health: " << team[j]->get_health() << endl;

							}
							system("pause");
							system("cls");
						}
					}
					if (group[0]->get_regen() > 0)
					{
						regen_hlth(group[0]);
					}


					for (size_t i = 0; i < group.size(); i++)
					{
						explosion_result(group_size, fight);

						if (hero_hlth == false)
						{
							break;

						}
						
						int evade = rand() % team[j]->get_evade();
						if (team[j]->get_hero() == "Spiderman" || team[j]->get_hero() == "Black Widow")
						{

							if ((evade >= (team[j]->get_evade() * 100) && team[j]->get_defense_mod() > 0 && team[j]->get_hero() == "Spiderman") || (evade >= (team[j]->get_evade() * 0.8) && team[j]->get_defense_mod() > 0 && team[j]->get_hero() == "Black Widow"))//0.7
							{
								std::cout<< group[i]->get_enemies() << " Is attacking!" << endl;
								system("pause");
								system("cls");
								if (team[j]->get_hero() == "Spiderman")
								{
									std::cout<< "Spidy sense is tingling!" << endl;
								}
								std::cout<< team[j]->get_hero() << " evades the on comming attack!" << endl;
								int h_counter = rand() % team[j]->get_speed() + team[j]->get_Cskill();
								int e_counter = rand() % group[i]->get_speed() + group[i]->get_Cskill();
								if (h_counter > e_counter)
								{
									counter_attack(team[j], group[i], "hero", h_counter, e_counter);
								}
								system("pause");
								system("cls");
								if (group[i]->get_health() <= 0)
								{
									hero_hlth = false;
									if (hero_hlth == false)
									{
										dead_enemy();
										if (group.size() == 0)
										{
											while (team[j]->get_current_experience() >= team[j]->get_experience()) // if
											{
												level_up();

												
												int rand_int = rand() % 5;

												if (team[j]->get_defense_mod() == true)
												{
													if (group[i]->get_power() == "fire")
													{
														std::cout << team[j]->get_hero() << " is still on fire!" << endl;
														std::cout << group[i]->get_level() << " Damage!" << endl;
														team[j]->set_health(-group[i]->get_level());
														std::cout << team[j]->get_hero() << " has " << team[j]->get_health() << " health left!" << endl;
													}
													if (team[j]->get_defense() > 0)
													{
														while (team[j]->get_defense() > 0)
														{
															team[j]->set_defense(-1);
														}
													}
													team[j]->set_defense_mod(0, group[i]->get_power(), group[i]->get_ice());
												}
												else
												{
													team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);
												}
											}

											std::cout << "Would you like to rest?" << endl;
											std::cout << "1. Yes" << endl;
											std::cout << "2. No" << endl;
											char a = 0;
											a = selection(a);
											if (a == '1')
											{
												std::cout << team[j]->get_hero() << " takes a short rest." << endl;
												rest();

												team[j]->print_stat();
												if (group.size() == 0)
												{
													std::cout << "here1" << endl;
													return;


												}

											}
											else if (a == '2')
											{
												team[j]->print_stat();
												if (group.size() == 0)
												{
													return;
												}
											}

										}
									}
								}
								int rand_int = rand() % 5;
								team[j]->reset_defense();
								team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);
								
								if (team[j]->get_health() < (team[j]->get_durability() * (15 + team[j]->get_level()) + 100) / 3)
								{
									if (team[j]->get_defense_mod() == true)
									{
										if (group[i]->get_power() == "fire")
										{
											std::cout << team[j]->get_hero() << " is still on fire!" << endl;
											std::cout << group[i]->get_level() << " Damage!" << endl;
											team[j]->set_health(-group[i]->get_level());
											std::cout << team[j]->get_hero() << " has " << team[j]->get_health() << " health left!" << endl;
										}
										if (team[j]->get_defense() > 0)
										{
											while (team[j]->get_defense() > 0)
											{
												team[j]->set_defense(-1);
											}
										}
										team[j]->set_defense_mod(0, group[i]->get_power(), group[i]->get_ice());
									}
									else
									{
										team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 20);
									}										
									int second_chance = rand() % 100;
									if (second_chance > 80)
									{
										if (escape == false)
										{
											escape = true;
										}
									}
									while (escape)
									{
										std::cout<< team[j]->get_hero() << " sees and opening to escape. will you runaway?" << endl;
										std::cout<< "1. Yes, try to runaway" << endl;
										std::cout<< "2. No, stay and fight" << endl;

										char to_run = 0;
										to_run = selection(to_run);

										if (to_run == '1')
										{
											
											int run = rand() % 5;
											int hero = rand() % team[j]->get_level();
											int bad = rand() % group[i]->get_level();
											if (hero + run >= bad)
											{
												std::cout<< team[j]->get_hero() << " manages to runaway." << endl;
												system("pause");
												system("cls");
												group.clear();
												escape = false;
												return;

											}
											else
											{
												std::cout<< team[j]->get_hero() << " can't escape!" << endl;
												escape = false;
											}
										}
										else if (to_run == '2')
										{
											std::cout<< team[j]->get_hero() << " decides to stay and fight." << endl;
											escape = false;
										}
										else
										{
											std::cout<< "Please select a correct choice." << endl;
										}
									}
								}
								else
								{
									if (team[j]->get_defense_mod() == true)
									{
										if (group[i]->get_power() == "fire")
										{
											std::cout << team[j]->get_hero() << " is still on fire!" << endl;
											std::cout << group[i]->get_level() << " Damage!" << endl;
											team[j]->set_health(-group[i]->get_level());
											std::cout << team[j]->get_hero() << " has " << team[j]->get_health() << " health left!" << endl;
										}
										if (team[j]->get_defense() > 0)
										{
											while (team[j]->get_defense() > 0)
											{
												team[j]->set_defense(-1);
											}
										}
										team[j]->set_defense_mod(0, group[i]->get_power(), group[i]->get_ice());
									}
									else
									{
										team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);
									}
								}
								group[i]->reset_defense();
								group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_speed() + group[i]->get_level() + group[i]->get_intelligence() + rand_int);
								if (group[i]->get_boss())
								{
									if (group[j]->get_health() < (group[j]->get_durability() * (15 + group[j]->get_level()) + 100) / 3)
									{
										
										int run = rand() % group[i]->get_level();
										if (group[i]->get_defense_mod() == true)
										{
											if (group[i]->get_defense() > 0)
											{
												while (group[i]->get_defense() > 0)
												{
													group[i]->set_defense(-1);
												}
											}
											group[i]->set_defense_mod(0);
										}
										else
										{
											group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_level() + group[i]->get_speed() + group[i]->get_intelligence() + rand_int + run);
										}											if (run + 1 >= group[i]->get_level())
										{
											std::cout<< group[i]->get_enemies() << " manages to escape!" << endl;
											std::cout<< team[j]->get_hero() << " gained " << group[i]->get_experience() << " exp." << endl;
											team[j]->set_current_experience(group[i], 0);
											std::cout<< "You now have " << team[j]->get_current_experience() << " exp." << endl;
											team[j]->set_reputation(group[i]->get_reputation());
											std::cout<< "Your Current Reputation is: " << team[j]->get_reputation() << endl;

											system("pause");
											system("cls");
											group.clear();
											hero_hlth = false;
											if (hero_hlth == false)
											{


												fight = false;
												break;

											}
										}
									}
									else
									{
										if (group[i]->get_defense_mod() == true)
										{
											if (group[i]->get_defense() > 0)
											{
												while (group[i]->get_defense() > 0)
												{
													group[i]->set_defense(-1);
												}
											}
											group[i]->set_defense_mod(0);
										}
										else
										{
											group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_level() + group[i]->get_speed() + group[i]->get_intelligence() + rand_int);
										}
									}

								}
								else
								{
									if (group[i]->get_defense_mod() == true)
									{
										if (group[i]->get_defense() > 0)
										{
											while (group[i]->get_defense() > 0)
											{
												group[i]->set_defense(-1);
											}
										}
										group[i]->set_defense_mod(0);
									}
									else
									{
										group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_level() + group[i]->get_speed() + group[i]->get_intelligence() + rand_int);
									}
								}
								//system("pause");
								system("cls");
								for (size_t i = 0; i < group.size(); i++)
								{
									if (hero_hlth == false)
									{
										break;
									}
									if (player_att)
									{
										hero_hlth = false;

									}

								}
							}
						}
						else if (team[j]->get_hero() != "Spiderman" || team[j]->get_hero() != "Black Widow")
						{
							if (evade >= (team[j]->get_evade() * 0.9) && team[j]->get_defense_mod() > 0)
							{
								std::cout<< group[i]->get_enemies() << " Is attacking!" << endl;
								system("pause");
								system("cls");
								std::cout<< team[j]->get_hero() << " evades the on comming attack!" << endl;
								int h_counter = rand() % team[j]->get_speed() + team[j]->get_Cskill();
								int e_counter = rand() % group[i]->get_speed() + group[i]->get_Cskill();

								if (h_counter > e_counter)
								{
									counter_attack(team[j], group[i], "hero", h_counter, e_counter);
									system("pause");
									system("cls");
								}
								
								if (group[i]->get_health() <= 0)
								{
									hero_hlth = false;
									if (hero_hlth == false)
									{
										dead_enemy();

										if (group.size() == 0)
										{
											while (team[j]->get_current_experience() >= team[j]->get_experience()) // if
											{
												level_up();
												
												int rand_int = rand() % 5;

												if (team[j]->get_defense_mod() == true)
												{
													if (group[i]->get_power() == "fire")
													{
														std::cout << team[j]->get_hero() << " is still on fire!" << endl;
														std::cout << group[i]->get_level() << " Damage!" << endl;
														team[j]->set_health(-group[i]->get_level());
														std::cout << team[j]->get_hero() << " has " << team[j]->get_health() << " health left!" << endl;
													}
													if (team[j]->get_defense() > 0)
													{
														while (team[j]->get_defense() > 0)
														{
															team[j]->set_defense(-1);
														}
													}
													team[j]->set_defense_mod(0, group[i]->get_power(), group[i]->get_ice());
												}
												else
												{
													team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);
												}
											}

											std::cout << "Would you like to rest?" << endl;
											std::cout << "1. Yes" << endl;
											std::cout << "2. No" << endl;
											char a = 0;
											a = selection(a);
											if (a == '1')
											{
												std::cout << team[j]->get_hero() << " takes a short rest." << endl;
												rest();

												team[j]->print_stat();
												if (group.size() == 0)
												{
													std::cout << "here1" << endl;
													return;


												}

											}
											else if (a == '2')
											{
												team[j]->print_stat();
												if (group.size() == 0)
												{
													return;
												}
											}

										}
										


									}
								}
								int rand_int = rand() % 5;
								team[j]->reset_defense();
								team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);
								
								if (team[j]->get_health() < (team[j]->get_durability() * (15 + team[j]->get_level()) + 100) / 3)
								{
									if (team[j]->get_defense_mod() == true)
									{
										if (group[i]->get_power() == "fire")
										{
											std::cout << team[j]->get_hero() << " is still on fire!" << endl;
											std::cout << group[i]->get_level() << " Damage!" << endl;
											team[j]->set_health(-group[i]->get_level());
											std::cout << team[j]->get_hero() << " has " << team[j]->get_health() << " health left!" << endl;
										}
										if (team[j]->get_defense() > 0)
										{
											while (team[j]->get_defense() > 0)
											{
												team[j]->set_defense(-1);
											}
										}
										team[j]->set_defense_mod(0, group[i]->get_power(), group[i]->get_ice());
									}
									else
									{
										team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 20);
									}										
									int second_chance = rand() % 100;
									if (second_chance > 80)
									{
										if (escape == false)
										{
											escape = true;
										}
									}
									while (escape)
									{
										std::cout<< team[j]->get_hero() << " sees and opening to escape. will you runaway?" << endl;
										std::cout<< "1. Yes, try to runaway" << endl;
										std::cout<< "2. No, stay and fight" << endl;

										char to_run = 0;
										to_run = selection(to_run);

										if (to_run == '1')
										{
											
											int run = rand() % 5;
											int hero = rand() % team[j]->get_level();
											int bad = rand() % group[i]->get_level();
											if (hero + run >= bad)
											{
												std::cout<< team[j]->get_hero() << " manages to runaway." << endl;
												system("pause");
												system("cls");
												group.clear();
												escape = false;
												return;


											}
											else
											{
												std::cout<< team[j]->get_hero() << " can't escape!" << endl;
												escape = false;
											}
										}
										else if (to_run == '2')
										{
											std::cout<< team[j]->get_hero() << " decides to stay and fight." << endl;
											escape = false;
										}
										else
										{
											std::cout<< "Please select a correct choice." << endl;
										}
									}
								}
								else
								{
									if (team[j]->get_defense_mod() == true)
									{
										if (group[i]->get_power() == "fire")
										{
											std::cout << team[j]->get_hero() << " is still on fire!" << endl;
											std::cout << group[i]->get_level() << " Damage!" << endl;
											team[j]->set_health(-group[i]->get_level());
											std::cout << team[j]->get_hero() << " has " << team[j]->get_health() << " health left!" << endl;
										}
										if (team[j]->get_defense() > 0)
										{
											while (team[j]->get_defense() > 0)
											{
												team[j]->set_defense(-1);
											}
										}
										team[j]->set_defense_mod(0, group[i]->get_power(), group[i]->get_ice());
									}
									else
									{
										team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);
									}
								}
								if (i >= group.size())
								{
									i = group.size() - 1;
								}
								group[i]->reset_defense();
								group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_speed() + group[i]->get_level() + group[i]->get_intelligence() + rand_int);
								if (group[i]->get_boss())
								{
									if (group[j]->get_health() < (group[j]->get_durability() * (15 + group[j]->get_level()) + 100) / 3)
									{
										
										int run = rand() % group[i]->get_level();
										if (group[i]->get_defense_mod() == true)
										{
											if (group[i]->get_defense() > 0)
											{
												while (group[i]->get_defense() > 0)
												{
													group[i]->set_defense(-1);
												}
											}
											group[i]->set_defense_mod(0);
										}
										else
										{
											group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_level() + group[i]->get_speed() + group[i]->get_intelligence() + rand_int + run);
										}											if (run + 1 >= group[i]->get_level())
										{
											std::cout<< group[i]->get_enemies() << " manages to escape!" << endl;
											std::cout<< team[j]->get_hero() << " gained " << group[i]->get_experience() << " exp." << endl;
											team[j]->set_current_experience(group[i], 0);
											std::cout<< "You now have " << team[j]->get_current_experience() << " exp." << endl;
											team[j]->set_reputation(group[i]->get_reputation());
											std::cout<< "Your Current Reputation is: " << team[j]->get_reputation() << endl;

											system("pause");
											system("cls");
											group.clear();
											hero_hlth = false;
											if (hero_hlth == false)
											{

												fight = false;
												break;

											}
										}
									}
									else
									{
										if (group[i]->get_defense_mod() == true)
										{
											if (group[i]->get_defense() > 0)
											{
												while (group[i]->get_defense() > 0)
												{
													group[i]->set_defense(-1);
												}
											}
											group[i]->set_defense_mod(0);
										}
										else
										{
											group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_level() + group[i]->get_speed() + group[i]->get_intelligence() + rand_int);
										}
									}

								}
								else
								{
									if (group[i]->get_defense_mod() == true)
									{
										if (group[i]->get_defense() > 0)
										{
											while (group[i]->get_defense() > 0)
											{
												group[i]->set_defense(-1);
											}
										}
										group[i]->set_defense_mod(0);
									}
									else
									{
										group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_level() + group[i]->get_speed() + group[i]->get_intelligence() + rand_int);
									}
								}
								system("pause");
								system("cls");
								for (size_t i = 0; i < group.size(); i++)
								{
									if (hero_hlth == false)
									{
										break;
									}
									if (player_att)
									{
										hero_hlth = false;

									}

								}
							}


						}



						if (hero_hlth == false)
						{
							break;
						}
						
						std::cout<< group[i]->get_enemies() << " Is attacking!" << endl;
						
						int block = rand() % 10;
						if (block >= 7)
						{
							explosion_result(group_size, fight);

							std::cout<< team[j]->get_hero() << " blocks the incoming attack!" << endl;
							group[i]->set_attack(team[j], group[i]);
							group[i]->get_power();
							if (group[i]->get_power() == "Multiply")
							{
								std::cout << group[i]->get_enemies() << " divided!" << endl;
								group[i]->set_power("");
								enemies *m1 = new enemies(*group[i]);
								group.push_back(m1);
							}
							
							if (group[i]->get_power() == "Nano Assault")
							{

								team[j]->set_attack(group[i], team[j]);
								std::cout<< team[j]->get_attack() / block << " Damage!" << endl;
								team[j]->set_health(-team[j]->get_attack() / block);
								std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
								system("pause");
								system("cls");


							}
							else
							{


								if (team[j]->get_hero() == "Iron Man" || team[j]->get_hero() == "Mr. Fantastic")
								{
									team[j]->set_reduce();
									if ((group[i]->get_attack() / block) - team[j]->get_reduce() <= 0)
									{
										std::cout<< "0 Damage!" << endl;
										team[j]->set_health(-0);
									}
									else
									{
										std::cout<< (group[i]->get_attack() / block) - team[j]->get_reduce() << " Damage!" << endl;
										team[j]->set_health(-group[i]->get_attack() / block);
										if (team[j]->get_health() > 0)
										{
											team[j]->set_health(+team[j]->get_reduce());
										}

									}
									std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;

								}
								else if (team[j]->get_hero() == "Captain America")
								{
									std::cout<< group[i]->get_attack() / block << " Damage!" << endl;
									team[j]->set_health(-group[i]->get_attack() / block);
									std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
									group[i]->set_evade();
									if (group[i]->get_evade() == false)
									{
										group[i]->set_health(-(group[i]->get_attack() - (group[i]->get_attack() / block)));
										std::cout << team[j]->get_hero() << "'s shield reflects some of the Damage back!" << endl;
										std::cout << group[i]->get_enemies() << " has " << group[i]->get_health() << " left" << endl;
									
									}
									system("pause");
									
									

									if (group[i]->get_health() <= 0)
									{
										hero_hlth = false;
										if (hero_hlth == false)
										{
											dead_enemy();
											if (group.size() == 0)
											{
												while (team[j]->get_current_experience() >= team[j]->get_experience()) // if
												{
													level_up();

													
													int rand_int = rand() % 5;

													if (team[j]->get_defense_mod() == true)
													{
														if (group[i]->get_power() == "fire")
														{
															std::cout << team[j]->get_hero() << " is still on fire!" << endl;
															std::cout << group[i]->get_level() << " Damage!" << endl;
															team[j]->set_health(-group[i]->get_level());
															std::cout << team[j]->get_hero() << " has " << team[j]->get_health() << " health left!" << endl;
														}
														if (team[j]->get_defense() > 0)
														{
															while (team[j]->get_defense() > 0)
															{
																team[j]->set_defense(-1);
															}
														}
														team[j]->set_defense_mod(0, group[i]->get_power(), group[i]->get_ice());
													}
													else
													{
														team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);
													}
												}

												std::cout << "Would you like to rest?" << endl;
												std::cout << "1. Yes" << endl;
												std::cout << "2. No" << endl;
												char a = 0;
												a = selection(a);
												if (a == '1')
												{
													std::cout << team[j]->get_hero() << " takes a short rest." << endl;
													rest();

													team[j]->print_stat();
													if (group.size() == 0)
													{
														std::cout << "here1" << endl;
														return;


													}

												}
												else if (a == '2')
												{
													team[j]->print_stat();
													if (group.size() == 0)
													{
														return;
													}
												}

											}

										}
									}
								}
								else
								{
									std::cout<< group[i]->get_attack() / block << " Damage!" << endl;
									team[j]->set_health(-group[i]->get_attack() / block);
									std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
								}

							}

						}
						else
						{
							explosion_result(group_size, fight);

							group[i]->set_attack(team[j], group[i]);
							group[i]->get_power();
							if (group[i]->get_power() == "Multiply")
							{
								std::cout << group[i]->get_enemies() << " divided!" << endl;
								group[i]->set_power("");
								enemies *m2 = new enemies(*group[i]);
								group.push_back(m2);
							}
							
							if (group[i]->get_power() == "Nano Assault")
							{


								team[j]->set_attack(group[i], team[j]);
								std::cout<< team[j]->get_attack() << " Damage!" << endl;
								team[j]->set_health(-team[j]->get_attack());
								std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
								system("pause");
								system("cls");



							}
							else
							{
								if (team[j]->get_hero() == "Iron Man" || team[j]->get_hero() == "Mr. Fantastic")
								{
									team[j]->set_reduce();
									if (group[i]->get_attack() - team[j]->get_reduce() <= 0)
									{
										std::cout<< "0 Damage!" << endl;
										team[j]->set_health(-0);

									}
									else
									{
										std::cout<< group[i]->get_attack() - team[j]->get_reduce() << " Damage!" << endl;

										team[j]->set_health(-group[i]->get_attack());
										if (team[j]->get_health() > 0)
										{
											team[j]->set_health(+team[j]->get_reduce());
										}
									}
									std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
								}
								else if (group[i]->get_power() == "Bleed" && team[j]->get_hero() != "Mr. Fantastic")
								{
									std::cout<< group[i]->get_attack() << " Damage!" << endl;
									team[j]->set_health(-group[i]->get_attack());
									std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
									group[i]->set_bleed_dmg(+group[i]->get_bleed());
									team[j]->set_health(-group[i]->get_bleed_dmg());
									std::cout<< team[j]->get_hero() << " is bleeding " << team[j]->get_health() << " Health left" << endl;
									system("pause");
									system("cls");

								}
								else
								{
									std::cout<< group[i]->get_attack() << " Damage!" << endl;
									team[j]->set_health(-group[i]->get_attack());
									std::cout<< team[j]->get_hero() << " has " << team[j]->get_health() << " Health left" << endl;
								}

							}
						}
						for (size_t i = 0; i < group.size(); i++)
						{
							if (group[i]->get_bleeding() == true)
							{
								group[i]->set_health(-team[j]->get_bleed_dmg());
								std::cout << group[i]->get_enemies() << " is bleeding " << group[i]->get_health() << " Health left" << endl;
								system("pause");
								system("cls");

								if (group[i]->get_health() <= 0)
								{
									hero_hlth = false;
									if (hero_hlth == false)
									{
										dead_enemy();
										if (group.size() == 0)
										{
											while (team[j]->get_current_experience() >= team[j]->get_experience()) // if
											{
												level_up();

												
												int rand_int = rand() % 5;

												if (team[j]->get_defense_mod() == true)
												{
													if (group[i]->get_power() == "fire")
													{
														std::cout << team[j]->get_hero() << " is still on fire!" << endl;
														std::cout << group[i]->get_level() << " Damage!" << endl;
														team[j]->set_health(-group[i]->get_level());
														std::cout << team[j]->get_hero() << " has " << team[j]->get_health() << " health left!" << endl;
													}
													if (team[j]->get_defense() > 0)
													{
														while (team[j]->get_defense() > 0)
														{
															team[j]->set_defense(-1);
														}
													}
													team[j]->set_defense_mod(0, group[i]->get_power(), group[i]->get_ice());
												}
												else
												{
													team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);
												}
											}

											std::cout << "Would you like to rest?" << endl;
											std::cout << "1. Yes" << endl;
											std::cout << "2. No" << endl;
											char a = 0;
											a = selection(a);
											if (a == '1')
											{
												std::cout << team[j]->get_hero() << " takes a short rest." << endl;
												rest();

												team[j]->print_stat();
												if (group.size() == 0)
												{
													std::cout << "here1" << endl;
													return;


												}

											}
											else if (a == '2')
											{
												team[j]->print_stat();
												if (group.size() == 0)
												{
													return;
												}
											}

										}
									}
								}
							}
						}
						int rand_int = rand() % 5;
						team[j]->reset_defense();
						team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);

						
						if (team[j]->get_health() < (team[j]->get_durability() * (15 + team[j]->get_level()) + 100) / 3)
						{
							if (team[j]->get_defense_mod() == true)
							{
								if (group[i]->get_power() == "fire")
								{
									std::cout << team[j]->get_hero() << " is still on fire!" << endl;
									std::cout << group[i]->get_level() << " Damage!" << endl;
									team[j]->set_health(-group[i]->get_level());
									std::cout << team[j]->get_hero() << " has " << team[j]->get_health() << " health left!" << endl;
								}
								if (team[j]->get_defense() > 0)
								{
									while (team[j]->get_defense() > 0)
									{
										team[j]->set_defense(-1);
									}
								}
								team[j]->set_defense_mod(0, group[i]->get_power(), group[i]->get_ice());
							}
							else
							{
								team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 20);
							}								
							int second_chance = rand() % 100;
							if (second_chance > 80)
							{
								if (escape == false)
								{
									escape = true;
								}
							}
							while (escape)
							{
								std::cout<< team[j]->get_hero() << " sees and opening to escape. will you runaway?" << endl;
								std::cout<< "1. Yes, try to runaway" << endl;
								std::cout<< "2. No, stay and fight" << endl;

								char to_run = 0;
								to_run = selection(to_run);


								if (to_run == '1')
								{
									
									int run = rand() % 5;
									int hero = rand() % team[j]->get_level();
									int bad = rand() % group[i]->get_level();
									if (hero + run >= bad)
									{
										std::cout<< team[j]->get_hero() << " manages to runaway." << endl;
										system("pause");
										system("cls");
										group.clear();
										escape = false;
										return;

									}
									else
									{
										std::cout<< team[j]->get_hero() << " can't escape!" << endl;
										escape = false;
									}
								}
								else if (to_run == '2')
								{
									std::cout<< team[j]->get_hero() << " decides to stay and fight." << endl;
									escape = false;
								}
								else
								{
									std::cout<< "Please select a correct choice." << endl;
								}
							}
						}
						else
						{
							if (team[j]->get_defense_mod() == true)
							{
								if (group[i]->get_power() == "fire")
								{
									std::cout << team[j]->get_hero() << " is still on fire!" << endl;
									std::cout << group[i]->get_level() << " Damage!" << endl;
									team[j]->set_health(-group[i]->get_level());
									std::cout << team[j]->get_hero() << " has " << team[j]->get_health() << " health left!" << endl;
								}
								if (team[j]->get_defense() > 0)
								{
									while (team[j]->get_defense() > 0)
									{
										team[j]->set_defense(-1);
									}
								}
								team[j]->set_defense_mod(0, group[i]->get_power(), group[i]->get_ice());
							}
							else
							{
								team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);
							}
						}
						if (i >= group.size())
						{
							i = group.size() - 1;
						}
						group[i]->reset_defense();
						group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_speed() + group[i]->get_level() + group[i]->get_intelligence() + rand_int);
						if (group[i]->get_boss())
						{
							if (group[j]->get_health() < (group[j]->get_durability() * (15 + group[j]->get_level()) + 100) / 3)
							{
								
								int run = rand() % group[i]->get_level();
								if (group[i]->get_defense_mod() == true)
								{
									if (group[i]->get_defense() > 0)
									{
										while (group[i]->get_defense() > 0)
										{
											group[i]->set_defense(-1);
										}
									}
									group[i]->set_defense_mod(0);
								}
								else
								{
									group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_level() + group[i]->get_speed() + group[i]->get_intelligence() + rand_int + run);
								}

								if (run + 1 >= group[i]->get_level())
								{
									std::cout<< group[i]->get_enemies() << " manages to escape!" << endl;
									std::cout<< team[j]->get_hero() << " gained " << group[i]->get_experience() << " exp." << endl;
									team[j]->set_current_experience(group[i], 0);
									std::cout<< "You now have " << team[j]->get_current_experience() << " exp." << endl;
									team[j]->set_reputation(group[i]->get_reputation());
									std::cout<< "Your Current Reputation is: " << team[j]->get_reputation() << endl;

									system("pause");
									system("cls");
									group.clear();
									hero_hlth = false;
									if (hero_hlth == false)
									{

										fight = false;
										break;

									}
								}
							}
							else
							{
								if (group[i]->get_defense_mod() == true)
								{
									if (group[i]->get_defense() > 0)
									{
										while (group[i]->get_defense() > 0)
										{
											group[i]->set_defense(-1);
										}
									}
									group[i]->set_defense_mod(0);
								}
								else
								{
									group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_level() + group[i]->get_speed() + group[i]->get_intelligence() + rand_int);
								}
							}

						}
						else
						{
							if (group[i]->get_defense_mod() == true)
							{
								if (group[i]->get_defense() > 0)
								{
									while (group[i]->get_defense() > 0)
									{
										group[i]->set_defense(-1);
									}
								}
								group[i]->set_defense_mod(0);
							}
							else
							{
								group[i]->set_defense(group[i]->get_Cskill() + group[i]->get_level() + group[i]->get_speed() + group[i]->get_intelligence() + rand_int);
							}
						}
						system("pause");
						system("cls");
					}
					for (size_t i = 0; i < group.size(); i++)
					{
						if (hero_hlth == false)
						{
							break;
						}
						if (player_att)
						{
							hero_hlth = false;

						}



					}


					if (team[j]->get_health() <= 0)
					{
						std::cout<< p->get_hero() << " Has been killed!" << endl;
						std::cout<< "GAME OVER!" << endl;
						return;
						//exit(_getch());
					}

				}

			}// hero_hlth
			(group.size() > 0 ? (group[0]->get_enum() == POWDERKEG ? group[0]->set_nitro(1) : 0) : 0);

			if (hero_hlth == false)
			{

				fight = false;
			}
			if (group_size == false)
			{

				fight = false;
			}


		}
		if (group.size() == 0)
		{
			
			int rand_int = rand() % 5;
			team[j]->reset_defense();
			team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);
			if (team[j]->get_health() < (team[j]->get_durability() * (15 + team[j]->get_level()) + 100) / 3)
			{

				if (team[j]->get_defense_mod() == true)
				{
					if (team[j]->get_defense() > 0)
					{
						while (team[j]->get_defense() > 0)
						{
							team[j]->set_defense(-1);
						}
					}
					team[j]->set_defense_mod(0, "", 0);
				}
				else
				{
					team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 20);
				}
			}
			else
			{
				if (team[j]->get_defense_mod() == true)
				{
					if (team[j]->get_defense() > 0)
					{
						while (team[j]->get_defense() > 0)
						{
							team[j]->set_defense(-1);
						}
					}
					team[j]->set_defense_mod(0, "", 0);
				}
				else
				{
					team[j]->set_defense(team[j]->get_Cskill() + team[j]->get_speed() + team[j]->get_level() + team[j]->get_intelligence() + rand_int + 10);
				}
			}
			break;
		}
	}
}// fight



	else if (input == '2')
	{
		std::cout<< p->get_hero() << " ignors the sounds." << endl;
		if (team[j]->get_reputation() > 0)
		{
			team[j]->set_reputation(-1 * 0.1);
		}

		group.clear();


	}


}
void player_stats_renew(player* p)
{
	if (p->get_hero() == "Spiderman")
	{
		if (p->get_speed() < (p->get_level() + 5))
		{
			p->set_speed(+1);
			std::cout << p->get_hero() << " regains 1 Speed. " << p->get_hero() << " now has " << p->get_speed() << " Speed." << endl;
		}
		if (p->get_strength() < (p->get_level() + 3))
		{
			p->set_strenght(+1);
			std::cout << p->get_hero() << " regains 1 Strength. " << p->get_hero() << " now has " << p->get_strength() << " Strength." << endl;
		}
		if (p->get_durability() < (p->get_level() + 2))
		{
			p->set_durability(+1);
			std::cout << p->get_hero() << " regains 1 Durability. " << p->get_hero() << " now has " << p->get_durability() << " Durability." << endl;
		}
		if (p->get_Cskill() < (p->get_level() + 4))
		{
			p->set_Cskill(+1);
			std::cout << p->get_hero() << " regains 1 Combat Skill. " << p->get_hero() << " now has " << p->get_Cskill() << " Combat Skill." << endl;
		}
	}
	else if (p->get_hero() == "Iron Man")
	{
		if (p->get_speed() < (p->get_level() + 4))
		{
			p->set_speed(+1);
			std::cout << p->get_hero() << " regains 1 Speed. " << p->get_hero() << " now has " << p->get_speed() << " Speed." << endl;
		}
		if (p->get_strength() < (p->get_level() + 5))
		{
			p->set_strenght(+1);
			std::cout << p->get_hero() << " regains 1 Strength. " << p->get_hero() << " now has " << p->get_strength() << " Strength." << endl;
		}
		if (p->get_Cskill() < (p->get_level() + 2))
		{
			p->set_Cskill(+1);
			std::cout << p->get_hero() << " regains 1 Combat Skill. " << p->get_hero() << " now has " << p->get_Cskill() << " Combat Skill." << endl;
		}
		if (p->get_durability() < (p->get_level() + 5))
		{
			p->set_durability(+1);
			std::cout << p->get_hero() << " regains 1 Durability. " << p->get_hero() << " now has " << p->get_durability() << " Durability." << endl;
		}

	}
	else if (p->get_hero() == "Ms. Marvel")
	{
		if (p->get_speed() < (p->get_level() + 5))
		{
			p->set_speed(+1);
			std::cout << p->get_hero() << " regains 1 Speed. " << p->get_hero() << " now has " << p->get_speed() << " Speed." << endl;
		}
		if (p->get_strength() < (p->get_level() + 4))
		{
			p->set_strenght(+1);
			std::cout << p->get_hero() << " regains 1 Strength. " << p->get_hero() << " now has " << p->get_strength() << " Strength." << endl;
		}
		if (p->get_Cskill() < (p->get_level() + 4))
		{
			p->set_Cskill(+1);
			std::cout << p->get_hero() << " regains 1 Combat Skill. " << p->get_hero() << " now has " << p->get_Cskill() << " Combat Skill." << endl;
		}
		if (p->get_durability() < (p->get_level() + 4))
		{
			p->set_durability(+1);
			std::cout << p->get_hero() << " regains 1 Durability. " << p->get_hero() << " now has " << p->get_durability() << " Durability." << endl;
		}

	}
	else if (p->get_hero() == "Mr. Fantastic")
	{
		if (p->get_speed() < (p->get_level() + 2))
		{
			p->set_speed(+1);
			std::cout << p->get_hero() << " regains 1 Speed. " << p->get_hero() << " now has " << p->get_speed() << " Speed." << endl;
		}
		if (p->get_strength() < (p->get_level() + 3))
		{
			p->set_strenght(+1);
			std::cout << p->get_hero() << " regains 1 Strength. " << p->get_hero() << " now has " << p->get_strength() << " Strength." << endl;
		}
		if (p->get_Cskill() < (p->get_level() + 2))
		{
			p->set_Cskill(+1);
			std::cout << p->get_hero() << " regains 1 Combat Skill. " << p->get_hero() << " now has " << p->get_Cskill() << " Combat Skill." << endl;
		}
		if (p->get_durability() < (p->get_level() + 6))
		{
			p->set_durability(+1);
			std::cout << p->get_hero() << " regains 1 Durability. " << p->get_hero() << " now has " << p->get_durability() << " Durability." << endl;
		}
	}
	else if (p->get_hero() == "Black Widow")
	{
		if (p->get_speed() < (p->get_level() + 2))
		{
			p->set_speed(+1);
			std::cout << p->get_hero() << " regains 1 Speed. " << p->get_hero() << " now has " << p->get_speed() << " Speed." << endl;
		}
		if (p->get_strength() < (p->get_level() + 3))
		{
			p->set_strenght(+1);
			std::cout << p->get_hero() << " regains 1 Strength. " << p->get_hero() << " now has " << p->get_strength() << " Strength." << endl;
		}
		if (p->get_Cskill() < (p->get_level() + 6))
		{
			p->set_Cskill(+1);
			std::cout << p->get_hero() << " regains 1 Combat Skill. " << p->get_hero() << " now has " << p->get_Cskill() << " Combat Skill." << endl;
		}
		if (p->get_durability() < (p->get_level() + 3))
		{
			p->set_durability(+1);
			std::cout << p->get_hero() << " regains 1 Durability. " << p->get_hero() << " now has " << p->get_durability() << " Durability." << endl;
		}
	}
	else if (p->get_hero() == "Black Panther")
	{
		if (p->get_speed() < (p->get_level() + 4))
		{
			p->set_speed(+1);
			std::cout << p->get_hero() << " regains 1 Speed. " << p->get_hero() << " now has " << p->get_speed() << " Speed." << endl;
		}
		if (p->get_strength() < (p->get_level() + 4))
		{
			p->set_strenght(+1);
			std::cout << p->get_hero() << " regains 1 Strength. " << p->get_hero() << " now has " << p->get_strength() << " Strength." << endl;
		}
		if (p->get_Cskill() < (p->get_level() + 6))
		{
			p->set_Cskill(+1);
			std::cout << p->get_hero() << " regains 1 Combat Skill. " << p->get_hero() << " now has " << p->get_Cskill() << " Combat Skill." << endl;
		}
		if (p->get_durability() < (p->get_level() + 3))
		{
			p->set_durability(+1);
			std::cout << p->get_hero() << " regains 1 Durability. " << p->get_hero() << " now has " << p->get_durability() << " Durability." << endl;
		}
	}
	else if (p->get_hero() == "Wolverine")
	{
		if (p->get_speed() < (p->get_level() + 3))
		{
			p->set_speed(+1);
			std::cout << p->get_hero() << " regains 1 Speed. " << p->get_hero() << " now has " << p->get_speed() << " Speed." << endl;
		}
		if (p->get_strength() < (p->get_level() + 4))
		{
			p->set_strenght(+1);
			std::cout << p->get_hero() << " regains 1 Strength. " << p->get_hero() << " now has " << p->get_strength() << " Strength." << endl;
		}
		if (p->get_Cskill() < (p->get_level() + 4))
		{
			p->set_Cskill(+1);
			std::cout << p->get_hero() << " regains 1 Combat Skill. " << p->get_hero() << " now has " << p->get_Cskill() << " Combat Skill." << endl;
		}
		if (p->get_durability() < (p->get_level() + 4))
		{
			p->set_durability(+1);
			std::cout << p->get_hero() << " regains 1 Durability. " << p->get_hero() << " now has " << p->get_durability() << " Durability." << endl;
		}
	}
	else if (p->get_hero() == "Captain America")
	{
		if (p->get_speed() < (p->get_level() + 3))
		{
			p->set_speed(+1);
			std::cout << p->get_hero() << " regains 1 Speed. " << p->get_hero() << " now has " << p->get_speed() << " Speed." << endl;
		}
		if (p->get_strength() < (p->get_level() + 3))
		{
			p->set_strenght(+1);
			std::cout << p->get_hero() << " regains 1 Strength. " << p->get_hero() << " now has " << p->get_strength() << " Strength." << endl;
		}
		if (p->get_Cskill() < (p->get_level() + 6))
		{
			p->set_Cskill(+1);
			std::cout << p->get_hero() << " regains 1 Combat Skill. " << p->get_hero() << " now has " << p->get_Cskill() << " Combat Skill." << endl;
		}
		if (p->get_durability() < (p->get_level() + 3))
		{
			p->set_durability(+1);
			std::cout << p->get_hero() << " regains 1 Durability. " << p->get_hero() << " now has " << p->get_durability() << " Durability." << endl;
		}
	}

}

enemies* create_enemy(player* p, Map* m, int i, int rand_enemy)
{
	++i;
	int spd = rand() % 8;
	int rand_int = rand() % 8;
	int rand_enemies = rand_enemy;
	string name = "";
	enemies* enemy = new enemies();
	if (m->get_city() == "Sewers")
	{
		enemy->set_enemies("Morlock_" + to_string(i), p);
	}
	else if (m->get_city() == "Central Park")
	{
		enemy->set_enemies("Marauder_" + to_string(i), p);
	}
	else if (m->get_city() == "Hells Kitchen")
	{
		if (p->get_registration() == "anti")
		{
			if (rand_enemies == 0)
			{
				enemy->set_enemies("Thug_" + to_string(i), p);
			}
			else
			{
				enemy->set_enemies("Cape-Killer_" + to_string(i), p);
			}
		}
		else
		{
			enemy->set_enemies("Rebel_" + to_string(i), p);
		}
	}
	else if (m->get_city() == "The X Mansion")
	{
		if (p->get_registration() == "anti")
		{
			enemy->set_enemies("Sentinel_" + to_string(i), p);
		}
		else
		{
			enemy->set_enemies("Mutant_" + to_string(i), p);
		}

	}
	else if (m->get_city() == "Savage Lands")
	{
		if (rand_enemies == 0)
		{
			enemy->set_enemies("Savage Man_" + to_string(i), p);
		}
		else if (rand_enemies == 1)
		{
			enemy->set_enemies("Velociraptor_" + to_string(i), p);
		}
		else
		{
			enemy->set_enemies("Reptile Man_" + to_string(i), p);
		}
	}
	else if (m->get_city() == "Avenger Tower")
	{
		if (p->get_registration() == "anti")
		{
			enemy->set_enemies("Cape-Killer_" + to_string(i), p);
		}
		else
		{
			enemy->set_enemies("Rebel_" + to_string(i), p);
		}
	}
	else
	{
		if (rand_enemies == 0)
		{
			name = "Thug_" + to_string(i);
			enemy->set_enemies(name, p);
		}
		else if (rand_enemies == 1)
		{
			name = "Hydra Soldier_" + to_string(i);
			enemy->set_enemies(name, p);
		}
		else if (rand_enemies == -1)
		{
			name = "Civilian_" + to_string(i);
			enemy->set_enemies(name, p);
		}
		else
		{
			name = "A.I.M. Tech_" + to_string(i);
			enemy->set_enemies(name, p);
		}
	}
	enemy->set_level(p);
	enemy->set_strenght(0, team[0]);
	enemy->set_experience();
	enemy->set_Cskill(0, team[0]);
	enemy->set_durability(0, team[0]);
	enemy->set_health(enemy->get_durability() * 5);
	enemy->max_health(enemy->get_health());
	enemy->set_speed(1 + spd + enemy->get_level());
	enemy->set_intelligence(0, team[0]);
	enemy->set_energy(0, team[0]);
	enemy->set_defense(enemy->get_Cskill() + enemy->get_level() + enemy->get_speed() + rand_int);
	enemy->set_weapon();

	return enemy;
}

void events1(player* p, Map* m)
{
	
	int rand_int_event = 0;
	int spd = rand() % 8;
	int rage = rand() % 8;
	if (get_mission_stat() == true)
	{
		rand_int_event = 4;
	}
	else
	{
		if (p->get_level() >= 5)
		{
			if (get_mission_run() == true)
			{
				cout << "On a mission" << endl;
				rand_int_event = rand() % 6;
				while (rand_int_event == 4)
				{
					rand_int_event = rand() % 6;
				}
			}
			else
			{
				rand_int_event = rand() % 6;
			}


		}
		else
		{
			if (get_mission_run() == true)
			{
				cout << "On a mission" << endl;

				rand_int_event = rand() % 5;
				while (rand_int_event == 4)
				{

					rand_int_event = rand() % 5;

				}
			}
			else
			{
				rand_int_event = rand() % 5;
			}

		}



	}
	int dead_leaders = 0;
	int j = 0;
	string n = "";
	bool escape = true;
	bool fighting = true;
	switch (rand_int_event)
	{
	case 0:
	{
			  std::cout<< "case 0" << endl;
			  
			  int rand_int = rand() % 5;
			  int rand_enemies = rand() % 3;
			  
			  int num = rand() % 5;
			  if (num > 10)
			  {
				  num = 9;
			  }
			  num++;

			  enemies* Enemies;
			  for (int i = 0; i < num; i++)
			  {
				  Enemies = create_enemy(p, m, i, rand_enemies);
				  group.push_back(Enemies);
				  if (i == num-1)
				  {
					  fight(p, Enemies);
					  Enemies->reset_rnd();
				  }
			  }

			  break;
	}

	case 1:
	{
			  if (m->get_city() == "Sewers")
			  {
				  saved_people.push_back("child");
				  set_people(get_people());
				  std::cout << p->get_hero() << " finds a childen that was kidnapped by the Morlocks!" << endl
					  << p->get_hero() << " has now saved " << saved_people.size() << " people!" << endl
					  << "Only " << get_people() << " more children to find!" << endl;
			  }
			  else if (m->get_city() == "Avenger Tower")
			  {
				  std::cout << "This area is secured." << endl;
			  }
			  else
			 {
				  std::cout << "nothing is going on." << endl;
			 }
			  break;
	}
	case 2:
	{
		 if (m->get_city() == "Sewers")
		  {
			  
			  char input = 0;
			  int comp = rand() % 4;
			  int choice = comp + 1;
			  std::cout << "You find one of the bombs the Morlocks have planted!" << endl;
			  std::cout << "The bomb is placed under a heavily populated area!" << endl;
			  std::cout << "What do you think is the best way to disarm the bomb?" << endl;
			  std::cout << "Chose wisely the city is in danger!" << endl;
			  system("pause");
			  system("cls");
			  std::cout << "1. Cut the red wire" << endl;
			  std::cout << "2. Cut the blue wire" << endl;
			  std::cout << "3. Cut all the wires" << endl;
			  std::cout << "4. Bury the bomb in a deep part of the Sewers" << endl;
			  std::cout << "5. Punch the bomb and hope it shuts down" << endl;
			  input = selection(input);
			   if (input == '1')
				 {
					 input = 1;
				 }
				 else if (input == '2')
				  {
					  input = 2;
				  }
				  else if (input == '3')
				  {
					  input = 3;
				  }
				  else if (input == '4')
				  {
					  input = 4;
				  }
				  else if (input == '5')
				  {
					  input = 5;
				  }

				  if (input <= choice)
				  {
					  std::cout << "You have chosen wisely and have successfully disabled the bomb" << endl;
					  enemies* Enemies1 = new enemies();
					  Enemies1->set_enemies("Thug1", p);
					  Enemies1->set_level(p);
					  Enemies1->get_level();
					  Enemies1->set_strenght(0, team[j]);
					  Enemies1->get_strength();
					  Enemies1->set_Cskill(0, team[j]);
					  Enemies1->get_Cskill();
					  Enemies1->set_durability(0, team[j]);
					  Enemies1->get_durability();
					  Enemies1->set_speed(1 + spd + Enemies1->get_level());
					  Enemies1->get_speed();
					  Enemies1->set_experience();
					  Enemies1->get_experience();
					  std::cout << team[j]->get_hero() << " gained " << Enemies1->get_experience() + choice << " exp." << endl;
					  team[j]->set_current_experience(Enemies1, +choice);
					  std::cout << "You now have " << team[j]->get_current_experience() << " exp." << endl;

				  }
				  else
				  {
					  system("cls");
					  

					  std::cout << "The bomb has not shut down! ITS GOING TO BLOW!!!" << endl;
					  std::cout << "BOOOOOOOOMMM" << endl;
					  int dmg = 0;
					  int dead_people = 0;
					  team[j]->max_hlth();
					  if (team[j]->get_max() > 200)
					  {
						  int dmg = rand() % 200;
						  int dead_people = rand() % 20;

						  std::cout << dead_people << " People have died in the explosion!" << endl;
						  std::cout << team[j]->get_hero() << " takes " << dmg << " damage!" << endl;

						  std::cout << team[j]->get_hero() << " reputation has dropped by " << dead_people * 0.01 << endl;

						  team[j]->set_reputation(-dead_people * 0.1);
						  team[j]->set_health(-dmg);
					  }
					  else if (team[j]->get_max() > 300)
					  {
						  int dmg = rand() % 300;
						  int dead_people = rand() % 30;

						  std::cout << dead_people << " People have died in the explosion!" << endl;
						  std::cout << team[j]->get_hero() << " takes " << dmg << " damage!" << endl;

						  std::cout << team[j]->get_hero() << " reputation has dropped by " << dead_people * 0.01 << endl;

						  team[j]->set_reputation(-dead_people * 0.1);
						  team[j]->set_health(-dmg);

					  }
					  else if (team[j]->get_max() > 400)
					  {
						  int dmg = rand() % 400;
						  int dead_people = rand() % 40;

						  std::cout << dead_people << " People have died in the explosion!" << endl;
						  std::cout << team[j]->get_hero() << " takes " << dmg << " damage!" << endl;

						  std::cout << team[j]->get_hero() << " reputation has dropped by " << dead_people * 0.01 << endl;

						  team[j]->set_reputation(-dead_people * 0.1);
						  team[j]->set_health(-dmg);

					  }
					  else if (team[j]->get_max() > 500)
					  {
						  int dmg = rand() % 500;
						  int dead_people = rand() % 50;

						  std::cout << dead_people << " People have died in the explosion!" << endl;
						  std::cout << team[j]->get_hero() << " takes " << dmg << " damage!" << endl;

						  std::cout << team[j]->get_hero() << " reputation has dropped by " << dead_people * 0.01 << endl;

						  team[j]->set_reputation(-dead_people * 0.1);
						  team[j]->set_health(-dmg);

					  }
					  else if (team[j]->get_max() > 600)
					  {
						  int dmg = rand() % 600;
						  int dead_people = rand() % 60;

						  std::cout << dead_people << " People have died in the explosion!" << endl;
						  std::cout << team[j]->get_hero() << " takes " << dmg << " damage!" << endl;

						  std::cout << team[j]->get_hero() << " reputation has dropped by " << dead_people * 0.01 << endl;

						  team[j]->set_reputation(-dead_people * 0.1);
						  team[j]->set_health(-dmg);

					  }
					  else if (team[j]->get_max() > 700)
					  {
						  int dmg = rand() % 700;
						  int dead_people = rand() % 70;

						  std::cout << dead_people << " People have died in the explosion!" << endl;
						  std::cout << team[j]->get_hero() << " takes " << dmg << " damage!" << endl;

						  std::cout << team[j]->get_hero() << " reputation has dropped by " << dead_people * 0.01 << endl;

						  team[j]->set_reputation(-dead_people * 0.1);
						  team[j]->set_health(-dmg);

					  }
					  else if (team[j]->get_max() > 800)
					  {
						  int dmg = rand() % 800;
						  int dead_people = rand() % 80;

						  std::cout << dead_people << " People have died in the explosion!" << endl;
						  std::cout << team[j]->get_hero() << " takes " << dmg << " damage!" << endl;

						  std::cout << team[j]->get_hero() << " reputation has dropped by " << dead_people * 0.01 << endl;

						  team[j]->set_reputation(-dead_people * 0.1);
						  team[j]->set_health(-dmg);

					  }
					  else if (team[j]->get_max() > 900)
					  {
						  int dmg = rand() % 900;
						  int dead_people = rand() % 90;

						  std::cout << dead_people << " People have died in the explosion!" << endl;
						  std::cout << team[j]->get_hero() << " takes " << dmg << " damage!" << endl;

						  std::cout << team[j]->get_hero() << " reputation has dropped by " << dead_people * 0.01 << endl;

						  team[j]->set_reputation(-dead_people * 0.1);
						  team[j]->set_health(-dmg);

					  }
					  else
					  {
						  int dmg = rand() % 100;
						  int dead_people = rand() % 10;

						  std::cout << dead_people << " People have died in the explosion!" << endl;
						  std::cout << team[j]->get_hero() << " takes " << dmg << " damage!" << endl;

						  std::cout << team[j]->get_hero() << " reputation has dropped by " << dead_people * 0.01 << endl;

						  team[j]->set_reputation(-dead_people * 0.1);
						  team[j]->set_health(-dmg);
					  }

					  std::cout << "You now have " << team[j]->get_health() << " health left" << endl;
					  std::cout << "Your current reputaion is " << team[j]->get_reputation() << endl;

				  }
			  }//ppp
		 else if (m->get_city() == "Cental Park")
		 {
			 saved_people.push_back("morlock");
			 set_people(get_people());
			 std::cout << p->get_hero() << " finds a Morlock that was taken prisoner by the Marauders!" << endl
				 << p->get_hero() << " has now saved " << saved_people.size() << " Morlocks!" << endl
				 << "Only " << get_people() << " more Morlocks to find!" << endl;
		 }
		 else if (m->get_city() == "The X Mansion")
		 {
			 if (get_people() != 0)
			 {
				 if (p->get_registration() == "anti")
				 {

					 saved_people.push_back("student");
					 set_people(get_people());
					 std::cout << p->get_hero() << " finds a lost student!" << endl
						 << p->get_hero() << " has now saved " << saved_people.size() << " students!" << endl
						 << "Only " << get_people() << " more students to find!" << endl;
					 if (get_people() == 0)
					 {
						 std::cout << "All students have been saved!" << endl;
					 }
				 }
				 else
				 {
					 saved_people.push_back("student");
					 set_people(get_people());
					 std::cout << p->get_hero() << " finds an unregistered student and captures them!" << endl
						 << p->get_hero() << " has now captured " << saved_people.size() << " students!" << endl
						 << "Only " << get_people() << " more students to find!" << endl;
					 if (get_people() == 0)
					 {
						 std::cout << "All students have been captued!" << endl;
					 }
				 }
			 }
			 else
			 {
				 std::cout << "Nothing going on over here." << endl;
			 }
		 }
		 else if (m->get_city() == "Savage Lands")
		 {
			 //add event
		 }
		 else if (m->get_city() == "Hells Kitchen")
		 {
			 //add event
			 //purse snatcher, options to ignor or follow, can lead to fight with single or group or they give up.
				//option to beat them if they give up causing negative reputaion
			 //bar fight at Josie's Bar
			 //saving nuns??
		 }
		 else if (m->get_city() == "Avenger Tower")
		 {
			 // add event
		 }
			else // not on a mission
			  {
				  char input = 0;
				  std::cout << "You hear someone asking for help. What do you do?" << endl;
				  std::cout << "1. Run over and help" << endl;
				  std::cout << "2. Ignor it" << endl;
				  time_t  t1 = time(0);  // get time now

										 // get local time and subtract it from input time. if over 8 print sorry message

				  input = selection(input);

				  if (input == '1')
				  {

					  time_t  t2 = time(0); // get time now

					  if (t1 + 8 < t2)
					  {
						  std::cout << "You waited too long" << endl;
						  if (team[j]->get_reputation() > 0.7)
						  {
							  team[j]->set_reputation(-8 * 0.1);
						  }
						  break;
					  }
					  else
					  {

						  int side_missions = rand() % 3;

						  if (side_missions == 0)
						  {

							  char input = 0;
							  int comp = rand() % 4;
							  int choice = comp + 1;
							  std::cout << "A little old lady needs help getting her cat out of a tree." << endl;
							  std::cout << "What do you think is the best way to save the cat?" << endl;
							  std::cout << "She may not agree with you choice." << endl;
							  system("pause");
							  system("cls");
							  std::cout << "1. Shake the tree" << endl;
							  std::cout << "2. Jump up and grab the cat" << endl;
							  std::cout << "3. Use your strength to rip out the tree" << endl;
							  std::cout << "4. Coax it down with your words" << endl;
							  std::cout << "5. Climb up the tree and bring it down" << endl;
							  std::cout << "6. Kill the cat because this is a waste of your time" << endl;
							  input = selection(input);
							  if (input == '1')
							  {
								  input = 1;
							  }
							  else if (input == '2')
							  {
								  input = 2;
							  }
							  else if (input == '3')
							  {
								  input = 3;
							  }
							  else if (input == '4')
							  {
								  input = 4;
							  }
							  else if (input == '5')
							  {
								  input = 5;
							  }
							  else if (input == '6')
							  {
								  input = 6;
							  }

							  if (input == choice)
							  {
								  std::cout << "You have chosen wisely and have successfully saved the cat" << endl;
								  enemies* Enemies1 = new enemies();
								  Enemies1->set_enemies("Thug1", p);
								  Enemies1->set_level(p);
								  Enemies1->get_level();
								  Enemies1->set_strenght(0, team[j]);
								  Enemies1->get_strength();
								  Enemies1->set_Cskill(0, team[j]);
								  Enemies1->get_Cskill();
								  Enemies1->set_durability(0, team[j]);
								  Enemies1->get_durability();
								  Enemies1->set_speed(1 + spd + Enemies1->get_level());
								  Enemies1->get_speed();
								  Enemies1->set_experience();
								  Enemies1->get_experience();
								  std::cout << team[j]->get_hero() << " gained " << Enemies1->get_experience() + choice << " exp." << endl;
								  team[j]->set_current_experience(Enemies1, +choice);
								  std::cout << "You now have " << team[j]->get_current_experience() << " exp." << endl;

							  }
							  else
							  {
								  if (input == 6)
								  {
									  std::cout << "The little old lady screams in horror!" << endl << " She cannot believe that you killed her cat." << endl;
									  std::cout << "Your reputation has decreased by " << choice * 0.1 << endl;

									  team[j]->set_reputation(-choice * 0.1);

									  std::cout << "Your current reputaion is " << team[j]->get_reputation() << endl;

								  }
								  else
									  std::cout << "The little old lady did not agree with your choice and hits you with her purse." << endl;
							  }

						  }
						  else if (side_missions == 1)
						  {

							  char input = 0;
							  int comp = rand() % 4;
							  int choice = comp + 1;
							  std::cout << "The Police are in need of your help with a bomb." << endl;
							  std::cout << "What do you think is the best way to disarm the bomb?" << endl;
							  std::cout << "Chose wisely or people may die" << endl;
							  system("pause");
							  system("cls");
							  std::cout << "1. Cut the red wire" << endl;
							  std::cout << "2. Cut the blue wire" << endl;
							  std::cout << "3. Cut all the wires" << endl;
							  std::cout << "4. Take the bomb with you and get it away from people" << endl;
							  std::cout << "5. Punch the bomb and hope it shuts down" << endl;
							  input = selection(input);

							  if (input == '1')
							  {
								  input = 1;
							  }
							  else if (input == '2')
							  {
								  input = 2;
							  }
							  else if (input == '3')
							  {
								  input = 3;
							  }
							  else if (input == '4')
							  {
								  input = 4;
							  }
							  else if (input == '5')
							  {
								  input = 5;
							  }

							  if (input == choice)
							  {
								  std::cout << "You have chosen wisely and have successfully disabled the bomb" << endl;
								  enemies* Enemies1 = new enemies();
								  Enemies1->set_enemies("Thug1", p);
								  Enemies1->set_level(p);
								  Enemies1->get_level();
								  Enemies1->set_strenght(0, team[j]);
								  Enemies1->get_strength();
								  Enemies1->set_Cskill(0, team[j]);
								  Enemies1->get_Cskill();
								  Enemies1->set_durability(0, team[j]);
								  Enemies1->get_durability();
								  Enemies1->set_speed(1 + spd + Enemies1->get_level());
								  Enemies1->get_speed();
								  Enemies1->set_experience();
								  Enemies1->get_experience();
								  std::cout << team[j]->get_hero() << " gained " << Enemies1->get_experience() + choice << " exp." << endl;
								  team[j]->set_current_experience(Enemies1, +choice);
								  std::cout << "You now have " << team[j]->get_current_experience() << " exp." << endl;

							  }
							  else
							  {
								  system("cls");


								  std::cout << "The bomb has not shut down! ITS GOING TO BLOW!!!" << endl;
								  std::cout << "BOOOOOOOOMMM" << endl;
								  int dmg = 0;
								  int dead_people = 0;
								  team[j]->max_hlth();
								  std::cout << team[j]->get_max() << " max" << endl;
								  if (team[j]->get_max() > 200)
								  {
									  int dmg = rand() % 200;
									  int dead_people = rand() % 20;

									  std::cout << dead_people << " People have died in the explosion!" << endl;
									  std::cout << team[j]->get_hero() << " takes " << dmg << " damage!" << endl;

									  std::cout << team[j]->get_hero() << " reputation has dropped by " << dead_people * 0.01 << endl;

									  team[j]->set_reputation(-dead_people * 0.1);
									  team[j]->set_health(-dmg);
								  }
								  else if (team[j]->get_max() > 300)
								  {
									  int dmg = rand() % 300;
									  int dead_people = rand() % 30;

									  std::cout << dead_people << " People have died in the explosion!" << endl;
									  std::cout << team[j]->get_hero() << " takes " << dmg << " damage!" << endl;

									  std::cout << team[j]->get_hero() << " reputation has dropped by " << dead_people * 0.01 << endl;

									  team[j]->set_reputation(-dead_people * 0.1);
									  team[j]->set_health(-dmg);

								  }
								  else if (team[j]->get_max() > 400)
								  {
									  int dmg = rand() % 400;
									  int dead_people = rand() % 40;

									  std::cout << dead_people << " People have died in the explosion!" << endl;
									  std::cout << team[j]->get_hero() << " takes " << dmg << " damage!" << endl;

									  std::cout << team[j]->get_hero() << " reputation has dropped by " << dead_people * 0.01 << endl;

									  team[j]->set_reputation(-dead_people * 0.1);
									  team[j]->set_health(-dmg);

								  }
								  else if (team[j]->get_max() > 500)
								  {
									  int dmg = rand() % 500;
									  int dead_people = rand() % 50;

									  std::cout << dead_people << " People have died in the explosion!" << endl;
									  std::cout << team[j]->get_hero() << " takes " << dmg << " damage!" << endl;

									  std::cout << team[j]->get_hero() << " reputation has dropped by " << dead_people * 0.01 << endl;

									  team[j]->set_reputation(-dead_people * 0.1);
									  team[j]->set_health(-dmg);

								  }
								  else if (team[j]->get_max() > 600)
								  {
									  int dmg = rand() % 600;
									  int dead_people = rand() % 60;

									  std::cout << dead_people << " People have died in the explosion!" << endl;
									  std::cout << team[j]->get_hero() << " takes " << dmg << " damage!" << endl;

									  std::cout << team[j]->get_hero() << " reputation has dropped by " << dead_people * 0.01 << endl;

									  team[j]->set_reputation(-dead_people * 0.1);
									  team[j]->set_health(-dmg);

								  }
								  else if (team[j]->get_max() > 700)
								  {
									  int dmg = rand() % 700;
									  int dead_people = rand() % 70;

									  std::cout << dead_people << " People have died in the explosion!" << endl;
									  std::cout << team[j]->get_hero() << " takes " << dmg << " damage!" << endl;

									  std::cout << team[j]->get_hero() << " reputation has dropped by " << dead_people * 0.01 << endl;

									  team[j]->set_reputation(-dead_people * 0.1);
									  team[j]->set_health(-dmg);

								  }
								  else if (team[j]->get_max() > 800)
								  {
									  int dmg = rand() % 800;
									  int dead_people = rand() % 80;

									  std::cout << dead_people << " People have died in the explosion!" << endl;
									  std::cout << team[j]->get_hero() << " takes " << dmg << " damage!" << endl;

									  std::cout << team[j]->get_hero() << " reputation has dropped by " << dead_people * 0.01 << endl;

									  team[j]->set_reputation(-dead_people * 0.1);
									  team[j]->set_health(-dmg);

								  }
								  else if (team[j]->get_max() > 900)
								  {
									  int dmg = rand() % 900;
									  int dead_people = rand() % 90;

									  std::cout << dead_people << " People have died in the explosion!" << endl;
									  std::cout << team[j]->get_hero() << " takes " << dmg << " damage!" << endl;

									  std::cout << team[j]->get_hero() << " reputation has dropped by " << dead_people * 0.01 << endl;

									  team[j]->set_reputation(-dead_people * 0.1);
									  team[j]->set_health(-dmg);

								  }
								  else
								  {
									  int dmg = rand() % 100;
									  int dead_people = rand() % 10;

									  std::cout << dead_people << " People have died in the explosion!" << endl;
									  std::cout << team[j]->get_hero() << " takes " << dmg << " damage!" << endl;

									  std::cout << team[j]->get_hero() << " reputation has dropped by " << dead_people * 0.01 << endl;

									  team[j]->set_reputation(-dead_people * 0.1);
									  team[j]->set_health(-dmg);
								  }

								  std::cout << "You now have " << team[j]->get_health() << " health left" << endl;
								  std::cout << "Your current reputaion is " << team[j]->get_reputation() << endl;

							  }

						  }
						  else
						  {

							  char input = 0;
							  int comp = rand() % 2;
							  int choice = comp + 1;

							  std::cout << "You hear people screaming and you see search lights pointing at a building." << endl;
							  std::cout << "You run over to see what is going on." << endl;
							  std::cout << "You get there and find out that someone is about to jump off a building!" << endl;
							  std::cout << "Time is of the essence, what do you do?" << endl;
							  system("pause");
							  system("cls");
							  std::cout << "1. Try and save him." << endl;
							  std::cout << "2. Let them fall." << endl;
							  time_t  t1 = time(0);  // get time now


							  input = selection(input);
							  if (input == '1')
							  {
								  string name = "";
								  time_t  t2 = time(0); // get time now

								  if (t1 + 5 < t2)
								  {
									  std::cout << "You waited too long" << endl;
									  std::cout << team[j]->get_hero() << " reputation has dropped by " << 3 * 0.1 << endl;
									  team[j]->set_reputation(-3 * 0.1);
								  }
								  else
								  {
									  std::cout << "You decided to try and save the person." << endl;
									  std::cout << "How are you going to do this?" << endl;
									  system("pause");
									  system("cls");
									  std::cout << "1. Try and catch him." << endl;
									  std::cout << "2. Try and get to the top of the building and stop him." << endl;

									  if (team[j]->get_hero() == "Spiderman")
									  {
										  std::cout << "3. Spin a web to break his fall" << endl;
									  }
									  else if (team[j]->get_hero() == "Iron Man" || team[j]->get_hero() == "Ms. Marvel")
									  {
										  std::cout << "3. Fly up and grab them" << endl;
									  }
									  else if (team[j]->get_hero() == "Wolverine" || team[j]->get_hero() == "Black Panther")
									  {
										  std::cout << "3. Leap from a near by building and try to catch them mid air." << endl;
									  }
									  else if (team[j]->get_hero() == "Captain America" || team[j]->get_hero() == "Black Widow")
									  {
										  std::cout << "3. Convince them that it is not worth it to jump" << endl;
									  }
									  else if (team[j]->get_hero() == "Mr. Fantastic")
									  {
										  std::cout << "3. Stretch up and grab them" << endl;
									  }

									  std::cout << choice << "this" << endl;
									  time_t  t1 = time(0);  // get time now
									  input = selection(input);


									  if (input == '1')
									  {
										  input = 1;
									  }
									  else if (input == '2')
									  {
										  input = 2;
									  }
									  else if (input == '3')
									  {
										  input = 3;
									  }
									  if (input == choice)
									  {
										  time_t  t2 = time(0); // get time now

										  if (t1 + 3 < t2)
										  {
											  std::cout << "You did not act fast enough and the person falls and dies!" << endl;
											  std::cout << "The crowd turns against you and blames you for the person's death." << endl;
											  std::cout << team[j]->get_hero() << " reputation has dropped by " << 3 * 0.1 << endl;
											  team[j]->set_reputation(-3 * 0.1);

										  }
										  else
										  {
											  std::cout << "You manage to save the person and everyone stars cheering!" << endl;
											  std::cout << team[j]->get_hero() << " reputation has increased by " << 3 * 0.1 << endl;
											  team[j]->set_reputation(+3 * 0.1);

										  }
									  }
									  else
									  {
										  std::cout << "Your choice did not work and the person dies." << endl;
										  std::cout << team[j]->get_hero() << " reputation has dropped by " << 1 * 0.1 << endl;
										  team[j]->set_reputation(-1 * 0.1);

									  }
								  }
							  }
							  else if (input == '2')
							  {
								  std::cout << "You chose to do nothing and let the person die." << endl;
								  std::cout << "The crowd turns aggressive and they come after you!" << endl;
								  std::cout << "Will you attack civilians?" << endl;
								  std::cout << "1. Yes, attack" << endl;
								  std::cout << "2. No, run away" << endl;
								  input = selection(input);
								  if (input == '1')
								  {
									  std::cout << "You decided that you are going to teach the mob a lesson." << endl;

									  int rand_int = rand() % 10;
									  rand_int++;
									  enemies* Enemies = new enemies();
									  for (int i = 0; i < rand_int; i++)
									  {
										  Enemies = create_enemy(p, m, i, -1);
										  group.push_back(Enemies);
										  if (i == rand_int - 1)
										  {
											  fight(p, Enemies);
											  Enemies->reset_rnd();
										  }
									  }

								  }
								  else if (input == '2')
								  {
									  std::cout << "You chose to run away and give the people time to calm down." << endl;
								  }

							  }
						  }
					  }
				  }
				  if (input == '2')
				  {
					  std::cout << "You chose to ignor the jumper." << endl;
					  if (team[j]->get_reputation() > 0)
					  {
						  std::cout << team[j]->get_hero() << " reputation has dropped by " << 1 * 0.1 << endl;
						  team[j]->set_reputation(-1 * 0.1);
					  }

					  break;
				  }
			  }
			  
			  
			  break;
	}

	case 3:
	{
			  int no = 0;
			  int rand_int = rand() % 5;
			  enemies* e = new enemies();
			  bool dead = true;
			  bool fights = true;
			  string city;
			  //change to be like case 5, ternary and find no loop
			  std::cout<< "case 3" << endl;
			  if (m->get_city() == "Long Island" && p->get_level() >= 5 && p->get_registration() == "anti")
			  {
				  int rand_hero = rand() % 10;
				  if (rand_hero > 4)
				  {
					  e->set_enemies("Ms. Marvel", p);
				  }
				  else
				  {
					  e->set_enemies("Iron Man", p);
				  }

			  }
			  else if (m->get_city() == "New York City" && p->get_level() >= 5)
			  {
				  if (p->get_registration() == "anti")
				  {
					  e->set_enemies("Black Widow", p);
				  }
				  else
				  {
					  e->set_enemies("Wolverine", p);
				  }
			  }
			  else if (m->get_city() == "Brooklyn" && p->get_registration() == "pro" && p->get_level() >= 5)
			  {
				  e->set_enemies("Captain America", p);
			  }
			  else if (m->get_city() == "Queens" && p->get_registration() == "pro" && p->get_level() >= 5)
			  {
				  e->set_enemies("Spiderman", p);
			  }
			  else if (m->get_city() == "Manhattan" && p->get_registration() == "anti" && p->get_level() >= 5)
			  {
				  e->set_enemies("Mr. Fantastic", p);
			  }
			  else if (m->get_city() == "Wakanda" && p->get_registration() == "pro" && p->get_level() >= 5)
			  {
				  e->set_enemies("Black Panther", p);
			  }
			  else if (m->get_city() == "Sewers" && p->get_level() >= 5)
			  {
				  (find(mission_vill.begin(), mission_vill.end(), "Callisto") != mission_vill.end()) ?
					  (find(mission_vill.begin(), mission_vill.end(), "Dark Beast") != mission_vill.end()) ?
					  (find(mission_vill.begin(), mission_vill.end(), "Caliban") != mission_vill.end()) ?
					  e->set_enemies("Marrow", p) : no = 1 : no = 1 : no = 1;

				  if (no == 1)
				  {
					  std::cout << "You see Marrow but it is to late, she has escaped deeper into the Sewers." << endl;
				  }
			  }
			  else if (m->get_city() == "The X Mansion" && p->get_level() >= 5)
			  {
				  if (p->get_registration() == "anti")
				  {
					  (find(mission_vill.begin(), mission_vill.end(), "Bastion") != mission_vill.end()) ?
						  (find(mission_vill.begin(), mission_vill.end(), "Machine Man") != mission_vill.end()) ?
						  e->set_enemies("Tri-Sentinel", p) : no = 1 : no = 1;

					  if (no == 1)
					  {
						  std::cout << "You find Tri-Sentinel just as he flys away." << endl;
					  }
				  }
				  else
				  {
					  (find(mission_vill.begin(), mission_vill.end(), "Quicksilver") != mission_vill.end()) ?
						  (find(mission_vill.begin(), mission_vill.end(), "Toad") != mission_vill.end()) ?
						  (find(mission_vill.begin(), mission_vill.end(), "Scarlet Witch") != mission_vill.end()) ?
						  e->set_enemies("Magneto", p) : no = 1 : no = 1 : no = 1;

					  if (no == 1)
					  {
						  std::cout << "You find Magneto but he is still being protected by his followers." << endl;
					  }
				  }
				 
			  }
			  else if (m->get_city() == "Savage Lands" && p->get_level() >= 5)
			  {
				  fights = false;
				  std::cout << "Still no sign of Stegron or Sauron." << endl;
			  }
			  else if (m->get_city() == "Hells Kitchen" && p->get_level() >= 5)
			  {
				  if (p->get_registration() == "anti")
				  {
					  if (m->get_playerx() == m->get_length() - 2)
					  {
						  e->set_enemies("Kingpin", p);
					  }
					  else
					  {
						  fights = false;
						  std::cout << "No sign of the Kingpin here." << endl;
					  }
				  }
				  else
				  {
					  (find(mission_vill.begin(), mission_vill.end(), "Daredevil") != mission_vill.end()) ?
						  (find(mission_vill.begin(), mission_vill.end(), "Luke Cage") != mission_vill.end()) ?
							 e->set_enemies("Iron Fist", p) : no = 1 : no = 1;

					  if (no == 1)
					  {
						  std::cout << "No sign of unregistered heros here." << endl;
					  }
				  }
			  }
			  else if (m->get_city() == "Central Park" && p->get_level() >= 5)
			  {
				  (find(mission_vill.begin(), mission_vill.end(), "Blockbuster") != mission_vill.end()) ?
					  (find(mission_vill.begin(), mission_vill.end(), "Lady Mastermind") != mission_vill.end()) ?
					  (find(mission_vill.begin(), mission_vill.end(),"Arclight") != mission_vill.end()) ?
					  e->set_enemies("Mister Sinister", p) : no = 1 : no = 1 : no = 1;
				 
				  if(no == 1)
				  {
					  std::cout << "You see Mister Sinister in the distance but there is no way to get to him yet." << endl;
				  }
			  }
			  else if (m->get_city() == "Avenger Tower" && p->get_level() >= 5)
			  {
				  (find(mission_vill.begin(), mission_vill.end(), "Powderkeg") != mission_vill.end()) ?
					  (find(mission_vill.begin(), mission_vill.end(), "Shocker") != mission_vill.end()) ?
					  (find(mission_vill.begin(), mission_vill.end(), "Titania") != mission_vill.end()) ?
					  e->set_enemies("Doctor Octopus", p) : no = 1 : no = 1 : no = 1;
				  if (no == 1)
				  {
					  std::cout << "You know Doctor Octopus is here somewhere, but where." << endl;
				  }
			  }
			  else if (p->get_level() >= 3)
			  {
				  e->set_enemies("Mob Leader", p);
			  }
			  else
			  {
				  fights = false;
				  std::cout<< "Nothing going on." << endl;
			  }

			  if (find(mission_vill.begin(), mission_vill.end(), e->get_enemies()) != mission_vill.end())
			  {		  
				  (m->get_city() == "Sewers" || m->get_city() == "Central Park") ? dead_leaders = 4 :
					  (m->get_city() == "The X Mansion" && p->get_registration() == "anti") ? dead_leaders = 3 :
						  (m->get_city() == "The X Mansion" && p->get_registration() == "pro") ? dead_leaders = 4 :
							  (m->get_city() == "Hells Kitchen" &&  p->get_registration() == "anti") ? dead_leaders = 1 :
								  (m->get_city() == "Hells Kitchen" &&  p->get_registration() == "pro") ? dead_leaders = 3 :
									  (m->get_city() == "Savage Lands") ? dead_leaders = 2 : 
											(m->get_city() == "Avenger Tower") ? dead_leaders = 4 : dead_leaders = 0;
			   }
				  
			  while (find(die.begin(), die.end(), e->get_enemies()) != die.end())
			  {
				  e->set_enemies("hero", p);

				  if (die.size() == 4)
				  {
					  e->set_enemies("Hulk", p);
				  }
			  }
			  (no == 1) ? fights = false : 0;

			  if (fights)
			  {
				  e->set_level(p);
				  e->get_level();
				  e->set_strenght(0, team[j]);
				  e->get_strength();
				  e->set_experience();
				  e->get_experience();
				  e->set_Cskill(0, team[j]);
				  e->get_Cskill();
				  e->set_durability(0, team[j]);
				  e->get_durability();
				  e->set_energy(0, team[j]);
				  e->set_intelligence(0, team[j]);

				  if (e->get_enemies() != "Mob Leader")
				  {
					  e->set_boss();
					  int e_pp = p->get_level() * 4;

					  for (int i = 0; i < e_pp; i++)
					  {
						  int rand_pp = rand() % 6;
						  if (rand_pp == 0)
						  {
							  e->set_strenght(+1, p);
						  }
						  else if (rand_pp == 1)
						  {
							  e->set_speed(+1);
						  }
						  else if (rand_pp == 2)
						  {
							  e->set_durability(+1, p);
						  }
						  else if (rand_pp == 3)
						  {
							  e->set_Cskill(+1, p);
						  }
						  else if (rand_pp == 4)
						  {
							  e->set_energy(+1, p);
						  }
						  else if (rand_pp == 5)
						  {
							  e->set_intelligence(+1, p);
						  }
					  }
				  }
				  //e_dur * (15 + e_lvl) + 100
				  e->set_health(e->get_durability() * (15 + e->get_level()) + 100);
				  e->max_health(e->get_health());
				  e->get_health();

				  switch (e->get_enum())
				  {
				  case IRON_MAN:
					  e->set_speed(4 + e->get_level());
					  e->set_reduce();
					  break;
				  case SPIDERMAN:
					  e->set_speed(5 + e->get_level());
					  e->set_web_str(+e->get_energy());
					  break;
				  case WOLVERINE:
					  e->set_speed(3 + e->get_level());
					  e->set_regen();
					  break;
				  case CAPTAIN_AMERICA:
					  e->set_speed(3 + e->get_level());
					  break;
				  case BLACK_WIDOW:
					  e->set_speed(2 + e->get_level());
					  break;
				  case BLACK_PANTHER:
					  e->set_speed(4 + e->get_level());
					  break;
				  case MS_MARVEL:
					  e->set_speed(5 + e->get_level());
					  break;
				  case MR_FANTASTIC:
					  e->set_speed(2 + e->get_level());
					  e->set_reduce();
					  break;
				  case MARROW:
					  e->set_speed(2 + e->get_level());
					  e->set_reduce();
					  e->set_villian();
					  break;
				  case TRI_SENTINEL:
					  e->set_speed(5 + e->get_level());
					  e->set_regen();
					  e->set_reduce();
					  e->set_villian();
					  break;
				  case MAGNETO:
					  e->set_speed(4 + e->get_level());
					  e->set_reduce();
					  e->set_villian();
					  break;
				  case KINGPIN:
					  e->set_speed(2 + e->get_level());
					  e->set_reduce();
					  e->set_villian();
					  break;
				  case IRON_FIST:
					  e->set_speed(5 + e->get_level());
					  break;
				  case MISTER_SINISTER:
					  e->set_speed(5 + e->get_level());
					  e->set_regen();
					  e->set_reduce();
					  e->set_villian();
					  break;
				  case HULK:
					  e->set_speed(7 + e->get_level());
					  e->set_regen();
					  e->set_reduce();
					  e->set_rage(rage);
					  e->set_villian();
					  break;
				  case DOCTOR_OCTOPUS:
					  e->set_speed(3 + e->get_level());
					  e->set_villian();
					  break;
				  default:
					  e->set_speed(1 + spd + e->get_level());
					  e->set_villian();
					  break;
				  }
				  e->set_villian();
				  e->set_reputation();
				  e->set_defense(e->get_Cskill() + e->get_level() + e->get_speed() + rand_int);
				  group.push_back(e);
				  for (size_t i = 0; i < group.size(); i++)
				  {
					  std::cout << group[i]->get_enemies() << endl;
				  }
				  fight(p, e);
				  e->reset_rnd();
			  }
			  
			  break;
	}
	case 4:
	{
		if (p->get_level() > 4)
		{
			{

				int rand_m = rand() % 5;
				char mission = 0;
				bool input = true;
				if (events_m.size() == 0)
				{
					std::cout << "There is a mission avaible." << endl;
					std::cout << "Would you like to start a mission?" << endl;
					std::cout << "1. Yes" << endl << "2. No" << endl;
					while (input)
					{
						mission = selection(mission);
						if (mission == '1')
						{
							num_people(p);
							get_people();
							mission_stat(0);
							mission_run(1);

							input = false;
						}
						else if (mission == '2')
						{
							if (missions.size() == 6)
							{
								for (size_t i = 0; i < 3; i++)
								{
									missions.pop_back();
								}
								return;
							}
							bool new_mission = false;
							while (new_mission == false)
							{

								int rand_mission_location = rand() % 6;
								int count = 0;
								if (rand_mission_location == 0)
								{
									for (size_t i = 0; i < missions.size(); i++)
									{
										if (missions[i] == "Sewers")
										{
											break;
										}
										count++;
									}
									if (count == missions.size())
									{
										missions.push_back("Sewers");
										new_mission = true;
										input = false;
										return;
									}
								}
								else if (rand_mission_location == 1)
								{
									for (size_t i = 0; i < missions.size(); i++)
									{
										if (missions[i] == "Central Park")
										{
											break;
										}
										count++;
									}
									if (count == missions.size())
									{
										missions.push_back("Central Park");
										new_mission = true;
										input = false;
										return;
									}

								}
								else if (rand_mission_location == 2)
								{
									for (size_t i = 0; i < missions.size(); i++)
									{
										if (missions[i] == "Hells Kitchen")
										{
											break;
										}
										count++;
									}
									if (count == missions.size())
									{
										missions.push_back("Hells Kitchen");
										new_mission = true;
										input = false;
										return;
									}
								}
								else if (rand_mission_location == 3)
								{
									for (size_t i = 0; i < missions.size(); i++)
									{
										if (missions[i] == "The X Mansion")
										{
											break;
										}
										count++;
									}
									if (count == missions.size())
									{
										missions.push_back("The X Mansion");
										new_mission = true;
										input = false;
										return;
									}
								}
								else if (rand_mission_location == 4)
								{
									for (size_t i = 0; i < missions.size(); i++)
									{
										if (missions[i] == "Savage Lands")
										{
											break;
										}
										count++;
									}
									if (count == missions.size())
									{
										missions.push_back("Savage Lands");
										new_mission = true;
										input = false;
										return;
									}
								}
								else if (rand_mission_location == 5)
								{
									for (size_t i = 0; i < missions.size(); i++)
									{
										if (missions[i] == "Avenger Tower")
										{
											break;
										}
										count++;
									}
									if (count == missions.size())
									{
										missions.push_back("Avenger Tower");
										new_mission = true;
										input = false;
										return;
									}
								}
							}



						}
						else
						{
							std::cout << "Please select a vaild choice." << endl;
						}
					}

				}
				mission_stat(0);
				if (events.size() > 0)
				{
					events.clear();
				}
				events.push_back("event");
				bool t_mission = true;
				bool start = true;
				int pxs;
				int pys;
				string poss;
				Map* maps = new Map();
				while (t_mission)
				{
					while (start)
					{
						pxs = maps->get_playerx();
						pys = maps->get_playery();
						poss = maps->get_map_spot(pxs, pys);
						// if (player picks old mission)
						if (events_m.size() > 0)
						{
							maps->set_city_travel(events_m[0]);
						}
						else
						{
							if (rand_m == 0)
							{
								maps->set_city_travel("Sewers");

							}
							else if (rand_m == 1)
							{
								maps->set_city_travel("Central Park");

							}
							else if (rand_m == 2)
							{
								maps->set_city_travel("Hells Kitchen");

							}
							else if (rand_m == 3)
							{
								maps->set_city_travel("The X Mansion");

							}
							else if (rand_m == 4)
							{
								maps->set_city_travel("Savage Lands");

							}
							else if (rand_m == 5)
							{
								maps->set_city_travel("Avenger Tower");

							}

						}
						maps->get_city();
						city.pop_back();
						city.push_back(maps->get_city());

						std::cout << "You travel to " << maps->get_city() << endl;
						maps->generate_map();
						system("pause");
						system("CLS");
						start = false;
						events_m.clear();

					}
					poss = maps->get_map_spot(pxs, pys);

					if (poss == ">" && mission_complete == true)
					{
						std::cout << "here end" << endl;
						events.push_back("end");
						maps->clear_map();
						delete maps;
						return;
					}
					if (pxs != 0 && poss != "|" && poss != ">")
					{
						if (options.size() > 0)
						{
							options.clear();
						}
						else
						{
							events1(p, maps);
							if (m->get_city() == "Sewers" || m->get_city() == "Central Park")
							{
								if (dead_leaders == 4 && get_people() == 0)
								{
									mission_complete = true;
								}
							}
							else if (m->get_city() == "The X Mansion")
							{
								if (p->get_registration() == "anti")
								{
									if (dead_leaders == 3 && get_people() == 0)
									{
										mission_complete = true;
									}
								}
								else
								{
									if (dead_leaders == 4 && get_people() == 0)
									{
										mission_complete = true;
									}
								}

							}
							else if (m->get_city() == "Hells Kitchen")
							{
								if (p->get_registration() == "anti")
								{
									if (dead_leaders == 1)
									{
										mission_complete = true;
									}
								}
								else
								{
									if (dead_leaders == 3)
									{
										mission_complete = true;
									}
								}
							}
							else if (m->get_city() == "Savage Lands")
							{
								if (dead_leaders == 2)
								{
									mission_complete = true;
								}
							}
							explosion = false;
							while (explosion_victim.size() != 0)
							{
								explosion_victim.pop_back();
							}
							player_stats_renew(p);
							if (p->get_hero() == "Spiderman")
							{
								while (p->get_web_strength() > p->get_energy())
								{
									p->set_web_strength(-1);
								}
							}
							system("pause");
							system("cls");

						}

						maps->generate_map();


					}
					if (pxs == 0)
					{
						system("cls");
						maps->generate_map();
						std::cout << "1. Contiune" << endl;


					}
					else if (poss != ">")
					{
						if (poss == "|")
						{
							maps->generate_map();
						}
						std::cout << "1. Continue" << endl;
						std::cout << "2. Go Back" << endl;
						std::cout << "3. Options" << endl;



					}

					bool move = true;
					while (move)
					{
						if (poss == ">")
						{
							if (mission_complete == false)
							{
								std::cout << "Your mission is not finished yet. Do you wish to quit?" << endl << "1. Yes" << endl << "2. No" << endl;
								char input = 0;
								input = selection(input);
								if (input == '1')
								{
									mission_run(0);
									maps->clear_map();
									delete maps;
									move = false;
									break;
								}
								else if (input == '2')
								{
									pxs--;
									maps->set_player(pxs, pys);
									system("cls");
									move = false;
								}
								else
								{
									std::cout << "Please select a valid choice" << endl;
								}

							}
							else
							{
								mission_run(0);
								maps->clear_map();
								delete maps;
								move = false;
								break;
							}

						}
						char input = 0;
						input = selection(input);

						if (input == '1')
						{
							if (poss == "|" && pxs != 0)
							{
								std::cout << "1. Up?" << endl;
								std::cout << "2. Down?" << endl;
								input = selection(input);
								if (input == '1')
								{
									pys--;
									move = false;
								}
								else
								{
									pys++;
									move = false;
								}


								maps->set_player(pxs, pys);
								system("cls");


								move = false;

							}


							else
							{
								pxs++;
								maps->set_player(pxs, pys);
								system("cls");
								move = false;

							}
						}
						else if (input == '2' && pxs != 0)
						{
							pxs--;
							maps->set_player(pxs, pys);
							move = false;

						}
						else if (input == '3' && pxs != 0)
						{
							system("cls");
							options.push_back("options");
							std::cout << "1. Hero Details" << endl;
							std::cout << "2. Save" << endl;

							char input = 0;
							bool menu = true;
							while (menu)
							{
								input = selection(input);
								if (input == '1')
								{
									system("cls");
									p->print_stat();
									system("pause");
									system("cls");
									move = false;
									menu = false;
								}
								else if (input == '2')
								{
									std::cout << "saveing" << endl;
									save(p, maps);
									std::cout << "Would you like to quit the mission?" << endl;
									std::cout << "1. Yes" << endl;
									std::cout << "2. No" << endl;
									char choice = 0;
									bool end = true;

									while (end)
									{
										choice = selection(choice);
										if (choice == '1')
										{
											maps->clear_map();
											delete maps;
											return;

										}
										else if (choice == '2')
										{

											end = false;
											menu = false;
											move = false;
											system("cls");
											continue;



											end = false;
										}
										else
										{
											std::cout << "Please enter a vaild choice." << endl;
										}
									}
								}
								else
								{
									std::cout << "Please enter a vaild choice" << endl;
								}
							}


						}

						else
						{
							std::cout << "Please enter a vaild choice" << endl;
						}


						if (p->get_reputation() >= 100)
						{
							return;
						}
					}
				}

			}
		}
		else
		{
			std::cout << "A Mission is avalible but your not strong enough yet." << endl;
		}
		break;
	}

	case 5:
	{
			  std::cout << "case 5" << endl;			
			  int rand_int = rand() % 5;
			  enemies* Villian = new enemies();
			  int villian_pick = rand() % 8;

				  if (m->get_city() == "Sewers")
				  {
					  if (villian_pick == 0 || villian_pick < 3)
					  {
						  (find(mission_vill.begin(), mission_vill.end(), "Callisto") != mission_vill.end()) ?
							  Villian->set_enemies("Morlock", p) : Villian->set_enemies("Callisto", p);
					  }
					  else if (villian_pick == 3 || villian_pick < 6)
					  {
						  (find(mission_vill.begin(), mission_vill.end(), "Dark Beast") != mission_vill.end()) ?
							  Villian->set_enemies("Morlock", p) : Villian->set_enemies("Dark Beast", p);						  
					  }
					  else if (villian_pick >= 6)
					  {
						  (find(mission_vill.begin(), mission_vill.end(), "Caliban") != mission_vill.end()) ?
							  Villian->set_enemies("Morlock", p) : Villian->set_enemies("Caliban", p);
					  }
				  }
				  else if (m->get_city() == "Central Park")
				  {
					  if (villian_pick == 0 || villian_pick < 3)
					  {
						  (find(mission_vill.begin(), mission_vill.end(), "Blockbuster") != mission_vill.end()) ?
							  Villian->set_enemies("Marauder", p) : Villian->set_enemies("Blockbuster", p);
					  }
					  else if (villian_pick == 3 || villian_pick < 6)
					  {
						  (find(mission_vill.begin(), mission_vill.end(), "Lady Mastermind") != mission_vill.end()) ?
							  Villian->set_enemies("Marauder", p) : Villian->set_enemies("Lady Mastermind", p);
					  }
					  else if (villian_pick >= 6)
					  {
						  (find(mission_vill.begin(), mission_vill.end(), "Arclight") != mission_vill.end()) ?
							  Villian->set_enemies("Marauder", p) : Villian->set_enemies("Arclight", p);
					  }
				  }
				  else if (m->get_city() == "The X Mansion")
				  {
					  if (p->get_registration() == "anti")
					  {
						  if (villian_pick <= 3)
						  {
							  (find(mission_vill.begin(), mission_vill.end(), "Machine Man") != mission_vill.end()) ?
								  Villian->set_enemies("Sentinel", p) : Villian->set_enemies("Machine Man", p);
						  }
						  else
						  {
							  (find(mission_vill.begin(), mission_vill.end(), "Bastion") != mission_vill.end()) ?
								  Villian->set_enemies("Sentinel", p) : Villian->set_enemies("Bastion", p);
						  }

					  }
					  else
					  {
						  if (villian_pick == 0 || villian_pick < 3)
						  {
							  (find(mission_vill.begin(), mission_vill.end(), "Quicksilver") != mission_vill.end()) ?
								  Villian->set_enemies("Mutant", p) : Villian->set_enemies("Quicksilver", p);
						  }
						  else if (villian_pick == 3 || villian_pick < 6)
						  {
							  (find(mission_vill.begin(), mission_vill.end(), "Toad") != mission_vill.end()) ?
								  Villian->set_enemies("Mutant", p) : Villian->set_enemies("Toad", p);
						  }
						  else if (villian_pick >= 6)
						  {
							  (find(mission_vill.begin(), mission_vill.end(), "Scarlet Witch") != mission_vill.end()) ?
								  Villian->set_enemies("Mutant", p) : Villian->set_enemies("Scarlet Witch", p);
						  }
					  }
				  }
				  else if (m->get_city() == "Hells Kitchen")
				  {
					  if (p->get_registration() == "anti")
					  {

						  Villian->set_enemies("Cape-Killer Captain", p);
					  }
					  else
					  {
						  if (villian_pick <= 3)
						  {
							  (find(mission_vill.begin(), mission_vill.end(), "Daredevil") != mission_vill.end()) ?
								  Villian->set_enemies("Rebel Captain", p) : Villian->set_enemies("Daredevil", p);
						  }
						  else
						  {
							  (find(mission_vill.begin(), mission_vill.end(), "Luke Cage") != mission_vill.end()) ?
								  Villian->set_enemies("Rebel Captain", p) : Villian->set_enemies("Luke Cage", p);
						  }

					  }
				  }
				  else if (m->get_city() == "Savage Lands")
				  {
					  if (villian_pick <= 3)
					  {
						 (find(mission_vill.begin(), mission_vill.end(), "Stegron") != mission_vill.end()) ?
							  Villian->set_enemies("Velociraptor", p) : Villian->set_enemies("Stegron", p);
					  }
					  else
					  {
						  (find(mission_vill.begin(), mission_vill.end(), "Sauron") != mission_vill.end()) ?
							  Villian->set_enemies("Reptile Man", p) : Villian->set_enemies("Sauron", p);
					  }

				  }
				  else if (m->get_city() == "Avenger Tower")
				  {
					  if (villian_pick == 0 || villian_pick < 3)
					  {
						  (find(mission_vill.begin(), mission_vill.end(), "Powderkeg") != mission_vill.end()) ?
							  (p->get_registration() == "pro")? Villian->set_enemies("Rebel", p) : 
							  Villian->set_enemies("Powderkeg", p) : Villian->set_enemies("Cape-Killer", p);
					  }
					  else if (villian_pick == 3 || villian_pick < 6)
					  {
						  (find(mission_vill.begin(), mission_vill.end(), "Shocker") != mission_vill.end()) ?
							  (p->get_registration() == "pro") ? Villian->set_enemies("Rebel", p) :
							  Villian->set_enemies("Shocker", p) : Villian->set_enemies("Cape-Killer", p);
					  }
					  else if (villian_pick >= 6)
					  {
						  (find(mission_vill.begin(), mission_vill.end(), "Titania") != mission_vill.end()) ?
							  (p->get_registration() == "pro") ? Villian->set_enemies("Rebel", p) :
							  Villian->set_enemies("Titania", p) : Villian->set_enemies("Cape-Killer", p);
					  }
				  }
				  else
				  {
					  if (p->get_level() > 4)
					  {
						  switch (villian_pick)
						  {
						  case 0:
							  (find(v_die.begin(), v_die.end(), "Green Goblin") != v_die.end()) ?
								  Villian->set_enemies("Thug", p) : Villian->set_enemies("Green Goblin", p);
							  break;
						  case 1:
							  (find(v_die.begin(), v_die.end(), "Venom") != v_die.end()) ?
								  Villian->set_enemies("Thug", p) : Villian->set_enemies("Venom", p);
							  break;
						  case 2:
							  (find(v_die.begin(), v_die.end(), "Red Skull") != v_die.end()) ?
								  Villian->set_enemies("Thug", p) : Villian->set_enemies("Red Skull", p);
							  break;
						  case 3:
							  (find(v_die.begin(), v_die.end(), "Zemo") != v_die.end()) ?
								  Villian->set_enemies("Thug", p) : Villian->set_enemies("Zemo", p);
							  break;

						  case 4:
							  (find(v_die.begin(), v_die.end(), "Sabretooth") != v_die.end()) ?
								  Villian->set_enemies("Thug", p) : Villian->set_enemies("Sabretooth", p);
							  break;

						  case 5:
							  (find(v_die.begin(), v_die.end(), "Nitro") != v_die.end()) ?
								  Villian->set_enemies("Thug", p) : Villian->set_enemies("Nitro", p);
							  break;

						  case 6:
							  (find(v_die.begin(), v_die.end(), "Whiplash") != v_die.end()) ?
								  Villian->set_enemies("Thug", p) : Villian->set_enemies("Whiplash", p);
							  break;

						  case 7:
							  (find(v_die.begin(), v_die.end(), "Titanium Man") != v_die.end()) ?
								  Villian->set_enemies("Thug", p) : Villian->set_enemies("Titanium Man", p);
							  break;
						  }
					  }
					  else
					  {
						  Villian->set_enemies("Mob Leader",p);
					  }
					  
				  }
				  if (v_die.size() >= 8)
				  {
					  Villian->set_enemies("Hulk", p);
				  }
				  
			  

			  std::cout << Villian->get_enemies() << endl;
			  /*if (v_die.size() > 0)
			  {
				  int count_v = 0;
				  while (dead)
				  {
					  if (find(v_die.begin(), v_die.end(), Villian->get_enemies()) != v_die.end())
					  {
						  std::cout << " Replacing villian" << endl;
						  delete Villian;
						  enemies* Villian = new enemies();
						  Villian->set_enemies("villian", p);
						  Villian->get_enemies();
						  std::cout << Villian->get_enemies() << " new enemie?" << endl;
						  for (size_t i = 0; i < v_die.size(); i++)
						  {
							  if (v_die[i] == "Whiplash")
							  {
								  count_v++;
							  }
							  else if (v_die[i] == "Titanium Man")
							  {
								  count_v++;
							  }
							  else if (v_die[i] == "Nitro")
							  {
								  count_v++;
							  }
							  else if (v_die[i] == "Sabretooth")
							  {
								  count_v++;
							  }
							  else if (v_die[i] == "Red Skull")
							  {
								  count_v++;
							  }
							  else if (v_die[i] == "Zemo")
							  {
								  count_v++;
							  }
							  else if (v_die[i] == "Venom")
							  {
								  count_v++;

							  }
							  else if (v_die[i] == "Green Goblin")
							  {
								  count_v++;
							  }
						  }
						  if (count_v == 8)
						  {
							  delete Villian;
							  enemies* Villian = new enemies();
							  Villian->set_enemies("Hulk", p);
							  Villian->get_enemies();
							  dead = false;

						  }
						  else
						  {
							  count_v = 0;
						  }
					  }

					  else
					  {
						  dead = false;
					  }

				  }

			  }*/
			  Villian->set_level(p);
			  Villian->set_strenght(0, team[j]);
			  Villian->set_experience();
			  Villian->set_Cskill(0, team[j]);
			  Villian->set_durability(0, team[j]);
			  Villian->set_energy(0, team[j]);
			  Villian->set_intelligence(0, team[j]);

			  if (Villian->get_enemies() != "Mob Leader")
			  {
				  Villian->set_boss();
				  int villian_pp = p->get_level() * 4;
				  
				  for (int i = 0; i < villian_pp; i++)
				  {
					  int rand_pp = rand() % 6;
					  if (rand_pp == 0)
					  {
						  Villian->set_strenght(+1, p);
					  }
					  else if (rand_pp == 1)
					  {
						 Villian->set_speed(+1);
					  }
					  else if (rand_pp == 2)
					  {
						  Villian->set_durability(+1, p);
					  }
					  else if (rand_pp == 3)
					  {
						  Villian->set_Cskill(+1, p);
					  }
					  else if (rand_pp == 4)
					  {
						  Villian->set_energy(+1, p);
					  }
					  else if (rand_pp == 5)
					  {
						  Villian->set_intelligence(+1, p);
					  }
				  }
			  }
			 
			  (Villian->get_enum() < 1000 ? (Villian->set_health(+Villian->get_durability() * (15 + Villian->get_level()) + (p->get_health() * 2))) : 
				  Villian->set_health(+Villian->get_durability() * (15 + Villian->get_level()) + p->get_health()));
			  Villian->max_health(Villian->get_health());
			  Villian->get_health();
			  
			  switch (Villian->get_enum())
			  {
			  case GREEN_GOBLIN:
				  Villian->set_speed(5 + Villian->get_level());
				  Villian->set_villian();
				  break;
			  case VENOM:
				  Villian->set_speed(3 + Villian->get_level());
				  Villian->set_villian();
				  break;
			  case ZEMO:
				  Villian->set_speed(3 + Villian->get_level());
				  Villian->set_villian();
				  break;
			  case RED_SKULL:
				  Villian->set_speed(3 + Villian->get_level());
				  Villian->set_villian();
				  break;
			  case SABRETOOTH:
				  Villian->set_speed(2 + Villian->get_level());
				  Villian->set_regen();
				  Villian->set_rage(rage);
				  Villian->set_villian();
				  break;
			  case NITRO:
				  Villian->set_speed(4 + Villian->get_level());
				  Villian->set_rage(rage);
				  Villian->set_villian();
				  break;
			  case WHIPLASH:
				  Villian->set_speed(2 + Villian->get_level());
				  Villian->set_villian();
				  break;
			  case TITANIUM_MAN:
				  Villian->set_speed(5 + Villian->get_level());
				  Villian->set_reduce();
				  Villian->set_villian();
				  break;
			  case STEGRON:
				  Villian->set_speed(3 + Villian->get_level());
				  Villian->set_villian();
				  break;
			  case SAURON:
				  Villian->set_speed(2 + Villian->get_level());
				  Villian->set_villian();
				  break;
			  case CALLISTO:
				  Villian->set_speed(3 + Villian->get_level());
				  Villian->set_villian();
				  Villian->set_regen();
				  break;
			  case DARK_BEAST:
				  Villian->set_speed(2 + Villian->get_level());
				  Villian->set_regen();
				  Villian->set_villian();
				  break;
			  case CALIBAN:
				  Villian->set_speed(3 + Villian->get_level());
				  Villian->set_villian();
				  break;
			  case BLOCKBUSTER:
				  Villian->set_speed(2 + Villian->get_level());
				  Villian->set_reduce();
				  Villian->set_villian();
				  break;
			  case LADY_MASTERMIND:
				  Villian->set_speed(2 + Villian->get_level());
				  Villian->set_villian();
				  break;
			  case ARCLIGHT:
				  Villian->set_speed(2 + Villian->get_level());
				  Villian->set_villian();
				  break;
			  case MACHINE_MAN:
				  Villian->set_speed(3 + Villian->get_level());
				  Villian->set_regen();
				  Villian->set_villian();
				  break;
			  case BASTION:
				  Villian->set_speed(3 + Villian->get_level());
				  Villian->set_regen();
				  Villian->set_villian();
				  break;
			  case QUICKSILVER:
				  Villian->set_speed(7 + Villian->get_level());
				  Villian->set_villian();
				  break;
			  case TOAD:
				  Villian->set_speed(3 + Villian->get_level());
				  Villian->set_villian();
				  break;
			  case SCARLET_WITCH:
				  Villian->set_speed(2 + Villian->get_level());
				  Villian->set_villian();
				  break;
			  case DAREDEVIL:
				  Villian->set_speed(2 + Villian->get_level());
				  break;
			  case LUKE_CAGE:
				  Villian->set_speed(2 + Villian->get_level());
				  Villian->set_reduce();
				  break;
			  case HULK:
				  Villian->set_speed(7 + Villian->get_level());
				  Villian->set_rage(rage);
				  Villian->set_regen();
				  Villian->set_reduce();
				  break;
			  case POWDERKEG:
				  Villian->set_speed(2 + Villian->get_level());
				  Villian->set_nitro(0);
				  Villian->set_reduce();
				  Villian->set_villian();
				  break;
			  case SHOCKER:
				  Villian->set_speed(4 + Villian->get_level());
				  Villian->set_villian();
				  break;
			  case TITANIA:
				  Villian->set_speed(2 + Villian->get_level());
				  Villian->set_villian();
				  Villian->set_reduce();
				  break;
			  }

			  Villian->set_defense(Villian->get_Cskill() + Villian->get_level() + Villian->get_speed() + rand_int);
			  Villian->set_reputation();
			 
			  group.push_back(Villian);
			  fight(p, Villian);
			  Villian->reset_rnd();

			  break;
	}
		break;













	}
}

void restart_cleanup()
{
	//explosions
	bool explosion = false;
	while (explosion_victim.size() != 0)
	{
		explosion_victim.pop_back();
	}
	int count_down = 0; // used to see if a peron will explode

	while (saved_people.size() != 0)
	{
		saved_people.pop_back();
	}

	//characters
	while (team.size() != 0)
	{
		team.pop_back();
	}
	while (group.size() != 0)
	{
		group.pop_back();
	}
	while (die.size() != 0)
	{
		die.pop_back();
	}
	while (v_die.size() != 0)
	{
		v_die.pop_back();
	}
	while (mission_vill.size() != 0)
	{
		mission_vill.pop_back();
	}

	//missions
	bool mission_complete = false;
	bool rebuild = false;
	bool mission_stats;
	bool mission_runs;
	bool menu = false;
	while (events.size() != 0)
	{
		events.pop_back();
	}
	while (missions.size() != 0)
	{
		missions.pop_back();
	}
	while (events_m.size() != 0)
	{
		events_m.pop_back();
	}

	//used to offset player added stat increases
	int pp_strength = 0;
	int pp_speed = 0;
	int pp_durability = 0;
	int pp_Cskill = 0;
	int pp_energy = 0;
	int pp_intelligence = 0;

	//map
	int people = 0;
	while (city.size() != 0)
	{
		city.pop_back();
	}
	int map_height = 6;
	int map_length = 15;
	const int player_xy = 2;

	//options
	while (options.size() != 0)
	{
		options.pop_back();
	}
}

void load(player* p)
{
	enemies* e = new enemies();
	int dine;
	string dines;
	string file;
	vector<string>names;
	string war = ("C:\\Marvel Civil War");
	string name_file = "C:\\Marvel Civil War\\name.txt";
	ifstream filename(name_file);
	char input = 0;
	bool pick = true;
	if (filename.is_open())
	{
		while (!filename.eof())
		{
			filename >> dines;
			names.push_back(dines);
		}
	}
	else
	{
		std::cout << "No Saved Files found.\n";
		std::cout << "Press any key to continue...\n";
		_getch();
		std::system("cls");
		input = '3';
		
	}
	
	std::sort(names.begin(), names.end());
	names.erase(unique(names.begin(), names.end()), names.end());

	ofstream filenames(name_file);
	for (size_t i = 0; i < names.size(); i++)
	{
		filenames << names[i] << endl;
	}

	
	
	while (pick)
	{
		system("cls");
		std::cout << "D. Delete a file" << endl;
		std::cout << "M. Main Menu" << endl << endl;
		std::cout << "Please select a file to load." << endl;
		int i = 0;
		for (size_t ii = 0; ii < names.size(); ii++)
		{
			std::cout << ii << ". " << names[ii] << endl;
			i = ii;
		}
		input = selection(input);
		if (input == 'D')
		{
			int i = 0;
			std::cout << "Please select a file to delete." << endl;
			for (size_t t = 0; t < names.size(); t++)
			{
				std::cout << t << ". " << names[t] << endl;
				i = (int)t;
			}
			int check = i + '0';
			do
			{
				input = selection(input);
				if (input >= (i + '0') || input < i + '0')
				{
					std::cout << "Please select a correct choice.\n";
				}
			} while (!(input >= '0' && input <= check));
			 i = input - '0';
			 std::cout << "Delete " << names[i] << "?\n0. Yes\n1. No\n";
			 bool deleteing = true;
			 do
			 {
				 input = selection(input);
				 if (input == '0')
				 {
					 string newDir = (war + "\\" + names[i]);
					 string delete_text = newDir + "\\" + names[i] + ".bin";
					 std::cout << names[i] << endl;

					 if (remove(delete_text.c_str()) != 0) // deletes the text file
					 {
						 std::cout << "Error file not found" << endl;
					 }
					 else
					 {
						 std::cout << "File deleted" << endl;
						 string dead_hero = newDir + "\\" + names[i] + "_h.bin";
						 string dead_villian = newDir + "\\" + names[i] + "_v.bin";
						 string mission_list = newDir + "\\" + names[i] + "_m.bin";
						 string dead_mission_villian = newDir + "\\" + names[i] + "_mv.bin";

						 remove(dead_hero.c_str());
						 remove(dead_villian.c_str());
						 remove(mission_list.c_str());
						 remove(dead_mission_villian.c_str());

						 BOOL WINAPI RemoveDirectory(_In_ LPCTSTR newDir);

						 RemoveDirectory(newDir.c_str());// deletes the folder
						 swap(names[i], names[names.size() - 1]);
						 names.pop_back();
						 ofstream filename(name_file, ios::trunc);
						 for (size_t i = 0; i < names.size(); i++)
						 {
							 filename << names[i] << endl;
						 }
					 }
					 deleteing = false;
				 }
				 else if (input == '1')
				 {
					 deleteing = false;
				 }
				 else
				 {
					 std::cout << "Please input a correct choice.\n";
				 }
			 } while (deleteing);
			
			system("pause");
			system("cls");

		}
		else if (input == 'M')
		{
			pick = false;
			menu = true;
			system("cls");
		}
		else if(input  == '0' || input <= i + '0')
		{
			
			i = input - '0';
			file = names[i];
			ifstream myfile(war + "\\" + file + "\\" + file + ".bin", ios::in | ios::binary);
			if (myfile.is_open())
			{
				menu = false;
				loaded = true;
				getline(myfile, dines);
				p->set_hero(dines);

				p->set_level(-p->get_level());
				myfile >> dine;
				p->set_level(dine);
				myfile >> dine;
				p->set_strenght(dine);
				myfile >> dine;
				p->set_speed(dine);
				myfile >> dine;
				p->set_durability(dine);
				myfile >> dine;
				p->set_Cskill(dine);
				myfile >> dine;
				p->set_energy(0);
				p->set_energy(dine);
				myfile >> dine;
				p->set_intelligence(0);
				p->set_intelligence(dine);



				if (p->get_hero() == "Spiderman")
				{
					pp_speed = p->get_speed() - p->get_level() - 5;
					pp_strength = p->get_strength() - p->get_level() - 3;
					pp_Cskill = p->get_Cskill() - p->get_level() - 4;
					pp_durability = p->get_durability() - p->get_level() - 2;
					pp_energy = p->get_energy() - p->get_level() - 3;
					pp_intelligence = p->get_intelligence() - p->get_level() - 3;

					p->set_web_strength(-p->get_web_strength());
					p->set_web_strength(+p->get_energy());
					p->set_registration("anti");
				}
				else if (p->get_hero() == "Iron Man")
				{
					pp_speed = p->get_speed() - p->get_level() - 4;
					pp_strength = p->get_strength() - p->get_level() - 5;
					pp_Cskill = p->get_Cskill() - p->get_level() - 2;
					pp_durability = p->get_durability() - p->get_level() - 5;
					pp_energy = p->get_energy() - p->get_level() - 5;
					pp_intelligence = p->get_intelligence() - p->get_level() - 5;

					p->set_reduce();
					p->set_registration("pro");
				}
				else if (p->get_hero() == "Wolverine")
				{
					pp_speed = p->get_speed() - p->get_level() - 3;
					pp_strength = p->get_strength() - p->get_level() - 4;
					pp_Cskill = p->get_Cskill() - p->get_level() - 4;
					pp_durability = p->get_durability() - p->get_level() - 4;
					pp_energy = p->get_energy() - p->get_level() - 0;
					pp_intelligence = p->get_intelligence() - p->get_level() - 1;

					p->set_registration("anti");
				}
				else if (p->get_hero() == "Captain America")
				{
					pp_speed = p->get_speed() - p->get_level() - 3;
					pp_strength = p->get_strength() - p->get_level() - 3;
					pp_Cskill = p->get_Cskill() - p->get_level() - 6;
					pp_durability = p->get_durability() - p->get_level() - 3;
					pp_energy = p->get_energy() - p->get_level() - 0;
					pp_intelligence = p->get_intelligence() - p->get_level() - 3;

					p->set_registration("anti");
				}
				else if (p->get_hero() == "Mr. Fantastic")
				{
					pp_speed = p->get_speed() - p->get_level() - 2;
					pp_strength = p->get_strength() - p->get_level() - 3;
					pp_Cskill = p->get_Cskill() - p->get_level() - 2;
					pp_durability = p->get_durability() - p->get_level() - 6;
					pp_energy = p->get_energy() - p->get_level() - 0;
					pp_intelligence = p->get_intelligence() - p->get_level() - 5;

					p->set_registration("pro");
					p->set_reduce();
					p->get_reduce();
				}
				else if (p->get_hero() == "Ms. Marvel")
				{
					pp_speed = p->get_speed() - p->get_level() - 5;
					pp_strength = p->get_strength() - p->get_level() - 4;
					pp_Cskill = p->get_Cskill() - p->get_level() - 4;
					pp_durability = p->get_durability() - p->get_level() - 4;
					pp_energy = p->get_energy() - p->get_level() - 4;
					pp_intelligence = p->get_intelligence() - p->get_level() - 2;

					p->set_registration("pro");
				}
				else if (p->get_hero() == "Black Widow")
				{
					pp_speed = p->get_speed() - p->get_level() - 2;
					pp_strength = p->get_strength() - p->get_level() - 3;
					pp_Cskill = p->get_Cskill() - p->get_level() - 6;
					pp_durability = p->get_durability() - p->get_level() - 3;
					pp_energy = p->get_energy() - p->get_level() - 2;
					pp_intelligence = p->get_intelligence() - p->get_level() - 2;

					p->set_registration("pro");
				}
				else if (p->get_hero() == "Black Panther")
				{
					pp_speed = p->get_speed() - p->get_level() - 4;
					pp_strength = p->get_strength() - p->get_level() - 4;
					pp_Cskill = p->get_Cskill() - p->get_level() - 6;
					pp_durability = p->get_durability() - p->get_level() - 3;
					pp_energy = p->get_energy() - p->get_level() - 0;
					pp_intelligence = p->get_intelligence() - p->get_level() - 4;

					p->set_registration("anti");
				}

				/*cout << pp_speed << " speed" << endl << pp_strength << " strength" << endl;
				cout << pp_Cskill << " skill" << endl << pp_durability << " dur" << endl
				<< pp_energy << " energy" << endl << pp_intelligence << " intell" << endl;*/


				int rand_int = rand() % 5;
				p->set_health(-p->get_health());
				myfile >> dine;
				p->set_health(dine);
				p->max_hlth();
				if (p->get_hero() == "Wolverine")
				{
					p->set_regen();
				}

				myfile >> dine;
				p->set_current_experience(e, dine);
				myfile >> dine;
				myfile >> dine;
				p->set_reputation(dine * .01);
				int total = 0;
				for (int i = 1; i < p->get_level(); i++)
				{
					total += (i * 25);
				}
				p->set_experience(total);
				p->set_defense(p->get_Cskill() + p->get_speed() + p->get_level() + rand_int + 10);
				p->set_evade();

				p->print_stat();
				myfile.close();
				names.clear();
				pick = false;
			}

			else
			{
				std::cout << "Please select a vaild choice" << endl;
				system("pause");

			}

			ifstream myfiledie(war + "\\" + file + "\\" + file + "_h.bin", ios::in | ios::binary);
			if (myfiledie.is_open())
			{
				while (!myfiledie.eof())
				{
					getline(myfiledie, dines);
					die.push_back(dines);
				}
				myfiledie.close();
			}

			ifstream myfilediev(war + "\\" + file + "\\" + file + "_v.bin", ios::in | ios::binary);
			if (myfilediev.is_open())
			{
				while (!myfilediev.eof())
				{
					getline(myfilediev, dines);
					v_die.push_back(dines);
				}
				myfilediev.close();
			}

			ifstream missionfiles(war + "\\" + file + "\\" + file + "_m.bin", ios::in | ios::binary);
			if (missionfiles.is_open())
			{
				while (!missionfiles.eof())
				{
					getline(missionfiles, dines);
					if (!dines.empty())
					{
						missions.push_back(dines);
					}
				}
				missionfiles.close();
			}

			ifstream missionvillians(war + "\\" + file + "\\" + file + "_mv.bin", ios::in | ios::binary);
			if (missionvillians.is_open())
			{
				while (!missionvillians.eof())
				{
					getline(missionvillians, dines);
					if (!dines.empty())
					{
						mission_vill.push_back(dines);
					}
				}
				missionvillians.close();
			}

		}
		else
		{
			std::cout << "Please enter a valid choice." << endl;
			system("pause");
		}
	}

}

int main()
{
	//Get the window console handle(isn't the right code but works for these sample
	HWND ConsoleWindow;
	SetConsoleTitle(("Marvel Civil War"));
	ConsoleWindow = FindWindow(NULL, ("Marvel Civil War"));

	ConsoleWindow = GetForegroundWindow();

	//Getting the desktop hadle and rectangule
	HWND   hwndScreen;
	RECT   rectScreen;
	hwndScreen = GetDesktopWindow();
	GetWindowRect(hwndScreen, &rectScreen);

	//Set windows size(see the width problem)*/
	SetWindowPos(ConsoleWindow, NULL, 0, 0, 1000, 500, SWP_SHOWWINDOW);

	// Get the current width and height of the console
	RECT rConsole;
	GetWindowRect(ConsoleWindow, &rConsole);
	int Width = rConsole.left = rConsole.right;
	int Height = rConsole.bottom - rConsole.top;

	//caculate the window console to center of the screen	
	int ConsolePosX;
	int ConsolePosY;
	ConsolePosX = ((rectScreen.right - rectScreen.left) / 2 - Width / 2);
	ConsolePosY = ((rectScreen.bottom - rectScreen.top) / 2 - Height / 2);
	SetWindowPos(ConsoleWindow, NULL, ConsolePosX, ConsolePosY, Width, Height, SWP_SHOWWINDOW || SWP_NOSIZE);

//start
	bool running = true;

	while (running)
	{
		srand(time(NULL));
		int rand_int = rand() % 5;
		player* Player = new player();
		enemies* Enemiesstart = new enemies();
		Map* map = new Map();
		bool creating = true;
		bool gaming = true;

		while (creating)
		{
			std::cout << "\t\t\t\t\t\tWELCOME TO MARVEL CIVIL WAR" << endl << endl << endl;
			std::cout<< "1. Load a saved game" << endl;
			std::cout<< "2. Start a new game" << endl;
			std::cout<< "3. Quit game" << endl;
			char choice = 0;
			choice = selection(choice);
			if (choice == '1')
			{
				load(Player);
				team.push_back(Player);
				if (menu == false)
				{
					creating = false;
				}
			}
			else if (choice == '2')
			{
				Player->set_registration("");
				Player->get_registration();
				std::cout<< "The Marvel Universe is being torn appart by the Super Hero Registration Act."
					<< endl << "Lines have been drawn and friends have become enemies." << endl
					<< "To win this game you must gain the trust of the people by earning a reputaion of 100."
					<< endl << "Be careful and make decisions wisely." << endl;
				Player->set_hero("");
				std::cout<< "Player 1 You have chosen: " << Player->get_hero() << endl;
				Player->set_level(1);
				Player->set_experience(0);
				Player->set_current_experience(Enemiesstart, 0);
				if (Player->get_hero() == "Spiderman")
				{
					Player->set_speed(Player->get_level() + 5);
					Player->set_strenght(3 + Player->get_level());
					Player->set_durability(2 + Player->get_level());
					Player->set_Cskill(4 + Player->get_level());
					Player->set_intelligence(3 + Player->get_level());
					Player->set_energy(3 + Player->get_level());
					Player->set_web_strength(+Player->get_energy());

				}
				else if (Player->get_hero() == "Iron Man")
				{
					Player->set_speed(Player->get_level() + 4);
					Player->set_strenght(5 + Player->get_level());
					Player->set_durability(5 + Player->get_level());
					Player->set_Cskill(2 + Player->get_level());
					Player->set_intelligence(5 + Player->get_level());
					Player->set_energy(5 + Player->get_level());
					Player->set_reduce();
					Player->get_reduce();

				}
				else if (Player->get_hero() == "Wolverine")
				{
					Player->set_speed(Player->get_level() + 3);
					Player->set_strenght(4 + Player->get_level());
					Player->set_durability(4 + Player->get_level());
					Player->set_Cskill(4 + Player->get_level());
					Player->set_intelligence(1 + Player->get_level());
					Player->set_energy(0 + Player->get_level());

				}
				else if (Player->get_hero() == "Captain America")
				{
					Player->set_speed(Player->get_level() + 3);
					Player->set_strenght(3 + Player->get_level());
					Player->set_durability(3 + Player->get_level());
					Player->set_Cskill(6 + Player->get_level());
					Player->set_intelligence(3 + Player->get_level());
					Player->set_energy(0 + Player->get_level());

				}
				else if (Player->get_hero() == "Mr. Fantastic")
				{
					Player->set_speed(Player->get_level() + 2);
					Player->set_strenght(3 + Player->get_level());
					Player->set_durability(6 + Player->get_level());
					Player->set_Cskill(2 + Player->get_level());
					Player->set_intelligence(5 + Player->get_level());
					Player->set_energy(0 + Player->get_level());
					Player->set_reduce();
					Player->get_reduce();
				}
				else if (Player->get_hero() == "Ms. Marvel")
				{
					Player->set_speed(Player->get_level() + 5);
					Player->set_strenght(4 + Player->get_level());
					Player->set_durability(4 + Player->get_level());
					Player->set_Cskill(4 + Player->get_level());
					Player->set_intelligence(2 + Player->get_level());
					Player->set_energy(4 + Player->get_level());

				}
				else if (Player->get_hero() == "Black Widow")
				{
					Player->set_speed(Player->get_level() + 2);
					Player->set_strenght(3 + Player->get_level());
					Player->set_durability(3 + Player->get_level());
					Player->set_Cskill(6 + Player->get_level());
					Player->set_intelligence(2 + Player->get_level());
					Player->set_energy(2 + Player->get_level());

				}
				else if (Player->get_hero() == "Black Panther")
				{
					Player->set_speed(Player->get_level() + 4);
					Player->set_strenght(4 + Player->get_level());
					Player->set_durability(3 + Player->get_level());
					Player->set_Cskill(6 + Player->get_level());
					Player->set_intelligence(4 + Player->get_level());
					Player->set_energy(0 + Player->get_level());

				}
				Player->set_health(Player->get_durability() * (15 + Player->get_level()) + 100);
				Player->max_hlth();
				if (Player->get_hero() == "Wolverine")
				{
					Player->set_regen();

				}
				Player->set_defense(Player->get_Cskill() + Player->get_speed() + Player->get_level() + rand_int + 6);
				Player->set_evade();

				Player->print_stat();
				team.push_back(Player);
				system("pause");
				system("CLS");
				creating = false;
			}
			else if (choice == '3')
			{
				return 0;
			}
			else
			{
				std::cout<< "Please select a valid choice" << endl;
			}




		}
		int px;
		int py;
		string pos;
		bool start = true;
		bool move;
		while (gaming)
		{
			while (start)
			{
				mission_run(0);
				px = map->get_playerx();
				py = map->get_playery();
				map->set_c_city(Player);
				map->get_city();
				city.push_back(map->get_city());

				std::cout<< "You start in " << map->get_city() << endl;
				system("pause");
				system("CLS");
				start = false;

			}
			if (map->get_city() == "Long Island")
			{

				if (pos == ">")
				{
					map->clear_map();
					delete map;
					city.pop_back();
					Map* map = new Map();
					px = 0;
					py = 2;
					map->set_player(px, py);
					pos = map->get_map_spot(px, py);
					map->set_city_travel("Long Island");
					map->get_city();
					city.push_back(map->get_city());
					std::cout<< "You are in " << map->get_city() << endl;

					map->generate_map();
					system("pause");
					system("cls");
				}
				else
				{

					std::cout<< map->get_city() << endl;


					map->generate_map();
					px = map->get_playerx();
					py = map->get_playery();
					pos = map->get_map_spot(px, py);
					map->set_city_travel("Long Island");
					map->get_city();
					system("pause");

					system("CLS");
				}


			}
			else if (map->get_city() == "Queens")
			{

				if (pos == ">")
				{
					map->clear_map();
					delete map;
					city.pop_back();
					Map* map = new Map();
					px = 0;
					py = 2;
					map->set_player(px, py);
					pos = map->get_map_spot(px, py);
					map->set_city_travel("Queens");
					map->get_city();
					city.push_back(map->get_city());
					std::cout<< "You are in " << map->get_city() << endl;

					map->generate_map();
					system("pause");
					system("cls");
				}
				else
				{
					std::cout<< map->get_city() << endl;


					map->generate_map();
					px = map->get_playerx();
					py = map->get_playery();
					pos = map->get_map_spot(px, py);
					map->set_city_travel("Queens");
					map->get_city();


					system("pause");

					system("CLS");
				}
			}
			else if (map->get_city() == "Brooklyn")
			{

				if (pos == ">")
				{
					map->clear_map();
					delete map;
					city.pop_back();
					Map* map = new Map();
					px = 0;
					py = 2;
					map->set_player(px, py);
					pos = map->get_map_spot(px, py);
					map->set_city_travel("Brooklyn");
					map->get_city();
					city.push_back(map->get_city());
					std::cout<< "You are in " << map->get_city() << endl;

					map->generate_map();
					system("pause");
					system("cls");
				}
				else
				{
					std::cout<< map->get_city() << endl;

					map->generate_map();
					px = map->get_playerx();
					py = map->get_playery();
					pos = map->get_map_spot(px, py);
					map->set_city_travel("Brooklyn");
					map->get_city();
					system("pause");

					system("CLS");
				}
			}
			else if (map->get_city() == "New York City")
			{

				if (pos == ">")
				{
					map->clear_map();
					delete map;
					city.pop_back();
					Map* map = new Map();
					px = 0;
					py = 2;
					map->set_player(px, py);
					pos = map->get_map_spot(px, py);
					map->set_city_travel("New York City");
					map->get_city();
					city.push_back(map->get_city());
					std::cout<< "You are in " << map->get_city() << endl;

					map->generate_map();
					system("pause");
					system("cls");
				}
				else
				{
					std::cout<< map->get_city() << endl;

					map->generate_map();
					px = map->get_playerx();
					py = map->get_playery();
					pos = map->get_map_spot(px, py);
					map->set_city_travel("New York City");
					map->get_city();
					system("pause");

					system("CLS");
				}


			}
			else if (map->get_city() == "Manhattan")
			{

				if (pos == ">")
				{
					map->clear_map();
					delete map;
					city.pop_back();
					Map* map = new Map();
					px = 0;
					py = 2;
					map->set_player(px, py);
					pos = map->get_map_spot(px, py);
					map->set_city_travel("Manhattan");
					map->get_city();
					city.push_back(map->get_city());
					std::cout<< "You are in " << map->get_city() << endl;

					map->generate_map();
					system("pause");
					system("cls");
				}
				else
				{
					std::cout<< map->get_city() << endl;

					map->generate_map();
					px = map->get_playerx();
					py = map->get_playery();
					pos = map->get_map_spot(px, py);
					map->set_city_travel("Manhattan");
					map->get_city();
					system("pause");

					system("CLS");
				}


			}
			else if (map->get_city() == "Wakanda")
			{

				if (pos == ">")
				{
					map->clear_map();
					delete map;
					city.pop_back();
					Map* map = new Map();
					px = 0;
					py = 2;
					map->set_player(px, py);
					pos = map->get_map_spot(px, py);
					map->set_city_travel("Wakanda");
					map->get_city();
					city.push_back(map->get_city());
					std::cout<< "You are in " << map->get_city() << endl;

					map->generate_map();
					system("pause");
					system("cls");
				}
				else
				{
					std::cout<< map->get_city() << endl;

					map->generate_map();
					px = map->get_playerx();
					py = map->get_playery();
					pos = map->get_map_spot(px, py);
					map->set_city_travel("Wakanda");
					map->get_city();
					system("pause");

					system("CLS");
				}


			}
			else if (map->get_city() == "End Mission")
			{
				map->clear_map();
				delete map;
				city.pop_back();
				rebuild = false;
				Map* map = new Map();
				px = 0;
				py = 2;
				pos = map->get_map_spot(px, py);
				map->set_city_travel("End Mission");
				map->get_city();
				city.push_back(map->get_city());
				std::cout<< "You are in " << map->get_city() << endl;

				map->generate_map();
				system("pause");
				system("cls");
			}


			if (px != 0 && pos != "|" && pos != ">")
			{
				if (options.size() > 0)
				{
					options.clear();
				}
				else
				{

					events1(Player, map);
					if (Player->get_health() <= 0)
					{
						gaming = false;
						move = false;
						std::cout << "1. Main Menu\n" << "2. Quit\n";
						char choice = 0;
						do
						{
							choice = selection(choice);
							if (choice == '1')
							{
								restart_cleanup();
								system("cls");
								team.pop_back();
								//map->clear_map();
								//delete map;
								Map* map = new Map();

								move = false;
								menu = false;
								start = false;
								gaming = false;
								//end = false;
							}
							else if (choice == '2')
							{
								return 0;
							}
						} while (choice != '1');

					}
					explosion = false;
					while (explosion_victim.size() != 0)
					{
						explosion_victim.pop_back();
					}
					player_stats_renew(Player);
					if (Player->get_hero() == "Spiderman")
					{
						while (Player->get_web_strength() > Player->get_energy())
						{
							Player->set_web_strength(-1);
						}
					}
					std::cout<< events.size() << " Size" << endl;
					if (events.size() > 0)
					{
						std::cout<< "rebuild here" << endl;
						rebuild = true;
						events.clear();
						mission_run(0);
						map->get_city() = "End Mission";
						//map->set_city("1");
						//map->get_city();
						move = false;
						pos = ">";

						/*while (pos != ">")
						{
						pos = ">";
						map->set_player(px, py);
						}*/

					}
					system("pause");
					system("cls");

				}
				if (mission_stats == false)
				{
					map->generate_map();
				}

			}
			if (px == 0 && Player->get_health() > 0)
			{
				system("cls");
				map->generate_map();
				std::cout<< "1. Contiune" << endl;


			}
			else if (pos != ">" && Player->get_health() > 0)
			{
				if (pos == "|")
				{
					map->generate_map();
				}
				std::cout<< "1. Continue" << endl;
				std::cout<< "2. Go Back" << endl;
				std::cout<< "3. Options" << endl;
				std::cout<< "4. Mission Log" << endl;

			}
			if (mission_stats == false)
			{
				move = true;
			}
			else
			{
				mission_stat(0);
			}

			while (move)
			{
				if (pos == ">")
				{
					std::cout<< "check 3" << endl;
					map->set_city("");
					map->get_city();
					move = false;
					rebuild = false;
					break;
				}
				char input = 0;
				input = selection(input);

				if (input == '1')
				{
					if (pos == "|" && px != 0)
					{
						std::cout<< "1. Up?" << endl;
						std::cout<< "2. Down?" << endl;
						input = selection(input);
						if (input == '1')
						{
							py--;
							move = false;
						}
						else
						{
							py++;
							move = false;
						}


						map->set_player(px, py);
						system("cls");


						move = false;

					}


					else
					{
						px++;
						map->set_player(px, py);
						system("cls");
						move = false;

					}
				}
				else if (input == '2' && px != 0)
				{
					px--;
					map->set_player(px, py);
					move = false;

				}
				else if (input == '3' && px != 0)
				{
					system("cls");
					options.push_back("options");
					std::cout<< "1. Hero Details" << endl;
					std::cout<< "2. Save" << endl;
					std::cout << "3. Quit" << endl;

					char input = 0;
					bool menu = true;
					while (menu)
					{
						input = selection(input);
						if (input == '1')
						{
							system("cls");
							Player->print_stat();
							system("pause");
							system("cls");
							move = false;
							menu = false;
						}
						else if (input == '2')
						{
							std::cout<< "saveing" << endl;
							save(Player, map);
							std::cout<< "Would you like to quit?" << endl;
							std::cout<< "1. Yes" << endl;
							std::cout<< "2. No" << endl;
							char choice = 0;
							bool end = true;

							while (end)
							{
								choice = selection(choice);
								if (choice == '1')
								{
									return 0;
									end = false;
								}
								else if (choice == '2')
								{
									std::cout<< "1. Continue" << endl;
									std::cout<< "2. Load new game/ start new game" << endl;
									char choice = 0;
									choice = selection(choice);
									if (choice == '1')
									{
										end = false;
										menu = false;
										move = false;
										loaded = true;
										system("cls");
										continue;

									}
									else if (choice == '2')
									{
										system("cls");
										team.pop_back();
										map->clear_map();
										delete map;
										Map* map = new Map();

										move = false;
										menu = false;
										start = false;
										gaming = false;
										end = false;
										//running = false;
										//main();

									}
									end = false;
								}
								else
								{
									std::cout<< "Please enter a vaild choice." << endl;
								}
							}
						}
						else if (input == '3')
						{
							return 0;
						}
						else
						{
							std::cout<< "Please enter a vaild choice" << endl;
						}
					}


				}
				else if (input == '4' && px != 0)
				{
					options.push_back("log");
					system("cls");
					if (missions.size() > 0)
					{
						while (missions.size() > 3)
						{
							swap(missions[0], missions[1]);
							swap(missions[1], missions[2]);
							swap(missions[2], missions[3]);
							std::cout<< missions.back() << " Mission is no longer avalible."
								<< endl << " You waited to long." << endl;
							missions.pop_back();
							system("pause");
							system("cls");
						}
						for (size_t i = 0; i < missions.size(); i++)
						{
							std::cout<< i << ". " << missions[i] << endl;
						}
						std::cout<< endl << endl;
						std::cout<< "Would you like to start a Mission?" << endl;
						std::cout<< "1. Yes" << endl << "2. No" << endl;
						char yorn = 0;
						bool starts = true;
						while (starts)
						{
							yorn = selection(yorn);
							if (yorn == '1')
							{
								num_people(Player);
								get_people();
								system("cls");
								std::cout<< "Which Mission would you like to start?" << endl;
								for (size_t i = 0; i < missions.size(); i++)
								{
									std::cout<< i << ". " << missions[i] << endl;
								}
								char log = 0;
								bool m_log = true;
								while (m_log)
								{
									log = selection(log);
									if (log == '0' && missions.size() > 0)
									{
										events_m.push_back(missions[0]);
										mission_stat(1);
										mission_run(1);


										events1(Player, map);
										explosion = false;
										while (explosion_victim.size() != 0)
										{
											explosion_victim.pop_back();
										}
										player_stats_renew(Player);
										if (missions.size() > 1)
										{
											swap(missions[0], missions[missions.size() - 1]);
										}
										missions.pop_back();
										events.clear();
										mission_run(0);
										rebuild = true;
										pos = ">";
										m_log = false;
										starts = false;

									}
									else if (log == '1' && missions.size() > 1)
									{

										events_m.push_back(missions[1]);
										mission_stat(1);
										events1(Player, map);
										explosion = false;
										while (explosion_victim.size() != 0)
										{
											explosion_victim.pop_back();
										}
										player_stats_renew(Player);
										if (missions.size() > 2)
										{
											swap(missions[1], missions[missions.size() - 1]);
										}
										missions.pop_back();
										events.clear();
										mission_run(0);
										rebuild = true;
										pos = ">";
										m_log = false;
										starts = false;
									}
									else if (log == '2' && missions.size() > 2)
									{

										events_m.push_back(missions[2]);
										missions.pop_back();
										mission_stat(1);
										events1(Player, map);
										explosion = false;
										while (explosion_victim.size() != 0)
										{
											explosion_victim.pop_back();
										}
										player_stats_renew(Player);
										events.clear();
										mission_run(0);
										rebuild = true;
										pos = ">";
										m_log = false;
										starts = false;
									}
									else
									{
										std::cout<< "Please select a valid choice." << endl;
									}

								}

							}
							else if (yorn == '2')
							{
								starts = false;
								move = false;
								continue;
							}
							else
							{
								std::cout<< "Please select a valid choice." << endl;
							}
						}

					}
					else
					{
						std::cout<< "No Missions avalible." << endl;
						move = false;
						system("pause");
						system("cls");
					}

				}

				else
				{
					std::cout<< "Please enter a vaild choice" << endl;
				}
			}// while move

			if (Player->get_reputation() >= 100)
			{
				std::cout<< "You have won!" << endl;
				Player->print_stat();
				gaming = false;
				if (gaming == false)
				{
					running = false;
				}
			}


		}//gasize_t if







	}
	_getch();

}


