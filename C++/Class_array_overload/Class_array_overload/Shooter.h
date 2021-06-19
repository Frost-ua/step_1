#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Shooter
{
public:
		Shooter(size_t ammunition_amount, const string& ammunition_name)
		{
			set_ammunition_name(ammunition_name);
			set_ammunition_amount(ammunition_amount);
			//cout << "Ctor shooter " << ammunition_name << " " << ammunition_amount << endl;
		}

		size_t get_ammunition_amount() const;
		string get_ammunition_name() const;

		void set_ammunition_amount(size_t ammunition_amount);
		void set_ammunition_name(const string & ammunition_name);

		void shoot();
		void getAmmunition(size_t amount, const string& name);

protected:
	string ammunition_name;
	size_t ammunition_amount;

};

inline size_t Shooter::get_ammunition_amount() const
{
	return ammunition_amount;
}

inline string Shooter::get_ammunition_name() const
{
	return ammunition_name;
}

inline void Shooter::set_ammunition_amount(size_t ammunition_amount)
{
	ammunition_amount >= 0 ? this->ammunition_amount = ammunition_amount : 1;
}

inline void Shooter::set_ammunition_name(const string& ammunition_name)
{
	!empty(ammunition_name) ? this->ammunition_name = ammunition_name : "Noname";

}

inline void Shooter::shoot()
{
	if (this->ammunition_amount > 0)
	{
		this->ammunition_amount -= 1;
		cout << "There are " << get_ammunition_amount() << " more shots by " << get_ammunition_name() << "s" << endl;
	}
	else
	{
		cout << "There was no shot! There are no " << get_ammunition_name() <<"s.\n";
	}
}

inline void Shooter::getAmmunition(size_t amount, const string& name)
{
	set_ammunition_name(name);
	set_ammunition_amount(amount);
}
