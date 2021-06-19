#include <ctime>
#include <iostream>
#include "Team.h"
#include "Swordsman.h"
#include "Archer.h"
#include "Mage.h"
#include "Game.h"



Team::Team(const string& team_name, size_t size_team)
{
	set_team_name(team_name);
	set_size_team(size_team);
	team = new Unit[size_team];
	set_team();
}

void Team::set_team()
{
	for (size_t i = 0; i < size_team; i++)
	{
		team[i] = get_random_unit();
		team[i].set_race(team_name);
	}
}

Unit Team::get_random_unit()
{
	//srand(unsigned int(time(NULL)));
	size_t random_unit = rand() % 3;
	switch (random_unit)
	{
		case 0: {
			Swordsman tmp;
			return tmp;
		}
		case 1: {
			Archer tmp;
			return tmp;
		}
		case 2: {
			Mage tmp;
			return tmp;
		}
	}
}

Unit& Team::search_enemy(const Team& other, string unit_name) const
{
	bool is_same_enemy = false;
	
		for (size_t j = 0; j < other.get_size_team(); j++)
		{
			if (unit_name == other.team[j].get_name() && other.team[j].get_hp() > 0)
			{
				is_same_enemy = true;
				return other.team[j];
			}
		}
	
	if (!is_same_enemy)
	{
		size_t a = rand() % other.get_size_team();
		if (other.team[a].get_hp() > 0)
		{
			return other.team[a];
		}
	}
}

Team &Team::get_team()
{
	return *this;
}


size_t Team::check_index_attacking_unit(size_t index) const                                // REWORK!!!!
{
	if (index < size_team)
	{
		return index;
	}
	else
	{
		return rand() % this->get_size_team();
	}
}

Team& Team::operator=(const Team& other)
{
	this->size_team = other.size_team;                       
	this->team_name = other.team_name;
	team = new Unit[size_team];

	for (size_t i = 0; i < size_team; i++)
	{
		team[i] = other.team[i];
	}
	
	return *this;	
}

Unit& Team::operator[](size_t index)
{
	if (index < size_team)
		return team[index];
}

size_t Team::get_original_team_size() const
{
	return ORIGINAL_TEAM_SIZE;
}

string Team::get_team_name() const
{
	return team_name;
}

size_t Team::get_size_team() const
{
	return size_team;
}



bool Team::is_dead_team()
{
	int counter = 0;
	for (size_t i = 0; i < size_team; i++)
	{
		if (team[i].get_hp() <= 0)
		{
			counter++;
		}
	}
	if (counter == size_team)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool Team::check_dead_unit()
{
	size_t dead_unit_index = 0;
		bool is_dead_unit = false;
		for (size_t i = 0; i < size_team; i++)
		{
			if (team[i].get_hp() <= 0)
			{
				is_dead_unit = true;
				dead_unit_index = i;
				break;
			}
		}
	
		if (is_dead_unit)
		{
			if (size_team > 1)
			{
				Unit* new_team = new Unit[size_team - 1];

				for (size_t j = 0; j < size_team - 1; j++)
				{
					if (j < dead_unit_index)
					{
						new_team[j] = team[j];
					}
					if (j >= dead_unit_index)
					{
						new_team[j] = team[j + 1];
					}
				}

				delete[] team;
				team = new_team;
				--size_team;
			}
			else
			{
				--size_team;
			}
		}
		if (size_team == 0)
		{
			
			return true;
		}
		else
		{
			return false;
		}

	
}

void Team::print_team() const
{
	if (get_size_team() > 0)
	{
		cout << " - ";
	}
	
	for (size_t i = 0; i < size_team; i++)
	{
		if (!team[i].is_unit_die())
		{
			cout << team[i].get_name() << "(" << team[i].get_hp() << ")" << " - ";
		}
	}
}

Team::~Team()
{
	if (team != nullptr)
	{
		delete[] team;
	}
}

void Team::set_team_name(const string &team_name)
{
	this->team_name = team_name;
}

void Team::set_size_team(size_t size_team)
{
	size_team >= MIN_TEAM_SIZE ? this->size_team = size_team : MIN_TEAM_SIZE;
}


