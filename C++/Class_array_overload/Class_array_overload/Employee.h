#pragma once
#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
	static size_t count;

	Employee(const string &name, const string &hiring_date);
	Employee();

	void set_name(string name);
	void set_hiring_date(string hiring_date);
	void set_id(size_t id);

	string get_name() const;
	size_t get_id() const;
	string get_hiring_date();

	void print_employee_info() const;

private:
	string name;
	string hiring_date;
	size_t id;
};

