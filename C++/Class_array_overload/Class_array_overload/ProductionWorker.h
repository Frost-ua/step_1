#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

class ProductionWorker : public Employee
{
public:
	enum shift
	{
		DAY = 1, NIGHT
	};

	static string shift_to_string[];
	static void show_shift(shift working_shift);

	ProductionWorker(const string &name, const string & hiring_date, shift working_shift, float hourly_rate, float worked_hours);
	ProductionWorker();

	void set_woking_shift(shift working_shift);
	void set_hourly_rate(float hourly_rate);
	void set_worked_hours(float worked_hours);
	void set_night_multiplier(float night_multiplier);

	shift get_working_shift() const;
	float get_hourly_rate() const;
	float get_worked_hours() const;
	float get_night_multiplier() const;

	void print_employee_info() const;

private:
	static const size_t MIN_HOURLY_RATE = 2;
	float hourly_rate;
	float worked_hours;
	shift working_shift;
	float night_multiplier = 0.25;

};

