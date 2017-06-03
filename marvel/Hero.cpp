#include <iostream>
#include <string>
#include <conio.h>
#include <time.h>
#include "Hero.h"
#include "enemi.h"
using namespace std;

player::player()
{
	attack = 0;
	bleed = 0;
	bleed_dmg = 0;
	Cexp = 0;
	defe = 0;
	rnd_defe = 0;
	dmg = 0;
	dur = 0;
	energy = 0;
	exp = 0;
	hlth = 0;
	intell = 0;
	lvl = 0;
	max = 0;
	regen = 0;
	reduce = 0;
	skill = 0;
	str = 0;
	spd = 0;
	rep = 0;
	web_str = 0;
	ko = false;
	reg = "";
	hero = "";
	power = "";
}
void player::set_registration(string h)
{
	if (h == "pro")
	{
		reg = "pro";
	}
	else if (h == "anti")
	{
		reg = "anti";
	}
	else
	{
		bool pick = true;
		cout << "During a televised raid of a house containing select villains that had recently"
			<< endl << "escaped from the super villain facility at Ryker's Island prison during a"
			<< endl << "massive breakout, the escaped villain Nitro let off a massive explosion that"
			<< endl << "killed the majority of the New Warriors, as well as the children at a nearby"
			<< endl << "elementary school. In the wake of the tragedy, the U.S. Government proposed"
			<< endl << "the Superhuman Registration Act, intending to register all super-powered"
			<< endl << "beings as living weapons of mass destruction and requiring all costumed heroes"
			<< endl << "to unmask themselves before the government and subject themselves to federally"
			<< endl << "mandated standards." << endl << endl << endl;

		while (pick)
		{
			int side;
			cout << "Are you Pro Registration or Anti Registration?" << endl;
			cout << "1. Pro Registraion" << endl;
			cout << "2. Anti Registration" << endl;
			side = _getch();
			if (side == 49)
			{
				std::system("cls");
				cout << "Pro Registration Super Heros Include:"
					<< endl << "Iron Man, Ms. Marvel, Mr. Fantastic, Black Widow" << endl;
				cout << "Would you like to be Pro Registration?" << endl;
				cout << "1. Yes" << endl;
				cout << "2. No" << endl;
				side = _getch();
				if (side == 49)
				{
					cout << "You have chosen Pro Registration" << endl;
					reg = "pro";
					pick = false;
					std::system("pause");
					std::system("cls");
				}
				else if (side == 50)
				{
					std::system("cls");
				}
				else
				{
					cout << "Please select a valid choice." << endl;
				}
			}
			else if (side == 50)
			{
				std::system("cls");
				cout << "Anti Registration Super Heros Include:"
					<< endl << "Spiderman, Wolverine, Black Panther, Captain America" << endl;
				cout << "Would you like to be Anti Registration?" << endl;
				cout << "1. Yes" << endl;
				cout << "2. No" << endl;
				side = _getch();
				if (side == 49)
				{
					cout << "You have chosen Anti Registration" << endl;
					reg = "anti";
					pick = false;
					std::system("pause");
					std::system("cls");
				}
				else if (side == 50)
				{
					std::system("cls");
				}
				else
				{
					cout << "Please select a valid choice." << endl;
				}
			}
			else
			{
				cout << "Please select a valid choice." << endl;
			}
		}

	}
}
string player::get_registration()
{
	return reg;
}
void player::set_hero(string h)
{
	bool pick = true;
	if (h == "Spiderman")
	{
		h = "Spiderman";
		hero = h;
	}
	else if (h == "Iron Man")
	{
		h = "Iron Man";
		hero = h;
	}
	else if (h == "Wolverine")
	{
		h = "Wolverine";
		hero = h;
	}
	else if (h == "Captain America")
	{
		h = "Captain America";
		hero = h;
	}
	else if (h == "Ms. Marvel")
	{
		h = "Ms. Marvel";
		hero = h;
	}
	else if (h == "Mr. Fantastic")
	{
		h = "Mr. Fantastic";
		hero = h;
	}
	else if (h == "Black Widow")
	{
		h = "Black Widow";
		hero = h;
	}
	else if (h == "Black Panther")
	{
		h = "Black Panther";
		hero = h;
	}
	else
	{
		while (pick)
		{
			if (reg == "pro")
			{
				cout << "Who would you like to be?" << endl;
				cout << "1. Iron Man" << endl;
				cout << "2. Ms. Marvel" << endl;
				cout << "3. Mr. Fantastic" << endl;
				cout << "4. Black Widow" << endl;

			}
			else
			{
				cout << "Who would you like to be?" << endl;
				cout << "1. Spiderman" << endl;
				cout << "2. Wolverine" << endl;
				cout << "3. Black Panther" << endl;
				cout << "4. Captain America" << endl;

			}
			h = _getch();
			if (h == "1" && reg == "anti")
			{
				std::system("cls");
				cout << "Spiderman has spidy sense which helps him evade most attacks " << endl << "and is faster then other characters." << endl;
				cout << "Strength: 4" << endl << "Speed: 6" << endl << "Durability: 3" << endl << "Combat Skill: 5" << endl
					<< "Intelligence: 4" << endl << "Energy Projection: 4" << endl;
				cout << "Do you want to be Spiderman?" << endl << "1. YES" << endl << "2. No" << endl;
				h = _getch();
				if (h == "1")
				{
					h = "Spiderman";
					hero = h;
					pick = false;
					std::system("cls");
				}
				else
				{
					std::system("cls");
					continue;
				}
				
			}
			else if (h == "1" && reg == "pro")
			{
				std::system("cls");
				cout << "Iron Man's armour provides him with damage reduction." << endl 
					<< " His Combat Skill is lower then most but his powers hit hard." << endl;
				cout << "Strength: 6" << endl << "Speed: 5" << endl << "Durability: 6" << endl << "Combat Skill: 3" << endl
					<<"Intelligence: 6" << endl << "Energy Projection: 6" << endl << "Damage Reduction: 3" <<endl;
				cout << "Do you want to be Iron Man?" << endl << "1. YES" << endl << "2. No" << endl;
				h = _getch();
				if (h == "1")
				{
					h = "Iron Man";
					hero = h;
					pick = false;
					std::system("cls");
				}
				else
				{
					std::system("cls");
					continue;
				}
				
			}
			else if (h == "2" && reg == "anti")
			{
				std::system("cls");
				cout << "Wolverine has a healing factor that allows him to regenerate health." << endl
					<< " His attacks cause the enemy to bleed due to his claws." << endl;
				cout << "Strength: 5" << endl << "Speed: 4" << endl << "Durability: 5" << endl << "Combat Skill: 5" << endl
					<< "Intelligence: 2" << endl << "Energy Projection: 1" << endl << "Health Regeneration: 3" << endl;
				cout << "Do you want to be Wolverine?" << endl << "1. YES" << endl << "2. No" << endl;
				h = _getch();
				if (h == "1")
				{
					h = "Wolverine";
					hero = h;
					pick = false;
					std::system("cls");
				}
				else
				{
					std::system("cls");
					continue;
				}
			
			}
			else if (h == "2" && reg == "pro")
			{
				std::system("cls");
				cout << "Ms. Marvel is stronger and faster than most heros." << endl
					<< " She is able to shoot concussive energy burst from her hands." << endl;
				cout << "Strength: 5" << endl << "Speed: 6" << endl << "Durability: 5" << endl << "Combat Skill: 5" << endl
					<< "Intelligence: 3" << endl << "Energy Projection: 5" << endl;
				cout << "Do you want to be Ms. Marvel?" << endl << "1. YES" << endl << "2. No" << endl;
				h = _getch();
				if (h == "1")
				{
					h = "Ms. Marvel";
					hero = h;
					pick = false;
					std::system("cls");
				}
				else
				{
					std::system("cls");
					continue;
				}

			}
			else if (h == "3" && reg == "anti")
			{
				std::system("cls");
				cout << "Black Panther has enhanced sense that allow him to evade attacks easier." << endl
					<< "He also can reflect back some damage to attackers." << endl;
				cout << "Strength: 5" << endl << "Speed: 5" << endl << "Durability: 4" << endl << "Combat Skill: 7" << endl
					<< "Intelligence: 5" << endl << "Energy Projection: 1" << endl;
				cout << "Do you want to be Black Panther?" << endl << "1. YES" << endl << "2. No" << endl;
				h = _getch();
				if (h == "1")
				{
					h = "Black Panther";
					hero = h;
					pick = false;
					std::system("cls");
				}
				else
				{
					std::system("cls");
					continue;
				}

			}
			else if (h == "3" && reg == "pro")
			{
				std::system("cls");
				cout << "Mr. Fantastic is immune to all bleed damage ." << endl
					<< "He also receives a small damage reduction due to his malleable skin." << endl;
				cout << "Strength: 4" << endl << "Speed: 3" << endl << "Durability: 7" << endl << "Combat Skill: 3" << endl
					<< "Intelligence: 6" << endl << "Energy Projection: 1" << endl << "Damage Reduction: 1" << endl;
				cout << "Do you want to be Mr. Fantastic?" << endl << "1. YES" << endl << "2. No" << endl;
				h = _getch();
				if (h == "1")
				{
					h = "Mr. Fantastic";
					hero = h;
					pick = false;
					std::system("cls");
				}
				else
				{
					std::system("cls");
					continue;
				}

			}
			else if (h == "4" && reg == "anti")
			{
				std::system("cls");
				cout << "Captain America's shield will reflect damage to attackers when he blocks." << endl
					<< " His Combat Skill is the highest due to his military training." << endl;
				cout << "Strength: 4" << endl << "Speed: 4" << endl << "Durability: 4" << endl << "Combat Skill: 7" << endl
					<< "Intelligence: 4" << endl << "Energy Projection: 1" << endl;
				cout << "Do you want to be Captain America?" << endl << "1. YES" << endl << "2. No" << endl;
				h = _getch();
				if (h == "1")
				{
					h = "Captain America";
					hero = h;
					pick = false;
					std::system("cls");
				}
				else
				{
					std::system("cls");
					continue;
				}
	
			}
			else if (h == "4" && reg == "pro")
			{
				std::system("cls");
				cout << "Black Widow is an expert at hand to hand combat." << endl
					<< "Her skills give her a high chance for criticals and crippling blows ." << endl;
				cout << "Strength: 4" << endl << "Speed: 3" << endl << "Durability: 4" << endl << "Combat Skill: 7" << endl
					<< "Intelligence: 3" << endl << "Energy Projection: 3" << endl;
				cout << "Do you want to be Black Widow?" << endl << "1. YES" << endl << "2. No" << endl;
				h = _getch();
				if (h == "1")
				{
					h = "Black Widow";
					hero = h;
					pick = false;
					std::system("cls");
				}
				else
				{
					std::system("cls");
					continue;
				}

			}
			else
			{
				cout << "Please Select a valid choice." << endl;

			}
		}
	}
}

string player::get_hero()
{
	return hero;
}
void player::set_strenght(int s)
{
		str += s;
		if (str < 0)
		{
			str = 0;
		}
}
int player::get_strength()
{
	return str;
}
void player::set_energy(int i)
{
	energy += i;
	if (energy < 0)
	{
		energy = 0;
	}
}
int player::get_energy()
{
	return energy;
}
void player::set_intelligence(int i)
{
	intell += i;
	if (intell < 0)
	{
		intell = 0;
	}
}
int player::get_intelligence()
{
	return intell;
}
void player::set_speed(int i)
{
	spd += i;
	if (spd < 0)
	{
		spd = 0;
	}
}
int player::get_speed()
{
	return spd;
}
void player::set_durability(int s)
{
	dur += s;
	if (dur < 0)
	{
		dur = 0;
	}
}
int player::get_durability()
{
	return dur;
}
void player::set_Cskill(int s)
{
	skill += s;
	if (skill < 0)
	{
		skill = 0;
	}
}
int player::get_Cskill()
{
	return skill;
}
void player::set_health(int i)
{
	hlth += i;
	if (hlth < 0)
	{
		hlth = 0;
	}
	
}
int player::get_health()
{
	return hlth;
}

void player::max_hlth()
{
	max = dur * (15 + lvl) + 100;
}
int player::get_max()
{
	return max;
}
void player::set_regen()
{
	regen = (hlth * 0.02);
}
int player::get_regen()
{
	return regen;
}
void player::set_experience(int s)
{
	exp = ((lvl * (25 + lvl) + exp)) + s;
}

int player::get_experience()
{
	return exp;
}
void player::set_current_experience(enemies* h, int s)
{
	
		Cexp += s + h->get_experience();

}
int player::get_current_experience()
{
	return Cexp;
}
void player::set_level(int s)
{

	if (Cexp >= exp)
	{
		lvl += s;
	}

	else
	{
		lvl += s;
	}


}
int player::get_level()
{
	return lvl;
}
void player::set_defense(int i)
{
	defe < 0 ? defe = 0 : defe += i;//use to be defe <= 0
	
}
int player::get_defense()
{
	ko ? rnd_defe = 0 :	rnd_defe = rand() % defe;
	std::cout << "defense: " << rnd_defe << endl;

	return rnd_defe;
}
void player::reset_defense()
{
	defe = 0;
}

void player::set_attack(enemies* h, player* p)
{
	
	char a;
	bool input;
	do
	{
		input = false;
		cout << "1. Punch!" << endl;
		cout << "2. Kick!" << endl;
		cout << "3. Powers!" << endl;
		a = _getch();
		if (a == '1' && hero == "Spiderman")
		{
			attack = a;
			cout << "Spiderman lunges forward with all this might! BAM! He delieves a mighty punch!" << endl;
			dmg = str + lvl;
			power = "p";
		}
		else if (a == '2' && hero == "Spiderman")
		{
			cout << "Spiderman Dashes forward! Jump left and right with great speed! He jumps and deals a powerful Kick!" << endl;
			dmg = spd + lvl;
			power = "p";

		}
		else if (a == '1' && hero == "Iron Man")
		{
			attack = a;
			cout << "Iron Man flys forward! BAM! He delieves a mighty punch!" << endl;
			power = "p";
			dmg = str + lvl;
		}
		else if (a == '2' && hero == "Iron Man")
		{
			cout << "Iron Man rocket forward! He flips feet first and deals a powerful double Kick!" << endl;
			power = "p";
			dmg = spd + lvl;
		}
		else if (a == '1' && hero == "Wolverine")
		{
			cout << "Wolverine drives his fist forward and deals a mighty punch, with a loud CLANK!" << endl;
			power = "p";
			dmg = str + lvl;
		}
		else if (a == '2' && hero == "Wolverine")
		{
			cout << "Wolverine runs forward and delivers a powerful  Kick!" << endl;
			power = "p";
			dmg = spd + lvl;
		}
		else if (a == '1' && hero == "Captain America")
		{
			cout << "Captain America dealivers a mighty right hook!" << endl;
			power = "p";
			dmg = str + lvl;
		}
		else if (a == '2' && hero == "Captain America")
		{
			cout << "Captain America quickly crouches down and delivers sweeping Kick!" << endl;
			power = "p";
			dmg = spd + lvl;
		}
		else if (a == '1' && hero == "Mr. Fantastic")
		{
			cout << "Mr. Fantastic slings his arm out to deliver a strong punch!" << endl;
			power = "p";
			dmg = str + lvl;
		}
		else if (a == '2' && hero == "Mr. Fantastic")
		{
			cout << "Mr. Fantastic stretches his leg out and whips it around!" << endl;
			power = "p";
			dmg = spd + lvl;
		}
		else if (a == '1' && hero == "Ms. Marvel")
		{
			cout << "Ms. Marvel dealivers a devistating punch!" << endl;
			power = "p";
			dmg = str + lvl;
		}
		else if (a == '2' && hero == "Ms. Marvel")
		{
			cout << "Ms. Marvel Swoops down and kicks with all her might!" << endl;
			power = "p";
			dmg = spd + lvl;
		}
		else if (a == '1' && hero == "Black Widow")
		{
			cout << "Black Widow dealivers a stratigic kidney punch!" << endl;
			power = "p";
			if (spd >= (h->get_speed() - h->get_level()) + lvl)
			{
				dmg = 0;
				for (int i = 0; i < (spd - (h->get_speed() - h->get_level())); i++)
				{
					cout << "Black Widow punches again!" << endl;
					dmg += str;

				}
				if (skill >= h->get_Cskill())
				{
					cout << "Critical Hit!" << endl;

					dmg = dmg * 2;
				}
			}
			else if (skill >= h->get_Cskill())
			{
				cout << "Black Widow uses her tactical advantage to increase her damage!" << endl;

				dmg = (str + lvl) * 2;
			}
			else
			{
				dmg = str + lvl;
			}
		}
		else if (a == '2' && hero == "Black Widow")
		{
			cout << "Black Widow delivers a crippling blow to the her enemies knee!" << endl;
			power = "p";
			if (spd >= (h->get_speed() - h->get_level()) + lvl)
			{
				dmg = spd + lvl;
				for (int i = 0; i < (spd - (h->get_speed() - h->get_level())); i++)
				{
					cout << "Black Widow Kicks again!" << endl;

					dmg += spd;

				}
				if (skill >= h->get_Cskill())
				{
					cout << "Critical Hit!" << endl;
					dmg = dmg * 2;
				}
			}
			else if (skill >= h->get_Cskill())
			{
				cout << "Black Widow uses her tactical advantage to increase her damage!" << endl;
				dmg = (spd + lvl) * 2;
			}
			else
			{
				dmg = spd + lvl;
			}
		}
		else if (a == '1' && hero == "Black Panther")
		{
			cout << "Black Panther ducks and throws a might punch!" << endl;
			power = "p";
			dmg = str + lvl;
		}
		else if (a == '2' && hero == "Black Panther")
		{
			cout << "Black Panther crouches down and strikes with a swift kick!" << endl;
			power = "p";
			dmg = spd + lvl;
		}
		else if (a == '3' && hero == "Spiderman")
		{
			bool description = true;
			std::system("cls");
			while (description)
			{
				cout << "1. Chose a power?" << endl;
				cout << "2. Power description?" << endl;
				int d;
				d = _getch();
				if (d == '1')
				{
					std::system("cls");
					cout << "1. Web Balls" << endl;
					cout << "2. Web String" << endl;
					cout << "3. Sling Shot" << endl;
					if (lvl >= 5)
					{
						cout << "4. Web Mace" << endl;
					}
					if (lvl >= 10)
					{
						cout << "5. Web Yank" << endl;
					}
					if (lvl >= 15)
					{
						cout << "6. Web Throw" << endl;
					}
					if (lvl >= 20)
					{
						cout << "7. Web Dive" << endl;
					}
					description = false;
				}
				else if (d == '2')
				{
					std::system("cls");
					cout << "1. Web Balls: can possibly shoot one ball or many." << endl
						<< " Also will lower an enemie's speed due to the sticky web." << endl << endl;
					cout << "2. Web String: shoots out a long strand of web that deals no damage."
						<< endl << " This attack greatly reduces an enemie's speed." << endl << endl;
					cout << "3. Sling Shot: Strong attacked based on your current strength "
						<< endl << "and speed also has a high chance for a critical hit." << endl << endl;
					if (lvl >= 5)
					{
						cout << "4. Web Mace: An attack that will hit each enemy one time." << endl << endl;
					}
					if (lvl >= 10)
					{
						cout << "5. Web Yank: High chance for single hit agains one enemy." << endl << endl;
					}
					if (lvl >= 15)
					{
						cout << "6. Web Throw: An attack that deals massive damage as well as "
							<< endl << "lowers an enemie's defense for a short time." << endl << endl;
					}
					if (lvl >= 20)
					{
						cout << "7. Web Dive: An attack that hits all enemies and lowers their speed." << endl << endl;
					}
					std::system("pause");
					std::system("cls");
				}
				else
				{
					cout << "Please select a valid choice" << endl;
				}
			}

			if (hero == "Spiderman")
			{
				int a;
				a = _getch();
				if (a == '1' && hero == "Spiderman")
				{
					srand(time(NULL));
					cout << "Spiderman quickly does a double back flip, landing in a crouched position!" << endl;
					cout << "His hands quickly spurt back and forth as he delivers a" << endl << " sticky barrage of Web Balls!" << endl;
					int rand_int = rand() % 5;
					int rand_str;
					if (energy > 0)
					{
						rand_str = rand() % energy;
					}
					else
					{
						rand_str = 1;
					}
					dmg = (rand_int + lvl + skill) * 2;
					power = "p";
					if (h->get_strength() < (web_str + rand_str))
					{
						web_str += 1;
						if (h->get_speed() > 0)
						{
							h->set_speed(-2);
						}
						cout << endl << h->get_enemies() << " speed decreases to " << h->get_speed() << endl;

					}
					else
					{
						if (web_str > lvl)
						{
							cout << h->get_enemies() << " easily breaks the webbing! " << endl;

							h->set_speed(+2);
							web_str += -1;
						}
					}

					if (rand_int >= 3)
					{
						for (int i = rand() % 5; i < lvl; i++)
						{
							if (i >= lvl)
							{

								break;

							}
							else
							{
								cout << "Spiderman continues to shoot!" << endl;
								std::system("pause");
								std::system("cls");
								int rand_int = rand() % 5;
								dmg = dmg + ((rand_int + skill));
								{
									if (dmg == 0)
									{
										dmg = dmg + (rand_int + skill) * 2;
									}
								}
								power = "p";

							}

						}
					}


				}
				else if (a == '2' && hero == "Spiderman")
				{
					srand(time(NULL));
					cout << "Spiderman jumps back and throws both is hands forward, a long continues sting of" << endl << " Web shoots out!" << endl;
					int rand_int;
					int rand_spd = rand() % spd;

					if (lvl <= 3)
					{
						rand_int = rand() % 3;

					}
					else if (lvl >= 4)
					{
						rand_int = rand() % lvl;
					}
					dmg = 0;
					power = "p";
					if (h->get_strength() < (web_str + rand_spd))
					{
						cout << h->get_enemies() << " is being slowed down by webbing!" << endl;
						web_str += 1;
						if (h->get_speed() > 0)
						{
							h->set_speed(-rand_int);
						}
						cout << endl << h->get_enemies() << " speed decreases to " << h->get_speed() << endl;

					}
					else
					{
						cout << h->get_enemies() << " easily breaks the webbing! " << endl;
						if (web_str > lvl)
						{
							h->set_speed(+rand_int);
							web_str += -1;
						}

					}


				}
				else if (a == '3' && hero == "Spiderman")
				{
					cout << "Spiderman shoots webs onto the buildings near by!" << endl
						<< "He pulls back and flys forward like a Sling Shot!" << endl;
					srand(time(NULL));
					int rand_int = rand() % 10;
					power = "p";
					if (rand_int >= 8)
					{
						cout << "CRITICAL HIT!" << endl;
						dmg = (str + spd + rand_int + skill + lvl) * 2;

					}
					else
						dmg = str + spd + rand_int + skill + lvl;



				}
				else if (a == '4' && hero == "Spiderman" && lvl >= 5)
				{
					cout << "Spiderman grabs a rock with his web." << endl
						<< " He spins around hitting all enemies with his Web Mace!" << endl;
					srand(time(NULL));
					int rand_int = rand() % 10;
					power = "Web Mace";
					dmg = str + spd + skill + rand_int + lvl;
				}
				else if (a == '5' && hero == "Spiderman" && lvl >= 10)
				{
					cout << "Spiderman shoots out a string of web and grabs " << h->get_enemies() << "!" << endl
						<< "He pulls yanks him forward and delivers a massive blow!" << endl;
					power = "p";
					int rand_ints = rand() % 10;
					if (rand_ints >= 7)
					{
						srand(time(NULL));
						int rand_int = rand() % 5;
						cout << "CRITICAL HIT!" << endl;
						dmg = (str + lvl + spd) * rand_int;

					}
					else
					{
						srand(time(NULL));
						int rand_int = rand() % 3;
						if (rand_int == 0)
						{
							rand_int = 1;
						}
						dmg = (str + lvl + spd) * rand_int;

					}


				}
				else if (a == '6' && hero == "Spiderman" && lvl >= 15)
				{
					cout << "Spiderman shoots out and web and grabs " << h->get_enemies() << "," << endl
						<< "and he throws him with all his might!" << endl;
					power = "p";
					srand(time(NULL));
					int distance = rand() % 100 + 1;
					if (distance <= 20)
					{
						cout << h->get_enemies() << " is to far way to attack!" << endl;

						h->set_defense_mod(1);

					}


					srand(time(NULL));
					int rand_int = rand() % 5;
					dmg = (str + skill + spd) * (rand_int + 1);

				}
				else if (a == '7' && hero == "Spiderman" && lvl >= 20)
				{
					cout << "Spiderman leaps into the air and shoots webs on the ground below him," << endl
						<< " he then pull the webs tight and speeds back to the ground!" << endl
						<< "BOOM! Dirt and web fly every where!" << endl;
					power = "Web Dive";
					srand(time(NULL));
					int rand_int = rand() % 5;
					dmg = (str + spd + skill + lvl) * (rand_int + 3);



				}
				else
				{
					cout << "Please select a valid choice." << endl;
				}



			}


		}
		else if (a == '3' && hero == "Iron Man")
		{
			bool description = true;
			std::system("cls");
			while (description)
			{
				cout << "1. Chose a power?" << endl;
				cout << "2. Power description?" << endl;
				int d;
				d = _getch();
				if (d == '1')
				{
					std::system("cls");
					cout << "1. Repulsor Rays" << endl;
					cout << "2. UniBeam" << endl;
					cout << "3. Missile Barrage" << endl;
					if (lvl >= 5)
					{
						cout << "4. Rocket Uppercut" << endl;
					}
					if (lvl >= 10)
					{
						cout << "5. Radial Pulse" << endl;
					}
					if (lvl >= 15)
					{
						cout << "6. Nano Assault" << endl;
					}
					if (lvl >= 20)
					{
						cout << "7. Tank Missile" << endl;
					}

					description = false;
				}
				else if (d == '2')
				{
					std::system("cls");
					cout << "1. Repulsor Rays: Can shoot one ray or multiple." << endl << endl;
					cout << "2. UniBeam: Strong attack that can deal a lot of damage." << endl << endl;
					cout << "3. Missile Barrage: Launches missiles at each enemy. Deals moderate damage." << endl
						<< "Also reduces all enemie's defense for a short time." << endl << endl;
					if (lvl >= 5)
					{
						cout << "4. Rocket Uppercut: Has a chance to deal extra damage if Iron Man is faster "
							<< endl << "then his enemy." << endl << endl;
					}
					if (lvl >= 10)
					{
						cout << "5. Radial Pulse: An attack that hits all enemies one time." << endl;
					}
					if (lvl >= 15)
					{
						cout << "6. Nano Assault: Tiny Robots attach to an enemy."
							<< endl << " If successful the enemy will attack each of his partners once."
							<< endl << " This attack does not always work against single enemies." << endl << endl;
					}
					if (lvl >= 20)
					{
						cout << "7. Tank Missile: Has a high chance for massive damage to all enemies."
							<< endl << "Also has a chance to do low damage to all enemies." << endl << endl;
					}

					std::system("pause");
					std::system("cls");
				}
				else
				{
					cout << "Please select a valid choice" << endl;
				}
			}

			if (hero == "Iron Man")
			{
				int a;
				a = _getch();

				if (a == '1' && hero == "Iron Man")
				{
					srand(time(NULL));
					cout << "Iron Man's hands light up as he delivers a multiple Repulsor Rays!" << endl;
					power = "p";

					int rand_int = rand() % lvl;
					if (lvl >= 10)
					{
						rand_int = 10;
					}
					dmg = 0;
					if (rand_int == 0)
					{
						rand_int = 1;
					}
					for (int i = 0; i < rand_int; i++)
					{

						if (rand_int == 1)
						{
							dmg = (energy + skill);

						}
						else
						{
							cout << "Iron Man Continues to shoot!" << endl;
							dmg = dmg + (energy);


						}



					}
					if (rand_int > lvl - 2)
					{
						\
							dmg = dmg * 2;

					}
					else
					{
						dmg = dmg;

					}

				}
				else if (a == '2' && hero == "Iron Man")
				{
					dmg = 0;

					srand(time(NULL));

					cout << "Iron Man throws his arms back and unleases a power UniBeam from his core!" << endl;
					power = "p";
					int rand_int = rand() % energy;
					if (rand_int >= 7)
					{
						dmg = (energy + lvl + skill) * (rand_int);
					}
					else
					{
						dmg = (energy + lvl + skill) * 2;

					}

				}
				else if (a == '3' && hero == "Iron Man")
				{
					dmg = 0;
					srand(time(NULL));
					cout << "Tiny rocket launchers open up on Iron Man's shoulder!" << endl
						<< "He unleases a Missile Barrage, at all enemies!" << endl;
					power = "Missile Barrage";
					int rand_int = rand() % 5;
					int rand_ints = rand() % 5;
					if (rand_int == 0)
					{
						rand_int = 1;
					}

					if (h->get_defense() == 0)
					{
						h->set_defense(h->get_Cskill() + h->get_level() + h->get_speed() + rand_ints);
					}
					h->set_defense(-rand_int);
					if (h->get_defense() <= p->get_defense())
					{
						h->set_defense_mod(1);
						cout << h->get_enemies() << "'s defense have droped due to the explosion " << endl;
					}
					dmg = rand_int + lvl + skill + 1;

				}
				else if (a == '4' && hero == "Iron Man" && lvl >= 5)
				{
					dmg = 0;
					cout << "Iron Man flys forward and then boots upwards dealing a massive Rocket Uppercut!" << endl;
					power = "Rocket Uppercut";
					power = "p";
					if (p->get_speed() >= h->get_speed())
					{
						int modify = p->get_speed() - h->get_speed();
						if (modify <= 1)
						{
							modify = 3;
						}
						cout << "Iron Man circles around and delivers another devisating blow!" << endl;
						dmg = (str + lvl + spd) *modify;
						cout << " Dealing another " << dmg / modify << " damage!" << endl;
					}
					else
						dmg = (str + lvl + spd) * 2;
				}
				else if (a == '5' && hero == "Iron Man" && lvl >= 10)
				{
					dmg = 0;
					cout << "Iron Man charges up and unleases a burst of energy!" << endl;
					power = "Radial Pulse";
					srand(time(NULL));
					int rand_int = rand() % energy;
					dmg = energy * (rand_int + 1);
				}
				else if (a == '6' && hero == "Iron Man" && lvl >= 15)
				{
					cout << "Iron Man unleases a swarm of nano bots to try and control the enemie!" << endl;
					power = "Nano Assault";
					dmg = 0;
				}
				else if (a == '7' && hero == "Iron Man" && lvl >= 20)
				{
					dmg = 0;
					cout << "A tiny slot opens up on Iron Man's wrist." << endl
						<< "He says 'Tank Missile'." << endl;
					power = "Tank Missile";
					srand(time(NULL));
					int rand_int = rand() % (10 * energy);
					dmg = rand_int + 1;
					if (dmg <= 50)
					{
						dmg = 10 * energy;


					}
				}
				else
				{
					cout << "Please select a valid choice." << endl;
				}





			}
		}
		else if (a == '3' && hero == "Wolverine")
		{
			bool description = true;
			std::system("cls");
			while (description)
			{
				cout << "1. Chose a power?" << endl;
				cout << "2. Power description?" << endl;
				int d;
				d = _getch();
				if (d == '1')
				{
					std::system("cls");
					cout << "1. Claw Slash" << endl;
					cout << "2. Lethal Lunge" << endl;
					cout << "3. Dashing Flurry" << endl;
					if (lvl >= 5)
					{
						cout << "4. Eviscerate" << endl;
					}
					if (lvl >= 10)
					{
						cout << "5. Claw Frenzy" << endl;
					}
					if (lvl >= 15)
					{
						cout << "6. Claw Kebab" << endl;
					}
					if (lvl >= 20)
					{
						cout << "7. Certain Death" << endl;
					}


					description = false;
				}
				else if (d == '2')
				{
					std::system("cls");
					cout << "1. Claw Slash: A deadly single claw attack with low bleed damage" << endl << endl;
					cout << "2. Lethal Lunge: Multi slash attack with high bleed damage." << endl << endl;
					cout << "3. Dashing Flurry: Multi slash attack that deals high damage." << endl;

					if (lvl >= 5)
					{
						cout << "4. Eviscerate: Strong attack with high damage "
							<< endl << "and high chance to high bleed damage" << endl << endl;
					}
					if (lvl >= 10)
					{
						cout << "5. Claw Frenzy: Multi slash attack that builds up Wolverine's rage." << endl << endl;
					}
					if (lvl >= 15)
					{
						cout << "6. Claw Kebab: Very high chance for high damage with massive bleeding." << endl << endl;
					}
					if (lvl >= 20)
					{
						cout << "7. Certain Death: Has a chance to cause instant death to any enemy." << endl << endl;
					}


					std::system("pause");
					std::system("cls");
				}
				else
				{
					cout << "Please select a valid choice" << endl;
				}
			}
			int a;
			a = _getch();
			if (a == '1' && hero == "Wolverine")
			{
				srand(time(NULL));
				cout << "Wolverine throws his claws out and slashes twice!" << endl;
				power = "Bleed";
				int rand_int = rand() % 4;
				dmg = (rand_int + str) * 2;
				bleed = dmg * .10;

			}
			else if (a == '2' && hero == "Wolverine")
			{
				srand(time(NULL));
				cout << "Wolverine Launches forward knocking back his enemy" << endl
					<< "Wolverine lands and brutally slashing his target!" << endl;
				power = "Bleed";
				if (h->get_strength() <= p->get_strength())
				{
					cout << "Wolverine keeps " << h->get_enemies() << " pinned down!" << endl;
					h->set_defense_mod(1);
				}
				int rand_int = rand() % 2;
				dmg = (str + spd) * (rand_int + 1);
				bleed = dmg * .30;

			}
			else if (a == '3' && hero == "Wolverine")
			{
				srand(time(NULL));
				cout << "Wolverine dashes forward and unleases a flurry of deadly slashes!" << endl;
				power = "Bleed";
				int rand_int = rand() % 4;
				dmg = (str + 5) * (rand_int + 1);
				bleed = dmg * .10;

			}
			else if (a == '4' && hero == "Wolverine" && lvl >= 5)
			{
				srand(time(NULL));
				cout << "Wolverine stabbs his claws into his enemy," <<
					endl << " and pulls the his arms sideways!" << endl;
				power = "Bleed";
				int rand_int = rand() % 6;
				dmg = (str + (rand_int + 1)) * 3;
				bleed = dmg * .20;
				if (bleed >= (h->get_health() / 5))
				{
					cout << h->get_enemies() << " is dizy from losing to much blood!" << endl;
					h->set_defense_mod(1);
				}

			}
			else if (a == '5' && hero == "Wolverine" && lvl >= 10)
			{
				srand(time(NULL));
				cout << "Wolverine delivers multiple slashing attacks with each hit increasing in his rage!" << endl;
				power = "Bleed";
				int rand_int = rand() % 3;
				dmg = (str + (rand_int + 1)) * 4;
				bleed = dmg * .10;
				if (bleed >= (h->get_health() / 10))
				{
					cout << h->get_enemies() << " is bleeding out!" << endl;
					h->set_health(-bleed * 2);
				}

			}
			else if (a == '6' && hero == "Wolverine" && lvl >= 15)
			{
				srand(time(NULL));
				cout << "Wolverine drives his claws deep into his enemy," << endl
					<< "picks them up and throws them to the side!" << endl;
				power = "Bleed";
				int rand_int = rand() % 10;
				dmg = (str + (rand_int + 1)) * 5;
				bleed = dmg * .10;

			}
			else if (a == '7' && hero == "Wolverine" && lvl >= 20)
			{
				srand(time(NULL));
				cout << "Wolverine Impale the enemy on his claws, lift them up, and throw them down." << endl
					<< " He stabbs, attempting for an Instant Kill!" << endl;
				power = "Bleed";
				int kill = rand() % 10;
				if (kill >= 7)
				{
					cout << "Instant Kill!" << endl;
					h->max_health(h->get_health());
					dmg = h->get_max();
				}
				else
				{
					int rand_int = rand() % 10;
					dmg = (str  * (rand_int + 1)) * 2;
					bleed = dmg * .10;

				}

			}
			else
			{
				cout << "Please select a valid choice." << endl;
			}




		}
		else if (a == '3' && hero == "Captain America")
		{
			bool description = true;
			std::system("cls");
			while (description)
			{
				cout << "1. Chose a power?" << endl;
				cout << "2. Power description?" << endl;
				int d;
				d = _getch();
				if (d == '1')
				{
					std::system("cls");
					cout << "1. Shield Throw" << endl;
					cout << "2. Shield Bash" << endl;
					cout << "3. Shield Dash" << endl;
					if (lvl >= 5)
					{
						cout << "4. Shield Uppercut  " << endl;
					}
					if (lvl >= 10)
					{
						cout << "5. Pistol " << endl;
					}
					if (lvl >= 15)
					{
						cout << "6. Random Grenade " << endl;
					}
					if (lvl >= 20)
					{
						cout << "7. Skull Slam" << endl;
					}



					description = false;
				}
				else if (d == '2')
				{
					std::system("cls");
					cout << "1. Shield Throw: Shield attack that hits all enemies one time." << endl << endl;
					cout << "2. Shield Bash: A massive shield swing that may deal high damage." << endl << endl;
					cout << "3. Shield Dash: Running attack that increases Captain America's "
						<< endl << "speed for a short time." << endl << endl;
					if (lvl >= 5)
					{
						cout << "4. Shield Uppercut: Has a high chance for massive damage." << endl << endl;
					}
					if (lvl >= 10)
					{
						cout << "5. Pistol: Shoots a random number of bullets at an enemy." << endl << endl;
					}
					if (lvl >= 15)
					{
						cout << "6. Random Grenade: Grenade may cause instant death or may do nothing." << endl << endl;
					}
					if (lvl >= 20)
					{
						cout << "7. Skull Slam: High chance to instantly kill an enemy." << endl << endl;
					}



					std::system("pause");
					std::system("cls");
				}
				else
				{
					cout << "Please select a valid choice" << endl;
				}
			}
			if (hero == "Captain America")
			{
				int a;
				a = _getch();

				if (a == '1' && hero == "Captain America")
				{
					cout << "Captain America flips forward and hurls his mighty shield!" << endl;
					power = "Shield Throw";
					int rand_int;
					if (lvl <= 3)
					{
						srand(time(NULL));
						int rand_int = rand() % 10;
						int s_speed = rand() % 3;
						if (s_speed == 0)
						{
							s_speed = 1;

						}
						dmg = (rand_int + str) * s_speed;
					}
					else
					{
						srand(time(NULL));
						int rand_int = rand() % 20;
						int s_speed = rand() % 5;
						if (s_speed == 0)
						{
							s_speed = 1;

						}
						dmg = (rand_int + str) * s_speed;
					}

				}
				else if (a == '2' && hero == "Captain America")
				{
					srand(time(NULL));
					int rand_ints = rand() % 5;

					cout << "Captina America swings his Shield with great strenght!" << endl;
					power = "p";
					int rand_int = rand() % 10;
					if (h->get_defense() == 0)
					{
						h->set_defense(h->get_Cskill() + h->get_level() + h->get_speed() + rand_ints);
					}
					h->set_defense(-rand_int);
					if (h->get_defense() < p->get_defense())
					{
						h->set_defense_mod(1);
						cout << h->get_enemies() << "'s defense have droped due to the massive blow!" << endl;
					}
					dmg = str * lvl;

				}
				else if (a == '3' && hero == "Captain America")
				{
					srand(time(NULL));
					cout << "Captain America dashes forward with his Sheild in front!" << endl;
					power = "p";
					int rand_int = rand() % 6;
					if (rand_int == 5)
					{
						dmg = ((spd + str) * 2) + rand_int;

					}
					else
					{
						dmg = spd + str + rand_int;
					}


				}
				else if (a == '4' && hero == "Captain America" && lvl >= 5)
				{
					cout << "Captain America dashes forward and swings his shield upwards!" << endl;
					power = "p";
					srand(time(NULL));
					int rand_int = rand() % 5;
					if (rand_int > 3)
					{
						dmg = spd + str + skill * rand_int;
					}
					else
						dmg = spd + str + skill;
				}
				else if (a == '5' && hero == "Captain America" && lvl >= 10)
				{
					cout << "Captain America pulls out a Pistol and fires!" << endl;
					power = "p";
					srand(time(NULL));
					int rand_int = rand() % p->get_level();
					if (rand_int == 0)
					{
						rand_int = p->get_level();
					}
					cout << rand_int << " shots!" << endl;
					dmg = rand_int * 5;
				}
				else if (a == '6' && hero == "Captain America" && lvl >= 15)
				{
					cout << "Captain America finds a Grenade and throws it!" << endl;
					power = "Shield Throw";
					srand(time(NULL));
					int rand_int = rand() % 5;
					if (rand_int == 0)
					{
						cout << "Black Hole Grenade, " << h->get_enemies() << " is sucked into the void!" << endl;
						h->max_health(h->get_health());
						dmg = h->get_max();
					}
					else if (rand_int == 1)
					{
						srand(time(NULL));
						int rand_ints = rand() % 5;
						cout << "Dendrotoxin Grenade" << endl;
						if (rand_ints == 0)
						{
							rand_ints = 10;
						}
						cout << rand_ints << endl;
						dmg = rand_ints * skill;
					}
					else if (rand_int == 2)
					{
						cout << "Gas Grenade, " << h->get_enemies() << " falls asleep!" << endl;

						h->set_defense_mod(1);

						dmg = 0;
					}
					else if (rand_int == 3)
					{
						cout << "Dud!" << endl;
						dmg = 0;
					}
					else
					{
						cout << "Hand Grenade!" << endl;
						dmg = lvl * rand_int;
					}
				}
				else if (a == '7' && hero == "Captain America" && lvl >= 20)
				{
					cout << "Captain America digs deep and finds reserve strength." << endl
						<< "He SLAMS his shield into " << h->get_enemies() << " head!" << endl;
					power = "p";
					srand(time(NULL));
					int rand_int = rand() % (p->get_Cskill() + 10);
					if (p->get_Cskill() > rand_int)
					{
						cout << "Instant kill!" << endl;
						h->max_health(h->get_health());
						dmg = h->get_max();
					}
					else
					{
						dmg = h->get_health() / rand_int;
						if (dmg <= 0)
						{
							dmg = rand_int;
						}
					}
				}
				else
				{
					cout << "Please select a valid choice." << endl;
				}





			}
		}// end of cap
		else if (a == '3' && hero == "Black Panther")
		{
			bool description = true;
			std::system("cls");
			while (description)
			{
				cout << "1. Chose a power?" << endl;
				cout << "2. Power description?" << endl;
				int d;
				d = _getch();
				if (d == '1')
				{
					std::system("cls");
					cout << "1. Panther Claw" << endl;
					cout << "2. Energy Daggers" << endl;
					cout << "3. Razor Cyclone" << endl;
					if (lvl >= 5)
					{
						cout << "4. Crippling Blow" << endl;
					}
					if (lvl >= 10)
					{
						cout << "5. Pounce" << endl;
					}
					if (lvl >= 15)
					{
						cout << "6. Stealth" << endl;
					}
					if (lvl >= 20)
					{
						cout << "7. Panther's Might" << endl;
					}



					description = false;
				}
				else if (d == '2')
				{
					std::system("cls");
					cout << "1. Panther Claw: Slash at an enemy twice." << endl << endl;
					cout << "2. Energy Dagger: Thrown daggers hit all enemies." << endl << endl;
					cout << "3. Razor Cyclone: Spinning attack that hits all enemies." << endl << endl;
					if (lvl >= 5)
					{
						cout << "4. Crippling Blow: Slash attack with a high chance for criticals." << endl << endl;
					}
					if (lvl >= 10)
					{
						cout << "5. Pounce: Tackle an enemy with a chance to pin them." << endl << endl;
					}
					if (lvl >= 15)
					{
						cout << "6. Stealth: Increases defence for a short time and attacks one enemy." << endl << endl;
					}
					if (lvl >= 20)
					{
						cout << "7. Panther's Might: High chance to instantly kill an enemy." << endl << endl;
					}



					std::system("pause");
					std::system("cls");
				}
				else
				{
					cout << "Please select a valid choice" << endl;
				}
			}
			if (hero == "Black Panther")
			{
				int a;
				a = _getch();

				if (a == '1' && hero == "Black Panther")
				{
					cout << "Black Panther dashes forward and deleivers two deadly slashes to " << h->get_enemies() << "!" << endl;
					power = "p";
					srand(time(NULL));
					int rand_int = rand() % lvl;
					dmg = (rand_int + str + spd) * 2;

				}
				else if (a == '2' && hero == "Black Panther")
				{
					srand(time(NULL));
					int rand_ints = rand() % 5;

					cout << "Black Panther flips backwards and unleases a volly of energy daggers!" << endl;
					power = "Energy Daggers";
					int rand_int = rand() % (skill + str);
					if (rand_int > ((skill + str) / 2))
					{
						dmg = (lvl + skill + str) * 2;
					}
					else
					{
						dmg = (lvl + skill + str + rand_int);
					}

				}
				else if (a == '3' && hero == "Black Panther")
				{
					srand(time(NULL));
					cout << "Black Panther runs forward, jumps and spins as daggers slash at anyone near him!" << endl;
					power = "Razor Cyclone";
					int rand_int = rand() % 6;
					if (rand_int == 5)
					{
						dmg = ((spd + str) * 2) + rand_int;

					}
					else
					{
						dmg = spd + str + rand_int + skill;
					}


				}
				else if (a == '4' && hero == "Black Panther" && lvl >= 5)
				{
					cout << "Black Panther dashes forward and slashes with his claws!" << endl;
					power = "p";
					srand(time(NULL));
					int rand_int = rand() % 6;
					if (rand_int > 3)
					{
						cout << "Black Panther hits a vital spot! CRITICAL HIT!" << endl;
						dmg = (spd + str + skill) * rand_int;
					}
					else
						dmg = spd + str + skill;
				}
				else if (a == '5' && hero == "Black Panther" && lvl >= 10)
				{
					cout << "Black Panther leaps into the air and lands on " << h->get_enemies() << "!" << endl;
					power = "p";
					srand(time(NULL));
					int rand_slash = rand() % lvl;
					if (rand_slash == 0)
					{
						rand_slash = 1;
					}
					if (h->get_strength() <= p->get_strength())
					{
						cout << "Black Panther keeps " << h->get_enemies() << " pinned down!" << endl;
						h->set_defense_mod(1);
					}

					cout << "Black Panther slashes " << rand_slash << " times!" << endl;
					dmg = (str + skill) * rand_slash;
				}
				else if (a == '6' && hero == "Black Panther" && lvl >= 15)
				{
					cout << "Black Panther becomes invisible and goes in for a sneak attack!" << endl;
					power = "p";
					srand(time(NULL));
					defe = defe * 2;
					int rand_int = rand() % lvl;
					if (rand_int > (lvl / 2))
					{
						cout << "CRITICAL HIT!" << endl;
						dmg = str * rand_int;
					}
					else
					{
						dmg = str + defe;
						if (dmg < lvl)
						{
							dmg = lvl;
						}
					}
				}
				else if (a == '7' && hero == "Black Panther" && lvl >= 20)
				{
					cout << "Black Panther leaps into the air and slams down on " << h->get_enemies() << "!" << endl;
					power = "p";
					srand(time(NULL));
					int rand_int = rand() % (p->get_Cskill() + 10);
					if (p->get_Cskill() > rand_int)
					{
						cout << "Instant kill!" << endl;
						h->max_health(h->get_health());
						dmg = h->get_max();
					}
					else
					{
						dmg = h->get_health() / rand_int;
						if (dmg <= 0)
						{
							dmg = rand_int;
						}
					}
				}
				else
				{
					cout << "Please select a valid choice." << endl;
				}
			}
		}//end panther

		else if (a == '3' && hero == "Ms. Marvel")
		{
			bool description = true;
			std::system("cls");
			while (description)
			{
				cout << "1. Chose a power?" << endl;
				cout << "2. Power description?" << endl;
				int d;
				d = _getch();
				if (d == '1')
				{
					std::system("cls");
					cout << "1. Luminous" << endl;
					cout << "2. Photon Burst" << endl;
					cout << "3. Explosive Touch" << endl;
					if (lvl >= 5)
					{
						cout << "4. Mega Blast" << endl;
					}
					if (lvl >= 10)
					{
						cout << "5. Prism" << endl;
					}
					if (lvl >= 15)
					{
						cout << "6. Warp Punch" << endl;
					}
					if (lvl >= 20)
					{
						cout << "7. Cosmic Slam" << endl;
					}



					description = false;
				}
				else if (d == '2')
				{
					std::system("cls");
					cout << "1. Luminous: A powerful force blast." << endl << endl;
					cout << "2. Photon Burst: Burst of energy that hits all enemies." << endl << endl;
					cout << "3. Explosive Touch: Charges an enemy with explosive energy " << endl <<
						"that blows up after a time." << endl << endl;
					if (lvl >= 5)
					{
						cout << "4. Mega Blast: Blast energy into the ground hitting all enemies." << endl << endl;
					}
					if (lvl >= 10)
					{
						cout << "5. Prism: Solid beam of energy that might split and hit multiple enemies." << endl << endl;
					}
					if (lvl >= 15)
					{
						cout << "6. Warp Punch: Massive punch with a high chance to stun an enemy.." << endl << endl;
					}
					if (lvl >= 20)
					{
						cout << "7. Cosmic Slam: Slams the ground potentially knocking over all enemies." << endl << endl;
					}



					std::system("pause");
					std::system("cls");
				}
				else
				{
					cout << "Please select a valid choice" << endl;
				}
			}
			if (hero == "Ms. Marvel")
			{
				int a;
				a = _getch();

				if (a == '1' && hero == "Ms. Marvel")
				{
					cout << "Ms. Marvel's hands glow as she blast energy at " << h->get_enemies() << "!" << endl;
					power = "p";
					srand(time(NULL));
					int rand_int = rand() % energy;
					rand_int++;
					if (lvl >= 5)
					{
						h->set_durability(-rand_int, p);
						int max_health;
						while (h->get_durability() <= 0)
						{
							h->set_durability(+1, p);
						}
						cout << h->get_enemies() << "'s durability drops to " << h->get_durability() << " due to the energy!" << endl;
						if (h->get_enemies() == "Thug" || h->get_enemies() == "Thug1" || h->get_enemies() == "Thug2" || h->get_enemies() == "Thug3"
							|| h->get_enemies() == "Thug4" || h->get_enemies() == "Thug5" || h->get_enemies() == "Hydra Soldier"
							|| h->get_enemies() == "A.I.M. Tech" || h->get_enemies() == "Civilian" || h->get_enemies() == "Mob Leader")
						{
							max_health = h->get_durability() * 5;
							if (max_health < h->get_health())
							{
								while (h->get_health() > max_health)
								{
									h->set_health(-1);
								}
							}
						}
						else
						{
							h->set_durability(+rand_int, p);
							h->max_health(h->get_durability() * (15 + h->get_level()) + 100);
							max_health = h->get_max() - h->get_health();
							h->set_durability(-rand_int, p);
							h->max_health(h->get_durability() * (15 + h->get_level()) + 100);
							while (h->get_health() != 0)
							{
								h->set_health(-1);
							}
							h->set_health(+h->get_max());
							h->set_health(-max_health);

						}
					}
					dmg = (rand_int + energy + skill);

				}
				else if (a == '2' && hero == "Ms. Marvel")
				{
					srand(time(NULL));
					cout << "Ms. Marvel's hands glow as she blast enery all around her!" << endl;
					power = "Photon Burst";
					int rand_int = rand() % (energy + energy);
					if (rand_int > energy)
					{
						dmg = (lvl + skill + energy) * 2;
					}
					else
					{
						dmg = (lvl + skill + energy + rand_int);
					}

				}
				else if (a == '3' && hero == "Ms. Marvel")
				{
					srand(time(NULL));
					cout << "Ms. Marvel runs forward and grabs " << h->get_enemies() << "!" << endl;
					cout << "Her hands glow as she charges " << h->get_enemies() << " with energy!" << endl;
					power = "Explosive Touch";
					dmg = energy;
				}
				else if (a == '4' && hero == "Ms. Marvel"  && lvl >= 5)
				{
					cout << "Ms. Marvel fires a blast of energy into the ground!" << endl;
					power = "Mega Blast";
					srand(time(NULL));
					int rand_int = rand() % (energy * 2);
					rand_int++;
					dmg = rand_int + energy + skill;
				}
				else if (a == '5' && hero == "Ms. Marvel" && lvl >= 10)
				{
					cout << "Ms. Marvel shoots a focused beam of energy at " << h->get_enemies() << "!" << endl;
					power = "Prism";
					srand(time(NULL));
					int rand_slash = rand() % energy;
					int strength_sap = (h->get_strength() / 4);
					if (rand_slash == 0)
					{
						cout << h->get_enemies() << "'s Strength has been sapped due to the energy!" << endl;
						cout << h->get_enemies() << "'s Strenght drops by " << strength_sap << "!" << endl;
						h->set_strenght(-strength_sap, p);
						cout << h->get_enemies() << "'s Strength is now " << h->get_strength() << "." << endl;
						rand_slash = 1;
					}
					dmg = (energy + skill) * rand_slash;
				}
				else if (a == '6' && hero == "Ms. Marvel" && lvl >= 15)
				{
					cout << "Ms. Marvel flies forward delivering a massive blow!" << endl;
					power = "p";
					srand(time(NULL));
					int rand_int = rand() % lvl;
					if (rand_int > (lvl / 2))
					{
						cout << "The blow renders " << h->get_enemies() << " stunned!" << endl;
						h->set_defense_mod(1);
					}
					if (skill > h->get_Cskill())
					{
						cout << "Ms. Marvel Continues his assault!" << endl;
						int extra_dmg = skill - h->get_Cskill();
						if (extra_dmg <= 1)
						{
							extra_dmg = 2;
						}
						dmg = (str + spd + skill + rand_int + lvl) * extra_dmg;
					}
					else
					{
						dmg = (str + spd + skill + rand_int + lvl);
					}
				}
				else if (a == '7' && hero == "Ms. Marvel" && lvl >= 20)
				{
					cout << "Ms. Marvel flies into the air and slams into the ground!" << endl;
					power = "Cosmic Slam";
					srand(time(NULL));
					int rand_int = rand() % (str + spd);
					if (rand_int == 0)
					{
						rand_int = 1;
					}

					dmg = str * spd * rand_int;
				}
				else
				{
					cout << "Please select a valid choice." << endl;
				}
			}
		}// end marvel
		else if (a == '3' && hero == "Mr. Fantastic")
		{
			bool description = true;
			std::system("cls");
			while (description)
			{
				cout << "1. Chose a power?" << endl;
				cout << "2. Power description?" << endl;
				int d;
				d = _getch();
				if (d == '1')
				{
					std::system("cls");
					cout << "1. Propeller Arms" << endl;
					cout << "2. Drastic Elastic" << endl;
					cout << "3. Dashing Wheel" << endl;
					if (lvl >= 5)
					{
						cout << "4. Pin Ball" << endl;
					}
					if (lvl >= 10)
					{
						cout << "5. Extending Strike" << endl;
					}
					if (lvl >= 15)
					{
						cout << "6. Elastic Smash" << endl;
					}
					if (lvl >= 20)
					{
						cout << "7. Elastic Crush" << endl;
					}



					description = false;
				}
				else if (d == '2')
				{
					std::system("cls");
					cout << "1. Propeller Arms: Spins arms in inflicting damage" << endl <<
						" and raising his defense." << endl << endl;
					cout << "2. Drastic Elastic: Powerful swing that can knock down an enemy." << endl << endl;
					cout << "3. Dashing Wheel: Slams into an enemy, possible stunning them. " << endl << endl;
					if (lvl >= 5)
					{
						cout << "4. Pin Ball: As a ball, he bounces off of all enemies, " << endl
							<< " possibly knocking them down." << endl << endl;
					}
					if (lvl >= 10)
					{
						cout << "5. Extending Strike: Massive hit with high chance for critical." << endl << endl;
					}
					if (lvl >= 15)
					{
						cout << "6. Elastic Smash: Massive punch into the ground " << endl
							<< "with a high chance to stun all enemies." << endl << endl;
					}
					if (lvl >= 20)
					{
						cout << "7. Elastic Crush: Out-strechted arms crush all enemies." << endl
							<< "Stunned enemies take double damage." << endl << endl;
					}



					std::system("pause");
					std::system("cls");
				}
				else
				{
					cout << "Please select a valid choice" << endl;
				}
			}
			if (hero == "Mr. Fantastic")
			{
				int a;
				a = _getch();

				if (a == '1' && hero == "Mr. Fantastic")
				{
					cout << "Mr. Fantastic's arm spin in a circle creating a protective barrier!" << endl;
					power = "p";
					srand(time(NULL));
					int rand_int = rand() % lvl;
					h->set_defense_mod(1);
					dmg = (rand_int + str + spd);

				}
				else if (a == '2' && hero == "Mr. Fantastic")
				{
					srand(time(NULL));
					int rand_ints = rand() % 5;

					cout << "Mr. Fantastic extends his arm and whips it at " << h->get_enemies() << "!" << endl;
					power = "p";
					int rand_int = rand() % (skill + str);
					dmg = rand_int + lvl + spd;
					if (rand_int > h->get_speed())
					{
						cout << "Mr. Fantastic pops " << h->get_enemies() << " into the air!" << endl;
						cout << "He then slams his arm into " << h->get_enemies() << " slamming them into the ground!" << endl;
						dmg = dmg * 2;
					}
					if (dmg > (h->get_health() * .25))
					{
						cout << h->get_enemies() << " is stunned from the attack!" << endl;
						h->set_defense_mod(1);
					}

				}
				else if (a == '3' && hero == "Mr. Fantastic")
				{
					srand(time(NULL));
					cout << "Mr. Fantastic runs forward and grabs his anckles turning himself into a wheel!" << endl;
					cout << "He rolls and slams into " << h->get_enemies() << " with great force!" << endl;
					power = "p";
					int momentum = rand() % (spd + lvl);
					momentum++;
					dmg = lvl + spd + str;
					if (momentum > lvl && momentum > spd)
					{
						cout << "CRITICAL HIT! Mr. Fantastic crushes " << h->get_enemies() << " with his body!" << endl;
						dmg += (dur * 2);
						cout << h->get_enemies() << " is stunned from the attack!" << endl;
						h->set_defense_mod(1);
					}
					else if (momentum > lvl || momentum > spd)
					{
						cout << h->get_enemies() << " is stunned from the attack!" << endl;
						h->set_defense_mod(1);
					}
				}
				else if (a == '4' && hero == "Mr. Fantastic" && lvl >= 5)
				{
					cout << "Mr. Fantastic rolls up into a ball and starts slamming into his enemies!" << endl;
					power = "Pin Ball";
					srand(time(NULL));
					int rand_int = rand() % (lvl + dur);
					dmg = rand_int + str + skill + spd + dur;
				}
				else if (a == '5' && hero == "Mr. Fantastic" && lvl >= 10)
				{
					cout << "Mr. Fantastic extends his arm and swings it forward at " << h->get_enemies() << " with great might!" << endl;
					power = "p";
					srand(time(NULL));
					int rand_spd = rand() % (defe + spd);
					int rand_e_spd = rand() % (h->get_speed() + h->get_defense());
					dmg = str + spd + skill + rand_spd;
					if (rand_spd > rand_e_spd || (rand_e_spd == 0 && rand_spd > 0))
					{
						cout << "CRITICAL HIT!" << endl;
						dmg = dmg * 2;
					}

				}
				else if (a == '6' && hero == "Mr. Fantastic" && lvl >= 15)
				{
					cout << "Mr. Fantastic extends his arms and whips them into the ground!" << endl;
					power = "Elastic Smash";
					srand(time(NULL));
					int rand_int = rand() % lvl;
					if (rand_int > 5)
					{
						rand_int = 5;
					}
					if (rand_int == 0)
					{
						rand_int = 6;
					}
					dmg = (spd + str) * rand_int;
				}
				else if (a == '7' && hero == "Mr. Fantastic" && lvl >= 20)
				{
					cout << "Mr. Fantastic's hands grow in size as he slams both is hands down onto " << h->get_enemies() << "!" << endl;
					power = "Elastic Crush";
					srand(time(NULL));
					int rand_int = rand() % (str + spd);
					rand_int++;
					cout << str << " str" << endl << spd << " spd" << endl << rand_int << " int" << endl;
					dmg = str * spd * rand_int;
				}
				else
				{
					cout << "Please select a valid choice." << endl;
				}
			}
		}// end fantastic
		else if (a == '3' && hero == "Black Widow")
		{
			bool description = true;
			std::system("cls");
			while (description)
			{
				cout << "1. Chose a power?" << endl;
				cout << "2. Power description?" << endl;
				int d;
				d = _getch();
				if (d == '1')
				{
					std::system("cls");
					cout << "1. Widow's Bite" << endl;
					cout << "2. Dual Pistol" << endl;
					cout << "3. Tear Gas" << endl;
					if (lvl >= 5)
					{
						cout << "4. Garrote" << endl;
					}
					if (lvl >= 10)
					{
						cout << "5. Round House Kick" << endl;
					}
					if (lvl >= 15)
					{
						cout << "6. Takedown" << endl;
					}
					if (lvl >= 20)
					{
						cout << "7. Martial Art Assault" << endl;
					}



					description = false;
				}
				else if (d == '2')
				{
					std::system("cls");
					cout << "1. Widow's Bite: Electric bullets shot at all enemies, " << endl
						<< "with a high chance to stun." << endl << endl;
					cout << "2. Dual Pistol: Shoot a volley of bullets." << endl << endl;
					cout << "3. Tear Gas: Causes no damage but can blind all enemies. " << endl << endl;
					if (lvl >= 5)
					{
						cout << "4. Garrote: Grab and choke an enemy, " << endl
							<< " possibly knocking them out." << endl << endl;
					}
					if (lvl >= 10)
					{
						cout << "5. Round House Kick: Massive hit with high chance for a follow up attack." << endl << endl;
					}
					if (lvl >= 15)
					{
						cout << "6. Takedown: Can pin an enemy, while attacking " << endl
							<< "without mercy." << endl << endl;
					}
					if (lvl >= 20)
					{
						cout << "7. Martial Art Assault: Launch a volley of punches, " << endl
							<< "kicks, and chokes agains an enemy." << endl << endl;
					}



					std::system("pause");
					std::system("cls");
				}
				else
				{
					cout << "Please select a valid choice" << endl;
				}
			}
			if (hero == "Black Widow")
			{
				int a;
				a = _getch();
				while (a == '1' && h->get_defense_mod() == true)
				{
					cout << "Widow's Bite Must recharge." << endl;
					cout << "Please select a new power." << endl;
					system("pause");
					system("cls");

					cout << "1. Widow's Bite" << endl;
					cout << "2. Dual Pistol" << endl;
					cout << "3. Tear Gas" << endl;
					if (lvl >= 5)
					{
						cout << "4. Garrote" << endl;
					}
					if (lvl >= 10)
					{
						cout << "5. Round House Kick" << endl;
					}
					if (lvl >= 15)
					{
						cout << "6. Takedown" << endl;
					}
					if (lvl >= 20)
					{
						cout << "7. Martial Art Assault" << endl;
					}
					a = _getch();
				}

				if (a == '1' && hero == "Black Widow")
				{
					cout << "Black Widow raises her arm and uleashes a volley of Widow's Bite!" << endl;
					power = "Widow's Bite";
					srand(time(NULL));
					dmg = 0;
					int rand_shock = rand() % energy;
					if (rand_shock < 1)
					{
						rand_shock = 1;
					}
					else if (rand_shock > 10)
					{
						rand_shock = 10;
					}
					for (int i = 0; i < rand_shock; i++)
					{
						dmg = dmg + (rand_shock + energy);
					}

				}
				else if (a == '2' && hero == "Black Widow")
				{
					srand(time(NULL));
					int rand_ints = rand() % 5;

					cout << "Black Widow pulls out two pistols and fires!" << endl;
					power = "p";
					int rand_int = rand() % skill;
					int count = 0;
					dmg = 0;
					for (int i = 0; i < rand_int; i++)
					{
						dmg += 2;
						count++;
						if (count == 12)
						{
							cout << "Black Widow reloads and continues shooting!" << endl;
							while (count != 0)
							{
								count--;
							}
						}
					}
					if (dmg == 0)
					{
						cout << "The Gun jams and won't fire!" << endl;
					}

				}
				else if (a == '3' && hero == "Black Widow")
				{
					cout << "Black Widow shoots tear gas cartridges from her bracelets!" << endl;
					power = "Tear Gas";
					dmg = 0;
				}
				else if (a == '4' && hero == "Black Widow" && lvl >= 5)
				{
					power = "p";
					bool attack = false;
					if (h->get_defense_mod() == true)
					{
						attack = true;
					}
					else if (h->get_speed() > skill || h->get_Cskill() > skill)
					{
						cout << "Black Widow can't get the garrote around " << h->get_enemies() << " neck." << endl;
						dmg = 0;
					}
					else
					{
						cout << "Black Widow pulls out a garrote wire and wraps it around " << h->get_enemies() << " neck!" << endl;

						srand(time(NULL));
						int rand_str = rand() % (skill + str);
						int rand_e_str = rand() % (h->get_strength() + h->get_Cskill());
						int passout = 0;
						dmg = str + skill + rand_str;
						if (rand_str > rand_e_str)
						{
							while (rand_str > rand_e_str)
							{
								passout++;
								dmg += 2;
								srand(time(NULL));
								rand_str = rand() % (skill + str);
								rand_e_str = rand() % (h->get_strength() + h->get_Cskill());
								if (passout > h->get_durability())
								{
									cout << h->get_enemies() << " blacks out!" << endl;
									dmg += passout;
									h->set_defense_mod(1);
									break;
								}
							}
						}
						else
						{
							cout << h->get_enemies() << " escapes from the garrote!" << endl;
							if (spd > h->get_speed() && skill > h->get_Cskill())
							{
								cout << "Black Widow quickly spins around and unleashes a flurry of deadly punches!" << endl;
								for (int i = 0; i < skill; i++)
								{
									dmg = skill;
								}
							}
							else if (spd > h->get_speed())
							{
								cout << "Black Widow quickly spins around and unleashes a burst of jabs!" << endl;
								for (int i = 0; i < spd; i++)
								{
									dmg = str;
								}
							}
						}
					}

					if (attack = true)
					{

						cout << "Black Widow pulls out a garrote wire and wraps it around " << h->get_enemies() << " neck!" << endl;

						srand(time(NULL));
						int rand_str = rand() % (skill + str);
						int rand_e_str = rand() % (h->get_strength() + h->get_Cskill());
						int passout = 0;
						dmg = str + skill + rand_str;
						if (rand_str > rand_e_str)
						{
							while (rand_str > rand_e_str)
							{
								passout++;
								dmg += 2;
								srand(time(NULL));
								rand_str = rand() % (skill + str);
								rand_e_str = rand() % (h->get_strength() + h->get_Cskill());
								if (passout > h->get_durability())
								{
									cout << h->get_enemies() << " blacks out!" << endl;
									dmg += passout;
									h->set_defense_mod(1);
									break;
								}
							}
						}
						else
						{
							cout << h->get_enemies() << " escapes from the garrote!" << endl;
							if (spd > h->get_speed() && skill > h->get_Cskill())
							{
								cout << "Black Widow quickly spins around and unleashes a flurry of deadly punches!" << endl;
								for (int i = 0; i < skill; i++)
								{
									dmg = skill;
								}
							}
							else if (spd > h->get_speed())
							{
								cout << "Black Widow quickly spins around and unleashes a burst of jabs!" << endl;
								for (int i = 0; i < spd; i++)
								{
									dmg = str;
								}
							}
						}
					}

				}
				else if (a == '5' && hero == "Black Widow" && lvl >= 10)
				{
					cout << "Black Widow quickly spins around and delievers a powerful round house kick!" << endl;
					power = "p";
					srand(time(NULL));
					int rand_spd = rand() % spd;
					int rand_e_spd = rand() % h->get_speed();
					rand_spd += spd;
					rand_e_spd += h->get_speed();
					dmg = spd * str;
					if (rand_spd >= rand_e_spd)
					{
						if (skill >= h->get_Cskill())
						{
							cout << "Black Widow follows with a second powerful round house kick!" << endl;
							dmg *= 2;
						}
						else
						{
							cout << "Black Widow follows with a powerful uppercut!" << endl;
							dmg += (dmg / 2);
						}
					}
					else if (skill >= h->get_Cskill())
					{

						cout << "Black Widow follows with a flurry of punches!" << endl;
						for (int i = 0; i < (skill - h->get_Cskill()); i++)
						{
							dmg += str;
						}
					}

				}
				else if (a == '6' && hero == "Black Widow" && lvl >= 15)
				{
					cout << "Black Widow jumps onto " << h->get_enemies() << " flips them onto the floor and starts a beat down!" << endl;
					power = "p";
					srand(time(NULL));
					int rand_dur = rand() % h->get_durability();
					if (rand_dur == 0)
					{
						rand_dur = skill;
					}
					else if (rand_dur < lvl)
					{
						rand_dur = lvl + (lvl / 4);
					}
					int rand_skill = rand() % skill;
					int rand_str = rand() % str;
					rand_skill += skill;
					rand_str += h->get_strength();
					dmg = 0;
					for (int i = lvl; i < rand_dur; i++)
					{
						int rand_attack = rand() % 5;
						if (rand_attack == 0)
						{
							cout << "Black Widow punches " << h->get_enemies() << " in the face!" << endl;
							dmg += str;
						}
						else if (rand_attack == 1)
						{
							cout << "Black Widow knees " << h->get_enemies() << " in the ribs!" << endl;
							dmg += str + spd;
						}
						else if (rand_attack == 2)
						{
							cout << "Black Widow knees " << h->get_enemies() << " in the groin!" << endl;
							dmg += str + skill;
						}
						else if (rand_attack == 3)
						{
							cout << "Black Widow elbows " << h->get_enemies() << " in the face!" << endl;
							dmg += str + str + spd;
						}
						else
						{
							cout << "Black Widow headbutts " << h->get_enemies() << endl;
							dmg += str + spd + skill + dur;
						}
						system("pause");
						system("cls");
					}
					if (rand_skill > rand_str)
					{
						srand(time(NULL));
						rand_dur = rand() % h->get_durability();
						if (rand_dur == 0)
						{
							rand_dur = 1;
						}
						else if (rand_dur < lvl)
						{
							rand_dur = lvl + (lvl / 4);
						}
						cout << h->get_enemies() << " tries to push Black Widow off but fails!" << endl
							<< "Black Widow continues the assault!" << endl;
						for (int i = lvl; i < rand_dur; i++)
						{
							int rand_attack = rand() % 5;
							if (rand_attack == 0)
							{
								cout << "Black Widow punches " << h->get_enemies() << " in the face!" << endl;
								dmg += str;
							}
							else if (rand_attack == 1)
							{
								cout << "Black Widow knees " << h->get_enemies() << " in the ribs!" << endl;
								dmg += str + spd;
							}
							else if (rand_attack == 2)
							{
								cout << "Black Widow knees " << h->get_enemies() << " in the groin!" << endl;
								dmg += str + skill;
							}
							else if (rand_attack == 3)
							{
								cout << "Black Widow elbows " << h->get_enemies() << " in the face!" << endl;
								dmg += str + str + spd;
							}
							else
							{
								cout << "Black Widow headbutts " << h->get_enemies() << endl;
								dmg += str + spd + skill + dur;
							}
							system("pause");
							system("cls");
						}

					}
					else if (dmg > (h->get_health() / 4))
					{
						h->set_defense_mod(1);
						cout << h->get_enemies() << " blacks out from the assault!" << endl;
					}
				}
				else if (a == '7' && hero == "Black Widow" && lvl >= 20)
				{
					cout << "Black Widow charges " << h->get_enemies() << " and unleases an onslaught of attacks!" << endl;
					power = "p";
					dmg = 0;
					int dmg_attack = 0;
					for (int i = 0; i < (skill + h->get_durability()); i++)
					{
						srand(time(NULL));
						int rand_int = rand() % 8;
						int rand_hit = rand() % skill;
						if (rand_hit == 0)
						{
							rand_hit = 1;
						}
						int rand_rib = rand() % 13;
						if (rand_rib == 0)
						{
							rand_rib = 1;
						}
						if (rand_int == 0)
						{
							cout << "Black Widow smashes " << h->get_enemies() << "'s face into a wall!" << endl;
							dmg_attack = str + skill + rand_hit;
							cout << dmg_attack << " Damage!" << endl;
							dmg += dmg_attack;
						}
						else if (rand_int == 1)
						{
							cout << "Black Widow punches " << h->get_enemies() << " " << rand_hit << " times in the face!" << endl;
							dmg += (str * rand_hit);
							cout << dmg_attack << " Damage!" << endl;
							dmg += dmg_attack;
						}
						else if (rand_int == 2)
						{
							cout << "Black Widow slames her fist into " << h->get_enemies() << " ribs " << rand_hit << endl
								<< " times and breaks " << rand_rib << " ribs!" << endl;
							dmg_attack = (str * rand_rib) + (h->get_durability() - rand_rib);
							cout << dmg_attack << " Damage!" << endl;
							dmg += dmg_attack;
						}
						else if (rand_int == 3)
						{
							cout << "Black Widow spins around and kicks " << h->get_enemies() << "'s knee caps!" << endl;
							if (dmg >= h->get_durability())
							{
								cout << "The impact breaks " << h->get_enemies() << "'s knee!" << endl;
								h->set_defense_mod(1);
							}
							dmg_attack = spd + h->get_durability();
							cout << dmg_attack << " Damage!" << endl;
							dmg += dmg_attack;
						}
						else if (rand_int == 4)
						{
							cout << "Black Widow manages to get behind " << h->get_enemies() << " and places him in a choke hold!" << endl;
							srand(time(NULL));
							int rand_choke = rand() % (str + skill);
							dmg_attack = (str * rand_hit) + skill;
							cout << dmg_attack << " Damage!" << endl;
							dmg += dmg_attack;
							if (rand_choke > h->get_durability())
							{
								cout << "Black Widow's choke hold causes " << h->get_enemies() << " to black out!" << endl;
								h->set_defense_mod(1);
								break;
							}
						}
						else if (rand_int == 7)
						{
							cout << "Black Widow grabs " << h->get_enemies() << "'s head and tries to snap his neck!" << endl;
							if (h->get_enemies() == "Wolverine")
							{
								cout << "Wolverine laughs and says 'Look lady, my neck will not brake'" << endl;
								cout << "Black Widow responds' Your right, thats why i placed a C-4 in your pocket.'" << endl
									<< "Black Widow releases Wolverine and dives for cover." << endl << "BOOOOMMM!!!!" << endl;
								if (dmg < (h->get_health() / 2))
								{
									dmg = (h->get_health() / 2);
								}
								else
								{
									dmg_attack = (h->get_health() / 4);
									cout << dmg_attack << " Damage!" << endl;
									dmg += dmg_attack;
								}
								break;
							}
							else if ((dmg + str) > (h->get_durability() + h->get_defense()))
							{
								cout << "With one swift motion Black Widow snaps " << h->get_enemies() << "'s neck!" << endl;
								h->max_health(h->get_health());
								dmg = h->get_max();
								break;
							}
							else
							{
								cout << h->get_enemies() << " breaks free befor Black Widow can snap his neck!" << endl;
							}
						}
						else
						{
							cout << "Black Widow unleases a flurry of punch and kicks at " << h->get_enemies() << "!" << endl;
							dmg_attack = str + spd;
							cout << dmg_attack << " Damage!" << endl;
							dmg += dmg_attack;

						}
						system("pause");
						system("cls");
					}
				}
				else
				{
					cout << "Please select a valid choice." << endl;
				}
			}
		}// end widow
		else
		{
			cout << "Please enter a valid choice." << endl;
			input = true;
		}

	} while (input == true);

}
int player::get_attack()
{
	return dmg;
}
void player::set_conditon(enemies* h)
{
	if (power == "Web Dive")
	{
		srand(time(NULL));
		int rand_int = rand() % 5;
		int rand_str = rand() % str;
		if (h->get_strength() < (web_str + rand_str))
		{
			web_str += 1;
			if (h->get_speed() > 0)
			{
				h->set_speed(-rand_int);
			}
			cout << endl << h->get_enemies() << " speed decreases to " << h->get_speed() << endl;

		}
		else
		{
			if (web_str > lvl)
			{
				cout << h->get_enemies() << " easily breaks the webbing! " << endl;

				h->set_speed(+rand_int);
				web_str += -1;
			}
		}

	}
	else if (power == "Missile Barrage")
	{
		int rand_ints = rand() % 5;
		int rand_int = rand() % 5;
		if (h->get_defense() == 0)
		{
			h->set_defense(h->get_Cskill() + h->get_level() + h->get_speed() + rand_ints);
		}
		h->set_defense(-rand_int);
		if (h->get_defense() <= defe)
		{
			h->set_defense_mod(1);
			cout << h->get_enemies() << "'s defense have droped due to the explosion " << endl;
		}

	}
	else
	{
		;
	} 
	
}
string player::get_power()
{
	return power;
}
void player::set_bleed_dmg(int i)
{
	bleed_dmg += i;
}
int player::get_bleed_dmg()
{
	return bleed_dmg;
}
int player::get_bleed()
{
	return bleed;
}
void player::set_reputation(double i)
{
	rep += i;
}
double player::get_reputation()
{
	return rep;
}
void player::print_stat()
{
	cout << "Hero: " << hero << ", Level: " << lvl << ", Health: " << hlth << endl;
	cout << "Expereince to next level: " << exp << endl;
	if (lvl > 1)
	{
		cout << "Current Expereince: " << Cexp << endl;
	}
	else
		cout << "Current Expereince: "<< Cexp << endl;

	cout << "Strength: " << str << endl;
	cout << "Speed: " << spd << endl;
	cout << "Durability: " << dur << endl;
	cout << "Combat Skill: " << skill << endl;
	cout << "Intelligence: " << intell << endl;
	cout << "Energy Projection: " << energy << endl;
	if (hero == "Wolverine")
	{
		cout << "Health Regeneration: " << regen << endl;
	}
	else if (hero == "Iron Man" || hero == "Mr. Fantastic")
	{
		cout << "Damage Reduction: " << reduce << endl;
	}
	cout << "Reputation: " << rep << " / 100" << endl;

}
void player::set_reduce()
{
	if (hero  == "Iron Man")
	{
		reduce = dur / 2;
	}
	else if (hero == "Mr. Fantastic")
	{
		reduce = dur / 4;
	}
	if (reduce <= 0)
	{
		reduce = 1;
	}
}
int player::get_reduce()
{
	return reduce;
}
void player::set_web_strength(int i)
{
	web_str += i;
}
int player::get_web_strength()
{
	return web_str;
}
void player::set_evade()
{
	evade = (skill + intell);
}
int player::get_evade()
{
	return evade;
}
void player::set_defense_mod(int i, string h, int ice)
{
	if (i == 1)
	{
		ko = true;
	}
	else
	{
		int stunned = rand() % dur;
		if (stunned < (dur / 2))
		{
			ko = false;
		}
		else
		{
			if (h == "ice")
			{
				if (str > ice)
				{
					cout << hero << " smashes out of the ice!" << endl;
					ko = false;
				}
				else
				{
					cout << hero << " is still stuck in the ice!" << endl;
					spd -= 2;
					cout << hero << "'s speed has dropped to " << spd << " due to the ice!" << endl;
					ko = true;
				}
				
			}
			else if (h == "Earth")
			{
				cout << hero << " is still trapped in the earth!" << endl;
				ko = true;
			}
			else
			{
				cout << hero << " is unable to attack!" << endl;
				ko = true;
			}
			system("pause");
			system("cls");
		}
	}
}
bool player::get_defense_mod()
{
	return ko;
}
