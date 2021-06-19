#pragma once
#include "Shooter.h"

class FortressArcher :virtual protected Shooter
{
public:
	//FortressArcher() = default;
	FortressArcher(size_t ammunition_amount, const string& ammunition_name = "arrow")
		:Shooter(ammunition_amount, ammunition_name)
	{
		//cout << "Ctor archer " << ammunition_name << " " << ammunition_amount << endl;
	}
	
	void ArcherShoot();
};

inline void FortressArcher::ArcherShoot()
{
	if (ammunition_amount > 0)
	{
		cout << "Archer shot. ";
	}
	
	shoot();
}


