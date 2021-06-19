#include <iostream>
#include "Auto.h"
using namespace std;

Auto::Auto(const char* car_number, const size_t& current_speed, const size_t& max_speed)
{
	try
	{
		set_car_number(car_number);
		set_max_speed(max_speed);
		set_current_speed(current_speed);
	}
	catch (WrongMaxSpeedException& ex)
	{
		
		if (car_number != nullptr)
		{
			this->~Auto();
		}
		throw;
		
	}
	catch (WrongSpeedException& ex)
	{
		
		if (car_number != nullptr)
		{
			this->~Auto();
		}
		throw;
	}
	
	
}

string Auto::get_car_number() const
{
	return car_number;
}

size_t Auto::get_current_speed() const
{
	return current_speed;
}

size_t Auto::get_max_speed() const
{
	return MAX_SPEED;
}

void Auto::set_car_number(const char* number)
{
	if (check_car_number(number))
	{
		this->car_number = create_memory_for_str(number);
	}
	else
	{
		throw InvalidNumberException(number, "");
	}
}

void Auto::set_current_speed(const size_t &curr_speed)
{
	if (curr_speed > MAX_SPEED || curr_speed <= 0)
	{
		throw WrongSpeedException(curr_speed, "");
		
	}
	this->current_speed = curr_speed;
}

void Auto::set_max_speed(const size_t& max_speed)
{
	if (max_speed > MAX_SPEED)
	{
		throw WrongMaxSpeedException(max_speed, "");
	}
	const_cast<size_t&>(this->MAX_SPEED) = max_speed;
}

void Auto::increase_speed(const size_t& speed)
{
	if (current_speed + speed_difference > MAX_SPEED)
	{
		throw WrongSpeedException((current_speed + speed_difference), "");
	}
	current_speed += speed_difference;
}

void Auto::decrease_speed(const size_t& speed)
{
	if (current_speed - speed_difference <= 0)
	{
		throw WrongSpeedException((current_speed - speed_difference), "Current car speed is zero, car has stopped.\n");
	}
	current_speed -= speed_difference;
}

bool Auto::check_car_number(const char* number) const
{
	if (strlen(number) != strlen(DEFAULT_CAR_NUMBER))
	{
		return false;
	}
	else
	{
		for (size_t i = 0; i < strlen(number); i++)
		{
			if (i == 0 || i == 1 || i == 6 || i == 7)
			{
				if (number[i] < 65 || number[i] > 90)
				{
					return false;
				}
			}
			if (i == 2 || i == 3 || i == 4 || i == 5)
			{
				if (number[i] < 48 || number[i] > 57)
				{
					return false;
				}
			}
		}
	}
	return true;
}

const char* Auto::create_memory_for_str(const char* str)
{
	auto size = strlen(str) + 1;
	char* result = new char[size];
	strcpy_s(result, size, str);
	return result;
}

void Auto::print_car_info() const
{
	cout << "-------------------------------------\n";
	cout << "Car number is \t\t" << car_number << endl;
	cout << "Current car speed is \t" << current_speed << endl;
	cout << "Maximum car speed is \t" << MAX_SPEED << endl;
	cout << "-------------------------------------\n";
}

Auto::~Auto()
{
	if (car_number !=  nullptr)
	{
		delete[] car_number;
	}
	
}
