#include <iostream>
#include <string>
#include "group.h"

using namespace std;



group::group(const string& group_name, size_t group_size)
{
	set_group_name(group_name);
	group_size == 0 ? arr_group = new pupil[group_size + 1]{} : arr_group = new pupil[group_size]{};
}

group::group(const group& other)
{
	this->group_name = other.group_name;
	this->group_size = other.group_size;

	if (arr_group != nullptr)
		delete[] arr_group;
	arr_group = new pupil[group_size];
	for (size_t i = 0; i < group_size; i++)
	{
		arr_group[i] = other.arr_group[i];
	}
}

void group::set_group_name(string group_name)
{
	this->group_name = group_name;
}

group& group::operator = (const group& other)
{
	this->group_name = other.group_name;
	this->group_size = other.group_size;

	if (arr_group != nullptr)
		delete[] arr_group;
	arr_group = new pupil[group_size];
	for (size_t i = 0; i < group_size; i++)
	{
		arr_group[i] = other.arr_group[i];
	}

	return *this;
}

void group::set_pupil_to_group(string name, string surname, string city)
{
	if (group_size == 0)
	{
		group_size++;
		arr_group = new pupil[group_size]{};
		pupil pers(name, surname, city, 10);
		arr_group[group_size - 1] = pers;

	}
	else if (group_size > 0)
	{
		pupil pers(name, surname, city, 10);
		pupil* new_arr = new pupil[group_size + 1];

		for (int i = 0; i < group_size; i++)
		{
			new_arr[i] = arr_group[i];
		}
		new_arr[group_size] = pers;
		delete[] this->arr_group;
		arr_group = new_arr;
		group_size++;
	}
}

void group::set_pupil_to_group(pupil& pers)
{
	if (group_size == 0)
	{
		group_size++;
		arr_group = new pupil[group_size]{};
		arr_group[group_size - 1] = pers;

	}
	else if (group_size > 0)
	{
		pupil* new_arr = new pupil[group_size + 1];
		for (int i = 0; i < group_size; i++)
		{
			new_arr[i] = arr_group[i];
		}
		new_arr[group_size] = pers;
		delete[] this->arr_group;
		arr_group = new_arr;
		group_size++;
	}
}

string group::search_pupil(string name)
{
	bool is_name = false;

	for (int i = 0; i < group_size; i++)
	{
		if (arr_group[i].get_name() == name)
		{
			is_name = true;
		}
	}

	if (is_name)
	{
		return name;
	}
	else
	{
		return "\nThe name isn't found\n";
	}
}

bool group::delete_pupil(string name)
{
	bool is_pipil = false;
			int index;
	
			for (int i = 0; i < group_size; i++)
			{
				if (arr_group[i].get_name() == search_pupil(name))
				{
					is_pipil = true;
					index = i;
				}
			}
	
			if (is_pipil)
			{
				pupil* new_arr = new pupil[group_size - 1];
	
				for (int i = 0; i < group_size - 1; i++)
				{
					if (i >= index)
					{
						new_arr[i] = arr_group[i + 1];
					}
					else
					{
						new_arr[i] = arr_group[i];
					}
				}
				delete[] arr_group;
				arr_group = new_arr;
				group_size--;
				return true;
	
			}
			else
			{
				return false;
				/*cout << search_pupil(name);*/
			}
}

void group::print_group_info() const
{
	for (int i = 0; i < group_size; i++)
	{
		cout << i + 1 << ". ";
		arr_group[i].print_pupil_info();
	}
}

group::~group()
{
	delete[] this->arr_group;
	arr_group = nullptr;
}
