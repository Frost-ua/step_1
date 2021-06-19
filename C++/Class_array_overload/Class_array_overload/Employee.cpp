#include "Employee.h"


size_t Employee::count = 1;

Employee::Employee(const string& name, const string& hiring_date)
{
	set_name(name);
	set_hiring_date(hiring_date);
	set_id(count);
	count++;
}

Employee::Employee()
{
	name = "Noname";
	hiring_date = "-- -- --";
	id = count;
	count++;
}

void Employee::set_name(string name)
{
	this->name = name;
}

void Employee::set_hiring_date(string hiring_date)
{
	this->hiring_date = hiring_date;
}

void Employee::set_id(size_t id)
{
	this->id = count;
}

string Employee::get_name() const
{
	return name;
}

size_t Employee::get_id() const
{
	return id;
}

string Employee::get_hiring_date()
{
	return hiring_date;
}

void Employee::print_employee_info() const
{
	cout << "id:" << this->id << "\t name: " << name << "\thiring date: " << hiring_date << "\t";
}
