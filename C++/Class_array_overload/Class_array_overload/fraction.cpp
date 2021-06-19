#include <iostream>
#include "fraction.h"

fraction::fraction(int numer, int denom)
{
	set_numer(numer);
	set_denom(denom);
}

fraction::fraction(int numer)
{
	set_numer(numer);
	denom = 1;
}

fraction::fraction()
{
	numer = 0;
	denom = 1;
}

int fraction::get_numer() const
{
	return numer;
}

int fraction::get_denomr() const
{
	return denom;
}

void fraction::set_numer(int numer)
{
	this->numer = numer;
}

void fraction::set_denom(int denom)
{
	if (denom != 0)
		this->denom = denom;
	else
	{
		this->denom = 1;
	}

	if (denom < 0)
	{
		this->denom = -denom;
		this->numer = -numer;
	}
	
}

void fraction::print_fraction() const
{
	std::cout << "Fraction: " << numer << "/" << denom << std::endl;
	std::cout << "------------------------------------------"<< std::endl;
}

fraction &fraction::fraction_reduction()
{
	int i, less;                                  
	do {
		if (numer < denom)                                    
			less = numer;                               
		else                                                   
			less = denom;                                
		for (i = less; i > 0; i--) {
			if (!(numer % i) && !(denom % i)) {
				numer /= i;
				denom /= i;
				break;                               
			}
		}
	} while (i != 1);

	return *this;
}

fraction fraction::operator+(const fraction& other) const
{
	return fraction();
}

fraction fraction::operator+(int value) const
{
	return fraction();
}

fraction fraction::operator-(const fraction& other) const
{
	return fraction();
}

fraction fraction::operator*(const fraction& other) const
{
	return fraction();
}

fraction fraction::operator*(int value) const
{
	return fraction();
}

fraction fraction::operator/(const fraction& other) const
{
	return fraction();
}

fraction fraction::operator++()
{
	return fraction();
}

fraction fraction::operator++(int)
{
	return fraction();
}

fraction fraction::operator--()
{
	return fraction();
}

fraction fraction::operator--(int)
{
	return fraction();
}

bool fraction::operator==(const fraction& other) const
{
	return false;
}

bool fraction::operator!=(const fraction& other) const
{
	return false;
}

bool fraction::operator>(const fraction& other) const
{
	return false;
}

bool fraction::operator<(const fraction& other) const
{
	return false;
}

bool fraction::operator+=(int value) const
{
	return false;
}

bool fraction::operator*=(int value) const
{
	return false;
}
