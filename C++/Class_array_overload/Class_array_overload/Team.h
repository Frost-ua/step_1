#pragma once
#include <string>
#include "Unit.h"
using namespace std;

class Team
{
public:
	Team(const string & team_name, size_t size_team);
	Team() = default;

	Team& operator = (const Team& other);
	Unit& operator [] (size_t index);

	size_t get_original_team_size() const;
	string get_team_name() const;
	size_t get_size_team() const;
	Unit get_random_unit();
	Unit& search_enemy(const Team & other, string unit_name) const;
	Team &get_team();
	size_t check_index_attacking_unit(size_t index) const;
	
	bool is_dead_team();
	bool check_dead_unit();
	void print_team() const;
	~Team();
	
private:
	const size_t ORIGINAL_TEAM_SIZE = 5;
	const size_t MIN_TEAM_SIZE = 1;
	size_t size_team = 5;
	string team_name = "Noname";
	Unit* team = nullptr;

	void set_team_name(const string &team_name);
	void set_size_team(size_t size_team);
	void set_team();
};

