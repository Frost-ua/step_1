#include <iostream>
#include <string>
#include "windows.h"
#include "water.h"
//------------------------------------------------  Done -----------------------






int water::count = 0;
string water::quater_to_string[5]{ "Lake", "Channel", "Basin", "Reservoir", "Swamp" };

size_t gr_size = 0;
water* w_group = nullptr;


water::water(string name, double width, double length, double maxDepth, typeWater type)
{
	set_name(name);
	set_width(width);
	set_length(length);
	set_maxDepth(maxDepth);
	set_type_water(type);
	count++;
}

water::water(string name, double width, double length)
	:water(name, width, length, 5, LAKE)
{
}

water::water()
{
	width = 10;
	length = 20;
	maxDepth = 5;
	name = "Noname";
	type = LAKE;
	size;
}

string water::get_name() const
{
	return name;
}

double water::get_width() const{
	return width;
}

double water::get_length() const
{
	return length;
}

double water::get_maxDepth() const
{
	return maxDepth;
}

water::typeWater water::get_type_water() const
{
	return type;
}

void water::set_name(string name)
{
	this->name = name;
}

void water::set_width(double width)
{
	if (width >= MIN_WIDTH)
	{
		this->width = width;
	}
	else
	{
		throw WrongWidthException();	
	}
}

void water::set_length(double length)
{
	if (length >= MIN_LENGTH)
	{
		this->length = length;
	}
	else
	{
		throw WrongLengthException();
	}
}

void water::set_maxDepth(double maxDepth)
{
	if (maxDepth >= MIN_MAX_DEPTH)
	{
		this->maxDepth = maxDepth;
	}
	else
	{
		throw WrongDepthException();
	}
}

void water::set_type_water(typeWater type)
{
	this->type = type;
}

void water::show_water_type() const
{
	cout << quater_to_string[type];
}

void water::print_info() const
{
	cout << name << "    \t";
	water::show_water_type();
	cout << "\t\t" << "W: " << width << "\t\t" << "L: " << length << "\t\t" << "D: " << maxDepth << endl;
	cout << "------------------------------------------------------------------------" << endl;
}

double water::water_volume() const
{
	return width * length * maxDepth;
}

double water::water_squere() const
{
	return width * length;
}

bool water::compare_type_water(const water& water_1, const water& water_2)
{
	return (water_1.type == water_2.type);
}

int water::compare_water_squere(const water& water_1, const water& water_2)
{
	if ((water_1.water_squere()) > water_2.water_squere())
		return 1;
	else if ((water_1.water_squere()) < water_2.water_squere())
		return -1;
	else if ((water_1.water_squere()) == water_2.water_squere())
		return 0;
}

void water::add_water_to_group() const
{
	if (gr_size == 0)
	{
		gr_size++;
		w_group = new water[gr_size]{};
		w_group[gr_size - 1] = *this;

	}
	else if (gr_size > 0)
	{
		water* new_arr = new water[gr_size + 1];

		for (int i = 0; i < gr_size; i++)
		{
			new_arr[i] = w_group[i];
		}
		new_arr[gr_size] = *this;
		delete[] w_group;
		w_group = new_arr;
		gr_size++;
	}
	
}

water water::Search_bigest_water(typeWater search_type)
{
	int max_size = 0;
	water biggest_water;
	for (size_t i = 0; i < gr_size; i++)
	{
		if (w_group[i].type == search_type)
			
			if (w_group[i].water_squere() > max_size)
			{
				max_size += w_group[i].water_squere();
				biggest_water = w_group[i];
			}
	}
	return biggest_water;
}



