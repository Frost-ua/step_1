#pragma once
#include "Shooter.h"

class Catapult : protected Shooter
{
public:
	//Catapult() = default;
	Catapult(size_t ammunition_amount, const string& ammunition_name = "stone")
		:Shooter(ammunition_amount, ammunition_name)
	{
		//cout << "Ctor catapult " << this->ammunition_name << " " << this->ammunition_amount << endl;
	}

	void CtapultShoot();
};

inline void Catapult::CtapultShoot()
{
	if (this->ammunition_amount > 0)
	{
		cout << "Catapult shot. ";
	}
	shoot();
}

