#include "Maps.h"
#include "Hero.h"
#include <conio.h>

using namespace std;

Map::Map() //change this
{
	people = 0;
	p_pos[0] = 0;
	p_pos[1] = 2;
	string city = "";
	string c_city = "";
	mission = new Mission();

	int path_offset[] = { 2, 2, 2 };
	int num_cities = 0;
	int rand_int = 0;
	if (mission->get_event_size() > 0)
	{
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
void Map::generate_map()
{

	for (int y = 0; y < map_height; y++)
	{
		for (int x = 0; x < map_length; x++)
		{
			if ((p_pos[0] == x) && (p_pos[1] == y))
			{
				std::cout << "P";
			}
			else
			{
				if (mission->get_event_size() > 0)
				{
					std::cout << m_the_path[x][y];

				}
				else if (mission->get_rebuild() == false)
				{
					std::cout << the_path[x][y];

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
	if (mission->get_event_size() > 0)
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
		std::cout << "Returning to " << i << endl;
		city = i;
	}
	else
	{
		bool choice = true;

		while (choice)
		{
			std::cout << "Which city would you like to travel to?" << endl;
			std::cout << "1. Queens" << endl;
			std::cout << "2. Brooklyn" << endl;
			std::cout << "3. New York City" << endl;
			std::cout << "4. Long Island" << endl;
			std::cout << "5. Manhattan" << endl;
			std::cout << "6. Wakanda" << endl;
			char inputc = 0;
			inputc = _getch();
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

int Map::change_h()//change map height
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
int Map::change_l()//change the map length
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

void Map::num_people(player* h)
{
	people = rand() % 11;
	people += 5;
	std::cout << people << " people" << endl;
	system("pause");
}
void Map::set_people(int p)
{
	cout << people << " befor" << endl;
	people = p - 1;
	cout << people << " after" << endl;
	system("pause");
}
int Map::get_people()
{
	return people;
}

void Map::saved_people_push(string who)
{
	saved_people.push_back(who);
}

int Map::get_saved_people_size()
{
	return saved_people.size();
}

void Map::saved_people_clear()
{
	saved_people.clear();
}
