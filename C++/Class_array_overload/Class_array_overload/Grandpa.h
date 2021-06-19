#pragma once
#include<iostream>
#include <string>

using namespace std;

class Grandpa
{
public:
	Grandpa(const string & name, size_t age);
	Grandpa() = default;
	void set_name(const string& name);
	void set_age(size_t age);
	virtual string get_name() const;
	virtual size_t get_age() const;
	virtual void Sleep() const;
	~Grandpa();

private:
	const size_t MIN_AGE = 1;
	string name = "Noname";
	size_t age = 70;
};

inline Grandpa::Grandpa(const string& name, size_t age)
{
	set_name(name);
	set_age(age);
}

inline void Grandpa::set_name(const string& name)
{
	if (!empty(name))
	{
		this->name = name;
	}
}

inline void Grandpa::set_age(size_t age)
{
	age > 0 ? this->age = age : MIN_AGE;
}

inline string Grandpa::get_name() const
{
	return name;
}

inline size_t Grandpa::get_age() const
{
	return this->age;
}

inline void Grandpa::Sleep() const
{
	cout << typeid(*this).name() + 6 << " " << this->name << " is sleeping now\n";
}

inline Grandpa::~Grandpa()
{
}


