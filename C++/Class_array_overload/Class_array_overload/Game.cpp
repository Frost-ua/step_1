#include "Game.h"
#include<iostream>
#include "Unit.h"
#include "Team.h"

using namespace std;

Game::Game(const Team& team_1, const Team& team_2)
{
	this->team_1 = team_1;
	this->team_2 = team_2;
}

void Game::battle()
{
	cout << "Press SPACE for start" << endl << endl;
	system("Pause");
	system("Cls");
	print_map();
	
	while (!team_1.is_dead_team() && !team_2.is_dead_team())
	{
		for (size_t i = 0; i < team_1.get_original_team_size(); i++)
		{
			team_1[team_1.check_index_attacking_unit(i)].attack(team_1.search_enemy(team_2, team_1[team_1.check_index_attacking_unit(i)].get_name()));
			team_2.check_dead_unit();
			if (team_2.is_dead_team())
			{
				system("Cls");
				print_map();
				cout << "Gnomes WON!" << endl;
				break;
			}
			
			cout << endl << endl;
			system("Pause");
			system("Cls");
			print_map();

			team_2[team_2.check_index_attacking_unit(i)].attack(team_2.search_enemy(team_1, team_2[team_2.check_index_attacking_unit(i)].get_name()));
			team_1.check_dead_unit();
			if (team_1.is_dead_team())
			{
				system("Cls");
				print_map();
				cout << "Orks WON!" << endl;

				break;
			}

			cout << endl << endl;
			system("Pause");
			system("Cls");
			print_map();
		}
	}

}

void Game::print_map() const
{
	cout << "\n\n\t\t\t\t\t------======   " << team_1.get_team_name() << "   ======------" << endl;
	cout << "\n\t\t\t";
	this->team_1.print_team();
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t";
	this->team_2.print_team();
	cout << "\n\n\t\t\t\t\t------======   " << team_2.get_team_name() << "   ======------" << endl;
	cout << "\n\n\n";
}


