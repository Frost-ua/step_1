#pragma once
#include <iostream>
#include <string>
using namespace std;

class Ship abstract
{
public:
	static const size_t NOWADAYS = 2020;

	Ship(const string& name, size_t year);
	Ship() = default;

	void setYear(size_t year);
	size_t getYear() const;
	void setName(const string& name);
	const string& getName() const;
	virtual void Print() const = 0;

private:
	string name = "Noname";
	size_t year = 1990;
};

inline Ship::Ship(const string& name, size_t year)
{
	setName(name);
	setYear(year);
}

inline void Ship::setYear(size_t year)
{
	if (year <= NOWADAYS)
	{
		this->year = year;
	}
}

inline size_t Ship::getYear() const
{
	return year;
}

inline void Ship::setName(const string& name)
{
	this->name = name;
}

inline const string& Ship::getName() const
{
	return name;
}

inline void Ship::Print() const
{
	cout << "Name: " << name << "\t" << "Year: " << year;
}
