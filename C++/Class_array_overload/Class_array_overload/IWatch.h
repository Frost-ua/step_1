#pragma once
#include "Animal.h"


class IWatch
{
public:
	virtual void Watch(Animal& animal) const = 0;
};

