#pragma once
#include "lib.h"

class Parrot : public Animal
{
public:
	Parrot(const string& name)
		:Animal(name)
	{
	}
	Parrot() = default;
};

