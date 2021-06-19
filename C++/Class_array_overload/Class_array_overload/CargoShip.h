#pragma once
#include "Ship.h"

class CargoShip : public Ship
{
public:
	CargoShip(const string& name, size_t year, int capacity);
	CargoShip() = default;

	void set_capacity(int capacity);
	int get_capacity() const;
	virtual void Print() const override;
	virtual void loading() const;

private:
	int capacity = 1000;
};

inline CargoShip::CargoShip(const string& name, size_t year, int capacity)
	:Ship(name, year)
{
	set_capacity(capacity);
}

inline void CargoShip::set_capacity(int capacity)
{
	capacity > 0 ? this->capacity = capacity : this->capacity = 1000;
}

inline int CargoShip::get_capacity() const
{
	return capacity;
}

inline void CargoShip::Print() const
{
	
	Ship::Print();
	cout << "\nMax capasity: " << get_capacity() << "\n--------------------------------------\n";;
	
}

inline void CargoShip::loading() const
{
	cout << get_capacity() << " loaded!\n";
}


