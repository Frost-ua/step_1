#pragma once
#include "Ranger.h"
#include "FortressArcher.h"

class Tower : public FortressArcher, public Ranger
{
public:
	
	Tower(size_t ammunition_amount, const string& ammunition_name = "arrow")
		: Shooter(ammunition_amount, ammunition_name), FortressArcher(ammunition_amount, ammunition_name), Ranger(ammunition_amount, ammunition_name)
	{
		//cout << "Ctor tower " << this->ammunition_name << " " << this->ammunition_amount << endl;
	}

	size_t getAmount()
	{
		return ammunition_amount;
	}
};





