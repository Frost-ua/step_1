#include<iostream>
#include "Animal.h"

Animal::Animal(const std::string& name)
{
	set_name(name);
}

Animal& Animal::operator[](size_t index)
{
	return this[index];	
}

std::string Animal::get_name() const
{
	return name;
}

std::string Animal::get_kind() const
{
	return kind;
}

void Animal::set_name(const std::string & name)
{
	(!empty(name)) ? this->name = name : "Noname";
}

void Animal::set_kind(const std::string& kind)
{
	this->kind = kind;
}

void Animal::set_is_eating(bool a)
{
	is_eating = a;
}

bool Animal::get_is_eating() const
{
	return is_eating;
}

void Animal::random_action(const Animal& animal) const
{
	if (animal.get_is_eating())
	{
		Eat();
	}
	else
	{
		int chance = rand() % 3;

		switch (chance)
		{
		case 0:{
			Walk();
			break;
			}
		case 1: {
			Sleep();
			break;
		}
		case 2: {
			Eat();
			break;
		}
		}
	}
}

void Animal::Walk() const
{
	std::cout << this->get_kind()  << " " << get_name() << " is walking now.\n";
}

void Animal::Eat() const
{
	std::cout << this->get_kind() << " " << get_name() << " is eating now.\n\n";
}

void Animal::Sleep() const
{
	std::cout << this->get_kind() << " " << get_name() << " is sleeping now.\n";
}


