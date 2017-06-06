#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
#include "enemies.h"
#include "Hero.h"
#include "Enum.h"
using namespace std;

int rnd_prv[15] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 }; // durability
int rnd_prv2[15] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 }; // defense

enemies::enemies()
{
	name = "";
	weapon = "";
	e_energy = 0;
	e_intell = 0;
	e_str = 0;
	e_spd = 0;
	e_dur = 0;
	e_skill = 0;
	e_hlth = 0;
	e_exp = 0;
	e_attack = 0;
	e_lvl = 0;
	e_defe = 0;
	rnd_defe = 0;
	e_dmg = 0;
	bleed = 0;
	bleed_dmg = 0;
	ice_str = 0;
	max = 0;
	rage = 0;
	nitro = 0;
	regen = 0;
	reduce = 0;
	number_enemies = 0;
	rep = 0;
	evade = 0;
	web_str = 0;
	int_name = -1;
	e_power = "";
	for (int i = 0; i < 6; i++) items[i] = NULL;
	ko = false;
	is_boss = false;
	is_villian = false;
	bleeding = false;
	evades = false;
}
void enemies::set_enemies(string h, player* hero)
{
	bool replace = true;
	if (h == "hero")
	{
		while (replace)
		{
			srand(time(NULL));
			int rand_int = rand() % 4;
			if (hero->get_registration() == "anti")
			{
				if (rand_int == 0)
				{
					h = "Iron Man";
					name = h;
					replace = false;
				}
				else if (rand_int == 1)
				{
					h = "Mr. Fantastic";
					name = h;
					replace = false;
				}
				else if (rand_int == 2)
				{
					h = "Black Widow";
					name = h;
					replace = false;
				}
				else if (rand_int == 3)
				{
					h = "Ms. Marvel";
					name = h;
					replace = false;
				}
				
				
			}
			else
			{
				if (rand_int == 0)
				{
					h = "Wolverine";
					name = h;
					replace = false;
				}
				else if (rand_int == 1)
				{
					h = "Captain America";
					name = h;
					replace = false;
				}
				else if (rand_int == 2)
				{
					h = "Spiderman";
					name = h;
					replace = false;
				}
				else if (rand_int == 3)
				{
					h = "Black Panther";
					name = h;
					replace = false;
				}
			}

		}
	}
	else if (h == "villian")
	{
		
		while (replace)
		{
			srand(time(NULL));
			int rand_int = rand() % 8;
			if (rand_int == 0)
			{
				h = "Green Goblin";
				name = h;
				replace = false;
			}
			else if (rand_int == 1)
			{
				h = "Venom";
				name = h;
				replace = false;
			}
			else if (rand_int == 2)
			{
				h = "Red Skull";
				name = h;
				replace = false;
			}
			else if (rand_int == 3)
			{
				h = "Zemo";
				name = h;
				replace = false;
			}
			else if (rand_int == 4)
			{
				h = "Sabretooth";
				name = h;
				replace = false;
			}
			else if (rand_int == 5)
			{
				h = "Nitro";
				name = h;
				replace = false;
			}
			else if (rand_int == 6)
			{
				h = "Whiplash";
				name = h;
				replace = false;
			}
			else if (rand_int == 7)
			{
				h = "Titanium Man";
				name = h;
				replace = false;
			}
			

		}
	}
	else
	{
		name = h;
		//int rand_int = 0;
		/*switch (rand_int)
		{
		case 0:
			if (hero->get_hero() == "Spiderman" && hero->get_level() >= 3)
			{
				if (h == "Hulk")
				{
					name = h;
				}
				else if (h == "Iron Man")
				{
					name = h;
				}
				else if (h == "Ms. Marvel")
				{
					name = h;
				}
				else if (h == "Captain America")
				{
					name = h;
				}
				else if (h == "Mob Leader")
				{
					name = h;
				}
				else if (h == "Green Goblin")
				{
					name = h;
				}
				else if (h == "Venom")
				{
					name = h;
				}
				else if (h == "Zemo")
				{
					name = h;
				}
				else if (h == "Red Skull")
				{
					name = h;
				}
				else if (h == "Sabretooth")
				{
					name = h;
				}
				else if (h == "Nitro")
				{
					name = h;
				}
				else if (h == "Whiplash")
				{
					name = h;
				}
				else if (h == "Titanium Man")
				{
					name = h;
				}
				else
				{
					name = h;

				}

			}
			else if (hero->get_hero() == "Iron Man" && hero->get_level() >= 3)
			{
				if (h == "Hulk")
				{
					name = h;
				}
				else if (h == "Spiderman")
				{
					name = h;
				}
				else if (h == "Wolverine")
				{
					name = h;
				}
				else if (h == "Captain America")
				{
					name = h;
				}
				else if (h == "Mob Leader")
				{
					name = h;
				}
				else if (h == "Green Goblin")
				{
					name = h;
				}
				else if (h == "Venom")
				{
					name = h;
				}
				else if (h == "Zemo")
				{
					name = h;
				}
				else if (h == "Red Skull")
				{
					name = h;
				}
				else if (h == "Sabretooth")
				{
					name = h;
				}
				else if (h == "Nitro")
				{
					name = h;
				}
				else if (h == "Whiplash")
				{
					name = h;
				}
				else if (h == "Titanium Man")
				{
					name = h;
				}
				else
				{
					name = h;

				}

			}
			else if (hero->get_hero() == "Captain America" && hero->get_level() >= 3)
			{
				if (h == "Hulk")
				{
					name = h;
				}
				else if (h == "Spiderman")
				{
					name = h;
				}
				else if (h == "Iron Man")
				{
					name = h;
				}
				else if (h == "Wolverine")
				{
					name = h;
				}
				else if (h == "Mob Leader")
				{
					name = h;
				}
				else if (h == "Green Goblin")
				{
					name = h;
				}
				else if (h == "Venom")
				{
					name = h;
				}
				else if (h == "Zemo")
				{
					name = h;
				}
				else if (h == "Red Skull")
				{
					name = h;
				}
				else if (h == "Sabretooth")
				{
					name = h;
				}
				else if (h == "Nitro")
				{
					name = h;
				}
				else if (h == "Whiplash")
				{
					name = h;
				}
				else if (h == "Titanium Man")
				{
					name = h;
				}
				else
				{
					name = h;

				}

			}
			else if (hero->get_hero() == "Wolverine" && hero->get_level() >= 3)
			{
				if (h == "Hulk")
				{
					name = h;
				}
				else if (h == "Spiderman")
				{
					name = h;
				}
				else if (h == "Iron Man")
				{
					name = h;
				}
				else if (h == "Captain America")
				{
					name = h;
				}
				else if (h == "Mob Leader")
				{
					name = h;
				}
				else if (h == "Green Goblin")
				{
					name = h;
				}
				else if (h == "Venom")
				{
					name = h;
				}
				else if (h == "Zemo")
				{
					name = h;
				}
				else if (h == "Red Skull")
				{
					name = h;
				}
				else if (h == "Sabretooth")
				{
					name = h;
				}
				else if (h == "Nitro")
				{
					name = h;
				}
				else if (h == "Whiplash")
				{
					name = h;
				}
				else if (h == "Titanium Man")
				{
					name = h;
				}
				else
				{
					name = h;

				}



			}
			else
			{
				name = h;
			}

		case 1:
			name = h;

		}
		*/
	}
	
	set_enum(name);

}
string enemies::get_enemies()
{
	return name;
}

void enemies::set_enum(string h)
{
	if (h == "Hulk")
	{
		int_name = HULK;
	}
	else if (h == "Spiderman")
	{
		int_name = SPIDERMAN;
	}
	else if (h == "Iron Man")
	{
		int_name = IRON_MAN;
	}
	else if (h == "Captain America")
	{
		int_name = CAPTAIN_AMERICA;
	}
	else if (h == "Wolverine")
	{
		int_name = WOLVERINE;
	}
	else if (h == "Black Widow")
	{
		int_name = BLACK_WIDOW;
	}
	else if (h == "Black Panther")
	{
		int_name = BLACK_PANTHER;
	}
	else if (h == "Ms. Marvel")
	{
		int_name = MS_MARVEL;
	}
	else if (h == "Mr. Fantastic")
	{
		int_name = MR_FANTASTIC;
	}
	else if (h == "Green Goblin")
	{
		int_name = GREEN_GOBLIN;
	}
	else if (h == "Venom")
	{
		int_name = VENOM;
	}
	else if (h == "Zemo")
	{
		int_name = ZEMO;
	}
	else if (h == "Red Skull")
	{
		int_name = RED_SKULL;
	}
	else if (h == "Sabretooth")
	{
		int_name = SABRETOOTH;
	}
	else if (h == "Nitro")
	{
		int_name = NITRO;
	}
	else if (h == "Whiplash")
	{
		int_name = WHIPLASH;
	}
	else if (h == "Titanium Man")
	{
		int_name = TITANIUM_MAN;
	}
	else if (h == "Tri-Sentinel")
	{
		int_name = TRI_SENTINEL;
	}
	else if (h == "Magneto")
	{
		int_name = MAGNETO;
	}
	else if (h == "Stegron")
	{
		int_name = STEGRON;
	}
	else if (h == "Sauron")
	{
		int_name = SAURON;
	}
	else if (h == "Kingpin")
	{
		int_name = KINGPIN;
	}
	else if (h == "Iron Fist")
	{
		int_name = IRON_FIST;
	}
	else if (h == "Mister Sinister")
	{
		int_name = MISTER_SINISTER;
	}
	else if (h == "Callisto")
	{
		int_name = CALLISTO;
	}
	else if (h == "Dark Beast")
	{
		int_name = DARK_BEAST;
	}
	else if (h == "Caliban")
	{
		int_name = CALIBAN;
	}
	else if (h == "Blockbuster")
	{
		int_name = BLOCKBUSTER;
	}
	else if (h == "Lady Mastermind")
	{
		int_name = LADY_MASTERMIND;
	}
	else if (h == "Arclight")
	{
		int_name = ARCLIGHT;
	}
	else if (h == "Machine Man")
	{
		int_name = MACHINE_MAN;
	}
	else if (h == "Bastion")
	{
		int_name = BASTION;
	}
	else if (h == "Quicksilver")
	{
		int_name = QUICKSILVER;
	}
	else if (h == "Toad")
	{
		int_name = TOAD;
	}
	else if (h == "Scarlet Witch")
	{
		int_name = SCARLET_WITCH;
	}
	else if (h == "Daredevil")
	{
		int_name = DAREDEVIL;
	}
	else if (h == "Luke Cage")
	{
		int_name = LUKE_CAGE;
	}
	else if (h == "Marrow")
	{
		int_name = MARROW;
	}
	else if (h == "Doctor Octopus")
	{
		int_name = DOCTOR_OCTOPUS;
	}
	else if (h == "Powderkeg")
	{
		int_name = POWDERKEG;
	}
	else if (h == "Shocker")
	{
		int_name = SHOCKER;
	}
	else if (h == "Titania")
	{
		int_name = TITANIA;
	}
	else
	{
		int_name = 1000;
	}
}

int enemies::get_enum()
{
	return int_name;
}

void enemies::set_strenght(int i, player* hero)
{
	if (i != 0)
	{
		e_str += i;
	}
	else
	{
		if (name == "Iron Man")
		{
			e_str = 6 + e_lvl + i;
		}
		else if (name == "Spiderman")
		{
			e_str = 4 + e_lvl + i;
		}
		else if (name == "Wolverine")
		{
			e_str = 4 + e_lvl + i;
		}
		else if (name == "Captain America")
		{
			e_str = 3 + e_lvl + i;
		}
		else if (name == "Black Panther")
		{
			e_str = 4 + e_lvl + i;
		}
		else if (name == "Ms. Marvel")
		{
			e_str = 5 + e_lvl + i;
		}
		else if (name == "Black Widow")
		{
			e_str = 3 + e_lvl + i;
		}
		else if (name == "Mr. Fantastic")
		{
			e_str = 3 + e_lvl + i;
		}
		else if (name == "Hulk")
		{
			e_str = 7 + e_lvl + i;
		}
		else if (name == "Green Goblin")
		{
			e_str = 6 + e_lvl + i;
		}
		else if (name == "Venom")
		{
			e_str = 5 + e_lvl + i;
		}
		else if (name == "Zemo")
		{
			e_str = 4 + e_lvl + i;
		}
		else if (name == "Red Skull")
		{
			e_str = 3 + e_lvl + i;
		}
		else if (name == "Sabretooth")
		{
			e_str = 4 + e_lvl + i;
		}
		else if (name == "Nitro")
		{
			e_str = 5 + e_lvl + i;
		}
		else if (name == "Whiplash")
		{
			e_str = 2 + e_lvl + i;
		}
		else if (name == "Titanium Man")
		{
			e_str = 5 + e_lvl + i;
		}
		else if (name == "Marrow")
		{
			e_str = 3 + e_lvl + i;
		}
		else if (name == "Tri-Sentinel")
		{
			e_str = 6 + e_lvl + i;
		}
		else if (name == "Magneto")
		{
			e_str = 2 + e_lvl + i;
		}
		else if (name == "Stegron")
		{
			e_str = 4 + e_lvl + i;
		}
		else if (name == "Sauron")
		{
			e_str = 4 + e_lvl + i;
		}
		else if (name == "Kingpin")
		{
			e_str = 3 + e_lvl + i;
		}
		else if (name == "Iron Fist")
		{
			e_str = 2 + e_lvl + i;
		}
		else if (name == "Mister Sinister")
		{
			e_str = 4 + e_lvl + i;
		}
		else if (name == "Callisto")
		{
			e_str = 3 + e_lvl + i;
		}
		else if (name == "Dark Beast")
		{
			e_str = 4 + e_lvl + i;
		}
		else if (name == "Caliban")
		{
			e_str = 4 + e_lvl + i;
		}
		else if (name == "Blockbuster")
		{
			e_str = 6 + e_lvl + i;
		}
		else if (name == "Lady Mastermind")
		{
			e_str = 2 + e_lvl + i;
		}
		else if (name == "Arclight")
		{
			e_str = 5 + e_lvl + i;
		}
		else if (name == "Machine Man")
		{
			e_str = 4 + e_lvl + i;
		}
		else if (name == "Bastion")
		{
			e_str = 4 + e_lvl + i;
		}
		else if (name == "Quicksilver")
		{
			e_str = 4 + e_lvl + i;
		}
		else if (name == "Toad")
		{
			e_str = 4 + e_lvl + i;
		}
		else if (name == "Scarlet Witch")
		{
			e_str = 2 + e_lvl + i;
		}
		else if (name == "Daredevil")
		{
			e_str = 3 + e_lvl + i;
		}
		else if (name == "Luke Cage")
		{
			e_str = 4 + e_lvl + i;
		}
		else if (name == "Doctor Octopus")
		{
			e_str = 4 + e_lvl + i;
		}
		else if (name == "Powderkeg")
		{
			e_str = 3 + e_lvl + i;
		}
		else if (name == "Shocker")
		{
			e_str = 4 + e_lvl + i;
		}
		else if (name == "Titania")
		{
			e_str = 6 + e_lvl + i;
		}
		else if (name.substr(0, 4) == "Sent")
		{
			srand(time(NULL));
			int n = rand() % hero->get_strength();
			e_str = 6 + e_lvl + i + n;
		}
		else
		{
			srand(time(NULL));
			int n = rand() % hero->get_strength();
			if (name.substr(0, 4) == "Sent")
			{
				e_str = n + 6 + e_lvl;
			}
			else
			{
				if (n < hero->get_level())
				{
					n = hero->get_level();
				}
				e_str = (n-hero->get_level()) + 3 + e_lvl;
			}
		}
	}
	
}
int enemies::get_strength()
{
	return e_str;
}
void enemies::set_speed(int i)
{
		e_spd += i;
		if (e_spd < 0)
		{
			e_spd = 0;

		}
}
int enemies::get_speed()
{
	return e_spd;
}
void enemies::set_durability(int i, player* hero)
{
	bool same = true;
	if (i != 0)
	{
		e_dur += i;
	}
	else
	{
		if (name == "Marrow")
		{
			e_dur = 4 + e_lvl + i;
		}
		else if (name == "Tri-Sentinel")
		{
			e_dur = 6 + e_lvl + i;
		}
		else if (name == "Magneto")
		{
			e_dur = 2 + e_lvl + i;
		}
		else if (name == "Stegron")
		{
			e_dur = 5 + e_lvl + i;
		}
		else if (name == "Sauron")
		{
			e_dur = 3 + e_lvl + i;
		}
		else if (name == "Kingpin")
		{
			e_dur = 2 + e_lvl + i;
		}
		else if (name == "Iron Fist")
		{
			e_dur = 3 + e_lvl + i;
		}
		else if (name == "Mister Sinister")
		{
			e_dur = 7 + e_lvl + i;
		}
		else if (name == "Callisto")
		{
			e_dur = 3 + e_lvl + i;
		}
		else if (name == "Dark Beast")
		{
			e_dur = 4 + e_lvl + i;
		}
		else if (name == "Caliban")
		{
			e_dur = 3 + e_lvl + i;
		}
		else if (name == "Blockbuster")
		{
			e_dur = 6 + e_lvl + i;
		}
		else if (name == "Lady Mastermind")
		{
			e_dur = 2 + e_lvl + i;
		}
		else if (name == "Arclight")
		{
			e_dur = 3 + e_lvl + i;
		}
		else if (name == "Machine Man")
		{
			e_dur = 6 + e_lvl + i;
		}
		else if (name == "Bastion")
		{
			e_dur = 7 + e_lvl + i;
		}
		else if (name == "Quicksilver")
		{
			e_dur = 3 + e_lvl + i;
		}
		else if (name == "Toad")
		{
			e_dur = 3 + e_lvl + i;
		}
		else if (name == "Scarlet Witch")
		{
			e_dur = 2 + e_lvl + i;
		}
		else if (name == "Daredevil")
		{
			e_dur = 2 + e_lvl + i;
		}
		else if (name == "Luke Cage")
		{
			e_dur = 5 + e_lvl + i;
		}
		else if (name == "Doctor Octopus")
		{
			e_dur = 3 + e_lvl + i;
		}
		else if (name == "Powderkeg")
		{
			e_dur = 6 + e_lvl + i;
		}
		else if (name == "Shocker")
		{
			e_dur = 4 + e_lvl + i;
		}
		else if (name == "Titania")
		{
			e_dur = 5 + e_lvl + i;
		}
		else if (name == "Iron Man")
		{
			e_dur = 6 + e_lvl + i;
		}
		else if (name == "Spiderman")
		{
			e_dur = 3 + e_lvl + i;
		}
		else if (name == "Wolverine")
		{
			e_dur = 4 + e_lvl + i;
		}
		else if (name == "Captain America")
		{
			e_dur = 3 + e_lvl + i;
		}
		else if (name == "Black Panther")
		{
			e_dur = 3 + e_lvl + i;
		}
		else if (name == "Ms. Marvel")
		{
			e_dur = 4 + e_lvl + i;
		}
		else if (name == "Black Widow")
		{
			e_dur = 3 + e_lvl + i;
		}
		else if (name == "Mr. Fantastic")
		{
			e_dur = 6 + e_lvl + i;
		}
		else if (name == "Hulk")
		{
			e_dur = 7 + e_lvl + i;
		}
		else if (name == "Green Goblin")
		{
			e_dur = 6 + e_lvl + i;
		}
		else if (name == "Venom")
		{
			e_dur = 5 + e_lvl + i;
		}
		else if (name == "Zemo")
		{
			e_dur = 5 + e_lvl + i;
		}
		else if (name == "Red Skull")
		{
			e_dur = 3 + e_lvl + i;
		}
		else if (name == "Sabretooth")
		{
			e_dur = 4 + e_lvl + i;
		}
		else if (name == "Nitro")
		{
			e_dur = 5 + e_lvl + i;
		}
		else if (name == "Whiplash")
		{
			e_dur = 3 + e_lvl + i;
		}
		else if (name == "Titanium Man")
		{
			e_dur = 6 + e_lvl + i;
		}
		else
		{
			int n = -1;
			int i = 0;
			do
			{
				n = rand() % hero->get_durability();
				for (i; i < 15; i++)
				{
					if (rnd_prv[i] == -1)
					{
						rnd_prv[i] = n;
						same = false;
						break;
					}
					if (n == rnd_prv[i])
						break;
					if (i == 14)
					{
						reset_rnd();
						rnd_prv[0] = n;
						same = false;
					}
				}
			} while (same);
			std::cout << n << " n vale" << endl;
			if (name.substr(0, 4) != "Sent")
			{
				e_dur = n + 3 + e_lvl + i;
			}
			else
			{
				if (n < hero->get_level())
				{
					n = hero->get_level();
				}
				e_dur = (n - hero->get_level()) + 6 + e_lvl + i;
			}

		}
	}
	
}
int enemies::get_durability()
{
	return e_dur;
}
void enemies::set_Cskill(int i, player* hero)
{
	if (i != 0)
	{
		e_skill += i;
	}
	else
	{
		if (name == "Iron Man")
		{
			e_skill = 3 + e_lvl + i;
		}
		else if (name == "Spiderman")
		{
			e_skill = 5 + e_lvl + i;
		}
		else if (name == "Wolverine")
		{
			e_skill = 4 + e_lvl + i;
		}
		else if (name == "Captain America")
		{
			e_skill = 6 + e_lvl + i;
		}
		else if (name == "Black Panther")
		{
			e_skill = 6 + e_lvl + i;
		}
		else if (name == "Ms. Marvel")
		{
			e_skill = 4 + e_lvl + i;
		}
		else if (name == "Black Widow")
		{
			e_skill = 6 + e_lvl + i;
		}
		else if (name == "Mr. Fantastic")
		{
			e_skill = 2 + e_lvl + i;
		}
		else if (name == "Hulk")
		{
			e_skill = 5 + e_lvl + i;
		}
		else if (name == "Green Goblin")
		{
			e_skill = 3 + e_lvl + i;
		}
		else if (name == "Venom")
		{
			e_skill = 4 + e_lvl + i;
		}
		else if (name == "Zemo")
		{
			e_skill = 7 + e_lvl + i;
		}
		else if (name == "Red Skull")
		{
			e_skill = 5 + e_lvl + i;
		}
		else if (name == "Sabretooth")
		{
			e_skill = 7 + e_lvl + i;
		}
		else if (name == "Nitro")
		{
			e_skill = 6 + e_lvl + i;
		}
		else if (name == "Whiplash")
		{
			e_skill = 3 + e_lvl + i;
		}
		else if (name == "Titanium Man")
		{
			e_skill = 6 + e_lvl + i;
		}
		else if (name == "Marrow")
		{
			e_skill = 4 + e_lvl + i;
		}
		else if (name == "Tri-Sentinel")
		{
			e_skill = 2 + e_lvl + i;
		}
		else if (name == "Magneto")
		{
			e_skill = 4 + e_lvl + i;
		}
		else if (name == "Stegron")
		{
			e_skill = 2 + e_lvl + i;
		}
		else if (name == "Sauron")
		{
			e_skill = 3 + e_lvl + i;
		}
		else if (name == "Kingpin")
		{
			e_skill = 5 + e_lvl + i;
		}
		else if (name == "Iron Fist")
		{
			e_skill = 6 + e_lvl + i;
		}
		else if (name == "Mister Sinister")
		{
			e_skill = 4 + e_lvl + i;
		}
		else if (name == "Callisto")
		{
			e_skill = 6 + e_lvl + i;
		}
		else if (name == "Dark Beast")
		{
			e_skill = 3 + e_lvl + i;
		}
		else if (name == "Caliban")
		{
			e_skill = 3 + e_lvl + i;
		}
		else if (name == "Blockbuster")
		{
			e_skill = 4 + e_lvl + i;
		}
		else if (name == "Lady Mastermind")
		{
			e_skill = 4 + e_lvl + i;
		}
		else if (name == "Arclight")
		{
			e_skill = 4 + e_lvl + i;
		}
		else if (name == "Machine Man")
		{
			e_skill = 4 + e_lvl + i;
		}
		else if (name == "Bastion")
		{
			e_skill = 4 + e_lvl + i;
		}
		else if (name == "Quicksilver")
		{
			e_skill = 4 + e_lvl + i;
		}
		else if (name == "Toad")
		{
			e_skill = 3 + e_lvl + i;
		}
		else if (name == "Scarlet Witch")
		{
			e_skill = 3 + e_lvl + i;
		}
		else if (name == "Daredevil")
		{
			e_skill = 5 + e_lvl + i;
		}
		else if (name == "Luke Cage")
		{
			e_skill = 4 + e_lvl + i;
		}
		else if (name == "Doctor Octopus")
		{
			e_skill = 4 + e_lvl + i;
		}
		else if (name == "Powderkeg")
		{
			e_skill = 2 + e_lvl + i;
		}
		else if (name == "Shocker")
		{
			e_skill = 6 + e_lvl + i;
		}
		else if (name == "Titania")
		{
			e_skill = 4 + e_lvl + i;
		}
		else
		{
			int n = rand() % hero->get_Cskill();
			if (n < hero->get_level())
			{
				n = hero->get_level();
			}
			e_skill = (n - hero->get_level()) + 3 + e_lvl + i;
		}
	}
	
}
int enemies::get_Cskill()
{
	return e_skill;
}
void enemies::set_energy(int i, player* hero)
{
	if (i != 0)
	{
		e_energy += i;
	}
	else
	{
		if (name == "Iron Man")
		{
			e_energy = 6 + e_lvl + i;
		}
		else if (name == "Spiderman")
		{
			e_energy = 4 + e_lvl + i;
		}
		else if (name == "Wolverine")
		{
			e_energy = 1 + e_lvl + i;
		}
		else if (name == "Captain America")
		{
			e_energy = 1 + e_lvl + i;
		}
		else if (name == "Black Panther")
		{
			e_energy = 1 + e_lvl + i;
		}
		else if (name == "Ms. Marvel")
		{
			e_energy = 5 + e_lvl + i;
		}
		else if (name == "Black Widow")
		{
			e_energy = 3 + e_lvl + i;
		}
		else if (name == "Mr. Fantastic")
		{
			e_energy = 1 + e_lvl + i;
		}
		else if (name == "Hulk")
		{
			e_energy = 1 + e_lvl + i;
		}
		else if (name == "Green Goblin")
		{
			e_energy = 6 + e_lvl + i;
		}
		else if (name == "Venom")
		{
			e_energy = 3 + e_lvl + i;
		}
		else if (name == "Zemo")
		{
			e_energy = 7 + e_lvl + i;
		}
		else if (name == "Red Skull")
		{
			e_energy = 1 + e_lvl + i;
		}
		else if (name == "Sabretooth")
		{
			e_energy = 1 + e_lvl + i;
		}
		else if (name == "Nitro")
		{
			e_energy = 5 + e_lvl + i;
		}
		else if (name == "Whiplash")
		{
			e_energy = 4 + e_lvl + i;
		}
		else if (name == "Titanium Man")
		{
			e_energy = 6 + e_lvl + i;
		}
		else if (name == "Marrow")
		{
			e_energy = 1 + e_lvl + i;
		}
		else if (name == "Tri-Sentinel")
		{
			e_energy = 6 + e_lvl + i;
		}
		else if (name == "Magneto")
		{
			e_energy = 6 + e_lvl + i;
		}
		else if (name == "Stegron")
		{
			e_energy = 1 + e_lvl + i;
		}
		else if (name == "Sauron")
		{
			e_energy = 4 + e_lvl + i;
		}
		else if (name == "Kingpin")
		{
			e_energy = 1 + e_lvl + i;
		}
		else if (name == "Iron Fist")
		{
			e_energy = 3 + e_lvl + i;
		}
		else if (name == "Mister Sinister")
		{
			e_energy = 4 + e_lvl + i;
		}
		else if (name == "Callisto")
		{
			e_energy = 1 + e_lvl + i;
		}
		else if (name == "Dark Beast")
		{
			e_energy = 1 + e_lvl + i;
		}
		else if (name == "Caliban")
		{
			e_energy = 3 + e_lvl + i;
		}
		else if (name == "Blockbuster")
		{
			e_energy = 1 + e_lvl + i;
		}
		else if (name == "Lady Mastermind")
		{
			e_energy = 3 + e_lvl + i;
		}
		else if (name == "Arclight")
		{
			e_energy = 5 + e_lvl + i;
		}
		else if (name == "Machine Man")
		{
			e_energy = 6 + e_lvl + i;
		}
		else if (name == "Bastion")
		{
			e_energy = 4 + e_lvl + i;
		}
		else if (name == "Quicksilver")
		{
			e_energy = 1 + e_lvl + i;
		}
		else if (name == "Toad")
		{
			e_energy = 1 + e_lvl + i;
		}
		else if (name == "Scarlet Witch")
		{
			e_energy = 6 + e_lvl + i;
		}
		else if (name == "Daredevil")
		{
			e_energy = 4 + e_lvl + i;
		}
		else if (name == "Luke Cage")
		{
			e_energy = 1 + e_lvl + i;
		}
		else if (name == "Doctor Octopus")
		{
			e_energy = 1 + e_lvl + i;
		}
		else if (name == "Powderkeg")
		{
			e_energy = 2 + e_lvl + i;
		}
		else if (name == "Shocker")
		{
			e_energy = 6 + e_lvl + i;
		}
		else if (name == "Titania")
		{
			e_energy = 1 + e_lvl + i;
		}
		else
		{
			srand(time(NULL));
			int n = rand() % hero->get_energy();
			if (name.substr(0, 4) == "Sent" || name.substr(0, 4) == "Morl" || name.substr(0, 4) == "Muta")
			{
				e_energy = n + 5 + e_lvl + i;
			}
			else
			{
				if (n < hero->get_level())
				{
					n = hero->get_level();
				}
				e_energy = (n - hero->get_level()) + 3 + e_lvl + i;
			}
			
		}
		
	}
}
int enemies::get_energy()
{
	return e_energy;
}
void enemies::set_intelligence(int i, player* hero)
{
	if (i != 0)
	{
		e_intell += i;
	}
	else
	{
		if (name == "Iron Man")
		{
			e_intell = 6 + e_lvl + i;
		}
		else if (name == "Spiderman")
		{
			e_intell = 4 + e_lvl + i;
		}
		else if (name == "Wolverine")
		{
			e_intell = 2 + e_lvl + i;
		}
		else if (name == "Captain America")
		{
			e_intell = 4 + e_lvl + i;
		}
		else if (name == "Black Panther")
		{
			e_intell = 5 + e_lvl + i;
		}
		else if (name == "Ms. Marvel")
		{
			e_intell = 3 + e_lvl + i;
		}
		else if (name == "Black Widow")
		{
			e_intell = 3 + e_lvl + i;
		}
		else if (name == "Mr. Fantastic")
		{
			e_intell = 6 + e_lvl + i;
		}
		else if (name == "Hulk")
		{
			e_intell = 6 + e_lvl + i;
		}
		else if (name == "Green Goblin")
		{
			e_intell = 6 + e_lvl + i;
		}
		else if (name == "Venom")
		{
			e_intell = 4 + e_lvl + i;
		}
		else if (name == "Zemo")
		{
			e_intell = 5 + e_lvl + i;
		}
		else if (name == "Red Skull")
		{
			e_intell = 4 + e_lvl + i;
		}
		else if (name == "Sabretooth")
		{
			e_intell = 2 + e_lvl + i;
		}
		else if (name == "Nitro")
		{
			e_intell = 7 + e_lvl + i;
		}
		else if (name == "Whiplash")
		{
			e_intell = 4 + e_lvl + i;
		}
		else if (name == "Titanium Man")
		{
			e_intell = 5 + e_lvl + i;
		}
		else if (name == "Marrow")
		{
			e_intell = 2 + e_lvl + i;
		}
		else if (name == "Tri-Sentinel")
		{
			e_intell = 3 + e_lvl + i;
		}
		else if (name == "Magneto")
		{
			e_intell = 5 + e_lvl + i;
		}
		else if (name == "Stegron")
		{
			e_intell = 5 + e_lvl + i;
		}
		else if (name == "Sauron")
		{
			e_intell = 3 + e_lvl + i;
		}
		else if (name == "Kingpin")
		{
			e_intell = 3 + e_lvl + i;
		}
		else if (name == "Iron Fist")
		{
			e_intell = 3 + e_lvl + i;
		}
		else if (name == "Mister Sinister")
		{
			e_intell = 5 + e_lvl + i;
		}
		else if (name == "Callisto")
		{
			e_intell = 3 + e_lvl + i;
		}
		else if (name == "Dark Beast")
		{
			e_intell = 5 + e_lvl + i;
		}
		else if (name == "Caliban")
		{
			e_intell = 2 + e_lvl + i;
		}
		else if (name == "Blockbuster")
		{
			e_intell = 2 + e_lvl + i;
		}
		else if (name == "Lady Mastermind")
		{
			e_intell = 2 + e_lvl + i;
		}
		else if (name == "Arclight")
		{
			e_intell = 2 + e_lvl + i;
		}
		else if (name == "Machine Man")
		{
			e_intell = 4 + e_lvl + i;
		}
		else if (name == "Bastion")
		{
			e_intell = 5 + e_lvl + i;
		}
		else if (name == "Quicksilver")
		{
			e_intell = 3 + e_lvl + i;
		}
		else if (name == "Toad")
		{
			e_intell = 3 + e_lvl + i;
		}
		else if (name == "Scarlet Witch")
		{
			e_intell = 3 + e_lvl + i;
		}
		else if (name == "Daredevil")
		{
			e_intell = 3 + e_lvl + i;
		}
		else if (name == "Luke Cage")
		{
			e_intell = 3 + e_lvl + i;
		}
		else if (name == "Doctor Octopus")
		{
			e_intell = 5 + e_lvl + i;
		}
		else if (name == "Powderkeg")
		{
			e_intell = 2 + e_lvl + i;
		}
		else if (name == "Shocker")
		{
			e_intell = 4 + e_lvl + i;
		}
		else if (name == "Titania")
		{
			e_intell = 2 + e_lvl + i;
		}
		else
		{
			srand(time(NULL));
			int n = rand() % hero->get_intelligence();
			if (n < hero->get_level())
			{
				n = hero->get_level();
			}
			e_intell = (n - hero->get_level()) + 3 + e_lvl + i;
		}
	}
}
int enemies::get_intelligence()
{
	return e_intell;
}
void enemies::set_defense(int i)
{
	e_defe < 0 ? e_defe = 0 : e_defe += i; //use to be e_defe <= 0
}
int enemies::get_defense()
{
	int  j = 0;
	bool same = true;
	if (ko)
	{
		rnd_defe = 0;
	}
	else
	{
		do
		{
			rnd_defe = rand() % e_defe;
			for (j = 0; j < 15; j++)
			{
				if (rnd_prv2[j] == -1)
				{
					rnd_prv2[j] = rnd_defe;
					same = false;
					break;
				}
				if (rnd_defe == rnd_prv2[j])
					break;
				if (j == 14)
				{
					reset_rnd();
					rnd_prv2[0] = rnd_defe;
					same = false;
				}

			}
		} while (same);

	}
	std::cout << " Baddy defense: " << rnd_defe << endl;
	return rnd_defe;
}
void enemies::reset_defense()
{
	e_defe = 0;
}

void enemies::reset_rnd()
{
	for (int i = 0; i < 15; i++)
	{
		rnd_prv[i] = -1;
		rnd_prv2[i] = -1;
	}
}

void enemies::set_experience()
{
	if (name == "Iron Man" || name == "Spiderman" || name == "Wolverine" || name == "Captain America" || name == "Hulk" 
		|| name == "Mob Leader" || name == "Green Goblin" || name == "Venom" || name == "Zemo" || name == "Red Skull"
		|| name == "Sabretooth" || name == "Nitro" || name == "Whiplash" || name == "Titanium Man" || name == "Black Widow"
		|| name == "Black Panther" || name == "Ms. Marvel" || name == "Mr. Fantastic")
	{
		e_exp = e_lvl + ((e_str + e_skill + e_dur + e_spd) / 3) * 5;

	}
	else
	{
		e_exp = e_lvl + ((e_str + e_skill + e_dur + e_spd) / 3);
	}
}
int enemies::get_experience()
{
	return e_exp;
}
void enemies::set_health(int i)
{
	e_hlth += i;
	if (e_hlth < 0)
	{
		e_hlth = 0;
	}
	cout << e_hlth << " health\n";
}
int enemies::get_health()
{
	return e_hlth;
}
void enemies::set_level(player* h)
{
	if (name == "Civilian")
	{
		e_lvl = h->get_level();
	}
	else
	{
		int n = rand() % 3;
		e_lvl = h->get_level() + n + 1;
	}
}
int enemies::get_level()
{
	return e_lvl;
}

void enemies::set_item(string p_name)
{
	int number = rand() % 6;
	for (int i = 0; i < number; i++)
	{
		items[i] = new Equipment(e_lvl, p_name);
	}
}
Equipment** enemies::get_item()
{
	return items;
}

void enemies::set_attack(player* h, enemies* e) //do this: add attacks for mission mission bosses
/*Marrow, Tri-Sentinel, Magneto, Stegron, Sauron, Kingpin, Iron Fist, Mister Sinister, Callisto, Dark Beast, Caliban,
Blockbuster, Lady Mastermind, Arclight, Machine Man, Bastion, Quicksilver, Toad, Scarlet Witch, Daredevil, Luke Cage,
*/
{
	int a = rand() % 9;
	int b;
	if (int_name < NITRO || (int_name > NITRO && int_name < TRI_SENTINEL))
	{
		if (e_lvl >= 5 && e_lvl < 10)
		{
			b = rand() % 12;

		}
		else if (e_lvl >= 10 && e_lvl < 15)
		{
			b = rand() % 15;

		}
		else if (e_lvl >= 15 && e_lvl < 20)
		{
			b = rand() % 18;

		}
		else if (e_lvl >= 20)
		{
			b = rand() % 21;

		}
		else
		{
			b = rand() % 8;

		}
	}
	else if (int_name == TRI_SENTINEL || int_name == MAGNETO)
	{
		if (e_lvl >= 5 && e_lvl < 10)
		{
			b = rand() % 12;

		}
		else if (e_lvl >= 10)
		{
			b = rand() % 15;

		}
		else
		{
			b = rand() % 8;

		}
	}
	else if (int_name == HULK || int_name == NITRO)
	{
		b = rand() % 9;
	}
	switch (int_name)	//using enums to select attacker faster
	{
		case IRON_MAN:
		{
			if (a >= 0 && a < 3)
			{
				e_attack = a;
				cout << "Iron Man flys forward! BAM! He delieves a mighty punch!" << endl;
				e_power = " ";
				e_dmg = e_str + e_lvl;
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Iron Man rocket forward! He flips feet first and deals a powerful double Kick!" << endl;
				e_power = " ";
				e_dmg = e_spd + e_lvl;
				cout << name << " Deals ";
			}
			else if (a >= 6 && a < 9)
			{
				
				if (b >= 0 && b < 3)
				{
					srand(time(NULL));
					cout << "Iron Man's hands light up as he delivers a multiple Repulsor Rays!" << endl;
					e_power = "p";
					int rand_int = rand() % e_lvl;
					if (e_lvl >= 10)
					{
						rand_int = 10;
					}

					e_dmg = 0;
					for (int i = 0; i < rand_int; i++)
					{

						if (rand_int == 1)
						{
							e_dmg = (e_energy + e_skill);

						}
						else
						{
							cout << "Iron Man Continues to shoot!" << endl;
							e_dmg = e_dmg + (e_energy);


						}



					}
					if (rand_int > e_lvl - 2)
					{
						e_dmg = e_dmg * 2;

					}
					else
					{
						e_dmg = e_dmg;

					}

				}
				else if (b >= 3 && b < 6)
				{
					srand(time(NULL));

					cout << "Iron Man throws his arms back and unleases a power UniBeam from his core!" << endl;
					e_power = " ";
					int rand_int = rand() % e_energy;
					if (rand_int >= 9)
					{
						e_dmg = (e_energy + e_lvl + e_skill) * (rand_int);
					}
					else
					{
						e_dmg = (e_energy + e_lvl + e_skill) * 2;

					}

				}
				else if (b >= 6 && b < 9)
				{
					srand(time(NULL));
					int rand_int = rand() % 5;
					int rand_ints = rand() % 5;
					cout << "Tiny rocket launchers open up on Iron Man's shoulder!" << endl
						<< "He unleases a Missile Barrage, at " << h->get_hero() << "!" << endl;
					e_power = " ";
					if (h->get_defense() == 0)
					{
						h->set_defense(h->get_Cskill() + h->get_level() + h->get_speed() + rand_ints + 6);
					}
					h->set_defense(-rand_int);
					if (h->get_defense() <= e_defe)
					{
						h->set_defense_mod(1, e_power, 0);;
						cout << h->get_hero() << "'s defense have droped due to the explosion " << endl;
					}
					e_dmg = rand_int + e_skill + e_lvl + 1;

				}
				else if (b >= 9 && b < 12)
				{
					cout << "Iron Man flys forward and then boots upwards dealing a massive Rocket Uppercut!" << endl;
					e_power = " ";
					if (e_spd >= h->get_speed())
					{
						int modify = e_spd - h->get_speed();
						if (modify <= 1)
						{
							modify = 3;
						}
						e_dmg = (e_str + e_lvl + e_spd) *modify;
					}
					else
						e_dmg = (e_str + e_lvl + e_spd) * 2;

				}
				else if (b >= 12 && b < 15)
				{
					cout << "Iron Man charges up and unleases a burst of energy!" << endl;
					e_power = " ";
					srand(time(NULL));
					int rand_int = rand() % e_energy;
					e_dmg = e_energy * (rand_int + 1);
				}
				else if (b >= 15 && b < 18)
				{
					cout << "Iron Man unleases a swarm of nano bots to try and control the enemy!" << endl;
					e_power = "Nano Assault";
					e_dmg = 0;
				}
				else if (b >= 18 && b < 21)
				{
					cout << "A tiny slot opens up on Iron Man's wrist." << endl
						<< "He says 'Tank Missile'." << endl;
					e_power = " ";
					srand(time(NULL));
					int rand_int = rand() % (10 * e_energy);
					e_dmg = rand_int + 1;
					if (e_dmg <= 50)
					{
						e_dmg = 10 * e_energy;
					}
				}
			}
			break;
		}
		case SPIDERMAN:
		{
			if (a >= 0 && a < 3)
			{
				e_attack = a;
				cout << "Spiderman lunges forward with all this might! BAM! He delieves a mighty punch!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Spiderman Dashes forward! Jump left and right with great speed! He jumps and deals a powerful Kick!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 6 && a < 9)
			{
				if (b >= 0 && b < 3)
				{
					srand(time(NULL));
					cout << "Spiderman quickly does a double back flip, landing in a crouched position!" << endl;
					cout << "His hands quickly spurt back and forth as he delivers a" << endl << " sticky barrage of Web Balls!" << endl;
					int rand_int = rand() % 5;
					int rand_str = rand() % e_energy;
					e_dmg = (rand_int + 1) * 2;
					e_power = " ";
					if (h->get_strength() < (web_str + rand_str))
					{
						web_str += 1;
						if (h->get_speed() > 0)
						{
							h->set_speed(-2);
						}
						cout << endl << h->get_hero() << " speed decreases to " << h->get_speed() << endl;

					}
					else
					{
						if (web_str > e_lvl)
						{
							cout << h->get_hero() << " easily breaks the webbing! " << endl;

							h->set_speed(+2);
							web_str += -1;
						}
					}
					if (rand_int >= 3)
					{
						for (int i = rand() % 5; i <= e_lvl; i++)
						{
							if (i >= e_lvl)
							{

								break;

							}
							else
							{
								cout << "Spiderman continues to shoot!" << endl;
								std::system("pause");
								std::system("cls");
								int rand_int = rand() % 5;
								e_dmg = e_dmg + ((rand_int + e_skill));
								{
									if (e_dmg == 0)
									{
										e_dmg = e_dmg + (rand_int + e_skill) * 2;
									}
								}
								e_power = " ";
							}

						}
					}


				}
				else if (b >= 3 && b < 6)
				{
					srand(time(NULL));
					cout << "Spiderman jumps back and throws both is hands forward, a long continues sting of Web shoots out!" << endl;
					int rand_spd = rand() % e_spd;
					int rand_int = rand() % e_lvl;
					e_power = " ";

					e_dmg = 0;
					if (h->get_strength() < (web_str + rand_spd))
					{
						web_str += 1;
						if (h->get_speed() > 0)
						{
							h->set_speed(-rand_int);
						}
						cout << endl << h->get_hero() << " speed decreases to " << h->get_speed() << endl;

					}
					else
					{
						if (web_str > e_lvl)
						{
							cout << h->get_hero() << " easily breaks the webbing! " << endl;

							h->set_speed(+2);
							web_str += -1;
						}
					}
					cout << name << " Deals ";


				}
				else if (b >= 6 && b < 9)
				{
					cout << "Spiderman shoots webs onto the buildings near by!" << endl
						<< "He pulls back and flys forward like a Sling Shot!" << endl;
					srand(time(NULL));
					int rand_int = rand() % 10;
					e_power = "p";
					if (rand_int >= 8)
					{
						cout << "CRITICAL HIT!" << endl;
						e_dmg = (e_str + e_spd + rand_int + e_lvl + e_skill) * 2;

					}
					else
						e_dmg = e_str + e_spd + rand_int + e_lvl + e_skill;

				}
				else if (b >= 9 && b < 12)
				{
					cout << "Spiderman grabs a rock with his web." << endl
						<< " He spins around hitting all enemies with his Web Mace!" << endl;
					srand(time(NULL));
					e_power = "Web Mace";
					int rand_int = rand() % 10;
					e_dmg = e_str + e_spd + e_skill + rand_int + e_lvl;
				}
				else if (b >= 12 && b < 15)
				{
					cout << "Spiderman shoots out a string of web and grabs " << h->get_hero() << "!" << endl
						<< "He pulls yanks him forward and delivers a massive blow!" << endl;
					e_power = " ";
					int rand_ints = rand() % 10;
					if (rand_ints >= 7)
					{
						srand(time(NULL));
						int rand_int = rand() % 5;
						cout << "CRITICAL HIT!" << endl;
						e_dmg = (e_str + e_lvl + e_spd) * rand_int;

					}
					else
					{
						srand(time(NULL));
						int rand_int = rand() % 3;
						if (rand_int == 0)
						{
							rand_int = 1;
						}
						e_dmg = (e_str + e_lvl + e_spd) * rand_int;

					}


				}
				else if (b >= 15 && b < 18)
				{
					cout << "Spiderman shoots out and web and grabs " << h->get_hero() << "," << endl
						<< "and he throws his with all his might!" << endl;
					cout << h->get_hero() << " is to far way to attack!" << endl;
					e_power = " ";
					srand(time(NULL));
					int distance = rand() % 100 + 1;
					if (distance <= 20)
					{
						cout << h->get_hero() << " is to far way to attack!" << endl;

						h->set_defense_mod(1, e_power, 0);

					}


					srand(time(NULL));
					int rand_int = rand() % 5;
					e_dmg = (e_str + e_skill + e_spd) * (rand_int + 1);

				}
				else if (b >= 18)
				{
					cout << "Spiderman leaps into the air and shoots webs on the ground below him," << endl
						<< " he then pull the webs tight and speeds back to the ground!" << endl
						<< "BOOM! Dirt and web fly every where!" << endl;
					e_power = " ";
					srand(time(NULL));
					int rand_int = rand() % 5;
					int rand_str = rand() % e_str;
					if (h->get_strength() < (web_str + rand_str))
					{
						web_str += 1;
						if (h->get_speed() > 0)
						{
							h->set_speed(-rand_int);
						}
						cout << endl << h->get_hero() << " speed decreases to " << h->get_speed() << endl;

					}
					else
					{
						if (web_str > e_lvl)
						{
							cout << h->get_hero() << " easily breaks the webbing! " << endl;

							h->set_speed(+rand_int);
							web_str += -1;
						}
					}



					e_dmg = (e_str + e_spd + e_skill) * rand_int;



				}
			}
			break;
		}
		case WOLVERINE:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Wolverine drives his fist forward and deals a mighty punch, with a loud CLANK!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Wolverine runs forward and delivers a powerful  Kick!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 6 && a < 9)
			{
				if (b >= 0 && b < 3)
				{
					srand(time(NULL));
					cout << "Wolverine throws his claws out and slashes twice!" << endl;
					e_power = "Bleed";
					int rand_int = rand() % 4;
					e_dmg = (rand_int + e_str) * 2;
					bleed = e_dmg * .10;
				}
				else if (b >= 3 && b < 6)
				{
					srand(time(NULL));
					cout << "Wolverine Launches forward knocking back his enemy" << endl
						<< "Wolverine lands and brutally slashing his target!" << endl;
					e_power = "Bleed";
					if (h->get_strength() < e_str)
					{
						cout << "Wolverine keeps " << h->get_hero() << " pinned down!" << endl;
						h->set_defense_mod(1, e_power, 0);
					}
					int rand_int = rand() % 2;
					e_dmg = (e_str + e_spd) * (rand_int + 1);
					bleed = e_dmg * .10;

				}
				else if (b >= 6 && b < 9)
				{

					srand(time(NULL));
					cout << "Wolverine dashes forward and unleases a flurry of deadly slashes!" << endl;
					e_power = "Bleed";
					int rand_int = rand() % 4;
					e_dmg = (e_str + 5) * (rand_int + 1);
					bleed = e_dmg * .10;
				}
				else if (b >= 9 && b < 12)
				{
					srand(time(NULL));
					cout << "Wolverine stabbs his claws into his enemy," <<
						endl << " and pulls the his arms sideways!" << endl;
					e_power = "Bleed";
					int rand_int = rand() % 6;
					e_dmg = (e_str + (rand_int + 1)) * 3;
					bleed = e_dmg * .20;
					if (bleed_dmg >= (h->get_health() / 5))
					{
						cout << h->get_hero() << " is dizy from losing to much blood!" << endl;
						h->set_defense_mod(1, e_power, 0);
					}
				}
				else if (b >= 12 && b < 15)
				{
					srand(time(NULL));
					cout << "Wolverine delivers multiple slashing attacks with each hit increasing in his rage!" << endl;
					e_power = "Bleed";
					int rand_int = rand() % 3;
					e_dmg = (e_str + (rand_int + 1)) * 4;
					bleed = e_dmg * .10;
				}
				else if (b >= 15 && b < 18)
				{
					srand(time(NULL));
					cout << "Wolverine drives his claws deep into his enemy," << endl
						<< "picks them up and throws them to the side!" << endl;
					e_power = "Bleed";
					int rand_int = rand() % 10;
					e_dmg = (e_str + (rand_int + 1)) * 5;
					bleed = e_dmg * .10;
				}
				else if (b >= 18 && b < 21)
				{
					srand(time(NULL));
					cout << "Wolverine Impale the enemy on his claws, lift them up, and throw them down." << endl
						<< " He stabbs, attempting for an Instant Kill!" << endl;
					e_power = "Bleed";
					int kill = rand() % 10;
					if (kill >= 7)
					{
						cout << "Instant Kill!" << endl;
						h->max_hlth();
						e_dmg = h->get_max();
					}
					else
					{
						int rand_int = rand() % 10;
						e_dmg = (e_str  * (rand_int + 1)) * 2;
						bleed = e_dmg * .10;

					}
				}


			}
			break;
		}
		case CAPTAIN_AMERICA:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Captain America dealivers a mighty right hook!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Captain America quickly crouches down and delivers sweeping Kick!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 6 && a < 9)
			{
				if (b >= 0 && b < 3)
				{
					cout << "Captain America flips forward and hurls his mighty shield!" << endl;
					int rand_int;
					if (e_lvl <= 3)
					{
						srand(time(NULL));
						int rand_int = rand() % 10;
						int s_speed = rand() % 3;
						if (s_speed == 0)
						{
							s_speed = 1;

						}
						e_dmg = (rand_int + e_str) * s_speed;
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
						e_dmg = (rand_int + e_str) * s_speed;
					}
				}
				else if (b >= 3 && b < 6)
				{
					srand(time(NULL));

					cout << "Captina America swings his Shield with great strenght! " << endl;
					int rand_int = rand() % 10;
					int rand_ints = rand() % 5;
					if (h->get_defense() == 0)
					{
						h->set_defense(h->get_Cskill() + h->get_level() + h->get_speed() + rand_ints + 6);
					}
					h->set_defense(-rand_int);
					if (h->get_defense() < e_defe)
					{
						h->set_defense_mod(1, e_power, 0);
						cout << h->get_hero() << "'s defense have droped due to the massive blow!" << endl;
					}
					e_dmg = e_str * e_lvl;

				}
				else if (b >= 6 && b < 9)
				{

					srand(time(NULL));
					cout << "Captain America dashes forward with his Sheild in front!" << endl;
					int rand_int = rand() % 6;
					if (rand_int == 5)
					{
						e_dmg = ((e_spd + e_str) * 2) + rand_int;

					}
					else
					{
						e_dmg = e_spd + e_str + rand_int;
					}

				}
				else if (b >= 9 && b < 12)
				{
					cout << "Captain America dashes forward and swings his shield upwards!" << endl;
					srand(time(NULL));
					int rand_int = rand() % 5;
					if (rand_int > 3)
					{
						e_dmg = e_spd + e_str + e_skill * rand_int;
					}
					else
						e_dmg = e_spd + e_str + e_skill;
				}
				else if (b >= 12 && b < 15)
				{
					cout << "Captain America pulls out a Pistol and fires!" << endl;
					srand(time(NULL));
					int rand_int = rand() % e_lvl;
					if (rand_int == 0)
					{
						rand_int = e_lvl;
					}
					cout << rand_int << " shots!" << endl;
					e_dmg = rand_int * 5;
				}
				else if (b >= 15 && b < 18)
				{
					cout << "Captain America finds a Grenade and throws it!" << endl;
					srand(time(NULL));
					int rand_int = rand() % 5;
					if (rand_int == 0)
					{
						cout << "Black Hole Grenade, " << h->get_hero() << " is sucked into the void!" << endl;
						h->max_hlth();
						e_dmg = h->get_max();
					}
					else if (rand_int == 1)
					{
						srand(time(NULL));
						int rand_ints = rand() % 5;
						cout << "Dendrotoxin Grenade!" << endl;
						if (rand_ints == 0)
						{
							rand_ints = 10;
						}
						e_dmg = rand_ints * e_skill;
					}
					else if (rand_int == 2)
					{
						cout << "Gas Grenade, " << h->get_hero() << " falls asleep!" << endl;
						h->set_defense_mod(1, e_power, 0);
						e_dmg = 0;
					}
					else if (rand_int == 3)
					{
						cout << "Dud!" << endl;
						e_dmg = 0;
					}
					else
					{
						cout << "Hand Grenade!" << endl;
						e_dmg = e_lvl * rand_int;
					}
				}
				else if (b >= 18 && b < 21)
				{
					cout << "Captain America digs deep and finds reserve strength." << endl
						<< "He SLAMS his shield into " << h->get_hero() << " head!" << endl;
					srand(time(NULL));
					int rand_int = rand() % (e_skill + 10);
					if (e_skill > rand_int)
					{
						cout << "Instant kill!" << endl;
						h->max_hlth();
						e_dmg = h->get_max();
					}
					else
					{
						e_dmg = h->get_health() / rand_int;
						if (e_dmg <= 0)
						{
							e_dmg = rand_int;
						}
					}
				}


			}
			break;
		}
		case BLACK_WIDOW:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Black Widow dealivers a stratigic kidney punch!" << endl;
				e_power = "p";
				if (e_spd >= (h->get_speed() - h->get_level()) + e_lvl)
				{
					e_dmg = 0;
					for (int i = 0; i < (e_spd - (h->get_speed() - h->get_level())); i++)
					{
						cout << "Black Widow punches again!" << endl;
						e_dmg = e_dmg + e_str + e_lvl;

					}
					if (e_skill >= h->get_Cskill())
					{
						cout << "Critical Hit!" << endl;

						e_dmg = e_dmg * 2;
					}
				}
				else if (e_skill >= h->get_Cskill())
				{
					cout << "Black Widow uses her Combat Skills to increase her damage!" << endl;

					e_dmg = (e_str + e_lvl) * 2;
				}
				else
				{
					e_dmg = e_str + e_lvl;
				}
				cout << "She Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Black Widow delivers a crippling blow to the her enemies knee!" << endl;
				e_power = "p";
				if (e_spd >= (h->get_speed() - h->get_level()) + e_lvl)
				{
					e_dmg = e_spd + e_lvl;
					for (int i = 0; i < (e_spd - (h->get_speed() - h->get_level())); i++)
					{
						cout << "Black Widow Kicks again!" << endl;

						e_dmg = e_dmg + e_spd + e_lvl;

					}
					if (e_skill >= h->get_Cskill())
					{
						cout << "Critical Hit!" << endl;
						e_dmg = e_dmg * 2;
					}
				}
				else if (e_skill >= h->get_Cskill())
				{
					cout << "Black Widow uses her Combat Skills to increase her damage!" << endl;
					e_dmg = (e_spd + e_lvl) * 2;
				}
				else
				{
					e_dmg = e_spd + e_lvl;
				}
				cout << "She Deals ";
			}
			else if (a >= 6 && a < 9)
			{
				if (b >= 0 && b < 3)
				{
					cout << "Black Widow raises her arm and uleashes a volley of Widow's Bite!" << endl;
					e_power = "Widow's Bite";
					srand(time(NULL));
					e_dmg = 0;
					int rand_shock = rand() % e_energy;
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
						e_dmg = e_dmg + (rand_shock + e_energy);
					}
					h->set_defense_mod(1, e_power, 0);
					cout << h->get_hero() << " is stunned from the electricity!" << endl;
				}
				else if (b >= 3 && b < 6)
				{
					srand(time(NULL));
					int rand_ints = rand() % 5;

					cout << "Black Widow pulls out two pistols and fires!" << endl;
					e_power = "p";
					int rand_int = rand() % e_skill;
					int count = 0;
					e_dmg = 0;
					for (int i = 0; i < rand_int; i++)
					{
						e_dmg += 2;
						count++;
						if (count == 12 && rand_int > 12)
						{
							cout << "Black Widow reloads and continues shooting!" << endl;
							while (count != 0)
							{
								count--;
							}
						}
					}
					if (e_dmg == 0)
					{
						cout << "The Gun jams and won't fire!" << endl;
					}
				}
				else if (b >= 6 && b < 9)
				{
					cout << "Black Widow shoots tear gas cartridges from her bracelets!" << endl;
					e_power = "Tear Gas";
					e_dmg = 0;
					h->set_defense_mod(1, e_power, 0);
					cout << h->get_hero() << " is unable to see due to the tear gas!" << endl;

				}
				else if (b >= 9 && b < 12)
				{
					cout << "Black Widow pulls out a garrote wire and wraps it around " << h->get_hero() << " neck!" << endl;
					e_power = "p";
					srand(time(NULL));
					int rand_str = rand() % (e_skill + e_str);
					int rand_e_str = rand() % (h->get_strength() + h->get_Cskill());
					int passout = 0;
					e_dmg = e_str + e_skill + rand_str;
					if (rand_str > rand_e_str)
					{
						while (rand_str > rand_e_str)
						{
							passout++;
							e_dmg += 3;
							srand(time(NULL));
							rand_str = rand() % (e_skill + e_str);
							rand_e_str = rand() % (h->get_strength() + h->get_Cskill());
							if (passout > h->get_durability())
							{
								cout << h->get_hero() << " blacks out!" << endl;
								e_dmg += passout;
								h->set_defense_mod(1, e_power, 0);
								break;
							}
						}
					}
					else
					{
						cout << h->get_hero() << " escapes from the garrote!" << endl;
						if (e_spd > h->get_speed() && e_skill > h->get_Cskill())
						{
							cout << "Black Widow quickly spins around and unleashes a flurry of deadly punches!" << endl;
							for (int i = 0; i < e_skill; i++)
							{
								e_dmg = e_skill;
							}
						}
						else if (e_spd > h->get_speed())
						{
							cout << "Black Widow quickly spins around and unleashes a burst of jabs!" << endl;
							for (int i = 0; i < e_spd; i++)
							{
								e_dmg = e_str;
							}
						}
					}
				}
				else if (b >= 12 && b < 15)
				{
					cout << "Black Widow quickly spins around and delievers a powerful round house kick!" << endl;
					e_power = "p";
					srand(time(NULL));
					int rand_spd = rand() % e_spd;
					int rand_e_spd = rand() % h->get_speed();
					rand_spd += e_spd;
					rand_e_spd += h->get_speed();
					e_dmg = e_spd * e_str;
					if (rand_spd >= rand_e_spd)
					{
						if (e_skill >= h->get_Cskill())
						{
							cout << "Black Widow follows with a second powerful round house kick!" << endl;
							e_dmg *= 2;
						}
						else
						{
							cout << "Black Widow follows with a powerful uppercut!" << endl;
							e_dmg += (e_dmg / 2);
						}
					}
					else if (e_skill >= h->get_Cskill())
					{

						cout << "Black Widow follows with a flurry of punches!" << endl;
						for (int i = 0; i < (e_skill - h->get_Cskill()); i++)
						{
							e_dmg += e_str;
						}
					}
				}
				else if (b >= 15 && b < 18)
				{
					cout << "Black Widow jumps onto " << h->get_hero() << " flips them onto the floor and starts a beat down!" << endl;
					e_power = "p";
					srand(time(NULL));
					int rand_e_dur = rand() % h->get_durability();
					if (rand_e_dur == 0)
					{
						rand_e_dur = e_skill;
					}
					else if (rand_e_dur < e_lvl)
					{
						rand_e_dur = e_lvl + (e_lvl / 4);
					}
					int rand_e_skill = rand() % e_skill;
					int rand_e_str = rand() % e_str;
					rand_e_skill += e_skill;
					rand_e_str += h->get_strength();
					e_dmg = 0;
					for (int i = e_lvl; i < rand_e_dur; i++)
					{
						int rand_attack = rand() % 5;
						if (rand_attack == 0)
						{
							cout << "Black Widow punches " << h->get_hero() << " in the face!" << endl;
							e_dmg += e_str;
						}
						else if (rand_attack == 1)
						{
							cout << "Black Widow knees " << h->get_hero() << " in the ribs!" << endl;
							e_dmg += e_str + e_spd;
						}
						else if (rand_attack == 2)
						{
							cout << "Black Widow knees " << h->get_hero() << " in the groin!" << endl;
							e_dmg += e_str + e_skill;
						}
						else if (rand_attack == 3)
						{
							cout << "Black Widow elbows " << h->get_hero() << " in the face!" << endl;
							e_dmg += e_str + e_str + e_spd;
						}
						else
						{
							cout << "Black Widow headbutts " << h->get_hero() << endl;
							e_dmg += e_str + e_spd + e_skill + e_dur;
						}
						system("pause");
						system("cls");
					}
					if (rand_e_skill > rand_e_str)
					{
						srand(time(NULL));
						rand_e_dur = rand() % h->get_durability();
						if (rand_e_dur == 0)
						{
							rand_e_dur = 1;
						}
						else if (rand_e_dur < e_lvl)
						{
							rand_e_dur = e_lvl + (e_lvl / 4);
						}
						cout << h->get_hero() << " tries to push Black Widow off but fails!" << endl
							<< "Black Widow continues the assault!" << endl;
						for (int i = e_lvl; i < rand_e_dur; i++)
						{
							int rand_attack = rand() % 5;
							if (rand_attack == 0)
							{
								cout << "Black Widow punches " << h->get_hero() << " in the face!" << endl;
								e_dmg += e_str;
							}
							else if (rand_attack == 1)
							{
								cout << "Black Widow knees " << h->get_hero() << " in the ribs!" << endl;
								e_dmg += e_str + e_spd;
							}
							else if (rand_attack == 2)
							{
								cout << "Black Widow knees " << h->get_hero() << " in the groin!" << endl;
								e_dmg += e_str + e_skill;
							}
							else if (rand_attack == 3)
							{
								cout << "Black Widow elbows " << h->get_hero() << " in the face!" << endl;
								e_dmg += e_str + e_str + e_spd;
							}
							else
							{
								cout << "Black Widow headbutts " << h->get_hero() << endl;
								e_dmg += e_str + e_spd + e_skill + e_dur;
							}
							system("pause");
							system("cls");
						}

					}
					else if (e_dmg > (h->get_health() / 4))
					{
						h->set_defense_mod(1, e_power, 0);
						cout << h->get_hero() << " blacks out from the assault!" << endl;
					}
				}
				else if (b >= 18 && b < 21)
				{
					cout << "Black Widow charges " << h->get_hero() << " and unleases an onslaught of attacks!" << endl;
					e_power = "p";
					e_dmg = 0;
					int dmg_attack = 0;
					for (int i = 0; i < (e_skill + h->get_durability()); i++)
					{
						srand(time(NULL));
						int rand_int = rand() % 8;
						int rand_hit = rand() % e_skill;
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
							cout << "Black Widow smashes " << h->get_hero() << "'s face into a wall!" << endl;
							dmg_attack = e_str + e_skill + rand_hit;
							cout << dmg_attack << " Damage!" << endl;
							e_dmg += dmg_attack;
						}
						else if (rand_int == 1)
						{
							cout << "Black Widow punches " << h->get_hero() << " " << rand_hit << " times in the face!" << endl;
							e_dmg += (e_str * rand_hit);
							cout << dmg_attack << " Damage!" << endl;
							e_dmg += dmg_attack;
						}
						else if (rand_int == 2)
						{
							cout << "Black Widow slames her fist into " << h->get_hero() << " ribs " << rand_hit << endl
								<< " times and breaks " << rand_rib << " ribs!" << endl;
							dmg_attack = (e_str * rand_rib) + (h->get_durability() - rand_rib);
							cout << dmg_attack << " Damage!" << endl;
							e_dmg += dmg_attack;
						}
						else if (rand_int == 3)
						{
							cout << "Black Widow spins around and kicks " << h->get_hero() << "'s knee caps!" << endl;
							if (e_dmg >= h->get_durability())
							{
								cout << "The impact breaks " << h->get_hero() << "'s knee!" << endl;
								h->set_defense_mod(1, e_power, 0);
							}
							dmg_attack = e_spd + h->get_durability();
							cout << dmg_attack << " Damage!" << endl;
							e_dmg += dmg_attack;
						}
						else if (rand_int == 4)
						{
							cout << "Black Widow manages to get behind " << h->get_hero() << " and places him in a choke hold!" << endl;
							srand(time(NULL));
							int rand_choke = rand() % (e_str + e_skill);
							dmg_attack = (e_str * rand_hit) + e_skill;
							cout << dmg_attack << " Damage!" << endl;
							e_dmg += dmg_attack;
							if (rand_choke > h->get_durability())
							{
								cout << "Black Widow's choke hold causes " << h->get_hero() << " to black out!" << endl;
								h->set_defense_mod(1, e_power, 0);
								break;
							}
						}
						else if (rand_int == 7)
						{
							cout << "Black Widow grabs " << h->get_hero() << "'s head and tries to snap his neck!" << endl;
							if (h->get_hero() == "Wolverine")
							{
								cout << "Wolverine laughs and says 'Look lady, my neck will not brake'" << endl;
								cout << "Black Widow responds' Your right, thats why i placed a C-4 in your pocket.'" << endl
									<< "Black Widow releases Wolverine and dives for cover." << endl << "BOOOOMMM!!!!" << endl;
								if (e_dmg < (h->get_health() / 2))
								{
									e_dmg = (h->get_health() / 2);
								}
								else
								{
									dmg_attack = (h->get_health() / 4);
									cout << dmg_attack << " Damage!" << endl;
									e_dmg += dmg_attack;
								}
								break;
							}
							else if ((e_dmg + e_str) > (h->get_durability() + h->get_defense()))
							{
								cout << "With one swift motion Black Widow snaps " << h->get_hero() << "'s neck!" << endl;
								h->max_hlth();
								e_dmg = h->get_max();
								break;
							}
							else
							{
								cout << h->get_hero() << " breaks free befor Black Widow can snap his neck!" << endl;
							}
						}
						else
						{
							cout << "Black Widow unleases a flurry of punch and kicks at " << h->get_hero() << "!" << endl;
							dmg_attack = e_str + e_spd;
							cout << dmg_attack << " Damage!" << endl;
							e_dmg += dmg_attack;

						}
						system("pause");
						system("cls");
					}
				}


			}
			break;
		}
		case BLACK_PANTHER:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Black Panther ducks and throws a might punch!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Black Panther crouches down and strikes with a swift kick!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 6 && a < 9)
			{
				if (b >= 0 && b < 3)
				{
					cout << "Black Panther dashes forward and deleivers two deadly slashes to " << h->get_hero() << "!" << endl;
					e_power = "p";
					srand(time(NULL));
					int rand_int = rand() % e_lvl;
					e_dmg = (rand_int + e_str + e_spd) * 2;
				}
				else if (b >= 3 && b < 6)
				{
					srand(time(NULL));
					int rand_ints = rand() % 5;

					cout << "Black Panther flips backwards and unleases a volly of energy daggers!" << endl;
					e_power = "Energy Daggers";
					int rand_int = rand() % (e_skill + e_str);
					if (rand_int >((e_skill + e_str) / 2))
					{
						e_dmg = (e_lvl + e_skill + e_str) * 2;
					}
					else
					{
						e_dmg = (e_lvl + e_skill + e_str + rand_int);
					}
				}
				else if (b >= 6 && b < 9)
				{

					srand(time(NULL));
					cout << "Black Panther runs forward, jumps and spins as daggers slash at anyone near him!" << endl;
					e_power = "Razor Cyclone";
					int rand_int = rand() % 6;
					if (rand_int == 5)
					{
						e_dmg = ((e_spd + e_str) * 2) + rand_int;

					}
					else
					{
						e_dmg = e_spd + e_str + rand_int + e_skill;
					}

				}
				else if (b >= 9 && b < 12)
				{
					cout << "Black Panther dashes forward and slashes with his claws!" << endl;
					e_power = "p";
					srand(time(NULL));
					int rand_int = rand() % 6;
					if (rand_int > 3)
					{
						cout << "Black Panther hits a vital spot! CRITICAL HIT!" << endl;
						e_dmg = (e_spd + e_str + e_skill) * rand_int;
					}
					else
						e_dmg = e_spd + e_str + e_skill;
				}
				else if (b >= 12 && b < 15)
				{
					cout << "Black Panther leaps into the air and lands on " << h->get_hero() << "!" << endl;
					e_power = "p";
					srand(time(NULL));
					int rand_slash = rand() % e_lvl;
					if (rand_slash == 0)
					{
						rand_slash = 1;
					}
					if (e_str <= h->get_strength())
					{
						cout << "Black Panther keeps " << h->get_hero() << " pinned down!" << endl;
						h->set_defense_mod(1, e_power, 0);
					}

					cout << "Black Panther slashes " << rand_slash << " times!" << endl;
					e_dmg = (e_str + e_skill) * rand_slash;
				}
				else if (b >= 15 && b < 18)
				{
					cout << "Black Panther becomes invisible and goes in for a sneak attack!" << endl;
					e_power = "p";
					srand(time(NULL));
					e_defe = e_defe * 2;
					int rand_int = rand() % e_lvl;
					if (rand_int >(e_lvl / 2))
					{
						cout << "CRITICAL HIT!" << endl;
						e_dmg = e_str * rand_int;
					}
					else
					{
						e_dmg = e_str + e_defe;
						if (e_dmg < e_lvl)
						{
							e_dmg = e_lvl;
						}
					}
				}
				else if (b >= 18 && b < 21)
				{
					cout << "Black Panther leaps into the air and slams down on " << h->get_hero() << "!" << endl;
					e_power = "p";
					srand(time(NULL));
					int rand_int = rand() % (e_skill + 10);
					if (e_skill > rand_int)
					{
						cout << "Instant kill!" << endl;
						h->max_hlth();
						e_dmg = h->get_max();
					}
					else
					{
						e_dmg = h->get_health() / rand_int;
						if (e_dmg <= 0)
						{
							e_dmg = rand_int;
						}
					}
				}


			}
			break;
		}
		case MS_MARVEL:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Ms. Marvel dealivers a devistating punch!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Ms. Marvel Swoops down and kicks with all her might!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 6 && a < 9)
			{
				if (b >= 0 && b < 3)
				{
					cout << "Ms. Marvel's hands glow as she blast energy at " << h->get_hero() << "!" << endl;
					e_power = "p";
					srand(time(NULL));
					int rand_int = rand() % e_energy;

					h->set_durability(+rand_int);
					h->max_hlth();
					int max_health = h->get_max() - h->get_health();
					h->set_durability(-rand_int);
					h->max_hlth();
					while (h->get_health() != 0)
					{
						h->set_health(-1);
					}
					h->set_health(+h->get_max());
					h->set_health(-max_health);
					e_dmg = (rand_int + e_energy + e_skill);
				}
				else if (b >= 3 && b < 6)
				{
					srand(time(NULL));
					int rand_ints = rand() % 5;

					cout << "Ms. Marvel's hands glow as she blast energy all around her!" << endl;
					e_power = "Photon Burst";
					int rand_int = rand() % (e_energy + e_energy);
					if (rand_int > e_energy)
					{
						e_dmg = (e_lvl + e_skill + e_energy) * 2;
					}
					else
					{
						e_dmg = (e_lvl + e_skill + e_energy + rand_int);
					}
				}
				else if (b >= 6 && b < 9)
				{

					srand(time(NULL));
					cout << "Ms. Marvel runs forward and grabs " << h->get_hero() << "!" << endl;
					cout << "Her hands glow as she charges " << h->get_hero() << " with energy!" << endl;
					e_power = "Explosive Touch";
					e_dmg = e_energy;

				}
				else if (b >= 9 && b < 12)
				{
					cout << "Ms. Marvel fires a blast of energy into the ground!" << endl;
					e_power = "Mega Blast";
					srand(time(NULL));
					int rand_int = rand() % (e_energy * 2);
					e_dmg = rand_int + e_energy + e_skill;
				}
				else if (b >= 12 && b < 15)
				{
					cout << "Ms. Marvel shoots a focused beam of energy at " << h->get_hero() << "!" << endl;
					e_power = "Prism";
					srand(time(NULL));
					int rand_slash = rand() % e_energy;
					int strength_sap = (h->get_strength() / 4);
					if (rand_slash == 0)
					{
						cout << h->get_hero() << "'s Strength has been sapped due to the energy!" << endl;
						cout << h->get_hero() << "'s Strenght drops by " << strength_sap << "!" << endl;
						h->set_strenght(-strength_sap);
						cout << h->get_hero() << "'s Strength is now " << h->get_strength() << "." << endl;
						rand_slash = 1;
					}
					e_dmg = (e_energy + e_skill) * rand_slash;
				}
				else if (b >= 15 && b < 18)
				{
					cout << "Ms. Marvel flies forward delivering a massive blow!" << endl;
					e_power = "p";
					srand(time(NULL));
					int rand_int = rand() % e_lvl;
					if (rand_int >(e_lvl / 2))
					{
						cout << "The blow renders " << h->get_hero() << " stunned!" << endl;
						h->set_defense_mod(1, e_power, 0);
					}
					if (e_skill > h->get_Cskill())
					{
						cout << "Ms. Marvel Continues his assault!" << endl;
						int extra_dmg = e_skill - h->get_Cskill();
						if (extra_dmg <= 1)
						{
							extra_dmg = 2;
						}
						e_dmg = (e_str + e_spd + e_skill + rand_int + e_lvl) * extra_dmg;
					}
					else
					{
						e_dmg = (e_str + e_spd + e_skill + rand_int + e_lvl);
					}
				}
				else if (b >= 18 && b < 21)
				{
					cout << "Ms. Marvel flies into the air and slams into the ground!" << endl;
					e_power = "Cosmic Slam";
					srand(time(NULL));
					int rand_int = rand() % (e_str + e_spd);
					if (rand_int == 0)
					{
						rand_int = 1;
					}

					e_dmg = e_str * e_spd * rand_int;
				}


			}
			break;
		}
		case MR_FANTASTIC:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Mr. Fantastic slings his arm out to deliver a strong punch!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Mr. Fantastic stretches his leg out and whips it around!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 6 && a < 9)
			{
				if (b >= 0 && b < 3)
				{
					cout << "Mr. Fantastic's arm spin in a circle creating a protective barrier!" << endl;
					e_power = "p";
					srand(time(NULL));
					int rand_int = rand() % e_lvl;
					int protection = rand() % e_lvl + e_spd;
					e_defe = e_defe + (e_spd + protection);
					e_dmg = (rand_int + e_str + e_spd);
				}
				else if (b >= 3 && b < 6)
				{
					srand(time(NULL));
					int rand_ints = rand() % 5;

					cout << "Mr. Fantastic extends his arm and whips it at " << h->get_hero() << "!" << endl;
					e_power = "p";
					int rand_int = rand() % (e_skill + e_str);
					e_dmg = rand_int + e_lvl + e_spd;
					if (rand_int > h->get_speed())
					{
						cout << "Mr. Fantastic pops " << h->get_hero() << " into the air!" << endl;
						cout << "He then slams his arm into " << h->get_hero() << " slamming them into the ground!" << endl;
						e_dmg = e_dmg * 2;
					}
					if (e_dmg > (h->get_health() * .25))
					{
						cout << h->get_hero() << " is stunned from the attack!" << endl;
						h->set_defense_mod(1, e_power, 0);
					}
				}
				else if (b >= 6 && b < 9)
				{
					srand(time(NULL));
					cout << "Mr. Fantastic runs forward and grabs his anckles turning himself into a wheel!" << endl;
					cout << "He rolls and slams into " << h->get_hero() << " with great force!" << endl;
					e_power = "p";
					int momentum = rand() % (e_spd + e_lvl);
					momentum++;
					e_dmg = e_lvl + e_spd + e_str;
					if (momentum > e_lvl && momentum > e_spd)
					{
						cout << "CRITICAL HIT! Mr. Fantastic crushes " << h->get_hero() << " with his body!" << endl;
						e_dmg += (e_dur * 2);
						cout << h->get_hero() << " is stunned from the attack!" << endl;
						h->set_defense_mod(1, e_power, 0);
					}
					else if (momentum > e_lvl || momentum > e_spd)
					{
						cout << h->get_hero() << " is stunned from the attack!" << endl;
						h->set_defense_mod(1, e_power, 0);
					}

				}
				else if (b >= 9 && b < 12)
				{
					cout << "Mr. Fantastic rolls up into a ball and starts slamming into his enemies!" << endl;
					e_power = "Pin Ball";
					srand(time(NULL));
					int rand_int = rand() % (e_lvl + e_dur);
					srand(time(NULL));
					int momentum = rand() % (h->get_speed() + h->get_Cskill());
					momentum++;
					int balance = rand() % (e_skill + e_lvl);
					if (momentum >= balance)
					{
						h->set_defense_mod(1, e_power, 0);
						std::cout << h->get_hero() << " is knocked down from the attack!" << endl;
					}
					e_dmg = rand_int + e_str + e_skill + e_spd + e_dur;
				}
				else if (b >= 12 && b < 15)
				{
					cout << "Mr. Fantastic extends his arm and swings it forward at " << h->get_hero() << " with great might!" << endl;
					e_power = "p";
					srand(time(NULL));
					int rand_spd = rand() % (e_defe + e_spd);
					int rand_e_spd = rand() % (h->get_speed() + h->get_defense());
					e_dmg = e_str + e_spd + e_skill + rand_spd;
					if (rand_spd > rand_e_spd || (rand_e_spd == 0 && rand_spd > 0))
					{
						cout << "CRITICAL HIT!" << endl;
						e_dmg = e_dmg * 2;
					}
				}
				else if (b >= 15 && b < 18)
				{
					cout << "Mr. Fantastic extends his arms and whips them into the ground!" << endl;
					e_power = "Elastic Smash";
					srand(time(NULL));
					int rand_int = rand() % e_lvl;
					if (rand_int > 5)
					{
						rand_int = 5;
					}
					if (rand_int == 0)
					{
						rand_int = 6;
					}
					e_dmg = (e_spd + e_str) * rand_int;
					srand(time(NULL));
					int hit_speed = rand() % (h->get_speed() + h->get_strength());
					int protect = rand() % e_defe;
					if (hit_speed >= protect)
					{
						h->set_defense_mod(1, e_power, 0);
						std::cout << h->get_hero() << " is stunned from the attack!" << endl;
					}
				}
				else if (b >= 18 && b < 21)
				{
					cout << "Mr. Fantastic's hands grow in size as he slams both is hands down onto " << h->get_hero() << "!" << endl;
					e_power = "Elastic Crush";
					srand(time(NULL));
					int rand_int = rand() % (e_str + e_spd);
					if (rand_int == 0)
					{
						rand_int = 1;
					}

					e_dmg = e_str * e_spd * rand_int;
					if (h->get_defense_mod() == true)
					{
						std::cout << h->get_hero() << " is stunned and cannot defend from the oncoming attack!" << endl;
						e_dmg = e_dmg * 2;
					}
				}


			}
			break;
		}
		case GREEN_GOBLIN:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Green Goblin flys forward and throws a mighty punch at great speed!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Green Goblin flys forward and kicks with all his might!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 6 && a < 9)
			{
				if (b >= 0 && b < 3)
				{
					srand(time(NULL));
					cout << "Green Goblin pulls out and throws a pumpkin bomb!" << endl;
					e_power = " ";
					int rand_int = rand() % 4;
					e_dmg = (rand_int + e_energy) * 2;
				}
				else if (b >= 3 && b < 6)
				{
					srand(time(NULL));
					cout << "Green Goblin pulls out and throws a smoke bomb!" << endl;
					e_power = " ";
					cout << h->get_hero() << " can't see!" << endl;
					int rand_int = rand() % 2;
					e_dmg = (e_lvl)* (rand_int + 1);
					h->set_Cskill(-e_dmg);
					while (h->get_Cskill() < 0)
					{
						h->set_Cskill(+1);
					}
					cout << h->get_hero() << "'s Combate Skills drop to " << h->get_Cskill() << endl;
					e_dmg = 0;

				}
				else if (b >= 6 && b < 9)
				{

					srand(time(NULL));
					cout << "Green Goblin unleashes a swarm of Razor Bats!" << endl;
					e_power = "Bleed";
					int rand_int = rand() % 4;
					e_dmg = (e_spd + 5) * (rand_int + 1);
					bleed = e_dmg * .10;
				}
				else if (b >= 9 && b < 12)
				{
					srand(time(NULL));
					cout << "Green Goblin pulls out and throws a concussive bomb!" << endl;
					cout << h->get_hero() << " is blinded by the explosion!" << endl;
					e_power = " ";
					int rand_int = rand() % 3;
					h->set_defense_mod(1, e_power, 0);
					cout << h->get_hero() << "'s defence drops to " << "0" << endl;
					e_dmg = e_energy;
				}
				else if (b >= 12 && b < 15)
				{
					srand(time(NULL));
					cout << "Green Goblin pulls out and throws a poison gas bomb!" << endl;
					cout << "The gas is making " << h->get_hero() << " feel weak!" << endl;
					e_power = " ";
					int rand_int = rand() % 3;
					e_dmg = e_lvl* rand_int;
					h->set_strenght(-e_dmg);
					while (h->get_strength() < 0)
					{
						h->set_strenght(+1);
					}
					cout << h->get_hero() << "'s strength has dropped to " << h->get_strength() << endl;
					e_dmg = (e_str + (rand_int + 1)) * 4;

				}
				else if (b >= 15 && b < 18)
				{
					srand(time(NULL));
					int rand_int = rand() % e_skill;
					rand_int++;
					e_dmg = 0;
					cout << "Green Goblin throws a barrage of " << rand_int + 1 << " pumpkin bombs!" << endl;
					e_power = " ";
					for (int i = 0; i < rand_int; i++)
					{
						e_dmg += e_energy;
					}
				}
				else if (b >= 18 && b < 21)
				{
					srand(time(NULL));
					cout << "Green Goblin unleases a barrage of random bombs!" << endl;
					e_power = " ";

					int rand_int = rand() % 3;
					if (rand_int == 0)
					{
						srand(time(NULL));
						cout << "Green Goblin pulls out and throws a smoke bomb!" << endl;
						cout << h->get_hero() << " can't see!" << endl;
						int rand_int = rand() % 2;
						e_dmg = (e_lvl)* (rand_int + 1);
						h->set_Cskill(-e_dmg);
						while (h->get_Cskill() < 0)
						{
							h->set_Cskill(+1);
						}
						cout << h->get_hero() << "'s Combate Skills drop to " << h->get_Cskill() << endl;
						std::system("pause");
						std::system("cls");

						cout << "Green Goblin pulls out and throws a concussive bomb!" << endl;
						cout << h->get_hero() << " is blinded by the explosion!" << endl;
						int rand_ints = rand() % 3;
						e_dmg = e_lvl * rand_ints;
						h->set_defense_mod(1, e_power, 0);
						cout << h->get_hero() << "'s defence drops to " << "0" << endl;
						std::system("pause");
						std::system("cls");

						cout << "Green Goblin pulls out and throws a poison gas bomb!" << endl;
						cout << "The gas is making " << h->get_hero() << " feel weak!" << endl;
						int rand_intss = rand() % 3;
						e_dmg = e_lvl* rand_intss;
						h->set_strenght(-e_dmg);
						while (h->get_strength() < 0)
						{
							h->set_strenght(+1);
						}
						cout << h->get_hero() << "'s strength has dropped to " << h->get_strength() << endl;
						std::system("pause");
						std::system("cls");

						int rand_intes = rand() % 10;
						cout << "Green Goblin throws a barrage of " << rand_intes + 1 << " pumpkin bombs!" << endl;
						e_dmg = ((e_energy)* (rand_intes + 1)) + ((e_energy + (rand_int + 1)) * 4) + (e_lvl * rand_intss + 1) + e_lvl;

					}
					else if (rand_int == 1)
					{
						srand(time(NULL));

						cout << "Green Goblin pulls out and throws a poison gas bomb!" << endl;
						cout << "The gas is making " << h->get_hero() << " feel weak!" << endl;
						int rand_int = rand() % 3;
						e_dmg = e_lvl* rand_int;
						h->set_strenght(-e_dmg);
						while (h->get_strength() < 0)
						{
							h->set_strenght(+1);
						}
						cout << h->get_hero() << "'s strength has dropped to " << h->get_strength() << endl;
						std::system("pause");
						std::system("cls");

						int rand_ints = rand() % 10;
						cout << "Green Goblin throws a barrage of " << rand_ints + 1 << " pumpkin bombs!" << endl;
						e_dmg = ((e_energy)* (rand_ints + 1));
					}
					else if (rand_int == 2)
					{
						srand(time(NULL));
						cout << "Green Goblin pulls out and throws a smoke bomb!" << endl;
						cout << h->get_hero() << " can't see!" << endl;
						int rand_int = rand() % 2;
						e_dmg = (e_lvl)* (rand_int + 1);
						h->set_Cskill(-e_dmg);
						while (h->get_Cskill() < 0)
						{
							h->set_Cskill(+1);
						}
						cout << h->get_hero() << "'s Combate Skills drop to " << h->get_Cskill() << endl;
						std::system("pause");
						std::system("cls");

						cout << "Green Goblin pulls out and throws a concussive bomb!" << endl;
						cout << h->get_hero() << " is blinded by the explosion!" << endl;
						int rand_ints = rand() % 3;
						e_dmg = e_lvl * rand_ints;
						h->set_defense_mod(1, e_power, 0);
						cout << h->get_hero() << "'s defence drops to " << "0" << endl;
						e_dmg = ((e_lvl)* (rand_ints + 1)) + e_lvl;
					}
					else if (rand_int == 3)
					{
						srand(time(NULL));
						int rand_int = rand() % 10;
						e_dmg = 0;
						cout << "Green Goblin throws his biggest barrage of pumpkin bombs!" << endl;
						cout << "He throws out " << rand_int + 1 << " bombs!" << endl;
						for (int i = 0; i < rand_int; i++)
						{
							e_dmg = e_dmg + ((e_energy)* (i + 1));

						}
					}


				}


			}
			break;
		}
		case VENOM:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Venom lunges forward and throws a mighty punch!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Venom jumps forward and kicks with all his might!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 6 && a < 9)
			{
				if (b >= 0 && b < 3)
				{
					srand(time(NULL));
					cout << "Venom throws out his tendrils stretching them to a great distance!" << endl;
					e_power = " ";
					int rand_int = rand() % 4;
					e_dmg = (rand_int + e_str) * 2;
				}
				else if (b >= 3 && b < 6)
				{
					srand(time(NULL));
					cout << "Venom terrorizes " << h->get_hero() << " !" << endl;
					e_power = " ";
					int rand_int = rand() % 2;
					e_dmg = (e_lvl)* (rand_int + 1);
					h->set_defense_mod(1, e_power, 0);
					cout << h->get_hero() << "'s defense drops to " << "0" << endl;
					e_dmg = 0;

				}
				else if (b >= 6 && b < 9)
				{

					srand(time(NULL));
					cout << "Venom reaches out with his tendrils and grabs " << h->get_hero() << " !" << endl;
					cout << "He then throws him high into the air!" << endl;
					e_power = " ";
					int rand_int = rand() % 4;
					e_dmg = (e_str + 5) * (rand_int + 1);
				}
				else if (b >= 9 && b < 12)
				{
					srand(time(NULL));
					cout << "Venom releases a burst of symbiotes!" << endl;
					cout << h->get_hero() << " is weaked by the symbiotes!" << endl;
					e_power = " ";
					int rand_int = rand() % 3;
					e_dmg = e_energy * rand_int;
					h->set_strenght(-e_dmg);
					while (h->get_strength() < 0)
					{
						h->set_strenght(+1);
					}
					cout << h->get_hero() << "'s strength drops to " << h->get_strength() << endl;
					e_dmg = e_lvl;
				}
				else if (b >= 12 && b < 15)
				{
					srand(time(NULL));
					cout << "Venom lashes out with his tongue!" << endl;
					cout << "The sticky saliva is slowing down " << h->get_hero() << endl;
					e_power = " ";
					int rand_int = rand() % 3;
					e_dmg = e_lvl* rand_int;
					h->set_speed(-e_dmg);
					while (h->get_speed() < 0)
					{
						h->set_speed(+1);
					}
					cout << h->get_hero() << "'s speed has dropped to " << h->get_speed() << endl;
					e_dmg = (e_str + (rand_int + 1)) * 4;

				}
				else if (b >= 15 && b < 18)
				{
					srand(time(NULL));
					cout << "Venom is attempting to impale " << h->get_hero() << " with his tendrils!" << endl;
					e_power = " ";
					int rand_int = rand() % 10;
					if (rand_int == 0)
					{
						cout << "A direct hit! " << h->get_hero() << " has been impaled!" << endl;
						h->max_hlth();
						e_dmg = h->get_max();

					}
					else if (rand_int > 0 && rand_int < 5)
					{
						cout << h->get_hero() << " manages to avoid a direct hit!" << endl;
						e_dmg = (e_str + e_spd) * (rand_int + 1);

					}
					else
					{
						cout << "Venom misses!" << endl;
						e_dmg = 0;
					}
				}
				else if (b >= 18 && b < 21)
				{
					srand(time(NULL));
					cout << "Venom lunges forward knocking down " << h->get_hero() << endl
						<< "  and bites him multiple times!" << endl;
					e_power = " ";


					srand(time(NULL));
					int bite = rand() % 10;
					int rand_int = rand() % 2;

					e_dmg = (e_lvl)* (rand_int + 1);

					h->set_strenght(-e_dmg);
					while (h->get_strength() < 0)
					{
						h->set_strenght(+1);
					}
					cout << h->get_hero() << "'s Strength drop to " << h->get_strength() << endl;
					std::system("pause");
					std::system("cls");

					cout << "Venom is asorbing life from " << h->get_hero() << " !" << endl;
					for (int i = 0; i < bite; i++)
					{
						e_dmg = e_dmg + (e_lvl)* (rand_int + 1);
					}
					e->set_health(+e_dmg);
					cout << "Venom's health has increased to " << e->get_health() << endl;

					e_dmg = e_dmg;


				}


			}
			break;
		}
		case ZEMO:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Zemo dashes forward and throws a mighty punch!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Zemo lunges forward and kicks with all his might!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 6 && a < 9)
			{
				if (b >= 0 && b < 3)
				{
					srand(time(NULL));
					cout << "Zemo pulls out a pistol and fires!" << endl;
					e_power = " ";
					int rand_int = rand() % e_energy;
					if (h->get_defense() <= 0)
					{
						e_dmg = (rand_int + e_skill) * 4;
					}
					else
					{
						e_dmg = (rand_int + e_skill) * 2;
					}

				}
				else if (b >= 3 && b < 6)
				{
					srand(time(NULL));
					cout << "Zemo pulls out his sword and dashes forward with the streak of steel!" << endl;
					e_power = " ";
					int rand_int = rand() % 2;
					if (h->get_defense() <= 0)
					{
						e_dmg = (e_lvl + e_skill)* (rand_int + 1) * 2;
					}
					else
					{
						e_dmg = (e_lvl + e_skill)* (rand_int + 1);
					}


				}
				else if (b >= 6 && b < 9)
				{

					srand(time(NULL));
					cout << "Zemo marks " << h->get_hero() << "  for death!" << endl;
					e_power = " ";
					int rand_int = rand() % 4;
					e_dmg = 0;
					h->set_defense_mod(1, e_power, 0);
					cout << h->get_hero() << " 's defense has dropped to " << "0" << endl;
				}
				else if (b >= 9 && b < 12)
				{
					srand(time(NULL));
					cout << "Zemo with surgeon like precision, cuts vital tendens!" << endl;
					cout << h->get_hero() << " is weaked by the cuts!" << endl;
					e_power = " ";
					int rand_int = rand() % 3;
					e_dmg = e_lvl * rand_int;
					h->set_strenght(-e_dmg);
					while (h->get_strength() < 0)
					{
						h->set_strenght(+1);
					}
					cout << h->get_hero() << "'s strength drops to " << h->get_strength() << endl;
					if (h->get_defense() <= 0)
					{
						e_dmg = e_dmg = e_lvl * (rand_int + 1) * 2;
					}
					else
					{
						e_dmg = e_lvl * (rand_int + 1);
					}

				}
				else if (b >= 12 && b < 15)
				{
					srand(time(NULL));
					cout << "Zemo pulls out two pistols and uleases a hail of fire!" << endl;
					e_power = " ";
					int rand_int = rand() % e_energy;
					e_dmg = 0;
					for (int i = 0; i < rand_int; i++)
					{

						if (i == 0)
						{
							e_dmg = e_dmg + (e_skill + rand_int);

						}
						else
							e_dmg = e_dmg + (e_skill + rand_int) + i;

					}
					if (h->get_defense() <= 0)
					{
						e_dmg = e_dmg * 2;
					}
					else
					{
						e_dmg = e_dmg;
					}


				}
				else if (b >= 15 && b < 18)
				{
					srand(time(NULL));
					cout << "Zemo pulls out his sword and attempts to decapitate " << h->get_hero() << "!" << endl;
					e_power = " ";
					int rand_int = rand() % 10;
					if (rand_int == 0)
					{
						if (h->get_hero() == "Wolverine")
						{
							cout << "A direct hit, but Zemo's sword does not go all the way through!" << endl;
							cout << "Wolverine laughs, and says 'You can't kill me that way bub'" << endl;
							e_dmg = 0;

						}
						else
						{
							cout << "A direct hit! " << h->get_hero() << " has been decapitated!" << endl;
							h->max_hlth();
							e_dmg = h->get_max();
						}

					}
					else if (rand_int > 0 && rand_int < 11)
					{
						cout << h->get_hero() << " manages to avoid a direct hit!" << endl;
						e_dmg = (e_str + e_spd + e_skill) * (rand_int + 1);

					}

				}
				else if (b >= 18 && b < 21)
				{
					srand(time(NULL));
					cout << "Zemo takes careful aim with his pistols and fires!" << endl;
					e_power = " ";
					int rand_int = rand() % 3;
					if (rand_int == 0)
					{
						cout << "Zemo hits a vital spot with deadly percision!" << endl;
						e_dmg = (e_skill * e_energy) / 2;
					}
					else
					{
						cout << "Zemo's shot was off and did not hit a vital spot!" << endl;
						for (int i = 0; i < rand_int; i++)
						{
							e_dmg = e_dmg + (e_skill * (i + 1));
						}
					}
					if (h->get_defense() <= 0)
					{
						e_dmg = e_dmg * 2;
					}
					else
					{
						e_dmg = e_dmg;
					}


				}


			}
			break;
		}
		case RED_SKULL:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Red Skull puts all his weight forward and throws a mighty punch!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Red Skull spins around and delivers a power kicks with all his might!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 6 && a < 9)
			{
				if (b >= 0 && b < 3)
				{
					srand(time(NULL));
					cout << "Red Skull pulls out a pistol and fires!" << endl;
					e_power = " ";
					int rand_int = rand() % 4;
					e_dmg = (rand_int + e_skill) * 2;
				}
				else if (b >= 3 && b < 6)
				{
					srand(time(NULL));
					cout << "Red Skull injects himself with a strange syringe!" << endl;
					e_power = " ";
					int rand_int = rand() % e_lvl;
					e_dmg = rand_int * 3;
					e->set_health(+e_dmg);
					cout << "Red Skull appears to be full of energy!" << endl;
					e_dmg = 0;

				}
				else if (b >= 6 && b < 9)
				{

					srand(time(NULL));
					cout << "Red Skull stabs " << h->get_hero() << "  with a syringe!" << endl;
					e_power = " ";
					int rand_int = rand() % 4;
					e_dmg = (e_skill)* (rand_int + 1);
					h->set_defense_mod(1, e_power, 0);
					cout << h->get_hero() << " 's defense has dropped to " << "0" << endl;
				}
				else if (b >= 9 && b < 12)
				{
					srand(time(NULL));
					cout << "Red Skull releases a burst of energy from a mysterious orb!" << endl;
					cout << h->get_hero() << " is weaked by the energy!" << endl;
					e_power = " ";
					int rand_int = rand() % 3;
					e_dmg = e_lvl * rand_int;
					h->set_Cskill(-e_dmg);
					while (h->get_Cskill() < 0)
					{
						h->set_Cskill(+1);
					}
					h->set_strenght(-e_dmg);
					while (h->get_strength() < 0)
					{
						h->set_strenght(+1);
					}
					cout << h->get_hero() << "'s Combat Skill drops to " << h->get_Cskill() << endl;
					cout << h->get_hero() << "'s Strength drops to " << h->get_strength() << endl;

					e_dmg = e_lvl;
				}
				else if (b >= 12 && b < 15)
				{
					srand(time(NULL));
					cout << "Red Skull pulls out two SMGs and uleases a hail of fire!" << endl;
					e_power = " ";
					int rand_int = rand() % e->get_level();
					for (int i = 0; i <= rand_int; i++)
					{
						e_dmg = e_dmg + (e_skill + rand_int) * (i + 1);

					}
					h->set_speed(-e_dmg);
					while (h->get_speed() < 0)
					{
						h->set_speed(+1);
					}
					cout << h->get_hero() << "'s speed has dropped to " << h->get_speed() << endl;
					e_dmg = (e_str + (rand_int + 1)) * 4;

				}
				else if (b >= 15 && b < 18)
				{
					cout << "Red Skull pulls out his vaporizing pistol and"
						<< endl << " attempts to disintegrate " << h->get_hero() << "!" << endl;
					e_power = " ";
					srand(time(NULL));
					int rand_int = rand() % 10;
					int second_rand_int = rand() % 10;
					if (rand_int == second_rand_int)
					{

						cout << "A direct hit! " << h->get_hero() << " has been disintegrated!" << endl;
						h->max_hlth();
						e_dmg = h->get_max();


					}
					else if (rand_int > 0 && rand_int < 11)
					{
						cout << h->get_hero() << " manages to avoid a direct hit!" << endl;
						if (rand_int > 5)
						{
							rand_int = 5;
						}
						if (second_rand_int > 5)
						{
							second_rand_int = 5;
						}
						e_dmg = (e_skill)* (rand_int + second_rand_int + 1);

					}

				}
				else if (b >= 18 && b < 21)
				{
					srand(time(NULL));
					cout << "Red Skull takes out his Dust of Death Pistol and fires!" << endl;
					e_power = " ";
					int rand_int = rand() % 3;
					if (rand_int == 0)
					{
						cout << "Red Skull manages to shot the dust into " << h->get_hero() << "'s face!" << endl;
						for (int i = 0; i < rand_int; i++)
						{
							e_dmg = e_dmg + (e_skill * (i + 1));
						}
						if (e_dmg < h->get_max() / 2)
						{
							e_dmg = h->get_max() / 2;
						}

					}
					else
					{
						cout << "Red Skull's shot was off and did not hit " << h->get_hero() << " in the face!" << endl;
						for (int i = 0; i < rand_int; i++)
						{
							e_dmg = e_dmg + (e_skill * (i + 1));
						}
						if (e_dmg > h->get_max() / 2)
						{
							e_dmg = h->get_max() / 2;
						}
					}


				}


			}
			break;
		}
		case SABRETOOTH:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Sabretooth puts all his weight into a mighty punch!" << endl;
				e_dmg = e_str + e_lvl + e->get_rage();
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Sabretooth jumps and kicks with both his feet with all his might!" << endl;
				e_dmg = e_spd + e_lvl + e->get_rage();
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 6 && a < 9)
			{
				if (b >= 0 && b < 6)
				{
					srand(time(NULL));
					cout << "Sabretooth slashes with both his hands!" << endl;
					e_power = "Bleed";
					e->set_rage(+1);
					e->get_rage();
					if (e->get_rage() < 5)
					{
						cout << "Sabretooth's rage inceases with every attack!" << endl;

						int rand_int = rand() % 4;
						e_dmg = (rand_int + e_str) * 2;
						bleed = e_dmg * 0.10;

					}
					else
					{
						cout << "Sabretooth unlease his rage!" << endl;
						int rand_int = rand() % 4;
						e_dmg = (rand_int + e_str) * (2 + e->get_rage());
						bleed = e_dmg * 0.10;
						e->set_rage(-e->get_rage());
					}
				}
				else if (b >= 6 && b < 12)
				{
					srand(time(NULL));
					cout << "Sabretooth roars as his rage increases!" << endl;
					e_power = " ";
					int rand_int = rand() % 5;
					e_dmg = rand_int + 1;
					e->set_rage(+e_dmg);
					cout << "Sabretooth appears to be full of rage!" << endl;
					e_dmg = 0;

				}
				else if (b >= 12 && b < 18)
				{

					srand(time(NULL));
					cout << "Sabretooth slashes " << h->get_hero() << "  multiple times with his claws!" << endl;
					e_power = "Bleed";
					int rand_int = rand() % 4;
					e->set_rage(+rand_int);
					if (e->get_rage() < 6)
					{
						cout << "Sabretooth's rage increases with every attack" << endl;
						e_dmg = (e_str + e->get_rage())* (rand_int + 1);
						bleed = e_dmg * 0.10;
					}
					else
					{
						cout << "Sabretooth unleases his rage!" << endl;
						for (int i = 1; i < e->get_rage(); i++)
						{
							e_dmg = e_dmg + (e_str + e->get_rage())* (i);

						}
						e->set_rage(-e->get_rage());
						bleed = e_dmg * 0.10;
					}

				}
				else if (b >= 18 && b < 21)
				{
					srand(time(NULL));
					cout << "Sabretooth burst forward and unleases powerful deadly strikes!" << endl;
					e_power = "Bleed";
					int rand_int = rand() % 3;
					e->set_rage(+rand_int);
					if (e->get_rage() < 7)
					{
						cout << "Sabretooth's rage increases with every attack!" << endl;
						e_dmg = (e_str + e_spd + e_skill + e->get_rage()) * (1 + rand_int);
						bleed = e_dmg * 0.10;
					}
					else
					{
						cout << "Sabretooth unleases his rage!" << endl;
						for (int i = 1; i < rand_int; i++)
						{
							e_dmg = e_dmg + (e_str + e_spd + e_skill) * (e->get_rage() + rand_int);

						}
						e->set_rage(-e->get_rage());
						bleed = e_dmg * 0.10;
					}

				}


			}
			break;
		}
		case NITRO:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Nirto's hand glows as he puts all his weight into an explosive punch!" << endl;
				e_power = " ";
				if (e->get_health() < e->get_max() && e->get_rage() < 6)
				{
					srand(time(NULL));
					int rage_rand = rand() % e_energy;
					e->set_rage(+rage_rand);

				}
				if (e->get_rage() > 1)
				{
					e_dmg = e_str + (e_energy * e->get_rage());

					e->set_rage(-1);
				}
				else
				{
					e_dmg = e_str + e_lvl;

				}
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Nirto's foot glows as he unleases an explosive kick!" << endl;
				e_power = " ";
				if (e->get_health() < e->get_max() && e->get_rage() < 6)
				{
					srand(time(NULL));
					int rage_rand = rand() % e_energy;
					e->set_rage(+rage_rand);

				}
				if (e->get_rage() > 1)
				{
					e_dmg = e_spd + (e_energy * e->get_rage());

					e->set_rage(-1);

				}
				else
				{
					e_dmg = e_spd + e_lvl;

				}
				cout << name << " Deals ";
			}
			else if (a >= 6 && a < 9)
			{
				if (b >= 0 && b < 3)
				{
					srand(time(NULL));
					int rand_int = rand() % e_energy;
					cout << "Nirto glows brighter!" << endl;
					e_power = " ";
					e->set_rage(+rand_int);
					e->get_rage();
					e_dmg = 0;


				}
				else if (b >= 3 && b < 6)
				{
					srand(time(NULL));
					cout << "Nitro seems to be claming down, his glow is less intense!" << endl;
					e_power = " ";
					int rand_int = rand() % e_energy;
					e_dmg = rand_int + 1;
					e->set_rage(-e_dmg);
					while (e->get_rage() <= 0)
					{
						e->set_rage(+1);
					}

					e_dmg = 0;

				}
				else if (b >= 6 && b < 9)
				{

					srand(time(NULL));
					cout << "Nitro screems in anger as he explodes!" << endl;
					e_power = " ";
					int rand_int = rand() % 4;
					if (e->get_rage() <= e_lvl)
					{
						cout << "Nitro partialy explodes!" << endl;
						e->set_rage(-e->get_rage());

						e_dmg = h->get_health() / 4;

					}
					else
					{
						cout << "Nitro unleases all of his energy in a massive EXPLOSION!" << endl;

						e->set_rage(-e->get_rage());
						e->set_health(-e->get_health());
						e_dmg = e->get_max();
					}

				}



			}
			break;
		}
		case WHIPLASH:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Whiplash throws a mighty punch!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Whiplash delivers a power kicks with all his might!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 6 && a < 9)
			{
				if (b >= 0 && b < 3)
				{
					srand(time(NULL));
					cout << "Whiplash lashes out with one of his eletric whips!" << endl;
					e_power = " ";
					int rand_int = rand() % (e_skill / 2);
					rand_int++;
					e_dmg = (e_str + e_energy) * (rand_int);
				}
				else if (b >= 3 && b < 6)
				{
					srand(time(NULL));
					cout << "Whiplash lashes out with both of his eletric whips!" << endl;
					e_power = " ";
					int rand_int = rand() % e_skill;
					rand_int++;
					e_dmg = (e_str + e_energy) * (rand_int);

				}
				else if (b >= 6 && b < 9)
				{

					srand(time(NULL));
					cout << "Whiplash lashes multiple times with both of his eletric whips!" << endl;
					e_power = " ";
					int rand_int = rand() % e_skill;
					rand_int++;
					for (int i = 1; i < rand_int; i++)
					{
						e_dmg = e_dmg + e_skill + e_str + e_energy;
						cout << "Lash " << i << endl;

					}
				}
				else if (b >= 9 && b < 12)
				{
					srand(time(NULL));
					cout << "Whiplash cracks his whips causing a bright spark of electricity!" << endl;
					cout << h->get_hero() << " is blinded by the spark!" << endl;
					e_power = " ";
					int rand_int = rand() % e_energy;
					rand_int++;
					e_dmg = e_energy * rand_int;
					h->set_defense_mod(1, e_power, 0);
					cout << h->get_hero() << " 's defense has dropped to " << "0" << endl;

					e_dmg = e_skill * rand_int;
				}
				else if (b >= 12 && b < 15)
				{
					srand(time(NULL));
					cout << "Whiplash spins both his whips creating an electric wall!" << endl;
					e_power = " ";
					e_dmg = 0;
					int rand_int = rand() % e_energy;
					rand_int++;
					for (int i = 0; i < rand_int; i++)
					{
						e_dmg += e_energy;

					}
					e->set_defense(+e_dmg);
					e_dmg = 0;

				}
				else if (b >= 15 && b < 18)
				{
					cout << "Whiplash cracks his whip and grabs " << h->get_hero() << "!" << endl;
					cout << "He then unleases electricity into his whips!" << endl;
					e_power = " ";
					e_dmg = 0;
					srand(time(NULL));
					int rand_int = rand() % e_energy;
					rand_int++;
					for (int i = 0; i < rand_int; i++)
					{
						e_dmg += (rand_int * i);
					}


				}
				else if (b >= 18 && b < 21)
				{
					srand(time(NULL));
					cout << "Whiplash charges up all his power " << endl << "and unleases it with a massive swing of his whips!" << endl;
					e_power = " ";
					e_dmg = 0;
					int rand_int = rand() % e_energy;
					if (rand_int < 10)
					{
						rand_int = 10;
					}
					for (int i = 0; i <= rand_int; i++)
					{
						e_dmg += (e_str + e_spd + e_energy) * (rand_int + i);
					}



				}


			}
			break;
		}
		case TITANIUM_MAN:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Titanium Man throws a mighty punch with a loud 'CLANK'!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Titanium Man thrust forward and delivers a power kicks with all his might!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 6 && a < 9)
			{

				int b;

				if (e_lvl >= 5 && e_lvl < 10)
				{
					b = rand() % 12;

				}
				else if (e_lvl >= 10 && e_lvl < 15)
				{
					b = rand() % 15;

				}
				else if (e_lvl >= 15 && e_lvl < 20)
				{
					b = rand() % 18;

				}
				else if (e_lvl >= 20)
				{
					b = rand() % 21;

				}
				else
				{
					b = rand() % 8;

				}
				if (b >= 0 && b < 3)
				{
					srand(time(NULL));
					cout << "Titanium Man charges up and fires his palm blasters!" << endl;
					e_power = " ";
					e_dmg = 0;
					int rand_int;
					if (e_lvl <= 3)
					{
						rand_int = rand() % 4;

					}
					else
					{
						rand_int = rand() % e_energy;

					}
					for (int i = 0; i <= rand_int; i++)
					{
						if (e_lvl <= 10)
						{
							if (rand_int == 1)
							{
								e_dmg = (rand_int + e_energy) * (rand_int + 1);

							}
							else
							{
								cout << "Titanium Man Continues to shoot!" << endl;
								e_dmg += e_energy;

							}
						}
						else
						{
							cout << "Titanium Man Continues to shoot!" << endl;
							e_dmg += e_energy;

						}

					}
				}
				else if (b >= 3 && b < 6)
				{
					srand(time(NULL));
					cout << "Titanium Man charges up and shoots his impulse ray!" << endl
						<< "Which sends out a barrage of mines!" << endl;
					e_power = " ";
					int rand_int = rand() % 8;
					e_dmg = (e_skill + e_energy) * (rand_int + 1);

				}
				else if (b >= 6 && b < 9)
				{

					srand(time(NULL));
					cout << "Titanium Man shoots his Power-Sapping beam!" << endl;
					cout << h->get_hero() << "is getting weaker!" << endl;
					e_power = " ";
					e_dmg = 0;
					int rand_int = rand() % (e_skill + e_energy);
					h->set_strenght(-rand_int);
					while (h->get_strength() < 0)
					{
						h->set_strenght(+1);
					}
					cout << h->get_hero() << "'s Strength drops to " << h->get_strength() << endl;
					for (int i = 1; i < rand_int; i++)
					{
						e_dmg += e_energy;

					}

				}
				else if (b >= 9 && b < 12)
				{
					srand(time(NULL));
					cout << "Titanium Man throws a ring of energy that is growing exponentially!" << endl;
					cout << h->get_hero() << " is binded by the energy ring!" << endl;
					e_power = " ";
					int rand_int = rand() % e_lvl;
					if (h->get_strength() > rand_int)
					{
						cout << h->get_hero() << " easily brakes out of the energy rings!" << endl;
						e_dmg = 0;
					}
					else
					{
						if (rand_int == 0)
						{
							rand_int = 1;
						}

						h->set_defense_mod(1, e_power, 0);
						h->set_speed(-e_dmg);
						while (h->get_speed() < 0)
						{
							h->set_speed(+1);
						}
						cout << h->get_hero() << " 's defense has dropped to " << "0" << endl;
						cout << h->get_hero() << " 's speed has dropped to " << h->get_speed() << endl;
						e_dmg = e_energy * rand_int;
					}


				}
				else if (b >= 12 && b < 15)
				{
					srand(time(NULL));
					cout << "Titanium Man launches a barrage of missles!" << endl;
					e_power = " ";
					e_dmg = 0;
					int rand_int = rand() % e_skill;
					if (h->get_speed() > rand_int)
					{
						cout << h->get_hero() << " easily evades the oncoming missiles!" << endl;
						e_dmg = 0;
					}
					else
					{
						for (int i = 1; i < rand_int; i++)
						{
							e_dmg += e_energy + i;

						}
					}


				}
				else if (b >= 15 && b < 18)
				{
					cout << "Titanium Man unleases his Molecular-Scrambler Ray!" << endl;
					e_power = " ";
					srand(time(NULL));
					int rand_int = rand() % 10;
					if (rand_int == 0)
					{
						rand_int = 1;
					}
					cout << h->get_hero() << " feels odd, something in him has changed!" << endl;
					int str = rand() % h->get_strength();
					int spd = rand() % h->get_speed();
					int intell = rand() % h->get_intelligence();
					int dur = rand() % h->get_durability();
					if (dur <= 0)
					{
						dur = 1;
					}
					int skill = rand() % h->get_Cskill();
					int energy = rand() % h->get_energy();
					h->set_strenght(-h->get_strength());
					h->set_strenght(+str);
					h->set_intelligence(-h->get_intelligence());
					h->set_intelligence(+intell);
					h->set_speed(-h->get_speed());
					h->set_speed(+spd);
					h->set_Cskill(-h->get_Cskill());
					h->set_Cskill(+skill);
					h->set_durability(-h->get_durability());
					h->set_durability(+dur);
					h->set_energy(-h->get_energy());
					h->set_energy(+energy);
					cout << h->get_hero() << "'s stats have all changed!" << endl;
					h->print_stat();
					h->max_hlth();
					h->set_health(-h->get_health());
					h->set_health(+h->get_max());
					cout << h->get_hero() << "'s new health is " << h->get_health() << endl;



				}
				else if (b >= 18 && b < 21)
				{
					srand(time(NULL));
					cout << "Titanium Man unleases his deadliest weapon, his Disintegrator Ray!" << endl;
					e_power = " ";
					int rand_int = rand() % e_lvl;
					int n_rand_int = rand() % e_lvl;
					if (n_rand_int != rand_int)
					{
						e_dmg = 0;
						while (n_rand_int != rand_int)
						{
							e_dmg += e_energy;
							rand_int = rand() % e_lvl;
							n_rand_int = rand() % e_lvl;
						}
					}
					else
					{
						cout << "Titanium Man misses!" << endl;
						e_dmg = 0;
					}




				}


			}
			break;
		}
		case TRI_SENTINEL:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Tri-Sentinel throws a gigantic punch!" << endl;
				if (h->get_speed() > e_spd || h->get_Cskill() > e_spd)
				{
					cout << "Tri-Sentinel is too slow to hit " << h->get_hero() << endl;
					e_dmg = 0;
				}
				else
				{
					e_dmg = (e_str * 2) + e_lvl;
				}
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				int direct_hit = rand() % 10;
				cout << "Tri-Sentinel stomps his foot down with great force!" << endl;
				if (h->get_speed() > e_spd || h->get_Cskill() > e_spd)
				{
					cout << "Tri-Sentinel is too slow to hit " << h->get_hero() << endl;
					e_dmg = 0;
				}
				else if (direct_hit < 7)
				{
					e_dmg = (e_spd * 2) + e_lvl;
				}
				else
				{
					cout << "Direct Hit!\n";
					e_dmg = (e_spd * 3) + e_lvl;
				}
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 6 && a < 9)
			{
				if (b >= 0 && b < 3)
				{
					cout << "Tri-Sentinel fires energy from his palm blasters!" << endl;
					e_power = " ";
					e_dmg = 0;
					int rand_int;
					if (e_lvl <= 3)
					{
						rand_int = rand() % 4;

					}
					else
					{
						rand_int = rand() % e_energy;

					}
					for (int i = 0; i <= rand_int; i++)
					{
						if (e_lvl <= 10)
						{
							if (rand_int == 1)
							{
								e_dmg = (rand_int + e_energy) * (rand_int + 1);

							}
							else
							{
								cout << "Tri-Sentinel Continues to shoot!" << endl;
								e_dmg += e_energy;

							}
						}
						else
						{
							cout << "Tri-Sentinel Continues to shoot!" << endl;
							e_dmg += e_energy;

						}

					}
				}
				else if (b >= 3 && b < 6)
				{
					cout << "Tri-Sentinel launches tear gas at " << h->get_hero() << "!" << endl;
					e_power = " ";
					h->set_defense_mod(1, e_power, 0);
					cout << h->get_hero() << " is unable to see due to the tear gas!" << endl;

				}
				else if (b >= 6 && b < 9)
				{

					cout << "Tri-Sentinel grabs " << h->get_hero() << " with his tenticles!" << endl;
					cout << h->get_hero() << "is pumped full of electricity!" << endl;
					e_power = " ";
					int hold = rand() % e_str;
					int escape = rand() % h->get_strength();
					e_dmg = e_energy + e_str;
					while (hold > escape)
					{
						e_dmg += 5;
						hold = rand() % e_str;
						escape = rand() % h->get_strength();
					}

				}
				else if (b >= 9 && b < 12)
				{
					cout << "Tri-Sentinel's eyes glow as he unleases a power energy blast from his eyes!" << endl;
					e_power = " ";
					e_dmg = e_energy * 2;
				}
				else if (b >= 12 && b < 15)
				{
					if (e_hlth < max)
					{
						cout << "Tri-Sentinel initiates a self-repair!" << endl;
						e_hlth += e_energy * 2;
						if (e_hlth > max)
						{
							e_hlth = max;
						}
					}
					else
					{
						cout << "Tri-Sentinel activates a force field!" << endl;
						e_hlth += e_energy;
					}
					e_power = " ";
					e_dmg = 0;
				}
			}
			break;
		}
		case MAGNETO://finish b attacks from here
		{
			if (a >= 0 && a < 6)
			{
				cout << "Magneto throws a metal orb with great speed!" << endl;
				e_dmg = e_energy + e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 6 && a < 9)
			{
				if (b >= 0 && b < 3)
				{
					cout << "Magneto fires a magnetic pulse from his hands!" << endl;
					e_power = " ";
					e_dmg = 0;
					int rand_int;
					if (e_lvl <= 3)
					{
						rand_int = rand() % 4;

					}
					else
					{
						rand_int = rand() % e_energy;

					}
					for (int i = 0; i <= rand_int; i++)
					{
						if (e_lvl <= 10)
						{
							if (rand_int == 1)
							{
								e_dmg = (rand_int + e_energy) * (rand_int + 1);

							}
							else
							{
								e_dmg += e_energy;

							}
						}
						else
						{
							e_dmg += e_energy;

						}

					}
				}
				else if (b >= 3 && b < 6)
				{
					e_power = " ";
					string object;
					int rand_obj = rand() % 10;
					switch (rand_obj)
					{
					case 0:
						object = "pipe";
						e_dmg = e_energy + e_str + 5;
						break;
					case 1:
						object = "sink";
						e_dmg = e_energy + e_str + 10;
						break;
					case 2:
						object = "chair";
						e_dmg = e_energy + e_str + 15;
						break;
					case 3:
						object = "knife";
						e_dmg = e_energy + e_str + 20;
						bleed_dmg = e_dmg * 0.10;
						e_power = "Bleed";
						break;
					case 4:
						object = "sculpture bust";
						e_dmg = e_energy + e_str + 25;
						break;
					case 5:
						object = "chandelier";
						e_dmg = e_energy + e_str + 30;
						break;
					case 9:
						object = "car";
						e_dmg = e_energy * 3;
						break;
					default:
						object = "pan";
						e_dmg = e_energy + e_str;
						break;
					}
					//left here add all stats for new baddies
					cout << "Magneto uses a magnetic beam to throw a " << object << " at " << h->get_hero() << endl;
				}
				else if (b >= 6 && b < 9)
				{

					cout << "Tri-Sentinel grabs " << h->get_hero() << " with his tenticles!" << endl;
					cout << h->get_hero() << "is pumped full of electricity!" << endl;
					e_power = " ";
					int hold = rand() % e_str;
					int escape = rand() % h->get_strength();
					e_dmg = e_energy + e_str;
					while (hold > escape)
					{
						e_dmg += 5;
						hold = rand() % e_str;
						escape = rand() % h->get_strength();
					}

				}
				else if (b >= 9 && b < 12)
				{
					cout << "Tri-Sentinel's eyes glow as he unleases a power energy blast from his eyes!" << endl;
					e_power = " ";
					e_dmg = e_energy * 2;
				}
				else if (b >= 12 && b < 15)
				{
					if (e_hlth < max)
					{
						cout << "Tri-Sentinel initiates a self-repair!" << endl;
						e_hlth += e_energy * 2;
						if (e_hlth > max)
						{
							e_hlth = max;
						}
					}
					else
					{
						cout << "Tri-Sentinel activates a force field!" << endl;
						e_hlth += e_energy;
					}
					e_power = " ";
					e_dmg = 0;
				}
			}
			break;
		}
		case STEGRON:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Stegron slashes out with his claws!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = "Bleed";
				bleed_dmg = e_dmg * 0.1;
				if (bleed_dmg < 1)
				{
					bleed_dmg = 1;
				}
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Stegron lashes out with his powerful tail!" << endl;
				e_dmg = e_str + e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case SAURON:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Sauron slashes out with his claws!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = "Bleed";
				bleed_dmg = e_dmg * 0.05;
				if (bleed_dmg < 1)
				{
					bleed_dmg = 1;
				}
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Sauron swoops down and kicks hard with booth feet!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case KINGPIN:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Kingpin throws a devistating punch!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Kingpin delivers a power kicks with all his might!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case IRON_FIST:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Iron Fist throws a punch with amazing strength!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Iron Fist lands a powerful kick with amazing speed!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case MISTER_SINISTER:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Mister Sinister throws a mighty punch!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Mister Sinister delivers a power kicks with all his might!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case CALLISTO:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Callisto lashes out with one of her tenticles!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				int tenticles = rand() % 4;
				tenticles++;
				cout << "Callisto lashes out with multiple tenticles!" << endl;
				e_dmg = (e_str * tenticles) + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case DARK_BEAST:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Dark Beast throws a punch with all his might!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Dark Beast flips through the air and lands a doulbe kick!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case CALIBAN:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Caliban throws a solid punch!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Caliban rushes forward and delivers a power kicks with all his might!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case BLOCKBUSTER:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Blockbuster throws a punch as with all his might!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Blockbuster delivers a power kicks with all his might!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case LADY_MASTERMIND:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Lady Mastermind decieds to throws a punch!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Lady Mastermind is forced to throw a kick!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case ARCLIGHT:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Arclight throws a punch with surprising power!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Arclight delivers a power kicks with all her might!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case MACHINE_MAN:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Machine Man extends his arm out with great speed and throws a mighty punch!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Machine Man extends his leg and lands a powerful kick!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case BASTION:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Bastion throws a punch with all his might!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Bastion lands a kick with all his might!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case QUICKSILVER:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Quicksilver lands a series of quick punches!" << endl;
				int bonus_spd = e_spd - h->get_speed();
				int bonus_skill = e_spd - h->get_Cskill();
				if (e_spd > h->get_Cskill() && e_spd >= h->get_speed())
				{
					e_dmg = e_str + bonus_spd + bonus_skill + e_lvl;
				}
				else if (e_spd > h->get_Cskill())
				{
					e_dmg = e_str + bonus_skill + e_lvl;

				}
				else if (e_spd >= h->get_speed())
				{
					e_dmg = e_str + bonus_spd + e_lvl;
				}
				else
				{
					e_dmg = e_str + e_lvl;
				}
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case TOAD:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Toad throws a low punch!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Toad jumps and lands a powerful drop kick!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case SCARLET_WITCH:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Scarlet Witch throws a punch with all her might!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Scarlet Witch delivers a power kick!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case DAREDEVIL:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Daredevil throws a mighty punch!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Daredevil flips through the air and delivers a power kicks with all his might!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case LUKE_CAGE:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Luke Cage throws a punch as solid as a wall!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Luke Cage rushes forward and delivers a power kicks with all his might!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case MARROW:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Marrow throws a reinforced punch!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Marrow delivers a power kicks with all her might!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 6 && a < 9)
			{

				b = rand() % 12;
				int hits = rand() % e_skill;
				hits++;

				if (b >= 0 && b < 3)
				{
					//bone slash
					cout << "Marrow uses the bones encrusting her fingers and slashes wildly!\n";
					e_power = "Bleed";
					e_dmg = e_str + e_skill + hits;
					bleed_dmg = e_dmg * 0.1;
				}
				else if (b >= 3 && b < 6)
				{
					//bone throw
					cout << "Marrow pulls out bone splinters and throws them at " << h->get_hero() << "!" << endl;
					e_power = "Bleed";

					e_dmg = e_dur + e_skill + e_energy + hits;
					bleed_dmg = e_dmg * 0.2;

				}
				else if (b >= 6 && b < 9)
				{
					//bone sword
					cout << "Marrow forms a bone sword and slashes at " << h->get_hero() << "!" << endl;
					e_power = "Bleed";
					e_dmg = (e_str * e_dur);


				}
				else if (b >= 9 && b < 12)
				{
					//bone shiv
					srand(time(NULL));
					cout << "Marrow produces a small bone splinter and stabs for a vitle spot!" << endl;
					e_power = "Bleed";
					if (e_skill > h->get_Cskill())
					{
						cout << "Marrow finds a vitle spot!\n";
						e_dmg = h->get_max() / 4;
					}
					else
					{
						cout << "Marrow barely misses her mark!\n";
						e_dmg = e_dur + e_str + e_spd + e_energy + hits;
					}
					bleed_dmg = e_dmg * 0.3;
				}
			}
			break;
		}
		case HULK:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Hulk swings his fist with amazing strength!" << endl;
				e_power = " ";
				if (e->get_health() < e->get_max() && e->get_rage() < 6)
				{
					srand(time(NULL));
					int rage_rand = rand() % e_lvl;
					e->set_rage(+rage_rand);

				}
				if (e->get_rage() > 1)
				{
					e_dmg = e_str + e_lvl * e->get_rage();

					e->set_rage(-1);
				}
				else
				{
					e_dmg = e_str + e_lvl;

				}
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Hulk slams his foot forward with great force!" << endl;
				e_power = " ";
				if (e->get_health() < e->get_max() && e->get_rage() < 6)
				{
					srand(time(NULL));
					int rage_rand = rand() % e_lvl;
					e->set_rage(+rage_rand);

				}
				if (e->get_rage() > 1)
				{
					e_dmg = e_spd + e_lvl * e->get_rage();

					e->set_rage(-1);

				}
				else
				{
					e_dmg = e_spd + e_lvl;

				}
				cout << name << " Deals ";
			}
			else if (a >= 6 && a < 9)
			{
				if (b >= 0 && b < 3)
				{
					srand(time(NULL));
					int rand_int = rand() % e_lvl;
					cout << "Hulk screams out 'HULK SMASH!!'" << endl;
					e_power = " ";
					if (e->get_rage() > 0)
					{
						e_dmg = (e_str + e_dur) * e->get_rage();
					}
					else
					{
						e->set_rage(+5);
						e_dmg = (e_str + e_dur) * e->get_rage();
					}
					while (e->get_rage() > 0)
					{
						e->set_rage(-1);
					}
					e->set_rage(+5);



				}
				else if (b >= 3 && b < 6)
				{
					srand(time(NULL));
					cout << "Hulk slams his hands together with a thunderous clap!" << endl;
					e_power = " ";
					if (e->get_rage() > 0)
					{
						e_dmg = (e_str + e_spd) * e->get_rage();
					}
					else
					{
						e_dmg = (e_str + e_spd) * 5;
					}
					while (e->get_rage() > 0)
					{
						e->set_rage(-1);
					}
					e->set_rage(+5);

				}
				else if (b >= 6 && b < 9)
				{

					srand(time(NULL));
					cout << "Hulk roars as his anger and rage build!" << endl;
					cout << "Hulk dashes forward and tackles " << h->get_hero() << " !" << endl;
					cout << "Hulk repeatedly slams his fist into " << h->get_hero() << " !" << endl;
					e_power = "p";
					e_dmg = 0;
					if (e->get_rage() >= e_lvl)
					{
						for (int i = 0; i <= e->get_rage(); i++)

							e_dmg += (e_str + i);

					}
					else
					{
						if (e->get_rage() <= 3)
						{
							for (int i = 0; i < 3; i++)
							{
								e_dmg += (e_str + i);
							}
						}
						else
						{
							for (int i = 0; i < (e->get_rage() / 3); i++)
							{
								e_dmg += (e_str + i);
							}
						}

					}
					while (e->get_rage() > 0)
					{
						e->set_rage(-1);
					}

				}



			}
			break;
		}
		case DOCTOR_OCTOPUS:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Doctor Octopus throws a massive punch!" << endl;
				e_dmg = e_str + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Doctor Octopus unleases a power double kick!" << endl;
				e_dmg = e_spd + e_lvl;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case POWDERKEG:
		{
			if (a >= 0 && a < 3)
			{
				(nitro > 0 ? cout << "Powderkeg throws an explosive punch!" << endl : cout << "Powderkeg throws a massive punch!" << endl);
				e_dmg = e_str + e_lvl + nitro;
				nitro += e_energy;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				(nitro > 0 ? cout << "Powderkeg delivers an explosive kick!" << endl : cout << "Powderkeg kicks with all his might!" << endl);
				e_dmg = e_spd + e_lvl  + nitro;
				nitro += e_energy;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case SHOCKER:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Shocker throws an energy charged punch!" << endl;
				e_dmg = e_str + e_energy;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Shocker unleases an energy charged kick!" << endl;
				e_dmg = e_spd + e_energy;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		case TITANIA:
		{
			if (a >= 0 && a < 3)
			{
				cout << "Titania throws a massive punch!" << endl;
				e_dmg = e_str + e_energy;
				e_power = " ";
				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				cout << "Titania unleases a devistating kick!" << endl;
				e_dmg = e_spd + e_energy;
				e_power = " ";
				cout << name << " Deals ";
			}
			break;
		}
		default:
		{
			if (a >= 0 && a < 3)
			{
				if (name == "Mob Leader")
				{
					cout << "Mob Leader throws a punch with all his might!" << endl;
					e_dmg = e_str + e_lvl;
				}
				else if (name == "Civilian")
				{
					cout << "A Civilian throws a punch with all his might!" << endl;
					e_dmg = e_str + e_lvl;
				}
				else if (name == "Cape-Killer")
				{
					cout << "Cape-Killer swings a cattle prod with all his might!" << endl;
					if (e_skill > h->get_Cskill())
					{
						cout << h->get_hero() << " is stunned by the electric shock!" << endl;
						e_dmg = (e_str + e_lvl) * 2;
						h->set_defense_mod(1, e_power, 0);
					}
				}
				else if (name == "A.I.M. Tech")
				{
					srand(time(NULL));
					int weapon_fail = rand() % 10;
					if (weapon_fail > 4)
					{
						cout << "A.I.M. Tech pulls out a close quarters plasma pistol and fires!" << endl;
						e_dmg = e_skill + weapon_fail + e_lvl;
					}
					else
					{
						cout << "A.I.M. Tech's weapon is not responding!" << endl << "They have no choice but to throw a punch!" << endl;
						e_dmg = e_str - e_lvl;
					}

				}
				else if (name == "Hydra Soldier")
				{
					cout << "Hydra Soldier puts on brass knuckles and throws a punch!" << endl;
					srand(time(NULL));
					int brass_dmg = rand() % (e_str + e_lvl);
					e_dmg = e_str + e_lvl + brass_dmg;
				}
				else if (name.substr(0, 4) == "Sent")
				{
					srand(time(NULL));
					int hit = rand() % (e_skill + e_spd);
					int miss = rand() % (h->get_Cskill() + h->get_speed());
					if (hit > miss)
					{
						cout << name << " slams their fist into " << h->get_hero() << "!" << endl;
						e_dmg = e_str * 2;
					}
					else
					{
						cout << name << " slams their fist into the ground, barely missing " << h->get_hero() << endl;
						e_dmg = 0;
						if ((miss - hit) < 3)
						{
							cout << "The impact knocks " << h->get_hero() << " to the ground!" << endl;
							h->set_defense_mod(1, e_power, 0);

						}
					}
				}
				else if (name.substr(0, 4) == "Velo" || name.substr(0, 4) == "Rept")
				{
					cout << "A " << name << " slashes wildly at " << h->get_hero() << endl;
					e_power = "Bleed";
					e_dmg = e_str + e_lvl;
					bleed = (e_dmg * .10);

				}
				else
				{
					cout << name << " throws a punch with all their might!" << endl;
					e_dmg = e_str + e_lvl;
				}
				//add bad guys from missions
				/*Morlock1-5, Marauder1-5, Rebel1-5, Sentinel1-5, Mutant1-5, Savage Man1-5, Velociraptor, Reptile Man, */

				cout << name << " Deals ";
			}
			else if (a >= 3 && a < 6)
			{
				if (name == "Mob Leader")
				{
					cout << "Mob Leader delivers a kick with all his might!" << endl;
					e_dmg = e_spd + e_lvl;

				}
				else if (name == "Civilian")
				{
					cout << "A Civilian delivers a kick with all his might!" << endl;
					e_dmg = e_spd + e_lvl;

				}
				else if (name == "Cape-Killer")
				{
					cout << "Cape-Killer delivers a kick with all his might!" << endl;
					e_dmg = e_spd + e_lvl;
				}
				else if (name == "A.I.M. Tech")
				{
					cout << "A.I.M. Tech uses rocket boots to deliver a mighty kick!" << endl;
					srand(time(NULL));
					int rocket_kick = rand() % 10;
					if (rocket_kick > 4)
					{
						e_dmg = (e_spd * rocket_kick);
					}
					else
					{
						cout << "The rocket boots malfunction!" << endl;
						e_dmg = 0;
					}
				}
				else if (name == "Hydra Soldier")
				{
					cout << "Hydra Soldier delivers a kick with all his might!" << endl;
					e_dmg = e_spd + e_lvl;
				}
				else if (name.substr(0, 4) == "Sent")
				{
					srand(time(NULL));
					int hit = rand() % (e_skill + e_spd);
					int miss = rand() % (h->get_Cskill() + h->get_speed());
					if (hit > miss)
					{
						cout << name << " slams their foot into " << h->get_hero() << "!" << endl;
						e_dmg = e_str + e_spd + e_lvl;
					}
					else
					{
						cout << name << " slams their foot into the ground, barely missing " << h->get_hero() << endl;
						e_dmg = 0;
						if ((miss - hit) < 5)
						{
							cout << "The impact knocks " << h->get_hero() << " to the ground!" << endl;
							h->set_defense_mod(1, e_power, 0);

						}
					}
				}
				else if (name.substr(0, 4) == "Velo")
				{
					cout << "A " << name << " slashes " << h->get_hero() << " with their claws!" << endl;
					e_power = "Bleed";
					e_dmg = e_spd + e_lvl;
					bleed = (e_dmg * .10);
				}
				else
				{
					cout << name << " delivers a kick with all their might!" << endl;
					e_dmg = e_spd + e_lvl;
				}

				cout << name << " Deals ";
			}
			else if (a >= 6 && a < 9)
			{
				srand(time(NULL));
				e_dmg = 0;
				if (weapon == "Knife")
				{
					e_power = "Bleed";
					int rand_int = rand() % e_skill;
					rand_int++;
					cout << name << " slashes and stabes at " << h->get_hero() << " with their knife!" << endl;
					e_dmg = rand_int + e_str + e_lvl;
					bleed = e_dmg * 0.10;
					cout << name << " Deals ";
				}
				else if (weapon == "Sword")
				{
					e_power = "Bleed";
					int rand_int = rand() % (e_skill + e_lvl);
					rand_int++;
					cout << name << " takes out a Sword and slashes wildly!" << endl;
					e_dmg = rand_int + e_spd + e_lvl + e_str;
					bleed = e_dmg * 0.10;
					cout << name << " Deals ";
				}

				else if (weapon == "Baseball Bat")
				{
					int rand_int = rand() % e_skill;
					cout << name << " swings a Baseball Bat  with great speed!" << endl;
					e_dmg = rand_int + 5 + e_str + e_lvl;
					cout << name << " Deals ";
				}
				else if (weapon == "Crowbar")
				{
					int rand_int = rand() % e_skill;
					cout << name << " slames a Crowbar into " << h->get_hero() << " !" << endl;
					e_dmg = rand_int + 8 + e_str + e_lvl;
					cout << name << " Deals ";
				}
				else if (weapon == "Steel Bar")
				{
					int rand_int = rand() % e_skill;
					cout << name << " pulls out a Steel Bar and swings away!" << endl;
					e_dmg = rand_int + 8 + e_lvl + (e_str * 2);
					cout << name << " Deals ";
				}

				else if (weapon == "Gun")
				{
					int rand_int = rand() % (e_skill + 6);
					rand_int++;
					e_dmg = 0;
					cout << name << " holds his Gun gangster style and fires away!" << endl;
					for (int i = 0; i < rand_int; i++)
					{
						e_dmg += 2;
					}
					cout << name << " Deals ";
				}
				else if (weapon == "Assault Rifle")
				{
					int rand_int = rand() % (e_skill + 12);
					rand_int++;
					cout << name << " pulls out an Assault Rifle and Fires!" << endl;
					for (int i = 0; i < rand_int; i++)
					{
						e_dmg += 3;
					}
					cout << name << " Deals ";
				}
				else if (weapon == "Shot Gun")
				{
					int rand_int = rand() % (e_skill + 25);
					e_dmg = 0;
					cout << name << " bust out a shotgun and fires!" << endl;
					if (e_spd < h->get_speed())//bird shot
					{
						for (int i = 0; i < rand_int; i++)
						{
							e_dmg += 2;
						}
					}
					else// slug
					{
						e_dmg = ((rand_int + 10) * e_lvl) / 2;
					}

					cout << name << " Deals ";
				}

				else if (weapon == "none")
				{
					int rand_int = rand() % 5;
					cout << name << " uses their kungfu skill and delivers a Round House Kick!" << endl;
					e_dmg = e_spd * e_str;
					cout << name << " Deals ";
				}
				else if (weapon == "Tranqulizer Gun")
				{
					int rand_int = rand() % 5;
					cout << "Cape-Killer unleases a hail of Tranqulizer darts!" << endl;
					if (e_spd > h->get_speed())
					{
						e_dmg = rand_int + e_skill + e_lvl;
						h->set_defense_mod(1, e_power, 0);
					}
					else
					{
						e_dmg = 0;
						for (int i = 0; i < e_lvl; i++)
						{
							e_dmg = e_dmg + rand_int + e_skill + e_lvl;

						}

					}
					cout << name << " Deals ";
				}
				else if (weapon == "Paralyzing Lazer")
				{
					int rand_int = rand() % e_lvl;
					cout << "Cape-Killer shoots his Paralyzing Lazer!" << endl;
					if (e_skill > h->get_speed())
					{
						e_dmg = rand_int + e_skill + e_lvl;
						h->set_defense_mod(1, e_power, 0);
					}
					else
					{
						e_dmg = rand_int + e_skill + e_lvl;

					}
					cout << name << " Deals ";
				}
				else if (weapon == "Cattle Prod")
				{
					int rand_int = rand() % e_lvl;
					cout << "Cape-Killer uses his Cattle Prod to shock " << h->get_hero() << "!" << endl;
					if (e_skill > h->get_speed())
					{
						h->set_defense_mod(1, e_power, 0);
					}
					e_dmg = rand_int + e_skill + e_lvl;
					cout << name << " Deals ";
				}
				else if (weapon == "Power Fist")
				{
					int rand_int = rand() % e_lvl;
					cout << "Cape-Killer uses his Power Fist to destroy " << h->get_hero() << "!" << endl;
					if (e_skill > h->get_speed())
					{
						e_dmg = (rand_int + e_skill) * e_str;
					}
					else
					{
						e_dmg = rand_int + e_str + e_lvl;
					}
					cout << name << " Deals ";
				}
				else if (weapon == "Taser")
				{
					int rand_int = rand() % e_lvl;
					cout << "Cape-Killer uses his Taser to  incapacitate " << h->get_hero() << "!" << endl;
					if (e_skill > h->get_speed())
					{
						e_dmg = rand_int;
						h->set_defense_mod(1, e_power, 0);
					}
					else
					{
						e_dmg = rand_int;
					}
					cout << name << " Deals ";
				}
				else if (weapon == "Plasma Rifle")
				{
					cout << "A.I.M Tech Charges and fires his Plasma Rifle at " << h->get_hero() << "!" << endl;

					int charge = rand() % (100 + e_skill);
					charge++;
					if (charge < e_skill)
					{
						charge = e_skill * 2;
					}
					e_dmg = charge;
					cout << name << " Deals ";
				}
				else if (weapon == "Tesla Coil Ray")
				{
					cout << "A.I.M. Tech primes his Tesla Coil Ray and fires it at " << h->get_hero() << "!" << endl;

					int rand_dmg = rand() % (e_skill + e_spd) * 2;
					rand_dmg++;
					int rand_skill = rand() % e_skill;
					rand_skill += e_skill;
					int rand_spd = rand() % h->get_speed();
					rand_spd += h->get_speed();
					if (e_skill >= h->get_speed())
					{
						e_dmg = rand_dmg * 2;
						cout << "Direct Hit!" << endl;
					}
					else
					{
						e_dmg = rand_dmg;
					}
					cout << name << " Deals ";
				}
				else if (weapon == "Rail Gun")
				{
					int rand_int = rand() % (e_lvl * e_lvl);
					if (rand_int == 0)
					{
						rand_int = 1;
					}
					cout << "A.I.M. locks on and shoots his Rail Gun at " << h->get_hero() << "!" << endl;
					e_dmg = rand_int;
					cout << name << " Deals ";
				}
				else if (weapon == "Plasma Cannon")
				{
					h->max_hlth();
					int rand_int = rand() % h->get_max();
					cout << "A.I.M. Tech tries to uses his Plasma Cannon to obliterate " << h->get_hero() << "!" << endl;
					if (rand_int >= h->get_health())
					{
						cout << "Direct Hit!" << endl;
						e_dmg = rand_int;
						cout << name << " Deals ";
					}
					else if (rand_int == 0)
					{
						cout << "The Plasma Cannon malfunctions and explodes!" << endl;
						e_hlth -= e_lvl;
						e_dmg = 0;
						weapon = "chicken";
					}

				}
				else if (weapon == "chicken")
				{
					cout << "A.I.M. Tech is too afraid to fight!" << endl;
				}
				else if (weapon == "Energy Grenade Launcher")
				{
					int rand_int = rand() % (100 + e_lvl);
					int direct_hit = rand() % 10;
					cout << "Hydra Soldier launches an energy grenade at " << h->get_hero() << "!" << endl;
					if (direct_hit > 4)
					{
						cout << "Direct Hit!" << endl;
						e_dmg = rand_int;
					}
					else
					{
						cout << h->get_hero() << " is hit by the explosion!" << endl;
						e_dmg = rand_int / 2;
					}
					cout << name << " Deals ";
				}
				else if (weapon == "Laser Rifle")
				{
					int rand_int = rand() % e_lvl;
					rand_int++;
					int shots = rand() % e_skill;
					shots++;
					e_dmg = 0;
					cout << "Hydra Soldier unleashes a volly of Laser Rifle rounds at " << h->get_hero() << "!" << endl;
					for (int i = 0; i <= shots; i++)
					{
						e_dmg += 3;
					}
					if (e_dmg < rand_int)
					{
						e_dmg = rand_int;
					}
					cout << name << " Deals ";
				}
				else if (weapon == "Flame Thrower")
				{
					int rand_int = rand() % (e_lvl + e_skill);
					rand_int++;
					e_power = "fire";
					cout << "Hydra Soldier ignights his Flame Thrower and tries to set " << h->get_hero() << " on fire!" << endl;
					if (e_skill > h->get_speed())
					{
						cout << h->get_hero() << " is not fast enough and is lit on fire!" << endl;
						cout << h->get_hero() << " must put the fire out!" << endl;
						h->set_defense_mod(1, e_power, 0);
					}
					else
					{
						cout << h->get_hero() << " manages to not be lit on fire!" << endl;
					}
					e_dmg = e_skill + e_lvl + rand_int;
					cout << name << " Deals ";
				}
				else if (weapon == "Laser Cannon")
				{
					int rand_int = rand() % (e_lvl + e_skill) * 2;
					rand_int++;
					cout << "Hydra Soldier kneels down and braces his Laser Cannon as he fires at " << h->get_hero() << "!" << endl;
					if (e_skill > h->get_speed())
					{
						e_dmg = rand_int / 2;
						cout << h->get_hero() << " dives out of the way but gets trapped under the rubble from the shot!" << endl;
						h->set_defense_mod(1, e_power, 0);
					}
					else
					{
						e_dmg = rand_int;
					}
					cout << name << " Deals ";
				}
				else if (weapon == "Laser Pistol")
				{
					int rand_int = rand() % e_skill;
					if (rand_int == 0)
					{
						rand_int++;
					}
					cout << "Hydra Soldier pulls out his Laser Pistol and fires at " << h->get_hero() << "!" << endl;
					for (int i = 0; i < rand_int; i++)
					{
						e_dmg += 2;
					}
					if (e_dmg < e_lvl)
					{
						e_dmg = e_lvl;
					}
					cout << name << " Deals ";
				}
				else if (weapon == "Energy Blast")
				{
					int blast = rand() % 4;
					if (blast == 0)
					{
						int heat = rand() % e_lvl;
						heat *= 2;
						cout << name << " shoots plasma from their hands!" << endl;
						e_dmg = e_energy + e_skill + heat;
					}
					else if (blast == 1)
					{
						cout << name << " shoots electrons from their cheast!" << endl;
						e_dmg = e_energy * 2;
					}
					else if (blast == 2)
					{
						cout << name << " shoots stunners from their hands!" << endl;
						e_dmg = e_energy + e_lvl;
						h->set_defense_mod(1, e_power, 0);
					}
					else if (blast == 3)
					{
						int heat = rand() % e_energy;
						heat *= 2;
						cout << name << " shoots a blast of searing heat from their eyes!" << endl;
						e_dmg = e_energy + heat;
					}
					cout << name << " Deals ";
				}
				else if (weapon == "Self Repair")
				{
					if (e_hlth < max)
					{
						int repair = (max - e_hlth) / 2;
						e_hlth += repair;
						cout << name << " is self repairing!" << endl;
						e_dmg = 0;
					}
					else
					{
						cout << name << " is adding armour!" << endl;
						e_hlth += (e_lvl / 2);
						e_dmg = 0;
					}

					cout << name << " Deals ";
				}
				else if (weapon == "Catching Cable")
				{
					if (e_skill >= h->get_Cskill())
					{
						cout << name << " shoots out cables and grabs " << h->get_hero() << "!" << endl;
						cout << h->get_hero() << " can't move!" << endl;
						e_dmg = e_str;
						h->set_defense_mod(1, e_power, 0);
					}
					else
					{
						cout << name << " shoots out cables and slams them into " << h->get_hero() << "!" << endl;
						e_dmg = e_str + e_spd + e_skill;
					}

					cout << name << " Deals ";
				}
				else if (weapon == "Cold Blast")
				{
					int freeze = rand() % e_energy;
					freeze++;
					cout << name << " shoots out liquid Nitrogen and freezes " << h->get_hero() << "!" << endl;
					cout << h->get_hero() << "'s speed has dropped by " << freeze << " due to the cold blast!" << endl;
					h->set_speed(-freeze);
					e_dmg = e_energy * freeze;
					cout << name << " Deals ";
				}
				else if (weapon == "Shock Wave")
				{
					cout << name << " slams the ground and unleashes a massive shock wave!" << endl;
					int balance = rand() % (h->get_speed() + h->get_Cskill());
					int wave = rand() % e_energy + e_spd + e_str;
					if (balance < ((h->get_speed() + h->get_Cskill())) / 2)
					{
						cout << "The shock wave knocks " << h->get_hero() << " to the ground!" << endl;
						h->set_defense_mod(1, e_power, 0);
					}
					e_dmg = e_str + e_spd + wave;
					cout << name << " Deals ";
				}
				else if (weapon == "Shuriken")
				{
					e_power = "Bleed";
					int number_thrown = rand() % e_skill;
					number_thrown++;
					cout << name << " unleashes a hail of " << number_thrown << " shuriken!" << endl;
					if (e_skill > h->get_Cskill())
					{
						cout << name << " throws with deadly accuracy!" << endl;
						e_dmg = 5 * number_thrown;
					}
					else
					{
						cout << h->get_hero() << " is able to avoid direct hits!" << endl;
						e_dmg = 4 * number_thrown;
					}
					bleed = e_dmg * 0.10;
					cout << name << " Deals ";
				}
				else if (weapon == "Teleport")
				{
					if (e_skill > h->get_Cskill())
					{
						if (e_spd > h->get_speed() || e_skill > h->get_speed())
						{
							cout << name << " teleports behind " << h->get_hero() << " and stabs them with a knife!" << endl;
							cout << name << " hits a vitial spot!" << endl;
							e_power = "Bleed";
							e_dmg = h->get_health() * 0.25;
						}
						else
						{
							cout << name << " teleports behind " << h->get_hero() << " and stabs them with a knife!" << endl;
							e_power = "Bleed";
							e_dmg = h->get_health() * 0.10;
						}
					}
					else
					{
						srand(time(NULL));
						int number_punches = rand() % e_skill;
						number_punches++;
						cout << name << " teleports behind " << h->get_hero() << " and punches them in the kidney!" << endl;
						e_dmg = e_str * number_punches;

					}
					cout << name << " Deals ";
				}
				else if (weapon == "Regeneration")
				{
					if (e_hlth < max)
					{
						int regenerate = rand() % (max - e_hlth);
						if (regenerate == 0)
						{
							regenerate++;
						}
						cout << name << " regenerates health!" << endl;
						e_hlth += regenerate;
						e_dmg = 0;
					}
					else
					{
						cout << name << " sucks health from " << h->get_hero() << "!" << endl;
						e_dmg = e_lvl;
						e_hlth += (e_lvl / 2);
					}
					cout << name << " Deals ";
				}
				else if (weapon == "Hand Gun")
				{
					int rand_int = rand() % (e_skill + 6);
					rand_int++;
					e_dmg = 0;
					cout << name << " pulls out a hand gun and fires away!" << endl;
					for (int i = 0; i < rand_int; i++)
					{
						e_dmg += 2;
						if ((e_dmg % 12 == 0) && i != rand_int)
						{
							cout << name << " reloads and continues to fire!" << endl;
						}
					}
					cout << name << " Deals ";
				}
				else if (weapon == "RPG")
				{
					int skill = rand() % e_skill + e_spd;
					int avoid = rand() % h->get_speed() + h->get_Cskill();
					cout << name << " pulls out and RPG and Fires!" << endl;
					if (skill > avoid)
					{
						cout << h->get_hero() << " takes a direct hit!" << endl;
						e_dmg = (h->get_max() / 6);
					}
					else if ((e_skill > h->get_Cskill()) || (e_spd > h->get_speed()))
					{
						h->set_defense_mod(1, e_power, 0);
						cout << h->get_hero() << " is knocked off their feet due to the explosion!" << endl;
						e_dmg = (h->get_max() / 10);
					}
					cout << name << " Deals ";
				}
				else if (weapon == "Fire")
				{
					e_power = "fire";
					int accuracy = rand() % e_skill + e_spd;
					int avoid = rand() % h->get_Cskill() + h->get_speed();
					cout << name << "'s hands glow red as fire erupts from them!" << endl;
					if (accuracy > avoid)
					{
						cout << h->get_hero() << " has been lit on fire!" << endl;
						cout << h->get_hero() << " must put the fire out!" << endl;
						h->set_defense_mod(1, e_power, 0);

					}
					e_dmg = e_energy + h->get_level();

					cout << name << " Deals ";
				}
				else if (weapon == "Ice")
				{
					int accuracy = rand() % e_skill + e_spd;
					int avoid = rand() % h->get_Cskill() + h->get_speed();
					cout << name << "'s hands glow blue as an ice beam shoots from them!" << endl;
					e_power = "ice";
					if (accuracy > avoid)
					{
						cout << h->get_hero() << " has been frozen!" << endl;
						cout << h->get_hero() << " must break out of the ice!" << endl;
						h->set_defense_mod(1, e_power, ice_str);
						ice_str += rand() % e_energy;
					}
					else
					{
						h->set_speed(-2);
						cout << h->get_hero() << "'s speed has droped due to the ice!" << endl;
						cout << h->get_hero() << "'s speed is now " << h->get_speed() << "!" << endl;
					}
					e_dmg = e_energy + h->get_level();
					cout << name << " Deals ";
				}
				else if (weapon == "Earth")
				{
					e_power = "Earth";
					int accuracy = rand() % e_skill + e_spd;
					int avoid = rand() % h->get_Cskill() + h->get_speed();
					int durability_mod = e_dur - h->get_durability();
					if (durability_mod < 0)
					{
						durability_mod = 1;
					}
					if (accuracy > avoid)
					{
						cout << name << " forms the earth around " << h->get_hero() << " and encases them in the earth!" << endl;
						h->set_defense_mod(1, e_power, 0);
						e_dmg = (rand() % e_energy) * (rand() % e_str);
						if (e_dmg == 0)
						{
							e_dmg = e_energy;
						}
					}
					else
					{
						cout << name << " causes a large boulder to erupt from the ground and smashes it into " << h->get_hero() << "!" << endl;
						e_dmg = e_energy * durability_mod;
					}

					cout << name << " Deals ";
				}
				else if (weapon == "Mind")
				{
					cout << name << "blast " << h->get_hero() << " with telepathic waves!" << endl;
					int will = rand() % h->get_intelligence();
					int e_will = rand() % e_intell;
					if (e_will > will)
					{
						cout << name << " over powers " << h->get_hero() << "!" << endl;
						e_dmg = e_intell + e_energy;
						h->set_strenght(-2);
						h->set_durability(-2);
						h->set_defense_mod(1, "", 0);
						cout << "The blast weakens " << h->get_hero() << "!" << endl;
					}
					else
					{
						e_dmg = e_intell + e_energy;
					}
					cout << name << " Deals ";
				}
				else if (weapon == "Strength")
				{
					cout << name << " uses their super human strength to land a massive upper cut!" << endl;
					e_dmg = e_str * e_energy;
					if ((rand() % e_str) > (rand() % h->get_durability()))
					{
						cout << h->get_hero() << " is knocked out cold!" << endl;
						h->set_defense_mod(1, "", 0);
					}
					cout << name << " Deals ";
				}
				else if (weapon == "Sparks")
				{
					cout << name << " raises thier hands and energy globes comes flying out!" << endl;
					if ((rand() % 100) >= 98)
					{
						cout << "The globes are super deadly and extremely powerful!" << endl;
						e_dmg = h->get_health() / 2;
					}
					else if (rand() % 100 > 50)
					{
						e_dmg = e_energy;
					}
					else
					{
						cout << h->get_hero() << " laughs as the globes harmlessly fizzle out!" << endl;
						e_dmg = 0;
					}
					cout << name << " Deals ";
				}
				else if (weapon == "Power Steal")
				{
					cout << name << " reaches out with their hands and touches " << h->get_hero() << "!" << endl;
					if (h->get_hero() == "Spiderman")
					{
						cout << "Spiderman is fully protected due to his costume!" << endl;
						e_dmg = 0;
					}
					else if (h->get_hero() == "Iron Man")
					{
						cout << "Iron Man is fully protected doe to his suit!" << endl;
						e_dmg = 0;
					}
					else if (h->get_hero() == "Wolverine")
					{
						e_power = "Power Steal";
						cout << name << " grabs Wolverine's arm and steals his power!" << endl;
						e_hlth += (e_hlth * 0.02);
						h->set_durability(-2);
						e_dmg = e_energy;
					}
					else
					{
						cout << name << " grabs " << h->get_hero() << "'s arm and drains their strength!" << endl;
						h->set_strenght(-3);
						h->set_durability(-3);
						e_dmg = e_energy;
					}

					cout << name << " Deals ";
				}
				else if (weapon == "Electricity")
				{
					int spark = rand() % e_energy;
					cout << name << "'s hands glow as a streak of electricity shoots from them!" << endl;
					if (h->get_hero() == "Iron Man")
					{
						cout << "The electricity hits hard but the suite absorbs it!" << endl;
						h->set_energy(+spark);
						e_dmg = 0;
					}
					else
					{
						e_dmg = (e_energy * spark) + e_spd;
					}
					cout << name << " Deals ";
				}
				else if (weapon == "Multiply")
				{
					e_power = "Multiply";
				}
				else if (weapon == "Absorb")
				{
					if (h->get_attack() > 0)
					{
						cout << name << " glows mysteriously." << endl;
						e_dmg = 0;
					}
					else
					{
						cout << name << " reflects back the damage they recieved!" << endl;
						e_dmg = h->get_attack();
					}

					cout << name << " Deals ";
				}
				else if (weapon == "Mace")
				{
					cout << name << " swings a Mace with all their might!" << endl;
					e_dmg = e_str * 2;
					if ((e_dmg / 2) > h->get_durability())
					{
						cout << "The blows knocks " << h->get_hero() << " out cold!" << endl;
						h->set_defense_mod(1, "", 0);
					}
					cout << name << " Deals ";
				}
				else if (weapon == "Axe")
				{
					e_power = "Bleed";
					cout << name << " swings their axe with great speed and strength!" << endl;
					e_dmg = e_str + e_spd + e_lvl;
					bleed = e_dmg * 0.10;
					cout << name << " Deals ";
				}
				else if (weapon == "Spear")
				{
					e_power = "Bleed";
					cout << name << " lunges with their spear!" << endl;
					e_dmg = e_str * e_spd;
					bleed = e_dmg * 0.10;
					cout << name << " Deals ";
				}
				else if (weapon == "Bow")
				{
					e_power = "Bleed";
					cout << name << " notches an arrow in their bow and fires!" << endl;
					for (int i = 0; i < (e_skill / 2); i++)
					{
						cout << name << " fires again!" << endl;
					}
					e_dmg = 3 * (e_skill / 2);
					bleed = e_dmg * 0.10;
					cout << name << " Deals ";
				}
				else if (weapon == "Claw")
				{
					e_power = "Bleed";
					cout << name << " delivers a deadly slashes with their claws!" << endl;
					e_dmg = e_str * (e_skill / 4);
					bleed = e_dmg * 0.10;
					cout << name << " Deals ";
				}
				else if (weapon == "Club")
				{
					cout << name << " swings their club with great might!" << endl;
					e_dmg = e_str * 2;
					if ((e_dmg / 2) > h->get_durability())
					{
						cout << "The blows knocks " << h->get_hero() << " out cold!" << endl;
						h->set_defense_mod(1, "", 0);
					}
					cout << name << " Deals ";
				}
				else if (weapon == "Blow Gun")
				{
					if (h->get_hero() != "Iron Man" || h->get_hero() != "Mr. Fantastic" || h->get_hero() != "Wolverine")
					{
						cout << name << " shoots a dart from their blow gun!" << endl;
						e_dmg = 1;
						cout << h->get_hero() << " is getting sleepy!" << endl;
						h->set_defense_mod(1, "", 0);
					}
					else
					{
						cout << h->get_hero() << " is uneffected by the dart!" << endl;
						e_dmg = 0;
					}
					cout << name << " Deals ";
				}

			}
			break;
		}

	}
}

	enemies::enemies(const enemies &obj)
	{
		name = obj.name;
		e_str = obj.e_str;
		e_spd = obj.e_spd;
		e_dur = obj.e_dur;
		e_skill = obj.e_skill;
		e_energy = obj.e_energy;
		e_intell = obj.e_intell;
		weapon = "none";
		e_hlth = (obj.e_hlth / 2);
		e_defe = obj.e_defe;
		e_lvl = obj.e_lvl;
		e_exp = obj.e_exp;
	}
int enemies::get_attack()
{
	if (e_dmg > 0)
	{
		return e_dmg;
	}
	else
	{
		e_dmg = 0;

		return e_dmg;
	}
}

void enemies::set_bleeding()
{
	if (name == "Mr. Fantastic" || name == "Mr. Fantastic")
	{
		bleeding = false;
	}
	else
	{
		bleeding = true;
	}
}
bool enemies::get_bleeding()
{
	return bleeding;
}

void enemies::set_bleed_dmg(int i)
{
	bleed_dmg += i;
}
int enemies::get_bleed_dmg()
{
	return bleed_dmg;
}

int enemies::get_bleed()
{
	return bleed;
}
void enemies::set_power(string s)
{
	e_power = s;
}
string enemies::get_power()
{
	return e_power;
}
void enemies::set_weapon()
{
	int a = rand() % 16;
	if (name != "Iron Man" && name != "Spiderman" && name != "Wolverine" && name != "Captain America" && name != "Hulk"
		&& name != "Black Panther" && name != "Black Widow" && name != "Mr. Fantastic" && name != "Ms. Marvel")
	{
		if (name == "Mob Leader")
		{
			if (a >= 0 && a <= 6)
			{
				weapon = "Sword";
			}
			else if (a >= 7 && a <= 10)
			{
				weapon = "Baseball Bat";
			}
			else if (a >= 11 && a <= 13)
			{
				weapon = "Steel Bar";
			}
			else if (a == 14)
			{
				weapon = "Assault Rifle";
			}
			else
			{
				weapon = "Shot Gun";
			}

		}// mob leader
		else if (name.substr(0, 4) == "Cape")
		{
			if (a >= 0 && a <= 6)
			{
				weapon = "Tranqulizer Gun";
			}
			else if (a >= 7 && a <= 10)
			{
				weapon = "Paralyzing Lazer";
			}
			else if (a >= 11 && a <= 13)
			{
				weapon = "Cattle Prod";
			}
			else if (a == 14)
			{
				weapon = "Power Fist";
			}
			else
			{
				weapon = "Taser";
			}
		} // cape-killer
		else if (name.substr(0, 4) == "A.I.")
		{
			if (a >= 0 && a <= 6)
			{
				weapon = "Plasma Rifle";
			}
			else if (a >= 7 && a <= 10)
			{
				weapon = "Tesla Coil Ray";
			}
			else if (a >= 11 && a <= 13)
			{
				weapon = "Rail Gun";
			}
			else
			{
				weapon = "Plasma Cannon";
			}
			
		} // A.I.M. Tech
		else if (name.substr(0, 4) == "Hydr")
		{
			if (a >= 0 && a <= 6)
			{
				weapon = "Energy Grenade Launcher";
			}
			else if (a >= 7 && a <= 10)
			{
				weapon = "Laser Rifle";
			}
			else if (a >= 11 && a <= 13)
			{
				weapon = "Flame Thrower";
			}
			else if (a == 14)
			{
				weapon = "Laser Cannon";
			}
			else
			{
				weapon = "Laser Pistol";
			}
		} // Hydra Soldier
		else if (name.substr(0, 4) == "Sent")
		{
			if (a >= 0 && a <= 6)
			{
				weapon = "Energy Blast";//look up on xmen wiki
			}
			else if (a >= 7 && a <= 10)
			{
				weapon = "Self Repair";//heal 50% or more health
			}
			else if (a >= 11 && a <= 13)
			{
				weapon = "Catching Cable";//restrins their victim
			}
			else if (a == 14)
			{
				weapon = "Cold Blast"; //freeze victim
			}
			else
			{
				weapon = "Self Repair";
			}
		}//sentinel
		else if (name.substr(0, 4) == "Rebe")
		{
			if (a >= 0 && a <= 6)
			{
				weapon = "Hand Gun";
			}
			else if (a >= 7 && a <= 10)
			{
				weapon = "Baseball Bat";
			}
			else if (a >= 11 && a <= 13)
			{
				weapon = "RPG";
			}
			else if (a == 14)
			{
				weapon = "Assault Rifle";
			}
			else
			{
				weapon = "Shot Gun";
			}
		}//rebels 
		else if (name.substr(0, 4) == "Morl")
		{
			if (a >= 0 && a <= 6)
			{
				weapon = "Fire";
			}
			else if (a >= 7 && a <= 10)
			{
				weapon = "Ice";
			}
			else if (a >= 11 && a <= 13)
			{
				weapon = "Earth";
			}
			else if (a == 14)
			{
				weapon = "Mind";
			}
			else
			{
				weapon = "Strength";
			}
		}//Morlocks
		else if (name.substr(0, 4) == "Mara")
		{
			if (a >= 0 && a <= 6)
			{
				weapon = "Shock Waves";
			}
			else if (a >= 7 && a <= 10)
			{
				weapon = "Shuriken";
			}
			else if (a >= 11 && a <= 13)
			{
				weapon = "Teleport";
			}
			else if (a == 14)
			{
				weapon = "Fire";
			}
			else
			{
				weapon = "Regeneration";
			}
		}//Marauders
		else if (name.substr(0, 4) == "Muta")
		{
			if (a >= 0 && a <= 6)
			{
				weapon = "Sparks";
			}
			else if (a >= 7 && a <= 10)
			{
				weapon = "Power Steal";//uses one of the users powers agains them
			}
			else if (a >= 11 && a <= 13)
			{
				weapon = "Electricity";
			}
			else if (a == 14)
			{
				weapon = "Multiply";//build copy constructor
			}
			else
			{
				weapon = "Abosrb";// reflects last damage recieved
			}
		}//Mutants
		else if (name.substr(0, 4) == "Sava")
		{
			if (a >= 0 && a <= 6)
			{
				weapon = "Sword";
			}
			else if (a >= 7 && a <= 10)
			{
				weapon = "Mace";
			}
			else if (a >= 11 && a <= 13)
			{
				weapon = "Axe";
			}
			else if (a == 14)
			{
				weapon = "Spear";
			}
			else
			{
				weapon = "Bow";
			}
		}//Savage Men
		else if (name.substr(0, 4) == "Velo")
		{
			weapon == "Claw";
		}//Velociraptors
		else if (name.substr(0, 4) == "Rept")
		{
			if (a >= 0 && a <= 6)
			{
				weapon = "Spear";
			}
			else if (a >= 7 && a <= 10)
			{
				weapon = "Club";
			}
			else if (a >= 11 && a <= 13)
			{
				weapon = "Sword";
			}
			else if (a == 14)
			{
				weapon = "Axe";
			}
			else
			{
				weapon = "Blow Gun";
			}
		}//Reptile Men
		else
		{
			if (a >= 0 && a <= 6)
			{
				weapon = "Knife";
			}
			else if (a >= 7 && a <= 10)
			{
				weapon = "Baseball Bat";
			}
			else if (a >= 11 && a <= 13)
			{
				weapon = "Crowbar";
			}
			else if (a == 14)
			{
				weapon = "Gun";
			}
			else
			{
				weapon = "none";
			}

		}
	}
	else
	{
		weapon = "";
	}
}
string enemies::get_weapon()
{
	return weapon;
}
void enemies::set_reputation()
{
	if (name == "Civilian")
	{
		rep = ((e_lvl + e_str + e_dur + e_skill + e_spd) / 5) * -0.01;

	}
	else if (is_boss && !is_villian)
	{
		rep = ((e_lvl + e_str + e_dur + e_skill + e_spd) / 5) * -0.01;

	}
	else if (is_villian && is_boss)
	{
		rep = ((e_lvl + e_str + e_dur + e_skill + e_spd) / 5) * 0.05;
	}
	else
	{
		rep = ((e_lvl + e_str + e_dur + e_skill + e_spd) / 5) * 0.03;
		cout << rep << "Reputaion" << endl;
	}
}
double enemies::get_reputation()
{
	return rep;
}

void enemies::max_health(int i)
{
	max = i;
}
int enemies::get_max()
{
	return max;
}
void enemies::set_boss()
{
	is_boss = true;
}
bool enemies::get_boss()
{
	if (is_boss)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void enemies::set_villian()
{
	is_villian = true;
}
bool enemies::get_villian()
{
	if (is_villian)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void enemies::set_regen()
{
	if (name == "Wolverine" || name == "Sabretooth")
	{
		regen = (e_hlth * 0.02);
	}
	else
	{
		regen = (e_hlth * 0.01) * e_lvl;

	}
}
int enemies::get_regen()
{
	return regen;
}
void enemies::set_reduce()
{
	if (name == "Iron Man" || name == "Hulk")
	{
		reduce = e_dur/2;
		
	}
	else if (name == "Mr. Fantastic")
	{
		reduce = e_dur / 3;
	}
	else
	{
		reduce = e_dur / 4;
	}
	if (reduce <= 0)
	{
		reduce = 1;
	}
}
void enemies::set_evade()
{
	srand(time(NULL));
	evade = e_skill + e_intell;
	int to_evade = rand() % evade;

	if (name == "Spiderman" && to_evade >= (evade * 0.7))
	{
		cout << endl << name << " Spidy sense is tingling!" << endl << "Spiderman evades the oncoming attack!" << endl;
		system("puase");
		system("cls");
		evades = true;
	}
	else if ((name == "Black Widow" || name == "Venom" || name == "Dark Beast" || name == "Callisto" || name == "Stegron") && to_evade >= (evade * 0.8))
	{
		cout << endl << name << " evades the oncoming attack!" << endl;
		system("puase");
		system("cls");
		evades = true;
	}
	else if (name == "Quicksilver" && to_evade > (evade * 0.5))
	{
		cout << endl << name << " easily evades the oncoming attack!" << endl;
		system("puase");
		system("cls");
		evades = true;
	}
	else if(to_evade > (evade * 0.9))
	{
		cout << endl << name << "evades the oncoming attack!" << endl;
		system("puase");
		system("cls");
		evades = true;
	}
	else
	{
		evades = false;
	}
}
int enemies::get_evade()
{
	return evades;
}
int enemies::get_reduce()
{
	return reduce;
}
void enemies::set_rage(int i)
{
	rage += i;
}
int enemies::get_rage()
{
	return rage;
}
void enemies::set_nitro(int i)
{
	(i == 0 ? nitro = 0 : nitro += i);
}
int enemies::get_nitro()
{
	return nitro;
}
void enemies::set_ice(int i)
{
	ice_str += 1;
}
int enemies::get_ice()
{
	return ice_str;
}
void enemies::set_defense_mod(int i)
{
	if (i == 1)
	{
		ko = true;
	}
	else
	{
		int stunned = rand() % e_dur;
		if (stunned < (e_dur / 2))
		{
			ko = false;
		}
		else
		{
			if (name != "")
			{
				cout << name << " is unable to attack!" << endl;
			}
			else
			{
				cout << name << " is unable to attack!" << endl;
			}
			ko = true;
			system("pause");
			system("cls");
		}
	}
}
bool enemies::get_defense_mod()
{
	return ko;
}
void enemies::set_web_str(int i)
{
	web_str += i;
}
int enemies::get_web_str()
{
	return web_str;
}
