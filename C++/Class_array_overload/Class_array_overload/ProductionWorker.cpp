#include "ProductionWorker.h"

string ProductionWorker::shift_to_string[]{ " ", "day", "night" };


ProductionWorker::ProductionWorker(const string& name, const string& hiring_date, shift working_shift, float hourly_rate, float worked_hours)
	:Employee (name, hiring_date)
{
	set_woking_shift(working_shift);
	set_hourly_rate(hourly_rate);
	set_worked_hours(worked_hours);
}

ProductionWorker::ProductionWorker()
{
	working_shift = DAY;
	hourly_rate = 5;
	worked_hours = 160;
}

void ProductionWorker::set_woking_shift(shift working_shift)
{
	this->working_shift = working_shift;
}

void ProductionWorker::set_hourly_rate(float hourly_rate)
{
	if (working_shift == DAY)
	{
		hourly_rate > MIN_HOURLY_RATE ? this->hourly_rate = hourly_rate : this->hourly_rate = MIN_HOURLY_RATE;
	}
	else if (working_shift == NIGHT)
	{
		hourly_rate > MIN_HOURLY_RATE ? this->hourly_rate = hourly_rate + (hourly_rate * night_multiplier) : this->hourly_rate = MIN_HOURLY_RATE * night_multiplier;
	}
}

void ProductionWorker::set_worked_hours(float worked_hours)
{
	worked_hours > 0 ? this->worked_hours = worked_hours : this->worked_hours = 0;
}

void ProductionWorker::set_night_multiplier(float night_multiplier)
{
	night_multiplier > 0 ? this->night_multiplier = night_multiplier : this->night_multiplier = 0.25;
}

ProductionWorker::shift ProductionWorker::get_working_shift() const
{
	return working_shift;
}

float ProductionWorker::get_hourly_rate() const
{
	return hourly_rate;
}

float ProductionWorker::get_worked_hours() const
{
	return worked_hours;
}

float ProductionWorker::get_night_multiplier() const
{
	return night_multiplier;
}

void ProductionWorker::show_shift(shift working_shift)
{
	cout << shift_to_string[working_shift] << "\t";
}


void ProductionWorker::print_employee_info() const
{
	cout << endl;
	Employee::print_employee_info();
	cout << "\tshift - ";
	ProductionWorker::show_shift(working_shift);
	cout << "\thourly rate - " << hourly_rate << "\tworked hours - " << worked_hours;

}
