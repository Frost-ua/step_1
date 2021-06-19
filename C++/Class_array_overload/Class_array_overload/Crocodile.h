#pragma once
#include "lib.h"

class Crocodile : public Animal
{
public:
	Crocodile(const string& name)
		:Animal(name)
	{
	}
	Crocodile() = default;
};



