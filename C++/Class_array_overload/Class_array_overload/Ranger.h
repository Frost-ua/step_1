#pragma once
#include "Shooter.h"

class Ranger : virtual protected Shooter
{
public:
	//Ranger() = default;
	Ranger(size_t ammunition_amount, const string& ammunition_name = "arrow")
		:Shooter(ammunition_amount, ammunition_name)
	{
		//cout << "Ctor ranger " << this->ammunition_name << " " << this->ammunition_amount << endl;
		
	}
	void RangerShoot();
};

inline void Ranger::RangerShoot()
{
	if (this->ammunition_amount > 0)
	{
		cout << "Ranger shot. ";	
	}
	shoot();
}
