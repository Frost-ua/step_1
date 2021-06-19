#pragma once
#include "Magazine.h"

class Gun
{
public:
	Gun();
	void shoot();
	void setMagazine(const Magazine& magazin);
	Magazine getMagazine() const;
private:
	Magazine magazine;
};

inline Gun::Gun()
{
	Magazine magazine;
}

inline void Gun::shoot()
{
	try
	{
		magazine.giveBullet().shoot();
	}
	catch (const std::out_of_range& ex)
	{
		cout << ex.what() << endl;
	}
}

inline void Gun::setMagazine(const Magazine& magazin)
{
	this->magazine = magazine;
}

inline Magazine Gun::getMagazine() const
{
	return magazine;
}


