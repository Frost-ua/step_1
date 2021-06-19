#pragma once
#include "lib.h"
/*#include "Animal.h"*/

class Bear : public Animal
{
public:
	Bear(const string& name)
		:Animal(name)
	{
	}
	Bear() = default;
};

