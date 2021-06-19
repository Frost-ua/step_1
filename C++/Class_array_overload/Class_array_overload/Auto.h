#pragma once
#include <string>
#include <iostream>
#include<exception>

using namespace std;

class WrongMaxSpeedException
{
public:
	WrongMaxSpeedException(const size_t &err_max_speed,const char* err_message)
		:err_max_speed(err_max_speed), err_message(err_message)
	{
	}

	size_t get_err_max_speed() const
	{
		return err_max_speed;
	}

	void get_err_message() const
	{
		cout << "Set maximum speed  \"" << get_err_max_speed() << "\" is greater than allowed maximum speed\n\n";
	}

private:
	const char* err_message;
	size_t err_max_speed;
};

class WrongSpeedException
{
public:
	WrongSpeedException(const size_t& err_curr_speed, const char* err_message)
		:err_curr_speed(err_curr_speed), err_message(err_message)
	{
	}

	size_t get_err_curr_speed() { return err_curr_speed; }

	void get_err_message()
	{
		if (get_err_curr_speed() == 0)
		{
			cout << err_message;
		}
		else
		{
			cout << "Current speed \"" << get_err_curr_speed() << "\" is greater than allowed maximum speed\n\n";
		}
		
	}

private:
	const char* err_message;
	size_t err_curr_speed;
};

class InvalidNumberException
{
public:
	InvalidNumberException(const char* err_car_number, const char* err_message)
		:err_car_number(err_car_number), err_message(err_message)
	{
	}

	const char* get_err_car_number() { return err_car_number; }

	void get_err_message()
	{
		cout << "Set car number " << get_err_car_number() << " is incorrect! It must be in AB1234CD format.\n";
	}

private:
	const char* err_message;
	const char* err_car_number;
};

class Auto
{
public:
	Auto(const char* car_number, const size_t& current_speed, const size_t& max_speed);

	//GETERS
	string get_car_number() const;
	size_t get_current_speed()const;
	friend class WrongMaxSpeedException;
	size_t get_max_speed()const;

	//SETERS
	void set_car_number(const char* number);
	void set_current_speed(const size_t &curr_speed);
	void set_max_speed(const size_t &max_speed);

	//METHODS
	void increase_speed(const size_t& speed = 5);
	void decrease_speed(const size_t& speed = 5);
	bool check_car_number(const char* number) const;
	const char* create_memory_for_str(const char* str);
	void print_car_info()const;

	~Auto();
private:
	const char* car_number = nullptr;
	const size_t MAX_SPEED = 360;
	size_t current_speed;
	size_t speed_difference = 5;
	const char* DEFAULT_CAR_NUMBER = "AB1234CD";

};

