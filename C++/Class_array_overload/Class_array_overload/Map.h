/*
#pragma once
#include <vector>
#include <iostream>
#include "Field.h"
#include "Fleet.h"

class Map
{
public:
	Map();
	
	void placeEnemyShips();
//	void placeMyShips();
	void print();
private:
	const int N = 10;
	std::vector<char> letters{};
	Field my_field;
	Field enemy_field;
	
	void print_letters()const;
	void fillField(Field& field);
	char default_symbol = ' ', enemy_symbol = 254, my_symbol = 254, sight_symbol = '+', destroyed_symbol = 'X', miss_symbol = '.', temp_miss_symbol = 'o';
};

inline Map::Map()
{
	//print();
}

inline void Map::print()
{
	int k = 0;

	for (int i = 0, j = 65; i < N; i++, j++) {
		letters.push_back(j);
	}

	std::cout << "\n\n\n\t      ";
	print_letters();
	std::cout << "\t\t\t\t  ";
	print_letters();
	std::cout << "\t\n\t      --------------------------------\t\t\t\t  --------------------------------\n";

	for (int i = 0; i < N; i++, k++)
	{
		std::cout << "\t    " << k << "|";
		for (int j = 0; j < N; j++)
		{
			std::cout << "  " << my_field.getMatrix()[i][j];

		}
		std::cout << "  |" << k;
		std::cout << "\t\t\t";
		std::cout << k << "|";

		for (int j = 0; j < N; j++)
		{
			std::cout << "  " << enemy_field.getMatrix()[i][j];
		}

		std::cout << "  |" << k;
		std::cout << std::endl;
	}
	std::cout << "\t      --------------------------------\t\t\t\t  --------------------------------\n\t      ";
	print_letters();
	std::cout << "\t\t\t\t  ";
	print_letters();
	std::cout << "\n\n\n";
}

inline void Map::print_letters() const
{
	for (int i = 0, j = 65; i < N; i++, j++)
	{
		std::cout << "  " << letters.begin()[i];
	}
}

inline void Map::fillField(Field& field)
{
	
}

inline void Map::placeEnemyShips()
{
	
		Fleet enemy_fleet;
		size_t x = 0, y = 0, tmp_x = 0, tmp_y = 0, direction = 0, counter = 0;
		bool place_is_possible = true;
		size_t ship_size = enemy_fleet.getCountFdShip();
		while (ship_size != 0)
		{

			direction = rand() % 4;
			x = rand() % N;
			y = rand() % N;
			tmp_x = x;
			tmp_y = y;

			for (int i = 0; i < enemy_fleet.getFleet()[0].getShip().size(); i++)
			{
				place_is_possible = true;
				if (x < 0 || x >= N || y < 0 || y >= N)
				{
					place_is_possible = false;
					break;
				}
				if (x = 0 || x == 9 || y == 0 || y == 9)
				{

				}

				if (enemy_field.getMatrix()[x][y] == enemy_symbol ||
					enemy_field.getMatrix()[x][y + 1] == enemy_symbol ||
					enemy_field.getMatrix()[x][y - 1] == enemy_symbol ||
					enemy_field.getMatrix()[x + 1][y] == enemy_symbol ||
					enemy_field.getMatrix()[x + 1][y + 1] == enemy_symbol ||
					enemy_field.getMatrix()[x + 1][y - 1] == enemy_symbol ||
					enemy_field.getMatrix()[x - 1][y] == enemy_symbol ||
					enemy_field.getMatrix()[x - 1][y + 1] == enemy_symbol ||
					enemy_field.getMatrix()[x - 1][y - 1] == enemy_symbol)
				{
					place_is_possible = false;
					break;
				}

				switch (direction)
				{
				case 0: {
					x++;
					break;
				}
				case 1: {
					y++;
					break;
				}
				case 2: {
					x--;
					break;
				}
				case 3: {
					y--;
					break;
				}
				}
			}

			x = tmp_x;
			y = tmp_y;
			--ship_size;
		}
		if (place_is_possible)
		{
			for (int i = 0, j = 0; i < enemy_fleet.getFleet()[0].getShip().size(); i++)
			{
				enemy_field.getMatrix()[x][y] = enemy_symbol;

				switch (direction)
				{
				case 0: {
					x++;
					break;
				}
				case 1: {
					y++;
					break;
				}
				case 2: {
					x--;
					break;
				}
				case 3: {
					y--;
					break;
				}
				}
			}

			counter++;
		}
}
*/
