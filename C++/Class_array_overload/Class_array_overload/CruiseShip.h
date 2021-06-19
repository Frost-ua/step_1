#pragma once
#include "Ship.h"

class CruiseShip : public Ship
{
	
public:
	CruiseShip(const string& name, size_t year, int MaxPasangers);
	CruiseShip() = default;

	void setMaxPasangers(int MaxPasangers);
	int getMaxPasangers() const;
	virtual void Print() const override;
	virtual void show_excursions() const;
private:
	int MaxPasangers = 2000;
};

inline CruiseShip::CruiseShip(const string& name, size_t year, int MaxPasangers)
	:Ship(name, year)
{
	setMaxPasangers(MaxPasangers);
}

inline void CruiseShip::setMaxPasangers(int MaxPasangers)
{
	this->MaxPasangers = MaxPasangers;
}

inline int CruiseShip::getMaxPasangers() const
{
	return MaxPasangers;
}

inline void CruiseShip::Print() const 
{
	Ship::Print();
	cout << "\nMax passengers: "  << getMaxPasangers() << "\n--------------------------------------\n";
}

inline void CruiseShip::show_excursions() const
{
	cout << "The excursion is done!\n";
}

