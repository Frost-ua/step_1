#pragma once
#include "Team.h"

class Game
{
public:
	Game(const Team & team_1, const Team & team_2);

	void battle();
	void print_map() const;
	
private:
	Team team_1;
	Team team_2;
	
};

