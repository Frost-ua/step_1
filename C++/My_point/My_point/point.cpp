#include<iostream>
#include<math.h>
#include "ctime"
#include "iomanip"
#include <conio.h>
#include <windows.h>
#include "point.h"

int point::count = 0;     // static
char point::water[SIZE][SIZE]{};


point::point(int x, int y)
	:x(x), y(y)      // initialization
{
	point_name = 'A' + count;   // A + 0 = A,   A + 1 = B
	++count;
}

point::point(int x)
	: point(x, 0)
{
}

int point::get_count_points()
{
	return count;
}

double point::distance(const point& point_1, const point& point_2)
{
	return sqrt(pow(point_1.x - point_2.x, 2) + (point_1.y - point_2.y, 2));
}

int point::comparison_two_points(const point& point_0, const point& point_1, const point& point_2)
{
	if (distance(point_0, point_1) > distance(point_0, point_2))
	{
		return 1;
	}
	if (distance(point_0, point_1) < distance(point_0, point_2))
	{
		return -1;
	}
	if (distance(point_0, point_1) == distance(point_0, point_2))
	{
		return 0;
	}
}

void point::print() const
{
	std::cout << point_name << "(" << x << "," << y << ")" << std::endl;
}

void point::init_water()
{
	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE; j++)
		{
			water[i][j] = DEFAULT_SYMBOL;
		}
		
	}
}

void point::print_water()
{
	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE; j++)
		{
			std::cout << water[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}

void point::put_point_on_water()
{
	water[y][x] = point_name;
}