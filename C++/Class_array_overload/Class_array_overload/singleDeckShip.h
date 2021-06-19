#pragma once
#include<vector>
#include"Ship_.h"
#include"Deck.h"

class singleDeckShip : public Ship_
{
public:
	singleDeckShip(const string& name = "Single-deck ship", size_t ship_size = 1)
		:Ship_(name, ship_size)
	{};
private:
	string name;
};

