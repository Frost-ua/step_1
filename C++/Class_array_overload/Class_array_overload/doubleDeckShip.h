#pragma once
#include<vector>
#include"Ship_.h"
#include"Deck.h"

class doubleDeckShip : public Ship_
{
public:
	doubleDeckShip(const string& name = "Double-deck ship", size_t ship_size = 2)
		:Ship_(name, ship_size)
	{};
private:
	string name;
};

