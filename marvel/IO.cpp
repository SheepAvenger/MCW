#include "IO.h"
#include <iostream>
#include <algorithm>
#include <string>
#include<vector>
#include<fstream>
#include <windows.h>
#include "Hero.h"
#include "Maps.h"
#include "Mission.h"
#include "enemies.h"
using namespace std;

IO::IO()
{
	loaded = false;
}

char IO::selection(char i)// user input with out pressing enter
{
	i = _getch();

	return i;
}

void IO::save(player* p, Map* m, Mission* mission, enemies* e)
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

	myfile.open(filename, ios::out | ios::binary);

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

	if (mission->get_mission_size() > 0)
	{
		missionfile.open(war + "\\" + file + "\\" + file + "_m.bin", ios::out | ios::binary);
		for (size_t i = 0; i < 3; i++)
		{
			if (i < mission->get_mission_size())
			{
				missionfile << mission->get_mission(i) << "\n";
			}
			else
			{
				break;
			}
		}
		missionfile.close();
	}
	if (e->die.size() > 0)
	{
		myfiledie.open(war + "\\" + file + "\\" + file + "_h.bin", ios::out | ios::binary);
		for (size_t i = 0; i < e->die.size(); i++)
		{
			myfiledie << e->die[i] << "\n";
		}
		myfiledie.close();
	}

	if (e->mission_vill.size() > 0)
	{
		myfiledie.open(war + "\\" + file + "\\" + file + "_mv.bin", ios::out | ios::binary);
		for (size_t i = 0; i < e->mission_vill.size(); i++)
		{
			myfiledie << e->mission_vill[i] << "\n";
		}
		myfiledie.close();
	}

	if (e->v_die.size() > 0)
	{
		ofstream myfilediev(war + "\\" + file + "\\" + file + "_v.bin", ios::out | ios::binary);
		if (myfilediev.is_open())
		{
			for (size_t i = 0; i < e->v_die.size(); i++)
			{
				myfilediev << e->v_die[i] << "\n";
			}
		}
		else
		{
			std::cout << "It failed" << filename + "_v.txt  would not open." << endl;
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
void IO::load(player* p, Mission* mission, enemies* e)
{
	//enemies* e = new enemies();
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
			mission->set_menu(true);
			system("cls");
		}
		else if (input == '0' || input <= i + '0')
		{

			i = input - '0';
			file = names[i];
			ifstream myfile(war + "\\" + file + "\\" + file + ".bin", ios::in | ios::binary);
			if (myfile.is_open())
			{
				mission->set_menu(false);
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
					p->set_pp_speed(p->get_speed() - p->get_level() - 5);
					p->set_pp_strength(p->get_strength() - p->get_level() - 3);
					p->set_pp_Cskill(p->get_Cskill() - p->get_level() - 4);
					p->set_pp_durability(p->get_durability() - p->get_level() - 2);
					p->set_pp_energy(p->get_energy() - p->get_level() - 3);
					p->set_pp_intelligence(p->get_intelligence() - p->get_level() - 3);

					p->set_web_strength(-p->get_web_strength());
					p->set_web_strength(+p->get_energy());
					p->set_registration("anti");
				}
				else if (p->get_hero() == "Iron Man")
				{
					p->set_pp_speed(p->get_speed() - p->get_level() - 4);
					p->set_pp_strength(p->get_strength() - p->get_level() - 5);
					p->set_pp_Cskill(p->get_Cskill() - p->get_level() - 2);
					p->set_pp_durability(p->get_durability() - p->get_level() - 5);
					p->set_pp_energy(p->get_energy() - p->get_level() - 5);
					p->set_pp_intelligence(p->get_intelligence() - p->get_level() - 5);

					p->set_reduce();
					p->set_registration("pro");
				}
				else if (p->get_hero() == "Wolverine")
				{
					p->set_pp_speed(p->get_speed() - p->get_level() - 3);
					p->set_pp_strength(p->get_strength() - p->get_level() - 4);
					p->set_pp_Cskill(p->get_Cskill() - p->get_level() - 4);
					p->set_pp_durability(p->get_durability() - p->get_level() - 4);
					p->set_pp_energy(p->get_energy() - p->get_level() - 0);
					p->set_pp_intelligence(p->get_intelligence() - p->get_level() - 1);

					p->set_registration("anti");
				}
				else if (p->get_hero() == "Captain America")
				{
					p->set_pp_speed(p->get_speed() - p->get_level() - 3);
					p->set_pp_strength(p->get_strength() - p->get_level() - 3);
					p->set_pp_Cskill(p->get_Cskill() - p->get_level() - 6);
					p->set_pp_durability(p->get_durability() - p->get_level() - 3);
					p->set_pp_energy(p->get_energy() - p->get_level() - 0);
					p->set_pp_intelligence(p->get_intelligence() - p->get_level() - 3);

					p->set_registration("anti");
				}
				else if (p->get_hero() == "Mr. Fantastic")
				{
					p->set_pp_speed(p->get_speed() - p->get_level() - 2);
					p->set_pp_strength(p->get_strength() - p->get_level() - 3);
					p->set_pp_Cskill(p->get_Cskill() - p->get_level() - 2);
					p->set_pp_durability(p->get_durability() - p->get_level() - 6);
					p->set_pp_energy(p->get_energy() - p->get_level() - 0);
					p->set_pp_intelligence(p->get_intelligence() - p->get_level() - 5);

					p->set_registration("pro");
					p->set_reduce();
					p->get_reduce();
				}
				else if (p->get_hero() == "Ms. Marvel")
				{
					p->set_pp_speed(p->get_speed() - p->get_level() - 5);
					p->set_pp_strength(p->get_strength() - p->get_level() - 4);
					p->set_pp_Cskill(p->get_Cskill() - p->get_level() - 4);
					p->set_pp_durability(p->get_durability() - p->get_level() - 4);
					p->set_pp_energy(p->get_energy() - p->get_level() - 4);
					p->set_pp_intelligence(p->get_intelligence() - p->get_level() - 2);

					p->set_registration("pro");
				}
				else if (p->get_hero() == "Black Widow")
				{
					p->set_pp_speed(p->get_speed() - p->get_level() - 2);
					p->set_pp_strength(p->get_strength() - p->get_level() - 3);
					p->set_pp_Cskill(p->get_Cskill() - p->get_level() - 6);
					p->set_pp_durability(p->get_durability() - p->get_level() - 3);
					p->set_pp_energy(p->get_energy() - p->get_level() - 2);
					p->set_pp_intelligence(p->get_intelligence() - p->get_level() - 2);

					p->set_registration("pro");
				}
				else if (p->get_hero() == "Black Panther")
				{
					p->set_pp_speed(p->get_speed() - p->get_level() - 4);
					p->set_pp_strength(p->get_strength() - p->get_level() - 4);
					p->set_pp_Cskill(p->get_Cskill() - p->get_level() - 6);
					p->set_pp_durability(p->get_durability() - p->get_level() - 3);
					p->set_pp_energy(p->get_energy() - p->get_level() - 0);
					p->set_pp_intelligence(p->get_intelligence() - p->get_level() - 4);

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
					e->die.push_back(dines);
				}
				myfiledie.close();
			}

			ifstream myfilediev(war + "\\" + file + "\\" + file + "_v.bin", ios::in | ios::binary);
			if (myfilediev.is_open())
			{
				while (!myfilediev.eof())
				{
					getline(myfilediev, dines);
					e->v_die.push_back(dines);
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
						mission->mission_push(dines);
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
						e->mission_vill.push_back(dines);
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

void IO::set_loaded(bool l)
{
	loaded = l;
}

bool IO::get_loaded()
{
	return loaded;
}

